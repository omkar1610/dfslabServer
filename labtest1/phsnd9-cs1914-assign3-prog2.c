#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
tot = total number of students initially
remaining = no of students remaining after removing some students
curr_pos = starting loc or current location
len = length of the rhyme
step = on which step i ma on for this iteration
*/

// Broadly i will keep on making the removed location -1 in the array
void play(int *arr, int remaining, int curr_pos, int len, int step, int tot)
{
	//if 1 stud is remaining, just find the location where value is 0
	//This is the last removal
	if(remaining==1)
	{
		int i;
		for(i=1;i<=tot;i++) if(arr[i] == 0) printf("%d\n", i);
		free(arr);
	}
	//If curr stud is removed I have to go to the next one anyway
	else if(arr[curr_pos] != 0)
	{
		curr_pos = curr_pos==tot?1:curr_pos+1;	//If curr_pos is last loc of array, It will be 1 next		
		play(arr,remaining,curr_pos,len,step,tot);
	}
	//This is the removal points except the last one
	else if(step == 1)
	{
		//If current stud is not removed, remove him
		arr[curr_pos] = -1;
		printf("%d ", curr_pos);
		curr_pos = curr_pos==tot?1:curr_pos+1; //If curr_pos is last loc of array, It will be 1 next
		step = len%(remaining-1)==0?remaining-1:len%(remaining-1); //If % gives zero then I have to make a full circle
		play(arr,remaining-1,curr_pos,len,step,tot);
	}
	//Just keep on going forward till step becomes 1
	else
	{
		if(arr[curr_pos] == 0)
		{
			curr_pos = curr_pos==tot?1:curr_pos+1;
			play(arr,remaining,curr_pos,len,step-1,tot);
		}
	}
}


int main(){
	int t;scanf("%d",&t);
	while(t--)
	{
		int i, n, curr_pos, len;
		scanf("%d%d%d",&n,&curr_pos,&len);
		int *arr = (int *)calloc(n+1,sizeof(int));
		//step size is length % total no of people
		//If % gives zero then I have to make a full circle
		int step = 0==len%n?n:len%n; 

		play(arr,n,curr_pos,len,step,n);
	}
}