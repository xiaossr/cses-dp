#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector< pair<int, int> > v;

int main()
{
    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].second >> v[i].first;

    sort(v.begin(), v.end());

    int ce = 0, ans = 0;
    for (int i = 0; i < N; i++)
        if (v[i].second >= ce) ans++, ce = v[i].first;
    cout << ans << "\n";

    return 0;
}
