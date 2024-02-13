
#include <Arduino.h>
#include <avr/pgmspace.h>

#include"inc\music.h"
#include"inc\defines.h"
#include"inc\musArray.h"
#include"inc\Timer.h"

/////////////////////////////////////// Tetris /////////////////////////////////
//Beat count, change this to make the song slower or faster
int tempo = 144;
// sizeof gives the number of bytes, each int value consists of two bytes (16 bits)
// Each note has two values (pitch and duration), so four bytes per note
//int notes = sizeof(melody) / sizeof(melody[0]) / 2;    // The number of notes is 99
// Calculate the duration of the entire note (60 seconds/beat)*4 beats
// The duration of a quarter note is 144, which is a speed of 144 beats per minute.
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;
///////////////////////////////////////Tetris end/////////////////////////////////

////////////////////////////////////Ode_to_Joy/////////////////////////////////////
//int length = sizeof(tune) / sizeof(tune[0]);
//////////////////////////////////Ode_to_Joy end///////////////////////////////////


CMusic::CMusic()
{
    m_stopFlag = false;

    m_melody = NULL;
    m_duration = NULL;
    m_current = 0;
    m_lenght = 0;
    m_toPlay = 0;
    m_tempo = 50;
    m_continue = 0;
}

void
CMusic::Init(char pin)
{
    buzzer_pin = pin;
    CTimer::Get()->SetCounter(MusicTimer, 5);
}

void CMusic::Stop()
{
    cleanup();

    m_stopFlag = true;

    noTone(buzzer_pin);
}

void CMusic::Update()
{

    if (!m_isTimerInit)
    {
        CTimer::Get()->SetCounter(MusicTimer, 5);
        m_isTimerInit = true;
    }

    if (CTimer::Get()->IsTimerFinish(MusicTimer))
    {
        if (m_stopFlag)
        {
            m_isTimerInit = false;
            return;
        }

        if (m_lenght > 0)
        {
            if (m_current < m_lenght)
            {
                if (m_toPlay > 0)
                {
                    m_toPlay -= 5;
                }
                else
                {


                    int duration = (int)m_duration[m_current];

                    int noteDuration;

                    if (duration > 0)
                    {
                        noteDuration = duration * m_tempo;
                    }
                    else
                    {
                        // Negative numbers are dotted notes
                        noteDuration = (-duration) * m_tempo;
                        noteDuration *= 1.25; // The duration of a dotted note is half note + quarter note
                    }

                    m_toPlay = noteDuration;
                    tone(buzzer_pin, m_melody[m_current], noteDuration);

                    m_current++;
                }
            }
            else
            {
                if (m_continue != NULL)
                {
                    (this->*m_continue)();
                }
                else
                {
                    Stop();
                }
            }
        }

        m_isTimerInit = false;
    }
}

void
CMusic::cleanup()
{
    int* melody = NULL;
    char* duration = NULL;

    uint8_t oldSREG = SREG;
    cli();

    m_lenght = 0;
    m_current = 0;
    m_toPlay = 0;
    m_continue = 0;

    melody = m_melody;
    m_melody = NULL;

    duration = m_duration;
    m_duration = NULL;

    SREG = oldSREG;


    if (melody != NULL) {

        free(melody);

    }
    if (duration != NULL) {

        free(duration);
    }  

}

void
CMusic::birthday(void)
{
    Stop();

    m_stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_tempo = 50;
    m_continue = NULL;
    m_melody = (int*)malloc(sizeof(birthday_tune));

    if (m_melody == NULL)
        return;

    m_duration = (char *)malloc(sizeof(birthday_durt));

    if (m_duration == NULL)
    {
        m_melody = NULL;
        free(m_melody);
        return;
    }

    memcpy_P(m_melody, birthday_tune, sizeof(birthday_tune));
    memcpy_P(m_duration, birthday_durt, sizeof(birthday_durt));

    m_lenght = ARRAYSIZE(birthday_tune);
}

// Popcorn
void
CMusic::popcorn(void)
{
    Stop();

    m_stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_tempo = 100;
    m_continue = NULL;
    m_melody = (int*)malloc(sizeof(popcorn_tune));

    if (m_melody == NULL)
        return;

    m_duration = (char*)malloc(sizeof(popcorn_durt));

    if (m_duration == NULL)
    {
        m_melody = NULL;
        free(m_melody);
        return;
    }

    memcpy_P(m_melody, popcorn_tune, sizeof(popcorn_tune));
    memcpy_P(m_duration, popcorn_durt, sizeof(popcorn_durt));

    for (int i = 0; i < ARRAYSIZE(popcorn_tune); i++)
    {
        m_melody[i] = m_melody[i] / 2;
    }


    m_lenght = ARRAYSIZE(popcorn_tune);
}

