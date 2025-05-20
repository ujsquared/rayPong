#include "raylib.h"
#include "gui_elements.h"

void DrawButton(button b){
    Color fillingRectangle = {255, 255, 255, 50};
    int lengthOfText = MeasureText(b.buttonText, font.baseSize*b.fontSize);
    Vector2 posOfButton = { b.buttonX, b.buttonY };
    Vector2 posOfText = { b.buttonX + 30, b.buttonY + 10 };
    DrawRectangle(b.buttonX, b.buttonY, 176, 50, fillingRectangle);
    DrawTextEx(font, b.buttonText, posOfText, font.baseSize*b.fontSize, 4, WHITE); // 230, 85
};
