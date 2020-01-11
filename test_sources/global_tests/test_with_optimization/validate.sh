i="$1"
make  --directory "/home/slahmer/cblass/cblas/CBLAS/examples" > /dev/null &&
/home/slahmer/cblass/cblas/CBLAS/examples/test_ > /tmp/second"${i}".log &&
make  --directory "/home/slahmer/cblass/cblas/CBLAS/examples" "cleanall" > /dev/null &&
cmp /tmp/second"${i}".log /tmp/first"${i}".log || ( echo "TEST $i failed" ; exit 1 ) && ( echo "TEST $i passed"; exit 0)