#include "Header.h"

void CenterString(string str, int required_len)
{
	int len = str.size();
	if (required_len)
	{

	}
}

FileStructure::FileStructure(int argc, char** argv)
{
	filename = argv[1];
	width = atoi(argv[2]);
}

string operator * (string a, unsigned int b) {
	string output = "";
	while (b--) {
		output += a;
	}
	return output;
}

void FileStructure::spacer(string& buff, int current_length, ofstream& output) {
	int diff;
	diff = (width - current_length) / 2;
	string space = " ";
	output << (space * diff) + buff + (space * diff) + '\n';
	buff.clear();
}

void FileStructure::ReadFile()
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
			/*if (cur_len > required_len)
			{
				cout << "+\n" << endl;
			}
			else {
				cout << "-\n" << endl;
			}*/
			cout << str << endl;
		}
	}

	fin.close();
}

void FileStructure::PrintWords()
{
	for (auto& w : words) {
		cout << w << endl;
	}
}