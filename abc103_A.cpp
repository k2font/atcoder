#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A(3); for(int i = 0; i < 3; ++i) cin >> A[i];

    sort(A.begin(), A.end());
    int cnt = 0;
    cnt += abs(A[1] - A[0]);
    cnt += abs(A[2] - A[1]);

    cout << cnt << endl;
}