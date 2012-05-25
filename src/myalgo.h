#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <inttypes.h>

using namespace std;
#define INT_MAX 1073741824
#define uint unsigned int
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(i=a; i<b; i++)
#define ll long long
#define p_vector(v) for(uint tptr=0; tptr<v.size(); tptr++) \
	cout<<v[tptr]<<endl;  //prints the vector elements

class FastInput {
public:
    FastInput() {
	m_dataOffset = 0;
	m_dataSize = 0;
	m_v = 0x80000000;
    }
 
    unsigned int ReadNext() {
	if (m_dataOffset == m_dataSize) {
	    int r = read(0, m_buffer, sizeof(m_buffer));
	    if (r <= 0) return m_v;
	    m_dataOffset = 0;
	    m_dataSize = 0;
	    int i = 0;
	    if (m_buffer[0] < '0') {
		if (m_v != 0x80000000) {
		    m_data[m_dataSize++] = m_v;
		    m_v = 0x80000000;
		}
		for (; (i < r) && (m_buffer[i] < '0'); ++i);
	    }
	    for (; i < r;) {
		if (m_buffer[i] >= '0') {
		    m_v = m_v * 10 + m_buffer[i] - 48;
		    ++i;
		} else {
		    m_data[m_dataSize++] = m_v;
		    m_v = 0x80000000;
		    for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
		}
	    }
	}
	return m_data[m_dataOffset++];
    }
 
public:
    uint8_t m_buffer[32768];
    uint32_t m_data[16384];
    size_t m_dataOffset, m_dataSize;
    uint32_t m_v;
};
 
class FastOutput {
public:
    FastOutput() {
	m_dataOffset = 0;
    }
    ~FastOutput() {
    }
 
    void Flush() {
	if (m_dataOffset) {
	    if (write(1, m_data, m_dataOffset));
	    m_dataOffset = 0;
	}
    }
    void PrintUint(uint32_t v, char d) {
	if (m_dataOffset + 11 > sizeof(m_data)) Flush();
	if (v < 100000) {
	    if (v < 1000) {
		if (v < 10) {
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 1;
		} else if (v < 100) {
		    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 2;
		} else {
		    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 3;
		}
	    } else {
		if (v < 10000) {
		    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 4;
		} else {
		    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 5;
		}
	    }
	} else {
	    if (v < 100000000) {
		if (v < 1000000) {
		    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 6;
		} else if (v < 10000000) {
		    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 7;
		} else {
		    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 8;
		}
	    } else {
		if (v < 1000000000) {
		    m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 9;
		} else {
		    m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
		    m_data[m_dataOffset + 0] = v + 48;
		    m_dataOffset += 10;
		}
	    }
	}
	m_data[m_dataOffset++] = d;
    }
    void PrintChar(char d) {
	if (m_dataOffset + 1 > sizeof(m_data)) Flush();
	m_data[m_dataOffset++] = d;
    }
    void ReplaceChar(int offset, char d) {
	m_data[m_dataOffset + offset] = d;
    }
 
public:
    uint8_t m_data[32768];
    size_t m_dataOffset;
};



class bignum {
public:
    int len;
    char val[100];
    bignum(int val);
    bignum(const char *, int);
    void printval();
    void add(bignum&, bignum&);
};

bignum::bignum(int t) {
    len=0;
    while(t) {
	val[len] = t%10;
	t/=10;
	len++;
    }
}

bignum::bignum(const char* c, int l) {
    len=0;
    while(len < l) {
	val[len++] = *(c++);
    }
}

void bignum::printval() {
    if(len==0) printf("0");
    for(int i=len-1;i>=0;i--) {
	printf("%c", '0'+val[i]);
    }
}

