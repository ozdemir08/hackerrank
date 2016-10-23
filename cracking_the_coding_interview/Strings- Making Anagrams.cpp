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

int number_needed(string a, string b) {
    int letters_A[30] = {}, letters_B[30] = {};
    for(int i=0;i<a.length();i++)
        letters_A[a[i]-'a']++;
    for(int i=0;i<b.length();i++)
        letters_B[b[i]-'a']++;

    int mutual = 0;
    for(int i=0;i<30;i++)
        mutual += 2*min(letters_A[i], letters_B[i]);
    return a.length() + b.length() - mutual;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
