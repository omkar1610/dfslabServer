#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stud
{
	char *roll, *fn, *ln;
	int attend;
	float agg;
};

void show(struct stud stud)
{
	printf("ROLL : %s, ATTND : %d, AGG : %f, FN : %s, LN: %s\n", stud.roll,
		stud.attend,stud.agg,stud.fn,stud.ln);
}



int comp_struct(struct stud s1, struct stud s2)
{
	return s1.agg>s2.agg?1:0;
}

int main(void)
{

   struct stud ptr[3];
   
   FILE *fp;
   char *line = NULL;
   size_t len = 0;
   size_t read;
   int i, loc = 0;

   fp = fopen("data", "r");
   if (fp == NULL)
       exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, fp)) != -1) {
		printf("Retrieved line of length %lu : ", read);
		printf("%s\n", line);
		char *tmp;
		
		tmp = strtok(line, " ");
		ptr[loc].roll = tmp;
		printf("ROLL :%s\n",tmp);
		line += 1 + strlen(tmp);

		tmp = strtok(line, " ");
		ptr[loc].attend = atoi(tmp);
		printf("ATTND :%s  %d \n",tmp, atoi(tmp));
		line += 1 + strlen(tmp);

		tmp = strtok(line, " ");
		ptr[loc].agg = atof(tmp);
		printf("PERC :%s %f\n",tmp, atof(tmp));
		line += 1 + strlen(tmp);

		tmp = strtok(line, " ");
		ptr[loc].fn = tmp;
		printf("FN :%s\n",tmp);
		line += 1 + strlen(tmp);

		tmp = strtok(line, " ");
		ptr[loc].ln = tmp;
		printf("LN :%s\n",tmp); 


		loc++;            

   }
   fclose(fp);


   printf("%d\n", loc);
   for(i=0;i<loc;i++)
   	show(ptr[i]);
   int max = 0, min = 0;
   for(i=1;i<loc;i++)
   	{
   		if(comp_struct(ptr[i],ptr[max])) max = i;
   		if(comp_struct(ptr[min], ptr[i])) min = i;
   	}

   printf("MAX : %f MIN : %f\n",ptr[max].agg, ptr[min].agg );
   
}