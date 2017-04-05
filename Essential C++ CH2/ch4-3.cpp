#include"ch4-3.h"
void UserProfile::Login(const string&log)
{
	_login = log;
}
string UserProfile::login()const
{
	string t = _login;
	return t;
}
void UserProfile::name(const string &n)
{
	_trueName = n;
}
string UserProfile::name()const
{
	string t = _trueName;
	return t;
}
void UserProfile::guessNum(const int &n)
{
	_guessNum = n;
}
int UserProfile::guessNum()const
{
	int t = _guessNum;
	return t;
}
void UserProfile::addGuessNum(const int &n )
{
	_guessNum += n;
}
void UserProfile::rightNum(const int &n)
{
	if (n > _guessNum)
	{
		cerr << "input wrong number of rightNumer" << endl;
	}
	_rightNum = n;
}
int UserProfile::rightNum()const 
{
	int t = _rightNum;
	return t;

}
void UserProfile::addRightNum(const int &n)
{
	if (_rightNum + n > _guessNum)
	{
		cerr << "input wrong number of rightNumer" << endl;
	}
	_rightNum += n;
}
bool UserProfile::operator==(const UserProfile&t)const
{
	if (_trueName == t._trueName)return true;
	return false;
}
bool UserProfile::operator!=(const UserProfile&t)const
{
	if (*this == t)return false;
	return true;
}
double UserProfile::correctRate()const
{
	double correctRate = (double)_rightNum / _guessNum;
	return correctRate;
}
ostream &operator<<(ostream&os, const UserProfile&t)
{
	os << t._trueName << " guessNum: " << t._guessNum << " rightNum: " << t._rightNum << " correctRate: " << t.correctRate();
	return os;
}
istream &operator >> (istream&is,  UserProfile&t)
{
	is >> t._trueName >> t._guessNum >> t._rightNum;

	return is;
}