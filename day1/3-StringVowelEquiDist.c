/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:26 July 2019
Program description:Let us define a string, comprising English alphabets, asNICEif each vowel within it are equidistant from its successor andpredecessor vowel, if applicable.  
					E.g., “rhythm”, “cool”,“malayalam” areNICEstrings.  Write a program to verifywhether a given string isNICEor not.  
					You are required totake the string as a direct input without asking for its length
Acknowledgements:
------------------------------------*/
#include<stdio.h>
#include<string.h>

int isVowel(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
		return 1;
	else
		return 0;
}


int main()
{
	char str[255];
	scanf("%s",str);
	int i,pos[255],j;
	j = 0;
	for(i=0;str[i]!='\0';i++)
		if(isVowel(str[i]))
			pos[j++] = i;
	for(i=0;i<j;i++)
		printf("%d ",pos[i]);
	if(j<3)
		printf("1NICE\n");
	else
	{
		for(i=1;i<j-1;i++)
			if(2*pos[i] !=pos[i+1]+pos[i-1])
				{printf("NOT NICE\n"); return 0;}
		printf("2NICE\n");
	}
	return 1;
}