import { GetServerSideProps, InferGetServerSidePropsType } from "next";

interface UserIdProps {
  id: string;
}

const UserId = ({
  id,
}: InferGetServerSidePropsType<typeof getServerSideProps>) => {
  return <h1>{id}</h1>;
};

export const getServerSideProps: GetServerSideProps<UserIdProps> = async (
  context
) => {
  const { params } = context;

  if (!params) return { notFound: true };

  const userId = params.uid;

  return {
    props: {
      id: "userid-" + userId,
    },
  };
};

export default UserId;
