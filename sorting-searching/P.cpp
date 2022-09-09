#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<int> k;
map<int, int> pr;

int main()
{
    cin >> N;

    k.resize(N);
    for (int i = 0; i < N; i++)
        cin >> k[i];

    int ans = 1, lrp = -1; 
    for (int i = 0; i < N; i++)
    {
        if (pr.count(k[i])) lrp = max(lrp, pr[k[i]]);

        ans = max(ans, i - lrp);
        pr[k[i]] = i;
    }

    cout << ans << "\n";

    return 0;
}
