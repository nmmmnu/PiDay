#include <cstdio>

using myfloat = double;

constexpr size_t MAX = 2'500'000'000;

int main(){
	myfloat sum = 0;

	myfloat const four = 4;

	for(size_t i = 0; i < MAX; ++i)
		sum += 1 / (four * i + 1) - 1 / (four * i + 3);

	myfloat const pi = sum * four;

	printf("%f\n", pi);
}

