#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
int a[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	unordered_set<LL> re;
	int ans = 0;
	LL s = 0;
	re.insert(0);
	for (int i = 0; i < n; ++i) {
		s += a[i];
		if (re.count(s)) {
			++ans;
			re.clear();
			re.insert(0);
			s = a[i];
		}
		re.insert(s);
	}
	
	cout << ans << endl;
    return 0;
}