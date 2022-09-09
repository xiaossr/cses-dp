#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
stack< pair<int, int> > s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int a;
    s.push({ 0, 0 });
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        while (s.top().first >= a) s.pop();

        cout << s.top().second  << " ";

        s.push({ a, i + 1 });
    }
    cout << "\n";

    return 0;
}
