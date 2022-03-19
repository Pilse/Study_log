import { NextPage } from 'next';

import EventList from '../../components/events/EventList';
import { getFeaturedEvents } from '../../data/dummy-data';

const EventsPage: NextPage = () => {
  const featuredEvents = getFeaturedEvents();

  return (
    <main>
      <EventList lists={featuredEvents} />
    </main>
  );
};

export default EventsPage;
