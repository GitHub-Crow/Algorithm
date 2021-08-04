#include <iostream>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 1e6 + 5, M = 1e4 + 5;
int a[N], b[M], nxt[M];
int m, n;

void getNext() {
	int i = 0, j = -1;
	nxt[0] = -1;
	while (i < m) {
		if (j == -1 || b[i] == b[j]) 
			nxt[++i] = ++j;
		else 
			j = nxt[j];
	}
}

int KMP() {
	getNext();
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (j == -1 || a[i] == b[j]) {
			++i; ++j;
			if (j == m) return i - m + 1;
		}
		else 
			j = nxt[j];
	}
	return -1;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.txt", "r", stdin);
	#endif
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i];
		cout << KMP() << endl;

	}

    return 0;
}