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

vector<int> v1; //smaller half, max heap
vector<int> v2; //greater half, min heap

bool cmp1(int a, int b){return a < b;}
bool cmp2(int a, int b){return a > b;}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }

    make_heap(v1.begin(), v1.end(), cmp1);
    make_heap(v2.begin(), v2.end(), cmp2);

    for(int i=0;i<n;i++){

        if(!i || v1[0] >= a[i]){
            v1.push_back(a[i]);
            push_heap(v1.begin(), v1.end(), cmp1);
            if(v1.size() > v2.size() + 1){
                int x = v1[0];
                pop_heap(v1.begin(), v1.end(), cmp1);
                v1.pop_back();

                v2.push_back(x);
                push_heap(v2.begin(), v2.end(), cmp2);
            }
        }
        else{
            v2.push_back(a[i]);
            push_heap(v2.begin(), v2.end(), cmp2);

            if(v2.size() > v1.size() + 1){
                int x = v2[0];
                pop_heap(v2.begin(), v2.end(), cmp2);
                v2.pop_back();

                v1.push_back(x);
                push_heap(v1.begin(), v1.end(), cmp1);
            }
        }
        float result;

        if(v1.size() > v2.size())   result = v1[0];
        else if(v2.size() > v1.size()) result = v2[0];
        else result = (v1[0] + v2[0]) / 2.0;

        printf("%.1f\n", result);
    }

    return 0;
}
