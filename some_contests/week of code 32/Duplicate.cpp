#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    string s = "0";
    while(s.size() < 1000){
        string t = "";
        for(int i=0;i<s.size();i++)
            t += 1-(s[i]-'0')+'0';
        s += t;
    }
    for(int a0 = 0; a0 < q; a0++){
        int x;
        cin >> x;
        cout << s[x] << endl;
    }
    return 0;
}
