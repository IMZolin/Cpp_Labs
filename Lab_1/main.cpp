#include <vector>
using namespace std;
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <ostream>

void spacer(string& buff, int cur_len, int width) {
	int diff;	
	diff = (width - cur_len) / 2;
	string whitespace(diff, ' ');
	cout << whitespace + buff + whitespace + '\n';
	buff.clear();
}
void PrintWords(string words)
{
	for (auto& w : words) {
		cout << w << endl;
	}
}

vector<string> ReadFile(string filename, int width)
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

void Formatter(vector<string>& words, int width)
{
	int k = 0;
	string buf;
	int cur_len = 0;
	for (auto& word : words)
	{
		int width_copy = width;
		if (cur_len + word.length() + 1 < width_copy) {
			cur_len += (int)word.length() + 1;
			buf += (word + " ");
			continue;
		}
		else if (word.length() < width_copy) {
			spacer(buf, cur_len, width_copy);
			cur_len = 0;
		}
		if (word.length() > width) {
			for (auto& letter : word) {
				cout << letter;
				k++;
				if (k == width) {
					k = 0;
					cout << '\n';
					//break;
				}
			
			}
			cout << " ";
			width_copy -= k;
		}
		if (word.length() == width) {
			cout << word;
			cout << '\n';
		}
		if (!width_copy)
			cout << '\n';
	}
}
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	std::cout << "There are arguments:\n";
	string filename = argv[1];
	int width = atoi(argv[2]);

	cout << "Required length = " << width;
	cout << "\nFile name for text = "<<filename;
	cout << "\n";
	vector<string> text = ReadFile(filename, width);
	Formatter(text, width);
	return 0;
}