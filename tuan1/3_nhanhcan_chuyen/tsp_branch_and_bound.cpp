#include <iostream>
#include <climits>
using namespace std;

int n, cmin;
int c[20][20];          // c[i][j]: chi phí đi từ i đến j
int x[20], best[20];    // hành trình đang xét / hành trình tốt nhất
bool daDi[20];
int lowcost = INT_MAX;  // kỷ lục hiện tại

void Try(int i, int g) {
    for (int j = 2; j <= n; j++) {
        if (daDi[j]) continue;

        x[i] = j;
        int gMoi = g + c[x[i - 1]][j];
        int cost = gMoi + (n - i + 1) * cmin;   // cận dưới
        if (cost >= lowcost) continue;          // cắt nhánh

        daDi[j] = true;
        if (i == n) {
            int tong = gMoi + c[x[n]][1];       // quay về thành phố 1
            if (tong < lowcost) {
                lowcost = tong;
                for (int k = 1; k <= n; k++) best[k] = x[k];
            }
        } else {
            Try(i + 1, gMoi);
        }
        daDi[j] = false;                        // quay lui
    }
}

int main() {
    cout << "Nhập số thành phố n: ";
    cin >> n;
    cout << "Nhập ma trận chi phí " << n << "x" << n << ":\n";
    cmin = INT_MAX;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (i != j && c[i][j] < cmin) cmin = c[i][j];
        }

    x[1] = 1;
    daDi[1] = true;
    Try(2, 0);

    cout << "Hành trình tối ưu: ";
    for (int i = 1; i <= n; i++) cout << best[i] << " -> ";
    cout << "1\nChi phí nhỏ nhất: " << lowcost << endl;
    return 0;
}