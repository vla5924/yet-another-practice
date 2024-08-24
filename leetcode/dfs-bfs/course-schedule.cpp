// https://leetcode.com/problems/course-schedule/

#include <vector>

using namespace std;

class Solution {
    enum struct Color { White, Gray, Black };

    void tarjanTraverse(int vertex, vector<vector<int>> &adj, vector<Color> &coloring, bool &hasLoop) {
        auto &color = coloring[vertex];
        if (color == Color::Black) {
            return;
        }
        if (color == Color::Gray) {
            hasLoop = true;
            return;
        }
        // color == Color::White
        color = Color::Gray;
        for (int neighbor : adj[vertex])
            tarjanTraverse(neighbor, adj, coloring, hasLoop);
        color = Color::Black;
        // for toposort, we also have to save 'vertex' to the beginning of order list
        // but for this problem the order list itself is not needed
    }

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for (auto &edge : prerequisites)
            adj[edge.back()].push_back(edge.front());
        vector<Color> coloring(numCourses, Color::White);
        bool hasLoop = false;
        for (int vertex = 0; vertex < numCourses; vertex++)
            tarjanTraverse(vertex, adj, coloring, hasLoop);
        return !hasLoop;
    }
};

int main() { return 0; }
