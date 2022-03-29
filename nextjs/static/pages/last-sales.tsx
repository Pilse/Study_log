import { GetStaticProps, InferGetStaticPropsType } from "next";
import { useState, useEffect } from "react";
import { useQuery } from "react-query";

interface PostProps {
  username: string;
  title: string;
}

const LastSales = ({
  filtered,
}: InferGetStaticPropsType<typeof getStaticProps>) => {
  const [posts, setPosts] = useState(filtered);

  const { data, isLoading, error } = useQuery<
    { title: string; username: string }[]
  >("posts", async () => {
    const res = await fetch("https://cs-roadmap.com/api/board/posts/page/1/79");
    const data = await res.json();
    return data.posts;
  });

  useEffect(() => {
    if (data) {
      setPosts(() => data);
    }
  }, [data]);

  if (error) {
    return <p>Error</p>;
  }

  if (!!posts) {
    return (
      <ul>
        {posts.map((post) => (
          <li key={post.title}>
            {post.title} - {post.username}
          </li>
        ))}
      </ul>
    );
  }
};

export const getStaticProps: GetStaticProps<{
  filtered: PostProps[];
}> = async () => {
  const res = await fetch("https://cs-roadmap.com/api/board/posts/page/1/79");
  const data = await res.json();

  const filtered = data.posts.map((ele: PostProps) => ({
    title: ele.title,
    username: ele.username,
  })) as PostProps[];

  if (filtered.length > 0) {
    return {
      props: {
        filtered,
      },
      revalidate: 10,
    };
  } else {
    return { notFound: true };
  }
};

export default LastSales;
