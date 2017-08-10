#include <stdio.h>
#include "codelib.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
const char * TEST_DATA_DIR = "data/TEST/"; 

// void split(const char * str, const char * c, std::vector<std::string>& str_seti, bool any = true);
// std::string trim(const char * str, const char * c, bool any = true);

string testTrim(ifstream& in, ifstream& ans) 
{
	string str; in >> str;
	string c; in >> c;
	bool b; in >> b;
	string answer ; ans >> answer;
	string result ; result = trim(str.c_str(), c.c_str(), b);
	if (result != answer) {
		std::stringstream s;
		s << "trim (" << str << ", " << c << ", any=" << b << ") = ";
		s << result << endl;
		s << "answer : ";
		s << answer << endl;
		s << "using function: match()";
		return s.str();
	}
	return "";
}

string testSplit(ifstream& in, ifstream& ans) 
{
	string str; in >> str;
	string c; in >> c;
	bool b; in >> b;
	vector<string> answer ; readVector(ans , answer);
	vector<string> result ; split(str.c_str(), c.c_str(), result, b);
	if (result != answer) {
		std::stringstream s;
		s << "split (" << str << ", " << c << ", any=" << b << ") = ";
		streamVector(s, result);
		s <<  "\n";
		s << "answer : ";
		streamVector(s, answer);
		return s.str();
	}
	return "";
}

string testFind(ifstream& in, ifstream& ans) 
{
	string str; in >> str;
	string c; in >> c;
	bool b; in >> b;
	int answer ; ans >> answer;
	int result = find(str.c_str(), c.c_str(), b);
	if (result != answer) {
		std::stringstream s;
		s << "find (" << str << ", " << c << ", any=" << b << ") = " << result << endl;
		s << "answer : " << answer; 
		return s.str();
	}
	return "";
}

string testGetFileName(ifstream& in, ifstream& ans)
{
	string path; in >> path;
	string ans_file; ans >> ans_file;
	string result = getFileName(path.c_str());
	if (result != ans_file) {
		std::stringstream s;
		s << "getFileName (" + path + ") = " + result  << endl;
		s << "answer : " + ans_file;
		return s.str();
	}
	return "";
}

string testRemoveFileExtentionName(ifstream& in, ifstream& ans)
{
	string file; in >> file;
	string ans_file; ans >> ans_file;
	string result = removeFileExtentionName(file.c_str());
	if (result != ans_file) {
		std::stringstream s;
		s << "removeFileExtentionName (" + file + ") = " + result << endl;
		s << "answer : " + ans_file;
		return s.str();
	}
	return "";
}

int main()
{
	Test test(TEST_DATA_DIR);
	test.add(testGetFileName, "getFileName");
	test.add(testRemoveFileExtentionName, "removeFileExtentionName");
	test.add(testFind, "find");
	test.add(testSplit, "split");
	test.add(testTrim, "trim");
	test.run();
	return 0;
}

