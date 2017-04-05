#include"ch2.h"
bool countPen(vector<int> &a, int num)
{
	if (isArguementValid(num))
	{
		count(a, num);
		return true;
	}
	return false;



}

void display(vector<int>&a, const string &msg, ostream &of)
{
	int n = a.size();
	if (n == 0)
	{
		of << "invalid arguement" << endl;
		return;
	}
	of << "the element of" << msg << "vector is :\n";
	for (int i = 0; i < n; i++)
	{
		of << a[i] << " ";
	}
	of << "\n";
}
const vector<int> * staticVectorCount(int num)
{
	static vector<int> a;
	int i = a.size() + 1;
	for (; i <= num; i++)
	{
		a.push_back((i* (3 * i - 1) / 2));
	}
	return &a;
}
bool valueOfPos(int pos, int &element)
{
	if (pos <= 0) {
		cerr << "invalid arguement\n";
		return false;
	}

	const vector<int> *a = staticVectorCount(pos);
	element = (*a)[pos - 1];
	return true;
}