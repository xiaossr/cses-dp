#include <iostream>
#include <vector>
using namespace std;

int N;
vector< vector<int> > par;
vector<int> ans;

void search(int at)
{
	if (par[at].empty()) return;

	for (const auto& k : par[at])
	{
		search(k);
		ans[at] += ans[k];
	}
	ans[at] += par[at].size();

	return;
}

int main()
{
	cin >> N;

	int a;
	par.resize(N + 3), ans.resize(N + 3, 0);
	for (int i = 2; i <= N; i++)
		cin >> a, par[a].push_back(i);

	search(1);

	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}
