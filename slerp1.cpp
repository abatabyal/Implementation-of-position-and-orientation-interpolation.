/*spherical interpolation between two quaternions for last two key frames*/
#include <math.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;
float q1vx1,q1vy1,q1vz1,q2vx1,q2vy1,q2vz1,q1s1,q2s1;
float u1=0,quvx1,quvy1,quvz1,qus1;

vector <float> slerp1(float q1vx1,float q1vy1, float q1vz1, float q2vx1,float q2vy1,float q2vz1,float q1s1,float q2s1)
{
	vector<float> slr1;
	
	float sine, cosine, theta, a1, a2;

	for (int i=0; i<19;i++)
	{
		u1 = u1+0.052632;
		cosine = q1vx1 * q2vx1 + q1vy1 * q2vy1 +
	         q1vz1 * q2vz1 + q1s1 * q2s1;
	sine = sqrt(1 - cosine*cosine);
	theta = atan2(sine,cosine);

	if (sine < 0.0001) 
	     {
		a1 = 1-u1;
		a2 = u1;
	     }
	else {
		a1 = sin( (1-u1)*theta )/sine;
		a2 = sin( u1*theta )/sine;
	     }

	quvx1 = a1 * q1vx1 + a2 * q2vx1;
	quvy1 = a1 * q1vy1 + a2 * q2vy1;
	quvz1 = a1 * q1vz1 + a2 * q2vz1;
	qus1   = a1 * q1s1   + a2 * q2s1;

	slr1.push_back(quvx1);
	slr1.push_back(quvy1);
	slr1.push_back(quvz1);
	slr1.push_back(qus1);
	}
	return slr1;
}
