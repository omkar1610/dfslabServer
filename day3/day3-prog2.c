/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:2 Aug 2019
Program description:Consider 2 sets of integers,AandB, are stored in arrays.
					Write a program to find the number of (possibly overlapping)occurrences of the sequenceBinA.
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <string.h>

int count(int a[], int b[], int m, int n) 
{ 
    if ((m == 0 && n == 0) || n == 0) 
        return 1; 
   if (m == 0) 
        return 0; 
  
    if (a[m - 1] == b[n - 1]) 
        return count(a, b, m - 1, n - 1) + count(a, b, m - 1, n); 
    else
        return count(a, b, m - 1, n); 
} 

int main()
{
	int b[] = {3,4,5};
	int a[] = {1,2,3,4,6,5,3,5,2,5,3,7,8,4,1,3,5};
	int m = sizeof(a)/sizeof(int);
	int n = sizeof(b)/sizeof(int);
	printf("%d\n", count(a,b,m,n));
}