#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct {
	int p, l, r;
};
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];

void print(int u) {
	int i, c;
	printf("node %d: parent = %d, depth = %d, ", u, T[u].p, D[u]);

	if(T[u].p == NIL) printf("root, ");
	else if(T[u].l == NIL) printf("leaf, ");
	else printf("internal node, ");

	printf("[");
	for (i=0, c = T[u].l; c != NIL; i++, c = T[c].r) {
		if(i) printf(", ");
		printf("%d", c);
	}
	printf("]\n");

}

void rec(int u, int p) {
	D[u] = p;
	if(T[u].r != NIL) rec(T[u].r, p);
	if(T[u].l != NIL) rec(T[u].l, p+1);
}

int main() {
	int i, j, k;
	int n;
	int id, sib, child;
	int r = NIL;
	scanf("%d", &n);
	for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;

	for(i=0; i<n; i++) {
		scanf("%d %d", &id, &k);
		for(j = 0, sib = NIL; j<k; j++) { 
			scanf("%d", &child);
			T[child].p = id;
			if(j == 0) T[id].l = child;
			else T[sib].r = child;
			sib = child;
		}
	}


	for(i=0; i<n; i++) {
		if(T[i].p == -1) r = i;
	}

	rec(r, 0);

	for(i=0; i<n; i++) print(i);

	return 0;
}

