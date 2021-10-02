# Ý tưởng
<!-- phần này có thể được thêm vào sau này nếu mà tụi em có thêm nhiều ý tưởng giải khác nha :> -->

Đề bài đã cho mình một dãy tăng dần và đang muốn tìm ra chênh lệch của hai phần tử liên tiếp có chênh lệch lớn nhất có thể sau khi xóa đi một phần tử bất kì.
$\rightarrow$ Sau khi xóa đi phần tử thứ $i$ thì chênh lệch mới sẽ là giữa hai phần tử thứ $i+1$ và $i-1$. Như vậy bài toán thành là kiếm chênh lệch lớn nhất giữa hai phần tử cách nhau đúng $1$ phần tử.

# Độ phức tạp thời gian
$O(N)$ với $N$ là số lượng phần tử của mảng.

# Notes
Thử nghĩ xem nếu bài toán này cho một dãy ngẫu nhiên và hỏi là chênh lệch nhỏ nhất giữa hai phần tử bất kì thì tụi mình sẽ làm như thế nào?
