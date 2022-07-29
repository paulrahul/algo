import inspect
import threading
from time import sleep

from pyparsing import col

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

    # def __init__(self):
    #     self.color_map = {}
    #     self.next_idx = 0
    #     self.lock = threading.Lock()

    # def get_color(self, key):
    #     with self.lock:
    #         if key not in self.color_map:
    #             self.color_map[key] = 

    def disable(self):
        self.HEADER = ''
        self.OKBLUE = ''
        self.OKGREEN = ''
        self.WARNING = ''
        self.FAIL = ''
        self.ENDC = ''

class ThreadStuff(object):
    def __init__(self):
        self.shared_dict = {}
        self.dict_lock = threading.Lock()

    def threadsafe_crashing_method(self):
        with self.dict_lock:
            self.shared_dict["1"] = "rahul"
            self.shared_dict["2"] = "paul"

            thread_print("Sleeping after setting the shared_dict", bcolors.OKGREEN)

            sleep(5)
            
            raise Exception("Fuck this shit!")

    def threadsafe_method(self):
        with self.dict_lock:
            thread_print("dict = %s" % (self.shared_dict), bcolors.OKBLUE)

    def threadunsafe_method(self):
        thread_print("dict = %s" % (self.shared_dict), bcolors.WARNING)

def thread_print(s, color):
    log_print(s, color=color, calling_fn=inspect.stack()[1].function)

def log_print(s, calling_fn = None, color=None):
    if not calling_fn:
        calling_fn = inspect.stack()[1].function

    if color:
        print(f"{color}Thread {calling_fn}: {s}\n")
    else:
        print(f"Thread {calling_fn}: {s}\n")

def create_thread_executor(f, start_after_secs=None):
    print("Starting thread %s" % (f.__name__))
    if start_after_secs:
        print("Sleeping in thread %s for %d seconds" %
                (f.__name__, start_after_secs))
        sleep(start_after_secs)
    print("Executing function in thread %s" % (f.__name__))
    f()
    
if __name__ == "__main__":
    o = ThreadStuff()

    """
    Start 3 threads:
    1. Thread-safe crashing
    2. Thread-safe good
    3. Thread-unsafe good

    Make T2 block on T1 i.e. have T1 crash before T2 gets in.
    Make T3 just go. 

    """
    threads = []
    threads.append(threading.Thread(target=create_thread_executor, args=(o.threadsafe_crashing_method,)))
    threads.append(threading.Thread(target=create_thread_executor, args=(o.threadsafe_method, 1,)))
    threads.append(threading.Thread(target=create_thread_executor, args=(o.threadunsafe_method,)))
    
    for t in threads:
        t.start()

    for t in threads:
        t.join()