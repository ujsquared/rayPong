#include "raylib.h"
#include "gui_elements.h"

int BUTTON_HEIGHT = 50;
int BUTTON_WIDTH = 176;
//----------------------------------------------------------------------------------
// Draw GUI elements function
//----------------------------------------------------------------------------------
void DrawButton(button b){
    Color fillingRectangle = {255, 255, 255, 50};
    int lengthOfText = MeasureText(b.buttonText, font.baseSize*b.fontSize);
    Vector2 posOfButton = { b.buttonX, b.buttonY };
    Vector2 posOfText = { b.buttonX + 30, b.buttonY + 10 };
    DrawRectangle(b.buttonX, b.buttonY, BUTTON_WIDTH, BUTTON_HEIGHT, fillingRectangle);
    DrawTextEx(font, b.buttonText, posOfText, font.baseSize*b.fontSize, 4, WHITE); // 230, 85
};
//----------------------------------------------------------------------------------
// Interact with GUI elements helper function
//----------------------------------------------------------------------------------
bool IsButtonHovered(button b){
    Rectangle checkingRect = { b.buttonX, b.buttonY, MeasureText(b.buttonText, font.baseSize * b.fontSize )+60, 50}; 
    return CheckCollisionPointRec(GetMousePosition(), checkingRect);
}

bool IsButtonClicked(button b){
    return IsButtonHovered(b) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

void RenderSelectionHighlight(Rectangle highlightRect, button b){
    highlightRect.x = b.buttonX;
    highlightRect.y = b.buttonY;
    highlightRect.width = BUTTON_WIDTH; 
    highlightRect.height = BUTTON_HEIGHT;
    DrawRectangleRec(highlightRect, Fade(RED, 0.2f));
}
