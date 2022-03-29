#include <iostream>
#include <set>
using namespace std;

int N;
set<int> s;

int main()
{
    int a;

    cin >> N;
    while (N--)
        cin >> a, s.insert(a);

    cout << s.size() << "\n";
    
    return 0;
}
