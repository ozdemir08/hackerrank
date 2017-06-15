#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector< vector<int> > adj(100002);
int group[100002];
int A[100002];
int DP[1002][1002];
int N, K, M;
int groupNumber = 1;

void read(){
	cin >> N >> K >> M;
	for(int i=0;i<K;i++){
		int x, y;
		scanf("%d %d",&x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1;i<=M;i++)
		scanf("%d",&A[i]);
}

void dfs(int x){
	// cout << x << ' ' << groupNumber << endl;
	group[x] = groupNumber;
	for(int i=0;i<adj[x].size();i++){
		int next = adj[x][i];
		if(!group[next])
			dfs(next);
	}
}

void transform(){
	for(int i=1;i<=M;i++)
		A[i] = group[A[i]];
}

int fillDP(int l, int r){
	if(l > r) return 0;
	if(l == r) return 1;
	if(DP[l][r])
		return DP[l][r];

	int mx = max(fillDP(l+1, r), fillDP(l, r-1));
	return DP[l][r] = max(mx, fillDP(l+1, r-1) + (A[l] == A[r] ? 2 : 0));
}

int main(){
	read();

	for(int i=1;i<=N;i++)
		if(!group[i]){
			dfs(i);
			groupNumber++;
		}

	transform();
	cout << fillDP(1, M) << endl;
	// for(int i=1;i<=M;i++, cout << endl)
	// 	for(int j=1;j<=M;j++)
	// 		cout << DP[i][j] << ' ';
}