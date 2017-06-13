universe = vanilla 

Executable =/cms/kyriacou/Stealth_17/NewCode/CMSSW_7_0_0/src/Top/CB
Requirements = (Arch == "X86_64")

Output = ./logsb/$(Process).out
Error  = ./logsb/$(Process).err
Log    = ./logsb/$(Process).log

arguments =$(Process)

 
Queue  900

