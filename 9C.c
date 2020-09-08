#include<stdio.h>
#include<string.h>

#define MAX 2000000
#define INFINITY (1<<30)

int H,A[MAX+1];

void maxHeapify(int i) {
	int left,right,largest;
	int tmp;
	left = 2*i;
	right = 2*i+1;

	if(left <= H && A[left] > A[i]) {
		largest = left;
	} else {
		largest = i;
	}

	if(right <= H && A[right] > A[largest]) {
		largest = right;
	}

	if(largest != i) {
		tmp=A[i];
		A[i]=A[largest];
		A[largest]=tmp;
		maxHeapify(largest);

	}
}

int extract() {
	int maxv;
	if(H < 1)return -INFINITY;
	maxv = A[1];
	A[1] = A[H--];
	maxHeapify(1);
	return maxv;
}



void increaseKey(int i,int key) {
	int tmp;
	if(key < A[i])return;

	A[i] = key;
	while(i > 1 && A[i/2] < A[i]) {
		tmp=A[i];
		A[i]=A[i/2];
		A[i/2]=tmp;
		i = i/2;
	}
}

void insert(int key) {
	H++;
	A[H] = -INFINITY;
	increaseKey(H,key);

}

int main() {
	int key;
	char com[10];

	while(1) {
		scanf("%s",com);
		if(com[0] == 'e' && com[1] == 'n')break;
		if(com[0] == 'i') {
			scanf("%d",&key);
			insert(key);
		} else {
			printf("%d\n",extract());
		}

	}
	return 0;
}
