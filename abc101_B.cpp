#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    string sn = to_string(N);
    int cnt = 0;
    for(int i = 0; i < sn.size(); ++i) {
        cnt += sn[i] - '0';
    }

    if(N % cnt == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}