void bignum::add(bignum &src1, bignum &src2) {
    char carry = 0; int i;
    for(i=0; i<MIN(src1.len, src2.len); i++) {
	val[i] = src1.val[i]+src2.val[i]+carry;
	carry = val[i]/10;
	val[i] %= 10;
    }
    if(src1.len>src2.len) {
	for(;i<src1.len;i++) {
	    val[i] = src1.val[i]+carry;
	    carry = val[i]/10;
	    val[i] %= 10;
	}
    } else {
	for(;i<src2.len;i++) {
	    val[i] = src2.val[i]+carry;
	    carry = val[i]/10;
	    val[i] %= 10;
	}
    }
    if(carry) {
	val[i++] = carry;
    }
    len=i;
}
//---END CLASS BIGNUM


void printpath(int *arr, int *path, int end)
{
    if(end> -1){
        printpath(arr,path,path[end]);
        printf("%d ",arr[end]);
    }
}
void lis(int *arr, int n)
{
    int *s = new int[n];    //current max number of ints
    int *path = new int[n]; //previous number
    memset(path,0,n);

    int global_max = 1;        //at least one number
    int end_pos = 0;

    s[0]= 1;
    path[0]= -1;
    for(int i=1;i<n;i++){
        int local_prev = -1;
        s[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && s[i]<(s[j]+1)){
                s[i]= s[j]+1;
                local_prev = j;
            }
        }

        path[i] = local_prev;
        if(global_max < s[i]){
            global_max = s[i];
            end_pos = i;
        }
    }

    printf(" size of longest seq : %d \n",global_max);
    printpath(arr,path,end_pos);
    printf("\n");
    delete(path);
    delete(s);
}

vector<int> mindistance_bfs_unweighted(int start, vector< vector<int>  > &adj) {
    uint i;uint n = adj.size();
    char col[n];
    vector<int> dis;
    memset(col, 0, n*sizeof(char));
    FOR(i, 0, n)
	dis.push_back(INT_MAX);
    queue<int> tr;
    tr.push(start);
    col[start] = 1;
    dis[start] = 0;
    while(!tr.empty())
    {
	int a = tr.front(), d = dis[a]+1;
	FOR(i,0,adj[a].size())
	{
	    if(dis[adj[a][i]] > d) {
		dis[adj[a][i]] = d; tr.push(adj[a][i]); }
	}
	tr.pop();
    }
    return dis;
}

int hcf(ullong a, ullong b)
{
    int x;
    while(b)
    {
	x = a%b;
	a = b;
	b = x;
    }
    return a;
}

inline int lcm(int a, int b) {
    return (a*b)/hcf(a,b);
}

int num_div_by_all(int n, vector<int> &a) {
    int sum = 0, k =0, last = a[0], temp;uint i;
    sum += n/last;
    vector<int> b;
    k++;
    FOR(i, 1, a.size()) {
	temp = a[i];
	b.push_back(lcm(temp, last));
	sum += n/temp;
	last = temp;
    }
    if(!b.empty())
	sum -= num_div_by_all(n, b);
    return sum;
}

bool eq_vector_int(vector<int> &a, vector<int> &b) {
    uint i;uint as=a.size();
    if(b.size() != as) return false;
    FOR(i, 0, as)
	if(a[i]!=b[i]) return false;
    return true;
}

vector<string> split(string &s, char c) {
    uint i;
    int lp=0, count = 0;
    vector<string> res;
    FOR(i, 0, s.size()) {
	count++;
	if(s[i] == c) {
	    string t = s.substr(lp, count);
	    res.push_back(t);
	    count = 0;
	    lp = i+1;
	}
    }
    return res;
}

string reverse(string s) {
    string rev;
    for(int t = s.size()-1; t>=0; t--)
	rev.push_back(s[t]);
    return rev;
}


// ---------- Union set data structure -------------------
void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}
// ---------------Union set data structure ends ----------

// ---------- Union set another implementation -----------

#define mx 100005
int parent[mx], rank[mx];
int N, M;
void init() {
    for(int i = 0; i <= N; ++i) {
	parent[i] = i;
	rank[i] = 0;
    }
}
 
