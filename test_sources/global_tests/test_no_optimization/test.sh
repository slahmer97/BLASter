#! /bin/sh


echo "projet compi.... :)"
blaster="/home/serradj/CLionProjects/zz/BLASter/blaster"
path_file_test="/home/serradj/CLionProjects/zz/BLASter/test_sources/global_tests/test_no_optimization"
optimizer="/home/serradj/CLionProjects/zz/Optimizer/optimizer"
cblas="/home/serradj/CLionProjects/testcbals/cblas/CBLAS/examples/"
file_test="test*.c"
file="/home/serradj/CLionProjects/zz/newtest.c"
i=1
output="/home/serradj/CLionProjects/zz/BLASter/test_sources/global_tests/test_no_optimization/output/cblas_test$i.c"
#TMP=/tmp/test
#LOG=test.log

for file in $path_file_test/test*.c
do
	echo "=======================traitement de test$i.c========================================================";
	$blaster $file $output 3 > /tmp/blaster$i &
	PID1=$!
	$optimizer && sleep 1 &
	PID2=$!
 	wait $PID1
	wait $PID2

	
	
#	kill -TERM $PID1
#	 kill -TERM $PID2
	#$optimizer >> /tmp/blaster$i &

	#kill -9 $PID1 &
	#kill -9 $PID2
#		cd $cblas
#		exec make
		
#	grep -R "error : " /tmp/outtest$i.c >/dev/null
#	if test $? != 0; then
#	echo "test de test$i.c a echoué"
#	else
#	echo "test de test$i.c a reussi"
#	fi
#	
#	rm /tmp/outtest$i.c 2>/dev/null
#	rm restest$i.c 2>/dev/null
	i=$((i+1))
done



