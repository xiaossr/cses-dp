#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, K;
vector<int> x;
multiset<int> s1, s2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    x.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
        if (i < K) s1.insert(x[i]);
    }

    while (s1.size() > (K + 1) / 2)
        s2.insert(*s1.rbegin()), s1.erase(prev(s1.end()));
    cout << *s1.rbegin();

    int at = K, median = *s1.rbegin();
    while (at < N)
    {
        if (x[at] <= median) s1.insert(x[at]);
        else s2.insert(x[at]);

        if (x[at - K] <= median) s1.erase(s1.find(x[at - K]));
        else s2.erase(s2.find(x[at - K]));

        while (s1.size() > (K + 1) / 2)
            s2.insert(*s1.rbegin()), s1.erase(prev(s1.end()));
        while (s2.size() > K / 2)
            s1.insert(*s2.begin()), s2.erase(s2.begin());

        median = *s1.rbegin();
        cout << " " << median;
        at++;
    }

    cout << "\n";

    return 0;
}
