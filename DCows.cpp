#include <iostream>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int n, m;
    cin>>n>>m;

    if(n == 0 || m == 0)
    {
        cout<<"0\n";
        return 0;
    }
    //cout<<n<<m<<"\n";
    int b[n];
    int c[m];

    long dp[n];

    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin>>c[i];
    }

    sort(b, b + n);
    sort(c, c + m);

    // for(int i = 0; i < n; i++)
    // {
    //     cout<<b[i]<<" ";
    // }
    // cout<<"\n";

    // for(int i = 0; i < m; i++)
    // {
    //     cout<<c[i]<<" ";
    // }
    // cout<<"\n";

    for(int i = 0; i < m; i++)
    {
        for(int j = min(i, n - 1); j >= 0; j--)
        {
            if(i == 0)
            {
                dp[j] = abs(c[i] - b[j]);
            }

            else if(j == 0)
            {
                dp[j] = dp[j] < abs(c[i] - b[j]) ? dp[j] : abs(c[i] - b[j]);
            }

            else
            {
                if(i < n && i == j)
                {
                    dp[j] = dp[j - 1] + abs(c[i] - b[j]);
                }
                else
                {
                    long temp = dp[j - 1] + abs(c[i] - b[j]);
                    dp[j] = dp[j] < temp ? dp[j] : temp;
                }
            }
            cout<<dp[j]<<" ";
        }
        cout<<"\n";
    }

    cout<<dp[n - 1]<<"\n";
}