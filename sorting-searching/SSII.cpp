#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int N, X;
vector<int> k;
map<long long, int> sum;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> N >> X;
    
    k.resize(N, -1);
    for (int i = 0; i < N; i++)
        cin >> k[i];
 
    long long psum = 0;
    long long ans = 0;
 
    sum[0] = 1;
 
    for (auto x : k)
        psum += x, ans += sum[psum - X], sum[psum]++; // very interesting
 
    cout << ans << "\n";
 
 
    return 0;
}
