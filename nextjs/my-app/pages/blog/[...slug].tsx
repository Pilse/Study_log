import { NextPage } from "next";
import { useRouter } from "next/router";

const BlogPostsPage: NextPage = () => {
  const router = useRouter();

  console.log(router.query, 1);

  return (
    <main>
      <h1>The Blog Posts</h1>
    </main>
  )
}

export default BlogPostsPage;