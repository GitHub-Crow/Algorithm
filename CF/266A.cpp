#include <iostream>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if (a * m > b) {
		int r = (n / m) * b + min((n % m) * a, b);
		cout << r << endl;
	}
	else
		cout << n * a << endl;
    return 0;
}