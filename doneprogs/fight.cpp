/* Jai Gupta */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <cmath>
#include <functional>
#include <set>

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define uint unsigned int
#define MAX(a,b)   (((a)>(b))?(a):(b))
#define MIN(a,b)   (((a)<(b))?(a):(b))
#define CMAX(a,b)  if((a)<(b)) a=b
#define CMIN(a,b)  if((a)>(b)) a=b
#define FOR(i,a,b)   for(i=a; i<b; i++)
#define REVI(i,a,b)  for(int i= a ; i >= b ; --i)
#define LET(x,a)     __typeof(a) x(a)
#define IFOR(i,a,b)  for(LET(i,a);i!=(b);++i)
#define EACH(it,v)   IFOR(it,v.begin(),v.end())
#define SWAP(a,b,t)  t=a,a=b,b=t
#define REP(i,n)     for(int i=0; i<n; i++)
#define ll           long long int
#define ull          unsigned long long int
#define gint(t)      scanf("%d", &t);
#define gint2(a,b)   scanf("%d%d", &a, &b);
#define gint3(a,b,c) scanf("%d%d%d", &a, &b, &c);
#define pint(t)      printf("%d\n", t);
#define pint2(a,b)   printf("%d %d\n", a, b);
#define pint3(a,b,c) printf("%d %d %d\n", a, b, c);
#define pii          pair<int, int>
#define debug(args...) {dbg,args; cerr<<endl;}
#define dline cerr<<endl
#define pb           push_back
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
	{
	    cerr<<v<<" ";
	    return *this;
	}
} dbg;


#define BUF 4096
char ibuf[BUF];
int ipt = BUF;
 
int readInt() {
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    }
    return n;
}


/* memset(start*, byteVal, numBytes);
 *  memcpy(dst*, src*, numBytes);
 */

ull hcf(ull a, ull b)
{
    ull x;
    while(b)
    {
	x = a%b;
	a = b;
	b = x;
    }
    return a;
}

ull lcm(ull a, ull b) {
    return (a/hcf(a,b))*b;
}


int main()
{
    int t;
    ull a, b, c, d, k, l, r, h1, h2;
    scanf("%d", &t);
    while(t--)
    {
	scanf("%llu %llu %llu %llu %llu", &a, &b, &c, &d, &k);
	h1 = hcf(a, b);
	h2 = hcf(c, d);
	r = 2*((k / (h1 / hcf(h1,h2)) / h2) ) +1 ;
	printf("%llu\n", r);
    }
    return 0;
}
