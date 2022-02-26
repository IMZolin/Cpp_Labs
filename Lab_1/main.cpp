#include <iostream>
#include <string>
#include<fstream>
#include <cstdlib>
using namespace std;

void CenterString(string str, int required_len)
{
	int len = str.size();
	if (required_len)
	{

	}
}

void Read(string filename, int required_len)
{
	ifstream fin;
	fin.open(filename);
	int cur_len = 0;
	//std::istream_iterator<string> eos;
	/*std::istream_iterator<string> iit(std::cin);*/
	if (!fin)
	{
		cout << "Uh oh, SomeText.txt could not be opened for writing or reading!\n" << endl;
		exit(1);
	}
	else {
		cout << "Success!\n" << endl;
		string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cur_len = str.size();
			if (cur_len > required_len)
			{
				cout << "+\n" << endl;
			}
			else {
				cout << "-\n" << endl;
			}
			cout << str << endl;
		}
	}

	fin.close();
}
int main()
{
	setlocale(LC_ALL, "rus");
	int length = 13;
	string filename = "input.txt";
	Read(filename, length);
	return 0;
}