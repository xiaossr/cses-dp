#include <iostream>
using namespace std;

long long N, a, csum = 0, ans = -1e9 - 7;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a;

        csum += a;
        ans = max(ans, max(a, csum));
        if (csum < 0) csum = 0; // if sum ever dips under 0 we can find a better one ! you deserve better queen
    }

    cout << ans << "\n";
    
    return 0;
}
