/*
Q: 给定数字n，求序列[1, 2, .. n] 中的最长子序列使得，子序列的乘积对n取模的结果为1。
A: gcd(prod % n, n) = gcd(prod, n) = gcd(1, n)
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
	int n;
	cin >> n;
	LL r = 1;
	vector<int> re;
	for (int k = 1; k < n; ++k) {
		if (__gcd(k, n) == 1) {
			re.push_back(k);
			r *= k;
			r %= n;
		}
	} 
	if (r == 1) {
		cout << re.size() << endl;
		for (auto & v : re) cout << v << ' ';
		cout << endl;
	}
	else {
		cout << re.size() - 1 << endl;
		for (auto & v : re) {
			if (v != r) cout << v << ' ';
		}
		cout << endl;
	}
	

    return 0;
}