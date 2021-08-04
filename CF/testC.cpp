#include <iostream>
#include <set>

using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
int a[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	multiset<int> re;
	int o = a[0];
	for (int i = 0; i < k; ++i) re.insert(a[i]);
	int mc = 0, me = 0, c = 0, e = -1;
	for (auto it = re.begin(); it != re.end(); ++it) {
		if (*it != e) {
			e = *it;
			c = 1;
		} else ++c;
		if (c > mc || (c == mc && me > e)) {
			mc = c;
			me = e;
		}
	}
	cout << me << endl;
	for (int i = k; i < n; ++i) {
		mc = 0, me = 0, c = 0, e = -1;
		re.erase(a[i - k]);
		re.insert(a[i]);
		for (auto it = re.begin(); it != re.end(); ++it) {
			if (*it != e) {
				e = *it;
				c = 1;
			} else ++c;
			if (c > mc || (c == mc && me > e)) {
				mc = c;
				me = e;
			}
		}
		cout << me << endl;
	}

    return 0;
}