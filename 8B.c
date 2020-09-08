#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node *r,*l,*p;
} Node;

Node *root, *NIL;

Node * find( Node *u, int k ) {
	while( u != NIL && k != u->key ) {
		if( k < u->key ) {
			u = u->l;
		} else {
			u = u->r;
		}
	}
	return u;
}

void insert( int k ) {
	Node *y = NIL;
	Node *x = root;
	Node *z;

	z = ( Node *)malloc( sizeof(Node) );
	z->key = k;
	z->l = NIL;
	z->r = NIL;

	while( x != NIL ) {
		y = x;
		if( z->key < x->key ) {
			x = x->l;
		} else {
			x = x->r;
		}
	}
	z->p = y;

	if( y == NIL ) {
		root = z;
	} else {
		if( z->key < y->key ) {
			y->l = z;
		} else {
			y->r = z;
		}
	}
}

void preorder( Node *u ) {

	if( u == NIL ) {
		return;
	}
	printf( " %d", u->key );
	preorder( u->l );
	preorder( u->r );
}

void inorder( Node *u ) {

	if( u == NIL ) {
		return;
	}
	inorder( u->l );
	printf( " %d", u->key );
	inorder( u->r );
}

int main( void ) {

	int n, i, x;
	char com[10];

	scanf( "%d", &n );

	for( i = 0; i < n; i++ ) {

		scanf( "%s", com );
		if( strcmp(com, "find") == 0 ) {
			scanf( "%d", &x );
			Node *t = find(root,x);
			if( t!= NIL ) {
				printf( "yes\n" );
			} else {
				printf( "no\n" );
			}
		} else if( strcmp(com,"insert") == 0 ) {
			scanf( "%d", &x );
			insert(x);
		} else if( strcmp(com,"print") == 0 ) {
			inorder(root);
			printf( "\n" );
			preorder(root);
			printf( "\n" );
		}
	}

	return 0;
}

