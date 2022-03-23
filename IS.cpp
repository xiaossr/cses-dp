#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, x;
vector<int> dp;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		auto it = lower_bound(dp.begin(), dp.end(), x);
		if (it == dp.end())
			dp.push_back(x);
		else *it = x;
	}

	cout << dp.size() << endl;

	return 0;
}