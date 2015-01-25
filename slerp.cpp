/*spherical interpolation between two quaternions*/
#include <math.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;
float q1vx,q1vy,q1vz,q2vx,q2vy,q2vz,q1s,q2s;
float u,quvx,quvy,quvz,qus;

vector <float> slerp(float q1vx,float q1vy, float q1vz, float q2vx,float q2vy,float q2vz,float q1s,float q2s)
{
	vector<float> slr;
	
	float u=0, sine, cosine, theta, a1, a2;

	for (int i=0; i<16;i++)
	{
		u = u+0.6250;
		cosine = q1vx * q2vx + q1vy * q2vy +
	         q1vz * q2vz + q1s * q2s;
	sine = sqrt(1 - cosine*cosine);
	theta = atan2(sine,cosine);

	if (sine < 0.0001) 
	     {
		a1 = 1-u;
		a2 = u;
	     }
	else {
		a1 = sin( (1-u)*theta )/sine;
		a2 = sin( u*theta )/sine;
	     }

	quvx = a1 * q1vx + a2 * q2vx;
	quvy = a1 * q1vy + a2 * q2vy;
	quvz = a1 * q1vz + a2 * q2vz;
	qus   = a1 * q1s   + a2 * q2s;

	slr.push_back(quvx);
	slr.push_back(quvy);
	slr.push_back(quvz);
	slr.push_back(qus);
	}
	return slr;
}
