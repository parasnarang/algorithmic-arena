#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include <string>

using namespace std;

class Triangulation {
public:
	vector <string> triangulate(vector <int>, vector <int>);
};

static int get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y, 
    float p2_x, float p2_y, float p3_x, float p3_y)
{
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s > 0 && s < 1 && t > 0 && t < 1)
    {
        // Collision detected
        return 1;
    }

    return 0; // No collision
}

static std::string to_string(int n)
{
     std::ostringstream os;
     os << n;
     return os.str();
}

vector <string> Triangulation::triangulate(vector <int> x, vector <int> y) {
	vector<string> res;
	vector<pair<int, int> > linesp1 ;
	vector<pair<int, int> > linesp2 ;
	int n = x.size();
	for(int i=0; i<x.size(); i++)
	{
		pair<int, int> p1 = make_pair(x[i%n], y[i%n]);
		linesp1.push_back(p1);
		pair<int, int> p2 = make_pair(x[(i+1)%n], y[(i+1)%n]);
		linesp2.push_back(p2);
	}
	char buf[20], buf2[20];
	printf("%d %d\n", linesp1.size(), linesp2.size());
	for(int i=0; i<x.size(); i++)
	{
		for(int j=i+2; j<x.size(); j++)
		{
			if(i == (j+1)%n) continue;
			int k;
			for(k=0; k<linesp1.size(); k++)
			{
				if(get_line_intersection(linesp1[k].first, linesp1[k].second, linesp2[k].first, linesp2[k].second, x[i], y[i], x[j], y[j]))
				{
					printf("line %d\n", k);
					break;
				}
			}
			if(k==linesp1.size())
			{
				pair<int, int> p1 = make_pair(x[i%n], y[i%n]);
				linesp1.push_back(p1);
				pair<int, int> p2 = make_pair(x[(j)%n], y[(j)%n]);
				linesp1.push_back(p2);
				res.push_back(to_string(i)+string(" ")+to_string(j));
			}
		}
	}
	return res;
}


double test0() {
	int t0[] = {0,10,10,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,10,10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Triangulation * obj = new Triangulation();
	clock_t start = clock();
	vector <string> my_answer = obj->triangulate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "0 2" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {0,10,10,8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,10,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Triangulation * obj = new Triangulation();
	clock_t start = clock();
	vector <string> my_answer = obj->triangulate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "1 3" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {0,5,10,10,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10,5,10,0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Triangulation * obj = new Triangulation();
	clock_t start = clock();
	vector <string> my_answer = obj->triangulate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "1 3",  "1 4" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {0,1,1,0,0,1,1,0,-1,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1,2,2,3,3,4,5,4,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Triangulation * obj = new Triangulation();
	clock_t start = clock();
	vector <string> my_answer = obj->triangulate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "0 2",  "0 3",  "0 8",  "3 8",  "4 6",  "4 7",  "4 8" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {0,1,1,0,1,1,0,-1,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1,2,2,3,4,5,4,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Triangulation * obj = new Triangulation();
	clock_t start = clock();
	vector <string> my_answer = obj->triangulate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "0 2",  "0 3",  "0 7",  "3 5",  "3 6",  "3 7" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
