#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 2e5 + 5;
int s[N], e[N], d[N];
int n;

LL gs(int iL, int iR) {
	LL sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (iR < s[i] or e[i] < iL) continue ;
		sum += (min(iR, e[i]) - s[i]) / d[i] + 1 - 
			   (max(iL, s[i]) - s[i] + d[i] - 1) / d[i];
	}
	return sum;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d %d %d", &s[i], &e[i], &d[i]);
	LL iL = 0, iR = *max_element(e + 1, e + 1 + n);
	if (not (gs(iL, iR) & 1)) {
		printf("There's no weakness.\n");
		return ;
	}
	while (iL < iR) {
		LL iM = (iL + iR) / 2;
		if (gs(iL, iM) & 1) iR = iM;
		else iL = iM + 1;
	}
	printf("%d %lld\n", iL, gs(iL, iL));
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