#include <iostream>
#include <string>

#define MAX_LENGTH 5002

using namespace std;

int N;
string s1, s2;
int DP[MAX_LENGTH][MAX_LENGTH];

int main(){
	cin >> s1 >> s2;
	N = s1.size();
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			DP[i][j] = max((s1[i-1] == s2[j-1]) + DP[i-1][j-1],
				max(DP[i-1][j], DP[i][j-1])
				);
	cout << DP[N][N] << endl;
}