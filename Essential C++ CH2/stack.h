#pragma once
#include <string>
#include <vector>
#include<ostream>
using namespace std;
class Stack {
public:
	virtual bool push(const string&)=0;
	virtual bool pop(string &elem)=0;
	virtual bool peek(string &elem)=0;
	virtual bool empty()=0;
	virtual bool full()=0;
	virtual int size() const{ return _stack.size(); }
	virtual bool find(const string &);

private:
	vector<string> _stack;
	vector<int> _t;
};


