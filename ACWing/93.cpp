#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int n, m;
void dfs(vector<int>& cache, int k) {
	if (cache.size() >= m) {
		for (auto & v : cache) cout << v << ' ';
		cout << endl;
		return ;
	} 
	if (k > n) return ;
	for (int i = k; i <= n; ++i) {
		cache.push_back(i);
		dfs(cache, i + 1);
		cache.pop_back();
	}
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> n >> m;
	vector<int> cache;
	dfs(cache, 1);
	

    return 0;
}