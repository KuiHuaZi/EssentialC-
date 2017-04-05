#pragma once
#include <vector>
#include <iostream>
#include<string>
using namespace std;
bool countPen(vector<int> &a, int num);
void display(vector<int>&a, const string &msg, ostream &of = cout);
inline bool isArguementValid(int num);
inline void count(vector<int> &a, int num);
bool valueOfPos(int pos, int &element);
const vector<int> * staticVectorCount(int num);
inline bool isArguementValid(int num)
{
	if (num <= 0 || num>10000)
	{
		cerr << "sorry,invalid arguement:" << num << endl;
		return false;
	}
	return true;
}
inline void count(vector<int> &a, int num)
{
	for (int i = 1; i <= num; i++) {
		a.push_back((i* (3 * i - 1) / 2));
	}
}