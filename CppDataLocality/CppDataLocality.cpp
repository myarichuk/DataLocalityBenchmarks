// CppDataLocality.cpp : Defines the entry point for the application.
//

#include <benchmark/benchmark.h>
#include <array>

using namespace std;

class array2d_benchmark
{
private:
	shared_ptr<vector<vector<unsigned long long>>> array2d;
	int _array_size;
public:
	array2d_benchmark(int array_size) : _array_size(array_size)
	{		
		array2d = make_shared<vector<vector<unsigned long long>>>(array_size , vector<unsigned long long> (array_size, 0));
	}
	
	void benchmark_column_first() const
	{
		for(unsigned long long y = 0; y < _array_size; y++)
		for(unsigned long long x = 0; x < _array_size; x++)
			(*array2d)[x][y] = x + y;
	}

	void benchmark_row_first() const
	{
		for(unsigned long long x = 0; x < _array_size; x++)
		for(unsigned long long y = 0; y < _array_size; y++)
			(*array2d)[x][y] = x + y;
	}
};


static void benchmark_array2d_column_first(benchmark::State& state) {
  const array2d_benchmark benchmark(state.range_x());
  for (auto _ : state) {
    benchmark.benchmark_column_first();
  }
}

static void benchmark_array2d_row_first(benchmark::State& state) {
  const array2d_benchmark benchmark(state.range_x());
  for (auto _ : state) {
    benchmark.benchmark_row_first();
  }
}
//16, 512, 4096, 16 * 1024
BENCHMARK(benchmark_array2d_column_first)->Arg(16);
BENCHMARK(benchmark_array2d_column_first)->Arg(512);
BENCHMARK(benchmark_array2d_column_first)->Arg(4096);
BENCHMARK(benchmark_array2d_column_first)->Arg(16 * 1024);

BENCHMARK(benchmark_array2d_row_first)->Arg(16);
BENCHMARK(benchmark_array2d_row_first)->Arg(512);
BENCHMARK(benchmark_array2d_row_first)->Arg(4096);
BENCHMARK(benchmark_array2d_row_first)->Arg(16 * 1024);

BENCHMARK_MAIN();
