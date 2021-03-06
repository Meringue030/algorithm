// fib.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int call = 0;
int fib(int n)
{
	
	if (n == 2) call++;
	// call++;
	if (n <= 1)
		return n;
	else
		return (fib(n - 1) + fib(n - 2));
}

typedef int index;
# define MAX 100
int f[MAX];

int fib2(int n)
{
	index i;
 
	f[0] = 0;
	if (n > 0) {
		f[1] = 1;
		for (i = 2; i <= n; i++)
			f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

 
int main()
{

	int i = 5;
	int j = 5;
	  printf("fib (%d) = %d \n", j, fib(j));
      printf("call = %d \n", call);
	
	printf("fib2 (%d) = %d \n", i, fib2(i));
	getchar();
	getchar();
    return 0;
}

