#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}
int char_to_int(char val) {
    return val - '0';
}

int main() {
    string s; cin >> s;

    if(char_to_int(s[0]) + char_to_int(s[1]) + char_to_int(s[2]) + char_to_int(s[3]) == 7 ) {
        cout << s[0] << '+' << s[1] << '+' << s[2] << '+' << s[3] << "=7" << endl;
    } else if(char_to_int(s[0]) + char_to_int(s[1]) + char_to_int(s[2]) - char_to_int(s[3]) == 7 ) {
        cout << s[0] <<  '+' <<  s[1] <<  '+' <<  s[2] <<  '-' <<  s[3] <<  "=7" << endl;
    } else if(char_to_int(s[0]) + char_to_int(s[1]) - char_to_int(s[2]) + char_to_int(s[3]) == 7 ) {
        cout << s[0] <<  '+' <<  s[1] <<  '-' <<  s[2] <<  '+' <<  s[3] <<  "=7" << endl;
    } else if(char_to_int(s[0]) + char_to_int(s[1]) - char_to_int(s[2]) - char_to_int(s[3]) == 7 ) {
        cout << s[0] <<  '+' <<  s[1] <<  '-' <<  s[2] <<  '-' <<  s[3] <<  "=7" << endl;
    } else if(char_to_int(s[0]) - char_to_int(s[1]) + char_to_int(s[2]) + char_to_int(s[3]) == 7 ) {
        cout << s[0] <<  '-' <<  s[1] <<  '+' <<  s[2] <<  '+' <<  s[3] <<  "=7" << endl;
    } else if(char_to_int(s[0]) - char_to_int(s[1]) + char_to_int(s[2]) - char_to_int(s[3]) == 7 ) {
        cout << s[0] <<  '-' <<  s[1] <<  '+' <<  s[2] <<  '-' <<  s[3] <<  "=7" << endl;
    } else if(char_to_int(s[0]) - char_to_int(s[1]) - char_to_int(s[2]) + char_to_int(s[3]) == 7 ) {
        cout << s[0] <<  '-' <<  s[1] <<  '-' <<  s[2] <<  '+' <<  s[3] <<  "=7" << endl;
    } else if(char_to_int(s[0]) - char_to_int(s[1]) - char_to_int(s[2]) - char_to_int(s[3]) == 7 ) {
        cout << s[0] <<  '-' <<  s[1] <<  '-' <<  s[2] <<  '-' <<  s[3] <<  "=7" << endl;
    }
}