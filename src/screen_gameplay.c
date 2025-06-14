#include <stdio.h>
#include <stdlib.h>
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

const int ballSpeedX = 5;
const int ballSpeedY = 5;
const int winningScore = 5;

Rectangle leftPaddle = {10, 330, 10, 60};
Rectangle rightPaddle = {1270, 330, 10, 60};

int countPause;
bool isPaused;
bool userPaused;

score GameScore;


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
    PaddleRight.paddleX = 1270;
    PaddleRight.paddleY = 330;

    GameBall.ballX = 640;
    GameBall.ballY = 360;

    if(rand() % 2 == 0){
        GameBall.ballVelocityX = -(ballSpeedX);
        GameBall.ballVelocityY = -(ballSpeedY);
    }
    else{
        GameBall.ballVelocityX = ballSpeedX;
        GameBall.ballVelocityY = ballSpeedY;
    }

    GameScore.leftScore = 0;
    GameScore.rightScore = 0;

    isPaused = false;
    userPaused = false;
    countPause = 0;
    
}

void resetGameScreen(int winner){
    GameBall.ballX = 640;
    GameBall.ballY = 360;
    if(winner == 0){
        GameBall.ballVelocityX = -(ballSpeedX);
        GameBall.ballVelocityY = -(ballSpeedY);
    }
    else{
        GameBall.ballVelocityX = ballSpeedX;
        GameBall.ballVelocityY = ballSpeedY;
    }
    // for(int i = 0; i < 144*2; i++){
        // char ls = (char) GameScore.leftScore;
        // char rs = (char) GameScore.rightScore;
        // char str[] = {ls, '-' , rs}; 
        // DrawText(str, GetScreenWidth()/2 - 100, GetScreenHeight()/2 -10, 20, WHITE);
    isPaused = true;
    countPause = 0;
       //just wait
    // }
}

// Gameplay Screen Update logic
bool IsGameEnded(){
    return false;
}
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
    BeginDrawing();
    //
    //
    /*
     *
     *
     *
     *
     *
     */
    if(IsKeyPressed(KEY_P)){
        isPaused = !isPaused;
        userPaused = !userPaused;
    }
    // This is paddle control area.
    if(!isPaused){
        if(IsKeyDown(KEY_W) && PaddleLeft.paddleY > 5) {
            PaddleLeft.paddleY -= 5; 
            leftPaddle.y -= 5;
            }
        if(IsKeyDown(KEY_S) && PaddleLeft.paddleY < GetScreenHeight()-60) {
            PaddleLeft.paddleY += 5; 
            leftPaddle.y += 5;
        }

        if (IsKeyDown(KEY_UP) && PaddleRight.paddleY > 5) {
            PaddleRight.paddleY -= 5;
            rightPaddle.y -= 5;
        }
        if (IsKeyDown(KEY_DOWN) && PaddleRight.paddleY < GetScreenHeight()-60) {
            PaddleRight.paddleY += 5; 
            rightPaddle.y += 5;
        }



        // now there are 4 cases-
        // a) hitting top wall
        if(GameBall.ballY <= 5 && GameBall.ballVelocityY < 0 ){
            GameBall.ballVelocityY = -(GameBall.ballVelocityY);  
        }
        // b) hitting bottom wall
        if(GameBall.ballY >= (GetScreenHeight()-10) && GameBall.ballVelocityY > 0 ){
            GameBall.ballVelocityY = -(GameBall.ballVelocityY);  
        }

        // if(
        //         GameBall.ballX <= PaddleLeft.paddleX+10 &&
        //         GameBall.ballVelocityX < 0 &&
        //         GameBall.ballY >= PaddleLeft.paddleY && 
        //         GameBall.ballY <= (PaddleLeft.paddleY+60)
        //     )
        // {
        //     GameBall.ballX = PaddleLeft.paddleX;
        //     GameBall.ballVelocityX = -(GameBall.ballVelocityX);
        // }
        //
        // if(
        //         GameBall.ballX >= (PaddleRight.paddleX-10) &&
        //         GameBall.ballVelocityX > 0 &&
        //         GameBall.ballY >= PaddleLeft.paddleY &&
        //         GameBall.ballY <= (PaddleLeft.paddleY+60)
        //     )
        // {
        //     GameBall.ballX = PaddleRight.paddleX;
        //     GameBall.ballVelocityX = -(GameBall.ballVelocityX);
        // }

        // c) hitting left paddle
        if(CheckCollisionCircleRec((Vector2){GameBall.ballX, GameBall.ballY}, 5, leftPaddle)){
            GameBall.ballVelocityX = -GameBall.ballVelocityX;
        }

        // d) hitting right paddle
        if(CheckCollisionCircleRec((Vector2){GameBall.ballX, GameBall.ballY}, 5, rightPaddle)){
            GameBall.ballVelocityX = -GameBall.ballVelocityX;
        }

        if(GameBall.ballX > GetScreenWidth()){
            GameScore.leftScore++;
            resetGameScreen(0);
        }
        if(GameBall.ballX < 0){
            GameScore.rightScore++;
            resetGameScreen(1);
        }
         
        
        
        // Eventually move the ball.
        GameBall.ballX += GameBall.ballVelocityX;
        GameBall.ballY += GameBall.ballVelocityY;
    }
    else{
        if(!userPaused)countPause++;
    }

    // while(!IsGameEnded()){
    //     // DrawGameplayScreen(PaddleLeft, PaddleRight, GameBall);
    // }
    DrawGameplayScreen();
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
    DrawRectangle(PaddleLeft.paddleX, PaddleLeft.paddleY, 10, 60, WHITE);
    DrawRectangle(PaddleRight.paddleX, PaddleRight.paddleY, 10, 60, WHITE);
    DrawCircle(GameBall.ballX, GameBall.ballY, 10, WHITE);
    framesCounter++;
    if(isPaused){
        if(countPause == 144){
            isPaused = false;
            countPause = 0;
        }
        else{
            char str[6];
            snprintf(str, sizeof(str), "%d - %d", GameScore.leftScore, GameScore.rightScore);
            DrawText(str, GetScreenWidth()/2 - 100, GetScreenHeight()/2 -10, 20, WHITE);
        }
    }
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
