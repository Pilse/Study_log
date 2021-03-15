import React, { useState } from 'react';
import './GithubUser.css'
import {makeMindMap} from '../GithubMindmap/GithubMindmap';

const APIURL = 'https://api.github.com/users/';

function GithubUser() {

  const [userName, setUserName] = useState('');
  const [showUser, setShowUser] = useState(false);
  const [card, setCard] = useState('');
  let arr;

  function makeErrCard(msg) {
    setCard(
      <div className="card">
        <h1>{msg}</h1>
      </div>
    )
  }

  async function makeCard(user) {
    try {
      const response = await fetch(APIURL + userName + '/repos?sort=created');
      const repos = await response.json();
      
      setCard(
        <div className="card">
          <div className="user-photo">
            <img className="avatar user-profile" src={user.avatar_url} alt={user.name} />
          </div>
          <div className="user-info">
            <h2>{user.name === null ? 'Null' : user.name}</h2>
            <p>{user.bio === null ? 'Null' : user.bio}</p>
            <ul>
              <li>{user.followers} <strong>Followers</strong></li>
              <li>{user.following} <strong>Following</strong></li>
              <li>{user.public_repos} <strong>Repos</strong></li>
            </ul>
            <div className="repos">
              {repos.slice(0, 10).map((repo, idx) =>
                <a key={repo.name + idx} href={repo.html_url} className="repo" target="_blank">
                  {repo.name}
                </a>
              )
              }
            </div>
          </div>
        </div>
      );

      makeMindMap(userName);

    } catch (err) {
      makeErrCard('repos not found');
    }
  }


  async function handleSubmit(e) {
    e.preventDefault();
    try {
      const response = await fetch(APIURL + userName);
      const data = await response.json();

      makeCard(data);

      setShowUser(true);
      setUserName('');

    } catch (err) {
      makeErrCard('Cannot find user');
    }
  }


  return (
    <>
      <div>
        <form className="search" onSubmit={handleSubmit}>
          <input
            type="text"
            placeholder="Search a Github User"
            value={userName}
            onChange={(e) => { setUserName(e.target.value) }} />
        </form>
      </div>
      {showUser ? card : null}
    </>
  );
}

export default GithubUser;
