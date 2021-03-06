#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<cctype>
#include<string>
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;

#define pb push_back
#define mem(x) memset(x,sizeof(x),0)
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 10009
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define eps 0.00000000001

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

struct Point
{
  double x;
  double y;
};
Point Ys[SIZE],Px[SIZE],Py[SIZE];
int n;

bool cmp1(Point a,Point b)
{
  return a.x<b.x;
}
bool cmp2(Point a,Point b)
{
  return a.y<b.y;
}
inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
inline dle sq(dle a)
{
  return a*a;
}
inline dle dis(Point a,Point b)
{
  return (sq(a.x-b.x)+sq(a.y-b.y));
}

dle closest_pair(int b,int e)
{
    dle Dl,Dr,Dm;
    int i,j,Xm,ns;
    
    if(e-b<=2){
     Dm=INT_MX;
     rep(i,b,e-1)
      rep(j,i+1,e){
       Dl=dis(Px[i],Px[j]);
       if(Dm>Dl)
        Dm=Dl;
        }
       return Dm;
      }
      
      Xm=(b+e)/2;
      Dl=closest_pair(b,Xm);  
      Dr=closest_pair(Xm+1,e);
      if(Dl<Dr)
       Dm=Dl;
      else
       Dm=Dr; 
      ns=0;
      rep(i,b,e)
       if(sq(Px[Xm].x-Px[i].x)<Dm)
        Ys[++ns]=Px[i];
      sort(Ys+1,Ys+ns+1,cmp2);
      Dl=Dm;
      rep(i,1,ns-1)
      {
        j=i+1;
        while(j<=ns&&sq(Ys[i].y-Ys[j].y)<Dm)
        {
          Dr=dis(Ys[i],Ys[j]);
          if(Dr<Dl)
          Dl=Dr;
          j++;
        }
      }
      return Dl;   
}
int main()
{
    int i;
    dle D;
    while(scanf("%d",&n)&&n)
    {
     rep(i,1,n){
      scanf("%lf %lf",&Px[i].x,&Px[i].y);
      }
     sort(Px+1,Px+n+1,cmp1);
     D=sqrt(closest_pair(1,n));
     if(D<10000)
     printf("%0.4lf\n",D);
     else
      printf("INFINITY\n");
    }
    return 0;
}
