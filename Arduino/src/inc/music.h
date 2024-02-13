#ifndef _MUSIC_H_
#define _MUSIC_H_ 
#include "singleton.h"
#include "dispatch.h"


class CMusic : public CDispatch, public Singleton<CMusic>
{

    volatile bool   m_stopFlag;

    int*            m_melody;
    char*           m_duration;
    int             m_current;
    int             m_lenght;
    int             m_toPlay;
    int             m_tempo;
    void           (CMusic::* m_continue)(void);

public:
     CMusic();

     void Init(char pin);
     virtual void Update();

     void Stop();

     void birthday(void);
     void Ode_to_Joy(void);
     void christmas(void);
     
     void super_mario(void);   // Super Mario
     void star_war_tone(void); // Star Wars
     void popcorn(void); // Popcorn
     void Willtell(void);


protected:
    void cleanup();

    void super_mario2(void);
    void super_mario3(void);

private:
     char buzzer_pin;
};
#endif
