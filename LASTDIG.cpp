#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define x vector<int>
#define p push_back
int main()
{
    freopen("in.txt", "r", stdin);
    int t; cin>>t;
    vector<x > m;
    x v0={0}; x v1={1}; x v2={6,2,4,8}; x v3={1,3,9,7}; x v4={6,4}; 
    x v5={5}; x v6={6}; x v7={1,7,9,3}; x v8={6,8,4,2}; x v9={1,9};
    m.p(v0);m.p(v1);m.p(v2);m.p(v3);m.p(v4);m.p(v5);m.p(v6);m.p(v7);m.p(v8);m.p(v9);
    while(t--)
    {
        string a; cin>>a;
        int u = a[a.length() - 1] - '0';
        unsigned long long b; cin>>b;
        if(a == "0") {cout<<"0\n"; continue;} if(b == 0) {cout<<"1\n";continue;}
        cout<<m[u][b % m[u].size()]<<"\n";
    }
}