int root(int x) {
    if(parent[x] != x) parent[x] = root(parent[x]);
    return parent[x];
}
 
inline bool merge(const int &a, const int &b) {
    int ra = root(a), rb = root(b);
    if(ra == rb) return false;
 
    if(rank[ra] > rank[rb]) parent[rb] = ra;
    else parent[ra] = rb;
    if(rank[ra] == rank[rb]) rank[rb]++;
    return true;
}

//------------- Union set ends ---------------------------



// -------------- SPLAY TREES -----------------------------

class node {
public:
    node *p, *l, *r;
    int id, s, rev;
    node(int id_, node *p_) { p=p_; l=0; r=0; id=id_; s=1; rev=1; }
};

void set_size(node *n) {
    n->s=1;
    if (n->l) { n->s+=n->l->s; }
    if (n->r) { n->s+=n->r->s; }
}

int get_size(node *n) {
    if (n==0) return 0;
    else return n->s;
}

void resolve(node *n) {
    if (n==0) return;
    if (n->rev==-1) {
	n->rev=1;
	if (n->l!=0) { n->l->rev*=-1; }
	if (n->r!=0) { n->r->rev*=-1; }
	swap(n->l,n->r);
    }
}

void rotate(node *n) {
    node *p=n->p;
    node *g=p->p;
    resolve(g);
    resolve(p);
    resolve(n);
    if (g!=0) {
        if (g->l==p) g->l=n; else g->r=n;
        n->p=g;
    } else {
        n->p=0;
    }
    if (p->r==n) {
        p->r=n->l;
        if (n->l!=0) n->l->p=p;
        n->l=p;
    } else {
        p->l=n->r;
        if (n->r!=0) n->r->p=p;
        n->r=p;
    }
    p->p=n;
    set_size(p);
    set_size(n);
}

void splay(node *n) {
    while (1) {
        node *p=n->p;
        resolve(p);
        if (p==0) { break; }
        node *g=p->p;
        resolve(g);
        if (g==0) { rotate(n); }
        else if ((p->l==n)==(g->l==p)) { rotate(p); rotate(n); }
        else { rotate(n); rotate(n); }
    }
}

node* detach(node* &n, int k) {
    if (k==0) return 0;
    if (k==n->s) {
	node *front = n;
	n = 0;
	return front;
    }
    k=k+1;
    resolve(n);
    int sl=get_size(n->l);
    while (sl+1!=k) {
        if (sl>=k) n=n->l;
        else {
	    k-=sl+1;
	    n=n->r;
        }
        resolve(n);
        sl=get_size(n->l);
    }
    splay(n);
    node *front = n->l;
    front->p=0;
    n->l=0;
    set_size(n);
    return front;
}

node* merge(node *n1, node *n2) {
    if (n1==0) return n2;
    if (n2==0) return n1;
    resolve(n2);
    while (n2->l!=0) {
	n2=n2->l;
	resolve(n2);
    }
    splay(n2);
    n2->l=n1;
    n1->p=n2;
    set_size(n2);
    return n2;
}

node* build(int n1, int n2) {  // build with 1(start), n(end)
    if (n1>n2) return 0;
    int k = (n1+n2)/2;
    node *n = new node(k,0);
    n->l = build(n1,k-1);
    n->r = build(k+1,n2);
    set_size(n);
    if (n->l) n->l->p=n;
    if (n->r) n->r->p=n;
    return n;
}

void print(node *n) {
    if (n==0) return;
    resolve(n);
    print(n->l);
    printf("%d ",n->id);
    print(n->r);
}

// ------------ SPLAY TREES ENDS ------------------------------

// ------------ SKIPLIST with merge detach rotate -------------


#define SKIPLIST_MAX_HEIGHT 18
#define SKIPLIST_SCALE 2.0

typedef struct struct_skip_list{
    int height;
    int val;
    int *dist;
    struct struct_skip_list **next;
}skipList;


