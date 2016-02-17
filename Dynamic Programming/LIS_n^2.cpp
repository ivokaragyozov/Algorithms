#include <iostream>
#define endl '\n'
using namespace std;

int n, a[5005], dp[5005], par[5005], indOfLast, maxLen;

void printLIS()
{
    int i = indOfLast, seq[5005], indInSeq = 0;

    while(1)
    {
        seq[indInSeq++] = a[i];

        if(i == par[i]) break;
        i = par[i];
    }

    cout<<seq[indInSeq-1];
    for(int i = indInSeq-2; i >= 0; i--)
    {
        cout<<" "<<seq[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    dp[0] = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j >= 0; j--)
        {
            if(dp[j]+1 > dp[i] && a[j] <= a[i])
            {
                dp[i] = dp[j]+1;
                par[i] = j;
            }
        }

        if(dp[i] > maxLen)
        {
            maxLen = dp[i];
            indOfLast = i;
        }
    }

    cout<<"Length of LIS is: "<<maxLen<<endl;
    cout<<"One of the possible LISes is: ";
    printLIS();
    return 0;
}
