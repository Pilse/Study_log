import type { NextPage } from "next";
import Head from "next/head";
import { useRouter } from "next/router";
import EventList from "../../components/events/event-list";
import EventsSearch from "../../components/events/events-search";
import { useQuery } from "react-query";
import { getAllEvents } from "../../dummy-data";

const Events: NextPage = () => {
  const { data: events } = useQuery("allEvents", getAllEvents);
  const router = useRouter();

  const findEventsHandler = (year: string, month: string) => {
    const fullPath = `/events/${year}/${month}`;
    router.push(fullPath);
  };

  if (!events) return <div>loading</div>;

  return (
    <div>
      <Head>
        <title>All Events</title>
      </Head>
      <EventsSearch onSearch={findEventsHandler} />
      <EventList items={events} />
    </div>
  );
};

export default Events;
