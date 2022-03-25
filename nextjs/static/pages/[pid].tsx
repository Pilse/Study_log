import { GetStaticProps, NextPage } from "next";
import fs from "fs/promises";
import path from "path";

import { HomeProps } from "./index";

type ProductDetailProps = {
  id: string;
  title: string;
  description: string;
};

const ProductDetail: NextPage<ProductDetailProps> = ({
  id,
  title,
  description,
}) => {
  return (
    <>
      <h1>{title}</h1>
      <p>{description}</p>
    </>
  );
};

export const getStaticProps: GetStaticProps = async (context) => {
  const { params } = context;

  const productId = params!.pid;

  const filePath = path.join(process.cwd(), "dummy-backend.json");
  const jsonData = await fs.readFile(filePath);
  const data = JSON.parse(jsonData.toString()) as HomeProps;

  const product = data.products.find((product) => product.id === productId);

  if (product) {
    return {
      props: {
        product,
      },
      revalidate: 10,
    };
  } else {
    return { notFound: true };
  }
};

export default ProductDetail;
