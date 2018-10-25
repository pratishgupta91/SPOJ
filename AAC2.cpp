#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <utility>
#include <unordered_map>
#include <climits>
#define inp freopen("in.txt", "r", stdin)

int isDebug = 1;

using namespace std;

class DSet
{
public:
    void makeSet(int a)
    {
        m[a] = a;
    }

    void union_set(int a, int b)
    {
        int pa = find_parent(a);
        int pb = find_parent(b);

        if(pa != pb)
        {
            m[pa] = pb;
        }
    }

    int find_parent(int a)
    {
        int cur = a;
        while(cur != m[cur])
        {
            cur = m[cur];
        }

        return cur;
    }

    bool isConnected(int a, int b)
    {
        return (find_parent(a) == find_parent(b));
    }

private:
    int m[1000001];
};

void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    DSet ds;

    for(int i = 0; i <= n; i++)
    {
        ds.makeSet(i);
    }

    vector<pair<int, int> > eq;
    vector<pair<int, int> > neq;


    for(int i = 0; i < k; i++)
    {
        int a, b;
		char comp[3];
		scanf("%d%s%d", &a, comp, &b);
        if (comp[0]=='='){
            ds.union_set(a, b);
        }
        else{
            neq.push_back(make_pair(a,b));
        }
    }

    bool isFine = true;

    for(int i = 0; i < neq.size(); i++)
    {
        if(ds.isConnected(neq[i].first, neq[i].second)) {isFine = false; break; }
    }
    if (!isFine){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}

int main()
{
    if(isDebug) inp;

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}