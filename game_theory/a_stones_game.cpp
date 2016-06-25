#include <iostream>
#include <cstdio>

using namespace std;

int main(){

	int N, res=0;
	cin >> N;
	for(int i=1;i<=N;i++)
		res ^= i;
	
	cout << res << endl;
	
}
