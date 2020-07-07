#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"

namespace Main {
    class Display {
        public:
        Adafruit_PCD8544 display;

        Display(int8_t SCLK, int8_t DIN, int8_t DC, int8_t CS, int8_t RST) {
            display = Adafruit_PCD8544(3, 4, 5, 6, 7);
            display.begin();
            ClearDisplay();
        }

        void ClearDisplay() {
            display.clearDisplay();
            display.display();
        }
        
    };
}