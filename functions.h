// Closes the fill valve that brings water to the tank
void closeFillValve();

// Fills the tank with water.
void fillWater();

// Drops the flapper that seals the tank to prevent water flowing out.
void dropFlapper();

/*
Closes the fill valve that brings water to the tank.
Doesn't fill the tank with water if the flapper is raised
because then the water flows out.
*/
void openFillValve();

// Allows water to flow out of the tank.
void drainWater();

// Lifts the flapper that seals the tank to allow the water to flow out.
void liftFlapper();

// Push the lever to start enable the flushing sequence.
void pushLever();

// Calls a series of functions that perform flushing the toilet.
void flushToilet();