void skipListInit(skipList *s, int val, int height){
    int i;
    if(height <= 0){
	REP(i,1,SKIPLIST_MAX_HEIGHT) if(RAND*SKIPLIST_SCALE < 1.0) break;
	height = i;
    }
    s->dist = (int*)malloc(height*sizeof(int));
    s->next = (skipList**)malloc(height*sizeof(skipList*));
    rep(i,height) s->dist[i] = -1;
    s->val = val;
    s->height = height;
}

void skipListFree(skipList *s){
    free(s->dist); free(s->next);
}

int skipListGetSize(skipList *s){
    int i;
    for(i=s->height-1; i>=0; i--) if(s->dist[i] > 0){
	    return s->dist[i] + skipListGetSize(s->next[i]);
	}
    return 0;
}

void skipListAddElementInLast(skipList *s, skipList *add, int sz){
    int i;
    for(i=s->height-1; i>=0; i--){
	if(s->dist[i] < 0 && i < add->height){
	    if(sz <= -1) sz = skipListGetSize(s);
	    s->dist[i] = sz+1;
	    s->next[i] = add;
	    continue;
	}
	if(s->dist[i] >= 0){
	    skipListAddElementInLast(s->next[i], add, sz-(s->dist[i]));
	    break;
	}
    }
}

void skipListAddListInLast(skipList *s, skipList *add, int sz){
    int i;
    for(i=s->height-1; i>=0; i--){
	if(s->dist[i] < 0 && add->dist[i] >= 0){
	    if(sz <= -1) sz = skipListGetSize(s);
	    s->dist[i] = sz + add->dist[i];
	    s->next[i] = add->next[i];
	    continue;
	}
	if(s->dist[i] >= 0){
	    skipListAddListInLast(s->next[i], add, sz-(s->dist[i]));
	    break;
	}
    }
}

/* a => a[1..K], b => a[K+1..last] */
void skipListDevide(skipList *a, skipList *b, int K){
    int i;
  
    rep(i,a->height) b->dist[i] = -1;
  
    for(i=a->height-1; i>=0; i--){
	if(a->dist[i] < 0) continue;
	if(a->dist[i] > K){
	    b->dist[i] = a->dist[i] - K;
	    b->next[i] = a->next[i];
	    a->dist[i] = -1;
	    continue;
	}
	if(a->dist[i] <= K){
	    skipListDevide(a->next[i], b, K-(a->dist[i]));
	    break;
	}
    }
}

skipList* skipListGetKthElement(skipList *s, int K){
    int i;
  
    if(K==0) return s;
    for(i=s->height-1; i>=0; i--){
	if(s->dist[i] < 0) continue;
	if(K >= s->dist[i]) return skipListGetKthElement(s->next[i], K-(s->dist[i]));
    }
  
    return (skipList*)NULL;
}

void skipListPuts(skipList *s){
    int br = 0;
    for(;;){
	if(s->dist[0] < 0) break;
	s = s->next[0];
	/*    if(br) printf(" -> "); else br = 1;*/
	if(br) putchar(' '); else br = 1;
	printf("%d",s->val+1);
    }
    puts("");
}

//
// sample usage
skipList S, A, B, C, ls[111111]; /* list: 1 -> 2 -> ... initially */
skipList SS, AA, BB, CC, lsls[111111]; /* list: N -> N-1 -> ... initially */

skipListInit(&S, -1, SKIPLIST_MAX_HEIGHT);
skipListInit(ls+i, i, 0);
skipListAddElementInLast(&S, ls+i, i);
skipListInit(lsls+i, N-1-i, 0);
skipListAddElementInLast(&SS, lsls+i, i);
//


//---------------END SKIPLIST ---------------------------





void intIntIntSort(int d[],int m1[],int m2[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m1[i];m1[i]=m1[j];m1[j]=t;t=m2[i];m2[i]=m2[j];m2[j]=t;}intIntIntSort(d,m1,m2,i);intIntIntSort(d+j+1,m1+j+1,m2+j+1,s-j-1);}



