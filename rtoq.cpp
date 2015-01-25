/* rotation to quaternions*/
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;
    
    float nx,ox,ax,ny,oy,ay,nz,oz,az;
	float dx, dy, dz, ds, s, vx, vy, vz;
	
int	max(float a,float b,float c,float d)
		{
	int m;

	if ( a >= b && a >= c && a >= d ) m = 1;
	if ( b >= a && b >= c && b >= d ) m = 2;
	if ( c >= a && c >= b && c >= d ) m = 3;
	if ( d >= a && d >= b && d >= c ) m = 4;

	return(m);
}
vector<float> rtoq (float nx,float ox,float ax,float ny,float oy,float ay,float nz,float oz,float az)
	
{
	vector<float> reu;

	dx = 1 + nx - oy - az;
	dy = 1 - nx + oy - az;
	dz = 1 - nx - oy + az;
	ds = 1 + nx + oy + az;

	//printf("dx: %f dy: %f dz: %f ds: %f \n", dx, dy, dz, ds);

	switch( max(dx, dy, dz, ds) ) {
	case 1 : vx = sqrt(dx)/2;
		 vy = (ny + ox)/(4 * vx);
		 vz = (nz + ax)/(4 * vx);
		 s   = (oz - ay)/(4 * vx);
	//printf("case 1 \n");
	break;

	case 2 : vy = sqrt(dy)/2;
		 vx = (ny + ox)/(4 * vy);
		 vz = (oz + ay)/(4 * vy);
		 s   = (ax - nz)/(4 * vy);
	//printf("case 2 \n");
	break;

	case 3 : vz = sqrt(dz)/2;
		 vx = (nz + ax)/(4 * vz);
		 vy = (oz + ay)/(4 * vz);
		 s   = (ny - ox)/(4 * vz);
	//printf("case 3 \n");
	break;

	case 4 : s   = sqrt(ds)/2;
		 vx = (oz - ay)/(4 * s);
		 vy = (ax - nz)/(4 * s);
		 vz = (ny - ox)/(4 * s);
	//printf("case 4 \n");
	}

	
	reu.push_back(vx);
	reu.push_back(vy);
	reu.push_back(vz);
	reu.push_back(s);
	return reu;
}


