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

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> heap, rheap;
    make_heap(heap.begin(), heap.end());
    make_heap(rheap.begin(), rheap.end(), cmp);

    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
       heap.push_back(a[a_i]);
       rheap.push_back(a[a_i]);
       push_heap(heap.begin(), heap.end());
       push_heap(rheap.begin(), rheap.end(), cmp);
       cout << heap[0] << ' ' << rheap[0] << endl;
       cout << (heap[0] + rheap[0]) / 2.0 << endl << endl;
    }


    return 0;
}
