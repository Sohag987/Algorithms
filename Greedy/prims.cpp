#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {

        int u, v, weight;

        cin >> u >> v >> weight;

        
        u--;
        v--;

        
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    
    vector<bool> visited(V, false);

    vector<int> parent(V, -1);

    
    vector<int> edgeWeight(V, 0);

    int totalCost = 0;

    
    pq.push({0, 0});

    while (!pq.empty()) {

        auto [weight, u] = pq.top();
        pq.pop();

        
        
        if (visited[u])
            continue;

     
        visited[u] = true;

        totalCost += weight;

        
        for (auto [v, w] : graph[u]) {

            
            if (!visited[v]) {

                pq.push({w, v});

                
                parent[v] = u;
                edgeWeight[v] = w;
            }
        }
    }

  
    cout << "\nMinimum Spanning Tree:\n";

    for (int v = 1; v < V; v++) {

        cout << parent[v] + 1
             << " -- "
             << v + 1
             << " = "
             << edgeWeight[v]
             << endl;
    }

    cout << "\nMinimum Cost = "
         << totalCost
         << endl;

    return 0;
}