#include <cstdio>
#include <cstdint>

using myfloat = double;

constexpr size_t MAX = 2'500;

int main(){
	myfloat pi = 3;

	int64_t i = 2;

	int sign = 1;

	while(i < MAX){
		auto x = i;
		x *= ++i;
		x *= ++i;

		pi += sign * 4.0 / x;

		sign = -sign;

	//	printf("%f %d %ld\n", pi, sign, x);
	}

	printf("%f\n", pi);
}

