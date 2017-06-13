universe = vanilla 

Executable =/cms/kyriacou/Stealth_17/NewCode/CMSSW_7_0_0/src/Top/CF
Requirements = (Arch == "X86_64")

Output = ./logsf/$(Process).out
Error  = ./logsf/$(Process).err
Log    = ./logsf/$(Process).log

arguments =$(Process)

 
Queue  900

