#include <iostream>
using namespace std;

// biểu diễn 16 ô trong ma trận 4x4
// mỗi ô được đánh số từ 0..15

#define i16 short
#define u16 unsigned short
#define u32 unsigned int

const u16 N = 4;
const u16 I = 65535;

// các bước di chuyển từ ô này sang một ô khác
// -4: lên 1 ô
// +4: xuống 1 ô
// -1: qua trái 1 ô
// +1: qua phải 1 ô
const i16 M[] = {-4, 1, 4, -1};
// các ô ở rìa ma trận
const i16 E[] = {0, 1, 2, 3, 4, 7, 8, 11, 12, 13, 14, 15};

// `houses[i]` == 0 --> có nhà ở ô thứ `i`
u16 houses;

// trả về ô tiếp theo từ ô `cr`,
// sau khi áp dụng phương thức di chuyển `m`
i16 getnxt(i16 cr, i16 m) {
	i16 nxt = cr + M[m];
	if (abs(M[m]) == 1) {
		// ở trên cùng một hàng
		if (cr/4 == nxt/4) return nxt;
		return -1;
	}
	// không vượt biên
	if (0 <= nxt && nxt < 16) return nxt;
	return -1;
}

//
void dfs(const u16 bitset, i16 u, u16 &visited, u16 &cnt) {
	visited |= 1<<u;
	cnt++;
	//
	for (i16 i = 0; i < 4; i++) {
		i16 nxt = getnxt(u, i);	// thử di chuyển đến ô tiếp theo
		if (
			(nxt != -1) &&		// ô tiếp theo hợp lệ trong không gian ma trận
			(bitset>>nxt&1) &&	// ô tiếp theo tồn tại
			!(visited>>nxt&1)	// ô tiếp theo chưa được thăm
		) dfs(bitset, nxt, visited, cnt);
	}
}

// chỉ khi tất cả các ô `1` liền nhau thì mới có cách xây hào theo hình đa giác hợp lệ
// hàm `dfs_g1()` kiểm tra tính liên thông trên
bool dfs_g1(u16 bitset) {
	u16 visited = 0, cnt = 0;
	for (i16 i = 0; i < 16; i++) if (bitset>>i&1) {
		dfs(bitset, i, visited, cnt);
		break;
	}
	// số các ô liền nhau == số các ô được chọn
	return cnt == __builtin_popcount(bitset);
}

/*
<note> tình trạng cô lập được miêu tả như sau:

1 1 1 1
1 0 0 1
1 0 0 1
1 1 1 1

không thể xây hào với một bitset như vậy
vì không thể vẽ một hình đa giác bao quanh tất cả các ô `1`
mà không bao quanh các ô `0`
*/

// kiểm tra xem có ô `0` nào bị cô lập trong hào hay không
// --> kiểm tra bằng cách tính số ô `0` liên thông với biên
bool dfs_g2(u16 bitset) {
	u16 visited = 0, cnt = 0;
	bitset = ~bitset;
	for (int _i = 0; _i < sizeof(E) / sizeof(E[0]); _i++) {
		u16 i = E[_i];
		if (
			(bitset>>i&1) && !(visited>>i&1)
		) dfs(bitset, i, visited, cnt);
	}
	return cnt == __builtin_popcount(bitset);
}

// kiểm tra xem bitset được chọn có bao phủ những ngôi nhà mục tiêu hay không
// --> `bitset` phải có bit == `1` ở những vị trí `houses` có bit == `0`
bool included(u16 &bitset) {
	u16 s = ~(bitset|houses);
	return s == 0;	// một bitset toàn số 1 khi bị lật sẽ ra 0
}

// vét cạn tất cả các cách chọn ô trong ma trận
// `bitset[i]` == 1 nếu ô thứ `i` được chọn
u32 brute() {
	u32 res = 0;
	for (u16 i = 1; i != 0; i++) {
		// nếu bitset bao phủ tất cả những ngôi nhà mục tiêu
		// nếu những ô được chọn liền cạnh
		// nếu những ô bị loại không bị cô lập
		if (included(i) && dfs_g1(i) && dfs_g2(i)) {
			res++;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	houses = ~houses;	// lật bit `houses` để dễ bề tính toán `included()`
	//
	for (int i = 0; i < N; i++) 
	for (int j = 0; j < N; j++) {
		bool k; cin >> k;
		if (k) houses ^= 1<<((i<<2) + j);	// houses ^= 1<<(i*4 + j);
	}
	//
	cout << brute() << "\n";
	return 0;
}
