#include <bits/stdc++.h>
using namespace std;

int main(){
    long long H, W; cin >> H >> W;

    if(H == 1 || W == 1) {
        cout << 1 << endl;
    } else {
        if(H % 2 == 0) {
            cout << H / 2 * W << endl;
        } else if(H % 2 == 1) {
            if(W % 2 == 0) {
                cout << H / 2 * W + (W / 2) << endl;
            } else {
                cout << H / 2 * W + (W / 2 + 1) << endl;
            }
        }
    }
}