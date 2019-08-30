#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
#define FF '.'
#define BB '@'

#define PRINT {\
for(i=0;i<leng;i++)\
	{\
		for(j=0;j<leng;j++)\
			printf("%c ", mat[i][j]);\
		printf("\n");\
	}\
	printf("\n");\
}


int main()
{
	int mat[5][5]= {FF,FF,FF,BB,FF,
				  BB,FF,BB,FF,FF,
				  FF,FF,BB,FF,FF,
				  BB,FF,FF,FF,BB,
				  BB,FF,FF,BB,FF};
	int start_x=0,start_y=0,leng = 5,end_x,end_y;
	int i,j,dir = 1;
	while(start_x <5 && start_x>=0 && start_y <5 && start_y>=0)
	//int p = 5;while(p--)
	{
		end_x = start_x, end_y = start_y;
		PRINT
		
		if(mat[start_x][start_y] != BB)
			{
				mat[start_x][start_y] = '*';
				if(dir == 1) 	  start_y++;
				else if(dir == 2) start_x++;
				else if(dir == 3) start_y--;
				else if(dir == 4) start_x--;
				
			}
		else
			{
				mat[start_x][start_y] = '*';
				dir = dir==4?1:dir+1;
			}
	}
	PRINT

	printf("EXIT X : %d Y : %d\n", end_x,end_y);
	return 0;
}