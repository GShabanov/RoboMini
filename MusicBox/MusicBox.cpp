// MusicBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include "music.h"

int
main()
{
    CMusic::CreateInstance();

    CMusic::Get()->Init(0);


    CMusic::Get()->popcorn();

    do
    {

    }
    while (CMusic::Get()->Update() == true);

}

