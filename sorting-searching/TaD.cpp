#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector< pair<int, int> > task;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    cin >> N;

    task.resize(N);
    for (int i = 0; i < N; i++)
        cin >> task[i].first >> task[i].second;
    sort(task.begin(), task.end()); // there is an interesting proof for this Plz draw it out

    long long ct = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        ct += task[i].first;
        ans += task[i].second - ct;
    }

    cout << ans << "\n";

    return 0;
}
