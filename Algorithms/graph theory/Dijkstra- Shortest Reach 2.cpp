#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

#define city first
#define dist second
#define MAX 3002

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.dist > b.dist;
}

vector<int> shortestPath(vector< vector < pair<int,int> > > graph, int start, int n){

    vector<int> shortest_distance(n, -1);
    vector< pair<int, int> > heap;
    heap.push_back(make_pair(start, 0));   
    make_heap(heap.begin(), heap.end(), cmp);

    while(!heap.empty()){
        pair<int, int> cur = heap[0];
        pop_heap(heap.begin(), heap.end(), cmp);
        heap.pop_back();

        if(shortest_distance[cur.city] != -1)   continue;
        shortest_distance[cur.city] = cur.dist;

        for(int i=0;i<graph[cur.city].size();i++){
            int next_city = graph[cur.city][i].city;
            int next_dist = graph[cur.city][i].dist + cur.dist;
            if(shortest_distance[next_city] == -1){
                heap.push_back(make_pair(next_city, next_dist));
                push_heap(heap.begin(), heap.end(), cmp);
            }
        }
    }

    return shortest_distance;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;

        vector< vector < pair<int,int> > > graph(n);
        for(int a1 = 0; a1 < m; a1++){
            int x;
            int y;
            int r;
            cin >> x >> y >> r;
            x--; y--;
            graph[x].push_back(make_pair(y, r));
            graph[y].push_back(make_pair(x, r));
        }
        int s;
        cin >> s;
        s--;

        vector<int> shortest_dist = shortestPath(graph, s, n);
        
        for(int i=0;i<n;i++)
            if(i != s)
                cout << shortest_dist[i] << ' ';
        cout << endl;

    }
    return 0;
}
