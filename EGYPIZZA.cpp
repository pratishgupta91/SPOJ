#include <iostream>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    cin>>n;
    //cout<<n;

    int s = 0;
    int m = 0;
    int l = 0; 

    for(int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        if(str == "1/4") ++s;
        if(str == "1/2") ++m;
        if(str == "3/4") ++l;
    }

    int count = 0;
    int slots = 0;
    count = count + ceil(m / 2.0);
    slots = (m % 2) * 2;
    count += l;
    slots += l;

    //cout<<slots<<count<<s<<ceil(1/4.0);;
    s = s - slots;

    if(s > 0)
    {
        count = count + ceil(s / 4.0);
    }

    cout<< count + 1 <<"\n";
}