#include<stdio.h>
void insertionSort(int a[], int n);
int main() {
	int a[100] = {}, n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	insertionSort(a, n);
	return 0;
}

void insertionSort(int a[], int n){
	int i, j, v, k;
	for (k = 0; k < n; k++){
		printf("%d%c", a[k], k < n - 1 ? ' ' : '\n');
	}
	for (i = 1; i <= n - 1; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		for (k = 0; k < n; k++) {
		    printf("%d%c", a[k], k < n-1 ? ' ' : '\n');
		}
	}
}
