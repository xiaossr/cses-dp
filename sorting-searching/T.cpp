#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
vector<int> k;
set< pair<int, int> > maxes;

int main()
{
    cin >> N;

    k.resize(N);
    for (int i = 0; i < N; i++)
        cin >> k[i];
    // always want to place on smallest possible tower

    int cgp = 0;
    for (int i = 0; i < N; i++)
    {
        auto it = maxes.upper_bound({ k[i], cgp });
        if (it == maxes.end()) {
            maxes.insert({ k[i], cgp++ });
            continue;
        }
        int gp = it->second;
        maxes.erase(it);
        maxes.insert({ k[i], gp });
    }

    cout << cgp << "\n";

    return 0;
}
