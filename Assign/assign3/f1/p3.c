#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char *str;
    int T;
}PRO;


int main(int argc, char **argv)
{
    FILE *inputFiles[argc - 1];
    PRO *p;
    int i,j,lines=0,x;
    //adjacency matrix
    int matrix[argc-1][argc-1];
    int mm[argc-1][argc-1];
    for(i=0;i<argc-1;i++)
    {
        for(j=0;j<argc-1;j++)
        {
            if(i==j)
            {
                matrix[i][j]=1;
                mm[i][j]=0;
            }
            else
            {
                matrix[i][j]=0;
                mm[i][j]=0;
            }
            
        }
    }

    char *str = (char*)malloc(80 * sizeof(char));
    //opening files
    for (i = 1; i < argc; i++)
    {
        //printf("%s\n",argv[i]);
        inputFiles[i] = fopen(argv[i], "r");
        fgets (str, 80, inputFiles[i]);
        sscanf(str, "%d", &x);
        lines+=x;
    }
    
    lines++;
    p = (PRO*)malloc(lines * sizeof(PRO));
    for(int a=1;a<lines;a++)
        p[a].str = (char*) malloc((80) * sizeof(char));
    //reading files
    for (i = 1; i < argc; i++)
    {
        while(fgets (str, 80, inputFiles[i])!=NULL)
        {
            int j=0,sum=0;
            char c = *str;
            while(isdigit(c)!=0)
            {
                x=c-'0';
                sum=sum*10+x;
                j++;
                c=*(str + j);
            }
            strcpy(p[sum].str,str);
            p[sum].T=i;
        }
        printf("\n");
    }
    printf("\n");

    for(i =1;i<lines;i++)
    {
        if((strstr(p[i].str,"read(A)")!=0)||(strstr(p[i].str,"read(B)")!=0))
        {
            if((strstr(p[i].str,"read(A)"))!=0)
            {
                for(j=i+1;j<lines;j++)
                {
                    if((strstr(p[j].str,"write(A)"))!=0)
                    {
                        matrix[p[i].T-1][p[j].T-1]=1;
                    }
                }
            }
            else
            {
                for(j=i+1;j<lines;j++)
                {
                    if((strstr(p[j].str,"write(B)"))!=0)
                        matrix[p[i].T-1][p[j].T-1]=1;
                }
            }
            
        }
        else if ((strstr(p[i].str,"write(A)")!=0)||(strstr(p[i].str,"write(B)")!=0))
        {
            if((strstr(p[i].str,"write(A)"))!=0)
            {
                for(j=i+1;j<lines;j++)
                {
                    if(((strstr(p[j].str,"write(A)"))!=0)||((strstr(p[j].str,"read(A)"))!=0))
                        matrix[p[i].T-1][p[j].T-1]=1;
                }
            }
            else
            {
                for(j=i+1;j<lines;j++)
                {
                    if(((strstr(p[j].str,"write(B)"))!=0)||((strstr(p[j].str,"read(B)"))!=0))
                        matrix[p[i].T-1][p[j].T-1]=1;
                }
            }
        }
    }

    for(i=0;i<argc-1;i++)
    {
        for(j=0;j<argc-1;j++)
        {
            for(int k=0;k<argc-1;k++)
                mm[i][j]+=matrix[i][k]*matrix[k][i];   
        }
    }

    for(i = 0;i<argc-1;i++)
    {
        if((mm[i][i])!=1)
        {
            printf("Not Conflict Serializable");
            break;
        }
    }
    if(i==argc-1)
    {
        printf("Conflict Serializable");
    }
    //freeing Files
    for (i = 1; i < argc; i++)
    {
        free(inputFiles[i]);
    }
  return 0;
}