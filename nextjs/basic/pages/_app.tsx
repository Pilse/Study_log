import "../styles/globals.css";
import type { AppProps } from "next/app";

function MyApp({ Component, pageProps }: AppProps) {
  return (
    <>
      <h1>The Home Page</h1>
      <Component {...pageProps} />
    </>
  );
}

export default MyApp;
