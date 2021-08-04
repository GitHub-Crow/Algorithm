#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	string s;
	cin >> s;
	int u = 0, ans = 0;
	for (auto& v : s) {
		if (v == 'w') ++u;
		else {
			ans += 2 * u - 1;
			u = 0;
		}
	}
	ans += 2 * u - 1;
	cout << ans;
	

    return 0;
}