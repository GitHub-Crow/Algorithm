/*
Q: 给定一个网格空间，你可以垂直走一步也可以水平走一步，但是必须是相互交替的
也就是说这一步是垂直向下或向上走的，下一步必须向左走或向右走，n步之后终点位置有多少种可能？
A: 分解垂直和水平，两者是相互独立的
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	if (n & 1) cout << 2 * (n/2 + 1) * (n/2 + 2) << endl;
	else cout << (n/2 + 1) * (n/2 + 1) << endl;
	

    return 0;
}