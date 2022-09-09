#include <iostream>
#include <set>
using namespace std;

int N;
set<int> josephus;

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        josephus.insert(i);

    auto it = josephus.begin();
    while (josephus.size() > 1)
    {
        ++it;
        if (it == josephus.end()) it = josephus.begin();
        cout << *it << " ";
        auto it2 = it;
        ++it2;
        josephus.erase(it);
        if (it2 == josephus.end()) it2 = josephus.begin();
        it = it2;
    }
    cout << *josephus.begin() << "\n";

    return 0;
}
