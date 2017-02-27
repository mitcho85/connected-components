#include <iostream>
#include <vector>
#include "solution.h"
using namespace std; 

int main(){
    //int n = 6
    //vector<pair<int,int>> edges = {{0,1},{1,2},{2,0},{3,4},{4,5}};
    int n = 5;
    vector<pair<int,int>> edges = {{0,1},{1,2},{2,3},{3,4}};

    Solution* sol = new Solution(n);
    int res = sol->countComponents(n, edges);

    cout << "No. of connected components is: " << res << endl;
    cout << "press any key to end. " << endl;
    getchar();

    return 0;
}