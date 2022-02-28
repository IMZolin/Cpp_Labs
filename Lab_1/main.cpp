#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	
	int length=0;
	cout << "Required length = ";
		cin>>  length;
	string filename = "input.txt";
	cout << "\nFile name for text = ";
	cin>> filename;
	FileStructure file = FileStructure(length, filename);
	return 0;
}