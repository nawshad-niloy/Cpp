#include <iostream>
#include <cctype>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;


unordered_set<string> keywords = {"int", "float", "double", "char", "return", "if", "else", "while", "for"};


unordered_set<char> operators = {'+', '-', '*', '/', '=', '<', '>'};


string classifyToken(const string &token) 
{

    if (keywords.find(token) != keywords.end()) return "Keyword";

    if (token.size() == 1 && operators.find(token[0]) != operators.end()) return "Operator";

    if (isdigit(token[0])) 
    {

        for (char c : token)
        {
            if (!isdigit(c)) return "Unknown Token";
        }

        return "Number";
    }
    if (isalpha(token[0]) || token[0] == '_') 
    {
        for (char c : token) {
            if (!isalnum(c) && c != '_') return "Unknown Token";
        }
        return "Identifier";
    }
    return "Unknown Token";
}

int main() 
{
    string input;
    cout << "Enter a line of C++ code: ";
    getline(cin, input);

    vector<string> tokens;
    stringstream ss(input);
    string token;
    while (ss >> token) 
    {
        tokens.push_back(token);
    }

    cout << "\nLexical Analysis:" << endl;
    for (const string &t : tokens) 
    
    {
        cout << t << " -> " << classifyToken(t) << endl;
    }
    return 0;
}
