# Ý tưởng
<!-- phần này có thể được thêm vào sau này nếu mà tụi em có thêm nhiều ý tưởng giải khác nha :> -->


Thật ra thì bài toán này chỉ là một bài toán QHĐ bình thường thôi <(").

Ta gọi một hàm $dp[u][j] = u \times A[j] + \max(dp[u-1][v] | \forall v, j - M \le v \le j - 1)$

Đáp án cuối cùng chính là $\max(dp[K][i]) \forall i \in [K; N]$

Nhưng mà thực tế thì không đơn giản như vậy, do là mình thấy được độ phức tạp của việc duyệt như trên thông thường sẽ là $O(N\times M \times K)$ như vậy sẽ bị TLE.

Ta có thể cải tiến nó hơn ở phần tìm max do là chúng ta đang tìm chính là max trên một đoạn tịnh tiến, như vậy có thể áp dụng deque để quản lý nhanh trong $O(1)$. Như vậy độ phức sẽ giảm xuống còn là $O(N\times K)$.



# Solution
<!-- sau đó thì ghi thêm vào trong đây -->

# Độ phức tạp thời gian

# Notes
