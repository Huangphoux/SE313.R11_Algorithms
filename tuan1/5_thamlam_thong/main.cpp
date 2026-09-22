#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Job {
    string id;
    int start;
    int finish;
};

int main() {
    int n;
    cout << "Nhap so luong cong viec: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Nhap ma cong viec, thoi gian bat dau va thoi gian ket thuc:\n";
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].id >> jobs[i].start >> jobs[i].finish;
    }

    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        if (a.finish != b.finish) {
            return a.finish < b.finish;
        }
        return a.start < b.start;
    });

    vector<Job> selectedJobs;
    int lastFinish = -1;

    for (const Job& job : jobs) {
        if (job.start >= lastFinish) {
            selectedJobs.push_back(job);
            lastFinish = job.finish;
        }
    }

    cout << "\nLich cong viec duoc chon:\n";
    for (const Job& job : selectedJobs) {
        cout << job.id << ": [" << job.start << ", " << job.finish << "]\n";
    }

    cout << "So cong viec nhieu nhat co the chon: " << selectedJobs.size() << '\n';

    return 0;
}
