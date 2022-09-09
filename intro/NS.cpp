#include <iostream>
using namespace std;
typedef long long ll;

int T; ll y, x;

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> y >> x;

		ll insec = max(y, x);

		if (insec % 2)
			cout << insec * insec - (y - 1) - (insec - x) << "\n";
		else cout << insec * insec - (x - 1) - (insec - y) << "\n";
	}

	return 0;
}
