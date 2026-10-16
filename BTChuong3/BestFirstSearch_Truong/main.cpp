
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Trang thai dich:
// 1 2 3
// 8 _ 4
// 7 6 5
// Ky hieu 0 dai dien cho o trong
const string GOAL = "123804765";

struct Node {
    string state;
    int g;  // So lan di chuyen tile
    int h;  // So tile sai vi tri
    int f;  // F = G + H
};

struct Compare {
    bool operator()(const Node& a, const Node& b) const {
        if (a.f != b.f)
            return a.f > b.f;
        return a.h > b.h;
    }
};

// In ban co 3x3
void printBoard(const string& state) {
    for (int i = 0; i < 9; i++) {
        if (state[i] == '0')
            cout << "_ ";
        else
            cout << state[i] << " ";

        if (i % 3 == 2)
            cout << '\n';
    }
}

// H(n): dem so tile sai vi tri, khong tinh o trong
int heuristic(const string& state) {
    int h = 0;

    for (int i = 0; i < 9; i++) {
        if (state[i] != '0' && state[i] != GOAL[i])
            h++;
    }

    return h;
}

// Dem so cap nghich the, bo qua o trong
int countInversions(const string& state) {
    int count = 0;

    for (int i = 0; i < 9; i++) {
        if (state[i] == '0')
            continue;

        for (int j = i + 1; j < 9; j++) {
            if (state[j] != '0' && state[i] > state[j])
                count++;
        }
    }

    return count;
}

// Kiem tra kha nang giai voi ban co 3x3
bool isSolvable(const string& start) {
    return countInversions(start) % 2 ==
           countInversions(GOAL) % 2;
}

// Sinh cac trang thai ke tiep bang cach di chuyen
// mot tile ke voi o trong
vector<string> getSuccessors(const string& state) {
    vector<string> successors;

    int pos = state.find('0');
    int row = pos / 3;
    int col = pos % 3;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if (newRow >= 0 && newRow < 3 &&
            newCol >= 0 && newCol < 3) {

            int newPos = newRow * 3 + newCol;
            string nextState = state;

            swap(nextState[pos], nextState[newPos]);
            successors.push_back(nextState);
        }
    }

    return successors;
}

// In OPEN, chi in cac trang thai con hop le
void printOpen(
    priority_queue<Node, vector<Node>, Compare> open,
    const unordered_map<string, int>& bestG,
    const unordered_set<string>& close
) {
    cout << "\nOPEN:\n";
    bool empty = true;

    while (!open.empty()) {
        Node n = open.top();
        open.pop();

        auto it = bestG.find(n.state);

        if (it != bestG.end() &&
            n.g == it->second &&
            !close.count(n.state)) {

            cout << "  ";
            printBoard(n.state);
            cout << "  G=" << n.g
                 << " H=" << n.h
                 << " F=" << n.f << "\n";
            empty = false;
        }
    }

    if (empty)
        cout << "  Rong\n";
}

// In CLOSE
void printClose(const unordered_set<string>& close) {
    cout << "\nCLOSE (" << close.size()
         << " trang thai):\n";

    for (const string& state : close) {
        cout << "  ";
        printBoard(state);
        cout << '\n';
    }
}

// Thuat toan tim kiem voi F(n) = G(n) + H(n)
void solve(const string& start) {
    priority_queue<Node, vector<Node>, Compare> open;
    unordered_set<string> close;
    unordered_map<string, int> bestG;
    unordered_map<string, string> parent;

    int startH = heuristic(start);

    open.push({start, 0, startH, startH});
    bestG[start] = 0;

    int expanded = 0;

    cout << "\n========== BAT DAU TIM KIEM ==========\n";

    while (!open.empty()) {
        Node current = open.top();
        open.pop();

        // Bo qua ban ghi cu neu da co duong di tot hon
        if (bestG[current.state] != current.g)
            continue;

        if (close.count(current.state))
            continue;

        close.insert(current.state);
        expanded++;

        cout << "\nMo rong nut " << expanded << ":\n";
        printBoard(current.state);

        cout << "G(n) = " << current.g
             << ", H(n) = " << current.h
             << ", F(n) = " << current.f << '\n';

        // Neu dat trang thai dich
        if (current.state == GOAL) {
            vector<string> path;
            string state = GOAL;

            while (state != start) {
                path.push_back(state);
                state = parent.at(state);
            }

            path.push_back(start);
            reverse(path.begin(), path.end());

            cout << "\n========== TIM THAY LOI GIAI ==========\n";
            cout << "So lan di chuyen tile: "
                 << path.size() - 1 << '\n';
            cout << "So nut da mo rong: " << expanded << '\n';

            cout << "\nDUONG DI TU DAU DEN DICH:\n";

            for (int i = 0; i < (int)path.size(); i++) {
                cout << "\nBuoc " << i << ":\n";
                printBoard(path[i]);

                int g = i;
                int h = heuristic(path[i]);

                cout << "G(n) = " << g
                     << ", H(n) = " << h
                     << ", F(n) = " << g + h << '\n';
            }

            return;
        }

        vector<string> successors =
            getSuccessors(current.state);

        for (const string& next : successors) {
            int newG = current.g + 1;

            auto it = bestG.find(next);

            if (it == bestG.end() || newG < it->second) {
                bestG[next] = newG;
                parent[next] = current.state;

                // Cho phep xet lai neu tim duoc duong tot hon
                close.erase(next);

                int h = heuristic(next);
                int f = newG + h;

                open.push({next, newG, h, f});
            }
        }

        printOpen(open, bestG, close);
        printClose(close);
    }

    cout << "\nKhong tim thay loi giai.\n";
}

int main() {
    string start = "";
    bool seen[10] = {false};

    cout << "====================================\n";
    cout << "       BEST FIRST SEARCH - 8 PUZZLE\n";
    cout << "====================================\n";
    cout << "Nhap cac so tu 1 den 8 va o trong.\n";
    cout << "Nhap 0 de dai dien cho o trong.\n";
    cout << "Moi gia tri chi duoc xuat hien mot lan.\n\n";

    for (int i = 0; i < 9; i++) {
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
            cout << "Loi: Gia tri " << x
                 << " bi trung!\n";
            return 1;
        }

        seen[x] = true;
        start += char('0' + x);
    }

    cout << "\nTRANG THAI BAN DAU:\n";
    printBoard(start);

    cout << "\nTRANG THAI DICH:\n";
    printBoard(GOAL);

    if (!isSolvable(start)) {
        cout << "\nTrang thai nay khong the di den dich.\n";
        cout << "Hay thu mot trang thai ban dau khac.\n";
        return 0;
    }

    cout << "\nTrang thai co the giai. Bat dau tim kiem...\n";
    solve(start);

    return 0;
}
