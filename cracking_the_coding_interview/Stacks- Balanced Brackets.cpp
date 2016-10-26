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

int pos;

bool is_balanced(string expression) {

    if (expression[pos] == ')' || expression[pos] == ']' || expression[pos] == '}')
         return false;
    char c = expression[pos++];
    while(pos < expression.length() && (expression[pos] == '{' || expression[pos] == '[' || expression[pos] == '('))
        if(!is_balanced(expression))
            return false;

    if(pos < expression.length() && ((c == '(' && expression[pos] == ')') || (c == '[' && expression[pos] == ']') || (c == '{' && expression[pos] == '}'))){
        pos++;
        return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        pos = 0;
        bool answer = true;
        while(pos < expression.length() && answer)
            answer &= is_balanced(expression);

        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
