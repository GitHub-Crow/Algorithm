#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
#define LOCAL

const int N = 105;
int a[N];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	if (n <= 1) 
		cout << "0 0 0 0\n";
	else {
		int smin = a[0], smax = a[n - 1];
		for (int i = 1; i < n; ++i) {
			if (smin < a[i]) {
				smin = a[i];
				break ;
			}
		}
		for (int i = n - 2; i >= 0; --i) {
			if (smax > a[i]) {
				smax = a[i];
				break ;
			}
		}
		printf("%d %d %d %d\n", a[n - 1] - smax, a[n - 1] - smin, smax - smin, smax - a[0]);
	} 

    return 0;
}
