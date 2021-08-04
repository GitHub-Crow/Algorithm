#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<int> f(n);
	int ans = 1;
	for (int k = 0; k < n; ++k) {
		int x = 2 * a[k];
		while (x < )
	}
	cout << ans;

    return 0;
}