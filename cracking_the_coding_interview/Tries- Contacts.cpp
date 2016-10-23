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

class Contacts{
    public:
    int n;
    Contacts* root[30];
};

Contacts *root = new Contacts();

void add(Contacts* node, string s){

    for(int i=0;i<s.size();i++){
        if(!node -> root[s[i]-'a'])
            node -> root[s[i]-'a'] = new Contacts();
        node -> n ++;
        node = node -> root[s[i]-'a'];
    }
    node -> n++;
}

int find(Contacts* node, string s){
    for(int i=0;i<s.size() && node; i++)
        node = node -> root[s[i]-'a'];

    if(!node) return 0;
    return node -> n;
}

int main(){
    int n;
    cin >> n;

    root -> n = 0;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add")
            add(root, contact);
        else
            cout << find(root, contact) << endl;
    }
    return 0;
}
