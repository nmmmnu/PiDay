#include <cstdio>
#include <cmath>

// π = 3 + 4 / (2*3*4) - 4 / (4*5*6) + 4 / (6*7*8) - . . .

int main(){
	constexpr size_t iterations = 10'000;

	double pi = 3; // do we know that?

	int den  = 2;

	int sign = 1;

	for(size_t i = 0; i < iterations; ++i){
		auto const d1 = den + 0;
		auto const d2 = den + 1;
		auto const d3 = den + 2;

		pi += sign * 4.0 / (d1 * d2 * d3);

		sign *= -1;

		den += 2;
	}

	printf("π     = %.19f\n", pi);
	printf("M_PI  = %.19f\n", M_PI);
	printf("error = %.19f %%\n", (pi - M_PI) / pi);
}

