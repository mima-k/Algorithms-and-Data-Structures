#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NIL NULL

typedef struct Node {
	int key;
	int priority;
	struct Node *r,*l,*p;
} Node;

Node *Delete(Node **t, int key);
Node *Delete2(Node **t, int key);


void preorder( Node *u ) {

	printf(" %d",u->key);
	if(u->l!=NIL) {
		preorder(u->l);
	}
	if(u->r!=NIL) {
		preorder(u->r);
	}
	return;
}

void inorder( Node *u ) {

	if(u->l!=NIL) {
		inorder(u->l);
	}
	printf(" %d",u->key);
	if(u->r!=NIL) {
		inorder(u->r);
	}
	return;

}

int find( Node *u, int k ) {
	while( u != NIL ) {
		if( u->key == k ) {
			return 1;
		} else if( k < u->key ) {
			u = u->l;
		} else {
			u = u->r;
		}
	}
	return 0;
}

Node *rightRotate(Node *t) {
	Node *s = t->l;
	t->l = s->r;
	s->r = t;
	return s;
}

Node *leftRotate(Node *t) {
	Node *s = t->r;
	t->r = s->l;
	s->l = t;
	return s;
}

Node* node( int x, int y ) {

	Node *new = malloc(sizeof(Node));
	new->key = x;
	new->priority = y;
	new->l = NIL;
	new->r = NIL;

	return new;
}

Node* insert(Node **t, int key, int priority) {

	Node *new;
	if( *t == NIL ) {
		return new = node(key, priority);
	}
	if( key == (*t)->key ) {
		return *t;
	}

	if( key < (*t)->key ) {
		(*t)->l = insert(&(*t)->l, key, priority);
		if ( (*t)->priority < (*t)->l->priority ) {
			*t = rightRotate(*t);
		}
	} else {
		(*t)->r = insert(&(*t)->r, key, priority);
		if( (*t)->priority < (*t)->r->priority ) {
			*t = leftRotate(*t);
		}
	}
	return *t;
}

Node *Delete(Node **t, int key) {

	if ((*t) == NIL) {
		return NIL;
	}
	if ( key < (*t)->key ) {
		(*t)->l = Delete(&((*t)->l), key);
	} else if ( key > (*t)->key ) {
		(*t)->r = Delete(&((*t)->r), key);
	} else {
		return Delete2(t, key);
	}
	return *t;
}

Node *Delete2(Node **t, int key) {
	if ((*t)->l == NIL && (*t)->r == NIL ) {
		return NIL;
	} else if ( (*t)->l == NIL ) {
		*t = leftRotate(*t);
	} else if ((*t)->r == NIL) {
		*t = rightRotate(*t);
	} else {
		if ((*t)->l->priority > (*t)->r->priority ) {
			*t = rightRotate(*t);
		}
		else {
			*t = leftRotate(*t);
		}
	}
	return Delete(t, key);
}

int main( void ) {

	int n, i, x, y;
	char com[10];
	Node *root = NIL;

	scanf( "%d", &n );

	for( i = 0; i < n; i++ ) {
		scanf( "%s", com );
		if( com[0]=='f')  {
			scanf( "%d", &x );
			if( find(root,x) ) {
				printf( "yes\n" );
			} else {
				printf( "no\n" );
			}
		}else if( com[0]=='p'){
			inorder(root);
			printf( "\n" );
			preorder(root);
			printf( "\n" );
		}  else if(com[0]=='i' ) {
			scanf("%d %d",&x,&y);
			root = insert(&root,x,y);
		} else if( com[0]=='d' ) {
			scanf( "%d", &x );
			root = Delete(&root,x);
		}
	}

	return 0;
}

