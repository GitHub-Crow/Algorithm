#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int a[105];

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
		set<int> re;
		for (int k = 0; k < n; ++k) {
			cin >> a[k];
			re.insert(a[k]);
		}
		if (re.size() > m) cout << "-1\n";
		else {
			vector<int> w;
			vector<int> r;
			for (auto it = re.begin(); it != re.end(); ++it) w.push_back(*it);
			while (w.size() < m) w.push_back(w.back());
			for (int i = 0, j = 0; i < n; ++i) {
				while (a[i] != w[j]) {
					r.push_back(w[j++]);
					if (j >= m) j = 0;
				}
				r.push_back(w[j++]);
				if (j >= m) j = 0;
			}
			cout << r.size() << endl;
			for (auto & v : r) cout << v << ' ';
			cout << endl;
		}
	}
	

    return 0;
}