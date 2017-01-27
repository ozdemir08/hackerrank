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

#define max_n 300

using namespace std;

long long make_change(vector<int> coins, int money) {
    long long arr[max_n] = {1};
    for(int i = 0;i<coins.size();i++)
        for(int j = 0; j+coins[i] < max_n; j++)
            arr[j + coins[i]] += (arr[j]?1:0) * arr[j];
    return arr[money];
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n) << endl;
    return 0;
}