// Popcorn
void
CMusic::Willtell(void)
{
    Stop();

    m_stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_tempo = 50;
    m_continue = NULL;

    m_melody = (int*)malloc(sizeof(WilliamTell_tune));

    if (m_melody == NULL)
        return;

    m_duration = (char*)malloc(sizeof(WilliamTell_durt));

    if (m_duration == NULL)
    {
        m_melody = NULL;
        free(m_melody);
        return;
    }

    memcpy_P(m_melody, WilliamTell_tune, sizeof(WilliamTell_tune));
    memcpy_P(m_duration, WilliamTell_durt, sizeof(WilliamTell_durt));

    for (int i = 0; i < ARRAYSIZE(WilliamTell_tune); i++)
    {
        m_melody[i] = m_melody[i] / 2;
    }


    m_lenght = ARRAYSIZE(WilliamTell_tune);
}

/////////////////////////////////////////////
void
CMusic::star_war_tone(void)
{
    Stop();

    m_stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_tempo = 50;
    m_continue = NULL;

    m_melody = (int*)malloc(sizeof(starWar_tune));

    if (m_melody == NULL)
        return;

    m_duration = (char*)malloc(sizeof(starWar_durt));

    if (m_duration == NULL)
    {
        m_melody = NULL;
        free(m_melody);
        return;
    }

    memcpy_P(m_melody, starWar_tune, sizeof(starWar_tune));
    memcpy_P(m_duration, starWar_durt, sizeof(starWar_durt));


    m_lenght = ARRAYSIZE(starWar_tune);

}

/////////////////////////////////////////////
void CMusic::Ode_to_Joy(void)
{
    Stop();

    Stop();

    m_stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_tempo = 100;
    m_continue = NULL;

    m_melody = (int*)malloc(sizeof(Ode_to_Joy_tune));

    if (m_melody == NULL)
        return;

    m_duration = (char*)malloc(sizeof(Ode_to_Joy_durt));

    if (m_duration == NULL)
    {
        m_melody = NULL;
        free(m_melody);
        return;
    }

    memcpy_P(m_melody, Ode_to_Joy_tune, sizeof(Ode_to_Joy_tune));
    memcpy_P(m_duration, Ode_to_Joy_durt, sizeof(Ode_to_Joy_durt));

    m_lenght = ARRAYSIZE(Ode_to_Joy_tune);
}
/////////////////////////////////////////////
void CMusic::christmas(void)
{
    Stop();

    m_stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_tempo = 100;
    m_continue = NULL;
    m_melody = (int*)malloc(sizeof(tune_christmas));

    if (m_melody == NULL)
        return;

    m_duration = (char*)malloc(sizeof(durt_christmas));

    if (m_duration == NULL)
    {
        m_melody = NULL;
        free(m_melody);
        return;
    }

    memcpy_P(m_melody, tune_christmas, sizeof(tune_christmas));
    memcpy_P(m_duration, durt_christmas, sizeof(durt_christmas));


    m_lenght = ARRAYSIZE(tune_christmas);
}

/////////////////////////////////////////////
void CMusic::super_mario(void)
{
    Stop();

    m_stopFlag = false;

    m_current = 0;
    m_lenght = 0;

    m_melody = (int*)malloc(sizeof(mario_melody));

    if (m_melody == NULL)
        return;

    m_duration = (char*)malloc(sizeof(mario_durt));

    if (m_duration == NULL)
    {
        m_melody = NULL;
        free(m_melody);
        return;
    }

    memcpy_P(m_melody, mario_melody, sizeof(mario_melody));
    memcpy_P(m_duration, mario_durt, sizeof(mario_durt));

    m_continue = &super_mario2;
    m_tempo = 25;
    m_lenght = ARRAYSIZE(mario_melody);

}

void
CMusic::super_mario2(void)
{
    m_current = 0;
    m_lenght = 0;
    m_continue = &super_mario3;
    m_tempo = 25;
    m_lenght = ARRAYSIZE(mario_melody);
}

void
CMusic::super_mario3(void)
{
    m_current = 0;
    m_lenght = 0;

    cleanup();

    m_melody = (int*)malloc(sizeof(underworld_melody_mario));

    if (m_melody == NULL)
        return;

    m_duration = (char*)malloc(sizeof(underworld_tempo_mario));

    if (m_duration == NULL)
    {
        m_melody = NULL;
        free(m_melody);
        return;
    }

    memcpy_P(m_melody, underworld_melody_mario, sizeof(underworld_melody_mario));
    memcpy_P(m_duration, underworld_tempo_mario, sizeof(underworld_tempo_mario));

    m_continue = NULL;
    m_tempo = 25;
    m_lenght = ARRAYSIZE(underworld_melody_mario);
}
