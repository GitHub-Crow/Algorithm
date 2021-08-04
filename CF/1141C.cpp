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
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	vector<bool> v(n);
	for (int i = 1; i < n; ++i) cin >> q[i];
	LL s = 0;
	for (int i = 1; i < n; ++i) {
		p[i] = p[i - 1] + q[i];
		s += p[i];
	}
	LL tot = 1ll * (1 + n) * n / 2;
	p[0] = (tot - s) / n;
	for (int i = 1; i < n; ++i) p[i] += p[0];

	bool isAc = true;
	for (auto & e : p) {
		if (e <= 0 or e > n or v[e - 1]) isAc = false;
		else v[e - 1] = true;
	}
	if (!isAc) cout << "-1\n";
	else {
		for (auto & v : p) cout << v << ' ';
		cout << endl;
	}
	

    return 0;
}