#include "ch3.h"
class comWithLen
{
public:
	bool operator()(string a, string b)
	{
		return a.length() < b.length();
	}
};
void ch3_2()
{
	string nameOfFile;
	cout << "Please input the name of file: ";
	cin >> nameOfFile;
	ifstream in(nameOfFile);
	if (!in)
	{
		cerr << "fuck!" << endl;
		return;
	}
	string word;
	vector<string> words;
	while (in>>word)
	{
		words.push_back(word);
	}
	display(words.begin(), words.end(), cout);
	sort(words.begin(), words.end());
	display(words.begin(), words.end(), cout);
	comWithLen t;
	sort(words.begin(), words.end(), t);
	display(words.begin(), words.end(), cout);
	return;
}
template<typename IteratorType>
void display(IteratorType frist, IteratorType last,ostream &out=cout)
{
	for (; frist != last; frist++)
	{
		out << *frist << " ";
	}
	out << "*****************************************************";
	out << endl;
}