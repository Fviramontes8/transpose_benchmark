# Transpose Benchmark
## MPI Transpose
This experiment creates a `kx8` matrix (where `k` is the number of processes),
then creates kxk partitions to exchange in the form of transposing the data.
This means that when data is sent from one process to another, the data
selected in the transposing pattern.

### Cmake build/compile instructions
The following cmake command can create the build folder:

```sh
cmake -B build
```

Then to compile the program:

```sh
cd build
make
```

### Run instructions
Use `mpirun` to run the program, below are some examples (from the cmake 
project home directory):

```sh
mpirun -n 4 ./build/app/mpi_transpose
```
