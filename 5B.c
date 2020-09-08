#include<stdio.h>

#define NMAX 500000
#define SMAX 1000000000
int L[NMAX/2+2],R[NMAX/2+2];
int cnt;

void merge(int A[],int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++) L[i]=A[left+i];
	for(int i=0;i<n2;i++) R[i]=A[mid+i];
	L[n1]=R[n2]=SMAX;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		cnt++;		//比較回数
		if(L[i]<=R[j]){
			A[k]=L[i++];
		}
		else{
			A[k]=R[j++];
		}
	}
}

void mergeSort(int A[],int left, int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main(){
	int A[NMAX],n,i;
	cnt=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	
	mergeSort(A,0,n);
	
	for(i=0;i<n-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[n-1]);
	printf("%d\n",cnt);
	
	return 0;
}