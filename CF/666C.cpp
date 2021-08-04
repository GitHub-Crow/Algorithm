#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL

const int N = 1e5 + 5;
int a[N];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int  n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	if (n == 1) {
		cout << "1 1\n";
		cout << "0\n";
		cout << "1 1\n";
		cout << "0\n";
		cout << "1 1\n";
		cout << -a[0] << endl;
			
	} else {
		cout << "1 1\n";
		cout << -a[0] << endl;
		cout << 1 << ' ' << n << endl;
		cout << 0 << ' ';
		for (int i = 1; i < n - 1; ++i) cout << -a[i] * 1LL * n << ' ';
		cout << -a[n - 1] * 1LL * n << endl;
		cout << 2 << ' ' << n << endl;
		for (int i = 1; i < n - 1; ++i) cout << a[i] * 1LL * (n - 1) << ' ';
		cout << a[n - 1] * 1LL * (n - 1) << endl;
		
	}

    return 0;
}	