char* reverse_char_string(const char* c, int len) {
    char *a=new char[len+1];
    int i=0,j=len-1;
    for(;j>=0;i++,j--)
	a[i] = c[j];
    a[len] = '\0';
    return a;
}

int lcs_len(string a, string b) {
    int al = a.size(), bl = b.size();
    int i, j, mat[al+1][bl+1];
    FOR(i, 0, al+1)
	mat[i][0] = 0;
    FOR(i, 0, bl+1)
	mat[0][i] = 0;
    FOR(i, 1, al+1) {
	FOR(j, 1, bl+1) {
	    mat[i][j] = MAX(mat[i-1][j-1],MAX(mat[i-1][j], mat[i][j-1])) + (a[i-1] == b[j-1])?1:0;
	}
    }
    return mat[al][bl];
}

/*
 * This uses (n k) = (n-1 k-1) + (n r-1)
 * So it can compute for large values without overflow
 */
ll nCr_recursive(ll n, ll k) {
    if(n==k || k==0) return 1;
    return nCk_recursive(n-1, k-1) + nCk_recursive(n-1, k);
}

ll nCr_iterative(ll n, ll k) {
    ll res = 1;
    if(k<n-k) k = n-k;
    for(ll i=1; i<=k; i++) {
	ll d = hcf(res, i);
	res/=d;
	res= res*((n-k+i)/(i/d));
    }
    return res;
}

/*
 * Same as above but stores in table. Useful if large no of calls are needed.
 * NOTE: need to update maxn
 */
inline int nCr_dynamic(int n, int k) {
    // --- #define part
    #define MAXN 10005
    //---------------
    //----- global initialization ----
    int tab[MAXN][MAXN];
    int ni=1;
    //--------------------------------
    // ----------- INITIAL INITIALISATION -----------
    tab[0][0]=1;
    //-----------------------------------------

    for(; ni<n+1; ++ni)
    {
	tab[ni][0] = 1;
	for(int j=1; j<ni; ++j)
	{
	    tab[ni][j] = tab[ni-1][j-1] + tab[ni-1][j];
	}
	tab[ni][ni] = 1;
    }
    return tab[n][k];
}

int power(int x, unsigned n) {
    int intermediateProduct = x;
    int result = 1;
    while(n)
    {
        if (n & 1)
            result = intermediateProduct * result;
        n >>= 1;
        intermediateProduct = intermediateProduct * intermediateProduct;
    }
    return result;
}


int inverse(int x){
    return power(x, MODN-2);
}
 
void factAndInvfact(){
    fact[0]=1;
    for(int i=1; i<=MAXN; i++)
	fact[i]=(long long)i*fact[i-1]%MODN;
    invfact[MAXN]=inverse(fact[MAXN]);
    for(int i=MAXN; i>0; i--)
	invfact[i-1]=(long long)i*invfact[i]%MODN;
}

int nCr(int n, int r){
    if(r>n || r<0)
	return 0;
    return (long long)((long long)fact[n]*invfact[r]%MODN)*invfact[n-r]%MODN;
}

/*
 * Finding nCr mod k using inverse mod k operations
 */


pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    while(a != 0) {
	q = b / a;
	r = b % a;
	m = xLast - q * x;
	n = yLast - q * y;
	xLast = x, yLast = y;
	x = m, y = n;
	b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}


// Longest incresing subsequence in )(nlog n)     result stored in b
void lis(vector<int> &a, vector<int> &b)
{
    vector<int> p(a.size());
    int u, v;

    if (a.empty()) return;

    b.push_back(0);

    for (size_t i = 1; i < a.size(); i++)
    {
	// If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
	if (a[b.back()] < a[i])
	{
	    p[i] = b.back();
	    b.push_back(i);
	    continue;
	}

	// Binary search to find the smallest element referenced by b which is just bigger than a[i]
	// Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.
	for (u = 0, v = b.size()-1; u < v;)
	{
	    int c = (u + v) / 2;
	    if (a[b[c]] < a[i]) u=c+1; else v=c;
	}

	// Update b if new value is smaller then previously referenced value
	if (a[i] < a[b[u]])
	{
	    if (u > 0) p[i] = b[u-1];
	    b[u] = i;
	}
    }

    for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}





