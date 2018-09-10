#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"

Graphics_Context g_sContext;

void InitGraphics();
void InitFonts();
void Initialize();


int main(void) {
    Initialize();

    Graphics_setFont(&g_sContext, &g_sFontCm14);
    Graphics_drawString(&g_sContext, "1234567890abcdefghijklmnopqrstuvwx", -1, 0, 0, false);
    unsigned char h = Graphics_getStringHeight(&g_sContext);
    Graphics_drawString(&g_sContext, "123456789012345678901234567890", -1, 0, 14, false);


    Graphics_setFont(&g_sContext, &g_sFontCmss18b);
    Graphics_drawString(&g_sContext, "GO HOKIES", -1, 10, 70, false);

    h = Graphics_getStringHeight(&g_sContext);
    Graphics_setFont(&g_sContext, &g_sFontCmss20b);
    Graphics_drawString(&g_sContext, "GO HOKIES", -1, 10, 90, true);

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
