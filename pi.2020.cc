#include <cstdio>

using myfloat = double;

constexpr size_t MAX = 2'500'000'000;

int main(){
	myfloat pi = 0;

	myfloat sign = +1;
	myfloat denominator = 1;

	for(size_t i = 0; i < MAX; ++i){
		pi += sign * ( 4 / denominator);

		denominator += 2;
		sign *= -1;
	}

	printf("%f\n", pi);
}

