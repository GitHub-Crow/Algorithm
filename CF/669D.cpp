#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;
#define LOCAL

int ask(int i, int j) {
	cout << "? " << i + 1 << ' ' << j + 1 << endl;
	int r;
	cin >> r;
	return r; 
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	vector<int> ans(n, -1);
	int mx = 0;
	for (int k = 1; k < n; ++k) {
		int a = ask(k, mx);
		int b = ask(mx, k);
		if (a > b) {
			ans[k] = a;
		} else {
			ans[mx] = b;
			mx = k;
		}
	}
	ans[mx] = n;
	cout << "! ";
	for (int k = 0; k < n; ++k) cout << ans[k] << ' '; 
	cout << endl;
	

    return 0;
}