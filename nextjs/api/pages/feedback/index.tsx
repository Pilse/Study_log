import { GetStaticProps, InferGetStaticPropsType } from "next";
import { useState } from "react";
import { buildFeedbackPath, extractFeedback } from "../api/feedback";

type FeedbackType = {
  id: string;
  email: string;
  text: string;
}[];

function Feedback({
  feedbacks,
}: InferGetStaticPropsType<typeof getStaticProps>) {
  const [feedbackData, setFeedbackData] = useState<{
    id: string;
    email: string;
    text: string;
  }>();

  async function loadFeedbackHandler(id: string) {
    const res = await fetch("/api/" + id);
    const data = await res.json();
    setFeedbackData(() => data.feedback);
  }
  return (
    <>
      {feedbackData && <p>{feedbackData.email}</p>}
      <ul>
        {feedbacks.map((item) => (
          <li key={item.id}>
            {item.text}{" "}
            <button onClick={loadFeedbackHandler.bind(null, item.id)}>
              Show Details
            </button>
          </li>
        ))}
      </ul>
    </>
  );
}

export const getStaticProps: GetStaticProps<{
  feedbacks: FeedbackType;
}> = () => {
  const filePath = buildFeedbackPath();
  const data = extractFeedback(filePath);

  return {
    props: {
      feedbacks: data,
    },
  };
};

export default Feedback;
