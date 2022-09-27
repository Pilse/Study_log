import "../styles/globals.css";
import type { AppProps } from "next/app";
import { useEffect, useState } from "react";

function MyApp({ Component, pageProps }: AppProps) {
  const [state, setState] = useState(1);
  useEffect(() => {
    console.log(state);
  }, [state]);

  return (
    <>
      <button onClick={() => setState((prev) => prev + 1)}>button</button>
      <Component {...pageProps} />
    </>
  );
}

export default MyApp;
