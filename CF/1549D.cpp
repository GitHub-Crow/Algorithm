/*
Q: 给定数组，求最长的子数组使得子数组能够满足所有元素Ai st. Ai%m=n，其中m>1
A: 子数组差值的GCD大于1
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
LL d[N];
LL lidx[4*N], val[4*N], ridx[4*N];
int n;

void build(int iL, int iR, int idx) {
	lidx[idx] = iL;
	ridx[idx] = iR;
	if (iL == iR) {
		val[idx] = d[iL];
		return ;
	}
	int iM = (iL + iR) / 2;
	build(iL, iM, idx * 2);
	build(iM + 1, iR, idx * 2 + 1);
	val[idx] = __gcd(val[2 * idx], val[2 * idx + 1]);
}

LL query(int iL, int iR, int idx) {
	if (lidx[idx] == iL and ridx[idx] == iR) return val[idx];
	int iM = (lidx[idx] + ridx[idx]) / 2;
	if (iR <= iM) return query(iL, iR, idx * 2);
	else if (iL > iM) return query(iL, iR, idx * 2 + 1);
	else return __gcd(query(iL, iM, idx * 2), query(iM + 1, iR, idx * 2 + 1));
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int k = 0; k < n; ++k) cin >> d[k];
		if (n < 2) {
			cout << 1 << endl;
			continue ;
		}
		for (int k = n - 1; k > 0; --k) d[k] = abs(d[k] - d[k - 1]);
		build(1, n - 1, 1);
		int ans = 1;
		for (int i = 1, j = 1; i < n and j < n; ++i) {
			while (j < i) ++j;
			while (j < n and query(i, j, 1) > 1) {
				ans = max(ans, j - i + 2);
				++j;
			}
		}
		cout << ans << endl;
	}

    return 0;
}