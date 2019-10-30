#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int count;
    char *string;
}LIST;

LIST *Max(LIST* ls,int cur)
{
    int i,j;
    LIST temp;
    for(i=0,j=1;j<cur;j++)
    {
        if(ls[i].count<ls[j].count)
        {
            temp.string=(char*)malloc((100)*sizeof(char));
            temp.count = ls[i].count;
            ls[i].count=ls[j].count;
            ls[j].count=temp.count;

            strcpy(temp.string,ls[i].string);
            strcpy(ls[i].string,ls[j].string);
            strcpy(ls[j].string,temp.string);
            
            free(temp.string);
        }
    }
    return ls;
}

LIST *Min(LIST* ls,int cur)
{
    int i,j;
    LIST temp;
    for(i=cur-1,j=cur-2;j>=0;j--)
    {
        if(ls[i].count>ls[j].count)
        {
            temp.string=(char*)malloc((100)*sizeof(char));
            temp.count = ls[i].count;
            ls[i].count=ls[j].count;
            ls[j].count=temp.count;

            strcpy(temp.string,ls[i].string);
            strcpy(ls[i].string,ls[j].string);
            strcpy(ls[j].string,temp.string);
            
            free(temp.string);
        }
    }
    return ls;
}


int main(int num,char *str[])
{
    LIST *ls;
    int i=0,j=0,flag=0,cur=0;
    //allocating memory to pointer variable
    ls = (LIST*) malloc((num-1) * sizeof(LIST));
    for(int a=0;a<num-1;a++)
        ls[a].string = (char*) malloc((100) * sizeof(char));
    
    //inserting the strings to List
    do{
        if(i==0)
        {
            ls[0].count=1;
            strcpy(ls[0].string,str[i+1]);
            cur++;
        }
        else
        {
            for(j=0;j<cur;j++)
            {
                if(strcmp(ls[j].string,str[i+1])==0)
                {
                    ls[j].count+=1;
                    flag=1;
                    break;
                }
            }
            if(flag == 0)
            {
                ls[cur].count=1;
                strcpy(ls[cur].string,str[i+1]);
                cur++;
            }
        }
        i++;
        flag=0; 
    }while(i<num-1);

    ls = Max(ls,cur); //shifting max to top position

    ls = Min(ls,cur);   //shifting min to last position
    
    for(int k=0;k<num-1;k++)
    {
        printf("%s ",ls[0].string); //printing the highest frequency string
        ls[0].count--;
        if(ls[cur-1].count)
            printf("%s ",ls[cur-1].string); //printing the lowest freauency string
        ls[cur-1].count--;
        while((ls[cur-1].count)<1) //Remove zero counter string 
        {
            cur--;
            num--;
        }
        ls=Max(ls,cur); //shifting max to top position
        ls=Min(ls,cur); //shifting min to last position
    }

    free(ls); //freeing the memory
    return 0;
}