import os 
import sys

print "test job"

i = sys.argv[1]
cmnd = 'root -b -q -l "CUTSbatch.C('+i+')"'


os.system(cmnd)


