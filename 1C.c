#include <stdio.h>
#include <math.h>

int main (void) {
	int a[10000]={};
	int n=0;
	int i,j,k,count=0;
	
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++){
		k=0;
		for(j=2;j<=sqrt((double)a[i]);j++){
			if(a[i]%j==0){
				k=1;
				break;
			}
		}

		if(k==0&&a[i]!=1) count++;
	}
	
	printf("%d\n",count);
}