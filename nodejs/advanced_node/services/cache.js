const mongoose = require('mongoose')
const redis = require('redis')
const util = require('util')

const redisUrl = 'redis://127.0.0.1:6379';
const client = redis.createClient(redisUrl);
client.hget = util.promisify(client.hget);
const exec = mongoose.Query.prototype.exec;

mongoose.Query.prototype.cache = function(options = {}) {
  this._cache = true;
  this._hashKey = JSON.stringify(options.key || '');
  
  return this;
}

mongoose.Query.prototype.exec = async function () {
  if(!this._cache) {
    return exec.apply(this, arguments)
  }

  const key = JSON.stringify(
    Object.assign({}, this.getQuery(), {
      collection: this.mongooseCollection.name
    }));

  // redis에 key가 있는지 확인한다
  const cacheValue = await client.hget(this._hashKey, key);

  // 있다면 해당 key에 해당하는 value를 return한다
  if(cacheValue) {
    const doc = JSON.parse(cacheValue);

    return Array.isArray(doc)  
      ? doc.map(d => new this.model(d))
      : new this.model(doc); 
  }

  // 그렇지 않다면 query를 실행하고 결과를 redis에 저장한다
  const result = await exec.apply(this, arguments);

  client.hset(this._hashKey, key, JSON.stringify(result));

  return result;
}

module.exports = {
  clearHash(hashKey) {
    client.del(JSON.stringify(hashKey));
  }
};