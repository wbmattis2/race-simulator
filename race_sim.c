#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

// Print functions section
void printIntro(void) {
  printf("The racers are starting their engines. Get Ready to Rumble!\n");
}

void printCountDown(void) {
  printf("On your mark...\n");
  for (int i = 10; i > 0; i--) {
    printf("%i\n", i);
    if (i == 4) {
      printf("Get set...\n");
    }
  }
  printf("GO!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
  printf("At the end of lap %i, %s is in first place in the %s car!\n\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
  printf("Congratulations to %s in the %s car! They have won the race!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// Logic functions section

int calculateTimeToCompleteLap(void) {
  int speed, acceleration, nerves;
  speed = rand() % 3 + 1;
  acceleration = rand() % 3 + 1;
  nerves = rand() % 3 + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct RaceCar* winner = ( raceCar1->totalLapTime <= raceCar2->totalLapTime ) ? raceCar1 : raceCar2;
  race->firstPlaceDriverName = winner->driverName;
  race->firstPlaceRaceCarColor = winner->raceCarColor;
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {
    .numberOfLaps = 5,
    .currentLap = 1,
    .firstPlaceDriverName = "",
    .firstPlaceRaceCarColor = ""
  };
  for (int i = 0; i < race.numberOfLaps; i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap++;
  }
  printCongratulation(race);
}

int main() {
	srand(time(0));
  struct RaceCar raceCar1 = {
    "Lightning Lucas",
    "silver",
    0
  };
  struct RaceCar raceCar2 = {
    "Fiery Frances",
    "gold",
    0
  };
  printIntro();
  printCountDown();
  startRace(&raceCar1, &raceCar2);
};