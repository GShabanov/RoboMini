/***************************************************************************************\
*   File:                                                                               *
*       Cart.cpp                                                                        *
*                                                                                       *
*   Abstract:                                                                           *
*       Motorized cart control code                                                     *
*                                                                                       *
*   Author:                                                                             *
*       G Shabanov  22-Dec-2023                                                         *
*                                                                                       *
*   Revision History:                                                                   *
\***************************************************************************************/
// $Id: $
#include <avr/eeprom.h>
#include <arduino.h>

//#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "inc\defines.h"
#include "inc\Cart.h"
#include "inc\Timer.h"

#define ML_Ctrl 4   // define the direction control pin of the left motor as 4
#define ML_PWM  6   // define the PWM control pin of the left motor 
#define MR_Ctrl 2   // define the direction control pin of the right sensor
#define MR_PWM  5   // define the PWM control pin of the right motor 

//extern void matrix_display(unsigned char matrix_value[]);
//unsigned char STOP01[] = { 0x2E, 0x2A, 0x3A, 0x00, 0x02, 0x3E, 0x02, 0x00, 0x3E, 0x22, 0x3E, 0x00, 0x3E, 0x0A, 0x0E, 0x00 };
//unsigned char front[]  = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x12, 0x09, 0x12, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
//unsigned char back[]   = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x48, 0x90, 0x48, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
//unsigned char left[]   = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x00 };
//unsigned char right[]  = { 0x00, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

void
CCart::Init()
{
    pinMode(ML_Ctrl, OUTPUT);
    pinMode(ML_PWM, OUTPUT);
    pinMode(MR_Ctrl, OUTPUT);
    pinMode(MR_PWM, OUTPUT);

    digitalWrite(ML_Ctrl, LOW);
    analogWrite(ML_PWM, 0);
    digitalWrite(MR_Ctrl, LOW);
    analogWrite(MR_PWM, 0);

    m_isTimerInit = false;

}

void
CCart::Update()
{
    if (!m_isTimerInit)
    {
        CTimer::Get()->SetCounter(MotorTimer, 50);
        m_isTimerInit = true;

    }

    if (CTimer::Get()->IsTimerFinish(MotorTimer))
    {
        m_isTimerInit = false;

        if (m_left_inc != 0)
        {
            if (m_left_inc < 0)
            {
                digitalWrite(ML_Ctrl, HIGH);
                if (m_speeds_L + (-m_left_inc) <= m_maxSpeed)
                {
                    m_speeds_L += (-m_left_inc);
                }
                else
                {
                    m_left_inc = 0;
                }

                analogWrite(ML_PWM, m_speeds_L);
            }
            else
            {
                digitalWrite(ML_Ctrl, LOW);

                if (m_speeds_L + m_left_inc <= m_maxSpeed)
                {
                    m_speeds_L += m_left_inc;
                }
                else
                {
                    m_left_inc = 0;
                }

                analogWrite(ML_PWM, m_speeds_L);
            }
        }

        if (m_right_inc != 0)
        {
            if (m_right_inc < 0)
            {
                digitalWrite(MR_Ctrl, HIGH);
                if (m_speeds_R + (-m_right_inc) <= m_maxSpeed)
                {
                    m_speeds_R += (-m_right_inc);
                }
                else
                {
                    m_right_inc = 0;
                }

                analogWrite(MR_PWM, m_speeds_R);
            }
            else
            {
                digitalWrite(MR_Ctrl, LOW);

                if (m_speeds_R + m_right_inc <= m_maxSpeed)
                {
                    m_speeds_R += m_right_inc;
                }
                else
                {
                    m_right_inc = 0;
                }

                analogWrite(MR_PWM, m_speeds_R);
            }
        }


    }
}

void
CCart::Back()
{

    m_right_inc = -m_r_speed_inc;
    m_left_inc = -m_l_speed_inc;
    m_speeds_L = 50;
    m_speeds_R = 50;

}

void
CCart::Front()
{
    m_right_inc = m_r_speed_inc;
    m_left_inc = m_l_speed_inc;
    m_speeds_L = 50;
    m_speeds_R = 50;

}

void
CCart::FFront()
{
    m_speeds_L = m_maxSpeed;
    m_speeds_R = m_maxSpeed;
    m_right_inc = 0;
    m_left_inc = 0;
    digitalWrite(ML_Ctrl, LOW);
    digitalWrite(MR_Ctrl, LOW);

    analogWrite(MR_PWM, m_maxSpeed);
    analogWrite(ML_PWM, m_maxSpeed);
}

void
CCart::Right()
{

    m_right_inc = -m_r_speed_inc;
    m_left_inc = m_l_speed_inc;
    m_speeds_L = 50;
    m_speeds_R = 50;

}

void
CCart::Left()
{

    m_right_inc = m_r_speed_inc;
    m_left_inc = -m_l_speed_inc;
    m_speeds_L = 50;
    m_speeds_R = 50;

}

void
CCart::Stop()
{
    m_right_inc = 0;
    m_left_inc = 0;
    m_speeds_R = 0;
    m_speeds_L = 0;
    digitalWrite(MR_Ctrl, LOW);
    digitalWrite(ML_Ctrl, LOW);
    analogWrite(MR_PWM, 0);
    analogWrite(ML_PWM, 0);

}

