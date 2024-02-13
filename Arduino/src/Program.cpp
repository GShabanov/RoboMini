
#include "inc\defines.h"

#include "inc\Timer.h"
#include "inc\RelayModule.h"
#include "inc\Keyboard.h"
#include "inc\Sensor.h"
#include "inc\Config.h"
#include "inc\LiquidCrystal_I2C.h"
#include "inc\Program.h"


extern LiquidCrystal_I2C lcd;

void
CProgram::StartRecicling()
{
    CRelayModule::Get()->SwitchRelay(RecycleOil, true);
}

void
CProgram::StopRecicling()
{
    CRelayModule::Get()->SwitchRelay(RecycleOil, false);
}

bool
CProgram::InitializePistons()
{
    WorkCode  workCode;

    lcd.clear();

    if (CConfig::Get()->ReleasePistonsOnStart() == true)
    {
        //
        // disable reduction
        //
        StopRecicling();

        //
        // enable turn back relay
        //
        m_FeedPiston.StartReturn();
        m_PackingPiston.StartReturn();

        lcd.setCursor(0, 0);
        lcd.print("Initializing");


        CTimer::Get()->SetCounter(PistonPoolTimer, m_pistonTimeout);    // 15 seconds

        m_SensorUpdate();

        lcd.setCursor(0, 1);
        lcd.print("<-(3) <-(1)");

        //
        // release pistons
        //
        workCode = DoReleaseAll();


        //
        // set on reduction
        //
        StartRecicling();

        m_SensorUpdate();

        lcd.setCursor(0, 1);
        lcd.print("            ");

        if (workCode != Success)
        {
            return false;
        }

        if (workCode == Stopped)
        {
            return false;
        }

        lcd.setCursor(0, 0);
        lcd.print("Init OK     ");

        CTimer::Get()->Delay(1000);
    }


    return true;
}

CProgram::WorkCode
CProgram::DoFeedWork()
{
    bool pistonReady = false;
    bool terminated = false;

    pistonReady = false;
    m_FeedPiston.StartExtend();

    do
    {
        m_SensorUpdate();

        if (m_FeedPiston.IsExtended())
        {
            pistonReady = true;
            break;
        }

        if (CKeyboard::Get()->IsKeyClicked())
        {
            terminated = true;
            break;
        }

    } while (!CTimer::Get()->IsTimerFinish(PistonPoolTimer));

    m_FeedPiston.StopExtend();

    m_SensorUpdate();

    if (terminated)
    {
        return Stopped;
    }

    if (!pistonReady)
    {
        return Error;
    }

    return Success;
}

CProgram::WorkCode
CProgram::FeedRelease()
{
    bool pistonReady = false;
    bool terminated = false;

    lcd.setCursor(0, 1);
    lcd.print("<-(1)");

    m_FeedPiston.StartReturn();

    do
    {
        m_SensorUpdate();

        if (m_FeedPiston.IsReturned())
        {
            pistonReady = true;
            break;
        }

        if (CKeyboard::Get()->IsKeyClicked())
        {

            terminated = true;
            break;
        }


    } while (!CTimer::Get()->IsTimerFinish(PistonPoolTimer));

    m_FeedPiston.StopReturn();

    lcd.setCursor(0, 1);
    lcd.print("-----");

    m_SensorUpdate();

    if (terminated)
    {
        return Stopped;
    }

    if (!pistonReady)
    {
        return Error;
    }

    return Success;
}

CProgram::WorkCode
CProgram::DoPacking()
{
    bool pistonReady = false;
    bool terminated = false;

    m_PackingPiston.StartExtend();

    do
    {
        m_SensorUpdate();

        if (m_PackingPiston.IsExtended())
        {
            pistonReady = true;
            break;
        }

        if (CKeyboard::Get()->IsKeyClicked())
        {
            terminated = true;
            break;
        }


    } while (!CTimer::Get()->IsTimerFinish(PistonPoolTimer));

    m_PackingPiston.StopExtend();

    m_SensorUpdate();

    if (terminated)
    {
        return Stopped;
    }

    if (!pistonReady)
    {
        return Error;
    }

    return Success;
}

CProgram::WorkCode
CProgram::PackingRelease()
{
    bool pistonReady = false;
    bool terminated = false;

    lcd.setCursor(6, 1);
    lcd.print("<-(3)");

    m_PackingPiston.StartReturn();

    do
    {
        m_SensorUpdate();

        if (m_PackingPiston.IsReturned())
        {
            pistonReady = true;
            break;
        }

        if (CKeyboard::Get()->IsKeyClicked()) {

            terminated = true;
            break;
        }


    } while (!CTimer::Get()->IsTimerFinish(PistonPoolTimer));

    m_PackingPiston.StopReturn();

    lcd.setCursor(6, 1);
    lcd.print("-----");

    m_SensorUpdate();

    if (terminated)
    {
        return Stopped;
    }

    if (!pistonReady)
    {
        return Error;
    }

    return Success;
}

