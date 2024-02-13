#pragma once
#ifndef __CART_H__
#define __CART_H__
#include "singleton.h"
#include "dispatch.h"

class CCart : public CDispatch, public Singleton<CCart>
{
    const uint8_t m_maxSpeed = 255;
    const uint8_t m_l_speed_inc = 20;
    const uint8_t m_r_speed_inc = 20;

    uint8_t m_speeds_L;
    uint8_t m_speeds_R;

    int8_t  m_left_inc;
    int8_t  m_right_inc;


public:
    CCart() throw()
        : CDispatch()
    {
        m_speeds_L = 0; // the initial speed of the left motor is 200
        m_speeds_R = 0; // the initial speed of the right motor is 200
        m_left_inc = 0;
        m_right_inc = 0;

        m_isTimerInit = false;
    }

    void setLeftSpeed(uint8_t val)
    {
        m_speeds_L = val;
    }

    void setRightSpeed(uint8_t val)
    {
        m_speeds_R = val;
    }

    void Init();
    virtual void Update();

    void Back();
    void Front();
    void FFront();
    void Right();
    void Left();
    void Stop();

};


#endif // __CART_H__
