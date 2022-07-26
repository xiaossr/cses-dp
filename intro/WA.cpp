#include <iostream>
using namespace std;

int N;

int main()
{
    cin >> N;

    while(N != 1)
    {
        cout << N << " ";
        if(N % 2) N = 3 * N + 1;
        else N /= 2;
    }
    cout << "1\n";

    return 0;
}