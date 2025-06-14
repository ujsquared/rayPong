#include "raylib.h"
#include "screens.h"
#include "gui_elements.h"


//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
//----------------------------------------------------------------------------------
// Button related Definition (on this screen)
//----------------------------------------------------------------------------------
enum buttonsOnTitleScreen{
    VSHUMAN_BUTTON, VSAI_BUTTON, BUTTON_COUNT
};
button selectionScreenButtons[BUTTON_COUNT];
enum buttonsOnTitleScreen selectionSelectedButton;

//----------------------------------------------------------------------------------
// Selection Screen Functions Definition
//----------------------------------------------------------------------------------
 
// Selection Screen Initialization logic
void InitSelectionScreen(void){
    selectionScreenButtons[VSHUMAN_BUTTON] = (button){0, 0, "vs Human", 0};
    selectionScreenButtons[VSAI_BUTTON] = (button){0, 0, "vs AI", 0};
    framesCounter = 0;
    finishScreen = 0;
};

// Selection Screen Update Logic
void UpdateSelectionScreen(void){

    if (IsKeyPressed(KEY_DOWN)) selectionSelectedButton = (selectionSelectedButton + 1) % BUTTON_COUNT;
    if (IsKeyPressed(KEY_UP)) selectionSelectedButton = (selectionSelectedButton - 1 + BUTTON_COUNT) % BUTTON_COUNT;

    if(IsKeyPressed(KEY_ENTER)){
        if(selectionSelectedButton == VSHUMAN_BUTTON) {
            finishScreen = 2;
            PlaySound(fxCoin);
        } 
        else if (selectionSelectedButton == VSAI_BUTTON) {
            finishScreen = 1;
            PlaySound(fxCoin);
        }
    }
    
    for(int i = 0; i <  BUTTON_COUNT; i++){
        if(IsButtonHovered(selectionScreenButtons[i])){
            selectionSelectedButton = i;
        }
        if(IsButtonClicked(selectionScreenButtons[i])){
            if(i == VSHUMAN_BUTTON){
                finishScreen = 2;
                PlaySound(fxCoin);
            }
            else if (i == VSAI_BUTTON) {
                finishScreen = 1;
                PlaySound(fxCoin); 
            }
        }
    }
};

// Selection Screen Draw Logic
void DrawSelectionScreen(void){

    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

    Vector2 posOfSelectHeading = { 290, 85 };
    DrawTextEx(font, "Select", posOfSelectHeading, font.baseSize*4.0f, 4, WHITE);


    selectionScreenButtons[VSHUMAN_BUTTON] = (button) { 530, 460, "vs Human", 2};
    selectionScreenButtons[VSAI_BUTTON] = (button) { 530, 520, "vs AI", 2};

    for(int i = 0; i< BUTTON_COUNT; i++){
        DrawButton(selectionScreenButtons[i]);
        if(i == selectionSelectedButton || IsButtonHovered(selectionScreenButtons[i])){
            Rectangle highlightRect = { 0 };
            RenderSelectionHighlight(highlightRect, selectionScreenButtons[i]);
        }
    }
};
// Selection Screen Unload logic
void UnloadSelectionScreen(void){

};

// Selection Screen should finish? 
int FinishSelectionScreen(void){
    return finishScreen;
};
