#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Trang thai dich: 1 2 3 / 8 _ 4 / 7 6 5; 0 la o trong.
const string GOAL = "123804765";

void printBoard(const string& state) {
    for (int i = 0; i < 9; ++i) {
        cout << (state[i] == '0' ? '_' : state[i]) << ' ';
        if (i % 3 == 2) cout << '\n';
    }
}

// H(n): so tile sai vi tri, khong tinh o trong. H=0 tai dich.
int heuristic(const string& state) {
    int h = 0;
    for (int i = 0; i < 9; ++i)
        if (state[i] != '0' && state[i] != GOAL[i]) ++h;
    return h;
}

// Thu tu sinh ke tiep: len, xuong, trai, phai.
vector<string> getSuccessors(const string& state) {
    vector<string> successors;
    const int pos = static_cast<int>(state.find('0'));
    const int row = pos / 3, col = pos % 3;
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        const int r = row + dr[i], c = col + dc[i];
        if (r >= 0 && r < 3 && c >= 0 && c < 3) {
            string next = state;
            swap(next[pos], next[r * 3 + c]);
            successors.push_back(next);
        }
    }
    return successors;
}

bool isValidState(const string& state) {
    if (state.size() != 9) return false;
    bool seen[9] = {};
    for (char ch : state) {
        if (ch < '0' || ch > '8' || seen[ch - '0']) return false;
        seen[ch - '0'] = true;
    }
    return true;
}

int countInversions(const string& state) {
    int count = 0;
    for (int i = 0; i < 9; ++i) {
        if (state[i] == '0') continue;
        for (int j = i + 1; j < 9; ++j)
            if (state[j] != '0' && state[i] > state[j]) ++count;
    }
    return count;
}

bool isSolvable(const string& state) {
    return countInversions(state) % 2 == countInversions(GOAL) % 2;
}

void solve(const string& start) {
    string current = start;
    vector<string> path{current};

    while (true) {
        if (current == GOAL) {
            cout << "\nKET QUA: TIM THAY DICH\n";
            cout << "So buoc di: " << path.size() - 1
                 << " | So trang thai: " << path.size() << '\n';
            cout << "\nDUONG DI (H la so o sai vi tri):\n";
            for (size_t i = 0; i < path.size(); ++i) {
                cout << "Buoc " << i << " - H=" << heuristic(path[i]) << '\n';
                printBoard(path[i]);
                if (i + 1 < path.size()) cout << "  |\n";
            }
            return;
        }

        bool moved = false;
        const vector<string> neighbors = getSuccessors(current);
        const int currentH = heuristic(current);
        for (const string& next : neighbors) {
            if (heuristic(next) < currentH) {
                current = next;
                path.push_back(current);
                moved = true;
                break;
            }
        }
        if (!moved) {
            cout << "\nKET QUA: DUNG TAI CUC TRI CUC BO\n";
            cout << "Khong co lang gieng nao co H nho hon.\n";
            cout << "So buoc di: " << path.size() - 1
                 << " | H tai diem dung: " << heuristic(current) << '\n';
            cout << "\nTRANG THAI CUOI:\n";
            printBoard(current);
            return;
        }
    }
}

int main() {
    string start;
    bool seen[9] = {};
    cout << "====================================\n";
    cout << "  SIMPLE HILL CLIMBING - 8 PUZZLE\n";
    cout << "====================================\n";
    cout << "Nhap cac so tu 1 den 8 va o trong (0). Moi so chi xuat hien mot lan.\n\n";

    for (int i = 0; i < 9; ++i) {
        int x;
        cout << "Nhap o thu " << i + 1 << " (0-8): ";
        if (!(cin >> x)) {
            cout << "Loi: Du lieu phai la so nguyen!\n";
            return 1;
        }
        if (x < 0 || x > 8) {
            cout << "Loi: Chi duoc nhap so tu 0 den 8!\n";
            return 1;
        }
        if (seen[x]) {
            cout << "Loi: Gia tri " << x << " bi trung!\n";
            return 1;
        }
        seen[x] = true;
        start += char('0' + x);
    }

    cout << "\nTRANG THAI BAN DAU:\n";
    printBoard(start);

    if (!isSolvable(start)) {
        cout << "\nKET QUA: TRANG THAI KHONG THE GIAI\n";
        cout << "Trang thai ban dau:\n";
        printBoard(start);
        return 0;
    }
    solve(start);
    return 0;
}
