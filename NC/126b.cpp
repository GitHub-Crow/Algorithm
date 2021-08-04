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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> g[26];
	for (int k = 0; k < n; ++k) g[s[k] - 'a'].push_back(k);

	int ans = 0;
	vector<int> trial(g[s[0] - 'a'].begin(), g[s[0] - 'a'].end());
	if (s[0] == s[n - 1] && trial.size() >= 3) ans = 1;
	for (int i = 1; i <  n; ++i) {
		int idx = s[i] - 'a';
		int u = 0, v = 0;
		vector<int> tmp;
		vector<int>& next = g[idx];
		while (u < trial.size() && v < next.size()) {
			// printf("%c, %d, %d\n", s[i], trial[u], next[v]);
			if (trial[u] > next[v] - 1) ++v;
			else if (trial[u] < next[v] - 1) ++u;
			else {
				tmp.push_back(next[v]);
				++u; ++v;
				if (tmp.back() == n - 1) ans = i + 1;
			}
		}
		trial = tmp;
		if (trial.size() < 3) break ;
	}
	if (ans) cout << s.substr(0, ans) << endl;
	else cout << "Just a legend\n";
	

    return 0;
}