#include"stack.h"
bool Stack::push(const string &s)
{
	if (full())return false;
	_stack.push_back(s);
	return true;
}
bool Stack::pop(string &elem)
{
	if (_stack.empty())return false;
	elem = _stack.back();
	_stack.pop_back();
	return true;
}
bool Stack::peek(string &elem)
{
	if (empty())return false;
	elem = _stack.back();
	return false;

}
int Stack::count(const string &item)
{
	if (empty())return 0;
	int count = 0;
	for (unsigned int i = 0; i < _stack.size(); i++)
	{
		if (_stack[i] == item)
			count++;
	}
	return count;
}
bool Stack::find(const string& item)
{
	if (count(item) > 0)return true;
	return false;
}
bool Stack::copy(const Stack &stac)
{
	if (stac._stack == this->_stack)return false;
	this->_stack = stac._stack;
	return true;

}
ostream&  Stack::operator<<( ostream &os)
{

	os << this->size();
	return os;
}
//int Stack::tt = 1;
//int Stack::ttt[2] = { 1,2 };
int justForfriend(int a)
{
	return a;
}