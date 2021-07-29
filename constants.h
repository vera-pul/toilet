// How much water the tank can hold
const float WATER_MAX = 60;
// How many seconds it takes to flush a full tank
const int SECONDS_TO_FLUSH = 3;
// How many seconds it takes to fill the tank with water
const int SECONDS_TO_FILL = 5;

// Precision
const float DELTA = 0.1;

// How much water is flushed per second
const float FLUSH_WATER_PER_SECOND = WATER_MAX / (float)SECONDS_TO_FLUSH;
// How much water flows in per second
const float FILL_WATER_PER_SECOND = WATER_MAX / (float)SECONDS_TO_FILL;
