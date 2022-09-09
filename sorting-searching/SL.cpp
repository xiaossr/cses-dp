#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> p;

int main()
{
    cin >> N;
    // median is best - why?

    p.resize(N);
    for (int i = 0; i < N; i++)
        cin >> p[i];
    sort(p.begin(), p.end());

    int mid = p[N / 2];
    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans += abs(p[i] - mid);
    cout << ans << endl;

    return 0;
}
