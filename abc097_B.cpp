#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int X; cin >> X;

    int res = 0;
    for(int i = 1; i <= 100; ++i) {
        for(int k = 2; k <= 100; ++k) {
            for(int m = 1; m <= X; ++m) {
                int tmp = pow(i, k);
                if(tmp == m) {
                    if(res < tmp) {
                        res = tmp;
                    }
                }
            }
        }
    }

    cout << res << endl;
}