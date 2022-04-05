#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, X, num[5005];
map<int, vector<int> > pres;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;

    int a;
    for (int i = 0; i < N; i++)
        cin >> a, num[i] = a, pres[a].push_back(i);

    bool flag = 0;
    int b = -1, c;
    for(int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            int g = X - num[i] - num[j];
            if (pres.count(g) && pres[g].size() - (num[i] == g) - (num[j] == g))
            {
                a = i, b = j;
                for (int k = 0; k < pres[g].size(); k++)
                    if (pres[g][k] != i && pres[g][k] != j)
                        c = pres[g][k];
                i = N, j = N;
            }
        }

    if (b == -1)
        cout << "IMPOSSIBLE\n";
    else cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";

    return 0;
}
