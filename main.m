A = importdata('robot.key'); %loading data from file

p1=[A(2) A(8) A(14) A(20) A(26)];%loading the first column file
v1=[A(5) A(11) A(17) A(23) A(29)];%velocities
[a1,b1,c1,d1] = ip(p1,v1);%function to calc the curve

p2=[A(33) A(39) A(45) A(51) A(57)];
v2=[A(36) A(42) A(48) A(54) A(60)];
[a2,b2,c2,d2] = ip(p2,v2);

p3=[A(3) A(9) A(15) A(21) A(27)];
v3=[A(6) A(12) A(18) A(24) A(30)];
[a3,b3,c3,d3] = ip(p3,v3);

p4=[A(34) A(40) A(46) A(52) A(58)];
v4=[A(37) A(43) A(49) A(55) A(61)];
[a4,b4,c4,d4] = ip(p4,v4);

p5=[A(4) A(10) A(16) A(22) A(28)];
v5=[A(7) A(13) A(19) A(25) A(31)];
[a5,b5,c5,d5] = ip(p5,v5);

p6=[A(35) A(41) A(47) A(53) A(59)];
v6=[A(38) A(44) A(50) A(56) A(62)];
[a6,b6,c6,d6] = ip(p6,v6);

x1=[a1' b1' c1' d1'];%matrix of curves
x2=[a2' b2' c2' d2'];
x3=[a3' b3' c3' d3'];
x4=[a4' b4' c4' d4'];
x5=[a5' b5' c5' d5'];
x6=[a6' b6' c6' d6'];

[y1] = fraseen(x1);%calculating the in between 67 points
y1c = y1(:);
[y2] = fraseen(x2);
y2c = y2(:);
[y3] = fraseen(x3);
y3c = y3(:);
[y4] = fraseen(x4);
y4c = y4(:);
[y5] = fraseen(x5);
y5c = y5(:);
[y6] = fraseen(x6);
y6c = y6(:);

[z1] = fraeen( x1 );
z1c = z1(:,[4]);
[z2] = fraeen( x2 );
z2c = z2(:,[4]);
[z3] = fraeen( x3 );
z3c = z3(:,[4]);
[z4] = fraeen( x4 );
z4c = z4(:,[4]);
[z5] = fraeen( x5 );
z5c = z5(:,[4]);
[z6] = fraeen( x6 );
z6c = z6(:,[4]);

 j1= vertcat(y1c, z1c);
 j2= vertcat(y2c, z2c);
 j3= vertcat(y3c, z3c);
 j4= vertcat(y4c, z4c);
 j5= vertcat(y5c, z5c);
 j6= vertcat(y6c, z6c);
 
fid = fopen('robot.ang', 'w');%output to the file

fprintf(fid, '%f %f %f %f %f %f\n',[j1 j2 j3 j4 j5 j6]);
fclose(fid);

