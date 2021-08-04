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
	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		int d = abs(n - m);
		int x = 0, s = 0;
		while (true) {
			s += x;
			if (s >= d && ((s & 1) == (d & 1))) break ;
			++x;
		}
		cout << x << endl;
	}
	

    return 0;
}