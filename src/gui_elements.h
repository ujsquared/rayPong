#include "raylib.h"
#include "screens.h"

typedef struct {
   int buttonX;
   int buttonY;
   char* buttonText;
   float fontSize;
} button;

void DrawButton(button b);
