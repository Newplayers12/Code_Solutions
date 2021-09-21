# Ý tưởng
<!-- phần này có thể được thêm vào sau này nếu mà tụi em có thêm nhiều ý tưởng giải khác nha :> -->
Ta nhận xét từ việc:
- Nếu mà ta tách `A[i]` thành một tập hợp `S = {2^0, 2^1, 2^2, ..., 2^k, r}` với `2^k > r >= 0` thì ta sẽ thấy được rằng mọi tập con trong S đều có thể lập nên tổng thuộc `[1; A[i]]`. 
- Như vậy mỗi vật ta sẽ tách ra nó thành $O(log(max(A[i])))$ vật khác với khối lượng và giá trị tăng tương ứng.

Sau đó chúng ta có thể knapsack trên danh sách các đồ mới như thông thường.


# Độ phức tạp thời gian
- $O(N\times W\times log(max(A[i])))$
# Notes
