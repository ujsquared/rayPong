/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Title Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"
#include "gui_elements.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

// typedef struct {
//    int buttonX;
//    int buttonY;
//    char* buttonText;
//    float fontSize;
// } button;
//
// void DrawButton(button b){
//     Color fillingRectangle = {255, 255, 255, 50};
//     int lengthOfText = MeasureText(b.buttonText, font.baseSize*b.fontSize);
//     Vector2 posOfButton = { b.buttonX, b.buttonY };
//     Vector2 posOfText = { b.buttonX + 30, b.buttonY + 10 };
//     DrawRectangle(b.buttonX, b.buttonY, lengthOfText+30, 50, fillingRectangle);
//     DrawTextEx(font, b.buttonText, posOfText, font.baseSize*b.fontSize, 4, WHITE); // 230, 85
// };

//----------------------------------------------------------------------------------
// Title Screen Functions Definition
//----------------------------------------------------------------------------------

// Title Screen Initialization logic
void InitTitleScreen(void)
{
    // TODO: Initialize TITLE screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Title Screen Update logic
void UpdateTitleScreen(void)
{
    // TODO: Update TITLE screen variables here!

    // Press enter or tap to change to GAMEPLAY screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        //finishScreen = 1;   // OPTIONS
        finishScreen = 2;   // GAMEPLAY
        PlaySound(fxCoin);
    }
}

// Title Screen Draw logic
void DrawTitleScreen(void)
{
    // TODO: Draw TITLE screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
    Vector2 posOfGameName = { 290, 85 };
    Vector2 posOfPlayHitbox = { 560, 525 };
    Vector2 posOfOptionsHitbox = { 560, 585 };
    DrawTextEx(font, "myPong (exactly what it sounds like)", posOfGameName, font.baseSize*4.0f, 4, WHITE); // 230, 85
    button option0 = { 530, 460, "PLAY", 2};
    button option1 = { 530, 520, "OPTIONS", 2};
    DrawButton(option0); 
    DrawButton(option1); 
    // DrawTextEx(font, "PLAY", posOfPlayHitbox, font.baseSize*2.0f, 4, WHITE); // 230, 85
    // DrawTextEx(font, "OPTIONS", posOfOptionsHitbox, font.baseSize*2.0f, 4, WHITE); // 230, 85
}

// Title Screen Unload logic
void UnloadTitleScreen(void)
{
    // TODO: Unload TITLE screen variables here!
}

// Title Screen should finish?
int FinishTitleScreen(void)
{
    return finishScreen;
}
