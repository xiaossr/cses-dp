#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
using namespace std;

int N, room = 0;
vector< array<int, 3> > v;
vector<int> ans;
set< pair<int, int> > bounds;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    cin >> N;

    v.resize(N), ans.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i][0] >> v[i][1], v[i][2] = i;
    sort(v.begin(), v.end(), [](array<int, 3> a, array<int, 3> b) {
            return (a[1] == b[1] ? a[0] < b[0] : a[1] < b[1]);
        });

    bounds.insert({ 1e9 + 3, 0 });
    
    for (int i = 0; i < N; ++i)
    {
        auto it = bounds.lower_bound({ v[i][0], 0 });
        if (it == bounds.begin())
            bounds.insert({ v[i][1], ++room }), ans[v[i][2]] = room;
        else
        {
            --it;
            bounds.insert({ v[i][1], it->second });
            ans[v[i][2]] = it->second;
            bounds.erase(it);
        }
    }

    cout << room << "\n";
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
