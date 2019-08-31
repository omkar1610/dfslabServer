/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:26 July 2019
Program description: Structure and quadratic root
Acknowledgements:
------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define sn struct node

sn {
    double a,b;
};

sn *create(double x, double y){
    sn *tmp = malloc(sizeof(sn));
    tmp->a = x;
    tmp->b = y;
    return tmp;
}

sn *multily(sn *s1, sn *s2){
    sn *tm = create(1,1);
    tm->a = s1->a*s2->a-s1->b*s2->b;
    tm->b = s1->a*s2->b+s1->b*s2->a;
    return tmp;
}
int main(){

  double a,b,c;
  scanf("%lf%lf%lf",&a,&b,&c);
  double D = (b*b) - (4*a*c);
  if(D==0)
  {
    printf("Root is %lf\n",-b/(2*a));
    printf("Ratio is 1");
  }
  else if(D>0)
  {
    D = sqrt(D);
    printf("%lf",D);
    printf("Roots are %lf and %lf",(-b+D)/(2*a),(-b-D)/(2*a));
    printf("Ratio is %lf",(-b+D)/(-b-D));
  }
  else
  {
    D = sqrt(-D);
    double tmp = D/(2*a);
    double alpha = -b/(2*a);

    printf("Roots are %lf+(%lf)i and %lf-(%lf)i",alpha,tmp,alpha,tmp);
    sn prod =  multily(create(alpha,tmp),create(alpha,-tmp));
  }
}
