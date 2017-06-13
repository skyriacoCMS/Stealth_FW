import os 
import sys

print "test job"

i = sys.argv[1]
cmnd = 'root -b -q -l "Est.C('+i+',1)"'

os.system("cp ../../Template/Est.C .")
os.system(cmnd)


