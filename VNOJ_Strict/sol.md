# Solution

### Nhận xét: 

$B \subset [1,n]$ mà $A_{B_1},A_{B_2},...,A_{B_n}$ tạo thành dãy tăng ngặt &rarr; đếm số dạy tăng nghiêm ngặt trong $A$ cũng là đếm số lượng tập hợp con $B$ có các giá trị đôi một khác nhau trong $A$.

Vì giá trị của $A$ là bất kì mà yêu cầu bài toán là số lượng dãy tăng &rarr; ta nén các phần tử của $A$ thành các giá trị thuộc $[1,n]$ mà vẫn giữ nguyên quan hệ lớn bé để dễ xử lý hơn.

### Giải:
Gọi $f[i]$ là số dãy tăng nghiêm ngặt có giá trị cuối cùng là $i$, $cnt[i]$ là số lượng phần tử giống nhau trong $A$.

$$
f[i] = \begin{cases} f[i-1], &\text{Nếu không chọn vật i}\\ f[i-1] * cnt[i], &\text{Nếu chọn vật i}
\end{cases}
$$

và $f[0] = 1$ vì số dãy tăng ngặt có $0$ đứng cuối là $1$ là dãy rỗng.
<center>

&rarr; $f[i] = f[i-1] + f[i-1] \times cnt[i] = f[i-1]\times (cnt[i] + 1)$

</center>

Đáp án chính là $f[n]$ sau khi duyệt qua mọi $i \in [1,n]$

### Note:
Nhớ chia lấy dư cho $10^9+7$.