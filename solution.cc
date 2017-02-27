#include "solution.h"

int Solution::countComponents(int n, vector<pair<int, int>>& edges) {
    if(n > 0 && edges.empty()) return n;
    if(edges.empty()) return 0;
    if(edges.size() == 1) return 1;
     // used to check visited nodes
    int connected_components = 0;
    for(int i = 0; i < n && !finished; i++){
        // for all nodes u in V
        cout << "countComponents: Checking if node " << i << " is visited." << endl;
        if(!visited[i]){
            bool single_node = true;
            // check if it's a node in an edge
            for(int j = 0; j < edges.size() && !finished; j++){
                if(i == edges[j].first && !visited[i]){
                    single_node = false;
                    cout << "countComponents: Node " << i << " has not been visited. Increasing component count. " << endl;
                    connected_components++;
                    cout << "countComponents: Running DFS on new root " << i << endl;
                    dfs(visited, edges, i);   
                }
            }
            if(single_node && !visited[i]){
                cout << "countComponents: Encountered single node " << i << ". Increasing component_count" << endl;
                visited[i] = true;
                connected_components++;    
            } 
        }
    }
    return connected_components;
}

void Solution::dfs(vector<bool>& visited, vector<pair<int,int>>& edges, int node_u){
    if(!visited[node_u]){
        cout << "!!!dfs:visiting node: " << node_u << endl;    
        visited[node_u] = true; visited_nodes++;
    }
    
    if(visited_nodes == visited.size()){
        cout << "!!!dfs: Entire node space has been visited. Ending DFS call." << endl;
        finished = true;
        return;    
    }
    if(!finished){
        cout << "!!!dfs:: starting edge check on node " << node_u << endl;
        getchar();
        for(int i = 0; i < edges.size(); i++){
            // (u, w)
            if(edges[i].first == node_u){ // for all (u,w) in edges
                int node_w = edges[i].second; 
                if(!visited[node_w]){
                    cout << "!!!dfs: Calling DFS on edge (" << node_u << ", " << node_w << ")" << endl;
                    dfs(visited, edges, node_w);
                }
                    
            }
        }
    }
}