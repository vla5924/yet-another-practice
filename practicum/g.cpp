// TL

#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
    int w;
    int p;

    Vertex(int w, int p) : w(w), p(p) {}
};

int getNumberOfUpgoingPaths(vector<Vertex> tree, int x) {
    int nPaths = 0;
    for (int i = 0; i < tree.size(); i++) {
        int current = i;
        int sum = 0;
        while (current != -1) {
            sum += tree[current].w;
            if (sum == x)
                nPaths++;
            current = tree[current].p;
        }
    }
    return nPaths;
}

vector<Vertex> readTree(int n) {
    vector<Vertex> tree;
    for (int i = 0; i < n; i++) {
        int parent, weight;
        cin >> parent >> weight;
        tree.push_back(Vertex(weight, parent));
    }
    return tree;
}

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<Vertex> tree = readTree(n);
    cout << getNumberOfUpgoingPaths(tree, x);
}
