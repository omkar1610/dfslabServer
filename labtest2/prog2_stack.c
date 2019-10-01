#include "stack.h"

void disp(void *data, char flag)
{
	if(flag == 'c') printf("%c ", *(char *)data);
	else if(flag == 'f') printf("%lf ", *(double *)data);
	else if(flag == 'i') printf("%d ", *(int *)data);
}
size_t Size(char flag)
{
	if(flag == 'c') return sizeof(char);
	else if(flag == 'f') return sizeof(double);
	else if(flag == 'i') return sizeof(int );
}

void inputInt(STACK *s)
{
	;
}


int main(int argc, char const *argv[])
{
	STACK stack;
	STACK *s = &stack;

	

	int max_elements = 4, spill_tol = 3; char flag = 'f';
	//scanf("%c%d%d", &flag, &max_elements, &spill_tol);
	initStack (s, Size(flag), max_elements, spill_tol, disp, flag);

	char *str;
	// while(scanf("%m[^\n]",&str))
	// {
	// 	;
	// 	free(s);
	// 	getchar();
	// }

	// while(scanf("%d%c",&tmp,&ch) == 2 && ch ==' ') // keep on taking inut till end of line
	// {
	// 	data[n-1] = tmp; n++;
	// 	data = (int *)realloc(data, n*sizeof(int));
	// }

	void *eptr = malloc(Size(flag));
	do
	{
		scanf("%m[^\n]",&str);
		if(str == NULL) break;

		
		if(str[0] == '+')
		{
			char *oper = strtok(str, " ");
			char *data = strtok(NULL, " ");
			if(flag == 'i')
			{
				int x = atoi(data);
				memcpy(eptr, &x, s->element_size);
			}
			if(flag == 'f')
			{
				double x = atof(data);
				memcpy(eptr, &x, s->element_size);
			}
			if(flag == 'c')
			{

				memcpy(eptr, &data[0], s->element_size);
			}

			push(s,eptr);
		}
		else if(str[0] == '-')
		{
			pop(s);
		}
		else if(str[0] == '=')
		{
			display(s);
		}

		free(str);
		getchar();

		//gen_display(s);
	}while(1);
	
	gen_display(s);

	return 0;
}