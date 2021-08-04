#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 5e5 + 5;
int a[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	LL tot = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		tot += a[i];
	}
	if (tot % 3) cout << "0\n";
	else {
		LL u = tot / 3, v = 0;
		vector<int> fk, bk;
		for (int k = 0; k < n; ++k) {
			v += a[k];
			if (v == u) fk.push_back(k);
		}
		v = 0;
		for (int k = n - 1; k >= 0; --k) {
			v += a[k];
			if (v == u) bk.push_back(k);
		}
		LL ans = 0;
		int i = 0, j = bk.size() - 1;
		while (i < fk.size() && j >= 0) {
			if (fk[i] + 1 < bk[j] ) {
				// cout << fk[i] << ' ' << bk[j] << endl;
				ans += j + 1;
				++i;
			}
			else {
				--j;
			}
		}
		cout << ans << endl;
	}


    return 0;
}