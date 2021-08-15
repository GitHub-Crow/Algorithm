#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m;
const int N = 2e5 + 5;
int a[N];
int lidx[4*N], ridx[4*N];
LL val[4*N], delta[4*N];

void pushdown(int idx) {
	val[idx << 1] += delta[idx], delta[idx << 1] += delta[idx];
	val[idx << 1 | 1] += delta[idx], delta[idx << 1 | 1] += delta[idx];
	delta[idx] = 0;
}

void pushup(int idx) {
	val[idx] = min(val[idx << 1], val[idx << 1 | 1]);
}

void buildSeg(int iL, int iR, int idx) {
	lidx[idx] = iL;
	ridx[idx] = iR;
	if (iL == iR) {
		val[idx] = a[iL];
		return ;
	}
	int iM = (iL + iR) / 2;
	buildSeg(iL, iM, idx * 2);
	buildSeg(iM + 1, iR, idx * 2 + 1);
	pushup(idx);
}


LL querySeg(int iL, int iR, int idx) {
	if (lidx[idx] == iL and ridx[idx] == iR) return val[idx];
	pushdown(idx);
	int iM = (lidx[idx] + ridx[idx]) / 2;
	if (iR <= iM) return querySeg(iL, iR, idx * 2);
	else if (iL > iM) return querySeg(iL, iR, idx * 2 + 1);
	else return min(querySeg(iL, iM, idx * 2), querySeg(iM + 1, iR, idx * 2 + 1));
}

void addSeg(int iL, int iR, int idx, int d) {
    if (lidx[idx] == iL and ridx[idx] == iR) {
        val[idx] += d;
        delta[idx] += d;
        return ;
    }
    pushdown(idx);
	int iM = (lidx[idx] + ridx[idx]) / 2;
	if (iR <= iM) addSeg(iL, iR, idx * 2, d);
	else if (iL > iM) addSeg(iL, iR, idx * 2 + 1, d);
	else {
	    addSeg(iL, iM, idx * 2, d);
	    addSeg(iM + 1, iR, idx * 2 + 1, d);
	}
	pushup(idx);
}

void add_(int iL, int iR, int d) {
    if (iL <= iR) addSeg(iL, iR, 1, d);
    else {
        addSeg(iL, n - 1, 1, d);
        addSeg(0, iR, 1, d);
    }
}

LL query_(int iL, int iR) {
    if (iL <= iR) return querySeg(iL, iR, 1);
    else {
        return min(querySeg(iL, n - 1, 1), querySeg(0, iR, 1));
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    buildSeg(0, n - 1, 1);
    cin >> m;
    string s;
    getline(cin, s);
    for (int i = 0; i < m; ++i) {
        getline(cin, s);
        stringstream _sin(s);
        int v;
        vector<int> cmds;
        while (_sin >> v) cmds.push_back(v);
        if (cmds.size() == 3) add_(cmds[0], cmds[1], cmds[2]);
        else cout << query_(cmds[0], cmds[1]) << endl;
    }
    return 0;
}
