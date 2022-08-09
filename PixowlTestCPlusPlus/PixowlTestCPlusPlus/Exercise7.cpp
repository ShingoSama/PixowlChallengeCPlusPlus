#include "funcPixowl.h"

//
//Exercise 7
//

void Exercise7()
{
	string text;
	string delimiter = " ";

	cout << "Ingrese un texto: ";
	cin.ignore();
	std::getline(std::cin, text);

	std::cout << text << "\n";
	vector<string> strings = split(text, delimiter);
	for (size_t i = 0; i < strings.size(); i++)
	{
		cout << strings[i] << "\n";
	}
}

vector<string> split(string s, string delimiter) 
{
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}