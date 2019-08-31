#include <stdio.h>


void quicksort(int *a,int start,int end){
	int i, j, pivot, temp;
	if(start<end){
		pivot = start;
		i = start;
		j = end;
		while(i<j)
		{
			while(a[i]< = a[pivot]&&i<end) i++;
			while(a[j]>a[pivot]) j--;
			if(i<j)
			{
				temp = a[i]; a[i] = a[j]; a[j] = temp;
			}
		}
		temp = a[pivot]; a[pivot] = a[j]; a[j] = temp;
		
		quicksort(a,start,j-1);
		quicksort(a,j+1,end);
	}
}
int main(){
	int i, count  =  7, a[]  =  {5,4,9,2,1,0,3};
	
	quicksort(a,0,count-1);
	for(i = 0;i<count;i++)
		printf("%d ",a[i]);
	return 0;
}