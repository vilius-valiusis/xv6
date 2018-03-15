#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main()
{
	// 2 sys calls sbrk and exec

	// 1 sys call
	int pid = getpid();

	// 1 sys call
	trace(1);

	// 4 sys calls
	fork();
	fork();
	wait();
	wait();

	// 1 sys call
	if(getpid() == pid){
		// should be 10 (include trace(0))
		printf(1, "total syscalls so far: %d\n", trace(1));
		// 26 more from print (2 digits for num)
	}

	// 2 sys calls
	fork();
	wait();

	// 1 sys call
	if(getpid() == pid){
		// should be 40 (39 + trace(0))
		printf(1, "totalsys calls so far: %d\n", trace(0));
	}
	exit();
}
