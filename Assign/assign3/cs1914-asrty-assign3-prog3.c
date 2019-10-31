#include <stdio.h>
#include <stdlib.h>
#include<string.h>


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


int checkCycle(int **mat, int argc, int v, int *visited, int *recStack) 
{ 
    if(visited[v] == 0) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = 1; 
        recStack[v] = 1; 
  
        // Recur for all the vertices adjacent to this vertex 
        for(int i = 1; i < argc; ++i) 
        { 
        	if(mat[v][i] == 1)
        	{
		        if ( !visited[i] && checkCycle(mat, argc, i, visited, recStack) ) 
		            return 1; 
		        else if (recStack[i]) 
		            return 1; 
		    }
        } 
  
    } 
    recStack[v] = 0;  // remove the vertex from recursion stack 
    return 0; 
} 

int cyclic(int **mat, int argc) 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    int visited[argc]; 
    int recStack[argc]; 
    for(int i = 1; i < argc; i++) 
    { 
        visited[i] = 0; 
        recStack[i] = 0; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 1; i < argc; i++) 
        if (/*printf("v %d\n", i) &&*/ checkCycle(mat, argc, i, visited, recStack)) 
            return 1; 
  
    return 0; 
} 


int main(int argc, char const *argv[])
{
	printf("Input Requirements : The operation like read/write must be written in lowercase in the file\n \
		the structure of the file given in the document must be followed i.e line_number<space>operation\n \
		The read/write operation must be written in the format given in the question i.e read<open bracket><variable name><Close bracket>\n\n");

	int tot_line_size = 100;
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
			
			fscanf(fp,"%d",&c); // C is the line number
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

	// printf("%d\n", line);
	// for (int i = 0; i < line; ++i)
	// 	printf("%d %s %c %d\n",tot_file[i].line_no, tot_file[i].var, 
	// 									tot_file[i].c, tot_file[i].t_no);


	//sort according to line number
	// This is required as we are neglecting the non read/write operations and storing the rows
	// So there is no chance of reading things simultaneously in all files to get the actual order
	qsort(tot_file, line, sizeof(TOT_FILE), comp_struct);

	// printf("Sorted\n");

	// for (int i = 0; i < line; ++i)
	// 	printf("%d %s %c %d\n",tot_file[i].line_no, tot_file[i].var, 
	// 									tot_file[i].c, tot_file[i].t_no);

	
	int **mat_adj = malloc(argc * sizeof(int *));

	for (int i = 1; i < argc; ++i)
	{
		mat_adj[i] = malloc(argc*sizeof(int));
		for(int j=1 ; j < argc ; ++j)
			mat_adj[i][j] = 0;
	}


	for (int i = 0; i < line-1; ++i)
		for(int j=i+1 ; j < line ; ++j)
		{
			TOT_FILE row1 = tot_file[i], row2 = tot_file[j];
			if((row1.c == 'W' || row2.c == 'W') && strcmp(row1.var, row2.var) == 0 && row1.t_no != row2.t_no)
				// //add an edge from ti to tj
				mat_adj[row1.t_no][row2.t_no] = 1;
		}


	// printf("\nHere\n");

	// for (int i = 1; printf("\n") && i < argc; ++i)
	// 	for(int j=1 ; j < argc; ++j)
	// 		printf("%d ", mat_adj[i][j]);


	printf(cyclic(mat_adj, argc)==1?"Not Conflict Serializable\n":"Conflict Serializable\n");

	return 0;
}