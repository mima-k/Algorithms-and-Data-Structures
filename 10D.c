#include <stdio.h>

int main(void){
	int i,j,k,n;
	scanf("%d",&n);
	double a[n];
	double b[n+1];
	double c[n+1][n+1];
	double d[n+1];
	double p,q;
	for(i = 0; i < n; i++) scanf("%lf",&a[i]);
	for(i = 0; i <= n; i++) scanf("%lf",&b[i]);
	c[0][0]=b[0];
	d[0]=a[0]+b[0];
	
	for(i = 1; i <= n; i++){
		c[i][i] = b[i];
		c[i-1][i] = a[i-1]+(b[i-1]+b[i])*2;
		d[i] = d[i-1]+a[i]+b[i];
	}
	for(i = 1;i < n; i++){
		for(j = 0; j < n-i; j++){
			p = c[j][j] + c[j+1][i+j+1];
			for(k = j; k <i+j; k++){
				q = c[j][k+1]+c[k+2][i+j+1];
				if(p>q) p = q;
			}
			c[j][i+j+1] = p + d[i+j] - d[j-1] + b[i+j+1];
		}
	}
	printf("%lf\n",c[0][n]);
	return 0;
}

