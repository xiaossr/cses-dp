#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, X;
vector<int> child;

int main()
{
    cin >> N >> X;

    child.resize(N);
    for (int i = 0; i < N; i++)
        cin >> child[i];
    sort(child.begin(), child.end());

    int l = 0, r = N - 1, ans = 0;
    while (l <= r)
    {
        if (l == r)
        {
            ans++;
            l++, r--;
        }
        else if (child[l] + child[r] > X)
            ans++, r--;
        else ans++, l++, r--;
    }

    cout << ans << "\n";

    return 0;
}
