#include <bits/stdc++.h>
#include <climits>

using namespace std;

pair<int, int> findMinimum(vector <int>& v, int except){
    pair<int, int> mn = make_pair(INT_MAX, -1);
    for(int i=0;i<v.size();i++)
        if(i != except && v[i] < mn.first)
            mn = make_pair(v[i], i);
    return mn;
}
int twinArrays(vector <int> ar1, vector <int> ar2){
    // Complete this function
    pair<int, int> mn1 = findMinimum(ar1, -1), mn2 = findMinimum(ar2, -1);
    if(mn1.second != mn2.second)
        return mn1.first + mn2.first;
    pair<int, int> smn1 = findMinimum(ar1, mn2.second), smn2 = findMinimum(ar2, mn1.second);
    return min(mn1.first + smn2.first, mn2.first + smn1.first);
}


int main() {
    int n;
    cin >> n;
    vector<int> ar1(n);
    for(int ar1_i = 0; ar1_i < n; ar1_i++){
       cin >> ar1[ar1_i];
    }
    vector<int> ar2(n);
    for(int ar2_i = 0; ar2_i < n; ar2_i++){
       cin >> ar2[ar2_i];
    }
    int result = twinArrays(ar1, ar2);
    cout << result << endl;
    return 0;
}
