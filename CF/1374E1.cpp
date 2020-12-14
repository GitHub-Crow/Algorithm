#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int n, k;
const int N = 2e5 + 5;
int t[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	cin >> n >> k;
	int af, bf;
	vector<int> a, b, ab;
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> af >> bf;
		if (af && bf) ab.push_back(t[i]);
		else if (af) a.push_back(t[i]);
		else if (bf) b.push_back(t[i]);
	} 
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(ab.begin(), ab.end());
	int pa = 0, pb = 0, pab = 0;
	int na = a.size(), nb = b.size(), nab = ab.size();
	// cout << na << ' ' << nb << ' ' << nab << endl;
	int ans = 0;
	while (k--) {
		if (pa < na && pb < nb && pab < nab) {
			if (a[pa] + b[pb] < ab[pab]) 
				ans += a[pa++] + b[pb++];
			else 
				ans += ab[pab++];
		}
		else if (pab < nab)
			ans += ab[pab++];
		else if (pa < na && pb < nb) 
			ans += a[pa++] + b[pb++];
		else {
			ans = -1;
			break ;
		}
	}
	cout << ans << endl;

    return 0;
}