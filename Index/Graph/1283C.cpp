/*
Q: 给定一个置换数组满足ai != i，但是其中缺少一些数字，请补充完整该置换数组。
A: 置换数组可以转化为互不相交一组圆环（ai->i构成一条边）。
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
int f[N];
int indeg[N], outdeg[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	memset(f, 0, sizeof(f));
	memset(indeg, 0, sizeof(indeg));
	memset(outdeg, 0, sizeof(outdeg));
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
		if (f[i]) {
			outdeg[i]++;
			indeg[f[i]]++;
		}
	}

	vector<int> iso;
	for (int i = 1; i <= n; ++i)
		if (indeg[i] or outdeg[i]) continue ;
		else iso.push_back(i);

	int m = iso.size();
	if (m > 1) {
		for (int i = 0; i < m; ++i) {
			int u = iso[i], v = iso[(i + 1) % m];
			f[u] = v;
			outdeg[u]++;
			indeg[v]++;
		}
	}
	else if (m == 1) {
		int u = iso[0];
		for (int i = 1; i <= n; ++i) {
			if (i != u && indeg[i] == 0) {
				indeg[i]++;
				outdeg[u]++;
				f[u] = i;
				break;
			}
		}
	}
	vector<int> iz, oz;
	for (int i = 1; i <= n; ++i) {
		if (not indeg[i]) iz.push_back(i);
		if (not outdeg[i]) oz.push_back(i);
	}
	for (int k = 0; k < iz.size(); ++k) f[oz[k]] = iz[k];
	for (int k = 1; k <= n; ++k) cout << f[k] << ' ';
	cout << endl;

    return 0;
}