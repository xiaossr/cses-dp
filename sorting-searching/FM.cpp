#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, T;
vector<int> k;

bool ok(long long lim)
{
    long long create = 0;
    for (int i = 0; i < N; i++)
    {
        create += lim / k[i];
        if (create >= T) return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    cin >> N >> T;

    k.resize(N);
    for (int i = 0; i < N; i++)
        cin >> k[i];

    long long l = -1, r = LLONG_MAX; // l is OUT OF BOUNDS
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;

        if (ok(mid)) r = mid;
        else l = mid;
    }

    cout << r << "\n";

    return 0;
}
