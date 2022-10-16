
import sys
import os


def run_child():
  
  pid = os.fork()
  if pid == 0:
    os.execv(sys.argv[1], sys.argv[1:])
  else:
    usage = os.wait4(pid, 0)
    print(usage)

if __name__ == '__main__':
  run_child()
