#ifndef ARRAY_H_
#define ARRAY_H_ 

#define NTF0 -1
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AE4 455
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976

#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define NOTE_A8  7040
#define NOTE_AS8 7459
#define NOTE_B8  7902

#define NOTE_C9  8372
#define NOTE_CS9 8870
#define NOTE_D9  9397
#define NOTE_DS9 9956
#define NOTE_E9  10548
#define NOTE_F9  11175
#define NOTE_FS9 11840
#define NOTE_G9  12544
#define NOTE_GS9 13290
#define NOTE_A9  14080
#define NOTE_AS9 14917
#define NOTE_B9  15804

#define NOTE_C10  16744
#define NOTE_CS10 17740
#define NOTE_D10  18795
#define NOTE_DS10 19912
#define NOTE_E10  21096
#define NOTE_F10  22351
#define NOTE_FS10 23680
#define NOTE_G10  25088
#define NOTE_GS10 26580
#define NOTE_A10  28160
#define NOTE_AS10 29834
#define NOTE_B10  31609

#define REST 0

//tone
#define D0 -1
#define D1 262
#define D2 293
#define D3 329
#define D4 349
#define D5 392
#define D6 440
#define D7 494
#define M1 523
#define M2 586
#define M3 658
#define M4 697
#define M5 783
#define M6 879
#define M7 987
#define H1 1045
#define H2 1171
#define H3 1316
#define H4 1393
#define H5 1563
#define H6 1755
#define H7 1971

#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625

//tone
const PROGMEM int Ode_to_Joy_tune[]  =
{
    NOTE_E5,
    NOTE_E5,
    NOTE_F5,
    NOTE_G5,
    NOTE_G5,
    NOTE_F5,
    NOTE_E5,
    NOTE_D5,
    NOTE_C5,
    NOTE_C5,
    NOTE_D5,
    NOTE_E5,
    NOTE_E5,
    NOTE_D5,
    NOTE_D5,
    NOTE_E5,
    NOTE_E5,
    NOTE_F5,
    NOTE_G5,
    NOTE_G5,
    NOTE_F5,
    NOTE_E5,
    NOTE_D5,
    NOTE_C5,
    NOTE_C5,
    NOTE_D5,
    NOTE_E5,
    NOTE_D5,
    NOTE_C5,
    NOTE_C5,
    NOTE_D5,
    NOTE_D5,
    NOTE_E5,
    NOTE_C5,
    NOTE_D5,
    NOTE_E5,
    NOTE_F5,
    NOTE_E5,
    NOTE_C5,
    NOTE_D5,
    NOTE_E5,
    NOTE_F5,
    NOTE_E5,
    NOTE_D5,
    NOTE_C5,
    NOTE_D5,
    NOTE_G4,
    NTF0,       // ?
    NOTE_E5,
    NOTE_E5,
    NOTE_F5,
    NOTE_G5,
    NOTE_G5,
    NOTE_F5,
    NOTE_E5,
    NOTE_F5,
    NOTE_D5,
    NOTE_C5,
    NOTE_C5,
    NOTE_D5,
    NOTE_E5,
    NOTE_D5,
    NOTE_C5,
    NOTE_C5
};

const PROGMEM char Ode_to_Joy_durt[]  =
{
    4, 4, 4, 4,    // 1, 1, 1, 1,
    4, 4, 4, 4,
    4, 4, 4, 4,
    6, 2, 8,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    6, 2, 8,
    4, 4, 4, 4,
    4, 2, 2, 4, 4,
    4, 2, 2, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 2, 2,
    4, 4, 4, 4,
    6, 2, 8,
};

const PROGMEM int birthday_tune[] = {
    NOTE_D4,
    NOTE_A4,
    NOTE_G4,
    NOTE_C5,
    NOTE_B4,
    NOTE_G4,
    NOTE_A4,
    NOTE_G4,
    NOTE_D5,
    NOTE_C5,
    NOTE_G4,
    NOTE_G5,
    NOTE_E5,
    NOTE_C5,
    NOTE_B4,
    NOTE_A4,
    NOTE_F5,
    NOTE_E5,
    NOTE_C5,
    NOTE_D5,
    NOTE_C5,
    NOTE_A4,
};

