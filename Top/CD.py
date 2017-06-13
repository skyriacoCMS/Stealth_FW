import os 
import sys

print "test job"

i = sys.argv[1]
cmnd = 'root -b -q -l "CUTStop.C('+i+',1)"'
os.system("cp ../Template/CUTStop.C .")
os.system(cmnd)


