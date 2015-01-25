function [ a,b,c,d ] = ip( p,v )

for i=1:4
a(i)= p(i);
b(i)= v(i);
c(i)= 3*(p(i+1)-p(i))-2*v(i)-v(i+1);
d(i)= -2*(p(i+1)-p(i))+(v(i)+v(i+1));
end
end

