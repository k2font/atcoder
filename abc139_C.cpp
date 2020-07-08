#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; ++i) cin >> H[i];

    int res = 0;
    int cnt = 0;
    for(int i = 1; i < N; ++i) {
        if(H[i - 1] >= H[i]) {
            cnt++;
        } else {
            cnt = 0;
        }

        if(res < cnt) {
            res = cnt;
        }
    }

    cout << res << endl;
}