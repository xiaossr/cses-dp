#include <iostream>
using namespace std;

int N;
long long t, mx, sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> t, mx = max(mx, t), sum += t; // prove this

    cout << max(sum, 2 * mx) << "\n";

    return 0;
}
