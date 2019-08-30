/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:26 July 2019
Program description:Problems – Day 16Suppose there are two separate files containing sufficientlylarge integer values.  
                    Write a program that will take those twofilenames as command line arguments and return themultiplication result.
                    This is the efficient implememtatoin
Acknowledgements:
------------------------------------*/
#include<stdio.h>


/*
123456
25256789
*/



void createFile(char *file)
{
    FILE *fp;
    char ch  = '1';

   /*  open for writing */
   fp = fopen(file, "w+");
   printf("Enter the file %s and press enter\n",file);
   while(ch != '\n'){
        scanf("%c",&ch);
        if(ch != '\n')
            fputc(ch,fp);
    }
    fclose(fp);
}

void readFile(char *file)
{
    FILE *fp;
   char ch;

   /*  open for writing */
   fp = fopen(file, "r");

   if (fp == NULL)
   {
      printf("\n%s does not exists \n", file);
      return;
   }
   else
      printf("\n%s: ", file);

   while ((ch = fgetc(fp) )!= EOF)
      printf ("%c_", ch);

   if (!fclose(fp))
      printf(" closed %s.\n", file);
}



int reduceByOne(char *file)
{
    FILE *fp, *fp2;


    fp = fopen(file, "r");
    fp2 = fopen("tmp.txt","w+");
    int flag = 0;
    char ch = fgetc(fp);
    char chNxt = fgetc(fp);
    if(ch == '1' && chNxt == EOF)
        return 0;//printf("Got One"); No more addition requored for multiplication
    while (ch != EOF)
    {

        int a = ch - '0';
        if(flag == 0)
        {
            if(a == 0)
                fputc((char)9+'0',fp2);
            else
            {
               flag = 1;
               if(chNxt == EOF && a == 1)
                {
                    break;
                }
                else
                    fputc((char)a-1+'0',fp2);
            }
        }
        else
        {
            fputc((char)a+'0',fp2);
        }
        ch = chNxt;
        chNxt = fgetc(fp);
    }

    fclose(fp);
    fclose(fp2);
    remove(file);
    rename("tmp.txt",file);
    return 1;
}

void addFile(char *fn1, char *fn2){
    FILE *fp1, *fp2;
    char ch, ch2;

    fp1 = fopen(fn1, "r");
    fp2 = fopen(fn2, "r+");

    int carry = 0;
    while ((ch = fgetc(fp1) )!= EOF && (ch2 = fgetc(fp2) )!= EOF)
    {
        int a = ch - '0';
        int b = ch2 - '0';
        int sum = carry + a+b;
        int dig = sum%10;
        carry = sum/10;
        //printf("%d ",dig);
        fseek(fp2,-1,SEEK_CUR);
        fputc((char)dig+'0',fp2);

    }

    //if(ch == EOF)// Second file is larger so file 1 will terminate fast
    //{
        //printf("\nFile1 finished, Copying file 2 to file 3\n");
    ch2 = fgetc(fp2);//Chk whats next for this
    if(ch2 != EOF)
        do
        {
            int a = ch2 - '0';
            int sum = carry + a;
            //printf("carr = %c\n",ch2);
            int dig = sum%10;
            carry = sum/10;
            //printf("%d ",dig);
            fseek(fp2,-1,SEEK_CUR);
            fputc((char)dig+'0',fp2);
        }while ((ch2 = fgetc(fp2) )!= EOF && carry != 0);
    if(carry)
        fputc((char)carry+'0',fp2);

    //}


    fclose(fp1);
    fclose(fp2);
}


void copy(char *sou, char *tar)
{
    FILE *src, *targ;
    src = fopen(sou,"r");
    targ = fopen(tar,"w+");
    char ch;
    while( ( ch = fgetc(src) ) != EOF )
      fputc(ch, targ);
    fclose(src);
    fclose(targ);
}

int main()
{
    char *file1 = "num1.txt";
    char * file2 = "num2.txt";
    char *file3 = "num3.txt";
    createFile(file1);
    createFile(file2);
    copy(file1, file3);
    while(reduceByOne(file2))
    {
        //readFile(file2);
        addFile(file1, file3);
        //readFile(file3);
    }
    readFile(file3);
    /*createFile("num1.txt");
    createFile("num2.txt");
    readFile("num1.txt");
    readFile("num2.txt");
    addFile("num1.txt", "num2.txt");// n2<- n1+n2
    readFile("num2.txt");
    createFile("diff.txt");
    readFile("diff.txt");
    reduceByOne("diff.txt","sum.txt");
    readFile("sum.txt");
*/}

