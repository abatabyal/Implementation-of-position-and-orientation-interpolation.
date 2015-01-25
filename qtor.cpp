/* function for converting quaternions to rotation matrix*/
#include <math.h>
#include <math.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <fstream> 

using namespace std;

extern ofstream of;
float vx1, vy1, vz1, s1;
float nx1,ox1,ax1,ny1,oy1,ay1,nz1,oz1,az1;
extern vector<float> eql;

void qtor(float vx1, float vy1, float vz1, float s1)
{
		nx1 = 1 - 2 * (vy1*vy1 + vz1*vz1);
		ny1 = 2 * (vx1*vy1 + s1*vz1);
		nz1 = 2 * (vx1*vz1 - s1*vy1);

		ox1 = 2 * (vx1*vy1 - s1*vz1);
		oy1 = 1 - 2 * (vx1*vx1 + vz1*vz1);
		oz1 = 2 * (vy1*vz1 + s1*vx1);

		ax1 = 2 * (vx1*vz1 + s1*vy1);
		ay1 = 2 * (vy1*vz1 - s1*vx1);
		az1 = 1 - 2 * (vx1*vx1 + vy1*vy1);

		of<<  nx1 <<"   "<< ox1 <<"   "<< ax1 <<"\n";
		of<<  ny1 <<"   "<< oy1 <<"   "<< ay1 <<"\n";
		of<<  nz1 <<"   "<< oz1 <<"   "<< az1 <<"\n";
		of<< "\n";
		of<< "\n";

	}
