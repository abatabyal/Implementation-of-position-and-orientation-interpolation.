/*function for interpolating the position of rotation matrices */
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream> 
#include <vector>
#include <sstream>

using namespace std;
vector<float> al(5);
vector<float> bl(5);
vector<float> cl(5);
vector<float> dl(5);
vector<float> eql;

float l0,l1,l2,l3;
void pos(vector<float> l, vector<float> m)
{
	
	for( int e=0; e<4;e++)
		{
		al[e]= l[e];
		bl[e]= m[e];
		cl[e]= 3*(l[e+1]-l[e])-2*m[e]-m[e+1];
		dl[e]= -2*(l[e+1]-l[e])+(m[e]+m[e+1]);
		}
	double w=0,w1=0;

	for (int f=0; f<16;f++)
		{
			w=w+0.6250;
		l0 = al[0] + bl[0]*w+ cl[0] * (pow(w,2)) +dl[0] *(pow(w,3));
		eql.push_back(l0); 
		}

	for (int f1=0; f1<16;f1++)
		{
			w=w+0.6250;
		l1 = al[1] + bl[1]*w+ cl[1] * (pow(w,2)) +dl[1] *(pow(w,3));
		eql.push_back(l1);
		}

	for (int f2=0; f2<16;f2++)
		{
			w=w+0.6250;
			l2 = al[2] + bl[2]*w+ cl[2] * (pow(w,2)) +dl[2] *(pow(w,3));
			eql.push_back(l2);
		}
	
	for (int f3=0; f3<19;f3++)
		{
			w1=w1+0.6250;
			l3 = al[3] + bl[3]*w+ cl[3] * (pow(w,2)) +dl[3] *(pow(w,3));
			eql.push_back(l3);
		}

		cout << " 67 positions for the rotation matrices Px,Py,Pz";
		for (int f4 = 0;f4<eql.size();f4++)
			{
			cout << eql[f4] << "\n";
		}
}