// ---- Fenwick tree--- From quick retrieval of cumulative sum
// Increase - O(logn)
// Query    - O(logn)
int fenwick_query(const vector<int> &tree, int a, int b) {
    if (a == 0) {
        int sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1)
	    sum += tree[b];
        return sum;
    } else {
        return fenwick_query(tree, 0, b) - query(tree, 0, a-1);
    }
}

// Increases value of k-th element by inc.
void fenwick_increase(vector<int> &tree, int k, int inc) {
    for (; k < (int)tree.size(); k |= k + 1)
        tree[k] += inc;
}

// ---- End of fenwick tree


//-----------------PRIMS MINIMUM SPANNING TREE------------------
/*
class prims
{
private :
int MAX = 100;
int cost[MAX][MAX], tree[MAX][MAX];
  int n;
  public  : void readmatrix();
    int spanningtree(int);
      void display(int);

      // NODES NUMBERED FROM 1 to n
    // Define code of both c[i][j] and c[j][i];
};

void prims :: readmatrix()
{
int i, j;
cout << "\nEnter the number of vertices in the Graph : ";
cin  >> n;
cout << "\nEnter the Cost matrix of the Graph\n\n";
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
cin >> cost[i][j];
}

int prims :: spanningtree(int src)
{
int visited[MAX], d[MAX], parent[MAX];
int i, j, k, min, u, v, stcost;
for (i = 1; i <= n; i++)
{
d[i] = cost[src][i];
visited[i] = 0;
parent[i] = src;
}
visited[src] = 1;
stcost = 0;
k = 1;
for (i = 1; i < n; i++)
{
min = 999;
for (j = 1; j <= n; j++)
{
if (!visited[j] && d[j] < min)
{
min = d[j];
u = j;
}
}
visited[u] = 1;
stcost = stcost + d[u];
tree[k][1] = parent[u];
tree[k++][2] = u;
for (v = 1; v <= n; v++)
if (!visited[v] && (cost[u][v] < d[v]))
{
d[v] = cost[u][v];
parent[v] = u;
}
}
return (stcost);
}

void prims :: display(int cost)
{
int i;
cout << "\nThe Edges of the Mininum Spanning Tree are\n\n";
for (i = 1; i < n; i++)
cout << tree[i][1] << " " << tree[i][2] << endl;
cout << "\nThe Total cost of the Minimum Spanning Tree is : " << cost;
}
*/
//---------------------------------------------------------------


/* ----------- IMPLEMENTATION OF KD-TREE ---------------------- */

typedef struct kdNode2D
{
    kdNode2D(pPoint2D pointList, int pointLength, int depth = 0);

    ~kdNode2D()
        {
	    for(int i=0; i<2; ++i)
		delete sons[i];
        }

    /* Leave depth alone for outside code! */
    unsigned nearest(const Point2D &point, int depth = 0);

    union {
	struct {
	    kdNode2D* left;
	    kdNode2D* right;
	};

	kdNode2D* sons[2];
    };

    Point2D p;

} kdNode2D;



static int cmpX(const void* a, const void* b)
{
    return (*(pPoint2D)a).x - (*(pPoint2D)b).x;
}

static int cmpY(const void* a, const void* b)
{
    return (*(pPoint2D)a).y - (*(pPoint2D)b).y;
}

