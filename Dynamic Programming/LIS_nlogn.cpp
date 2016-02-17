#include <iostream>
#define endl '\n'
using namespace std;

int n, a[5005], dp[5005], sizeOfLis = 1;

int binarySearch(int target)
{
    int le = 1, ri = sizeOfLis, mid, nearestRight = -1;

    while(le <= ri)
    {
        mid = (le+ri)/2;

        if(dp[mid] > target)
        {
            nearestRight = mid;
            ri = mid-1;
        }
        else if(dp[mid] < target) le = mid+1;
        else return mid;
    }

    return nearestRight;
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

    dp[1] = a[0];
    for(int i = 1; i < n; i++)
    {
        if(dp[sizeOfLis] <= a[i]) dp[++sizeOfLis] = a[i];
        else
        {
            int nearestRight = binarySearch(a[i]);

            dp[nearestRight] = a[i];
        }
    }

    cout<<sizeOfLis<<endl;
    return 0;
}
