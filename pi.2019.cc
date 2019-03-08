#include <iostream>
#include <iomanip>
#include <cmath>

using myfloat = double;
using uint    = unsigned int;

const uint MAX = 1000;

const auto PI  = M_PI;

namespace myprint{
	struct f_int{
		static constexpr int d = 5;
		static constexpr int p = 0;
		static constexpr const char *s = " ";
	};

	struct f_float{
		static constexpr int d = 2;
		static constexpr int p = 10;
		static constexpr const char *s = " ";
	};

	struct f_proc{
		static constexpr int d = 3;
		static constexpr int p = 4;
		static constexpr const char *s = "% ";
	};

	struct Printer{
		Printer(std::ostream &os) : os(os){};
		~Printer(){
			put();
		}

		template<class F, class T>
		Printer const &put(T const a) const{
			os
				<< std::fixed
				<< std::setprecision(F::p)
				<< std::setw(F::d + F::p)
				<< a
				<< ' '
				<< F::s
			;

			return *this;
		}

		Printer const &put() const{
			os << '\n';
			return *this;
		}
	private:
		std::ostream &os;
	};
} // namespace

int main(){
	constexpr
	myfloat one = 1;
	myfloat sum = 0;

	static_assert(MAX > 0, "Max must be greater than 0");

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

		using namespace myprint;

		Printer{std::cout}
			.put<f_int	>(i	)
			.put<f_float	>(term	)
			.put<f_float	>(sum	)
			.put<f_float	>(pi	)
			.put<f_proc	>(diff	)
		;
	}
}

