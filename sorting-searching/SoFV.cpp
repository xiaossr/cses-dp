#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, X, num[1003], ans[4];
map<int, vector< pair<int,int> > > pres;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;

    int a;
    for (int i = 0; i < N; i++)
        cin >> a, num[i] = a;

    ans[0] = -1;
    for(int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            int cnt = X - num[i] - num[j];
            if (pres.count(cnt))
            {
                int th4 = -1;
                for (int k = 0; k < pres[cnt].size(); k++)
                {
                    if (pres[cnt][k].first == i || pres[cnt][k].second == i ||
                        pres[cnt][k].first == j || pres[cnt][k].second == j) continue;
                    th4 = k;
                    break;
                }

                if (th4 != -1)
                    ans[0] = i + 1, ans[1] = j + 1, 
                    ans[2] = pres[cnt][th4].first + 1, 
                    ans[3] = pres[cnt][th4].second + 1,
                    i = N, j = N;
            }
            pres[num[i] + num[j]].push_back({ i, j });
        }

    if (ans[0] == -1) cout << "IMPOSSIBLE\n";
    else cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";

    return 0;
}
