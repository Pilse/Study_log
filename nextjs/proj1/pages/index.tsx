import { NextPage } from 'next';
import { useRouter } from 'next/router';

const HomePage: NextPage = () => {
  const router = useRouter();

  return (
    <main>
      <h1>hello</h1>

      <button onClick={() => router.push('/events')}>click</button>
    </main>
  );
};

export default HomePage;
