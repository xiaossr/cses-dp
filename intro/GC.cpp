#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int N;

void gc()
{
	for (int i = 0; i < (1 << N); i++)
	{
		int val = (i ^ (i >> 1)); // decimal i to decimal gray code
		bitset<32> r(val); // to binary

		cout << r.to_string().substr(32 - N) << "\n";
	}
}

int main()
{
	cin >> N;

	gc();

	return 0;
}
