#pragma once
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>


using namespace std;
void countFrequence();
void readAndcount(istream_iterator<string> frist, istream_iterator<string>last, map<string, int>&count, set<string>exc);

void query(map<string, int>t);
template<typename IteratorType>
void display(IteratorType frist, IteratorType last, ostream &out);

void ch3_2();