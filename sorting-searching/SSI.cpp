#include <iostream>
#include <vector>
using namespace std;

int N, X;
vector<int> k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;
    
    k.resize(N + 3, -1);
    for (int i = 0; i < N; i++)
        cin >> k[i];

    int l = 0, r = 0, sum = k[0], ans = (k[0] == X); // inclusive start and end
    while (r < N)
    {
        if (sum <= X) r++, sum += k[r]; // case 1 sum too small
        else if (sum > X && l < r) sum -= k[l], l++; // case 2 numbers can still be subtracted
        else if (sum > X) r++, sum += k[r]; // case 3 no numbers can be subtracted (add new number)

        if (r < N && sum == X) ans++, r++, sum += k[r];
    }

    cout << ans << "\n";

    return 0;
}
