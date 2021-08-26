/*
Q: 给定数字n，对于所有正整数x，都有y=ceil(n/x)，打印出所有可能的y。
A: y <= n/x < y + 1，则x的区间长度为n/(y*y + y)。
first, 当区间长度大于1时必定存在正整数，此时的y一定是解，当y在[0, ceil(sqrt(n))]内时，满足上述要求；
second，对于 x>sqrt(n)，那么相应的y一定是小于sqrt(n)，都在第一种情况中。此时只需要讨论 x<sqrt(n)。

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
		int m = sqrt(n);
		vector<int> r;
		for (int k = 0; k <= m; ++k) r.push_back(k);
		for (int k = 1; k <= m; ++k) {
			int u = n / k;
			r.push_back(u);
		}
		sort(r.begin(), r.end());
		r.resize(unique(r.begin(), r.end()) - r.begin());
		cout << r.size() << endl;

		for (int & v : r) cout << v << ' ';
		cout << endl;
	}
	

    return 0;
}