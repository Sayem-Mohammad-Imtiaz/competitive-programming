#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
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

#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,0,sizeof(x))
#define swap(a,b) a^=b,b^=a,a^=b
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
typedef pair<int,int>pii;



inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b) {return (a>b)?b:a;}
inline dle dis(Point a,Point b) {return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
int M[10000009],u,A[100009];

int init(int b,int e,int n)
{
  if(b==e) return M[n]=A[b];
  else{
   int m=(b+e)/2;
  return M[n]=init(b,m,2*n)+init(m+1,e,2*n+1);    
  }
}
int Query(int b,int e,int i,int j,int n)
{
  if(e<i||b>j) return 0;
  if(b>=i&&e<=j) return M[n];
  int m=(b+e)/2;
  return Query(b,m,i,j,2*n)+Query(m+1,e,i,j,2*n+1);
}
int Update(int b,int e,int i,int n)
{
  if(e<i||b>i) return M[n];
  if(b==i&&e==i){
   if(u)return M[n]=M[n]+u;
   else{
         printf("%d\n",M[n]);
    return M[n]=u;
   }
   }
  int m=(b+e)/2;
  return M[n]=Update(b,m,i,2*n)+Update(m+1,e,i,2*n+1);
}

int main()
{
    int a,b,q,n,i,j,kase,kas=0,typ;
    S1(kase);
    while(kase--)
    {
      S2(n,q);
      rep(i,1,n)
       S1(A[i]);
      init(1,n,1);
      printf("Case %d:\n",++kas);
      while(q--)
      {
       S1(typ);
       if(typ==1)
       {
         S1(a);a++;u=0;
         Update(1,n,a,1);
       }
       else if(typ==2)
       {
         S2(a,u);a++;
         Update(1,n,a,1);
       }
       else
       {
           S2(a,b);a++,b++;
           printf("%d\n",Query(1,n,a,b,1));
       }
      }
    }
    return 0;
}
