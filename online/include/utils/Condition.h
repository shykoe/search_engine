

#ifndef _WD_CONDITION_H
#define _WD_CONDITION_H

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock;

class Condition : Noncopyable
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyall();

private:
	pthread_cond_t cond_;
	MutexLock & mutex_;
};

}//end of namespace wd

#endif
