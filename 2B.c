#include <stdio.h>

void selectionsort(int a[],int n,int count);

int main (void) {
	int size,a[100]= {};

	scanf("%d",&size);
	for(int i=1; i<=size; i++) {
		scanf("%d",&a[i]);
	}

	selectionsort(a,size,0);
	return 0;
}

void selectionsort(int a[],int n,int count) {
	int i,j,min;
	int tmp;


	for(i=1; i<n; i++) {
		min=i;
		for(j=i+1; j<n+1; j++) {
			if(a[j]<a[min]) {
				min=j;
				
			}
		}
		if(a[i]>a[min]){
			tmp=a[min];
			a[min]=a[i];
			a[i]=tmp;
			count++;
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