const PROGMEM char birthday_durt[] = {
    5,              
    5,
    5,
    5,
    10,
    5,
    5,
    5,
    5,
    10,
    5,
    5,
    5,
    5,
    5,
    5,
    7,
    5,
    5,
    5,
    10,
    10
};


const PROGMEM int starWar_tune[] = {

    //
    // first section
    //
    NOTE_A4,
    REST,
    NOTE_A4,
    REST,
    NOTE_A4,
    REST,
    NOTE_F4,
    NOTE_C5,
    NOTE_A4,
    NOTE_F4,
    NOTE_C5,
    NOTE_A4,
    REST,

    NOTE_E5,
    REST,
    NOTE_E5,
    REST,
    NOTE_E5,
    REST,
    NOTE_F5,
    NOTE_C5,
    NOTE_GS4,
    NOTE_F4,
    NOTE_C5,
    NOTE_A4,
    REST,

    //
    // second section
    //
    NOTE_A5,
    NOTE_A4,
    NOTE_A4,
    NOTE_A5,
    NOTE_GS5,
    NOTE_G5,
    NOTE_FS5,
    NOTE_F5,
    NOTE_FS5,

    REST,

    NOTE_AE4,
    NOTE_DS5,
    NOTE_D5,
    NOTE_CS5,
    NOTE_C5,
    NOTE_AS4,
    NOTE_C5,

    REST,

    //
    // Variant 1
    //
    NOTE_F4,
    NOTE_GS4,
    NOTE_F4,
    NOTE_A4,
    NOTE_C5,
    NOTE_A4,
    NOTE_C5,
    NOTE_E5,

    //
    // Repeat second section
    //
    NOTE_A5,
    NOTE_A4,
    NOTE_A4,
    NOTE_A5,
    NOTE_GS5,
    NOTE_G5,
    NOTE_FS5,
    NOTE_F5,
    NOTE_FS5,

    REST,

    NOTE_AE4,
    NOTE_DS5,
    NOTE_D5,
    NOTE_CS5,
    NOTE_C5,
    NOTE_AS4,
    NOTE_C5,

    REST,

    //
    // Variant 2
    //
    NOTE_F4,
    NOTE_GS4,
    NOTE_F4,
    NOTE_C5,
    NOTE_A4,
    NOTE_F4,
    NOTE_C5,
    NOTE_A4,


    REST
};

const PROGMEM char starWar_durt[] = {

    //                         //
    // first section           // first section 
    //                         //
    10,                        // 500,    // 1
    1,                         // 50,     // 1/8
    10,                        // 500,    // 1
    1,                         // 50,     // 1/8
    10,                        // 500,    // 1
    1,                         // 50,     // 1/8
    7,                         // 350,    // 1/4 *
    3,                         // 150,    // 1/8 *
    10,                        // 500,    // 1
    7,                         // 350,    // 1/4 *
    3,                         // 150,    // 1/8 *
    13,                        // 650,    // 1 *

    10,                        // 500,    // 1

    10,                        // 500,    // 1
    1,                         // 50,     // 1/8 
    10,                        // 500,    // 1
    1,                         // 50,     // 1/8
    10,                        // 500,    // 1
    1,                         // 50,     //
    7,                         // 350,    // 1/4 *
    3,                         // 150,    // 1/8*
    10,                        // 500,    // 1
    7,                         // 350,    // 1/4 *
    3,                         // 150,    // 1/8*
    13,                        // 650,    // 1 *

    10,                        // 500,    // 1

    //                         //
    // second section          // second section
    //                         //

    10,                        // 500,    // 1
    6,                         // 300,    // 1/4 *
    3,                         // 150,    // 1/8 *
    10,                        // 500,    // 1
    -6,                        // 325,    // 1/4 *
    -3,                        // 175,    // 1/8 *
    -2,                        // 125,    // 1/8
    -2,                        // 125,    // 1/8
    5,                         // 250,


    -6,                        // 325,

    5,                         // 250,
    10,                        // 500,
    -6,                        // 325,
    -3,                        // 175,
    -2,                        // 125,
    -2,                        // 125,
    5,                         // 250,

    7,                         // 350,

    //                         //
    // Variant 1               // Variant 1
    //                         //
    5,                         // 250,
    10,                        // 500,
    7,                         // 350,
    -2,                        // 125,
    10,                        // 500,
    -6,                        // 375,
    -2,                        // 125,
    13,                        // 650,

    //                         //
    // Repeat second section   // Repeat second section
    //                         //
    10,                        // 500,
    6,                         // 300,
    3,                         // 150,
    10,                        // 500,
    -6,                        // 325,
    -3,                        // 175,
    -2,                        // 125,
    -2,                        // 125,
    5,                         // 250,


    -6,                        // 325,

    5,                         // 250,
    10,                        // 500,
    -6,                        // 325,
    -3,                        // 175,
    -2,                        // 125,
    -2,                        // 125,
    5,                         // 250,
                                
    7,                         // 350,

    //                         //
    // Variant 2               // Variant 2
    //                         //
    5,                         // 250,
    10,                        // 500,
    -6,                        // 375,
    -2,                        // 125,
    10,                        // 500,
    -6,                        // 375,
    -2,                        // 125,
    13,                        // 650,

    13                         // 650
};

