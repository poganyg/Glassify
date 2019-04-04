#include <stdio.h>
#include "DemoThread.h"

int qq;
int* ptr = &qq;

int main( int argc, const char* argv[] ) {
	printf("qq is %d\n", qq);
	DemoThread demoThread1(ptr);
	//DemoThread demoThread2(10);
	//DemoThread demoThread3(20);
	demoThread1.start();
	//demoThread2.start();
	//demoThread3.start();
	demoThread1.join();
	printf("qq is %d\n", qq);
	demoThread1.~DemoThread();
	DemoThread demoThread1(ptr);
	//demoThread2.join();
	//demoThread3.join();
	demoThread1.start();
	//demoThread2.start();
	//demoThread3.start();
	demoThread1.join();
	printf("qq is %d\n", qq);
	//demoThread2.join();
	//demoThread3.join();
}
