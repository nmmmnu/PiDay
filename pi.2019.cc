#include <iostream>
#include <iomanip>
#include <cmath>

using myfloat = double;
using uint    = unsigned int;

const uint MAX = 1000;

const auto PI  = M_PI;

static_assert(MAX > 0, "Max must be greater than 0");

const myfloat one = 1;

inline void put(std::ostream &os, uint const a){
	os << std::setprecision(0)  << std::setw(5) << a << ' ';
}

inline void put(std::ostream &os, myfloat const a){
	os << std::fixed << std::setprecision(10) << std::setw(12) << a << ' ';
}

struct percent_tag{};

inline void put(std::ostream &os, myfloat const a, percent_tag){
	os << std::fixed << std::setprecision(4) << std::setw(7) << a << " %" << ' ';
}

inline void put(std::ostream &os){
	os << '\n';
}

int main(){
	myfloat sum = 0;

	for(uint i = 1; i < MAX; ++i){
		const auto term = one / (i * i);
		sum += term;

		/*
		 * pi^2 / 6 = sum
		 * pi^2 = 6 sum
		 * pi = sqrt(6 sum)
		 */

		const auto pi = sqrt(6 * sum);
		const auto diff = (PI - pi) / PI * 100;

		put(std::cout, i			);
		put(std::cout, term			);
		put(std::cout, sum			);
		put(std::cout, pi			);
		put(std::cout, diff,	percent_tag{}	);
		put(std::cout				);
	}
}

