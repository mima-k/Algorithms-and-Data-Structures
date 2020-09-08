#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2];
int R[MAX/2+2];

long long merge(int A[],int left,int right,int mid){
	int i,j,k;
	int n1=mid-left;
	int n2=right-mid;
	long long count=0;
	
	for(i = 0; i < n1;i++){
		L[i] = A[left + i];
	}
	for(i = 0; i < n2; i++){
		R[i] = A[mid + i];
	}
	i=0;
	j=0;
	L[n1] = R[n2] = SENTINEL;
	for(k=left;k<right;k++){
		if(L[i]<=R[j]){
			A[k]=L[i++];
		}
		else{
			A[k]=R[j++];
			count+=n1-i;
		}
	}
	return count;
}

long long mergeSort(int A[],int left,int right){
	int mid;
	long long v1,v2,v3;
	if(left+1<right){
		mid=(left+right)/2;
		v1=mergeSort(A,left,mid);
		v2=mergeSort(A,mid,right);
		v3=merge(A,left,right,mid);
		return v1+v2+v3;
	}
	else return 0;
}


int main (void){
	
	int A[MAX];
	int n;
	int i;
	
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&A[i]);
	}
	long long cnt = mergeSort(A,0,n);
	printf("%lld\n",cnt);
	return 0;
}