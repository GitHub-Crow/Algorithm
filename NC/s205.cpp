#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long LL;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回符合题意的最长的子串长度
     * @param x string字符串 
     * @return int整型
     */
    int Maximumlength(string x) {
        int in = -1, ip = -1, iy = -1;
        int ans = 0;
        for (int k = 0; k < x.size(); ++k) {
            if (x[k] == 'n') in = k;
            else if (x[k] == 'p') ip = k;
            else if (x[k] == 'y') iy = k;
            ans = max(ans, k - min({in, ip, iy})); 
        }
        return ans;
    }

    long long solve(string str) {
        stack<LL> nums;
        LL c = 0;
        for (auto & v : str) {
            if (v >= '0' && v <= '9') c = c * 10 + v - '0';
            else if (v == '#') {
                nums.push(c);
                c = 0;
            }
            else {
                auto rhs = nums.top(); nums.pop();
                auto lhs = nums.top(); nums.pop();
                if (v == '+') nums.push(lhs + rhs);
                else if (v == '-') nums.push(lhs - rhs);
                else if (v == '*') nums.push(lhs * rhs);
            }
        }
        return nums.top();
    }
    int f, s;
    int tree3(vector<int>& e) {
        int n = e.size();
        vector<vector<int>> g(n + 2);
        for (int i = 0; i < n; ++i) {
            g[e[i]].push_back(i + 2);
        }
        f = 0, s = 0;
        dfs(g, 1);
        cout << s << endl;
        return s;
    }

    int dfs(vector<vector<int>>& g, int k) {
        if (g[k].empty()) return 0;
        vector<int> cd;
        for (auto & v : g[k]) {
            cd.push_back(dfs(g, v));
        }
        int r = 0;
        cd.push_back(-1);
        int n = cd.size(), mcd = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x = cd[i] + cd[j] + 2;
                if (x > f) {
                    s = f;
                    f = x;
                } else if (x > s) {
                    s = x;
                }
                printf("%d, %d, %d\n", i, j, x);
            }
            mcd = max(mcd, cd[i]);
        }
        return mcd + 1;
    }
};

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

    Solution sol;
    vector<int> tin = {1, 1, 1};
    sol.tree3(tin);
	

    return 0;
}