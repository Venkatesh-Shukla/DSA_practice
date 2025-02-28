#include <iostream>
#include <vector>
#include <set>
using namespace std;

class DSU {
public:
    vector<int> siz, parent;
    int cnt;

    DSU(int n) {
        siz.resize(n, 1);
        parent.resize(n);
        cnt = n;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void _union(int i, int j) {
        int iroot = find(i);
        int jroot = find(j);

        if (iroot == jroot)
            return;

        if (siz[iroot] < siz[jroot]) {
            parent[iroot] = jroot;
            siz[jroot] += siz[iroot];  // Correctly updating size
        } else {
            parent[jroot] = iroot;
            siz[iroot] += siz[jroot];
        }
    }

    int units() {
        set<int> s;
        for (int i = 0; i < parent.size(); i++) {
            s.insert(find(i));  // Count unique roots
        }
        return s.size();
    }

    int max_count() {
        int maxi = 0;
        for (int i = 0; i < siz.size(); i++) {
            if (find(i) == i)  // Only consider root nodes
                maxi = max(maxi, siz[i]);
        }
        return maxi;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    DSU obj(m);
    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        obj._union(t1 - 1, t2 - 1);
        cout << obj.units() << " ";
        cout << obj.max_count() << "\n";
    }
}
