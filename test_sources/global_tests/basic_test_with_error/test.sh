#! /bin/sh
#10 = display symbol table
path="/home/serradj/CLionProjects/zz/BLASter/blaster"
path_file_test="/home/serradj/CLionProjects/zz/BLASter/test_sources/global_tests/basic_test_with_error/"
optimizer="/home/serradj/CLionProjects/zz/Optimizer/optimizer"
file_test=test*.c
i=1
output="/home/serradj/CLionProjects/zz/BLASter/test_sources/global_tests/basic_test_with_error/output/resulttest$i.c"
for file in `ls $path_file_test$file_test`
do
	$path $file $output 10 > /tmp/outtest$i.c

	grep -R "error : " /tmp/outtest$i.c >/dev/null 
	if test $? != 0; then
	echo "test of test$i.c:  #TEST PASSED#"
	else
	echo "test of test$i.c: Error detected  #TEST PASSED#"
	fi
	
	rm /tmp/outtest$i.c 2>/dev/null
	rm restest$i.c 2>/dev/null
	i=$((i+1))
done




#rm all file res
