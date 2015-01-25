function [ y ] = fraseen( x )
u=0;
for j=1:3
for i=1:16

u = u + (1/16);    
y(i,j)=x(j,1)+x(j,2)*u+x(j,3)*u^2+x(j,4)*u^3;
end
end

end

