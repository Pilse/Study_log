import React, { useState } from 'react';
import './GithubUser.css'

const APIURL = 'https://api.github.com/users/';

function GithubUser() {

  const [userName, setUserName] = useState('');
  const [showUser,setShowUser] = useState(false);
  const [card,setCard] = useState('');

  let repoArr =[];

  function makeErrCard(msg) {
    setCard(
    <div class="card">
        <h1>{msg}</h1>
    </div>
    )
  }
  function makeCard(user) {
    console.log(repoArr);
    setCard(
      <div className="card">
        <div className="user-photo">
          <img className="avatar user-profile" src={user.avatar_url} alt={user.name} />
        </div>
        <div className="user-info">
          <h2>{user.name===null ? 'Null':user.name}</h2>
          <p>{user.bio===null ? 'Null':user.bio}</p>
          <ul>
            <li>{user.followers} <strong>Followers</strong></li>
            <li>{user.following} <strong>Following</strong></li>
            <li>{user.public_repos} <strong>Repos</strong></li>
          </ul>
          <div className="repos">
            {repoArr}
          </div>
        </div>
      </div>
    );
  }

  function makeRepo(repos) {
    repos.slice(0, 10).forEach(repo => {
      const repoEl = (
        <a href={repo.html_url} className="repo">
          {repo.name}
        </a>
      );
      repoArr.concat(repoEl);
    })
  }

  async function getRepo(user) {
    try {
      const response = await fetch(APIURL + user + '/repos?sort=created');
      const data = await response.json();

      makeRepo(data);

    } catch (err) {
      makeErrCard('Cannot fetch repos');
    }
  }


  async function handleSubmit(e) {
    e.preventDefault();
    try{
      const response = await fetch(APIURL + userName);
      const data = await response.json();

      getRepo(userName);
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
