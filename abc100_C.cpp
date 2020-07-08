#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> a(N); for(int i = 0; i < N; ++i) cin >> a[i];

    int cnt = 0;
    while(true) {
        int ret = 0;
        for(int i = 0; i < N; ++i) {
            if(a[i] % 2 == 1) {
                ret++;
            } else {
                a[i] = a[i] / 2;
                cnt++;
                break;
            }
        }

        if(ret == N) {
            break;
        }
    }

    cout << cnt << endl;
}