#if 0
int popcorn_tune[] = {
    // 2x
    NOTE_E7,
    NOTE_E5,
    NOTE_E7,
    NOTE_B7,
    NOTE_G7,
    NOTE_B7,
    NOTE_G4,

    REST,

    NOTE_E7,
    NOTE_E5,
    NOTE_E7,
    NOTE_B7,
    NOTE_G7,
    NOTE_B7,
    NOTE_G4,


    // First
    NOTE_E7,
    NOTE_E9,
    NOTE_E10,
    NOTE_E9,
    NOTE_E10,
    NOTE_E7,
    NOTE_E9,
    NOTE_E7,
    NOTE_E9,
    NOTE_E5,
    NOTE_E7,
    NOTE_E5,
    NOTE_B7,
    NOTE_E5,
    NOTE_E5,

    // 2x
    NOTE_E7,
    NOTE_E5,
    NOTE_E7,
    NOTE_B7,
    NOTE_G7,
    NOTE_B7,
    NOTE_G4,

    REST,

    NOTE_E7,
    NOTE_E5,
    NOTE_E7,
    NOTE_B7,
    NOTE_G7,
    NOTE_B7,
    NOTE_G4,

    // Second
    NOTE_E7,
    NOTE_E9,
    NOTE_E10,
    NOTE_E9,
    NOTE_E10,
    NOTE_E7,
    NOTE_E9,
    NOTE_E7,
    NOTE_E9,
    NOTE_E5,
    NOTE_E7,
    NOTE_E5,
    NOTE_E7,
    NOTE_E9,
    NOTE_E10,

};

char popcorn_durt[] = {
    // 2x
    5,
    5,
    5,
    5,
    5,
    5,
    5,

    // rest
    10,

    5,
    5,
    5,
    5,
    5,
    5,
    5,


    // First
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,

    // 2x
    5,
    5,
    5,
    5,
    5,
    5,
    5,

    // rest
    10,

    5,
    5,
    5,
    5,
    5,
    5,
    5,

    // Second
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,


};

#endif // if 0

