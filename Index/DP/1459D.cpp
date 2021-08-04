/*
Q: 有n个杯子，容积为a单位，杯中装有b单位水，你可以选任意一个杯子
向任意杯子倒入任意水量x，前提是水量不超过现有的，且杯子会溢出多余的水量，
但是在倒水时会有一半的水丢失，例如从杯1倒x水到杯2，那么杯1减少x水，杯2增加x/2水
问分别选择1,2,3...n个杯子作为收集器，能够收到最多的水是多少？
A: dp[i][j][k]表示前i个杯子选j个杯子且选中的杯子容积和为k的最多现有水量

*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 105;
int f[N][N*N];
int a[N], b[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	int tota = 0, totb = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		totb += b[i];
	}
	memset(f, -1, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		
		tota += a[i];
		for (int j = i; j; --j)
			for (int k = tota; k >= a[i]; --k) {
				if (f[j - 1][k - a[i]] != -1) {
					f[j][k] = max(f[j - 1][k - a[i]] + b[i], f[j][k]);
					// printf("%d, %d, %d = %d\n", i, j, k, f[j][k]);
				}
			}
	}
	for (int i = 1; i <= n; ++i) {
		int r = 0;
		for (int k = 1; k <= tota; ++k) 
			if (f[i][k] != -1)
				r = max(r, min(2 * k, f[i][k] + totb));
		cout << fixed << setprecision(12) << 1.0 * r / 2.0 << ' ';
	}
	cout << endl;

    return 0;
}