#include<stdio.h>

int search(int A[],int n, int key){
	int i=0;
	A[n] = key;
	while(A[i] != key) i++;
	return i !=n;
}

int main(void){
	int i,n,S[100000],q,T[10000],sum=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&S[i]);
	//while(scanf("%d",S) !=EOF)
	scanf("%d",&q);
	for(i=0;i<q;i++) scanf("%d",&T[i]);
	//while(scanf("%d",T) !=EOF)
	for(i=0;i<q;i++){
		if(search(S,n,T[i])) sum++;
	}
	printf("%d\n",sum);
	return 0;
}