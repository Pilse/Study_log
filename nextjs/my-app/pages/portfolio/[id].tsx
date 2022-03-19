import type { NextPage } from "next";
import { useRouter } from "next/router";

const PortfolioProjectPage: NextPage = () => {
  const router = useRouter()

  return (
    <main>
      <h1>Portfolio {router.query.id} Page</h1>
    </main>
  )
}

export default PortfolioProjectPage;