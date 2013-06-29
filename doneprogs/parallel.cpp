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
#define debug(args...) {} //{dbg,args; cerr<<endl;}
#define dline cerr<<endl
#define pb           push_back
#define mp           make_pair
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

vector<pii> resv[25];
vector<pii> pv[25];
void recurseup(int start, int end, int depth)
{
    debug("recurse for", start, end, depth);
    if(start >= end)
    {
	return;
    }
    if(start + 1 ==end)
    {
	resv[depth].push_back(mp(start, end));
	return;
    }
    int c = 1;
    while(start+c<=end) c=c<<1;
    c>>=1;
    debug("calling for", start, start+c-1);
    recurseup(start, start+c-1,depth-1);
    if(start + c  <= end)
    {
	debug("calling for", start+c, end);

	recurseup(start+c, end, depth-1);
	resv[depth].push_back(mp(start+c-1, end));
    }
}
void recursedown(int start, int end, int depth)
{
    
    debug("recursedown for", start, end, depth);
    if(start >= end)
    {
	return;
    }
    if(start + 1 ==end)
    {
	if(start!=1) {
	    debug("In", start, end);
	    resv[depth].push_back(mp(start-1, start));
	}
	return;
    }
    int c = 1;
    while(start+c<=end) c=c<<1;
    c>>=1;
    debug("calling for", start, start+c-1);
    recursedown(start, start+c-1,depth+1);
    if(start + c  <= end)
    {
	debug("calling for", start+c, end);

	recursedown(start+c, end, depth+1);
	if(start!=1) {
	    debug("In", start, end);
	    resv[depth].push_back(mp(start-1, start+c-1));
	}
    }
    
}
int main()
{
    int n = readInt();
    int tc = 0;
    recurseup(1, n, 10);
    recursedown(1, n, 11);
    int dc = 0;
    REP(i, 25)
    {
	if(resv[i].size() != 0)
	{
	    dc++;
	}
    }
    pint(dc);
    REP(i, 25)
    {
	if(resv[i].size() != 0)
	{
	    printf("%d", resv[i].size());
	    tc+=resv[i].size();
	    EACH(it, resv[i])
	    {
		printf(" %d+%d=%d", it->first, it->second, it->second);
	    }
	    printf("\n");
	}
    }
    debug("tc", tc, dc);
    
    return 0;
}
