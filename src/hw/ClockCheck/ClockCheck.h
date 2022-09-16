#ifndef __CLOCKCHECK_H__
#define __CLOCKCHECK_H__

#include <time.h>

class ClockCheck
{
private:
    time_t prevSec;

public:
    ClockCheck();
    virtual ~ClockCheck();
    bool isUpdate();
};

#endif /* __CLOCKCHECK_H__ */