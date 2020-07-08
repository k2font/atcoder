#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, K; cin >> A >> B >> C >> K;

    int max_n = max({A, B, C});
    string res;
    if(max_n == A) {
        res = "A";
    } else if(max_n == B) {
        res = "B";
    } else {
        res = "C";
    }

    int cnt = 1;
    while(cnt <= K) {
        max_n = max_n * 2;
        cnt++;
    }

    if(res == "A") {
        cout << B + C + max_n << endl;
    } else if(res == "B") {
        cout << A + C + max_n << endl;
    } else {
        cout << A + B + max_n << endl;
    }
}