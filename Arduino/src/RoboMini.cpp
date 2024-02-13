#include <avr/eeprom.h>
#include <arduino.h>

#include "inc\defines.h"
#include "inc\Timer.h"
#include "inc\Cart.h"
#include "inc\music.h"


//int length;
#define tonePin  10


#define Trig 12
#define Echo 13
#define light_L_Pin A1   // define the pin of the left photoresistor
#define light_R_Pin A2   // define the pin of the right photoresistor

#define led_Pin    9   // pin for LED

#define L_pin  11   //  left
#define M_pin  7    //  middle
#define R_pin  8    //  right


void tracking()
{

    int flag = 0;
    char bluetooth_val;

    while (flag == 0)
    {

        int L_val;
        int M_val;
        int R_val;

        if (Serial.available())
        {
            bluetooth_val = Serial.read();
            Serial.println(bluetooth_val);

            if (bluetooth_val == 'S') {
                flag = 1;

                break;
            }
        }

        L_val = digitalRead(L_pin);
        M_val = digitalRead(M_pin);
        R_val = digitalRead(R_pin);

        if (M_val == 1) { //the middle one detects black lines

            if (L_val == 1 && R_val == 0)   //If a black line is detected on the left, but not on the right, turn left
            {
                CCart::Get()->Left();
            }
            else if (L_val == 0 && R_val == 1)     //If a black line is detected on the right, not on the left, turn right
            {
                CCart::Get()->Right();
            }
            else    //go front
            {
                CCart::Get()->Front();
            }
        }
        else  // the middle sensor doesn’t detect black lines
        {
            if (L_val == 1 && R_val == 0)  // If a black line is detected on the left, but not on the right, turn left
            {
                CCart::Get()->Left();
            }
            else if (L_val == 0 && R_val == 1)   // If a black line is detected on the right, not on the left, turn right
            {
                CCart::Get()->Right();
            }
            else   // otherwise stop
            {

                CCart::Get()->Stop();

            }
        }


    }
}

void Back()
{
    CCart::Get()->Back();
    delay(200);
    CCart::Get()->Left();
    delay(700);
    CCart::Get()->Back();
}

//Control the ultrasonic sensor
float checkdistance()
{
    float distance;
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    distance = pulseIn(Echo, HIGH) / 58.20;  //
    delay(10);
    return distance;
}


void follow()
{

    int flag = 0;
    int sensor_L;
    int sensor_R;
    int distance;

    while (flag == 0)
    {

        if (Serial.available())
        {
            char bluetooth_val;
            bluetooth_val = Serial.read();
            Serial.println(bluetooth_val);

            if (bluetooth_val == 'S') {
                flag = 1;
                break;
            }
        }

        distance = checkdistance();
        sensor_L = digitalRead(light_L_Pin);
        sensor_R = digitalRead(light_R_Pin);

        if (distance <= 5 || sensor_L == 0 && sensor_R == 0)
        {

            CCart::Get()->Front();

        }
        else if (distance > 5 && (sensor_L == 0 && sensor_R == 1))
        {

            CCart::Get()->Right();

        }
        else if (distance > 5 && (sensor_L == 1 && sensor_R == 0))
        {

            CCart::Get()->Left();

        }
        else if ((distance > 5 && distance <= 15) && (sensor_L == 1 && sensor_R == 1))
        {

            //digitalWrite(6, LOW);
            //analogWrite(4, 0);
            //digitalWrite(5, LOW);
            //analogWrite(2, 0);

            CCart::Get()->Stop();
        }
        else if ((distance > 15 && distance <= 35) && (sensor_L == 1 && sensor_R == 1))
        {

            //digitalWrite(6, HIGH);
            //analogWrite(4, 255);
            //digitalWrite(5, HIGH);
            //analogWrite(2, 255);
            CCart::Get()->Front();
        }
        else if (distance > 35 && (sensor_L == 1 && sensor_R == 1))
        {

            //digitalWrite(6, LOW);
            //analogWrite(4, 0);
            //digitalWrite(5, LOW);
            //analogWrite(2, 0);

            CCart::Get()->Stop();
        }
    }
}

