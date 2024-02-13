#pragma once

class CPiston
{
    RelayModuleNames  m_extensionRelay;
    RelayModuleNames  m_returnRelay;
    SensorNames       m_extensionSensor;
    SensorNames       m_returnSensor;

public:
    explicit CPiston(
        IN RelayModuleNames  extensionRelay,   // extension relay
        IN RelayModuleNames  returnRelay,
        IN SensorNames       extensionSensor,
        IN SensorNames       returnSensor
    )
        : m_extensionRelay(extensionRelay)
        , m_returnRelay(returnRelay)
        , m_extensionSensor(extensionSensor)
        , m_returnSensor(returnSensor)
    {
    }

    inline void StartExtend();
    inline void StartReturn();
    inline bool IsExtended();
    inline bool IsReturned();
    inline void StopExtend();
    inline void StopReturn();
private:
    CPiston(CPiston &) { };
    CPiston & operator=(const CPiston &) { };
};

class CProgram
{
private:
    _SENSORUPDATE       m_SensorUpdate;

    uint16_t            m_pistonTimeout;
    //friend class CPiston;


    CPiston  m_FeedPiston;
    CPiston  m_PackingPiston;

    enum WorkCode : uint8_t
    {
        Success = 0,
        Stopped = 1,
        Error  = 2
    };

    WorkCode  DoFeedWork();
    WorkCode  FeedRelease();
    WorkCode  DoPacking();
    WorkCode  PackingRelease();
    WorkCode  DoReleaseAll();


    inline void StartRecicling();
    inline void StopRecicling();

public:
    CProgram(_SENSORUPDATE sensorUpdate, uint16_t pistonTimeout)
        : m_SensorUpdate(sensorUpdate)
        , m_pistonTimeout(pistonTimeout)
        , m_FeedPiston(Piston1Forward, Piston1Backwards, Piston1Extend, Piston1Return)
        , m_PackingPiston(Piston2Forward, Piston2Backwards, Piston2Extend, Piston2Return)
    {
    }

    bool InitializePistons();

    uint8_t Run();
};