# Solution to Infinity Table
Gọi $f(n)$ là số chữ số được điền vào tất cả các ô trong ô vuông có kích thước là $n$.
$$
    f(n) = n^2 
$$

Gọi $square[i]$ là bình phương của $i$ và $n$ là kích thước ô vuông nhỏ nhất có số $K$.
Ta dễ dàng có được $n$ bằng cách tìm kiếm nhị phân trên mảng $square$.

Nhận thấy, số $K$ chỉ có thể xuất hiện ở bìa của ô vuông kích thước $n$ nên tọa độ của $K$ chỉ có 2 trường hợp
$$
    (x_k,y_k) = \begin{cases} 
                (n,2\times n - k + square[n-1]),& \text {if }{(k - square[n-1]  > n)}\\ 
                (k - square[n-1], n),& \text{    } {otherwise} \end{cases}
$$


Độ phức tạp thuật toán sẽ là $O(Q.Log(K))$.