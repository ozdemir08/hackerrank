#include <iostream>

using namespace std;

int a[3000], b[3000];
int N,T;

int main(){

	cin >> T;
	while(T--){
		int x = 0;
		cin >> N;
		for(int i=0;i<N;i++) cin >> a[i];
		for(int i=0;i<N;i++) cin >> b[i];
		for(int i=0;i<N;i++) 
			x ^= abs(a[i]-b[i])-1;
		
		cout << (x ? "player-2" : "player-1") << endl;
	}
	return 0;
}