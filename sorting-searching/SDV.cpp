#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, K;
vector<int> x;
map<int, int> distinct;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    x.resize(N);
    for (int i = 0; i < N; i++)
        cin >> x[i];

    int l = 0, r = 0; long long cnt = 0;
    while (r < N)
    {
        distinct[x[r]]++;

        while (distinct.size() > K) // if larger than K
        {
            distinct[x[l]]--;
            if (distinct[x[l]] == 0)
                distinct.erase(x[l]);
            l++;
        }

        cnt += r - l + 1LL; // subarrays with endpoint r
        r++;
    }

    cout << cnt << "\n";

    return 0;
}
