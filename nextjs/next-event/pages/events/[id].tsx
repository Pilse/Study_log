import type {
  NextPage,
  GetStaticPropsContext,
  GetStaticProps,
  GetStaticPaths,
} from "next";
import Head from "next/head";
import EventSummary from "../../components/event-detail/event-summary";
import EventLogistics from "../../components/event-detail/event-logistics";
import EventContent from "../../components/event-detail/event-content";
import { useRouter } from "next/router";
import { getEventById, getFeaturedEvents } from "../../dummy-data";
import { dehydrate, QueryClient, useQuery } from "react-query";

const EventDetails: NextPage = () => {
  const router = useRouter();

  const eventId = router.query.id as string;
  const { data: event } = useQuery(["event", eventId], () =>
    getEventById(eventId)
  );

  if (!event) {
    return <p>No event found!</p>;
  }

  return (
    <>
      <Head>
        <title>{event.title}</title>
      </Head>
      <EventSummary title={event.title} />
      <EventLogistics
        date={event.date}
        address={event.location}
        image={event.image}
        imageAlt={event.title}
      />
      <EventContent>
        <p>{event.description}</p>
      </EventContent>
    </>
  );
};

export const getStaticProps: GetStaticProps = async ({
  params,
}: GetStaticPropsContext) => {
  const queryClient = new QueryClient();
  const eventId = params!.id as string;
  await queryClient.prefetchQuery(["event", eventId], () =>
    getEventById(eventId)
  );

  return {
    props: {
      dehydratedState: dehydrate(queryClient),
    },
    revalidate: 60,
  };
};

export const getStaticPaths: GetStaticPaths = async () => {
  const events = await getFeaturedEvents();
  const paths = events.map((event) => ({ params: { id: event.id } }));
  return {
    paths,
    fallback: false,
  };
};

export default EventDetails;
