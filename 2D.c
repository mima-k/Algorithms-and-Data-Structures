#include <stdio.h>

int insertionSort(int A[],int n,int g) {
	int cnt=0;
	for (int i=g; i<n; i++) {
		int v=A[i];
		int j=i-g;
		while((j>=0)&&(A[j]>v)) {
			A[j+g]=A[j];
			j-=g;
			cnt++;
			A[j+g]=v;
		}
	}
	return cnt;
}

void shellSort(int A[], int  n) {
	int  G[100];
	int  m,i,cnt=0;

	for(G[0]=1,m=0; (G[m]<=n) && (m<100); m++) {
		G[m+1]=G[m]*3+1;
	}

	cnt=0;
	for(i=m-1; i>=0; i--) {
		cnt +=insertionSort(A,n,G[i]);
	}
	printf("%d\n",m);
	for(i=m-1; i>0; i--) {
		printf("%d ", G[i]);
	}
	printf("%d\n",G[0]);
	printf("%d\n",cnt);
}


	int main(void) {
		int N,n;
		int A[1000000];
		scanf("%d\n",&N);
		for(n=0; n<N; n++) {
			scanf("%d\n",&A[n]);
		}
		shellSort(A,n);
		for(n=0; n<N; n++) {
			printf("%d\n",A[n]);
		}
		return 0;
	}
