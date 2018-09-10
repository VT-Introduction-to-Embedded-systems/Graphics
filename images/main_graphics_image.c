#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"

Graphics_Context g_sContext;

void InitGraphics() {
    Crystalfontz128x128_Init();
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);
    Graphics_initContext(&g_sContext,
                         &g_sCrystalfontz128x128,
                         &g_sCrystalfontz128x128_funcs);
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_YELLOW);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_BLUE);
    GrContextFontSet(&g_sContext, &g_sFontCmtt16);
    Graphics_clearDisplay(&g_sContext);
}

void LCDClearDisplay() {
    Graphics_clearDisplay(&g_sContext);
}


extern Graphics_Image max8BPP_UNCOMP;

int main(void) {
    unsigned i;

    WDT_A_hold(WDT_A_BASE);

    InitGraphics();
    LCDClearDisplay();

    Graphics_drawImage(&g_sContext, &max8BPP_UNCOMP, 0, 0);

    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
    Graphics_setFont(&g_sContext, &g_sFontCmss18b);
    Graphics_drawString(&g_sContext, "WOOF!", -1, 5, 90, false);
    Graphics_drawString(&g_sContext, "WOOF!", -1, 5, 105, false);

    while (1) ;
}
