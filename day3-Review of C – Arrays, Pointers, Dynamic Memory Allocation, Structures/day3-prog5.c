
 /*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:2 Aug 2019
Program description: uppose complex numbers are stored using structure variablesrepresenting the real and imaginary parts separately.  Ifxandyare two such variables then write logical conditions thatevaluate to TRUE if and only if:x+yis an imaginary number without any real component.x−yis a real number without any imaginary component.xandyare complex conjugate.Bothxandyare real numbers

Acknowledgements:
------------------------------------*/
#include <stdio.h>
struct node {
	int r,i;
};

int imagin(struct node c1,struct node c2)
{
	return (c1.r + c2.r == 0)?1:0;
}

int real(struct node c1,struct node c2)
{
	return (c1.i - c2.i == 0)?1:0;
}


int conju(struct node c1,struct node c2)
{
	return (c1.i + c2.i == 0)?1:0;
}

int imagin(struct node c1,struct node c2)
{
	return (c1.i == 0 && c2.i == 0)?1:0;
}

int main()
{
	struct node c1,c2;
	c1.r = 5, c1.i = 6, c2.r = 7, c2.i = -6;
}