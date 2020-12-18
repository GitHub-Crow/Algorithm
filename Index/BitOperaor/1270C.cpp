/*
Q: 给定数组，增加不超过3个数，使得数组的和等于数组异或操作后的数值的两倍
A: 考虑(X ^ X == 0)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		LL u = 0, s = 0, v;
		for (int i = 0; i < n; ++i) {
			cin >> v;
			u ^= v;
			s += v;
		}
		cout << 2 << endl;
		cout << u << ' ' << u + s << endl;

	}
	

    return 0;
}