#include <bits/stdc++.h>
using namespace std;

int main(){
    string S = "Kamenrider";
    S.replace(1, 3, "A");
    cout << S << endl;

    vector<int> A = {1, 2, 4, 2, 1, 6, 5};
    replace(A.begin(), A.end(), 2, 20);
    for(int i = 0; i < A.size(); ++i) cout << A[i] << " ";
}