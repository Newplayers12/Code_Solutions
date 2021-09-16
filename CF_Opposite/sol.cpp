#include <iostream>
using namespace std;

int a, b, c;

int calc()
{
	a--;
	b--;
	c--;
	//
	int h = abs(a - b),
		f = h << 1,
		d = (c + h) % f;
	if (a >= f || b >= f || c >= f)
		return -1;
	//
	return (c + h) % f + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		cout << calc() << "\n";
	}
	return 0;
}
