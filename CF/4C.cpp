#include <iostream>
#include <string>
#include <unordered_map>

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
	string x;
	cin >> n;
	unordered_map<string, int> re;
	while (n--) {
		cin >> x;
		if (re.count(x)) {
			while (true) {
				string t = x + to_string(re[x]);
				re[x]++;
				if (re.count(t)) 
					continue ; 
				else {
					re[t] = 1;
					cout << t << endl;
					break ;
				}
			}
		}
		else {
			re[x] = 1;
			cout << "OK\n";
		}
	}
	

    return 0;
}