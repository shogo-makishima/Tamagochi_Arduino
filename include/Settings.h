namespace Settings {
    // Hunger
    const float DEFAULT_VALUE_HUNGER = 100;
    const float DEFAULT_MAX_HUNGER = 100;
    const float DEFAULT_DOWN_HUNGER = 0.5;

    // Tired
    const float DEFAULT_VALUE_TIRED = 100;
    const float DEFAULT_MAX_TIRED = 100;
    const float DEFAULT_DOWN_TIRED = 0.2;

    // Dirty
    const float DEFAULT_VALUE_DIRTY = 100;
    const float DEFAULT_MAX_DIRTY = 100;
    const float DEFAULT_DOWN_DIRTY = 0.1;

    // Other
    const unsigned int DEFAULT_TIMER_PAUSE = 100;
    const unsigned int DEFAULT_SCREEN_WIDTH = 84;
    const unsigned int DEFAULT_SCREEN_HEIGHT = 48;

    const unsigned short int DEFAULT_STAGE_FULL_COUNT = 3;
    const unsigned short int DEFAULT_STAGE_MIDDLE_COUNT = 2;
    const unsigned short int DEFAULT_STAGE_LOW_COUNT = 1;
    const unsigned short int DEFAULT_STAGE_DEATH_COUNT = 0;

    namespace UI {
        // Select item cursor
        const unsigned int DEFAULT_SELECT_ITEM_X = 20, DEFAULT_SELECT_ITEM_Y = 36;

        // Sprites
        const unsigned int DEFAULT_CHARACTER_X = 6, DEFAULT_CHARACTER_Y = 1;
        const unsigned int DEFAULT_ITEM_X = 0, DEFAULT_ITEM_Y = 32;

        // Sliders
        const unsigned int DEFAULT_HUNGER_X = 43, DEFAULT_HUNGER_Y = 1, DEFAULT_HUNGER_W = 40, DEFAULT_HUNGER_H = 6, DEFAULT_HUNGER_OFFSET = 2;
        const unsigned int DEFAULT_TIRED_X = 43, DEFAULT_TIRED_Y = 13, DEFAULT_TIRED_W = 40, DEFAULT_TIRED_H = 6, DEFAULT_TIRED_OFFSET = 2;
        const unsigned int DEFAULT_DIRTY_X = 43, DEFAULT_DIRTY_Y = 25, DEFAULT_DIRTY_W = 40, DEFAULT_DIRTY_H = 6, DEFAULT_DIRTY_OFFSET = 2;
        /*const unsigned int DEFAULT_HUNGER_X = 43, DEFAULT_HUNGER_Y = 0, DEFAULT_HUNGER_W = 40, DEFAULT_HUNGER_H = 5, DEFAULT_HUNGER_OFFSET = 2;
        const unsigned int DEFAULT_TIRED_X = 43, DEFAULT_TIRED_Y = 6, DEFAULT_TIRED_W = 40, DEFAULT_TIRED_H = 5, DEFAULT_TIRED_OFFSET = 2;
        const unsigned int DEFAULT_DIRTY_X = 43, DEFAULT_DIRTY_Y = 12, DEFAULT_DIRTY_W = 40, DEFAULT_DIRTY_H = 5, DEFAULT_DIRTY_OFFSET = 2;*/
    };
};