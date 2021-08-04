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
	int n, m;
	cin >> n >> m;
	string op;
	int e = 0;
	int out0 = 0, out1 = -1;
	for (int k = 0; k < n; ++k) {
		cin >> op >> e;
		if (op == "AND") out0 &= e, out1 &= e;
		else if (op == "OR") out0 |= e, out1 |= e;
		else out0 ^= e, out1 ^= e;
	}
	int ans = 0;
	for (int k = 0; k < 30; ++k) {
		if ((out0 >> k & 1) or ((1 << k) < m and (out1 >> k & 1))) ans |= (1 << k);
	}
	cout << ans << endl;
    return 0;
}