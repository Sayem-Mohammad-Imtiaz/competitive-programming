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
#define i64 int
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

int memo[1020][2];
vi adj[1020];
 
int dp(int node,bool T,int par)
{
  int &ret=memo[node][T];
  if(ret!=-1) return ret;
  
  int i,sz,t=0;
  
  sz=adj[node].size();
  
  if(!T){
    t=1;
    rep(i,0,sz-1)
     if(adj[node][i]!=par)
     t=t+dp(adj[node][i],1,node);
    ret=t;
  }
  t=0;
  rep(i,0,sz-1)
     if(adj[node][i]!=par)
      t=t+dp(adj[node][i],0,node);
  ret=MAX(ret,t);
  if(ret==-1) ret=0;
  return memo[node][T]=ret;
}

int main()
{
    int a,b,res,n,m,i,j,kase,kas=0;
    S1(kase);
    while(kase--)
    {
      S2(n,m);
      rep(i,0,n){
       adj[i].clear();
       rep(j,0,1)
        memo[i][j]=-1;
        }
      while(m--)
      {
        S2(a,b);
        adj[a].pb(b),adj[b].pb(a);
      }
      res=0;
      rep(i,1,n)
      if(memo[i][0]==-1&&memo[i][1]==-1)
       res+=dp(i,0,-1);
      printf("Case %d: %d\n",++kas,res);
    }
    return 0;
}
