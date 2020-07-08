#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int A, B, C, X; cin >> A >> B >> C >> X;
    int cnt = 0;
    for(int a = 0; a <= A; ++a) {
        for(int b = 0; b <= B; ++b) {
            for(int c = 0; c <= C; ++c) {
                int tmp = 500 * a + 100 * b + 50 * c;
                if(tmp == X) cnt++;
            }
        }
    }

    cout << cnt << endl;
}