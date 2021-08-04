#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
#define LOCAL
const int N = 1e5 + 6;
const double eps = 0.0000001;
const double inf = 0x3f3f3f3f;
struct P {
	int x, y, z;
	bool operator < (const P& w) {
		return x < w.x;
	}
} p[2 * N];

double cd(int i, int j) {
	if (p[i].z == p[j].z) return inf;
	return sqrt((LD)(p[i].x - p[j].x) * (p[i].x - p[j].x) + 
				(LD)(p[i].y - p[j].y) * (p[i].y - p[j].y));
}

double raid(int iL, int iR) {
	if (iL == iR) return inf;
	if (iR - iL == 1) return cd(iL, iR);
	int iM = (iL + iR) / 2;
	double ans = min(raid(iL, iM), raid(iM, iR));
	for (int i = iM; i >= iL; --i) {
		if (p[iM].x - p[i].x + eps > ans) break ;
		for (int j = iM + 1; j <= iR; ++j) {
			if (p[j].x - p[iM].x + eps > ans) break ;
			ans = min(ans, cd(i, j));
		}
	}
	return ans;
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].z = 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &p[i+n].x, &p[i+n].y);
		p[i+n].z = 1;
	}
	sort(p + 1, p + 2 * n + 1);
	printf("%.3f\n", raid(1, 2 * n));
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) solve();
    return 0;
}