const PROGMEM int WilliamTell_tune[] =
{
  4561, 4561, 4561, 4561, 4561, 4561, 4561, 4561,
   0xd59,  0xbe4,  0xa98, 4561, 4561, 4561, 4561, 4561,
  4561,  0xd59,  0xa98,  0xbe4,  0xe24, 4561, 4561, 4561,
  4561, 4561, 4561, 4561, 4561, 4561,  0xd59,  0xbe4,
   0xa98,  0xd59,  0xa98,  0x8e8,  0xa00,  0xa98,  0xbe4,  0xd59,
   0xa98,  0xd59, 4561, 4561, 4561, 4561, 4561, 4561,
  4561, 4561,  0xd59,  0xbe4,  0xa98, 4561, 4561, 4561,
  4561, 4561, 4561,  0xd59,  0xa98,  0xbe4,  0xe24, 4561,
  4561, 4561, 4561, 4561, 4561, 4561, 4561, 4561,
   0xd59,  0xbe4,  0xa98,  0xd59,  0xa98,  0x8e8,  0xa00,  0xa98,
   0xbe4,  0xd59,  0xa98,  0xd59,  0xa98,  0xa98,  0xa98,  0xa98,
   0xa98,  0xa98,  0xa98,  0xa98,  0xa98,  0x7f0,  0xa98,  0x7f0,
   0xa98,  0x7f0,  0xa98,  0xbe4,  0xd59,  0xe24,  4063,  0xa98,
   0xa98,  0xa98,  0xa98,  0xa98,  0xa98,  0xa98,  0xa98,  0xa98,
   0x7f0,  0xa98,  0x7f0,  0xa98,  0x7f0,  0x8e8,  0x970,  0x8e8,
   0x970,  0x8e8,  0xa98,  0xa98,  0xa98,  0xa98,  0xa98,  0xa98,
   0xa98,  0xa98,  0xa98,  0x7f0,  0xa98,  0x7f0,  0xa98,  0x7f0,
   0xa98,  0xbe4,  0xd59,  0xe24,  4063,  0xa98,  0xa98,  0xa98,
   0xa98,  0xa98,  0xa98,  0xa98,  0xa98,  0xa98,  0x7f0,  0xa98,
   0x7f0,  0xa98,  0x7f0,  0x8e8,  0x970,  0x8e8,  0x970,  0x8e8
};

const PROGMEM char WilliamTell_durt[] =
{
  2,2,4,2, 2, 4, 2, 2,
  4,4,4,2, 2, 4, 2, 2,
  4,2,2,4, 4, 4, 2, 2,
  4,2,2,4, 2, 2, 4, 4,
  4,2,2,10,2, 2, 2, 4,
  4,4,2,2, 4, 2, 2, 4,
  2,2,4,4, 4, 2, 2, 4,
  2,2,4,2, 2, 4, 4, 4,
  2,2,4,2, 2, 4, 2, 2,
  4,4,4,2, 2, 10,2, 2,
  2,4,4,4, 2, 2, 4, 2,
  2,4,2,2, 4, 4, 4, 4,
  4,4,4,4, 4, 4, 4, 2,
  2,4,2,2, 4, 2, 2, 4,
  4,4,4,4, 4, 4, 4, 4,
  4,4,2,2, 4, 2, 2, 4,
  2,2,4,4, 4, 4, 4, 4,
  4,4,4,4, 4, 2, 2, 4,
  2,2,4,2, 2, 4, 4, 4,
  4,4,4,4, 4, 4, 4, 4
};

const PROGMEM int popcorn_tune[] =
{
   4063,  4561,     4063,  0x1530, 0x1ab2, 0x1530, 0x1fbf,  4063,
  4561,   4063,   0x1530, 0x1ab2, 0x1530, 0x1fbf,  4063,  0xe24,
   0xd59,  0xe24,  0xd59,   4063, 0xe24,   4063,  0xe24,  4561,
   4063,  4561,     4063,  0x1400, 4063,   4063, 4561,  4063,
  0x1530, 0x1ab2, 0x1530,  0x1fbf, 4063,  4561,  4063, 0x1530,
  0x1ab2, 0x1530, 0x1fbf,  4063,  0xe24,   0xd59,  0xe24,  0xd59,
   4063,   0xe24,   4063,  0xe24, 4561,   4063, 4561,  4063,
   0xe24,  0xd59,  0xa98,  0xbe4,  0xa98,   0xd59, 4561,  0xd59,
  0x1530,  0xa98,  0xbe4,  0xa98,  0xd59,  4561,  0xd59, 0x1530,
   0xa98,  0x970,  0x8e8,  0x970,  0x8e8,   0xa98,  0x970,  0xa98,
   0x970,  0xbe4,  0xa98,  0xbe4,  0xa98,   0xd59,  0xa98,  0xa98,
   0xbe4,  0xa98,  0xd59, 4561,  0xd59,  0x1530,  0xa98,  0xbe4,
   0xa98,  0xd59,   4561,  0xd59, 0x1530,  0xa98,   0x970,  0x8e8,
   0x970,  0x8e8,  0xa98,  0x970,  0xa98,  0x970,   0xbe4,  0xa98,
   0xbe4,  0xa98,  0xd59,  0xa98,  0x7f0,  0x8e8,   0xa98,  0xd59,
    4561,  0xd59, 0x1530,  0xa98,  0xbe4,  0xa98,   0xd59, 4561,
   0xd59, 0x1530,  0xa98,  0x970,  0x8e8,  0x970,   0x8e8,  0xa98,
   0x970,  0xa98,  0x970,  0xbe4,  0xa98,  0xbe4,   0xd59,  0xbe4,
   0xa98,

};

