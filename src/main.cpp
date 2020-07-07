#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"

#include "Main.h"

class Slider{
    public:
    Slider(Adafruit_PCD8544* display, int min, int max, int x, int y, int h, int w, int offset = 0) {
        m_Display = display;
        m_min = min; m_max = max; m_x = x; m_y = y; m_height = h; m_width = w; m_offset = offset;
    }

    void Update(int value) {
        m_widthSlider = ((m_width / m_width) / 100 * value * m_width) - m_offset * 2;

        m_Display->drawRect(m_x, m_y, m_width, m_height, BLACK);
        m_Display->fillRect(m_x + m_offset, m_y + m_offset, m_widthSlider, m_height - m_offset * 2, BLACK);
    }

    private:
    Adafruit_PCD8544* m_Display;
    float m_max, m_min, m_x, m_y, m_height, m_widthSlider, m_width, m_offset;
};

Main GAME = Main();
Adafruit_PCD8544 Display = Adafruit_PCD8544(3, 4, 5, 6, 7);

Slider hungerSlider = Slider(&Display, 0, Settings::UI::DEFAULT_HUNGER_H, Settings::UI::DEFAULT_HUNGER_X, Settings::UI::DEFAULT_HUNGER_Y, Settings::UI::DEFAULT_HUNGER_H, Settings::UI::DEFAULT_HUNGER_W, 2);
Slider tiredSlider = Slider(&Display, 0, Settings::UI::DEFAULT_DIRTY_H, Settings::UI::DEFAULT_DIRTY_X, Settings::UI::DEFAULT_DIRTY_Y, Settings::UI::DEFAULT_DIRTY_H, Settings::UI::DEFAULT_DIRTY_W, 2);
Slider dirtySlider = Slider(&Display, 0, Settings::UI::DEFAULT_TIRED_H, Settings::UI::DEFAULT_TIRED_X, Settings::UI::DEFAULT_TIRED_Y, Settings::UI::DEFAULT_TIRED_H, Settings::UI::DEFAULT_TIRED_W, 2);


void setup() {
    Serial.begin(9600);

    Display.begin();

    Display.setContrast(60);
    Display.clearDisplay();
    Display.display();
}

void loop() {
    Display.clearDisplay();

    Display.setTextSize(1);
    Display.setTextColor(BLACK);
    Display.setCursor(Settings::UI::DEFAULT_SELECT_ITEM_X, Settings::UI::DEFAULT_SELECT_ITEM_Y);

    GAME.Update();

    hungerSlider.Update(GAME.hunger.value);
    tiredSlider.Update(GAME.tired.value);
    dirtySlider.Update(GAME.dirty.value);
    // Display.drawBitmap(0, 0, Sprites::Character::Shogo, 32, 32, BLACK);

    int t_int = GAME.GetIsAllZeroParametrs();

    if (t_int == Settings::DEFAULT_STAGE_FULL_COUNT) 
        Display.drawBitmap(Settings::UI::DEFAULT_CHARACTER_X, Settings::UI::DEFAULT_CHARACTER_Y, Sprites::Character::Normal, 20, 30, BLACK);
    else if (t_int == Settings::DEFAULT_STAGE_MIDDLE_COUNT) 
        Display.drawBitmap(Settings::UI::DEFAULT_CHARACTER_X, Settings::UI::DEFAULT_CHARACTER_Y, Sprites::Character::Middle, 20, 30, BLACK);
    else
        Display.drawBitmap(Settings::UI::DEFAULT_CHARACTER_X, Settings::UI::DEFAULT_CHARACTER_Y, Sprites::Character::Bad, 20, 30, BLACK);

    if (GAME.b_selectItem) {
        Display.print(String(GAME.m_selectedItem.name));
        Display.drawBitmap(Settings::UI::DEFAULT_ITEM_X, Settings::UI::DEFAULT_ITEM_Y, GAME.m_selectedItem.Sprite, 16, 16, BLACK);
    }

    if (Serial.available() > 0){
        char t_char = Serial.read();

        switch (t_char){
        case 'f':
            GAME.SelectItem(0);
            break;
        case 'a':
            GAME.SelectItem(-1);
            break;
        case 'd':
            GAME.SelectItem(1);
            break;
        case 'w':
            GAME.ApplyItem();
            break;
        default:
            break;
        }
    }

    // GAME.Update();

    /*
    display.drawTriangle(0, 0, 80, 40, 30, 30, BLACK);
    display.drawBitmap(0, 0, Sprites::Character::Bad, 84, 48, BLACK);
    display.display();

    delay(10);
    display.clearDisplay();
    */

    Display.display();
}