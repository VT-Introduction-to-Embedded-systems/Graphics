#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"

Graphics_Context g_sContext;

void InitGraphics();
void InitFonts();
void LCDClearDisplay();
void Initialize();

unsigned colormix(unsigned r,unsigned g,unsigned b) {
    return ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
}

int main(void) {
    unsigned i, r, g, b;

    Initialize();
    for (i=0; i<128; i++) {
        r = 25;
        g = i*2;
        b = 256 - i*2;
        Graphics_setForegroundColor(&g_sContext, colormix(r,g,b));
        Graphics_drawLineH(&g_sContext, 0, 127, i);
    }


    Graphics_setFont(&g_sContext, &g_sFontCmss18b);
    Graphics_drawString(&g_sContext, "GO HOKIES", -1, 10, 70, false);

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
    Graphics_clearDisplay(&g_sContext);

    InitFonts();
}

void InitFonts() {
    Crystalfontz128x128_Init();
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);
}


void LCDClearDisplay() {
    Graphics_clearDisplay(&g_sContext);
}

void Initialize() {
    WDT_A_hold(WDT_A_BASE);

    InitGraphics();
    LCDClearDisplay();

}
