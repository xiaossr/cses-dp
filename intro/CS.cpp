#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string s;
map<char, int> m;

int fac(int num)
{
	int ret = 1;
	for (int i = 1; i <= num; i++)
		ret *= i;
	return ret;
}

int main()
{
	cin >> s;
	vector<char> v(s.begin(), s.end());
	for (auto& c : s)
		m[c]++;

	int k = fac(s.length());
	for (auto& c : m)
		k /= fac(c.second);
	cout << k << "\n";

	sort(v.begin(), v.end());
	do
	{
		s = string(v.begin(), v.end());
		cout << s << "\n";
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}
