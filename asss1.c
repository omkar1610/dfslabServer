#include <stdio.h>

float actAng(float a1, float a2)
{
	float tmp = a1<a2?a2-a1:a1-a2;
	return tmp>180?tmp-180:tmp;
}



int chkEq(float f1, float f2, float delta)
{
	return f1<f2?(f2-f1<=delta):(f1-f2<=delta);
}
int main(int argc, char const *argv[])
{
	float h,m,s;
	scanf("%f:%f:%f",&h,&m,&s);

	h = h>=12?12-h:h;


	float delta; scanf("%f",&delta);
	printf("TIME : %f %f %f\n",h,m,s );
	float ha, ma, sa;
	ha = h * 30 +m * 0.5 + (s/60);
	ma = m*6 + s*(1/2);
	sa = s*6;
	float hm, ms, sh;
	hm = actAng(ha,ma);
	ms = actAng(ma, sa);
	sh = actAng(sa, ha);

	printf("ANGLE WITH 12 : %f %f %f\n",ha,ma,sa);
	printf("PAIRWISE ANGLE : %f %f %f\n",hm, ms, sh);

	int a1,a2,a3;
	a1 = chkEq(ha, ma,delta);
	a2 = chkEq(ma,sa,delta);
	a3 = chkEq(sa,ha,delta);
	printf("Equality : %d %d %d\n",a1,a2,a3);
	a1+a2+a3==3?(printf("EQU\n")):(a1+a2+a3==2?(printf("SEMI\n")):(printf("NONE\n")));

	return 0;
}