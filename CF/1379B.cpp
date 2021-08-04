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
	LL T, l, r;
	LL m;
	cin >> T;
	while (T--) {
		cin >> l >> r >> m;
		for (LL a = l; a <= r; ++a) {
			LL m1 = m % a, m2 = m1 - a;
			if (m1 <= r - l && m >= a) {
				cout << a << ' ' << m1 + l << ' ' << l << endl;
				break ;
			}
			if (m2 >= l - r) {
				cout << a << ' ' << l << ' ' << l - m2 << endl;
				break ;
			}
		}
	}
	

    return 0;
}