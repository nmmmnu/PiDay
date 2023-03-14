#include <cstdio>
#include <cstdint>
#include <cmath>

using myfloat = double;

constexpr size_t  N  = 100'000'000;
constexpr myfloat N2 = N * N;


int main(){
	myfloat pi = 0;

	for(int64_t i = 1; i < N; ++i){
		auto const i2 = i * i;

		pi += sqrt(N2 - i2) / N2;
	}

	pi *= 4;

	printf("%10.10f\n", pi);
}

