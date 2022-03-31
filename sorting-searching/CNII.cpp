#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> x, loc;

int main()
{
    cin >> N >> M;

    x.resize(N), loc.resize(N + 3);
    for (int i = 0; i < N; i++)
        cin >> x[i], loc[x[i]] = i;

    int cur = -1, ans = 1;
    for (int i = 1; i <= N; i++)
    {
        if (loc[i] > cur) cur = loc[i];
        else ans++, cur = loc[i];
    }

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b; a--, b--;
      
        // how to simplify this?
        if (x[a] > 1 && loc[x[a]] > loc[x[a] - 1] && loc[x[b]] <= loc[x[a] - 1]) ans++;
        if (x[a] > 1 && loc[x[a]] < loc[x[a] - 1] && loc[x[b]] >= loc[x[a] - 1]) ans--;
        if (x[a] < N && loc[x[a]] < loc[x[a] + 1] && loc[x[b]] >= loc[x[a] + 1]) ans++;
        if (x[a] < N && loc[x[a]] > loc[x[a] + 1] && loc[x[b]] <= loc[x[a] + 1]) ans--;
        
        if (x[b] > 1 && loc[x[b]] > loc[x[b] - 1] && loc[x[a]] <= loc[x[b] - 1]) ans++;
        if (x[b] > 1 && loc[x[b]] < loc[x[b] - 1] && loc[x[a]] >= loc[x[b] - 1]) ans--;
        if (x[b] < N && loc[x[b]] < loc[x[b] + 1] && loc[x[a]] >= loc[x[b] + 1]) ans++;
        if (x[b] < N && loc[x[b]] > loc[x[b] + 1] && loc[x[a]] <= loc[x[b] + 1]) ans--;

        if (x[b] == x[a] - 1 && loc[x[b]] < loc[x[a]]) ans--;
        else if (x[b] == x[a] - 1) ans++;
        
        if (x[b] == x[a] + 1 && loc[x[b]] > loc[x[a]]) ans--;
        else if (x[b] == x[a] + 1) ans++;

        cout << ans << "\n";

        swap(loc[x[a]], loc[x[b]]);
        swap(x[a], x[b]);
    }

    return 0;
}
