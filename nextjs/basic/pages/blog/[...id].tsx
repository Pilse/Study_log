import type { NextPage } from "next";
import { useRouter } from "next/router";

const Blog: NextPage = () => {
  const router = useRouter();

  return (
    <div>
      <h1>The Blog Page</h1>
    </div>
  );
};

export default Blog;
