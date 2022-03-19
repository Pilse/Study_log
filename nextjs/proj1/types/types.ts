export interface DUMMY_EVENTS {
  id: string;
  title: string;
  description: string;
  location: string;
  date: string;
  image: string;
  isFeatured: boolean;
}

export type DUMMY_EVENTS_ITEM<Type extends keyof DUMMY_EVENTS> =
  DUMMY_EVENTS[Type];
