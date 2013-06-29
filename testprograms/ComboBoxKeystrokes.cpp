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
#include <cstdlib>
#include <ctime>
#define MAX(a, b) (((a)<(b))?(b):(a))
using namespace std;

class ComboBoxKeystrokes {
public:
	int minimumKeystrokes(vector <string>);
};

int ComboBoxKeystrokes::minimumKeystrokes(vector <string> elements) {
	int c[26];
	int s = elements.size();
	for(int i=0; i<26 ; i++) c[i] = 0;
	for(int i=0; i<s; i++)
	{
		c[toupper(elements[i][0])-'A']++;
	}
	
	int start = -1, end;
	int max = 0;
	int lastindex = -1;
	for(int i = 0; i<26; i++)
	{
		if(c[i])
		{
			if(lastindex == -1) lastindex = i;
			else
			{
				max = MAX(max, (c[lastindex])/2);
				lastindex = i;
			}
		}
	}
	if(lastindex != -1)
		max = MAX(max, c[lastindex]-1);
	if(max == 0) max = 1;
	return max;
}


double test0() {
	string t0[] = {"alpha","beta","gamma","delta"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ComboBoxKeystrokes * obj = new ComboBoxKeystrokes();
	clock_t start = clock();
	int my_answer = obj->minimumKeystrokes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"kyky","kalinov","kalmakka","Kavan","Kawigi","kaylin","Klinck","krijgertje","kupo"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ComboBoxKeystrokes * obj = new ComboBoxKeystrokes();
	clock_t start = clock();
	int my_answer = obj->minimumKeystrokes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"a","b","c","b","d","b","e","b","f"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ComboBoxKeystrokes * obj = new ComboBoxKeystrokes();
	clock_t start = clock();
	int my_answer = obj->minimumKeystrokes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"apple","Boy","CaRD","Dog","egG","FruiT",
 "Grape","hand","Ant","eagle","ice cream",
 "air","East","Exit","Door","camerA","bad",
 "fast","Zealot","internAtional","Bead",
 "Bread","Exit","fast", "actiVe","Cats",
 "beast","Alligator","drag","castle",
 "clean","iLlEgAl","crab","Free Willy",
 "first","dean","Fourth of July","King",
 "fellow","FrEaK","Elephant","bird","Bible",
 "creep","create","Deal","eEl","entrance",
 "cream","Fleece"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ComboBoxKeystrokes * obj = new ComboBoxKeystrokes();
	clock_t start = clock();
	int my_answer = obj->minimumKeystrokes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
