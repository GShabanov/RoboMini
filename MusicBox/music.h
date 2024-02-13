#ifndef _MUSIC_H_
#define _MUSIC_H_ 
#include "singleton.h"
#include "dispatch.h"


class CMusic : public CDispatch, public Singleton<CMusic>
{

    volatile bool   stopFlag;

    const int*            m_melody;
    const char*           m_duration;
    int             m_current;
    int             m_lenght;
    int             m_toPlay;
    int             m_tempo;

public:
     CMusic();

     void Init(char pin);
     virtual bool Update();

     void Stop();

     void birthday(void);
     void tetris(void);
     void Ode_to_Joy(void);
     void christmas(void);
     
     void super_mario(void);   // Super Mario

     void star_war_tone(void); // Star Wars

     void popcorn(void); // Popcorn

protected:


    void sing(int s);
    void buzz(int targetPin, long frequency, long length);
    void beep(int note, int duration);

private:
     char buzzer_pin;
};
#endif
