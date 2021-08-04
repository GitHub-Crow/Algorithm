#include <iostream>
#include <queue>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e4;
bool vis[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, m, ans;
	cin >> n >> m;
	queue<int> q;
	q.push(n);
	int steps = 0;
	for (int i = 0; i < N; ++i) vis[i] = false;
	bool f = false;
	while (!q.empty()) {
		int len = q.size();
		while (len--) {
			auto t = q.front(); q.pop();
			vis[t] = true;
			if (t == m) {
				f = true;
				break ;
			}
			if (t - 1 > 0 && !vis[t - 1]) q.push(t - 1);
			if (2 * t < N && !vis[2 * t]) q.push(2 * t);
		}
		if (f) break ;
		++ steps;
	}
	cout << steps << endl;

    return 0;
}