namespace Math {
    static int clamp(int min, int max, int value) {
        if (value >= max) return max;
        else if (value <= min) return min;
        else return value;
    }

    static float clamp(float min, float max, float value) {
        if (value >= max) return max;
        else if (value <= min) return min;
        else return value;
    }
};