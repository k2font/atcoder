#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int H, W; cin >> H >> W;
    vector<string> a(H); REP(i, H) cin >> a[i];

    for(int i = 0; i < H + 2; ++i) {
        if(i == 0 || i == H + 1) {
            for(int k = 0; k < W + 2; ++k) {
                cout << "#";
            }
            cout << endl;
        } else {
            cout << "#" << a[i - 1] << "#" << endl;
        }
    }
}