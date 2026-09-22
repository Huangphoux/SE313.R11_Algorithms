
---

### 2. `sinh_chinh_hop/README.md`

```markdown
# Bài toán Sinh chỉnh hợp chập k của n - Phương pháp sinh

## 1. Mô tả bài toán

Cho `n` phần tử và cần chọn `k` phần tử từ `n` phần tử đó, có xét đến thứ tự.

Yêu cầu: sinh ra tất cả các chỉnh hợp chập `k` của `n` phần tử bằng phương pháp sinh.

Ví dụ với `n = 3`, `k = 2`, các chỉnh hợp cần sinh là:

```text
12
13
21
23
31
32
Tổng số chỉnh hợp là:
A(3,2) = 3! / (3-2)! = 6
2. Phương pháp sử dụng
Sử dụng phương pháp sinh.
Ý tưởng chính:
Khởi tạo cấu hình đầu tiên theo thứ tự tăng dần.
Tìm cấu hình tiếp theo bằng cách thay đổi các phần tử theo thứ tự.
Đảm bảo các phần tử trong một chỉnh hợp không trùng nhau.
Tiếp tục sinh cho đến khi đạt cấu hình cuối cùng.
Do chỉnh hợp có xét đến thứ tự nên hai dãy có cùng phần tử nhưng khác vị trí được xem là hai chỉnh hợp khác nhau.
Ví dụ:
12
21
là hai chỉnh hợp khác nhau.
3. Dữ liệu vào
Chương trình nhập:
n: số lượng phần tử.
k: số lượng phần tử được chọn.
Ví dụ:
nhap so luong n
3
nhap so luong k
2
4. Kết quả
Chương trình in ra tất cả các chỉnh hợp chập k của n phần tử.
Với n = 3, k = 2, kết quả:
12
13
21
23
31
32
Tổng số chỉnh hợp được sinh ra là:
A(3,2) = 6
5. Giải thích thuật toán
Chỉnh hợp khác với tổ hợp ở chỗ thứ tự của các phần tử có ý nghĩa.
Với n = 3, k = 2, ta có:
12
13
21
23
31
32
Ví dụ:
12
và:
21
là hai cấu hình khác nhau.
Thuật toán bắt đầu từ cấu hình đầu tiên và lần lượt tìm cấu hình kế tiếp bằng cách thay đổi vị trí phù hợp.
Khi một vị trí không thể tăng thêm, thuật toán quay về vị trí trước đó để tiếp tục tìm cấu hình mới.
Trong quá trình sinh, các phần tử trong một cấu hình phải khác nhau.
Khi đã sinh đến cấu hình cuối cùng thì thuật toán kết thúc.
6. Độ phức tạp
Gọi:
n là số lượng phần tử.
k là số phần tử được chọn.
Số lượng chỉnh hợp được sinh ra là:
A(n,k) = n! / (n-k)!
Mỗi cấu hình có k phần tử.
Do đó:
Số cấu hình: O(A(n,k))
Thời gian: O(k * A(n,k))
Bộ nhớ: O(k)
