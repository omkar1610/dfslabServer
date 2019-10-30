#include<stdio.h>
#include<stdlib.h>
int divi(int n){
	if(n==1)
		return 1;
	int i=1,r;
	for(i=2;;i++){
		r=n%i;
		if(r==0){
			return i;
			break;
		}
	}
}
int main(){
	int degree_pro;
	scanf("%d",&degree_pro);
	int coeff[degree_pro+1],i;
	char c1;
	for(i=0;;i++){
		scanf("%d%c",&coeff[i],&c1);
		if(c1=='\n')
			break;
	}
	if (i!=degree_pro){
		printf("\n\nINVALID INPUT\n\n");
		return -1;
	}
//	for(i=0;i<degree_pro+1;i++){
//		printf("%d",coeff[i]);
//	}
	int *S;
	if(NULL == (S =(int *) malloc(100*sizeof(int)))){
    printf("Out of memory");
    exit(-1);
	}
	char c;
	int t;
	for(i=0;;i++)
	{
    	scanf("%d%c",&t,&c);
		*(S+i)=t; 
    	if(c=='\n')
			break;
		if(i>90){
			
			if(NULL == (S =(int *) realloc(S,2*sizeof(int )))){
      			printf("Out of memory");
      			exit(-1);
    		}
		}	
	} 
	int S_size=i+1;
/*	for(i=0;i<S_size+1;i++){
		t=*(S+i);
		printf("%d",t);
	}*/
	int pd1,pd2,j,flag1=0,flag2=0,flag;
	for(i=0;i<degree_pro+2;i++){
		pd1=divi(coeff[i]);
		pd2=coeff[i]/pd1;
		for(j=0;j<S_size;j++){
			if(*(S+j)==pd1){
				flag1=1;
				break;
			}
		}
		for(j=0;j<S_size;j++){
			if(*(S+j)==pd2){
				flag2=1;
				break;
			}
		}
		flag = flag1*flag2;
		if(flag==0){
			printf("\n\nFALSE\n\n");
			return 0;
		}	
		
		
	}
	printf("\n\nTRUE\n\n");
			return 0;
}
