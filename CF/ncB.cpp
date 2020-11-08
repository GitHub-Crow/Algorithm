#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
typedef long long LL;
#define LOCAL

const double d0 = 1;
const double d1 = 1.41421356;

vector<int> dx = {0, 0, -1, 1, -1, 1, -1, 1};
vector<int> dy = {1, -1, 0, 0, -1, -1, 1, 1};
vector<double> d = {d0, d0, d0, d0, d1, d1, d1, d1};

struct wall {
	int x1, y1, x2, y2;
	wall(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
	bool operator< (const wall& rhs) const {
		if (x1 < rhs.x1) return true;
		else if (x1 > rhs.x1) return false;
		else return x2 < rhs.x2;
	}
};

vector<wall> walls;

struct node {
	int i, j;
	double v, u;
	node(int i, int j, double u, double v) : i(i), j(j), u(u), v(v) {}
	bool operator< (const node& rhs) const {
		return u > rhs.u;
	}
	bool operator () (node& lhs, node& rhs) {
		return lhs.u > rhs.u;
	}
};

int n, m;

double get(int sx, int sy, int tx, int ty) {
	return sqrt(1.0 * (sx - tx) * (sx - tx) + 1.0 * (sy - ty) * (sy - ty));
}

bool isOb(int x, int y, int nx, int ny) {
	int lx = min(x, nx), ux = max(x, nx);
	int ly = min(y, ny), uy = max(y, ny);
	for (auto w : walls) {
		bool xOb = !(w.x1 >= ux || w.x2 <= lx);
		bool yOb = !(w.y1 >= uy || w.y2 <= ly);
		if (xOb && yOb) return true;
	}
	return false;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int k;
	cin >> n >> m >> k;
	++n; ++m;
	walls.clear();
	int x1, y1, x2, y2;
	for (int i = 0; i < k; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		walls.push_back(wall(x1, y1, x2, y2));
	}
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;

	sort(walls.begin(), walls.end());

	priority_queue<node> heap;
	heap.push(node(sx, sy, get(sx, sy, tx, ty), 0));
	
	unordered_set<int> re;
	while (!heap.empty()) {
		auto c = heap.top(); heap.pop();
		int x = c.i, y = c.j;
		int ckey = x * 1e5 + y;
		if (re.count(ckey)) continue ;
		re.insert(ckey);
		double u = c.u, v = c.v;
		printf("%d, %d, %f, %f\n", x, y, u, v);
		if (x == tx && y == ty) {
			cout << v;
			break ;
		}
		for (int k = 0; k < 8; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || isOb(x, y, nx, ny)) continue ;
			int key = nx * 1e5 + ny;
			if (re.count(key)) continue ;
			double nv = v + d[k];
			double nu = nv + get(nx, ny, tx, ty);
			heap.push(node(nx, ny, nu, nv));
		}
	}
    return 0;
}