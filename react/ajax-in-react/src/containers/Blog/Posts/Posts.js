import React, { Component } from "react";
import Post from "../../../components/Post/Post";
import { Route } from "react-router-dom";

import "./Posts.css";
import FullPost from "../FullPost/FullPost";

class Posts extends Component {
  state = {
    posts: [],
  };
  async componentDidMount() {
    console.log(this.props);
    try {
      const res = await fetch("https://jsonplaceholder.typicode.com/posts");
      const data = await res.json();
      const posts = data.slice(0, 4);
      const updatedPosts = posts.map((post) => {
        return {
          ...post,
          author: "Max",
        };
      });

      this.setState({ posts: updatedPosts });
    } catch (err) {
      this.setState({ error: true });
    }
  }

  postSelectedHandler = (id) => {
    this.props.history.push("/posts/" + id);
  };

  render() {
    let posts = <p style={{ textAlign: "center" }}>Something went wrong</p>;
    if (!this.state.error) {
      posts = this.state.posts.map((post) => {
        return (
          <Post
            key={post.id}
            title={post.title}
            author={post.author}
            clicked={() => this.postSelectedHandler(post.id)}
          />
        );
      });

      return (
        <div>
          <section className="Posts">{posts}</section>
          <Route
            path={this.props.match.url + "/:id"}
            exact
            component={FullPost}
          />
        </div>
      );
    }
  }
}

export default Posts;
