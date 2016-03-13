#include <iostream>
#include <ctime>
#include <cmath>
#include <omp.h>

using namespace std;

double func(double x) {
	return sqrt(sqrt(abs(pow(x, 1))));
}

int main()
{
	const int threads_count = 4;
	omp_set_num_threads(threads_count);
	cout << "Threads count: " << threads_count << endl;
	cout << "Let's integrate" << endl;

	double a = -500;
	double b = 500;
	double step = 0.0001;

	clock_t start = clock();

	double result = 0;

	#pragma omp parallel for reduction(+:result)
	for (int i = 0; i < (int)((b-a)/step); i++)
	{
		result += func(a + step*i)*step;
	}

	clock_t finish = clock();

	cout << "Result: " << result << endl;

	cout << "Elapsed time: " << (finish - start) / (double)(CLOCKS_PER_SEC / 1000) << "ms" << endl;

	return 0;
}