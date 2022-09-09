#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
multiset<int> s;

int main()
{
    cin >> N >> M;

    int a;
    for (int i = 0; i < N; i++)
        cin >> a, s.insert(a);
    
    for (int i = 0; i < M; i++)
    {
        cin >> a;
        if (s.empty()) {
            cout << "-1\n";
            continue;
        }

        auto it = s.upper_bound(a);
        if (it == s.begin())
        {
            cout << "-1\n";
            continue;
        }

        --it;
        cout << *it << "\n";
        s.erase(it);
    }


    return 0;
}
