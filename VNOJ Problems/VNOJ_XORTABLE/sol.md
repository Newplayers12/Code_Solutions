# Ý tưởng
<!-- phần này có thể được thêm vào sau này nếu mà tụi em có thêm nhiều ý tưởng giải khác nha :> -->

Đề đã cho ta hàng đầu tiên trong bảng ma trận như đề.
Ta áp dụng kiến thức bitwise phép XOR là `a XOR a = 0`
Như vậy nếu đề cho ta `Arr[i][u] = A[i] XOR A[u]` thì ta có thể thử 
```
Arr[i][u] XOR Arr[i][v] = A[i] XOR A[u] XOR A[i] XOR A[v] 
= A[u] XOR A[v] XOR 0 = A[u] XOR A[v] = Arr[u][v] 
```

Vậy ta chỉ cần chạy hai vòng for là sinh ngược lại ma trận.

# Độ phức tạp thời gian
- $O(N^2)$ với $N$ là độ dài mảng A đề cho.
# Notes
