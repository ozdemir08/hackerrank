#include <iostream>
#include <vector>

#define MAX 320

using namespace std;

int dir[][]{
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

int A[MAX][MAX];
int M, N, R;

class Point{
public:
	int i, j, edge;

	bool isInLimits(Point a){
		return a.i < M && a.i>=0 && a.j < N && a.j >= 0;
	}

};


Point nextPoint(Point a){
	Point next = a;
}

void read(){
	cin >> M >> N >> R;
	R %= 2 * (M + N - 1);
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin >> A[i][j];
}

int main(){
	read();
}