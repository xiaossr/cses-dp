#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int N, X;
set<int> tl;
multiset<int> dists;

int main()
{
    ifstream fin("test_input.in"); // testing
    ofstream fout("test.out");

    cin >> X >> N;

    tl.insert(0), tl.insert(X), dists.insert(X);
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        
        auto it = tl.lower_bound(a), it2 = it; // prev(it) and next(it) too slow
        --it;

        dists.erase(dists.lower_bound(*it2 - *it));
        dists.insert(a - *it), dists.insert(*it2 - a);
        tl.insert(a);

        cout << (i ? " " : "")  << *dists.rbegin();
    }
    cout << "\n";

    return 0;
}
