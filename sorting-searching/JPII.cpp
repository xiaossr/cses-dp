#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> a;

int main()
{
    int N, K;
    cin >> N >> K;

    int p = K % N;
    for (int i = 1; i <= N; i++)
        a.insert(i);

    while (!a.empty())
    {
        auto it = a.find_by_order(p);
        a.erase(it);

        if (a.size())
            p = (p + K) % a.size();
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}
