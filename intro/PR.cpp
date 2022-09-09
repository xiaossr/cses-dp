#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

char odd = '.';
string s;
map<char, int> enc;

int main()
{
	cin >> s;
	for (const auto& c : s)
		enc[c]++;

	s.clear();
	for (const auto& c : enc)
	{
		if (odd != '.' && c.second % 2)
		{
			cout << "NO SOLUTION\n";
			return 0;
		}
		else if (c.second % 2)
			odd = c.first;
		s += string(c.second / 2, c.first);
	}

	cout << s;
	if (odd != '.') cout << odd;
	reverse(s.begin(), s.end());
	cout << s << "\n";
	
	return 0;
}
