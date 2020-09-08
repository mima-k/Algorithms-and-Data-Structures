#include <stdio.h>

void bubblesort(int a[],int n,int count);

int main (void) {
	int size,a[100]= {};

	scanf("%d",&size);
	for(int i=1; i<=size; i++) {
		scanf("%d",&a[i]);
	}

	bubblesort(a,size,0);
	return 0;
}

void bubblesort(int a[],int n,int count) {
	int i,j;
	int tmp;


	for(i=1; i<n; i++) {
		for(j=n; j>=i+1; j--) {
			if(a[j]<a[j-1]) {
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
				count++;
			}
		}
	}
	for(int i=1; i<n+1; i++) {
		
		printf("%d",a[i]);
		if(i!=n)
			printf(" ");
	}
	printf("\n");
	printf("%d\n",count);
}