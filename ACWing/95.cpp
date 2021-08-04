#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

vector<string> G(5);
int C[5][5];
string el;
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};
int _count = 0;
void charge(int r, int c) {
	C[r][c] ^= 1;
}

void change(int r, int c) {
	++_count;
	charge(r, c);
	for (int k = 0; k < 4; ++k) {
		int nr = r + dr[k], nc = c + dc[k];
		if (nr < 0 or nr >= 5 or nc < 0 or nc >= 5) continue ;
		charge(nr, nc);
	}
}


bool isLight(int r) {
	for (int k = 0; k < 5; ++k) if (not C[r][k]) return false;
	return true;
}

int solve() {
	for (int si = 0; si < (1 << 5); ++si)
		for (int sj = 0; sj < (1 << 5); ++sj) {
			_count = 0;
			for (int i = 0; i < 5; ++i) 
				for (int j = 0; j < 5; ++j) C[i][j] = G[i][j] - '0';
			for (int o = 0; o < 5; ++o) {
				if (si >> o & 1) change(0, o);
				if (sj >> o & 1) change(1, o);
			}
			if (not isLight(0)) continue ;
			for (int r = 1; r < 4; ++r) {
				for (int c = 0; c < 5; ++c) {
					if (not C[r][c]) change(r + 1, c);
				}
			}
			if (isLight(4) and _count <= 6) return _count;
		}
	return -1;
}


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	while (n--) {
		string s;
		for (int k = 0; k < 5; ++k) cin >> G[k];
		cout << solve() << endl;
	}
    return 0;
}