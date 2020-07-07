#include "MathCustom.h"
#include "Timer.h"
#include "Settings.h"
#include "Sprites.h"

#define ITEMS_LENGHTS_ARRAY 9

enum TypeItems {
    FoodItem,
    CleaningItem,
    RelaxItem,
};

struct Item {
    char* name;
    TypeItems typeItem;
    float hungerPoints;
    float dirtyPoints;
    float tiredPoints;
    const unsigned char* PROGMEM Sprite;
};

const Item ITEMS[ITEMS_LENGHTS_ARRAY] {
    // FOODS
    { "Potato", TypeItems::FoodItem, 20, -1, 5, Sprites::ITEMS::Unknown },
    { "Chicken", TypeItems::FoodItem, 60, -10, 20, Sprites::ITEMS::Unknown },
    { "Sweet", TypeItems::FoodItem, 5, 0, 5, Sprites::ITEMS::Unknown },

    // CLEANING
    { "Head&Shoul", TypeItems::CleaningItem, 0, 5, 5, Sprites::ITEMS::Unknown },
    { "WD-40", TypeItems::CleaningItem, -2, 30, 0, Sprites::ITEMS::Unknown },
    { "Water", TypeItems::CleaningItem, -2, 10, -2, Sprites::ITEMS::Unknown },

    // RELAX
    { "TV", TypeItems::RelaxItem, -10, -2, 60, Sprites::ITEMS::Unknown },
    { "PS4", TypeItems::RelaxItem, -5, -2, 40, Sprites::ITEMS::Unknown },
    { "PC", TypeItems::RelaxItem, -5, -2, 80, Sprites::ITEMS::Unknown },
};


class ParametrLife {
    public:
    float value;
    float maxValue;
    float downInTime;
    bool isZero = false;

    ParametrLife(float getValue, float getMaxValue, float getDownInTime) {
        value = getValue;
        maxValue = getMaxValue;
        downInTime = getDownInTime;
    }

    void DownValue(float getValue) {
        value = Math::clamp(0.0, maxValue, value - getValue);
        isZero = value == 0;
    }

    void DownValueUpdate() {
        value = Math::clamp(0.0, maxValue, value - downInTime);
        isZero = value == 0;
    }

    void UpValue(float getvalue) {
        value = Math::clamp(0.0, maxValue, value + getvalue);
        isZero = value == 0;
    }
};


class Main {
    public:
    ParametrLife hunger = ParametrLife(Settings::DEFAULT_VALUE_HUNGER, Settings::DEFAULT_MAX_HUNGER, Settings::DEFAULT_DOWN_HUNGER);
    ParametrLife tired = ParametrLife(Settings::DEFAULT_VALUE_TIRED, Settings::DEFAULT_MAX_TIRED, Settings::DEFAULT_DOWN_TIRED);
    ParametrLife dirty = ParametrLife(Settings::DEFAULT_VALUE_DIRTY, Settings::DEFAULT_MAX_DIRTY, Settings::DEFAULT_DOWN_DIRTY);

    Timer timer = Timer(Settings::DEFAULT_TIMER_PAUSE);

    bool b_selectItem = false;

    // SelectedFood
    Item m_selectedItem;
    int currentIndexFood = 0;

    Main() {
        m_selectedItem = GetItemByIndex(currentIndexFood);
    }
    
    char** GetItemsList() {
        char* t_array[ITEMS_LENGHTS_ARRAY];

        for (int i = 0; i < ITEMS_LENGHTS_ARRAY; i++)
            t_array[i] = ITEMS[i].name;
        
        return t_array;
    }

    int GetIsAllZeroParametrs() {
        return !hunger.isZero + !tired.isZero + !dirty.isZero;
    }

    Item GetItemByIndex(int index) {
        for (int i = 0; i < ITEMS_LENGHTS_ARRAY; i++)
            if (i == index) return ITEMS[i];
    }

    void ApplyItem() {
        if (b_selectItem){
            hunger.UpValue(m_selectedItem.hungerPoints);
            tired.UpValue(m_selectedItem.tiredPoints);
            dirty.UpValue(m_selectedItem.dirtyPoints);

            b_selectItem = false;
        }
    }

    void SelectItem(short int direction = 1) {
        if (!b_selectItem && direction == 0) b_selectItem = true;
        else if (b_selectItem && direction == 0) b_selectItem = false;
        else if (b_selectItem && direction != 0) {
            int t_int = currentIndexFood + direction;
            currentIndexFood = Math::clamp(0, ITEMS_LENGHTS_ARRAY - 1, t_int);
            m_selectedItem = GetItemByIndex(currentIndexFood);
        }
    }

    char* GetStringByItemType(TypeItems type) {
        switch (type) {
        case TypeItems::FoodItem:
            return "Food";
        case TypeItems::CleaningItem:
            return "Clean";
        case TypeItems::RelaxItem:
            return "Relax";
        default:
            return "None";
        }
    }

    void Update() {
        timer.Update();

        if (timer.time <= 0) {
            hunger.DownValueUpdate();
            tired.DownValueUpdate();
            dirty.DownValueUpdate();

            DebugParametrsLife();

            timer.Reset();
        }
    }

    void DebugParametrsLife() {
        Serial.println("\n<!-- PARAMETRS DEBUG -->");
        Serial.println("HUNGER: " + String(hunger.value) + ";");
        Serial.println("TIRED: " + String(tired.value) + ";");
        Serial.println("DIRTY: " + String(dirty.value) + ";");
        Serial.println("<!-- END -->");
    }
};

