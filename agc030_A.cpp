#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    int cnt = 0;
    int maxrep = A + B + C; // ここでTLEになる。

    // 計算式求めればいいだけ。
    if((A + B + 1) > C) {
        cout << B + C << endl;
    } else {
        cout << A + 2 * B + 1 << endl;
    }
}