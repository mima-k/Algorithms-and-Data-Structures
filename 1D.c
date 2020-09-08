#include <stdio.h>
#include <limits.h>

int main (void){
	int i,j,n=0,r[200000]={};
	int max,min;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&r[i]);
	}
	
	max=INT_MIN;
	min=r[0];
	for(i=1;i<n;i++){
	    if(max<r[i]-min) max=r[i]-min;
        if(min>r[i]) min = r[i];
        
	}
	
	printf("%d\n",max);
}