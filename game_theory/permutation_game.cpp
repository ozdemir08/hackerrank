#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int T,N;
map< vector<int> , bool > M;

bool play(vector<int> vec){
	if(M.find(vec) != M.end())
		return M[vec];
	
	bool flag = true;
	for(int i=1;i<vec.size();i++)
		if(vec[i] < vec[i-1])
			flag = false;
	
	if(flag) 
		return M[vec] = false;
		
	vector<int> v2;	
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec.size();j++)
			if(i != j)
				v2.push_back(vec[j]);
				
		if(!play(v2))
			return M[vec] = true;
		v2.clear();
	}
	
	return M[vec] = false;
}

int main(){
	int x;
	vector<int> V;
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> N;
		for(int j=0;j<N;j++){
			cin >> x;
			V.push_back(x);
		}
		cout << (play(V) ? "Alice" : "Bob") << endl;
		V.clear();
	}
	return 0;
}