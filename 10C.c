#include<stdio.h>
#include<string.h>

#define N 1000

int lcs( char x[] , char y[] ){
	
	int c[N+1][N+1];
	int m = strlen(x);
	int n = strlen(y);
	int maxl = 0;
	int max=0;
	
	char x2[m+1] , y2[n+1];
	
	x2[0] = ' ';
	for( int i = 1; i <= m; i++ ){
		x2[i]=x[i-1];
	}
	y2[0] = ' ';
	for( int i = 1; i <= n; i++ ){
		y2[i]=y[i-1];
	}
	
	for( int i = 0; i <= m; i++ ){
		c[i][0] = 0;
	}
	for( int j = 1; j <= n; j++ ){
		c[0][j] = 0;
	}
	
	for( int i = 1; i <= m; i++ ){
		for( int j = 1; j <= n; j++ ){
			if( x2[i] == y2[j] ){
				c[i][j] = c[i-1][j-1] + 1;
			}else{
				if(c[i-1][j]>=c[i][j-1]) max=c[i-1][j];
				else max=c[i][j-1];
				c[i][j] = max;
			}
			if(maxl>=c[i][j]) max=maxl;
			else max=c[i][j];
			maxl = max;
		}
	}
	return maxl;
}

int main( void ){
	char s1[N] , s2[N];
	int n;
	scanf( "%d" , &n );
	
	for( int i = 0; i < n; i++ ){
		scanf( "%s" , s1 );
		scanf( "%s" , s2 );
		printf( "%d\n" , lcs(s1 , s2) );
	}
	
	return 0;
}
	
