#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5;
int label[N];
vector<int> cone[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, u, v;
	cin >> n;
	for (int i = 1; i <= n; ++i) cone[i].clear();
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		cone[u].push_back(i);
		cone[v].push_back(i);
		label[i] = -1;
	}
	int mcones = 0, mu = 0;
	for (int i = 1; i <= n; ++i) {
		if (mcones < cone[i].size()) {
			mcones = cone[i].size();
			mu = i;
		}
	}
	int cur = 0;
	for (auto & v : cone[mu]) label[v] = cur++;
	for (int i = 1; i < n; ++i) {
		if (label[i] == -1) label[i] = cur++;
		cout << label[i] << endl;
	}


    return 0;
}