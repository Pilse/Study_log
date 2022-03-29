import {
  GetStaticPaths,
  GetStaticProps,
  GetStaticPropsContext,
  InferGetStaticPropsType,
  NextPage,
} from "next";
import fs from "fs/promises";
import path from "path";

import { HomeProps } from "../index";

type ProductDetailProps = {
  product: {
    id: string;
    title: string;
    description: string;
  };
};

const ProductDetail = ({
  product,
}: InferGetStaticPropsType<typeof getStaticProps>) => {
  return (
    <>
      <h1>{product.title}</h1>
      <p>{product.description}</p>
    </>
  );
};

const getData = async (): Promise<HomeProps> => {
  const filePath = path.join(process.cwd(), "dummy-backend.json");
  const jsonData = await fs.readFile(filePath);
  const data = JSON.parse(jsonData.toString());

  return data;
};

export const getStaticProps: GetStaticProps<ProductDetailProps> = async ({
  params,
}: GetStaticPropsContext) => {
  const productId = params!.pid;

  const data = await getData();

  const product = data.products.find((product) => product.id === productId);

  if (product) {
    return {
      props: {
        product,
      },
    };
  } else {
    return { notFound: true };
  }
};

export const getStaticPaths: GetStaticPaths = async () => {
  const data = await getData();

  const ids = data.products.map((product) => product.id);

  const params = ids.map((id) => ({ params: { pid: id } }));

  return {
    paths: params,
    fallback: "blocking",
  };
};

export default ProductDetail;
