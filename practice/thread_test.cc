#include <iostream>
#include <thread>
#include <functional>

using namespace std;

class MyThread {
 public:
 	 void Start() {
		 function<void()> cb = bind(&MyThread::SomeFunc, this);
     	t_ = new thread(cb);
 	 }

	 void Wait() {
		 t_->join();
		 delete t_;
		 cout << "Deleted thread" << endl;
	 }

 private:
	 thread* t_;
	 
	 void SomeFunc() {
		 cout << "In thread func." << endl;
	 }
};

int main() {
	MyThread obj;
	
	obj.Start();
	obj.Wait();
	
	
	return 0;
}