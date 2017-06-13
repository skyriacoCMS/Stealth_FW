import os 
import sys

print "test job"

i = sys.argv[1]
cmnd = 'root -b -q -l "runSinglePoint_tree.C('+i+')"'

os.system("cp ../Template/CUTS.C .")
os.system(cmnd)


