import React from "react";
import Link from "next/link";
import Router from "next/router";

function indexPage(props) {
  return (
    <div>
      <h1>The Main Page - {props.appName}</h1>
      <p>
        Go to{" "}
        <Link href="/auth">
          <a>Auth</a>
        </Link>
      </p>
      <button onClick={() => Router.push("/auth")}>Go to Auth</button>
    </div>
  );
}

indexPage.getInitialProps = async (context) => {
  const promise = new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve({ appName: "Super " });
    }, 1000);
  });
  return promise;
};

export default indexPage;
