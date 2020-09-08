#include <stdio.h>
#include <stdbool.h>
#define true 1
#define false 0
#define MAX 1000
#define VMAX 10000
#define NMAX 500000
#define SMAX 1000000000
int L[NMAX/2+2],R[NMAX/2+2];

int n , A[MAX] , s;
int B[MAX] , T[VMAX+1];

void merge(int A[],int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++) L[i]=A[left+i];
	for(int i=0;i<n2;i++) R[i]=A[mid+i];
	L[n1]=R[n2]=SMAX;
	int i=0,j=0;
	for(int k=left;k<right;k++){
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

int min(int a , int b){
	if(a < b) return a;
	else return b;
}

int solve(){
	int ans = 0;
	
	bool V[MAX];
	for( int i = 0; i < n; i++){
		B[i] = A[i];
		V[i] = false;
	}
	mergeSort(A,0,n);
	for( int i = 0; i < n; i++){
		T[B[i]] = i;
	}
	for( int i = 0; i < n; i++) {
		if(V[i]) continue;
		int cur = i;
		int S = 0;
		int m = VMAX;
		int an = 0;
		while(1){
			V[cur] = true;
			an++;
			int v = A[cur];
			m = min(m,v);
			S += v;
			cur = T[v];
			if(V[cur])break;
		}
		ans += min(S+(an-2)*m,m+S+(an+1)*s);
	}
	return ans;
}

int main(void)
{
	scanf("%d",&n);
	s = VMAX;
	for( int i = 0; i < n; i++)
	{
		scanf("%d",&A[i]);
		s = min(s,A[i]);
	}
	int ans = solve();
	printf("%d\n",ans);
}
