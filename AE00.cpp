#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <utility>
#include <climits>
#define inp freopen("in.txt", "r", stdin)

int isDebug = 1;

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int sum = n;
    
    for(int i = 2; i <= n; i++)
    {
        int cur = ((n / i) - (i - 1));
        if(cur <= 0) break;
        sum += cur;
    }

    cout<<sum<<"\n";

}

int main()
{
    if(isDebug) inp;

    int t = 1;
    while(t--)
    {
        solve();
    }
}