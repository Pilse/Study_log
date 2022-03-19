import { NextPage } from "next";
import { useRouter } from "next/router";

const ClientProjectsPage: NextPage = () => {
  const router = useRouter();

  const loadProjectHandler = () => {
    router.push('/clients/max/projecta');
  }

  return (
    <div>
      <h1>The Projects of a {router.query.id}</h1>

      <button onClick={loadProjectHandler}>Load Project A</button>
    </div>
  )
}

export default ClientProjectsPage