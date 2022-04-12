import { Posts } from "./Posts";
import "./App.css";
import { Suspense } from "react";
import { ErrorBoundary } from "react-error-boundary";
import Error from "./Error";

import {
  QueryClient,
  QueryClientProvider,
  QueryErrorResetBoundary,
} from "react-query";
import { ReactQueryDevtools } from "react-query/devtools";

const queryClient = new QueryClient({
  defaultOptions: {
    queries: {
      suspense: true,
    },
  },
});

function App() {
  return (
    <QueryClientProvider client={queryClient}>
      <div className="App">
        <h1>Blog Posts</h1>

        <QueryErrorResetBoundary>
          {({ reset }) => (
            <ErrorBoundary
              fallbackRender={({ resetErrorBoundary }) => (
                <>
                  <Error />
                  <button onClick={() => resetErrorBoundary()}>
                    try again
                  </button>
                </>
              )}
              onReset={reset}
            >
              <Suspense fallback={<h3>Loading...</h3>}>
                <Posts />
              </Suspense>
            </ErrorBoundary>
          )}
        </QueryErrorResetBoundary>
      </div>
      <ReactQueryDevtools />
    </QueryClientProvider>
  );
}

export default App;
