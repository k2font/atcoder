#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> D(3);
    cin >> D[0];
    cin >> D[1];
    cin >> D[2];

    sort(D.begin(), D.end(), greater<int>());
    string max_s = to_string(D[0]) + to_string(D[1]);
    cout << stoi(max_s) + D[2] << endl;
}