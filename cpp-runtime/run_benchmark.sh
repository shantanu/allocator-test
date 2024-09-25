#!/bin/bash

# Run glibc benchmark 10 times
echo "Running glibc benchmark..."
for i in {1..10}; do
  /usr/bin/time -f "%e" ./benchmark_glibc 2>> /data/glibc_times.txt
done

# Run jemalloc benchmark 10 times
echo "Running jemalloc benchmark..."
for i in {1..10}; do
  /usr/bin/time -f "%e" ./benchmark_jemalloc 2>> /data/jemalloc_times.txt
done

# Calculate and display statistics for glibc
echo "glibc statistics:"
awk '{sum+=$1; if(min==""){min=max=$1}; if($1>max){max=$1}; if($1<min){min=$1}} END {print "Avg: " sum/NR "\nMin: " min "\nMax: " max}' /data/glibc_times.txt

# Calculate and display statistics for jemalloc
echo "jemalloc statistics:"
awk '{sum+=$1; if(min==""){min=max=$1}; if($1>max){max=$1}; if($1<min){min=$1}} END {print "Avg: " sum/NR "\nMin: " min "\nMax: " max}' /data/jemalloc_times.txt
