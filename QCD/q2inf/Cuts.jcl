universe = vanilla 

Executable =/cms/kyriacou/Stealth_17/NewCode/CMSSW_7_0_0/src/QCD/q2inf/Cuts
Requirements = (Arch == "X86_64")

Output = ./logs/$(Process).out
Error  = ./logs/$(Process).err
Log    = ./logs/$(Process).log

arguments =$(Process)
 
Queue 50

