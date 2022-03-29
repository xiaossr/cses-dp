#include <iostream>
#include <map>
using namespace std;

int N;
map<int, int> inc;

int main()
{
    cin >> N;

    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        inc[a]++, inc[b]--;
    }

    int ans = 0, cur = 0;
    for (const auto& i : inc)
        cur += i.second, ans = max(ans, cur);

    cout << ans << "\n";

    return 0;
}
