#include <iostream>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 105;
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
	int ans = 0, c = 0, idx = 0, tot = 0;
	for (int i = 0; i < n; ++i) {
		if (c < 0) c = 0;
		if (a[i]) --c;
		else ++c;
		if (c > ans) {
			ans = c;
			idx = i;
		}
		tot += a[i];
	}
	if (ans) tot += ans;
	else tot--;
	for (int i = idx; ans; ans -= 1 - a[i]) tot -= a[i];
	cout << tot << endl;


    return 0;
}