#include <iostream>
using namespace std;

int N; long long a[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int t;
    long long psums = 0;
    a[0] = 1;
    for (int i = 0; i < N; i++)
        cin >> t, psums += t, a[(psums % N + N) % N]++;
	// a[i] records number of prefixes in which modulo N is i

    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans += a[i] * (a[i] - 1) / 2;
	// combinatorics

    cout << ans << "\n";

    return 0;
}
