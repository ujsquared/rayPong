#ifndef SCREENS_H
#define SCREENS_H

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum GameScreen { UNKNOWN = -1, TITLE = 0, OPTIONS, GAMEPLAY, SELECTION, ENDING } GameScreen;

//----------------------------------------------------------------------------------
// Global Variables Declaration (shared by several modules)
//----------------------------------------------------------------------------------
extern GameScreen currentScreen;
extern Font font;
extern Music music;
extern Sound fxCoin;
extern bool AIMode;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Title Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitTitleScreen(void);
void UpdateTitleScreen(void);
void DrawTitleScreen(void);
void UnloadTitleScreen(void);
int FinishTitleScreen(void);

//----------------------------------------------------------------------------------
// Options Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitOptionsScreen(void);
void UpdateOptionsScreen(void);
void DrawOptionsScreen(void);
void UnloadOptionsScreen(void);
int FinishOptionsScreen(void);

//----------------------------------------------------------------------------------
// Selection Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitSelectionScreen(void);
void UpdateSelectionScreen(void);
void DrawSelectionScreen(void);
void UnloadSelectionScreen(void);
int FinishSelectionScreen(void);

//----------------------------------------------------------------------------------
// Gameplay Screen Structs Declaration
//----------------------------------------------------------------------------------
typedef struct paddle{
    int paddleX;
    int paddleY; 
} paddle;

typedef struct ball{
    int ballX;
    int ballY;
    int ballVelocityX;
    int ballVelocityY;
} ball;

typedef struct score{
    int leftScore;
    int rightScore;
} score;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitGameplayScreen(void);
void UpdateGameplayScreen(void);
void DrawGameplayScreen();
void UnloadGameplayScreen(void);
int FinishGameplayScreen(void);


#ifdef __cplusplus
}
#endif

#endif // SCREENS_H
