/*
Q: 给定数组，删除最少元素使得数组不能分成两个和相等的子数组。
A: 背包DP判断是否满足条件。删除一个“奇数”即可使得数组不可分割成两个相等的部分。
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
bool f[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	memset(f, 0, sizeof(f));
	f[0] = true;
	int tot = 0;
	for (int & v : arr) {
		tot += v;
		for (int k = N - 1; k >= 0; --k) {
			if (f[k]) f[k + v] = true;
		}
	}
	if ((tot & 1) or !f[tot >> 1]) cout << "0\n";
	else {
		bool ret = false;
		int ans = 0;
		for (int k = 0; !ret; ++k) {
			for (int v = 0; v < n; ++v) {
				if (arr[v] >> k & 1) {
					ret = true;
					ans = v;
					break ;
				}
			}
		}
		cout << '1' << endl << ans + 1 << endl;
	}
	

    return 0;
}