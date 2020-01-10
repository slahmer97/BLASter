#! /bin/sh
#10 = display symbol table
fileTest="test.sh"

for i in `ls -d */`
do
		echo "=============================================="
		echo " Traitement de tests: $i"
		echo "=============================================="
		$i$fileTest
done



