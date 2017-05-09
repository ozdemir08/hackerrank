#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Graph {
    public:
        vector< vector<int> > edges;
        int n;
        Graph(int n) {
            edges.resize(n);
            this -> n = n;
        }
    
        void add_edge(int u, int v) {
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            std::vector<bool> marked(n);
            std::vector<int> distance(n);
            queue<int> q;
            q.push(start);
            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int i=0;i<edges[cur].size();i++)
                    if(!marked[edges[cur][i]]){
                        int next = edges[cur][i];
                        marked[next] = true;
                        distance[next] = distance[cur] + 6;
                        q.push(next);
                    }
            }
            vector<int> res;
            for(int i=0;i<n;i++)
                if(!distance[i])
                    res.push_back(-1);
                else
                    res.push_back(distance[i]);
            return res;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

