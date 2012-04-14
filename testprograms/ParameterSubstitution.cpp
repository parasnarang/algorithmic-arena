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

using namespace std;

class ParameterSubstitution {
public:
	string processParams(string, vector <string>);
};
string ParameterSubstitution::processParams(string code, vector <string> params) {
	int i = 0;
	int n = code.size();
	//printf("%s\n", code.c_str());
	while(i<code.size())
	{
		n = code.size();
		while(i<n &&(code[i]!='$' )) i++;
		if(code[i] == '$' && i+1<n && isdigit(code[i+1]) && code[i+1]!='0')
		{
			int num = 0;
			int end = i;
			i++;
			while(i<n && isdigit(code[i]) && num*10 +(code[i]-'0') < params.size()+1) 
			{
				num= num*10 +(code[i] -'0');
				i++;
			}
			if(i==end || num==0) { continue;}
			printf("%d %d %d %d\n", num, end, i, code.size()-i);
			code = code.substr(0, end) + params[num-1] + code.substr(i, code.size()-i);
			i = end+params[num-1].size();
		}else i++;
		
	}
	return code;
}

double test0() {
	string p0 = "if ($1 == $2) $3;";
	string t1[] = {"12", "12", "doWhatIWant()"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ParameterSubstitution * obj = new ParameterSubstitution();
	clock_t start = clock();
	string my_answer = obj->processParams(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "if (12 == 12) doWhatIWant();";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "$3+$1*$2-$7=$10";
	string t1[] = {"myvar", "490jri", "e09jd9", "dlkjfoiej"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ParameterSubstitution * obj = new ParameterSubstitution();
	clock_t start = clock();
	string my_answer = obj->processParams(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "e09jd9+myvar*490jri-$7=myvar0";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "12342123$13231232$2123211242$a$dlkj$";
	string t1[] = {"$2", "$1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ParameterSubstitution * obj = new ParameterSubstitution();
	clock_t start = clock();
	string my_answer = obj->processParams(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "12342123$23231232$1123211242$a$dlkj$";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "{[(+.*-,/\\:;<=>?@)]}_`~|$$1";
	string t1[] = {"1{[(+.*-,/\\:;<=>?@)]}_`~|"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ParameterSubstitution * obj = new ParameterSubstitution();
	clock_t start = clock();
	string my_answer = obj->processParams(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "{[(+.*-,/\\:;<=>?@)]}_`~|$1{[(+.*-,/\\:;<=>?@)]}_`~|";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "$01";
	string t1[] = {"abc"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ParameterSubstitution * obj = new ParameterSubstitution();
	clock_t start = clock();
	string my_answer = obj->processParams(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "$01";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
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
