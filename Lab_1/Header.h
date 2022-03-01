#pragma once
#include <vector>
using namespace std;
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <ostream>
#define ERROR_OPENING_FILE 1
#define EXIT_SUCCESS 0


class FileStructure {
private:
    string filename;
    int width;
    vector <string> words;
    void spacer(string& buff, int current_length, ofstream& output);

public:
    FileStructure(int argc, char** argv);

    void ReadFile();
    void PrintWords();
    int text_align_center(string output_filename);

    string get_name() { return filename; }
    int get_width() const { return width; }
    vector <string> get_words() { return words; }
};