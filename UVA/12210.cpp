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
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int main()
{
    int b,s,m,i,a,t,kas=1;
    while(scanf("%d %d",&b,&s)&&(b||s))
    {
        scanf("%d",&m);
       for(i=2;i<=b;i++)
        scanf("%d",&a),m=MIN(m,a);
        for(i=1;i<=s;i++)
        scanf("%d",&t);
        printf("Case %d: ",kas++);
       if(b<=s){
        printf("0\n");continue;}
       printf("%d %d\n",b-s,m);
    }
    return 0;
}
