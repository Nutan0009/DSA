#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int n, vector<int>& arr) {
    vector<int> dp; 
    for (int x : arr) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }
    return dp.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(n, arr) << endl;
    return 0;
}
