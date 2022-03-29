import {
  GetServerSideProps,
  GetServerSidePropsContext,
  InferGetServerSidePropsType,
} from "next";

interface UserProfileProps {
  username: string;
}

const UserProfile = ({
  username,
}: InferGetServerSidePropsType<typeof getServerSideProps>) => {
  return <h1>{username}</h1>;
};

export const getServerSideProps: GetServerSideProps<UserProfileProps> = async (
  context: GetServerSidePropsContext
) => {
  const { params, req, res } = context;

  console.log(req);
  console.log(res);

  return {
    props: {
      username: "Max",
    },
  };
};

export default UserProfile;
