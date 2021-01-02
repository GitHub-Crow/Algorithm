/*
Q: 猜数字游戏，数字范围为[1 - n]，你可以询问该数字是否能被某个数整除，返回最少询问次数
A: 对于素数p，如果不询问p^k，则p^(k - 1)，p^k永远无法分辨。
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 1e3 + 5;
bool f[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	memset(f, 0, sizeof(f));
	for (int k = 2; k * k <= n; ++k) {
		if (!f[k]) {
			for (int i = k * k; i <= n; i += k) f[i] = true;
		}
	}
	vector<int> ans;
	for (int k = 2; k <= n; ++k) {
		if (!f[k]) {
			int u = k;
			while (u <= n) {
				ans.push_back(u);
				u *= k;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto & v : ans) cout << v << ' ';
	cout << endl;
	

    return 0;
}