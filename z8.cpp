#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canPlace(int dist, int k, const vector<int>& vec) {
    int count = 1;
    int last_placed = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] - last_placed >= dist) {
            count++;
            last_placed = vec[i];
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int left = 1;
    int right = vec.back() - vec[0];
    int ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlace(mid, k, vec)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans;
}