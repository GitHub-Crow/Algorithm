/*
Q: 给n个连续瓷砖涂色，要求对于相隔的瓷砖数为k的瓷砖颜色必须一致，其中k是n的因子，
问最多能图多少种颜色？
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL


const int N = 1e6 + 5;
bool v[N];
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	LL n;
	cin >> n;
	LL m = sqrt(n), ans = 0;
	memset(v, 0, sizeof(v));
	for (int k = 2; k <= m; ++k) {
		if (v[k]) continue ;
		if (n % k == 0) {
			LL o = n;
			while (o / k) {
				if (o % k) break ;
				o /= k;
			}
			if (o == 1) ans = k;
			else ans = 1;
			break ;
		}
		int u = k;
		while (u <= m) {
			v[u] = true;
			u += k;
		}
	}
	if (ans == 0) ans = n;
	cout << ans << endl;
	

    return 0;
}