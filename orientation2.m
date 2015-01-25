function [z ] = fraeen( x )
u1=0;
for j=4
for i=1:19
u1 = u1 + (1/19); 
z(i,j)=x(j,1)+x(j,2)*u1+x(j,3)*u1^2+x(j,4)*u1^3;
end
end

end

