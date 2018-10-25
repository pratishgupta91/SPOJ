#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 1000001
#define M 1000000007
#define ll long long
#define ld long double
#define ESP 0.0001
using namespace std;
#define inp freopen("in.txt", "r", stdin)

int n, k, p[MAX];

int getRoot(int x){
	if (p[x]==x) return x;
	else return getRoot(p[x]);
}

int union_(int x, int y){
	int rx = getRoot(x);
	int ry = getRoot(y);
	if (rx!=ry){
		p[rx] = ry;
	}
	return 0;
}

int main(){
    inp;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for (int i=0;i<=n;i++){
			p[i] = i;
		}
		vector < pair<int,int> > unequal;
		for (int i=0;i<k;i++){
			int x, y;
			char comp[3];
			scanf("%d%s%d", &x, comp, &y);
			if (comp[0]=='='){
				union_(x, y);
			}
			else{
				unequal.push_back(make_pair(x,y));
			}
		}
		int flag = 0;
		for (vector< pair<int,int> >::iterator it = unequal.begin();it!=unequal.end();it++){
			int rx = getRoot((*it).first);
			int ry = getRoot((*it).second);
			if (rx==ry){
				flag = 1;
				break;
			}
		}
		if (flag){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}