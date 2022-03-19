import { NextPage } from 'next';
import Link from 'next/link';

import { DUMMY_EVENTS } from '../../types/types';

interface EventItemProps {
  item: DUMMY_EVENTS;
}

const EventItem: NextPage<EventItemProps> = ({ item }) => {
  const { title, image, date, location, id } = item;

  const humanReadableDate = new Date(date).toLocaleDateString('kr-KO', {
    day: 'numeric',
    month: 'long',
    year: 'numeric',
  });

  const formatedAddress = location.replace(', ', '\n');

  const exploreLink = `/events/${id}`;

  return (
    <li>
      <img src={image} alt={image} />
      <div>
        <div>
          <h2>{title}</h2>

          <div>
            <time>{humanReadableDate}</time>
          </div>

          <div>
            <address>{formatedAddress}</address>
          </div>
        </div>

        <div>
          <Link href={exploreLink}>Explore Event</Link>
        </div>
      </div>
    </li>
  );
};

export default EventItem;
