#include <iostream>
#include <cstdio>

#define MAX 1000002

using namespace std;

int N;
int A[MAX];
int X, res;

void read(){
	cin >> N;
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		X = X xor A[i];
	}
}

int main(){
	read();
	for(int i=0;i<N;i++)
		res += (X xor A[i]) < A[i] ? 1  : 0 ; 
		
	cout << res << endl;
	return 0;
}