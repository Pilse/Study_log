import "./App.css";
import { Suspense } from "react";
import { QueryClient, QueryClientProvider } from "react-query";
import { ReactQueryDevtools } from "react-query/devtools";

import { InfinitePeople } from "./people/InfinitePeople";
import { InfiniteSpecies } from "./species/InfiniteSpecies";

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
        <h1>Infinite SWAPI</h1>
        <Suspense fallback={<h3>Loading...</h3>}>
          {/* <InfinitePeople /> */}
          <InfiniteSpecies />
        </Suspense>
      </div>
      <ReactQueryDevtools />
    </QueryClientProvider>
  );
}

export default App;