const PROGMEM char popcorn_durt[] =
{
  2, 2, 2, 2, 2, 2, 4, 2,
  2, 2, 2, 2, 2, 4, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 4, 2, 2, 2,
  2, 2, 2, 4, 2, 2, 2, 2,
  2, 2, 4, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,
  2, 4, 2, 2, 2, 2, 2, 2,
  4, 2, 2, 2, 2, 2, 2, 4,
  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 4, 2,
  2, 2, 2, 2, 2, 4, 2, 2,
  2, 2, 2, 2, 4, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 4, 2, 2, 2, 2,
  2, 2, 4, 2, 2, 2, 2, 2,
  2, 4, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2,
  4, 

};


// Pitch + duration.
// 4 represents a quarter note, 8 represents an eighth note, 16 represents a sixteenth note, and so on.
// Negative numbers are used to represent dotted notes, for example -4 represents a dotted quarter note, which is equivalent to a quarter note plus an eighth note!!
int tertis_tune[] = {
    //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192  //The song 198 has a total of 198 values for pitch + duration, which is 396 bytes (sizeof(melody) = 396)

    NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,

    NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, REST,

    NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,

    NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, REST, 


    NOTE_E5, NOTE_C5,
    NOTE_D5, NOTE_B4,
    NOTE_C5, NOTE_A4,
    NOTE_GS4, NOTE_B4, REST,
    NOTE_E5, NOTE_C5,
    NOTE_D5, NOTE_B4,
    NOTE_C5, NOTE_E5, NOTE_A5,
    NOTE_GS5,
};

char tertis_durt[] = {
    //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192  //The song 198 has a total of 198 values for pitch + duration, which is 396 bytes (sizeof(melody) = 396)

    4,  8, 8, 4, 8, 8,
    4,  8, 8, 4, 8, 8,
    -4, 8, 4, 4,
    4,  4, 8, 8, 8, 8,

    -4, 8, 4, 8, 8,
    -4, 8, 4, 8, 8,
    4,  8, 8, 4, 4,
    4,  4, 4, 4,

    4,  8, 8, 4, 8, 8,
    4,  8, 8, 4, 8, 8,
    -4, 8, 4, 4,
    4,  4, 8, 4, 8, 8,

    -4, 8, 4, 8, 8,
    -4, 8, 4, 8, 8,
    4,  8, 8, 4, 4,
    4,  4, 4, 4,


    2, 2,
    2, 2,
    2, 2,
    2, 4, 8,
    2, 2,
    2, 2,
    4, 4, 2,
    2,
};

// array of note frequencies
const PROGMEM int tune_christmas[]=
{
    NOTE_A4, NOTE_A4,  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
    NOTE_A4, NOTE_CS4, NOTE_F4, NOTE_G4, NOTE_A4, NTF0,
    NOTE_B4, NOTE_B4,  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
    NOTE_CS4, NOTE_CS4, NOTE_B4, NOTE_G4, NOTE_F4, NTF0,

    NOTE_C4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_C4, NTF0, NOTE_C4, NOTE_C4,
    NOTE_C4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NTF0,
    NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NTF0,
    NOTE_CS4, NOTE_CS4, NOTE_B4, NOTE_G4, NOTE_A4, NOTE_F4, NTF0,

    NOTE_C4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_C4, NTF0,
    NOTE_C4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NTF0, NOTE_D4,
    NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4,
    NOTE_DS5, NOTE_CS4, NOTE_B4, NOTE_G4, NOTE_F4, NTF0
};

