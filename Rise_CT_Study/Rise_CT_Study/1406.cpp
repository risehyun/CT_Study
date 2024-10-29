#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	string inputText = "";
	int M = 0;

	cin >> inputText >> M;

	list<char> editor(inputText.begin(), inputText.end());
	auto cursor = editor.end();

	while (M--)
	{
		string command;
		cin >> command;

		if (command == "L")
		{
			if (cursor != editor.begin()) cursor--;
		}
		else if (command == "D")
		{
			if (cursor != editor.end()) cursor++;
		}
		else if (command == "B") 
		{
			if (cursor != editor.begin()) cursor = editor.erase(--cursor);
		}
		else if (command == "P") 
		{
			char newChar;
			cin >> newChar;
			editor.insert(cursor, newChar);
		}
	}

	for (char ch : editor) 
	{
		cout << ch;
	}

	return 0;
}