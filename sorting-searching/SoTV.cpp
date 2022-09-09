#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, X;
map<int, vector<int> > val;

int main()
{
    cin >> N >> X;

    int a;
    for (int i = 0; i < N; i++)
        cin >> a, val[a].push_back(i + 1);

    for (const auto& k : val)
    {
        if (k.first * 2 == X)
        {
            if (k.second.size() >= 2)
            {
                cout << k.second[0] << " " << k.second[1] << "\n";
                return 0;
            }
        }
        else
        {
            if (val.count(X - k.first))
            {
                cout << k.second[0] << " " << val[X - k.first][0] << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
