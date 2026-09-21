# Bài toán Cái túi - Quy hoạch động

## 1. Mô tả

Cho n đồ vật, mỗi đồ vật có trọng lượng và giá trị.
Túi có sức chứa tối đa W. Tìm tổng giá trị lớn nhất
có thể đạt được khi mỗi đồ vật chỉ được chọn tối đa một lần.

## 2. Phương pháp

Sử dụng chiến lược Quy hoạch động (Dynamic Programming).

dp[j] là giá trị lớn nhất có thể đạt được với sức chứa j.

Công thức:

dp[j] = max(dp[j], dp[j - w[i]] + v[i])

Duyệt j từ W xuống w[i] để mỗi đồ vật chỉ được chọn một lần.

## 3. Độ phức tạp

- Thời gian: O(nW)
- Bộ nhớ: O(W)

## 4. Công nghệ

- C++
- MinGW/GCC
- Visual Studio Code