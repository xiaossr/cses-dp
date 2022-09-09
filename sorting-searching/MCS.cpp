#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> x;

int main()
{
    cin >> N;

    x.resize(N);
    for (int i = 0; i < N; i++)
        cin >> x[i];
    sort(x.begin(), x.end());

    long long ans = 1;
    for (int i = 0; i < N; i++)
    {
        if (ans < x[i]) break;
        ans += x[i]; // everything from 1-ans can add a x[i], so all possible
    }
    cout << ans << "\n";

    return 0;
}
