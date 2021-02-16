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

	int n, v;
	cin >> n;
	vector<LL> p(n + 1);
	for (int k = 0; k < n; ++k) {
		cin >> v;
		p[k + 1] = p[k] + v;
	}
	int left = 0, right = 1;
	LL ans = 0;
	unordered_set<LL> re = {0};
	while (left <= n) {
		while (right <= n && !re.count(p[right])) {
			re.insert(p[right++]);
		}
		ans += right - left - 1;
		re.erase(p[left]);
		++left;
	}
	cout << ans << endl;

    return 0;
}