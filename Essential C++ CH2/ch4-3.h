#pragma once
#include<string>
#include<iostream>
#include<set>
#include<vector>
#include<sstream>
using namespace std;

enum Rank
{
	primary,
	middle,
	high,
	expert
};
class UserProfile;
ostream &operator<<(ostream&, const UserProfile&);
istream &operator >> (istream&, UserProfile&);
class UserProfile
{
public:
	UserProfile(const string &log, const string &name="guest", const int &logN = 0, const int &gN = 0, const int &rN = 0, const Rank &r = primary)
		:_login(log), _trueName(name)
	{
		if (_trueName == "guest")
		{
			guestFlag++;

		}
		stringstream t;
		t <<guestFlag;
		_trueName = "guest"+t.str();
		_logNum = logN;
		_guessNum = gN;
		_rightNum = rN;
		_myrank = r;
	}
	UserProfile() {};
	void Login(const string&log);
	string login()const;
	void name(const string &n);
	string name()const;
	void guessNum(const int &n);
	int guessNum()const;
	void addGuessNum(const int &n = 1);
	void rightNum(const int &n);
	int rightNum()const;
	void addRightNum(const int &n = 1);
	bool operator==(const UserProfile&)const;
	bool operator!=(const UserProfile&)const;
	double correctRate()const;
	friend ostream &operator<<(ostream&, const UserProfile&);
	friend istream &operator >> (istream&, UserProfile&);
private:

	string _login;
	string _trueName;
	int _logNum;
	int _guessNum;
	int _rightNum;
	Rank _myrank;
	static int guestFlag;
};
int UserProfile::guestFlag;
