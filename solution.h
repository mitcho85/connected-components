#include <iostream>
#include <vector>
using namespace std;

class Solution{
    int visited_nodes;
    bool finished;
    vector<bool> visited;
    public: 
        Solution(int n): visited_nodes(0), finished(false), visited(n, false) {}

        int countComponents(int n, vector<pair<int,int>>& edges);
        void dfs(vector<bool>& visited, vector<pair<int,int>>& edges, int node_u);
};