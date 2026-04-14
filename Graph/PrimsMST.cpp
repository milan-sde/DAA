#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii; // (weight and vertex)


void prim(vector<vector<int>> &G,int n){
    vector<int> key(n,INT_MAX);
    vector<int> parent(n);
    vector<bool> mst(n,false);

    priority_queue<pii, vector<pii> ,greater<pii>> pq;

    key[0] = 0;
    parent[0] = -1;

    pq.push({0,0});
    int totalWeight = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(mst[u]) continue;

        mst[u] = true;
        totalWeight += key[u];

        for(int v=0;v<n;v++){
            if(G[u][v] != 0 && !mst[v] && G[u][v] < key[v]){
                key[v] = G[u][v];
                parent[v] = u;
                pq.push({key[v],v});
            }
        }
    }

    cout << "Edges in MST : \n";
    for( int i = 1; i< n;i++){
        cout << parent[i] << " - " << i << " : " << G[i][parent[i]] << endl;
    }

    cout << "Total Weight = " << totalWeight << endl; 

    
}

int main(){

    int n ; // input the number of vertices
    cin >> n;

    vector<vector<int>> G(n,vector<int>(n));

    for(int i = 0 ;i< n;i++){
        for(int j=0;j<n;j++){
            cin>>G[i][j];
        }
    }

    prim(G,n);

    return 0;
}