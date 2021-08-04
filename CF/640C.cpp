#include <iostream>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int  n, k, T;
	cin >> T;

	while (T--) {
		cin >> n >> k;
		cout << k + (k - 1) / (n - 1) << endl;
	}
    return 0;
}