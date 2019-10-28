#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
{
	char c;
	int t_no;
}OP_LIST;

typedef struct
{
	char *var;
	OP_LIST *oper;
}VAR_LIST;

typedef struct
{
	int line_no;
	char *var;
	char c;
	int t_no;
}TOT_FILE;


int comp_struct(const void *t1, const void *t2)
{

	return (*(TOT_FILE *)t1).line_no - (*(TOT_FILE *)t2).line_no;
}


int main(int argc, char const *argv[])
{

	int tot_line_size = 1000;
	TOT_FILE *tot_file = malloc(tot_line_size * sizeof(TOT_FILE));
	int line = 0;


	for (int i = 1; i < argc; ++i)
	{
		// printf("FILE %d\n",i);
		FILE *fp = fopen(argv[i],"r");
		int c; char *Var;
		fscanf(fp,"%d",&c); fgetc(fp); //eat up first line i.e no of lines
		do
		{
			
			fscanf(fp,"%d",&c);
			fgetc(fp);
			
			char *str; fscanf(fp,"%m[^\n]",&str);
			if(str[0] == 'r' || str[0] == 'w') 
			{
				strtok(str,"(");
				Var = strtok(NULL,")");
				// printf("%d %s %c %d\n",c, Var, str[0], i);
				if(line == tot_line_size-1)
				{
					tot_line_size *= 2;
					tot_file = realloc(tot_file, tot_line_size * sizeof(TOT_FILE));
				}
				tot_file[line].line_no = c;
				tot_file[line].var = malloc(strlen(Var));
				strcpy(tot_file[line].var, Var);

				tot_file[line].c = str[0] - 'a' + 'A';
				tot_file[line++].t_no = i;
				free(str);
			}
		}while(fgetc(fp) != EOF);

		fclose(fp);
	}

	//sort according to line number
	qsort(tot_file, line, sizeof(TOT_FILE), comp_struct);



	for (int i = 0; i < line; ++i)
		printf("%d %s %c %d\n",tot_file[i].line_no, tot_file[i].var, 
										tot_file[i].c, tot_file[i].t_no);

	

	return 0;
}