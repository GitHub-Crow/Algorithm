#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int dx = abs(x1 - x2), dy = abs(y1 - y2);
	if (x1 != x2 && y1 != y2) {
		if (dx == dy) printf("%d %d %d %d\n", x1, y2, x2, y1);
		else printf("-1\n");
	}
	else if (x1 != x2) printf("%d %d %d %d\n", x1, y1 + dx, x2, y2 + dx);
	else if (y1 != y2) printf("%d %d %d %d\n", x1 + dy, y1, x2 + dy, y2);
	
    return 0;
}