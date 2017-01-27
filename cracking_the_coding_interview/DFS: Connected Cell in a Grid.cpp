#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
int dir[8][2] = {{0, 1},{1, 0},{0, -1},{-1, 0},{1, 1},{1, -1},{-1, 1},{-1, -1}};

int get_biggest_region(vector< vector<int> > grid) {
    bool visited[100][100] = {};
    queue< pair<int,int> > q;
    int max_area = 0;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!visited[i][j] && grid[i][j] == 1){
                int area = 0;
                visited[i][j] = true;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    pair<int,int> pos = q.front();
                    q.pop();
                    area++;

                    for(int k=0;k<8;k++){
                        int nx = pos.first + dir[k][0], ny = pos.second + dir[k][1];
                        if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && grid[nx][ny]){
                            q.push(make_pair(nx, ny));
                            visited[nx][ny] = true;
                        }
                    }
                }
                max_area = max(max_area, area);
            }
    return max_area;
}

int main(){
    cin >> n;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
