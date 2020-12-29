#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

#define LOCAL
const int N = 1e6 + 5;
int f[N], nxt[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, u;
	cin >> n;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	for (int k = 1; k <= 9; ++k) {
		cin >> u;
		heap.push({u, k});
	}
	vector<PII> re;
	while (!heap.empty()) {
		auto t = heap.top(); heap.pop();
		if (re.empty()) re.push_back(t);
		else {
			if (t.second < re.back().second) continue ;
			else re.push_back(t);
		}
	}
	memset(f, -1, sizeof(f));
	f[0] = 0;
	int ed = 0, mbit = 0;
	for (int k = 1; k <= n; ++k) {
		for (auto & o : re) {
			if (o.first > k) break ;
			int nk = k - o.first;
			if (f[nk] == -1) continue ;
			if (f[k] == -1 || f[k] <= f[nk] + 1) {
				f[k] = f[nk] + 1;
				nxt[k] = nk;
			}
		}
		if (mbit <= f[k]) {
			mbit = f[k];
			ed = k;
		}
	}
	if (ed == 0) cout <<"-1\n";
	else {
		unordered_map<int, int> q;
		for (auto & v : re) q[v.first] = v.second;
		string w;
		while (ed) {
			w.push_back(q[ed - nxt[ed]] + '0');
			ed = nxt[ed];
		}
		sort(w.begin(), w.end());
		reverse(w.begin(), w.end());
		cout << w << endl;		
	}

    return 0;
}