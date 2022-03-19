import { NextPage } from "next";
import Head from "next/head";
import { useRouter } from "next/router";

const SelectedClientProjectsPage: NextPage = () => {
  const router = useRouter();

  return (
    <>
    <Head>
      <title>hi</title>
    </Head>
    <div>
      <h1>The Projects page for a {router.query.clientprojectId} of a {router.query.id}</h1>
    </div>
    </>
  )
}

export default SelectedClientProjectsPage