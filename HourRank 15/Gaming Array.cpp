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
#define MAX 100005

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main(){
    int g;
    pair<int,int> arr[MAX];
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        cin >> n;
        for(int i=0; i < n; i++){
            scanf("%d", &arr[i].first);
            arr[i].second = i;
        }
        sort(arr, arr+n, cmp);
        int pos = n-1, turn = 0;
        for(int i=n-1;i>=0;i--)
            if(arr[i].second >= arr[pos].second)
                continue;
            else{
                turn++;
                pos = i;
            }

        if(turn % 2 == 1)
            cout << "ANDY" << endl;
        else
            cout << "BOB" << endl;

    }
    return 0;
}
