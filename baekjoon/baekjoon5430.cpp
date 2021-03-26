#include <iostream>
#include <deque>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{

    int t;

    scanf("%d", &t)

        for (int i = 0; i < t; i++)
    {
        string str;
        int num;
        char arr[500000];
        char temp[1000];
        int j = 0;
        int flag = 1;
        deque<int> dq;

        cin >> str;
        scanf("%d", &num);
        scanf("%s", arr);

        for (int i = 1; i < strlen(arr); i++)
        {
            if (arr[i] == ',' || arr[i] == ']')
            {
                temp[j] = arr[i];
                if (j != 0)
                    dq.push_back(atoi(temp));
                j = 0;
            }
            else
                temp[j++] = arr[i];
        }
        int cnt = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'D')
                cnt++;
        }
        if (cnt > dq.size())
            printf("error\n");
        else
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == 'R')
                    flag = (flag + 1) % 2;
                if (str[i] == 'D')
                {
                    if (flag)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
            }
            if (i == str.length() - 1)
            {
                int s = dq.size();
                printf("[");
                for (int l = 0; l < s; l++)
                {
                    if (flag)
                    {
                        printf("%d", dq.front());
                        if (j != dq.size() - 1)
                            printf(",");
                        dq.pop_front();
                    }
                    else
                    {
                        printf("%d", dq.back());
                        if (j != dq.size() - 1)
                            printf(",");
                        dq.pop_back();
                    }
                }
                printf("]\n");
            }
        }
    }
}
}
