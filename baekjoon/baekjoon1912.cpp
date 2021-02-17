#include <iostream>

using namespace std;

int arr[100010];
int dp[100010];

int main()
{
    int sum = 0;
    int n;
    int negative_flag = 1;
    int largest = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= 0)
            negative_flag = 0;
    }
    if (!negative_flag)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[0] = arr[0];
            }
            else
            {
                dp[i] = max(dp[i - 1], sum + arr[i]);
            }
            sum = sum + arr[i];
            if (sum < 0)
                sum = 0;
        }
        cout << dp[n - 1] << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(i==0)
                largest=arr[i];
            else
            {
                largest=max(largest,arr[i]);
            }
        }
        cout<< largest << endl;
        return 0;
    }
    
}
