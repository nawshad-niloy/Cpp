#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int charCount = 0, wordCount = 0, lineCount = 0, commentCount = 0;
    string line;
    bool inBlockComment = false;

    while (getline(file, line)) {
        lineCount++;
        bool inWord = false;
        bool inString = false;

        for (size_t i = 0; i < line.length(); i++) {
            if (line[i] == '"' && (i == 0 || line[i - 1] != '\\')) {
                inString = !inString;
            }

            if (!inBlockComment && !inString) {
                if (i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/') {
                    commentCount++;
                    break;
                }
                if (i + 1 < line.length() && line[i] == '/' && line[i + 1] == '*') {
                    inBlockComment = true;
                    commentCount++;
                }
            }

            if (!inBlockComment) {
                charCount++;
                if (isspace(line[i])) {
                    inWord = false;
                } else if (!inWord) {
                    inWord = true;
                    wordCount++;
                }
            }

            if (inBlockComment && i + 1 < line.length() && line[i] == '*' && line[i + 1] == '/') {
                inBlockComment = false;
                i++; 
            }
        }
    }
    
    file.close();
    cout << "Characters: " << charCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Lines: " << lineCount << endl;
    cout << "Comments: " << commentCount << endl;
    
    return 0;
}
