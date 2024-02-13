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
#define NOTE_E8  5274
#define NOTE_F8  5588
#define NOTE_FS8 5920
#define NOTE_G8  6272
#define NOTE_GS8 6645
#define NOTE_A8  7040
#define NOTE_AS8 7459
#define NOTE_B8  7902

//C	        8.18	16.35	32.70	65.41	130.81	261.63	523.25	1046.50	2093.00	4186.01	8372.02	    16744.04
//C# / Db	8.66	17.32	34.65	69.30	138.59	277.18	554.37	1108.73	2217.46	4434.92	8869.84	    17739.69
//D	        9.18	18.35	36.71	73.42	146.83	293.66	587.33	1174.66	2349.32	4698.64	9397.27	    18794.54
//D# / Eb	9.72	19.45	38.89	77.78	155.56	311.13	622.25	1244.51	2489.02	4978.03	9956.06	    19912.13
//E	       10.30	20.60	41.20	82.41	164.81	329.63	659.26	1318.51	2637.02	5274.04	10548.08	21096.16
//F	       10.91	21.83	43.65	87.31	174.61	349.23	698.46	1396.91	2793.83	5587.65	11175.30	22350.61
//F# / Gb  11.56	23.12	46.25	92.50	185.00	369.99	739.99	1479.98	2959.96	5919.91	11839.82	23679.64
//G	       12.25	24.50	49.00	98.00	196.00	392.00	783.99	1567.98	3135.96	6271.93	12543.85	25087.71
//G# / Ab  12.98	25.96	51.91	103.83	207.65	415.30	830.61	1661.22	3322.44	6644.88	13289.75	26579.50
//A	       13.75	27.50	55.00	110.00	220.00	440.00	880.00	1760.00	3520.00	7040.00	14080.00	28160.00
//A# / Bb  14.57	29.14	58.27	116.54	233.08	466.16	932.33	1864.66	3729.31	7458.62	14917.24	29834.48
//B	       15.43	30.87	61.74	123.47	246.94	493.88	987.77	1975.53	3951.07	7902.13	15804.27	31608.53

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
const int Ode_to_Joy_tune[] =
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

float Ode_to_Joy_durt[] =
{
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1+0.5, 0.5, 1+1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1+0.5,0.5,1+1,
    1,1,1,1,
    1,0.5,0.5,1,1,
    1,0.5,0.5,1,1,
    1,1,1,1,
    1,1,1,1,
    1,1,1,0.5,0.5,
    1,1,1,1,
    1+0.5,0.5,1+1,
};

const int birthday_tune[] = {
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
    NOTE_C5

};

const int birthday_durt[] = {
    250,
    250,
    250,
    250,
    500,
    250,
    250,
    250,
    250,
    500,
    250,
    250,
    250,
    250,
    250,
    250,
    375,
    250,
    250,
    250,
    500
};

/*
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
#define NOTE_E8  5274
#define NOTE_F8  5588
#define NOTE_FS8 5920
#define NOTE_G8  6272
#define NOTE_GS8 6645
#define NOTE_A8  7040
#define NOTE_AS8 7459
#define NOTE_B8  7902
*/

int popcorn_tune[] =
{
    4063,   4561,   4063,   5424,   6834,   5424,   8127,   4063,
    4561,   4063,   5424,   6834,   5424,   8127,   4063,   3620,
    3417,   3620,   3417,   4063,   3620,   4063,   3620,   4561,
    4063,   4561,   4063,   5120,   4063,   4063,   4561,   4063,
    5424,   6834,   5424,   8127,   4063,   4561,   4063,   5424,
    6834,   5424,   8127,   4063,   3620,   3417,   3620,   3417,
    4063,   3620,   4063,   3620,   4561,   4063,   4561,   4063,
    3620,   3417,   2712,   3044,   2712,   3417,   4561,   3417,
    5424,   2712,   3044,   2712,   3417,   4561,   3417,   5424,
    2712,   2416,   2280,   2416,   2280,   2712,   2416,   2712,
    2416,   3044,   2712,   3044,   2712,   3417,   2712,   2712,
    3044,   2712,   3417,   4561,   3417,   5424,   2712,   3044,
    2712,   3417,   4561,   3417,   5424,   2712,   2416,   2280,
    2416,   2280,   2712,   2416,   2712,   2416,   3044,   2712,
    3044,   2712,   3417,   2712,   2032,   2280,   2712,   3417,
    4561,   3417,   5424,   2712,   3044,   2712,   3417,   4561,
    3417,   5424,   2712,   2416,   2280,   2416,   2280,   2712,
    2416,   2712,   2416,   3044,   2712,   3044,   3417,   3044,
    2712,
};

char popcorn_durt[] =
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

