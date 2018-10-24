#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

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
        kgPrice[i] = price;
    }

    vector<int> packCount;
    packCount.reserve()
    vector<int> minPrice;
    
    for(auto it = kgPrice.begin(), it != kgPrice.end(); ++it)
    {
    int res = 0;


}

int main()
{
    int t;
    cin>>t;
    while(--t)
    {
        solve();
    }
}