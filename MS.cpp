#include <iostream>
using namespace std;

int N, x[103], k = 0, s = 0;
bool ok[1000005];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> x[i], s += x[i];

	ok[0] = 1;
	for (int i = 0; i < N; i++)
		for (int num = s; num >= 1; num--)
			if (num - x[i] >= 0 && ok[num - x[i]])
				k += !ok[num], ok[num] = 1;

	cout << k << "\n";
	for (int num = 1; num <= s; num++)
		if (ok[num])
			cout << num << " ";
	cout << "\n";

	return 0;
}