#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int> a, b;
vector<bool> used;

int main()
{
    cin >> N >> M >> K;
    a.resize(N), b.resize(M), used.resize(M, 0);

    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int j = 0; j < M; j++)
        cin >> b[j];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    auto it = b.begin();
    for (int i = 0; i < N; i++)
    {
        //auto it = lower_bound(b.begin(), b.end(), a[i] - K);
        while (it != b.end() && (used[it - b.begin()] || *it < a[i] - K)) it++;
        if (it == b.end()) break;

        if (*it > a[i] + K) continue;
        ans++;
        used[it - b.begin()] = 1;
    }

    cout << ans << "\n";
    
    return 0;
}
