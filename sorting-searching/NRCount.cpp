#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
using namespace std;

int N, bit[400005]; int ans[2][200005]; // bool changed to int
array<int, 3> ranges[200005];
set<int> uniq;
map<int, int> comp;

void upd(int ind, int val)
{
    while (ind <= 2 * N)
        bit[ind] += val, ind += ind & -ind;
    return;
}

int get(int ind)
{
    int ret = 0;
    while (ind > 0)
        ret += bit[ind], ind -= ind & -ind;
    //cout << ret << "\n";
    return ret;
}

int main()
{
    //ifstream fin("test_input.in");
    //ofstream fout("test.out");

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    // optimization: one test case kept TIMING OUT !!!

    cin >> N;

    int x, y;
    for (int i = 0; i < N; ++i) // change i++ to ++i for optimization (less copies)
    {
        cin >> x >> y;
        ranges[i] = { x, y, i };
        uniq.insert(x), uniq.insert(y);
    }

    sort(ranges, ranges + N, [](array<int, 3> A, array<int, 3> B) {
        return (A[0] == B[0] ? A[1] > B[1] : A[0] < B[0]);
        }); // sort by x

    int id = 0;
    for (const auto& x : uniq)
        comp[x] = ++id;

    for (int i = N - 1; i >= 0; --i)
    {
        y = comp[ranges[i][1]];
        id = ranges[i][2];

        ans[0][id] = get(y);
        upd(y, 1);
    }

    fill(bit, bit + 2 * N, 0); 

    for (int i = 0; i < N; ++i)
    {
        y = comp[ranges[i][1]];
        id = ranges[i][2];

        ans[1][id] = i - get(y - 1);
        upd(y, 1);
    }

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < N; ++j)
            cout << ans[i][j] << (j == N - 1 ? "\n" : " ");

    return 0;
}
