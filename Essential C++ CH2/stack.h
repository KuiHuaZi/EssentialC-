#pragma once
#include <string>
#include <vector>
#include<ostream>
using namespace std;
class Stack {
public:
	bool push(const string&);
	bool pop(string &elem);
	bool peek(string &elem);
	bool empty();
	bool full();
	int size() const{ return _stack.size(); }
	bool find(const string &);
	int count(const string &);
	bool copy(const Stack &);
	ostream& operator<<( ostream &os);
	friend int justForfriend(int a);
private:
	vector<string> _stack;
	vector<int> _t;
	static int tt;
	static int ttt[2];
};
inline bool Stack::empty()
{
	return _stack.empty();

}
inline bool Stack::full()
{
	if (_stack.size() == _stack.max_size())return true;
	return false;
}

