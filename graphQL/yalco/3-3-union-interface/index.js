const { ApolloServer } = require('apollo-server')

const queries = require('./typedefs-resolvers/_queries')
const mutations = require('./typedefs-resolvers/_mutations')
const enums = require('./typedefs-resolvers/_enums')
const equipments = require('./typedefs-resolvers/equipments')
const softwares = require('./typedefs-resolvers/softwares')
const supplies = require('./typedefs-resolvers/supplies')

const typeDefs = [
    queries,
    mutations,
    enums,
    equipments.typeDefs,
    softwares.typeDefs,
    supplies.typeDefs
]

const resolvers = [
    equipments.resolvers,
    softwares.resolvers,
    supplies.resolvers
]

const server =  new ApolloServer({typeDefs, resolvers})

server.listen().then(({url}) => {
    console.log(`🚀  Server ready at ${url}`)
})
