import sys, subprocess, platform

actions = {"Linux": {"build": "cmake -S. -Bbuild", "clean": "rm -rf build bin"}, 
           "Darwin": {"build": "cmake -S. -Bbuild", "clean": "rm -rf build bin"}, 
           "Windows": {"build": 'cmake -G "Visual Studio 17 2022" -Bbuild', "clean": "rmdir build bin /s /q"}}

if len(sys.argv) > 1:
  actionsForSystem = actions[platform.system()]
  if sys.argv[1] in actionsForSystem:
    subprocess.run(actionsForSystem[sys.argv[1]], shell=True)
  else:
    print("Command not supported")
