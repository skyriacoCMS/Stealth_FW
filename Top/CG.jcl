universe = vanilla 

Executable =/cms/kyriacou/Stealth_17/NewCode/CMSSW_7_0_0/src/Top/CG
Requirements = (Arch == "X86_64")

Output = ./logsg/$(Process).out
Error  = ./logsg/$(Process).err
Log    = ./logsg/$(Process).log

arguments =$(Process)

 
Queue  900

