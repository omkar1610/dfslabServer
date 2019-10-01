#include<stdio.h>
#include <string.h>
void revFile(char*);
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


void createFileFromString(char *file, char *data) //Saves the String n reverse order
{
    FILE *fp;
    fp = fopen(file, "w+");
    int i = strlen(data);
    while(i-->0)
        fputc(data[i],fp);

    fclose(fp);
}

void readFile(char *file)
{
    revFile(file);
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
      printf ("%c", ch);            //Here add the delimeter in the final file e.g. %c~

   if (!fclose(fp))
      printf(" closed %s.\n", file);
    revFile(file);
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

void revFile(char *name)
{
    FILE *fp,*fp2;
    fp = fopen(name,"r+");
    fp2 = fopen(name,"r+");
    fseek(fp2,-1,SEEK_END);
    
    char ch;
    while(ftell(fp) < ftell(fp2))
    {
        ch = fgetc(fp);
        fseek(fp,-1,SEEK_CUR);

        fputc(fgetc(fp2),fp);
        fseek(fp2,-1,SEEK_CUR);

        fputc(ch,fp2);
        fseek(fp2,-2,SEEK_CUR);
    }
    fclose(fp);fclose(fp2);
}

//void multiply(char *file1, char *file2, char *file2)
void multiply(char *n1, char *n2) // file 3 = file1 * file 2
{
    char *file1 = "num1.txt", * file2 = "num2.txt", *file3 = "num3.txt";
    
    createFileFromString(file1, n1);
    copy(file1, file3);

    createFileFromString(file2, n2);

    while(reduceByOne(file2))
        addFile(file1, file3);
    
    //readFile(file3);
}

void multiplywith3(char *n2)
{
    char *file1 = "num1.txt", * file2 = "num2.txt", *file3 = "num3.txt";
    
    copy(file3, file1);  // 3 to 1
    createFileFromString(file2, n2);

    while(reduceByOne(file2))
        addFile(file1, file3);
    
    //readFile(file3);
}
int main()
{

    char *first, *second;
    scanf("%m[^ ]", &first); getchar();
    scanf("%m[^ ]", &second); getchar();

    multiply(first, second); // file 3 = first * second
    for(int i = 0; i<3; i++)
    {
        char *tmp;
        scanf("%m[^ ]", &tmp); getchar();
        multiplywith3(tmp);
    }
    char *tmp;
    scanf("%m[^\n]", &tmp); getchar();
    multiplywith3(tmp);

    readFile("num3.txt");

}

