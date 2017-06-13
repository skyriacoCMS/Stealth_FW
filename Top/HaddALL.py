import os
import sys

os.system("hadd -f -k runB.root ./PlotsB/*.root")
os.system("hadd -f -k runD.root ./PlotsD/*.root")
os.system("hadd -f -k runE.root ./PlotsE/*.root")
os.system("hadd -f -k runF.root ./PlotsF/*.root")
os.system("hadd -f -k runG.root ./PlotsG/*.root")
os.system("hadd -f -k allruns.root runB.root runD.root runE.root runF.root runG.root")
