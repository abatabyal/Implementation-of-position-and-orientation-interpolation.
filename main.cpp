/*main function where all the functions are called*/
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream> 
#include <vector>
#include <sstream>

using namespace std;

ofstream of;//global fstream object

//function declaration
extern vector<float> rtoq (float nx,float ox,float ax,float ny,float oy,float ay,float nz,float oz,float az);
extern vector <float> slerp(float q1vx,float q1vy, float q1vz, float q2vx,float q2vy,float q2vz,float q1s,float q2s);
extern vector <float> slerp1(float q1vx1,float q1vy1, float q1vz1, float q2vx1,float q2vy1,float q2vz1,float q1s1,float q2s1);
void qtor(float vx1, float vy1, float vz1, float s1);
void pos(vector<float> l, vector<float> m);

void main()
{
	vector<float> vs;
	ifstream in ("object.key"); //loading the object.key file
	int m,n;
    in >> m >> n;
	
	float x;
    while(in>>x){
	vs.push_back(x);
	}

    
	vector<float> r2q1;
	vector<float> r2q2;
	vector<float> r2q3;
	vector<float> r2q4;
	vector<float> r2q5;
	vector<float> sl1;
	vector<float> sl2;
	vector<float> sl3;
	vector<float> sl4;
	vector<float> q2r1;
	vector<float> q2r2;
	vector<float> q2r3;
	vector<float> q2r4;
	vector<float> px;
	vector<float> py;
	vector<float> pz;
	vector<float> vpz;
	
    
	
	//rotation matrix to quaternions
	r2q1 = rtoq (vs[0],vs[1],vs[2],vs[4],vs[5],vs[6],vs[8],vs[9],vs[10]); 
	r2q2 = rtoq (vs[12],vs[13],vs[14],vs[16],vs[17],vs[18],vs[20],vs[21],vs[22]);
	r2q3 = rtoq (vs[24],vs[25],vs[26],vs[28],vs[29],vs[30],vs[32],vs[33],vs[34]);
	r2q4 = rtoq (vs[36],vs[37],vs[38],vs[40],vs[41],vs[42],vs[44],vs[45],vs[46]);
	r2q5 = rtoq (vs[48],vs[49],vs[50],vs[52],vs[53],vs[54],vs[56],vs[57],vs[58]);

	//spherical interpolation between two quaternions
	sl1 = slerp (r2q1[0], r2q1[1], r2q1[2], r2q1[3], r2q2[0], r2q2[1], r2q2[2], r2q2[3]);
	sl2 = slerp (r2q2[0], r2q2[1], r2q2[2], r2q2[3], r2q3[0], r2q3[1], r2q3[2], r2q3[3]);
	sl3 = slerp (r2q3[0], r2q3[1], r2q3[2], r2q3[3], r2q4[0], r2q4[1], r2q4[2], r2q4[3]);
	sl4 = slerp1 (r2q4[0], r2q4[1], r2q4[2], r2q4[3], r2q5[0], r2q5[1], r2q5[2], r2q5[3]);
	
	of.open ("object.traj");
	//converting quaternions to rotation matrix
	for (int iq=0; iq<64 ;iq=iq+4)
		{
			qtor (sl1[iq], sl1[iq+1], sl1[iq+2], sl1[iq+3]);
			qtor (sl2[iq], sl2[iq+1], sl2[iq+2], sl2[iq+3]);
			qtor (sl3[iq], sl3[iq+1], sl3[iq+2], sl3[iq+3]);
	   }
	for (int iq1=0; iq1<76 ;iq1=iq1+4)
		{
			qtor (sl4[iq1], sl4[iq1+1], sl4[iq1+2], sl4[iq1+3]);
		}

	//interpolating the positions of the rotation matrix
	for (int pcx=3;pcx<52;pcx=pcx+12)
		{
		px.push_back(vs[pcx]);
		}
	for (int pcy=7;pcy<56;pcy=pcy+12)
		{
		py.push_back(vs[pcy]);
		}
	for (int pcz=11;pcz<60;pcz=pcz+12)
		{
		pz.push_back(vs[pcz]);
		}
	int zel=0;
	for (int zer=0;zer<5;zer++)
		{
		vpz.push_back(zel);
		}

	pos (px, vpz);
	pos (py, vpz);
	pos (py, vpz);

	getch();

}
