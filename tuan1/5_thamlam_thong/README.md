# Bài toán Lập lịch công việc - Tham lam

## 1. Mô tả bài toán

Cho `n` công việc. Mỗi công việc có:

- Mã công việc
- Deadline: thời hạn hoàn thành
- Lợi nhuận: giá trị nhận được nếu hoàn thành công việc trước hoặc đúng deadline

Giả sử mỗi công việc cần đúng 1 đơn vị thời gian để thực hiện và tại một thời điểm chỉ làm được 1 công việc.
Yêu cầu: chọn và sắp xếp các công việc sao cho tổng lợi nhuận đạt được là lớn nhất.

## 2. Phương pháp sử dụng

Sử dụng chiến lược Tham lam (Greedy).

Ý tưởng chính:

1. Sắp xếp các công việc theo lợi nhuận giảm dần.
2. Với mỗi công việc trong danh sách đã sắp xếp, đặt công việc vào vị trí trễ nhất còn trống nhưng không vượt quá deadline.
3. Nếu không còn vị trí phù hợp, bỏ qua công việc đó.

Cách chọn này giúp ưu tiên các công việc có lợi nhuận cao trước, đồng thời đặt chúng càng muộn càng tốt để giữ các vị trí sớm hơn cho những công việc có deadline ngắn.

## 3. Dữ liệu vào

Chương trình nhập:

- Số lượng công việc `n`
- Với mỗi công việc: mã công việc, deadline, lợi nhuận

Ví dụ:

```text
Nhap so luong cong viec: 5
Nhap ma cong viec, deadline va loi nhuan:
J1 2 100
J2 1 19
J3 2 27
J4 1 25
J5 3 15
```

## 4. Kết quả

Chương trình in ra lịch công việc được chọn theo từng thời điểm, số công việc được chọn và tổng lợi nhuận.

Với ví dụ trên, một kết quả có thể là:

```text
Lich cong viec duoc chon:
Thoi diem 1: J3
Thoi diem 2: J1
Thoi diem 3: J5
So cong viec duoc chon: 3
Tong loi nhuan lon nhat theo chien luoc tham lam: 142
```

## 5. Giải thích thuật toán

Sau khi sắp xếp theo lợi nhuận giảm dần, thuật toán xét công việc có giá trị cao trước.

Với mỗi công việc, thuật toán không đặt ngay vào vị trí sớm nhất mà tìm vị trí trễ nhất còn trống trước deadline. Nhờ vậy, các thời điểm sớm hơn vẫn có thể dành cho những công việc khác có deadline gấp hơn.

Ví dụ, nếu một công việc có deadline là 3, thuật toán sẽ thử đặt vào thời điểm 3 trước. Nếu thời điểm 3 đã có việc, thuật toán thử thời điểm 2, rồi thời điểm 1.

## 6. Độ phức tạp

Gọi:

- `n` là số lượng công việc
- `d` là deadline lớn nhất

Độ phức tạp:

- Sắp xếp công việc: `O(n log n)`
- Xếp lịch: `O(n * d)`
- Tổng thời gian: `O(n log n + n * d)`
- Bộ nhớ: `O(d)`