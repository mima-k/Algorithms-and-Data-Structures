#include <stdio.h>
#define A 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n ,m[A][A];

int color[A] , d[A] , f[A] , tt;

void dfs_visit(int u){
	int v ;
	color[u] = GRAY;
	d[u] = ++tt;
	for(v = 0; v < n; v++){
		if(m[u][v] == 0) continue;
		if(color[v] == WHITE) dfs_visit(v);
	}
	color[u] = BLACK;
	f[u] = ++tt;
}

void df(){
	int u;
	for(u = 0; u < n; u++) color[u] = WHITE;
	tt = 0; 
	for( u = 0; u < n; u++){
		if(color[u] == WHITE) dfs_visit(u);
	}
	for(u = 0; u < n; u++) printf("%d %d %d\n",u+1,d[u],f[u]);
}

int main(void){
	int u, v , k, i,j;
	scanf("%d",&n);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			m[i][j] = 0;
		}
	}
	for(i = 0; i < n; i++){
		scanf("%d %d",&u,&k);
		u--;
		for(j = 0; j < k; j++){
			scanf("%d",&v);
			v--;
			m[u][v] = 1;
		}
	}
	df();
	return 0;
}
