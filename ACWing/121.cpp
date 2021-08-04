#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 505, M = 10005;
int prs[N][N];
int x[M], y[M], xs[N], ys[N], px[N], py[N];
int c, n, nx = 0, ny = 0;

void buildPrs() {
	for (int i = 1; i <= n; ++i) prs[x[px[i]]][y[py[i]]]++;
	for (int i = 1; i <= nx; ++i) {
		for (int j = 1; j <= ny; ++j) {
			prs[i][j] = prs[i][j] + prs[i][j - 1] + prs[i - 1][j] - prs[i - 1][j - 1]; 
		}
	}
}

bool isValid(int s) {
	for (int i = x[s]; i <= nx; ++i)
		for (int j = y[s]; j <= ny; ++j) {
			int is = 0, js = 0;
			if (xs[i] - s >= 0) is = x[xs[i] - s];
			if (ys[j] - s >= 0) js = y[ys[j] - s];
			int tot = prs[i][j] - prs[i][js] - prs[is][j] + prs[is][js];
			if (tot >= c) return true;
		}
	return false;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	scanf("%d %d", &c, &n);
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	memset(xs, 0, sizeof(xs));
	memset(ys, 0, sizeof(ys));
	memset(prs, 0, sizeof(prs));

	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &px[i], &py[i]);
		x[px[i]]++;
		y[py[i]]++;
	}
	for (int i =1; i < M; ++i) {
		if (x[i]) xs[++nx] = i;
		x[i] = nx;
		if (y[i]) ys[++ny] = i;
		y[i] = ny;
	}
	buildPrs();
	int mis = 0, mas = M;
	while (mis < mas) {
		int ms = (mis + mas) / 2;
		if (isValid(ms)) mas = ms;
		else mis = ms + 1;
	}
	printf("%d\n", mis);
	

    return 0;
}