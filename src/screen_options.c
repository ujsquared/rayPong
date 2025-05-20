/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Options Screen Functions Definitions (Init, Update, Draw, Unload)
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
// Options Screen Functions Definition
//----------------------------------------------------------------------------------

// Options Screen Initialization logic
void InitOptionsScreen(void)
{
    // TODO: Initialize OPTIONS screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Options Screen Update logic
void UpdateOptionsScreen(void)
{
    // TODO: Update OPTIONS screen variables here!
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        //finishScreen = 1;   // OPTIONS
        finishScreen = 2;   // GAMEPLAY
        PlaySound(fxCoin);
    }
}

// Options Screen Draw logic
void DrawOptionsScreen(void)
{
    // TODO: Draw OPTIONS screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
    Vector2 posOfHeading = { 490, 85 };
    Vector2 posOfOpt1 = { 560, 525 };
    Vector2 posOfOpt2 = { 560, 585 };
    Color fillingRectangle = {255, 255, 255, 50};
    // DrawRectangle(530, 520, 150, 50, fillingRectangle);
    // DrawRectangle(530, 579, 150, 50, fillingRectangle);
    DrawTextEx(font, "OPTIONS", posOfHeading, font.baseSize*7.0f, 4, WHITE); // 230, 85
    button option0 = { 530, 460, "Option", 2};
    button option1 = { 530, 520, "Option", 2};
    button option2 = { 530, 579, "Option", 2};
    DrawButton(option0); 
    DrawButton(option1); 
    DrawButton(option2); 
    // DrawTextEx(font, "Option 1", posOfOpt1, font.baseSize*2.0f, 4, WHITE); // 230, 85
    // DrawTextEx(font, "Option 2", posOfOpt2, font.baseSize*2.0f, 4, WHITE); // 230, 85
}

// Options Screen Unload logic
void UnloadOptionsScreen(void)
{
    // TODO: Unload OPTIONS screen variables here!
}

// Options Screen should finish?
int FinishOptionsScreen(void)
{
    return finishScreen;
}
