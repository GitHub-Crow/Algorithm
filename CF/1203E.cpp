#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N =2e5;
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
	sort(a, a + n);
	unordered_set<int> re;
	for (int i = 0; i < n; ++i) {
		int v = a[i];
		if (v - 1 != 0 && !re.count(v - 1)) re.insert(v - 1);
		else if (!re.count(v)) re.insert(v);
		else re.insert(v + 1);
	}
	cout << re.size() << endl;

    return 0;
}