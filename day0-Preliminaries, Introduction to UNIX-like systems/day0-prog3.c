/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:23 July 2019
Program description:Given a list of positive integers, find the standard deviation of thenumbers.
					Note that the number of integers is not known in advance. 
					The user will supply the input one byone, and enter 0 when done.
Acknowledgements:
------------------------------------*/
#include<stdio.h>
#include<math.h>

void main()
{
 float a[1000];
 float flag = 1;
 int n = 0;
 float sum = 0;
 float sqSum = 0;
 printf("Put all and put 0 at last \n");
 while(flag){
	
	scanf("%f",&flag);
	sum += flag;
	sqSum += flag*flag;
	a[n++] = flag;
 }
 n--; // Coz of Zero reduce n by 1
 float mean = sum/n;
 float sqMean = sqSum/n;
 printf("n = %d,sum = %f, mean = %f\n",n,sum,mean);
 printf("SD = %f\n",sqrt(sqMean - pow(mean,2)));

}
