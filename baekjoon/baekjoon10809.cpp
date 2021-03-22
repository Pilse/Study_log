#include <iostream>
#include <string>

using namespace std;

int main()
{
    char arr[110];

    cin.getline(arr, sizeof(arr));

    int loca = -1;
    char a = 'a';

    for (int i = 0; i < 26; i++)
    {
        loca = -1;
        for (int j = 0; arr[j] != '\0'; j++)
            if (arr[j] == a)
            {
                loca = j;
                break;
            }

        printf("%d ", loca);

        a++;
    }
}
