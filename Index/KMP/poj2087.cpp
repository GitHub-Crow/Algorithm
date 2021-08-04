#include <iostream>
#include <string>

using namespace std;
typedef long long LL;

#define LOCAL

string s, p;
const int N = 1e3 + 5;
int nxt[N], ans;
void getNext() {
	int i = 0, j = -1, len = p.size(); // 这里j = -1是故意进行偏置一位
	nxt[0] = -1;
	while (i < len) {
		if (j == -1 || p[i] == p[j]) 
			nxt[++i] = ++j;
		else
			j = nxt[j];
	}
}

int KMP() {
	int i = 0, j = 0, ns = s.size(), np = p.size();
	ans = 0;
	getNext();
	while (i < ns && j < np) {
		if (j == -1 || s[i] == p[j]) {
			++i; ++j;
			if (j == np) {
				++ans;
				j = 0;
			}
		}
		else
			j = nxt[j];
	}
	return ans;
}


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.txt", "r", stdin);
	#endif

	while (cin >> s && s[0] != '#') {
		cin >> p;
		cout << KMP() << endl;
	}
	

    return 0;
}