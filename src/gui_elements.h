#include "raylib.h"
#include "screens.h"

typedef struct {
   int buttonX;
   int buttonY;
   char* buttonText;
   float fontSize;
} button;

//----------------------------------------------------------------------------------
// Draw GUI elements function
//----------------------------------------------------------------------------------
void DrawButton(button b);
//----------------------------------------------------------------------------------
// Interact with GUI elements function
//----------------------------------------------------------------------------------
bool IsButtonHovered(button b);
bool IsButtonClicked(button b);
//----------------------------------------------------------------------------------
// Render GUI elements function
//----------------------------------------------------------------------------------
void RenderSelectionHighlight(Rectangle highlightRect, button b);

