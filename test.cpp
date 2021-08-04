#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
int n, m;
const int N = 105;
int a[N][N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) cout << a[j][i] << ' ';
		cout << endl;
	}	

 

    return 0;
}