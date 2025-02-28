#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
    vector<int> siz, parent;
    int cnt, maxSize;

    DSU(int n) : siz(n, 1), parent(n), cnt(n), maxSize(1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        return (parent[x] == x) ? x : (parent[x] = find(parent[x]));  // Path compression
    }

    void _union(int i, int j) {
        int iroot = find(i), jroot = find(j);
        if (iroot == jroot) return;

        if (siz[iroot] < siz[jroot]) swap(iroot, jroot);  // Union by size
        parent[jroot] = iroot;
        siz[iroot] += siz[jroot];
        maxSize = max(maxSize, siz[iroot]);
        cnt--;  // Reduce component count
    }

    int units() { return cnt; }  // O(1) instead of O(n)

    int max_count() { return maxSize; }  // O(1)
};

int main() {
    ios_base::sync_with_stdio(false);  // Fast I/O
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    DSU obj(m);

    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        obj._union(t1 - 1, t2 - 1);
        cout << obj.units() << " " << obj.max_count() << "\n";
    }
}
