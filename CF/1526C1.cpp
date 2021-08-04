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
	int n, x;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> heap;
	LL c = 0, ans = n;
	while (n--) {
		cin >> x;
		heap.push(x);
		c += x;
		if (c < 0) {
			auto o = heap.top(); heap.pop();
			c -= o;
			--ans;
		}
	}
	cout << ans << endl;

    return 0;
}	