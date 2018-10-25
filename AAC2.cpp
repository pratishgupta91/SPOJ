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

struct Node
{
    int parent;
    int rank;
};

class DSet
{
public:
    void makeSet(int a)
    {
        if(m.find(a) != m.end()) return;
        m[a] = {a, 0};
    }

    void union_set(int a, int b)
    {
        int pa = find_parent(a);
        int pb = find_parent(b);

        if(pa != pb)
        {
            if(m[a].rank == m[b].rank)
            {
                m[b].parent = a;
                m[a].rank++;
            }
            else if(m[a].rank > m[b].rank)  m[b].parent = a;
            else m[a].parent = b;
        }
    }

    int find_parent(int a)
    {
        int cur = a;
        while(cur != m[cur].parent)
        {
            cur = m[cur].parent;
        }

        m[a].parent = cur;
        return cur;
    }

    bool isConnected(int a, int b)
    {
        return (find_parent(a) == find_parent(b));
    }

private:
    map<int, Node> m;
};

void solve()
{
    int n, k;
    cin>>n>>k;
    vector<pair<int, int> > eq;
    vector<pair<int, int> > neq;

    for(int i = 0; i < k; i++)
    {
        for(int i = 0; i < 3; i++)
        {
            string temp;
            cin>>temp;

            int a, b;
            bool isEq;
            if(i == 0)
            {
                a = stoi(temp);
            }
            else if(i == 1)
            {
                isEq = (temp == "=");
            }
            else
            {
                b = stoi(temp);
                if(isEq) eq.push_back({a, b});
                else neq.push_back({a, b});
            }

        }
    }

    DSet ds;

    for(int i = 0; i < eq.size(); i++)
    {
        ds.makeSet(eq[i].first);
        ds.makeSet(eq[i].second);

        ds.union_set(eq[i].first, eq[i].second);
    }

    bool isFine = true;
    for(int i = 0; i < neq.size(); i++)
    {
        ds.makeSet(neq[i].first);
        ds.makeSet(neq[i].second);

        if(ds.isConnected(neq[i].first, neq[i].second)) { isFine = false; break; }

    }

    if(isFine) cout<<"YES\n";
    else cout<<"NO\n";
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