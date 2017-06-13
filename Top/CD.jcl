universe = vanilla 

Executable =/cms/kyriacou/Stealth_17/NewCode/CMSSW_7_0_0/src/Top/CD
Requirements = (Arch == "X86_64")

Output = ./logsd/$(Process).out
Error  = ./logsd/$(Process).err
Log    = ./logsd/$(Process).log

arguments =$(Process)

 
Queue  900

