import type { AppProps } from 'next/app';
import { useState } from 'react';
import { QueryClientProvider, Hydrate, QueryClient } from 'react-query';
import GlobalStyles from '../styles/global';

function MyApp({ Component, pageProps }: AppProps) {
  const [client] = useState(new QueryClient());

  return (
    <QueryClientProvider client={client}>
      <Hydrate state={pageProps.dehydratedState}>
        <GlobalStyles />
        <Component {...pageProps} />
      </Hydrate>
    </QueryClientProvider>
  );
}

export default MyApp;
