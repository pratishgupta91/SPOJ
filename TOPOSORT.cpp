#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define x vector<int>
#define pb push_back

map<int, x > g;
//vector
void DFS(int v)
{
    
} 

int main()
{
    freopen("in.txt", "r", stdin);
    int vertexCount = 0;
    int edgeCount = 0;
    cin>>vertexCount>>edgeCount;

    int start, end;

    for(int i = 0; i < edgeCount; i++)
    {
        cin>>start>>end;
        if(g.find(start) == g.end())
        {
            x v;
            g[start] = v;
        }
        g[start].pb(end);
    }

    for(auto i = g.begin(); i != g.end(); i++)
    {
        cout<<i->first<<" -> ";
        x v = i->second;
        sort(v.begin(), v.end());
        i->second = v;

        for(int j = 0; j < v.size(); j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<"\n";
    }

    for(int i = vertexCount; i > 0; i--)
    {
        DFS(i);
    }
}