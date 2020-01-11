#!/usr/bin/env bash

exec 2>/tmp/blaster_log_error.log
blaster="/home/slahmer/CLionProjects/BLASter/cmake-build-debug/blaster"
optimizer="/home/slahmer/CLionProjects/Optimizer/cmake-build-debug/optimizer"
test_dir="/home/slahmer/CLionProjects/BLASter/test_sources/global_tests/test_with_optimization"
compiling_dir="/home/slahmer/cblass/cblas/CBLAS/examples"


cd $test_dir || echo "directory doesn't exist"

i="$1";
MARGE=0.2;
#echo "${test_dir}/res${i}.c";
echo "==============Testing : test${i}.c ===================" ;


$blaster "${test_dir}/test${i}.c" "${test_dir}/res${i}.c" "10" > "/tmp/blaster_log${i}.data" &
sleep $MARGE && $optimizer  > "/tmp/optimizer_log${i}.data"

sleep $MARGE ;

gcc "${test_dir}/test${i}.c" ;
./a.out > "/tmp/first${i}.log" ;
mv "${test_dir}/res${i}.c" "${compiling_dir}/test_.c"




