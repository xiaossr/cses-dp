#include <iostream>
using namespace std;

int N;
bool ok[200005];

int main()
{
	cin >> N;

	int a;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a;
		ok[a] = 1;
	}

	for(int i = 1; i <= N; i++)
		if (!ok[i])
		{
			cout << i << "\n";
			break;
		}

	return 0;
}
