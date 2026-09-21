#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, W;
    cout << "Nhap so luong do vat (n) va suc chua cua tui (W): \n";
    cin >> n >> W;

    vector<int> w(n);
    vector<int> v(n);

    cout << "Nhap trong luong va gia tri cua tung do vat:\n";
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    // dp[j] lưu giá trị lớn nhất với trọng lượng túi là j
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // Duyệt ngược từ W về w[i]
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << "Gia tri lon nhat co the dat duoc: " << dp[W] << "\n";

    return 0;
}
