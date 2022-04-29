import { AxiosResponse } from 'axios';
import { useQuery, useQueryClient } from 'react-query';

import type { User } from '../../../../../shared/types';
import { axiosInstance, getJWTHeader } from '../../../axiosInstance';
import { queryKeys } from '../../../react-query/constants';
import {
  clearStoredUser,
  getStoredUser,
  setStoredUser,
} from '../../../user-storage';

async function getUser(
  user: User | null,
  signal: AbortSignal,
): Promise<User | null> {
  if (!user) return null;
  const { data }: AxiosResponse<{ user: User }> = await axiosInstance.get(
    `/user/${user.id}`,
    {
      headers: getJWTHeader(user),
      signal,
    },
  );
  return data.user;
}

interface UseUser {
  user: User | null;
  updateUser: (user: User) => void;
  clearUser: () => void;
}

export function useUser(): UseUser {
  const queryClient = useQueryClient();
  const { data: user } = useQuery<User | null>(
    queryKeys.user,
    ({ signal }) => getUser(user, signal),
    {
      initialData: getStoredUser(),
      onSuccess: (received: User | null) => {
        if (!received) clearStoredUser();
        else setStoredUser(received);
      },
    },
  );

  // meant to be called from useAuth
  function updateUser(newUser: User): void {
    queryClient.setQueriesData(queryKeys.user, newUser);
  }

  // meant to be called from useAuth
  function clearUser() {
    queryClient.setQueriesData(queryKeys.user, null);
    queryClient.removeQueries([queryKeys.appointments, queryKeys.user]);
  }

  return { user, updateUser, clearUser };
}
