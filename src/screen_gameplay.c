#include<stdio.h>
#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Gameplay Elements Definitions
//----------------------------------------------------------------------------------
// static int paddleLeftX = 0;
// static int paddleLeftY = 0;
// static int paddleRightX = 0;
// static int paddleRightY = 0;
// static int ballX= 0;
// static int ballY= 0;
// static int ballVelocityX = 0;
// static int ballVelocityY = 0;
paddle PaddleLeft;
paddle PaddleRight;
ball GameBall;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    PaddleLeft.paddleX= 10;
    PaddleLeft.paddleY = 330;
    PaddleRight.paddleX = 1260;
    PaddleRight.paddleY = 330;
    GameBall.ballX = 360;
    GameBall.ballY = 640;
    GameBall.ballVelocityX = 0;
    GameBall.ballVelocityY = 0;
    UpdateGameplayScreen();
}

// Gameplay Screen Update logic
bool IsGameEnded(){
    return false;
}
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
    BeginDrawing();
    DrawGameplayScreen();
    // while(!IsGameEnded()){
    //     // DrawGameplayScreen(PaddleLeft, PaddleRight, GameBall);
    // }
    EndDrawing();
    // Press enter or tap to change to ENDING screen
    // if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    // {
    //     finishScreen = 1;
    //     PlaySound(fxCoin);
    // }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen()
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
    DrawRectangle(10, 330, 10, 60, WHITE);
    DrawRectangle(1260, 330, 10, 60, WHITE);
    DrawCircle(640, 360, 10, WHITE);
     
    // TODO: Draw GAMEPLAY screen here!
    // Vector2 pos = { 20, 10 };
    // DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize*3.0f, 4, WHITE);
    // DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, WHITE);
}

// Gameplay Ending Logic
// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
