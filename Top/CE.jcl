universe = vanilla 

Executable =/cms/kyriacou/Stealth_17/NewCode/CMSSW_7_0_0/src/Top/CE
Requirements = (Arch == "X86_64")

Output = ./logse/$(Process).out
Error  = ./logse/$(Process).err
Log    = ./logse/$(Process).log

arguments =$(Process)

 
Queue  900

