#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> x, loc;

int main()
{
    cin >> N;

    x.resize(N), loc.resize(N + 3);
    for (int i = 0; i < N; i++)
        cin >> x[i], loc[x[i]] = i;

    int cur = -1, ans = 1;
    for (int i = 1; i <= N; i++)
    {
        if (loc[i] > cur) cur = loc[i];
        else ans++, cur = loc[i];
    }

    cout << ans << "\n";

    return 0;
}
