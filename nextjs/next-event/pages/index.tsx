import type { GetStaticProps, NextPage } from "next";
import Head from "next/head";
import { getFeaturedEvents } from "../dummy-data";
import EventList from "../components/events/event-list";
import { dehydrate, QueryClient, useQuery } from "react-query";

const Home: NextPage = () => {
  const { data: featuredEvents } = useQuery(
    "featuredEvents",
    getFeaturedEvents
  );

  if (!featuredEvents) return <div>loading</div>;

  return (
    <div>
      <Head>
        <title>Next JS Events</title>
        <meta name="description" content="hello nextjs" />
      </Head>
      <EventList items={featuredEvents} />
    </div>
  );
};

export const getStaticProps: GetStaticProps = async () => {
  const client = new QueryClient();
  await client.prefetchQuery("featuredEvents", getFeaturedEvents);
  return {
    props: {
      dehydratedState: dehydrate(client),
    },
    revalidate: 60,
  };
};

export default Home;