kdNode2D::kdNode2D(pPoint2D pointList, int pointLength, int depth)
{
    if(pointLength == 1) {
	left    = NULL;
	right   = NULL;
	p               = *pointList;
	return;
    }

    // Odd depth = Y, even depth = X
    if(depth & 1)
	qsort(pointList, pointLength, sizeof(Point2D), cmpY);
    else
	qsort(pointList, pointLength, sizeof(Point2D), cmpX);

    const int halfLength = pointLength >> 1;
    p = pointList[halfLength];
    for(int i=0; i<2; ++i)
	sons[i] = new kdNode2D(pointList + (i*halfLength), halfLength, depth + 1);
}

unsigned kdNode2D::nearest(const Point2D &point, int depth)
{
    /* End of tree. */
    if(!left || !right)   // We assume if left != NULL, then right != NULL (see ctor)
    {
	Point2D r = p;
	for(int i=0; i<2; ++i)
	    r[i] -= point[i];

	return r.dot(r);
    }

    const int tmp = p[depth] - point[depth];
    const int side = tmp < 0; /* Prefer the left. */

    /* Switch depth. */
    depth ^= 1;

    /* Search the near side of the tree. */
    int leftDist = sons[side]->nearest(point, depth);

    /* Radius intersects a kd tree boundary? */
    if(leftDist < (tmp * tmp))
    {
	/* No; this is the nearest point on this side. */
	return leftDist;
    }

    /* Yes; look at the points on the other side. */
    return min(leftDist, sons[side ^ 1]->nearest(point, depth));
}

//------------- END OF KD- TREE IMPLEMENTATION -------------------------


// -------------------- SEGMENT TREE -----------------------------------

const int BASE = 1<<17;
int r[BASE+BASE];
int f[BASE+BASE];
 
int lo,hi;
void update(int ind,int beg,int end)
{
	if(beg>hi || end<lo) return;
	if(lo<=beg && end<=hi)
	{
		r[ind] = end-beg+1 - r[ind];
		f[ind] = 1-f[ind];
		
		int len = end-beg+1;
		for(ind>>=1,len<<=1; ind; ind>>=1,len<<=1)
		{
			r[ind] = r[ind+ind] + r[ind+ind+1];
			if(f[ind])
				r[ind] = len - r[ind];
		}
		return;
	}
	
	int twice=ind<<1;
	int mid = (beg+end)>>1;
	
	update(twice,beg,mid);
	update(twice+1,mid+1,end);
}
 
void updatex(int _lo,int _hi)
{
	lo=_lo;
	hi=_hi;
	update(1,0,BASE-1);
}
 
int query(int ind,int beg,int end,int flip)
{
	if(beg>hi || end<lo) return 0;
	if(lo<=beg && end<=hi) return flip ? end-beg+1 - r[ind] : r[ind];
	
	int twice=ind<<1;
	int mid = (beg+end)>>1;
	flip = flip^f[ind];

	return query(twice,beg,mid,flip) + query(twice+1,mid+1,end,flip);
}
 
int query(int _lo,int _hi)
{
	lo=_lo;
	hi=_hi;
	return query(1,0,BASE-1,0);
}
 
void init()
{
	fill(r,0);
	fill(f,0);
}



// ------------------------------- END OF SEGMENT TREE ---------------------------------------




// ---- FastInput Fastread ----

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

//-------------------------------


//  Josephus Permutation

//Implement JOSEPHUS Permutation Problem..

#include<stdio.h>
#include<conio.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node Node;
Node *start=NULL;

int main()
{
    int n,m,i,count;
    Node *n1,*ptr,*prev=NULL;
    printf("Enter n ");
    scanf("%d",&n);
    printf("Enter m ");
    scanf("%d",&m);
    printf("Josephus permutation is :\n");
    for(i=n;i>0;i--)
    {
	n1=(Node *)malloc(sizeof(Node));
	n1->data=i;
	n1->link=start;
	start=n1;
    }
    ptr=start;
    while(ptr->link!=NULL)
    {
	ptr=ptr->link;
    }
    ptr->link=start;
    ptr=start;
    while(1)
    {
	count=1;
	while(count!=m)
	{
	    prev=ptr;
	    ptr=ptr->link;
	    count++;
	}
	prev->link=ptr->link;
	printf("%d ",ptr->data);
	free(ptr);
	if(ptr==prev)
	    break;
	ptr=prev->link;
    }
    return 0;
}
// ---- End of Josephus Permutation


