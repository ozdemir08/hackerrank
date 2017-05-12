#include <iostream>
#include <vector>

#define MAX 320

using namespace std;


int A[MAX][MAX];
int rotated[MAX][MAX];
int M, N, R;
int dir[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};

class Point{
public:
	int i, j, edge, lap;

	Point(){
		i = j = edge = lap = 0;
	}

	Point(int x, int y, int e){
		i = x;
		j = y;
		edge = e;
		lap = 0;
	}
	Point(int x, int y, int e, int l){
		i = x;
		j = y;
		edge = e;
		lap = l;
	}

	Point(Point &b){
		i = b.i;
		j = b.j;
		edge = b.edge;
		lap = b.lap;
	}


	Point nextPoint(){
		Point next(i + dir[edge][0], j + dir[edge][1], edge, lap);
		if(next.isInLimits())
			return next;

		int nEdge = (edge + 1) % 4;
		Point next2(i + dir[nEdge][0], j + dir[nEdge][1], nEdge, lap);
		return next2;
	}
private:
	
	bool isInLimits(){
		return i < M-lap && i>=lap && j < N-lap && j >= lap;
	}
};

void read(){
	cin >> M >> N >> R;
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin >> A[i][j];
}

void rotate(){

	int elementNumber = 2 * (M + N - 2);

	for(int i=0;i<(min(M,N)+1)/2;i++, elementNumber -= 8){
		Point p(i,i,0,i);
		Point rot(p);
		int mod = (2 * (M+N-2-4*i));
		for(int j=0;mod>0 && j<R % mod;j++)
			rot = rot.nextPoint();

		for(int j=0;j<elementNumber;j++, rot = rot.nextPoint(), p = p.nextPoint())
			rotated[rot.i][rot.j] = A[p.i][p.j];
	}
}

void print(){
	for(int i=0;i<M;i++, cout << endl)
		for(int j=0;j<N;j++)
			cout << rotated[i][j] << ' ';
}

int main(){
	read();
	rotate();
	print();
}