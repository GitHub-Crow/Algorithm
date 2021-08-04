#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, n, k;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		if (n <= k) cout << k - n << endl;
		else {
			if ((n & 1) ^ (k & 1)) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	

    return 0;
}