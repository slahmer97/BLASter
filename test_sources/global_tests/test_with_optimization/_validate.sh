#!/usr/bin/env bash

i="$1"
make  --directory "/home/slahmer/cblass/cblas/CBLAS/examples" > /dev/null &&
/home/slahmer/cblass/cblas/CBLAS/examples/test_ > /tmp/second"${i}".log &&
make  --directory "/home/slahmer/cblass/cblas/CBLAS/examples" "cleanall" > /dev/null &&
cmp /tmp/second"${i}".log /tmp/first"${i}".log || ( cat /tmp/second"${i}".log ; echo "==========";cat /tmp/first"${i}".log ;echo "============";exit 1 ) && ( exit 0)
