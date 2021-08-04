#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL

int a[105];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int tot = 0;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) tot += a[i];
		bool firstWin = false;
		for (int i = 0; i < n; ++i) {
			if (a[i] > tot / 2) firstWin = true;
		}
		if (n == 1 || tot & 1) firstWin =  true;
		if (firstWin) cout << "T\n";
		else cout << "HL\n";
	}
	

    return 0;
}