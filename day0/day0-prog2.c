/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:23 July 2019
Program description:Given the(x;y)coordinates of the 3 vertices of a triangle, determinewhether the triangle is scalene, isosceles (but not equilateral), orequilateral.
Acknowledgements:
------------------------------------*/
#include<stdio.h>
#include<math.h>

float dist(int x1, int y1, int x2, int y2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}


void main()
{
 float x1,x2,x3,y1,y2,y3;
 printf("Enter x1,y1,x2,y2,x3,y3\n");
 scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
 float s1, s2, s3;
 s1 = dist(x1,y1,x2,y2);
 s2 = dist(x1,y1,x3,y3);
 s3 = dist(x3,y3,x2,y2);
 printf("Sides : %f %f %f\n",s1,s2,s3);
 if(s1==s2)
	if(s2==s3)
		printf("Eq");
	else
		printf("Iso");
 else
	if(s2==s3)
		printf("Iso");
	else
		printf("Scalene");

}
