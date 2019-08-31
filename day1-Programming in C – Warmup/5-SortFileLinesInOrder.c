/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:26 July 2019
Program description:You have to write a program that reads its own source file(i.e., mtc19xx-day1-prog5.c), and prints the lines in that file inlexicographically sorted order.  
                    The output of your programshould be identical to the output of the command “sortmtc19xx-day1-prog6.c”.  
                    Recall that, given any two stringssandt, the functionstrcmp()may be used to determine thelexicographic ordering ofsandt.
                    This is the efficient implementation
Acknowledgements:
------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{

    char *doc[500]; char tmpstr[100];
    int i = 0; int j = 0;
    FILE *fp; char ch; fp = fopen("sample.txt","r");


    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
        if(ch != '\n')
            tmpstr[i++]=ch;
        else
        {
            tmpstr[i++] = '\0';
            size_t l=strlen(tmpstr);
            char *x=(char*)malloc(l+1);//used malloc to allocate dynamic memory. l+1 to store "\0".
            strcpy(x,tmpstr);
            doc[j++]=x;
            i = 0;
        }
    }
    int n = j;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
           int a=strcmp(doc[i],doc[j]);
            if(a<0){
                char *temp=doc[i];
                doc[i]=doc[j];
                doc[j]=temp;
                }
        }

    for(i=0;i<n;i++)
        printf("%s\n",doc[i]);
}
