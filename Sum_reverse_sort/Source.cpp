#include "sum_reverse_sort.h"

#include <iostream>
#include <sstream>
using namespace std;

ostream& operator<<(ostream& os,const vector<int>v) {
	os << "[ ";
	for (const int& i : v)
		os << i << ' ';

	return os<<"]";
}
int main() {
	int a, b;
	string s;
	vector<int> v;

	//
	cout << "a b: ";
	cin >> a >> b;
	cout << Sum(a,b);
	cout << endl;

	//
	cout << "s: ";
	cin >> s;
	cout << endl << Reverse(s) << endl;

	//
	cout << "v5:";
	v.resize(5);
	for (int& i : v)
		cin >> i;
	cout << endl;
	Sort(v);
	for (int& i : v)
		cout << i<<' ';
	cout << endl<< v<<endl;
	return 0;
}