#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
#define x vector<int>
#define pb push_back
#define inp freopen("in.txt", "r", stdin)
#define lup(a, b, c) for(int a = b; a < c; a++)

int main()
{
    inp;

    int t;
    cin>>t;

    while(t--)
    {

        int n;
        scanf("%d", &n);
        x v;

        int sig;
        lup(i, 0, n)
        {
            scanf("%d", &sig);
            v.pb(sig);
        }

        sort(v.begin(), v.end());
        int cur = v[0];
        int mi = n / 2;
        int target = v[mi];
        int count = 0;
        lup(i, mi, n)
        {
            if(v[i] == target) count++;
            else break;
        }

        for(int i = mi - 1; i >= 0; i--)
        {
            if(v[i] == target) count++;
            else break;
        }

        //cout<<count<<target;
        if(count > mi)
        {
            cout<<"YES "<<target;
        }
        else
        {
            cout<<"NO";
        }
        cout<<"\n";
    }
}
