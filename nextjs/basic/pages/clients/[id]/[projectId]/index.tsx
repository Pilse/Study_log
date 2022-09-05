import type { NextPage } from "next";
import { useRouter } from "next/router";

const SelectedClientProject: NextPage = () => {
  const router = useRouter();

  return (
    <div>
      <h1>The Project Page for {router.query.projectId}</h1>
    </div>
  );
};

export default SelectedClientProject;
