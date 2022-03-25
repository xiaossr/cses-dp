#include <iostream>
#include <string>
using namespace std;

string s;
char pr;
int rep = 1, ans = 0;

int main()
{
	cin >> s;
	
	pr = s[0];
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == pr) rep++;
		else ans = max(ans, rep), rep = 1, pr = s[i];
	}

	cout << max(ans, rep) << "\n";

	return 0;
}
