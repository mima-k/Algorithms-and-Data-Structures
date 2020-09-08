#include<stdio.h>
#include<string.h>
#define MAX 100

int n,c,k=0;
int pre[MAX],in[MAX],post[MAX];


int find(int a){
	int i;
	for(i=0;i<n;i++){
		if(a==in[i])return i;
	}
	return 0;
}

void rec(int l,int r){
	int a,b;
	if(l >= r)return;
	
	a=pre[k++];
	b=find(a);
	rec(l,b);
	rec(b+1,r);
	post[c++]=a;
}

int main(void){
	int i;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	
	for(i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	
	rec(0,n);
	
	for(i=0;i<n;i++){
		if(i != n-1)printf("%d ",post[i]);
		else printf("%d\n",post[i]);
	}
	return 0;
}
