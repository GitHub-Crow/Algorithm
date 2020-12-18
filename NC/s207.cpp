#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param x string字符串 
     * @return int整型
     */
    int Maximumlength(string x) {
        int len = x.size();
        vector<int> a(len + 1), c(len + 1);

        for (int i = 0; i < len; ++i) {
        	if (x[i] == 'a') 
        		a[i + 1] = a[i] + 1;
        }
        for (int i = len - 1; i >= 0; --i) {
        	if (x[i] == 'c')
        		c[i] = c[i + 1] + 1;
        }
        int iL = -1, iR = -1, ans = 0;
        for (int i = 0; i < len; ++i) {
        	if (x[i] == 'b') {
        		if (iL == -1) iL = i;
        		else iR = i;
        		int u = iR - iL + 1;
        		if (a[iL] >= u && c[iR + 1] >= u) ans = max(ans, u);
        	}
        }
        return ans;
    }

    int PointsOnDiameter(int n, vector<int>& u, vector<int>& v) {
    	vector<int> g[n + 1];
    	for (int i = 0; i < n -1; ++i) {
    		g[u[i]].push_back(v[i]);
    		g[v[i]].push_back(u[i]);
    	}	   

    }

    pair<int, int> dfs(vector<vector<int>>& )


};


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	

    return 0;
}