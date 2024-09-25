# Use an official Ubuntu image as the base
FROM gcc:latest

# Install necessary packages
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    time \
    valgrind \
    libjemalloc-dev \
    && apt-get clean

# Set up work directory
WORKDIR /app

# Copy the C++ source code
COPY . .

# Compile the program with the default allocator (glibc)
RUN g++ -std=c++17 -o benchmark_glibc benchmark.cpp

# Compile the program with jemalloc
RUN g++ -std=c++17 -o benchmark_jemalloc benchmark.cpp -ljemalloc

# Ensure the script is executable
RUN chmod +x run_benchmark.sh

# Entry point for running the benchmark script
CMD ["./run_benchmark.sh"]
