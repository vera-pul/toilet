#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "constants.h"
#include "functions.h"

float water;
bool isFloatUp;
bool isLeverUp;
bool isFillValveClosed;
bool isFlapperDown;

void flushToilet() {
    pushLever();
    liftFlapper();
    drainWater();
    dropFlapper();
    fillWater();
    closeFillValve();
}

int main() {
    // init variables for flushing
    water = WATER_MAX;
    isFloatUp = true;
    isLeverUp = true;
    isFillValveClosed = true;
    isFlapperDown = true;

    char flushAnswer;
    char whitespace;
    do {
        printf("Press (f) when you're ready to flush the toilet. \n");
        printf("Press (l) if you want to leave. \n");
        scanf("%c", &flushAnswer);
        scanf("%c", &whitespace);
        if (flushAnswer == 'f') {
            flushToilet();
        }
    } while (flushAnswer != 'l');

   return 0;
}

void closeFillValve() {
    if (!isFillValveClosed && isFloatUp) {
        isFillValveClosed = true;
    } else {
        fprintf(stderr, "Error closing the fill valve.\n");
        exit(-1);
    }
}

void fillWater() {
    if (!isFillValveClosed && isFlapperDown) {
        printf("* Filling the tank with water...");
        time_t now = time(NULL);

        // Increase water every second
        while (water < WATER_MAX - DELTA) {
            time_t elapsed = time(NULL) - now;
            if (elapsed >= 1) {
                now = time(NULL);
                water += FILL_WATER_PER_SECOND;
                printf(".");
            }
        }
        printf(" Tank full.\n");
        water = trunc(water); // Get rid of decimals
        isFloatUp = true; // Float is in its highest possible position
        //closeFillValve();
    } else {
        fprintf(stderr, "Cannot fill the tank.\n");
        exit(-1);
    }
}

void dropFlapper() {
    if (!isFlapperDown && water == 0) {
        printf("* Dropped the flapper.\n");
        isFlapperDown = true;
        isLeverUp = true; // Flapper down releases the lever
        //fillWater();
    } else {
        fprintf(stderr, "Error dropping the flapper.\n");
        exit(-1);
    }
}

void openFillValve() {
    if (isFillValveClosed && !isFloatUp) {
        isFillValveClosed = false;
        printf("* Opened the filling valve.\n");
    } else {
        fprintf(stderr, "Error opening the fill valve.\n");
        exit(-1);
    }
}

void drainWater() {
    if (!isFlapperDown || water > 0) {
        isFloatUp = false;
        openFillValve(); // Float down automatically opens the fill valve
        printf("* Water is draining...");
        time_t now = time(NULL);

        // Decrease water every second
        while (water > 0 + DELTA) {
            time_t elapsed = time(NULL) - now;
            if (elapsed >= 1) {
                now = time(NULL);
                water -= FLUSH_WATER_PER_SECOND;
                printf(".");
            }
        }
        printf(" Tank empty.\n");
        water = trunc(water); // Get rid of decimals
        //dropFlapper();
    } else {
        fprintf(stderr, "Cannot drain water.\n");
        exit(-1);
    }
}

void liftFlapper() {
    if (isFlapperDown && !isLeverUp) {
        printf("* Lifting the flapper.\n");
        isFlapperDown = false;
        //drainWater();
    } else {
        fprintf(stderr, "Error lifting the flapper.\n");
        exit(-1);
    }
}

void pushLever() {
    if (isLeverUp) {
        printf("* Pushed the lever.\n");
        isLeverUp = false;
        //liftFlapper();
    } else {
        fprintf(stderr, "Cannot push the lever.\n");
        exit(-1);
    }
}
