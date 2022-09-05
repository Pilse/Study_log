import type { NextPage } from "next";
import { useRouter } from "next/router";

const PortfolioProject: NextPage = () => {
  const router = useRouter();
  return (
    <div>
      <h1>The {router.query.id} Page</h1>
    </div>
  );
};

export default PortfolioProject;
