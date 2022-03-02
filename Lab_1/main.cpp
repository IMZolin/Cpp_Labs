#include <vector>
using namespace std;
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <ostream>
//Output the text aligned in the center using whitespace
void spacer(string& buff, int cur_len, int width) {
	int diff;	
	diff = (width - cur_len) / 2;
	string whitespace(diff, ' ');
	cout << whitespace + buff + whitespace + '\n';
	buff.clear();
}
//Print words
void PrintWords(string words)
{
	for (auto& w : words) {
		cout << w << endl;
	}
}
//Read text in input.txt. Params:filename, required length. Return result in array(vector) of words
vector<string> ReadFile(string filename)
{
	ifstream file;
	vector<string>words;
	file.open(filename);
	cout<< "Result is ";
	if (!file.is_open())
	{
		cout << "Uh oh.File wasn't opened. Check if the name of file "<< filename <<" correct.\n" << endl;
		exit(1);
	}
	else {
		cout << "Success!\n" << endl;
		string buf;
		
		while (!file.eof())
		{	
			getline(file, buf);
			istringstream stream(buf);
			copy(istream_iterator<string>(stream),
				istream_iterator<string>(),
				back_inserter (words));
		}
	}
	file.close();
	return words;
}
//Read text in input.txt. Params:filename, required length. Return result in array(vector) of words
void Formatter(vector<string>& words, int width)
{
	int k = 0;
	string buf;
	int cur_len = 0;
	for (auto& word : words)
	{
		if (cur_len + word.length() + 1 <= width) {
			cur_len += (int)word.length() + 1;
			buf += word + " ";
			continue;
		}
		if (cur_len) {
			spacer(buf, cur_len, width);
		}
		if (word.length() > width) {
			for (auto& letter : word) {
				k++;
				buf += letter;
				if (k == width) {
					k = 0;
					cout << buf + '\n';
					buf.clear();
				}
			}
			buf += " ";
			cur_len = (int)buf.length();
			k = 0;
			continue;
		}
		//
		if (word.length() <= width) {
			buf += word + " ";
			cur_len = (int)buf.length();
		}
	}
	spacer(buf, cur_len, width);
}
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	std::cout << "There are arguments:\n";
	string filename = argv[1];
	int width = atoi(argv[2]);//convert str to int

	cout << "Required length = " << width;
	cout << "\nFile name for text = "<<filename;
	cout << "\n";
	vector<string> text = ReadFile(filename);
	Formatter(text, width);
	return 0;
}