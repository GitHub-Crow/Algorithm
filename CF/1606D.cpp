/*
Q: 给定一个矩阵，操作：你可以将每一行涂成R或者B，然后将矩阵分为左右两边。请问是否存在一种操作使得：
左半边矩阵标R的元素全部大于标B的元素，右半边矩阵标B的元素全部大于标R的元素？
A: 如果只考虑第一列是否满足要求，哪些行标R或者B？
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> a[i][j];
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int lhs, int rhs) {
            return a[lhs][0] < a[rhs][0];
        });
        vector<vector<int>> smnl(n, vector<int>(m)), smxr(n, vector<int>(m)); // suffix extreme value of left and right direction.
        for (int i = n - 1; i >= 0; --i) {
            int k = ord[i];
            for (int j = 0; j < m; ++j) {
                smnl[i][j] = a[k][j];
                if (i + 1 < n) smnl[i][j] = min(smnl[i + 1][j], smnl[i][j]);
                if (j - 1 >= 0) smnl[i][j] = min(smnl[i][j - 1], smnl[i][j]);
            }
            for (int j = m - 1; j >= 0; --j) {
                smxr[i][j] = a[k][j];
                if (i + 1 < n) smxr[i][j] = max(smxr[i + 1][j], smxr[i][j]);
                if (j + 1 < m) smxr[i][j] = max(smxr[i][j + 1], smxr[i][j]);
            }
        }
        vector<int> pmnr(m, INT_MAX), pmxl(m, INT_MIN); // prefix extrem value of left and right direction.
        int row, col;
        bool isOk = false;
        for (int i = 0; i + 1 < n && !isOk; ++i) {
            int k = ord[i];
            for (int j = 0; j < m; ++j) {
                pmxl[j] = max(pmxl[j], a[k][j]);
                if (j - 1 >= 0) pmxl[j] = max(pmxl[j], pmxl[j - 1]);
            }
            for (int j = m - 1; j >= 0; --j) {
                pmnr[j] = min(pmnr[j], a[k][j]);
                if (j + 1 < m) pmnr[j] = min(pmnr[j], pmnr[j + 1]);
            }
            for (int j = 0; j + 1 < m; ++j) {
                if (pmxl[j] < smnl[i + 1][j] && pmnr[j + 1] > smxr[i + 1][j + 1]) {
                    isOk = true;
                    row = i;
                    col = j;
                    break ;
                }
            }
        }
        if (isOk) {
            cout << "YES\n";
            string s(n, 'R');
            for (int i = 0; i <= row; ++i) s[ord[i]] = 'B';
            cout << s << ' ' << col + 1 << endl; 
        }
        else {
            cout << "NO\n";
        }


    }

    

    return 0;
}