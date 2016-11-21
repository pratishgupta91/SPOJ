#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define x vector<int>
#define pb push_back

map <int, x > g;
map <int, x > gt;
map <int, int> visited;
x fOrder;
x compIndex;

bool isVisited(int v)
{
     if(visited.find(v) == visited.end())
     {
         return false;
     }
     return (visited[v] == 1);
}

void makeVisited(int v)
{
    visited[v] = 1;
}

void clearVisited(int v)
{
    visited[v] = 0;
}

void DFS1(int v)
{
    if(!isVisited(v))
    {
        makeVisited(v);
        //cout<<v<<" visited\n";
        if(g.find(v) != g.end())
        {
            x adj = g[v];
             //cout<<"nbh size "<<adj.size()<<"\n";
            for(int i = 0; i < adj.size(); i++)
            {
                DFS1(adj[i]);
            }
        }
        //cout<<"added: "<<v<<"\n";
        fOrder.pb(v);
    }
} 

void DFS2(int v, int comp)
{
    if(isVisited(v))
    {
        compIndex[v] = comp;
        clearVisited(v);
        //cout<<v<<" visited\n";
        if(gt.find(v) != gt.end())
        {
            x adj = gt[v];
             //cout<<"nbh size "<<adj.size()<<"\n";
            for(int i = 0; i < adj.size(); i++)
            {
                DFS2(adj[i], comp);
            }
        }
    }
} 

int main()
{
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        g.clear();
        gt.clear();
        fOrder.clear();
        visited.clear();
        compIndex.clear();

        int vertexCount;
        scanf("%d",&vertexCount);
        
        compIndex.resize(vertexCount + 1, 0);
        
        for(int i = 1; i <= vertexCount; i++)
        {
            int ec;
            scanf("%d", &ec);
            int end = i;

            if(gt.find(end) == gt.end())
            {
                x v;
                gt[end] = v;
            }

            for(int j = 0; j < ec; j++)
            {
                int start;
                scanf("%d",&start);
                if(g.find(start) == g.end())
                {
                    x v;
                    g[start] = v;
                }
                g[start].pb(end);
                gt[end].pb(start);
            }
        }

        // for(auto i = g.begin(); i != g.end(); i++)
        // {
        //     cout<<i->first<<" -> ";
        //     x v = i->second;
            
        //     for(int j = 0; j < v.size(); j++)
        //     {
        //         cout<<v[j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        

        for(int i = 1; i <= vertexCount; i++)
        {
            if(!isVisited(i))
            {
                DFS1(i);
            }
            
        }

        // for(int i = 0; i < fOrder.size(); i++)
        // {
        //     cout<<fOrder[i]<<" ";
        // }

        // cout<<"\n";

        int compCount = 0;

        for(int i = fOrder.size() - 1; i >= 0; i--)
        {
            if(isVisited(fOrder[i]))
            {
                //cout<<"dfs2 for "<<fOrder[i]<<"\n";
                DFS2(fOrder[i], compCount);
                compCount++;
            }
        }

        //cout<<compCount;
        // for(int i = 1; i <= vertexCount; i++)
        // {
        //     cout<<compIndex[i]<<" ";
        // }

        // cout<<"\n";

        x ind;
        ind.resize(compCount, 0);

        for(auto i = g.begin(); i != g.end(); i++)
        {
            x v = i->second;
            
            for(int j = 0; j < v.size(); j++)
            {
                if(compIndex[i->first] != compIndex[v[j]])
                {
                    ind[compIndex[v[j]]]++;
                }
            }
        }

        //cout<<ind.size();
        int count = 0;
        int index = 0;
        for(int i = 0; i < ind.size(); i++)
        {
            if(ind[i] == 0)
            {
                ++count;
                index = i;
            }
        }

        if(count != 1)
        {
            cout<<"0\n";
        }
        else
        {
            int desiredCompIndex = ind[index];
            //cout<<desiredCompIndex;
            count = 0;

            for(int i = 1; i  < compIndex.size(); i++)
            {
                //cout<<compIndex[i]<<" ";
                if(compIndex[i] == desiredCompIndex)
                {
                    ++count;
                }
            }

            cout<<count<<"\n";
        }
    }

    return 0;
}