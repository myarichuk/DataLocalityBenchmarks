using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Diagnosers;
using BenchmarkDotNet.Running;

namespace NetCoreDataLocality
{
    [HardwareCounters(HardwareCounter.CacheMisses)]
    public class Program
    {
        [Params(16, 512, 4096, 16 * 1024)]
        public int Size { get; set; }

        private long[,] Array2D;

        [IterationSetup]
        public void Init() => Array2D = new long[Size, Size];

        [Benchmark]
        public void Iterate2DArrayColumnFirst()
        {
            for (int y = 0; y < Size; y++)
            for (int x = 0; x < Size; x++)
                Array2D[x, y] = x + y;
        }

        [Benchmark]
        public void Iterate2DArrayRowFirst()
        {
            for (int x = 0; x < Size; x++)
            for (int y = 0; y < Size; y++)
                Array2D[x, y] = x + y;
        }

        static void Main(string[] args) => BenchmarkRunner.Run<Program>();
    }
}