//-- FLOYD WARSHALL Algorithm----
//-- before calling initialise dist matrix to known distances and unknown or unconnected to INT_MAX
//-- updates dist to shortest known distances.
void floyd_warshall() {
    int i, j, k;
    for (k = 0; k < n; ++k) {
	for (i = 0; i < n; ++i)
	    for (j = 0; j < n; ++j)
		if ((i != j))
		    if ((dist[i][k] + dist[k][j] < dist[i][j]))
			dist[i][j] = dist[i][k] + dist[k][j];
    }
}



int dfs_grid(int obs[][53], int sx, int sy, int r, int c)
{
    char visited[r][c];
    memset(visited, 0, r*c*sizeof(char));
    queue<pii> s;
    s.push(pii(sx, sy));
    ti[sx][sy] = 0;
    visited[sx][sy]=1;
    while(!s.empty())
    {
	pii a = s.front();
	int x = a.first;
	int y = a.second;
	if(x+1 < r && visited[x+1][y]==0 && obs[x+1][y]==0)
	{
	    debug("pushing", x+1, y);
	    s.push(pii(x+1, y));
	    visited[x+1][y] = 1;
	    ti[x+1][y] = ti[x][y] + 1;
	}
	if(y+1 < c && visited[x][y+1]==0 && obs[x][y+1]==0)
	{
	    debug("pushing", x, y+1);
	    s.push(pii(x, y+1));
	    visited[x][y+1] = 1;
	    ti[x][y+1] = ti[x][y] + 1;
	}
	if(x-1>=0 && visited[x-1][y]==0 && obs[x-1][y]==0)
	{
	    debug("pushing", x-1, y);
	    s.push(pii(x-1, y));
	    visited[x-1][y] = 1;
	    ti[x-1][y] = ti[x][y] + 1;
	}
	if(y-1 >=0 && visited[x][y-1]==0 && obs[x][y-1]==0)
	{
	    debug("pushing", x, y-1);
	    s.push(pii(x, y-1));
	    visited[x][y-1] = 1;
	    ti[x][y-1] = ti[x][y] + 1;
	}
	s.pop();
    }
       
}


// Ford fulkerson to calculate maximum flow in a Graph
int fordFulkerson( int n, int s, int t )
{

    /*
      #define MAXN 1000
      int fnet[MAXN][MAXN];
      int cap[MAXN][MAXN];
     */
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );
    
    int flow = 0;
    
    while( true )
    {
        // find an augmenting path
        memset( prv, -1, sizeof( prv ) );
        qf = qb = 0;
        prv[q[qb++] = s] = -2;
        while( qb > qf && prv[t] == -1 )
            for( int u = q[qf++], v = 0; v < n; v++ )
                if( prv[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
                    prv[q[qb++] = v] = u;
	
        // see if we're done
        if( prv[t] == -1 ) break;
	
        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for( int v = t, u = prv[v]; u >= 0; v = u, u = prv[v] )
            bot = min(bot, cap[u][v] - fnet[u][v] + fnet[v][u]);
	
        // update the flow network
        for( int v = t, u = prv[v]; u >= 0; v = u, u = prv[v] )
            fnet[u][v] += bot;
	
        flow += bot;
    }
    
    return flow;
}

void powerMat(ULL f[2][2],ULL n,ULL mod){
    if(n==0||n==1)return;
    ULL m[2][2]={{1,1},{1,0}};
    powerMat(f,n/2,mod);
    multiply(f,f,mod);
    if(n%2!=0)
	multiply(f,m,mod);
}
