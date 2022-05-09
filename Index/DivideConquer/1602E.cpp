/*
Q: 给定数组a和数组b，你可以以任意顺序将数组b中的元素全部插入a中，问插入后得到的数组逆序对最小是多少？
A: 分治
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e6 + 5;
int a[N], b[N], idx[N], d[N << 1], t[N << 1];
LL ans;
void insertElement(int bl, int br, int al, int ar) {
    if (bl > br) return ;
    int m = (bl + br) >> 1;
    int ic = 0, pos, res = INT_MAX;;
    for (int k = al; k <= ar; ++k) 
        if (b[m] > a[k]) ++ic;
    for (int k = al; k <= ar; ++k) {
        if (b[m] < a[k]) ++ic;
        if (b[m] > a[k]) --ic;
        if (res > ic) {
            res = ic;
            pos = k;
        }
    }
    idx[m] = pos; // where is b[m] insert in a.
    insertElement(bl, m - 1, al, pos);
    insertElement(m + 1, br, pos, ar);
}

void mergeSort(int l, int r) {
    if (l >= r) return ;
    int m = (l + r) >> 1;
    int i = l, j = m + 1, k = i;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    while (i <= m && j <= r) {
        if (d[i] <= d[j]) t[k++] = d[i++];
        else t[k++] = d[j++], ans += m - i + 1;
    }
    while (i <= m) t[k++] = d[i++];
    while (j <= r) t[k++] = d[j++];
    for (int o = l; o <= r; ++o) d[o] = t[o];
}

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int n, m, T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int j = 1; j <= m; ++j) cin >> b[j];
        sort(b + 1, b + m + 1);
        insertElement(1, m, 0, n);

        for (int i = 1, j = 1, k = 1; i <= n + 1; ) { // make sure array b has been inserted to d.
            while (j <= m && idx[j] < i) d[k++] = b[j++];
            d[k++] = a[i++];
        }
        // d is inserted result array.
        ans = 0;
        mergeSort(1, m + n);
        cout << ans << endl;
    }   
    

    return 0;
}