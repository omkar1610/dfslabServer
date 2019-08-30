/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:30 July 2019
Program description:Given the lower and upper bound ofversion numbers of a software andn(the number ofcomponents of a version number) as user inputs, 
					list up allthe possible versions that might exist within the given range.
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <string.h>

void verprnt(int n)
{
	int tmp = 0,flag = 0;
	while(n%10 == 0 ) flag++,n=n/10;
	while(n>0)
	{
		tmp = tmp*10 + n%10;
		n = n/10;
	}
	while(tmp>9)
		{
			printf("%d.", tmp%10);
				tmp = tmp/10;
			}
	
	printf("%d.", tmp%10);
	while(flag--)printf("0.");

}

int main()
{
	char input[256];
    int v1[50],v2[50],n1,n2;
    int i,j; n1=0;n2=0;
    
    scanf("%s",input);
    for(i=0;i<strlen(input);i=i+2)
    	n1 = 10*n1 + input[i] - '0';

    scanf("%s",input);
    for(i=0;i<strlen(input);i=i+2)
    	n2 = 10*n2 + input[i] - '0';

    //printf("%d\n", n1);
    //printf("%d\n", n2);
    for(i=n1;i<n2;i++)
    	verprnt(i),printf("\b \n");;
    




	return 0;
}