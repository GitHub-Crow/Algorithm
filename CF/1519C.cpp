#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
int u[N], s[N];
vector<LL> ps[N];
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
 		for (int i = 0; i < n; ++i) cin >> u[i];
 		for (int i = 0; i < n; ++i) cin >> s[i];
 		for (int i = 1; i <= n; ++i) ps[i].clear();

 		for (int i = 0; i < n; ++i) ps[u[i]].push_back(s[i]);
 		for (int i = 1; i <= n; ++i) {
 			sort(ps[i].begin(), ps[i].end(), greater<LL>());
 			for (int k = 1; k < ps[i].size(); ++k) {
 				ps[i][k] += ps[i][k - 1];
 			}
 		}
 		vector<int> res;
 		for (int i = 1; i <= n; ++i) res.push_back(i);
 		for (int k = 1; k <= n; ++k) {
 			LL tot = 0;
 			vector<int> keep;
 			for (auto & v : res) {
 				int idx = (ps[v].size() / k) * k;
 				if (idx > 0) {
 					keep.push_back(v);
 					tot += ps[v][idx - 1];
 				}
 			}
 			res = keep;
 			cout << tot << ' ';
 		}
 		cout << endl;
 	}

    return 0;
}