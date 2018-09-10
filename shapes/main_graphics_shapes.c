

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"

// A structure that holds a large set of characteristics for graphics including foreground color, background color, fot of
Graphics_Context g_sContext;

void InitGraphics();
void InitFonts();
void Initialize();


int main(void) {
    Initialize();

    Graphics_Rectangle R;
    R.xMin = 0;
    R.xMax = 63;
    R.yMin = 0;
    R.yMax = 127;

    Graphics_drawRectangle(&g_sContext, &R);
    Graphics_drawLine(&g_sContext, 0, 0, 127, 127);
    Graphics_fillCircle(&g_sContext, 63, 63, 30);

    while (1) ;
}

void InitGraphics() {

    Graphics_initContext(&g_sContext,
                         &g_sCrystalfontz128x128,
                         &g_sCrystalfontz128x128_funcs);
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_YELLOW);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_BLUE);
    Graphics_setFont(&g_sContext, &g_sFontCmtt16);

    InitFonts();

    Graphics_clearDisplay(&g_sContext);
}

void InitFonts() {
    Crystalfontz128x128_Init();
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);
}


void Initialize() {
    WDT_A_hold(WDT_A_BASE);

    InitGraphics();
}
