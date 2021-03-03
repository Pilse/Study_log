#include <iostream>

using namespace std;

int N;
int first_flag = 1;
int total;
int largest;
int shortest;
int num[12];


void summation(int tot, int cnt, int plus, int minus ,int mul, int div)
{
    if(cnt==N-1)
    {
        if(first_flag)
        {
            largest=tot;
            shortest=tot;
            first_flag=0;
        }
        else
        {
            largest = max(tot,largest);
            shortest = min(tot,shortest);
        }
        return;
    }
    if(plus)
        summation(tot+num[cnt+1],cnt+1,plus-1,minus,mul,div);
    if(minus)
        summation(tot-num[cnt+1],cnt+1,plus,minus-1,mul,div);
    if(mul)
        summation(tot*num[cnt+1],cnt+1,plus,minus,mul-1,div);
    if(div)
    {
        if(tot<0)
            summation(-(abs(tot)/num[cnt+1]),cnt+1,plus,minus,mul,div-1);
        else
            summation(tot/num[cnt+1],cnt+1,plus,minus,mul,div-1);
    }
}

int main()
{
    cin >> N;
    int plus,minus,mul,div;
    for(int i=0;i<N;i++)
    {
        cin>>num[i];
    }
    cin>>plus>>minus>>mul>>div;

    total = num[0];
    summation(total,0,plus,minus,mul,div);
    cout<<largest<<'\n'<<shortest<<'\n';

}
