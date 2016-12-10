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

using namespace std;

int dp[40] = {0, 1, 2, 4};

int main(){
    int s;
    cin >> s;

    for(int i = 4;i<40;i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
