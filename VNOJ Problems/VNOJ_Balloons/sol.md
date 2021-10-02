# Ý tưởng
<!-- phần này có thể được thêm vào sau này nếu mà tụi em có thêm nhiều ý tưởng giải khác nha :> -->


Thật ra thì bài toán này chỉ là một bài toán QHĐ bình thường thôi <(").

Ta gọi hàm $dp[u][j]$ là tổng lớn nhất của dãy đã chọn $u$ vật và vật cuối cùng được chọn là vật thứ $j$. Như vậy ta có công thức như sau:

$$dp[u][j] = u \times A[j] + \max(dp[u-1][v] | \forall v, j - M \le v \le j - 1)$$

Đáp án cuối cùng chính là $\max(dp[K][i]) \forall i \in [K; N]$

Nhưng mà thực tế thì không đơn giản như vậy, do là mình thấy được độ phức tạp của việc duyệt như trên thông thường sẽ là $O(N\times M \times K)$ như vậy sẽ bị TLE.

Ta có thể cải tiến nó hơn ở phần tìm max do là chúng ta đang tìm chính là max trên một đoạn tịnh tiến, như vậy có thể áp dụng deque để quản lý nhanh trong $O(1)$. Như vậy độ phức sẽ giảm xuống còn là $O(N\times K)$.


# Độ phức tạp thời gian
- $O(N \times M \times K)$ nếu không có cải tiến.
- $O(N \times K)$ khi có cải tiến bằng deque trên đoạn tịnh tiến.

# Notes
- Theo như anh Thoại và Đạt nói thì là bài toán này dùng mảng hai chiều $O(N \times K)$ vẫn không TLE. Nhưng trong code của anh để thì là cải tiến hơn nữa về không gian bộ nhớ nên là $O(N)$.
- Có gì muốn xem thử code anh Thoại thì nói cũng được.
