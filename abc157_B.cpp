#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> A(3, vector<int>(3));
    for(int i = 0; i < 3; ++i) {
        for(int k = 0; k < 3; ++k) {
            cin >> A[i][k];
        }
    }

    int N; cin >> N;
    vector<int> b(N); for(int i = 0; i < N; ++i) cin >> b[i];

    for(int m = 0; m < N; ++m) {
        for(int i = 0; i < 3; ++i) {
            for(int k = 0; k < 3; ++k) {
                if(b[m] == A[i][k]) {
                    A[i][k] = A[i][k] - b[m];
                }
            }
        }
    }

    if((A[0][0] == 0 && A[1][1] == 0 && A[2][2] == 0)
    || (A[2][0] == 0 && A[1][1] == 0 && A[0][2] == 0)

    || (A[0][0] == 0 && A[0][1] == 0 && A[0][2] == 0)
    || (A[1][0] == 0 && A[1][1] == 0 && A[1][2] == 0)
    || (A[2][0] == 0 && A[2][1] == 0 && A[2][2] == 0)

    || (A[0][0] == 0 && A[1][0] == 0 && A[2][0] == 0)
    || (A[0][1] == 0 && A[1][1] == 0 && A[2][1] == 0)
    || (A[0][2] == 0 && A[1][2] == 0 && A[2][2] == 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}