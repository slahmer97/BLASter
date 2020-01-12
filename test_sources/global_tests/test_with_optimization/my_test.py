import subprocess as sp
import time
import sys

if len(sys.argv) != 3:
    print("USAGE : python test.py from to")
    sys.exit(1)
from_ = int(sys.argv[1])
to_ = int(sys.argv[2])

for i in range(from_,to_+1):
    proc1 = sp.run(["./_test.sh","{}".format(i)])
    time.sleep(1)
    proc2 = sp.run(["./_validate.sh","{}".format(i)])
    if proc2.returncode == 0:
        print("test {} passed".format(i))
    else :
        print("test {} failed".format(i))
