# Solution
Kiến thức cần có : cấu trúc dữ liệu DisjoinSet Union, Cây Khung.

Dễ nhận thấy đây là 1 bài cây khung cơ bản.

Ta thấy xây dựng ống dẫn nước là tương tự nối hai đỉnh trong đồ thị. Xây dựng giếng thì ta sẽ tạo một đỉnh phụ và nói rằng xây dựng giếng sẽ đồng nghĩa là dựng ống từ đỉnh phụ đến đỉnh xây giếng đó. Cuối cùng, nó thành bài toán là tìm cây khung nhỏ nhất trong $N + 1$ đỉnh ($N$ đỉnh đề cho và một đỉnh phụ).

Độ phức tạp là $O(E\times log(E))$