CProgram::WorkCode
CProgram::DoReleaseAll()
{
    bool piston1Ready = false;
    bool piston2Ready = false;
    bool terminated = false;

    //
    // enable turn back relay
    //
    m_FeedPiston.StartReturn();
    m_PackingPiston.StartReturn();

    //
    // first of all move pistons to start position
    //
    do
    {
        m_SensorUpdate();

        if (m_FeedPiston.IsReturned())
        {
            piston1Ready = true;
        }

        if (m_PackingPiston.IsReturned())
        {
            piston2Ready = true;
        }

        if (piston1Ready && piston2Ready)
        {
            break;
        }

        if (CKeyboard::Get()->IsKeyClicked()) {

            terminated = true;
            break;
        }

    } while (!CTimer::Get()->IsTimerFinish(PistonPoolTimer));

    //
    // stop pistons
    //
    m_FeedPiston.StopReturn();
    m_PackingPiston.StopReturn();

    m_SensorUpdate();

    if (terminated)
    {
        return Stopped;
    }

    //
    // if any error on pistons on timeout
    // 
    if ((!piston1Ready) || (!piston2Ready))
    {
        return Error;
    }

    return Success;
}

uint8_t
CProgram::Run()
{

    WorkCode  workCode = Error;

    m_SensorUpdate();

    StopRecicling();

    lcd.setCursor(0, 0);
    lcd.print("Working");

    do
    {
        m_SensorUpdate();
        //
        // start timeout for circle 1
        //
        CTimer::Get()->SetCounter(PistonPoolTimer, m_pistonTimeout);    // 15 seconds

        lcd.setCursor(0, 1);
        lcd.print("<-(3) <-(1)");

        //
        // work circle 1
        //
        workCode = DoReleaseAll();

        lcd.setCursor(0, 1);
        lcd.print("            ");

        if (Success != workCode)
        {
            break;
        }

        //
        // start timeout for circle 2
        //
        CTimer::Get()->SetCounter(PistonPoolTimer, m_pistonTimeout);

        lcd.setCursor(0, 1);
        lcd.print("->(2)");

        //
        // work circle 2
        //
        workCode = DoFeedWork();

        lcd.setCursor(0, 1);
        lcd.print("---- ");

        if (Success != workCode)
        {
            break;
        }

        //
        // start timeout for circle 3
        //
        CTimer::Get()->SetCounter(PistonPoolTimer, m_pistonTimeout);    // 15 seconds

        lcd.setCursor(6, 1);
        lcd.print("->(4)");

        //
        // work circle 3
        //
        workCode = DoPacking();

        lcd.setCursor(6, 1);
        lcd.print("-----");


    } while (Success == workCode);

    StartRecicling();

    lcd.setCursor(0, 1);
    lcd.print("            ");

    if (workCode == Success)
    {
        return 0;
    }

    if (workCode == Stopped)
    {
        return 0;
    }

    return 1;
}

//----------------------------------------------------------
// Piston class
//----------------------------------------------------------

void
CPiston::StartExtend()
{
    //
    // clear return if exists
    //
    CRelayModule::Get()->SwitchRelay(m_returnRelay, false);

    //
    // if already extended
    //
    /*if (CSensor::Get()->GetValue(m_extensionSensor) > 0x120)
        return;*/

    CRelayModule::Get()->SwitchRelay(m_extensionRelay, true);

}

void
CPiston::StartReturn()
{
    //
    // clear extension if exists
    //
    CRelayModule::Get()->SwitchRelay(m_extensionRelay, false);

    //
    // if already returned
    //
    /*if (CSensor::Get()->GetValue(m_returnSensor) > 0x120)
        return;*/

    CRelayModule::Get()->SwitchRelay(m_returnRelay, true);

}

void
CPiston::StopExtend()
{
    //
    // stop extension
    //
    CRelayModule::Get()->SwitchRelay(m_extensionRelay, false);
}

void
CPiston::StopReturn()
{
    //
    // stop return
    //
    CRelayModule::Get()->SwitchRelay(m_returnRelay, false);
}


bool
CPiston::IsExtended()
{
    if (CSensor::Get()->GetValue(m_extensionSensor) > 0x120)
        return true;

    return false;
}

bool
CPiston::IsReturned()
{
    if (CSensor::Get()->GetValue(m_returnSensor) > 0x120)
        return true;

    return false;
}