int starWar_tune[] = {

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

/*int starWar_durt[] = {

    //
    // first section
    //
    500,    // 1
    50,     // 1/8
    500,    // 1
    50,     // 1/8
    500,    // 1
    50,     // 1/8
    350,    // 1/4 *
    150,    // 1/8 *
    500,    // 1
    350,    // 1/4 *
    150,    // 1/8 *
    650,    // 1 *

    500,    // 1

    500,    // 1
    50,     // 1/8 
    500,    // 1
    50,     // 1/8
    500,    // 1
    50,     //
    350,    // 1/4 *
    150,    // 1/8*
    500,    // 1
    350,    // 1/4 *
    150,    // 1/8*
    650,    // 1 *

    500,    // 1

    //
    // second section
    //

    500,    // 1
    300,    // 1/4 *
    150,    // 1/8 *
    500,    // 1
    325,    // 1/4 *
    175,    // 1/8 *
    125,    // 1/8
    125,    // 1/8
    250,


    325,

    250,
    500,
    325,
    175,
    125,
    125,
    250,

    350,

    //
    // Variant 1
    //
    250,
    500,
    350,
    125,
    500,
    375,
    125,
    650,

    //
    // Repeat second section
    //
    500,
    300,
    150,
    500,
    325,
    175,
    125,
    125,
    250,


    325,

    250,
    500,
    325,
    175,
    125,
    125,
    250,

    350,

    //
    // Variant 2
    //
    250,
    500,
    375,
    125,
    500,
    375,
    125,
    650,

    650
};*/

char starWar_durt[] = {

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

// Pitch + duration.
// 4 represents a quarter note, 8 represents an eighth note, 16 represents a sixteenth note, and so on.
// Negative numbers are used to represent dotted notes, for example -4 represents a dotted quarter note, which is equivalent to a quarter note plus an eighth note!!
int melody[] = {
    //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192  //The song 198 has a total of 198 values for pitch + duration, which is 396 bytes (sizeof(melody) = 396)

    NOTE_E5, 4,  NOTE_B4, 8,  NOTE_C5, 8,  NOTE_D5, 4,  NOTE_C5, 8,  NOTE_B4, 8,
    NOTE_A4, 4,  NOTE_A4, 8,  NOTE_C5, 8,  NOTE_E5, 4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,8,  NOTE_B4,8,  NOTE_C5,8,

    NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
    NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

    NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
    NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

    NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
    NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,


    NOTE_E5,2,  NOTE_C5,2,
    NOTE_D5,2,   NOTE_B4,2,
    NOTE_C5,2,   NOTE_A4,2,
    NOTE_GS4,2,  NOTE_B4,4,  REST,8, 
    NOTE_E5,2,   NOTE_C5,2,
    NOTE_D5,2,   NOTE_B4,2,
    NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
    NOTE_GS5,2,
};

// array of note frequencies
int tune_christmas[]=
{
    NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,
    NOTE_A4,NOTE_CS4,NOTE_F4,NOTE_G4,NOTE_A4,NTF0,
    NOTE_B4,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,
    NOTE_CS4,NOTE_CS4,NOTE_B4,NOTE_G4,NOTE_F4,NTF0,

    NOTE_C4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_C4,NTF0,NOTE_C4,NOTE_C4,
    NOTE_C4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_D4,NTF0,
    NOTE_D4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_E4,NTF0,
    NOTE_CS4,NOTE_CS4,NOTE_B4,NOTE_G4,NOTE_A4,NOTE_F4,NTF0,

    NOTE_C4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_C4,NTF0,
    NOTE_C4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_D4,NTF0,NOTE_D4,
    NOTE_D4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_CS4,NOTE_CS4,NOTE_CS4,NOTE_CS4,
    NOTE_DS5,NOTE_CS4,NOTE_B4,NOTE_G4,NOTE_F4,NTF0
};

/*int durt_christmas[] =
{
    4, 4, 2, 4, 4, 2,
    4, 4, 3, 4, 1.5, 0.5,
    0.5, 0.5, 1, 0.5,0.5, 0.5,0.5,0.25,0.25,
    0.5, 0.5, 0.5, 0.5, 1.5,0.5,

    0.5,0.5,0.5,0.5,1,0.5,0.25,0.25,
    0.5,0.5,0.5,0.5,1,1,
    0.5,0.5,0.5,0.5,1,1,
    0.5,0.5,0.5,0.5,1,0.75,0.25,

    0.5,0.5,0.5,0.5,1,1,
    0.5,0.5,0.5,0.5,1,0.5,0.5,
    0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
    0.5,0.5,0.5,0.5,0.75,0.25
};*/
// note beat array
float durt_christmas[] =
{
    0.5, 0.5, 1, 0.5, 0.5, 1,
    0.5, 0.5, 0.75, 0.25, 1.5, 0.5,
    0.5, 0.5, 1, 0.5,0.5, 0.5,0.5,0.25,0.25,
    0.5, 0.5, 0.5, 0.5, 1.5,0.5,

    0.5,0.5,0.5,0.5,1,0.5,0.25,0.25,
    0.5,0.5,0.5,0.5,1,1,
    0.5,0.5,0.5,0.5,1,1,
    0.5,0.5,0.5,0.5,1,0.75,0.25,

    0.5,0.5,0.5,0.5,1,1,
    0.5,0.5,0.5,0.5,1,0.5,0.5,
    0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
    0.5,0.5,0.5,0.5,0.75,0.25
};

// Mario theme
int mario_melody[] =
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
char mario_durt[] = {
    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,

    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,

    12, 12, 12,               ////////////////
    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,

    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,

    12, 12, 12,             //////////////////
    9, 9, 9, 9,
    9, 9, 9, 9,
    9, 9, 9, 9,
};

//Underworld melody_mario
int underworld_melody_mario[] = {
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
int underworld_tempo_mario[] = {
    12, 12, 12, 12,
    12, 12, 6,
    3,
    12, 12, 12, 12,
    12, 12, 6,
    3,
    12, 12, 12, 12,
    12, 
    12,// 1/2
    6, // 1/4
    3, // 1/8
    12, 12, 12, 12,
    12, 12, 6,
    6, 18, 18, 18,
    6, 6,
    6, 6,
    6, 6,
    18, 18, 18, 18, 18, 18,
    10, 10, 10,
    10, 10, 10,
    3, 3, 3
};
#endif
