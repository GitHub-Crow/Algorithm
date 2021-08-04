#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << (abs(a - b) + 9) / 10 << endl;
	}
	

    return 0;
}