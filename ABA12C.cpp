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
    map<int, int> kgPrice;

    for(int i = 1; i <= k; i++)
    {
        int price;
        cin>>price;
        if(price > -1)
            kgPrice[i] = price;
    }

    vector<int> packCount;
    packCount.resize(k + 1, INT_MAX);
    vector<int> minPrice;
    minPrice.resize(k + 1, INT_MAX);

    packCount[0] = 0;
    minPrice[0] = 0;
    int res = INT_MAX;
    
    for(auto it = kgPrice.begin(); it != kgPrice.end(); ++it)
    {
        bool shouldAbort = false;
        for(int i = it->first; i <= k; ++i)
        {
            if(minPrice[i - it->first] + it->second < minPrice[i])
            {
                packCount[i] = min(packCount[i], packCount[i - it->first] + 1);
                minPrice[i] = min(minPrice[i], minPrice[i - it->first] + it->second);
            }
            if(packCount[i] == n) res = min(res, packCount[i]);

            if(i == k && packCount[i] < n) shouldAbort = true;
        }

        if(shouldAbort) break;
    }

    if(res == INT_MAX) res = -1;
    cout << res <<"\n";

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