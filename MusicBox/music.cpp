
#include <windows.h>

#include"music.h"
#include"defines.h"
#include"musArray.h"
//#include"Timer.h"

#define delay(x) Sleep(x)
#define noTone(x)
#define tone(pin, freq, duration)  Beep(freq, duration)

/////////////////////////////////////// Tetris /////////////////////////////////
//Beat count, change this to make the song slower or faster
int tempo = 144;
// sizeof gives the number of bytes, each int value consists of two bytes (16 bits)
// Each note has two values (pitch and duration), so four bytes per note
int notes = sizeof(melody) / sizeof(melody[0]) / 2;    // The number of notes is 99
// Calculate the duration of the entire note (60 seconds/beat)*4 beats
// The duration of a quarter note is 144, which is a speed of 144 beats per minute.
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;
///////////////////////////////////////Tetris end/////////////////////////////////

////////////////////////////////////Ode_to_Joy/////////////////////////////////////
//int length = sizeof(tune) / sizeof(tune[0]);
//////////////////////////////////Ode_to_Joy end///////////////////////////////////

////////////////////////////////////Christmas songs///////////////////////////////////////////
// Define buzzer pin, note length variable
//int length_christmas = sizeof(tune_christmas) / sizeof(tune_christmas[0]);
//////////////////////////////////Christmas songs end/////////////////////////////////////////

CMusic::CMusic()
{
    stopFlag = false;

    m_melody = NULL;
    m_duration = NULL;
    m_current = 0;
    m_lenght = 0;
    m_toPlay = 0;
}

void
CMusic::Init(char pin)
{
    buzzer_pin = pin;
}

void CMusic::Stop()
{
    stopFlag = true;
    m_current = 0;
    m_lenght = 0;
    m_melody = NULL;
    m_duration = NULL;
    m_toPlay = 0;
    m_tempo = 1;
    noTone(buzzer_pin);
}

bool CMusic::Update()
{


    if (m_lenght > 0)
    {
        if (m_current < m_lenght)
        {
            /*if (m_toPlay > 0)
            {
                m_toPlay -= 5;
            }
            else
            {
                m_toPlay = m_duration[m_current];
                //tone(buzzer_pin, m_melody[m_current]);

                m_current++;
            }*/

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


            Beep(m_melody[m_current] / 2, noteDuration);
            m_current++;

            return true;
        }
        else
        {
            Stop();
        }
    }

    return false;

}

void
CMusic::birthday(void)
{
    Stop();

    stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_melody = birthday_tune;
    //m_duration = birthday_durt;
    m_lenght = ARRAYSIZE(birthday_tune);
}

void
CMusic::popcorn(void)
{
    Stop();

    stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_tempo = 100;
    m_melody = popcorn_tune;
    m_duration = popcorn_durt;
    m_lenght = ARRAYSIZE(popcorn_tune);

}

/////////////////////////////////////////////
void
CMusic::star_war_tone(void)
{
    Stop();

    stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_melody = starWar_tune;
    m_duration = starWar_durt;
    m_tempo = 1;
    m_lenght = ARRAYSIZE(starWar_tune);


}

/////////////////////////////////////////////
void CMusic::tetris(void)    // Tetris song
{
    Stop();

    stopFlag = false;

    // Note that this array is twice the number of notes (notes + deadline)
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2)
    {
        if (stopFlag)
            break;

        // Calculate the duration of each note
        divider = melody[thisNote + 1];

        if (divider > 0)
        {
            noteDuration = (wholenote) / divider;
        }
        else if (divider < 0)
        {
            // Negative numbers are dotted notes
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5; // The duration of a dotted note is half note + quarter note
        }

        // We only play notes 90% of the time and pause the remaining 10% of the time
        tone(buzzer_pin, melody[thisNote], noteDuration * 0.9);
        // Waits for the specified duration before playing the next note.
        delay(noteDuration);
        // Stops waveform generation before the next note.
        noTone(buzzer_pin);
    }
}

/////////////////////////////////////////////
void CMusic::Ode_to_Joy(void)
{
    Stop();

    stopFlag = false;

    for (int thisNote = 0; thisNote < ARRAYSIZE(Ode_to_Joy_tune); thisNote++)
    {
        if (stopFlag)
            break;

        //tone(buzzer_pin, Ode_to_Joy_tune[x]);
        //delay(300 * Ode_to_Joy_durt[x]);

        buzz(buzzer_pin, Ode_to_Joy_tune[thisNote], 300 * Ode_to_Joy_durt[thisNote]);
    }

    noTone(buzzer_pin);
}
/////////////////////////////////////////////
void CMusic::christmas(void)
{
    Stop();

    stopFlag = false;

    //for loop plays music
    for (int thisNote = 0; thisNote < ARRAYSIZE(tune_christmas); thisNote++)
    {
        if (stopFlag)
            break;
        
        //int noteDuration = 1000 / durt_christmas[thisNote];

        buzz(buzzer_pin, tune_christmas[thisNote], 500 * durt_christmas[thisNote]);

        //tone(buzzer_pin, tune_christmas[thisNote]);
        //delay(500 * durt_christmas[thisNote]);         //The 500 here is to control the duration of each note to determine the rhythm of the song.
        noTone(buzzer_pin);
    }

}

/////////////////////////////////////////////
void CMusic::super_mario(void)
{
    Stop();

    stopFlag = false;

    m_current = 0;
    m_lenght = 0;
    m_melody = mario_melody;
    m_duration = mario_durt;
    m_tempo = 1;
    m_lenght = ARRAYSIZE(mario_melody);

    //sing(1);
    //sing(1);
    //sing(2);
}
/////////////////////////////////////////////
void CMusic::sing(int s)
{
    if (s == 2)
    {

        //Serial.println(" 'Underworld Theme'");

        for (int thisNote = 0; thisNote < ARRAYSIZE(underworld_melody_mario); thisNote++)
        {

            if (stopFlag)
                return;

            int noteDuration = 1000 / underworld_tempo_mario[thisNote];

            buzz(buzzer_pin, underworld_melody_mario[thisNote], noteDuration);

            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);

            // stop the tone playing:
            buzz(buzzer_pin, 0, noteDuration);

        }

    }
    else
    {

        //Serial.println(" 'Mario Theme'");

        for (int thisNote = 0; thisNote < ARRAYSIZE(mario_melody); thisNote++)
        {
            if (stopFlag)
                return;


            int noteDuration = 1000 / mario_durt[thisNote];
            buzz(buzzer_pin, mario_melody[thisNote], noteDuration);

            int pauseBetweenNotes = noteDuration * 1.30;

            delay(pauseBetweenNotes);
            buzz(buzzer_pin, 0, noteDuration);

        }
    }
}
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
void CMusic::buzz(int targetPin, long frequency, long length)
{
    tone(buzzer_pin, frequency, length);
    //long delayValue = 1000000 / frequency / 2;
    //long numCycles = frequency * length / 1000;

    /*for (long i = 0; i < numCycles; i++)
    {
        if (stopFlag)
            return;

        //digitalWrite(targetPin, HIGH);
        //delayMicroseconds(delayValue);
        //digitalWrite(targetPin, LOW);
        //delayMicroseconds(delayValue);
    }*/

}

/////////////////////////////////////////////
void CMusic::beep(int note, int duration)
{

    if (stopFlag)
        return;

    //Play tone on buzzerPin
    tone(buzzer_pin, note, duration);

    //Play different LED depending on value of 'counter'

    //delay(duration);

    //if (stopFlag)
    //    return;

    //Stop tone on buzzerPin
    //noTone(buzzer_pin);

    //delay(50);
}
