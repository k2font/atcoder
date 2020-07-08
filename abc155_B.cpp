#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> A(N); for(int i = 0; i < N; ++i) cin >> A[i];

    bool flg = false;

    for(int i = 0; i < N; ++i) {
        if(A[i] % 2 == 0 && flg == false) {
            if(A[i] % 3 == 0 || A[i] % 5 == 0) {
            } else {
                cout << "DENIED" << endl;
                flg = true;
            }
        }
    }

    if(flg == false) {
        cout << "APPROVED" << endl;
    }
}