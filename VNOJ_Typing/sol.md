# Ý tưởng
<!-- phần này có thể được thêm vào sau này nếu mà tụi em có thêm nhiều ý tưởng giải khác nha :> -->

- Ta xét trước một xâu như sau: `aaaa`
- Ta đặt câu hỏi rằng là có nhiêu xâu con có thể tạo nên xâu `aaaa`.
    - Theo đề bài, `a` có thể thành -> `aaaa`.
    - Tương tự `aa`, `aaa` cũng vậy, và đồng thời chính nó là `aaaa` (trong TH là không có typo).
    - Vậy với xâu `aaaa` thì sẽ có 4 xâu có thể tạo nên nó.
- Tổng quát lên thì ta thấy được với mỗi xâu $S$ gồm một kí tự liên tiếp nhau thì sẽ có $|S|$ xâu tạo nên xâu $S$ đó.

- Như vậy mỗi xâu gồm các kí tự liên tiếp như `aaabbbcccaa`, Ta sẽ tách ra thành 4 xâu con như sau `[aaa, bbb, ccc, aa]`. Từ đó tính số xâu có thể lập nên cho mỗi xâu con.
- Do mỗi xâu có lập nên của mỗi xâu con khi hợp lại sẽ tạo thành một xâu `S'` khác nhau. Và số lượng xâu `S'` đó chính là số ta đang muốn tìm. Áp dụng quy tắc nhân thì ta sẽ có được số xâu `S'` sẽ là bằng tích của số xâu có thể lập nên của xâu con (Như trong VD nãy thì là $3\times3\times3\times2 = 54$).

# Độ phức tạp thời gian
- $O(|S|)$ với $S$ là xâu ban đầu.
# Notes
