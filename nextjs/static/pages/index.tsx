import type { NextPage, GetStaticProps } from "next";
import fs from "fs/promises";
import path from "path";

import styles from "../styles/Home.module.css";
import Link from "next/link";

export type HomeProps = {
  products: {
    id: string;
    title: string;
    description: string;
  }[];
};

const Home: NextPage<HomeProps> = ({ products }) => {
  return (
    <div className={styles.container}>
      <ul>
        {products.map((product) => (
          <li key={product.id}>
            <Link href={`/${product.id}`}>{product.title}</Link>
          </li>
        ))}
      </ul>
      <Link href="/last-sales">click</Link>
    </div>
  );
};

export const getStaticProps: GetStaticProps = async (context) => {
  const filePath = path.join(process.cwd(), "dummy-backend.json");
  const jsonData = await fs.readFile(filePath);
  const data = JSON.parse(jsonData.toString());

  if (!data) {
    return {
      redirect: {
        destination: "/no-data",
        permanent: false,
      },
    };
  }

  if (data.products.length === 0) {
    return { notFound: true };
  }

  return {
    props: {
      products: data.products,
    },
    revalidate: 10,
  };
};

export default Home;
