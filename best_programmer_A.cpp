#include <bits/stdc++.h>
using namespace std;

int main(){
    int M, D; cin >> M >> D;
    
    int cnt = 0;
    for(int i = 1; i <= M; ++i) {
        for(int k = 20; k <= D; ++k) {
            int ten = k / 10;
            int one = k - (ten * 10);
            if(ten * one == i && ten >= 2 && one >= 2) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}