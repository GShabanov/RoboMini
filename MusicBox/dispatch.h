#pragma once
#ifndef __DISPATCH_H__
#define __DISPATCH_H__

class CDispatch
{

protected:
    volatile bool  m_isTimerInit;

public:
    CDispatch() throw()
    {
        m_isTimerInit = false;
    }

    virtual bool Update() = 0;

};


#endif // __DISPATCH_H__

