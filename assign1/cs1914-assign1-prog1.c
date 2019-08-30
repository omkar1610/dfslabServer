#include <stdio.h>

float actAng(float a1, float a2)
{
	float theta = a1<a2?a2-a1:a1-a2;// theta = |a1-a2|
	return theta>180?theta-180:theta; // if more than 180 degree, then take 180 -theta
}



int chkEq(float f1, float f2, float delta)
{
	return f1<f2?(f2-f1<=delta):(f1-f2<=delta); // function is |f1 - f2| <= delta or not; 1 = Yes 0 = No
}
int main()
{
	int h,m,s;
	scanf("%d:%d:%d",&h,&m,&s);

	h = h==12?12-h:h; //Handling 12

	if(m>59 || s>59 || h < 0 || m<0 || s<0 || h>12) 
		{printf("Invalid Entry\n"); return 0;} //cheking valid entry


	float delta; scanf("%f",&delta);
	if(delta < 0) {printf("Invalid Entry\n"); return 0;} //cheking valid entry
	delta *= 180*7/22; //Converting radian to degrees by multiplying 180/pi


	float h_vert, m_vert, s_vert;// angles made by thre hands with 12 in the clock
	h_vert = h * 30.0 +m * 0.5 + (s/120.0);
	m_vert = m*6.0 + s*0.1;
	s_vert = s*6.0;
	float hour_min, min_sec, sec_hour;// min angle between pair of hands
	hour_min = actAng(h_vert,m_vert);
	min_sec = actAng(m_vert, s_vert);
	sec_hour = actAng(s_vert, h_vert);

	//printf("ANGLE WITH 12 : %f %f %f\n",h_vert,m_vert,s_vert);
	//printf("PAIRWISE ANGLE : %f %f %f\n",hour_min, min_sec, sec_hour);

	int h_s_diff,m_h_diff,s_m_diff;// to check if difference between pairs is less than tolerance or not
	h_s_diff = chkEq(hour_min, min_sec,delta);
	m_h_diff = chkEq(min_sec,sec_hour,delta);
	s_m_diff = chkEq(sec_hour,hour_min,delta);
	//printf("Equality : %d %d %d\n",h_s_diff,m_h_diff,s_m_diff);
	//if all are different then sum will be 3
	//if all are same then sum will be 0
	//if any two are same sum will be 1
	3==h_s_diff+m_h_diff+s_m_diff?(printf("EQUIANGULAR\n")):(1==h_s_diff+m_h_diff+s_m_diff)?(printf("SEMI-EQUIANGULAR\n")):(printf("NONE\n"));

	return 0;
}
