#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int key;
	struct Node *r,*l,*p;
} Node;

Node *root , *NIL;

Node * treeMinimum(Node *x)
{
	while(x->l != NIL) x = x->l;
	return x;
}

Node * find(Node *u , int k)
{
	while( u != NIL && k != u->key)
	{
		if( k < u->key)u = u->l;
		else u = u ->r;
	}
	return u;
}

Node * treeSuccessor(Node *x)
{
	if(x->r != NIL) return treeMinimum(x->r);
	Node* y = x->p;
	while(y != NIL && x == y->r)
	{
		x = y;
		y = y->p;
	}
	return y;
}

void treeDelete(Node *z)
{
	Node *y;
	Node *x;
	
	if(z->l == NIL || z->r == NIL) y = z;
	else y = treeSuccessor(z);
	
	if( y->l != NIL)
	{
		x = y->l;
	}
	else
	{
		x = y->r;
	}
	
	if( x != NIL)
	{
		x->p = y->p;
	}
	
	if(y->p == NIL)
	{
		root = x;
	}
	else
	{
		if( y == y->p->l)
		{
			y->p->l = x;
		}
		else
		{
			y->p->r = x;
		}
	}
	
	if(y != z)
	{
		z->key = y->key;
	}
	
	free(y);
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

int main(void)
{
	int  n , i , x;
	char com[100];
	char str1[] = "insert";
	char str2[] = "print";
	char str3[] = "delete";
	scanf("%d",&n);
	
	for( i = 0; i < n; i++)
	{
		while(scanf("%s",com) != EOF)
		
		if(com[0] == 'f')
		{
			scanf("%d",&x);
			Node *t = find(root,x);
			if( t != NIL) printf("yes\n");
			else printf("no\n");
		}
		else if(strcmp(com,str1) == 0)
		{
			scanf("%d",&x);
			insert(x);
		}
		else if(strcmp(com,str2) == 0)
		{
			inorder(root);
			printf("\n");
			preorder(root);
			printf("\n");
		}
		else if(strcmp(com,str3) ==0)
		{
			scanf("%d",&x);
			treeDelete(find(root,x));
		}
	}
	return 0;
}

