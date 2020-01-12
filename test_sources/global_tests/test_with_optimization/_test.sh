#!/usr/bin/env bash

exec 2>/tmp/blaster_log_error.log
blaster="/home/slahmer/CLionProjects/BLASter/cmake-build-debug/blaster"
optimizer="/home/slahmer/CLionProjects/Optimizer/cmake-build-debug/optimizer"
test_dir="/home/slahmer/CLionProjects/BLASter/test_sources/global_tests/test_with_optimization"
compiling_dir="/home/slahmer/cblass/cblas/CBLAS/examples"


cd $test_dir || echo "directory doesn't exist"

i="$1";
MARGE=0.2;

$blaster "-i" "${test_dir}/test${i}.c" "-o" "${test_dir}/res/res${i}.c" > "/tmp/blaster_log${i}.data" &
sleep $MARGE && $optimizer  > "/tmp/optimizer_log${i}.data"

sleep $MARGE ;

gcc "${test_dir}/test${i}.c" || exit 1;
./a.out > "/tmp/first${i}.log" || exit 2;
mv "${test_dir}/res/res${i}.c" "${compiling_dir}/test_.c" || exit 3;




