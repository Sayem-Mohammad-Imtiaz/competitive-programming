#include<stdio.h>
long d,x,y;
void euclid(long a,long b)
{
    long x1;
	if(b==0)
	{
		d=a;
		x=1;
		y=0;
		return;
	}
	euclid(b,a%b);
	d=d;
	x1=x-(a/b)*y;
	x=y;
	y=x1;
}

int main()
{ 
	long a,b;
	while(scanf("%ld %ld",&a,&b)==2)
	{
		euclid(a,b);
		printf("%ld %ld %ld\n",x,y,d);
	}
	return 0;
}

		
  

