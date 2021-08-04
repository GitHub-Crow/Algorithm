#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL


int gen(int& a, int& b) {
	int tmp = min(a, b);
	a -= tmp;
	b -= tmp;
	return tmp;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T;
	int x1, y1, z1, x2, y2, z2;
	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		int ret = 0;
		ret += 2*gen(z1, y2);
		gen(z2, x1);
		gen(z2, z1);
		gen(y1, y2);
		gen(y1, x2);
		ret -= 2*gen(z2, y1);
		cout << ret << endl;
	}

    return 0;
}