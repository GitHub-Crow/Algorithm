void insert(int x) {
    if (currentSize == arr.size() - 1) {
        arr.resize(2 * currentSize);
    }
    arr[++currentSize] = x;
    int i = currentSize;
    for ( ; i > 1 && arr[i / 2] < x; i >>= 1) {
        arr[i] = arr[i / 2];
    }
    arr[i] = x;
}

void percolateDown(int hole) {
    int x = arr[hole];
    for (int child = hole * 2; hole <= currentSize; hole = child) {
        if (child < currentSize && arr[child + 1] < arr[child]) ++child;
        if (x < arr[child]) break ;
        else arr[hole] = arr[child];
    }
    arr[hole] = x;
}

void deleteMin() {
    arr[1] = arr[currentSize--];
    percolateDown(1);
}

void buildHeap() {
    for (int i = currentSize / 2; i; --i) percolateDown(i);
}

stack<char> ops;
for (auto & v : exp) {
    if (isops(v)) {
        while (!ops.empty() && !ops.top() isLowerThan(v)) ops.pop();
    }
}

void insertSort() {
    for (int i = 1; i < arr.size(); ++i) {
        int tmp = arr[i], j = i;
        for ( ; j > 0 && arr[j - 1] > arr[j]; --j) arr[j] = arr[j - 1];
        arr[j] = tmp;
    }
}

void quickSort(vector<int>& arr, int left, int right) {
    if (right - left < 10) insertSort(arr, left, right);
    int mid = (left + right) >> 1;
    int povit = getPivot(arr, left, right);
    int i = left, j = right - 1;
    while (i < j) {
        while (arr[++i] < povit) ;
        while (arr[--j] < povit) ;
        if (i < j) swap(arr[i], a[j]);
    }
    swap(arr[i], arr[right - 1]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int getPivot(vector<int>& arr, int left, int right) {
    int mid = (left + right) >> 1;
    if (arr[left] > arr[mid]) swap(arr[left], arr[mid]);
    if (arr[left] > arr[right]) swap(arr[left], arr[right]);
    if (arr[mid] > arr[right]) swap(arr[mid], arr[right]);
    swap(arr[mid], arr[right - 1]);
    return arr[right - 1];
}

void Kruskal() {
    sortByEadge(g);
    for (auto & e : g) {
        if (findFa(u) == findFa(v)) continue ;
        else merge(u, v);
    }
}

void Prim() {
    dis[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(0);
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        
    }
}