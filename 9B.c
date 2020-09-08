#include <stdio.h>
#define MAX 2000000

int H, A[MAX + 1];

void maxHeapity(int i) {
	int l, r, largest,tmp;
	l = 2*i;
	r = 2*i + 1;

	if(l <= H && A[l] > A[i]) {
		largest = l;
	} else {
		largest = i;
	}
	if(r <= H && A[r] > A[largest]) {
		largest = r;
	}

	if(largest != i) {
		tmp=A[i];
		A[i]=A[largest];
		A[largest]=tmp;
		maxHeapity(largest);
	}
}


int main(void){
	scanf("%d", &H);
	for(int i = 1; i <= H; i++) {
		scanf("%d", &A[i]);
	}

	for(int i = H/2; i>=1; i--) {
		maxHeapity(i);
	}

	for(int i = 1; i <= H; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");

	return 0;
}


