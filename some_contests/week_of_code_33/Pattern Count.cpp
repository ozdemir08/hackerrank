#include <bits/stdc++.h>

using namespace std;

int patternCount(string raw){
    // Complete this function
    if(raw == "")
        return 0;
    string s = "";
    s += raw[0];
    for(int i=1;i<raw.size();i++)
        if(!(raw[i] == '0' && raw[i-1] == '0')){
            s += raw[i];
        }
    int res = 0;
    for(int i=2;i<s.size();i++)
        if(s[i] == '1' && s[i-1] == '0' && s[i-2] == '1')
            res++;
    return res;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = patternCount(s);
        cout << result << endl;
    }
    return 0;
}
