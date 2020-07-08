#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    while(true) {
        if(to_string(N)[0] == to_string(N)[1] && to_string(N)[1] == to_string(N)[2]) {
            cout << N << endl;
            break;
        } else {
            N++;
        }
    }
}