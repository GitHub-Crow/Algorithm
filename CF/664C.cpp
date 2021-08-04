#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
#define LOCAL

const int N = 205;
int a[N], b[N];
int n, m;

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];

	
	int ret = 0;
	vector<vector<bool>> v(n, vector<bool>(m, true));
	for (int k = 9; k >= 0; --k) {
		bool f = false;
		for (int i = 0; i < n; ++i) {
			if (a[i] >> k & 1) {
				bool hasZeroBit = false;
				for (int j = 0; j < m; ++j) {
					if (v[i][j]) {
						if (b[j] >> k & 1)  continue;
						else hasZeroBit = true;
					}
				}
				if (!hasZeroBit) f = true;
			}
		}
		if (f) ret |= (1 << k); 
		else {
			for (int i = 0; i < n; ++i) {
				if (a[i] >> k & 1) {
					for (int j = 0; j < m; ++j) {
						if (v[i][j] && (b[j] >> k & 1)) v[i][j] = false;
					}
				}
			}	
		}
	}
	cout << ret << endl;
    return 0;
}