const PROGMEM char durt_christmas[] = {
    2, 2, 4, 2, 2, 4,        // 0.5, 0.5, 1, 0.5, 0.5, 1,
    2, 2, 3, 1, 6, 2,        // 0.5, 0.5, 0.75, 0.25, 1.5, 0.5,
    2, 2, 4, 2, 2, 2, 2, 1, 1,   // 0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.25, 0.25,
    2, 2, 2, 2, 6, 2,            // 0.5, 0.5, 0.5, 0.5, 1.5, 0.5,

    2, 2, 2, 2, 4, 2, 1, 1,     // 0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.25, 0.25,
    2, 2, 2, 2, 4, 4,           // 0.5, 0.5, 0.5, 0.5, 1, 1,
    2, 2, 2, 2, 4, 4,           // 0.5, 0.5, 0.5, 0.5, 1, 1,
    2, 2, 2, 2, 4, 3, 1,        // 0.5, 0.5, 0.5, 0.5, 1, 0.75, 0.25,

    2, 2, 2, 2, 4, 4,           // 0.5, 0.5, 0.5, 0.5, 1, 1,
    2, 2, 2, 2, 4, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 3, 1
};

// Mario theme
const PROGMEM int mario_melody[] =
{
    NOTE_E7, NOTE_E7, 0, NOTE_E7,
    0, NOTE_C7, NOTE_E7, 0,
    NOTE_G7, 0, 0,  0,
    NOTE_G6, 0, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,

    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,

    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0
};

// Mario main them tempo_mario
const PROGMEM char mario_durt[] = {                                 // 18 - 3, 12 - 6,  10 - 10, 6 - 12, 3 - 18
    6, 6, 6, 6,
    6, 6, 6, 6,
    6, 6, 6, 6,
    6, 6, 6, 6,

    6, 6, 6, 6,
    6, 6, 6, 6,
    6, 6, 6, 6,
    6, 6, 6, 6,

    10, 10, 10,               ////////////////
    6, 6, 6, 6,
    6, 6, 6, 6,
    6, 6, 6, 6,

    6, 6, 6, 6,
    6, 6, 6, 6,
    6, 6, 6, 6,
    6, 6, 6, 6,

    10, 10, 10,             //////////////////
    6, 6, 6, 6,
    6, 6, 6, 6,
    6, 6, 6, 6,
};

//Underworld melody_mario
const PROGMEM int underworld_melody_mario[] = {
    NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
    NOTE_AS3, NOTE_AS4, 0,
    0,
    NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
    NOTE_AS3, NOTE_AS4, 0,
    0,
    NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
    NOTE_DS3, NOTE_DS4, 0,
    0,
    NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
    NOTE_DS3, NOTE_DS4, 0,
    0, NOTE_DS4, NOTE_CS4, NOTE_D4,
    NOTE_CS4, NOTE_DS4,
    NOTE_DS4, NOTE_GS3,
    NOTE_G3, NOTE_CS4,
    NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
    NOTE_GS4, NOTE_DS4, NOTE_B3,
    NOTE_AS3, NOTE_A3, NOTE_GS3,
    0, 0, 0
};

// Underwolrd tempo_mario
const PROGMEM char underworld_tempo_mario[] = {   // 18 - 3, 12 - 6,  10 - 10, 6 - 12, 3 - 18
    6, 6, 6, 6,
    6, 6, 12,
    18,
    6, 6, 6, 6,
    6, 6, 12,
    18,
    6, 6, 6, 6,
    6, 6, 12,
    18,
    6, 6, 6, 6,
    6, 6, 12,
    12, 3, 3, 3,
    12, 12,
    12, 12,
    12, 12,
    3, 3, 3, 3, 3, 3,
    10, 10, 10,
    10, 10, 10,
    18, 18, 18
};
#endif
