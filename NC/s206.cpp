#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

class Solution {
public:
    /**
     * 
     * @param k int整型 表示最多的操作次数
     * @param s string字符串 表示一个仅包含小写字母的字符串
     * @return int整型
     */
    int string2(int k, string s) {
        vector<int> c(256);
        for (auto & v : s) {
        	c[v]++;
        }
        int r = 0;
        for (int i = 0; i < 256; ++i) {
        	int ans = c[i], u = k;
        	for (int j = 1; j < 256; ++j) {
        		int left = 0, right = 0;
        		if (i - j >= 0) left = c[i - j];
        		if (i + j < 256) right = c[i + j];
        		int x = left + right;
        		if (u <= j * x) {
        			ans += u / j;
        			break ;
        		} else {
        			ans += x;
        			u -= x * j;
        		}
        	}
        	r = max(ans, r);
        }
        return r;
    }
    const int N = 1e3 + 5;
    const int MOD = 1e9 + 7;
    int f[N][N];
    long long solve_bangbang(int n, int m, int k) {
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
        	f[i][0] = 1;
        	for (int j = 1; j <= m; ++j) {
        		f[i][j] = f[i - 1][j]; // 第i个字符不作为重音符
        		if (i - k - 1 >= 0) f[i][j] += f[i - k - 1][j - 1];
        		if (f[i][j] > MOD) f[i][j] -= MOD;
        	}
        }
        return f[n][m];
    }
};


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	Solotion sol;

	

    return 0;
}