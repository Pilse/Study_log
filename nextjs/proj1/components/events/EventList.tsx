import { NextPage } from 'next';
import { DUMMY_EVENTS } from '../../types/types';
import EventItem from './EventItem';

interface EventListProps {
  lists: DUMMY_EVENTS[];
}

const EventList: NextPage<EventListProps> = ({ lists }) => {
  return (
    <ul>
      {lists.map(list => (
        <EventItem key={list.id} item={list} />
      ))}
    </ul>
  );
};

export default EventList;
