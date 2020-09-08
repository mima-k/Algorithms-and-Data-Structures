#include<stdio.h>
#include<stdlib.h>

#define N 100
#define INFTY (1<<21)
#define MAX 100000

int n, M[N][N];
int d[N];

int head, tail;
int Q[MAX];

void initialize() {
	head = tail = 0;
}

int isEmpty() {
	if( head == tail ) return 1;
	else return 0;
}

int isFull() {
	if( head == ( tail + 1 ) % MAX ) {
		return 1;
	} else {
		return 0;
	}
}

void enqueue(int x) {
	Q[tail] = x;
	if ( tail + 1 == MAX ) tail = 0;
	else tail++;
}

int dequeue() {
	int x;
	x = Q[head];
	if( head + 1 == MAX ) head = 0;
	else head++;
	return x;

}

void bfs(int s) {
	enqueue(s);
	for( int i = 0; i < n; i++ ) {
		d[i] = INFTY;
	}
	d[s] = 0;
	int u;

	while( !isEmpty() ) {
		u = dequeue();
		for( int v = 0; v < n; v++ ) {
			if( M[u][v] == 0 ) continue;
			if( d[v] != INFTY ) continue;
			d[v] = d[u] + 1;
			enqueue(v);
		}
	}
	for( int i = 0; i < n; i++ ) {
		printf( "%d ", i+1 );
		if( d[i] == INFTY ) {
			printf( "-1\n" );
		} else {
			printf( "%d\n", d[i] );
		}
	}

}

int main( void ) {
	int u, k, v;

	scanf( "%d", &n );
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < n; j++ ) {
			M[i][j] =0;
		}
	}
	for( int i = 0; i < n; i++ ) {
		scanf( "%d", &u );
		scanf( "%d", &k );
		u--;
		for( int j = 0; j < k; j++) {
			scanf( "%d", &v );
			v--;
			M[u][v] = 1;
		}
	}
	bfs(0);

	return 0;
}

