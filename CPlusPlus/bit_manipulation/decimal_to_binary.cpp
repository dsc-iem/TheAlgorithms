#include <bits/stdc++.h>
using namespace std;

void bin(unsigned n)
{
	if (n > 1)
		bin(n >> 1);

	cout<<(n & 1);
}

int main(void)
{
	bin(131);
	cout<<endl;
	bin(3);
	return 0;
}
