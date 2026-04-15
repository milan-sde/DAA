#include <bits/stdc++.h>
using namespace std;

#define INF 1e9



void printMatrix(vector<vector<int>> &dist,int n){
    for(auto row : dist){
        for(auto val : row){
            if( val == INF){
                cout<< "INF";
            }
            else{
                cout<<val<< " ";
            }
        }

        cout<<endl;
    }
}

int main() {

    int n = 4;

    // Given undirected adjacency matrix
    vector<vector<int>> adj = {
       {0,3,0,2},
       {5,0,6,0},
       {0,0,0,4},
       {0,-1,-3,0}

    };

    vector<vector<int>> dist(n, vector<int>(n));

    // Step 1: Convert to distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j)
                dist[i][j] = 0;
            else if (adj[i][j] != 0)
                dist[i][j] = adj[i][j];
            else
                dist[i][j] = INF;
        }
    }

    // Step 2: Floyd Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        cout<<"\nAfter k = "<<k <<":\n";
        printMatrix(dist,n);
    }

    // Output
    cout << "Shortest Distance Matrix:\n";
    for (auto row : dist) {
        for (auto val : row) {
            if (val == INF) cout << "INF ";
            else cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}