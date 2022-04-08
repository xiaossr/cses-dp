#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int N, K;
vector<int> x;

bool ok(ll lim)
{
    int ck = 1, at = 0;
    ll csum = x[at];

    while (at < N - 1)
    {
        if (ck < K && csum + x[at + 1] > lim)
            at++, csum = x[at], ck++;
        else at++, csum += x[at];

        if (csum > lim) return 0;
    }

    return csum <= lim && at == N - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    x.resize(N);
    for (int i = 0; i < N; i++)
        cin >> x[i];

    ll l = 0, r = 2e14;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;

        if (ok(mid)) r = mid;
        else l = mid;
    }

    cout << r << "\n";

    return 0;
}
