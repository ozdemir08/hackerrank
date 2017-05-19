#include <iostream>
#include <vector>

using namespace std;

int getMaxMonsters(int n, int hit, int t, vector < int > h){
	int killedMonster = 0;
    sort(h.begin(), h.end());
    while(killedMonster < n && t >= (h[killedMonster]+hit-1)/hit){
    	t -= (h[killedMonster]+hit-1)/hit;
    	killedMonster++;
    }
    return killedMonster;
}

int main() {
    int n;
    int hit;
    int t;
    cin >> n >> hit >> t;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    int result = getMaxMonsters(n, hit, t, h);
    cout << result << endl;
    return 0;
}
