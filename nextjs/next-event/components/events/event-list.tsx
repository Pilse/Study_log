import type { NextPage } from "next";
import EventItem from "./event-items";
import type { DummyEvent } from "../../dummy-data";

import classes from "./event-list.module.css";

type EventListProps = {
  items: DummyEvent[];
};

const EventList: NextPage<EventListProps> = ({ items }) => {
  return (
    <ul className={classes.list}>
      {items.map((event) => (
        <EventItem
          key={event.id}
          id={event.id}
          title={event.title}
          location={event.location}
          date={event.date}
          image={event.image}
        />
      ))}
    </ul>
  );
};

export default EventList;
