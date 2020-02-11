
#include "utils/genFunc.hpp"

#include <sstream>      //para hacer el split

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> splitSpaces(string str) {
    istringstream iss(str);
    vector<string> out(
        istream_iterator<string>{iss},
        istream_iterator<string>()
    );
    return out;
}

bool isNumber(string str) {
    int i = 0;
    bool out = true;
	for (i = 0; i < (int) str.length(); i++) {
        if (((int) str[i] - (int) '0') >= 10) out = false;
	}
    return out;
}

string autotab2(string str) {
    if ((int) str.length() < 8) str += "\t\t";
        else str += "\t";
    return str;
}

string autotab2mod(string str, int characters) {
    if ((int) str.length() < characters) str += "\t\t";
        else str += "\t";
    return str;
}
