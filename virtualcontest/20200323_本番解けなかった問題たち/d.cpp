#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int A, B; cin >> A >> B;

    int a, b;
    int result;
    for(int i = 1; i < 10000; ++i) {
        a = i * 0.08;
        b = i * 0.1;

        if(a == A && b == B) {
            result = i;
            break;
        }

        if(i == 9999) {
            result = -1;
        }
    }

    cout << result << endl;
}