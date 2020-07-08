#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int H1, W1, H2, W2; cin >> H1 >> W1 >> H2 >> W2;

    if(H1 == H2 || H1 == W2 || W1 == H2 || W1 == W2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}