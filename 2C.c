#include<stdio.h>

typedef struct {
	char suit;
	char value;
	int idx;
} Card;

void print(Card* A, int N) {
	int i;
	for(i = 0; i < N; i++) {
		if(i) printf(" ");
		printf("%c%c",A[i].suit,A[i].value);
	}
	printf("\n");
}

void is_stable(Card* A, int N) {
	int i;
	for(i = 0; i+1 < N; i++) {
		if(A[i].value == A[i+1].value && A[i].idx > A[i+1].idx) {
			printf("Not stable\n");
			return;
		}
	}
	printf("Stable\n");
}

void swap(Card* a, Card* b) {
	Card tmp = *a;
	*a = *b;
	*b = tmp;
}

int bubblesort(Card* A, int N) {
	int i,j, cnt=0;
	for(i = 0; i < N; i++) {
		for(j = N-1; j >= i+1; j--) {
			if(A[j].value < A[j-1].value) {
				swap(&A[j],&A[j-1]);
				cnt++;
			}
		}
	}
	return cnt;
}

int selectionsort(Card* A, int N) {
	int i,j,cnt=0;
	for(i = 0; i < N; i++) {
		int mini = i;
		for(j = i; j < N; j++) {
			if(A[j].value < A[mini].value) {
				mini = j;
			}
		}
		cnt += (i==mini?0:1);
		swap(&A[i],&A[mini]);
	}
	return cnt;
}

int main() {
	int i,N;
	Card C1[40],C2[40];
	scanf("%d\n",&N);
	for(i = 0; i < N; i++) {
		scanf("%c%c ",&C1[i].suit, &C1[i].value);
	}
	for(i = 0; i < N; i++) {
		C2[i] = C1[i];
		C1[i].idx = C2[i].idx = i;
	}
	bubblesort(C1,N);
	selectionsort(C2,N);
	print(C1,N);
	is_stable(C1,N);
	print(C2,N);
	is_stable(C2,N);
	return 0;
}
