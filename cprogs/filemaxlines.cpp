#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <queue>

#define NOFILENAME -1
#define FILEOPENERR -2
#define MAXCHARS 512
#define MINHEAPSIZE 50
#define DEBUG 0

struct CustomCompare
{
	bool operator()(const string str1, const string str2)
	{
		return str1.length() > str2.length();
	}
};

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Specify file name as argument";
		return NOFILENAME;
	}

	if (DEBUG)
		cout << argc << " " << argv[1];
	fstream fs;
	try
	{
		// bad for getline
		if (DEBUG)
			fs.exceptions(fstream::badbit | fstream::failbit);
		fs.open(argv[1], fstream::in);
	}
	catch (const fstream::failure& ex)
	{
		cout << endl << "File I/O or Access exception";
		return FILEOPENERR;
	}
	priority_queue<string, vector<string>, CustomCompare> longnames_minheap;
	string name = "";

	while (getline(fs, name))
	{
		if (longnames_minheap.size() <= MINHEAPSIZE)
		{
			longnames_minheap.push(name);
		}
		else
		{
			if (name.length() > longnames_minheap.top().length())
			{
				longnames_minheap.pop();
				longnames_minheap.push(name);
			}
		}
	}

	cout << endl << MINHEAPSIZE << " longest names in the list";
	cout << endl;
	while (longnames_minheap.size())
	{
		cout << longnames_minheap.top() << endl;
		longnames_minheap.pop();
	}

	fs.close();
	getchar();
	return 0;

}
