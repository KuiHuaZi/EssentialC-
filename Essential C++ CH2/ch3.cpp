#include"ch3.h"
void display(map<string, int>t);
void countFrequence()
{
	string nameOfFile;
	map<string, int>words;
	string a[] = { "a","an","the","and","but","this","that" };
	vector<string> word_exc(a, a + 7);
	set<string>word_exclu(word_exc.begin(), word_exc.end());
	cout << "Please input the name of file: ";
	cin >> nameOfFile;
	ifstream in_file(nameOfFile);
	istream_iterator<string>is(in_file);
	istream_iterator<string>eof;
	readAndcount(is, eof, words, word_exclu);
	query(words);
	display(words);

}
void readAndcount(istream_iterator<string> frist, istream_iterator<string>last, map<string, int>&count,set<string>exc)
{
	int numofa = 0;
	for (;frist != last;frist++)
	{
		if (*frist == "a")
			numofa++;
		if (exc.count(*frist))
			continue;
		count[*frist]++;
	
	}

}
void query(map<string, int>t)
{
	string word;
	while (true)
	{
		cout << "please input word you want ask: ";
		cin >> word;
		if (word == "-1")break;
		if (t.count(word))
		{
			cout << "the count of " << word << " is " << t[word] << endl;
		}
		else
		{
			cout << "the " << word << " donot exit" << endl;
		}
	}
}
void display(map<string, int>t)
{
	map<string, int>::iterator it = t.begin();
	for (; it != t.end(); it++)
	{
		cout << "key: " << it->first << " value: " << it->second << endl;
	}
}