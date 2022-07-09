#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n, h[MAXN], p[MAXN][20], par[MAXN];


void dfs(int u){
	if(h[u]>0) return;
	if(par[u] == 0) h[u] = 1;
	else{
		dfs(par[u]);
		h[u] = h[par[u]] + 1;
	}
}
int getbit(int x, int i){
	return (x>>i)&1;
}
int lca(int u, int v){
	if(h[u]<h[v]) swap(u,v);
	//u la dinh co do sau lon hon v => nhay u
	//B1: nhay u sao cho h[u] = h[v]
	int x = h[u] - h[v];

	for(int i = 0; i<20; i++)
		if(getbit(x,i)==1){
			u = p[u][i];
		}
	if(u==v) return u;
	for(int i = 19; i>=0; i--){
		if(p[u][i] != p[v][i]){
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}
int main() {
	int test;
	cin>>test;
	for(int te = 1; te<=test; te++){
		int u,v,x;
		
		cin>>n;
		for(int i = 1; i<=n; i++){
			cin>>x;
			while(x--){
				cin>>u;
				par[u] = i;
			}
		}
		
		//Root la dinh ko co par
		for(int i = 1; i<=n; i++)
			dfs(i);
		for(int i = 1; i<=n; i++)
			p[i][0] = par[i];

		//Tinh p
		for(int i = 1; i<20; i++){
			for(int u = 1; u<=n; u++)
				p[u][i] = p[p[u][i-1]][i-1];
		}
	
		cout<<"Case "<<te<<":"<<endl;
		cin>>x;
		while(x--){
			cin>>u>>v;
			cout<<lca(u,v)<<endl;
		}
		for(int i = 0; i<=n; i++){
			h[i] = 0;
			par[i] = 0;
		}
		
	}
	return 0;
}
