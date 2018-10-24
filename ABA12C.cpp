#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <climits>
#define inp freopen("in.txt", "r", stdin)

int isDebug = 1;

using namespace std;

void solve()
{
    int n, k;
    cin>>n>>k;

    if(n == 0 || k == 0) { cout<<"-1\n";  return; }

    map<int, int> kgPrice;

    for(int i = 1; i <= k; i++)
    {
        int price;
        cin>>price;
        if(price > -1)
            kgPrice[i] = price;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

    for(int i = 1; i <= k; i++)
    {
        dp[1][i] = (kgPrice.find(i) == kgPrice.end() ? INT_MAX : kgPrice[i]);
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = i; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            for(int q = i - 1; q <= j - 1; q++)
            {
                if(dp[i - 1][q] != INT_MAX && kgPrice.find(j - q) != kgPrice.end())
                {
                     dp[i][j] = min(dp[i][j], dp[i - 1][q] + kgPrice[j - q]);
                }
            }
        }


    }

    int res = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        res = min(res, dp[i][k]);
        // for(int j = 1; j <= k; j++)
        // {
        //     cout<<dp[i][j]<<" ";
        // }
        // cout<<"\n";
    }
    

    res = (res == INT_MAX) ? -1 : res;
    cout<< res <<"\n";

}

int main()
{
    //if(isDebug) inp;;

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}