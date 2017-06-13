import os 
import sys

print "test job"

i = sys.argv[1]
cmnd = 'root -b -q -l "CUTSm.C('+i+',3,-1,-1,-1)"'

os.system("cp ../../Template/CUTSm.C .")
os.system(cmnd)


