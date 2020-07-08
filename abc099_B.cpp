#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;

    int cnt = 1;
    while(true) {
        int res = 0.5 * cnt * (cnt + 1);
        int res2 = 0.5 * (cnt + 1) * (cnt + 2);
        if(res - a == res2 - b) {
            cout << res - a << endl;
            break;
        }
        cnt++;
    }
}