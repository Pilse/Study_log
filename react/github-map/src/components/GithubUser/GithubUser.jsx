import React, { useState } from 'react';
import './GithubUser.css'
import GithubMindmap from '../GithubMindmap/GithubMindmap';

const APIURL = 'https://api.github.com/users/';

function GithubUser(props) {

  const [userName, setUserName] = useState('');
  const [submittedUser,setsubmittedUser] = useState('');
  const [showUser, setShowUser] = useState(false);
  const [card, setCard] = useState('');

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
              {repos.slice(0, 20).map((repo, idx) =>
                <a key={repo.name + idx} href={repo.html_url} className="repo" target="_blank">
                  {repo.name}
                </a>
              )
              }
            </div>
          </div>
        </div>
      );

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
      setsubmittedUser(data.login);

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
            onChange={(e) => {setUserName(e.target.value) }} />
        </form>
        <div className="container">
          {showUser ? card : null}
          {showUser ? <GithubMindmap user={submittedUser} /> : null}
        </div>
      </div>
    </>
  );
}

export default GithubUser;
