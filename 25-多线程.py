#coding=utf-8
import threading
import sys
from time import ctime,sleep

globals_num = 0

result = []
lock = threading.Lock()


def af():
    lock.acquire()  # 获得锁
    result.append('A')
    lock.release()  # 释放锁

def bf():
    lock.acquire()  # 获得锁
    result.append('B')
    lock.release()  # 释放锁

def cf():
    lock.acquire()  # 获得锁
    result.append('C')
    lock.release()  # 释放锁

def df():
    lock.acquire()  # 获得锁
    result.append('D')
    lock.release()  # 释放锁        

# threads = []
# t1 = threading.Thread(target=a)
# threads.append(t1)
# t2 = threading.Thread(target=b)
# threads.append(t2)
# t3 = threading.Thread(target=c)
# threads.append(t3)
# t4 = threading.Thread(target=d)
# threads.append(t4)

if __name__ == '__main__':
    num = raw_input("")
    if num == "":
        sys.exit()  
    for i in range(int(num)):
       a = threading.Thread(target=af)
       a.start()
       b = threading.Thread(target=bf)
       b.start()
       c = threading.Thread(target=cf)
       c.start()
       d = threading.Thread(target=df)
       d.start()
       d.join()  
    print "".join(result)