void avoid()
{
    int sensor_L;
    int sensor_R;
    int distance;
    int flag = 0;

    while (flag == 0)
    {

        if (Serial.available())
        {
            char bluetooth_val;
            bluetooth_val = Serial.read();
            Serial.println(bluetooth_val);
            if (bluetooth_val == 'S') {
                flag = 1;
                break;
            }
        }

        distance = checkdistance();
        sensor_L = digitalRead(light_L_Pin);
        sensor_R = digitalRead(light_R_Pin);

        if (sensor_L == 0 && sensor_R == 0) {
            CCart::Get()->Back();

            delay(1000);
            CCart::Get()->Left();
            delay(500);

        }
        else if (sensor_L == 1 && sensor_R == 0) {


            CCart::Get()->Left();
        }
        else if (sensor_L == 0 && sensor_R == 1) {
            CCart::Get()->Right();
        }
        else if (distance <= 10 && (sensor_L == 1 && sensor_R == 1)) {

            CCart::Get()->Left();
        }
        else if (distance > 10 && (sensor_L == 1 && sensor_R == 1)) {

            CCart::Get()->Front();
        }

    }
}

void setup()
{
    CTimer::CreateInstance();
    CCart::CreateInstance();
    CMusic::CreateInstance();


    CMusic::Get()->Init(tonePin);
    CCart::Get()->Init();

    Serial.begin(115200);

    pinMode(led_Pin, OUTPUT);
    pinMode(tonePin, OUTPUT);

    //
    // track sensor
    //
    pinMode(L_pin, INPUT);
    pinMode(M_pin, INPUT);
    pinMode(R_pin, INPUT);

    pinMode(12, OUTPUT);
    pinMode(13, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
}

void loop()
{

    if (Serial.available())
    {
        char bluetooth_val;

        bluetooth_val = Serial.read();
        Serial.println(bluetooth_val);

        switch (bluetooth_val)
        {
        case 'F':
            CCart::Get()->Front();
            break;

        case 'B':
            CCart::Get()->Back();
            break;

        case 'L':
            CCart::Get()->Left();
            break;

        case 'R':
            CCart::Get()->Right();
            break;

        case 'S':
            CCart::Get()->Stop();
            //noTone(tonePin);
            break;

        /*case 'Q':
            CCart::Get()->Left();
            break;

        case 'E':
            CCart::Get()->Right();
            break;

        case 'W':
            //CCart::Get()->Front();
            CCart::Get()->FFront();
            break;*/

        case 'a': // led on
            digitalWrite(led_Pin, HIGH);
            break;

        case 'b': // led off
            digitalWrite(led_Pin, LOW);
            break;

        case 'f':
            Back();
            break;

        case 'h':
            follow();
            break;

        case 'e':
            tracking();
            break;

        case 'g':
            avoid();
            break;

        case '1':
            tone(tonePin, 262, 500);
            break;

        case '2':
            tone(tonePin, 294, 500);
            break;

        case '3':
            tone(tonePin, 330, 500);
            break;

        case '4':
            tone(tonePin, 349, 500);
            break;

        case '5':
            tone(tonePin, 392, 500);
            break;

        case '6':
            tone(tonePin, 440, 500);
            break;

        case '7':
            tone(tonePin, 494, 500);
            break;

        case '8':
            tone(tonePin, 532, 500);
            break;

            //The following three signals are mainly used for cyclic printing
        case 'x':
        {

            float distance = checkdistance();
            Serial.println(distance);
            delay(50);
            break;
        }

        case 'w':
        {
            int left_light = analogRead(light_L_Pin);
            Serial.println(left_light);
            delay(50);
            break;
        }

        case 'y':
        {
            int right_light = analogRead(light_R_Pin);
            Serial.println(right_light);
            delay(50);
            break;
        }


        case 'k':
            CMusic::Get()->super_mario();
            break;

        case 'l':
            CMusic::Get()->star_war_tone();
            break;

        case 'm':
            CMusic::Get()->birthday();
            break;

        case 'n':
            CMusic::Get()->christmas();
            break;

        case 'o':
            CMusic::Get()->Ode_to_Joy();
            break;

        case 'p':
            CMusic::Get()->popcorn();
            break;

        case 'z':
            CMusic::Get()->Stop();
            break;


        default:;
        }
    }

    CCart::Get()->Update();
    CMusic::Get()->Update();

}
