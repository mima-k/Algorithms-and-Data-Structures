#include <stdio.h>

#define MAX 100000

int n,m ,q ,from ,to;
int rank[MAX],parent[MAX];

int find(int x){
	if(x == parent[x]){
		return x;
	}else{
		return parent[x] = find(parent[x]);
	}
}

void unite(int x,int y){
	x = find(x);
	y = find(y);

	if(x == y) return;

	if(rank[x] < rank[y]){
		parent[x] = y;
	}else{
		parent[y] = x;
		if(rank[x] == rank[y]){
			rank[x]++;
		}
	}
}

int main(void){

	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++){
		rank[i] = 0;
		parent[i] = i;
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d",&from,&to);
		if(find(from)==find(to)) continue;
		unite(from,to);
	}
	scanf("%d",&q);

	int l,r;

	for(int i = 0; i < q; i++){
		scanf("%d %d",&l,&r);

		if(find(l)==find(r)){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
	return 0;
}

