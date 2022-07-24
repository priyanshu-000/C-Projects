#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Race
{
  int totalLap;
  int currentLap;
  char firstDriverName[20];
  char firstCarColor[20];
};

struct RaceCar
{
  int totalLapTIme;
  char driverName[20];
  char carColor[20];
};

void printIntro(void){
  printf("\n============================================\nWelcome to our main event digital race fans!\n============================================\n\n\nI hope everybody has their snacks because we are about to begin!\n\n");
  }
void printReady(void){
  printf("\nDrivers ready!\n\nGet Set\n");
  printf("Press Enter to Start ");
  while( getchar() != '\n' );
  printf("Race will start in\n5\n4\n3\n2\n1\nGo\n");
  }
void printFirstPlaceAfterLap(struct Race race){printf("\n\nAfter lap number %d\nFirst Place Is: %s in the %s race car!", race.currentLap, race.firstDriverName, race.firstCarColor);}
void printCongratulation(struct Race race){printf("Let's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a goodnight!", race.firstDriverName, race.firstCarColor);}

int calculateLapTime(int a, int b)
{
  int speed=rand() % (b-a+1)+a, acceleration=rand()%(b-a+1)+a, nerves=rand()%(b-a+1)+a;
  return speed+acceleration+nerves;
}

void updateRaceCar(struct RaceCar* raceCar)
{
  raceCar->totalLapTIme += calculateLapTime(1,3);
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2, struct RaceCar* raceCar3)
{
  if(raceCar1->totalLapTIme<=raceCar2->totalLapTIme && raceCar1->totalLapTIme<=raceCar3->totalLapTIme) 
  {
    strcpy(race->firstDriverName, raceCar1->driverName);
    strcpy(race->firstCarColor, raceCar1->carColor);
  }
  if (raceCar2->totalLapTIme<=raceCar1->totalLapTIme && raceCar2->totalLapTIme<=raceCar3->totalLapTIme)
  {
    strcpy(race->firstDriverName, raceCar2->driverName);
    strcpy(race->firstCarColor, raceCar2->carColor);
  }
  if (raceCar3->totalLapTIme<=raceCar1->totalLapTIme && raceCar3->totalLapTIme<=raceCar2->totalLapTIme)
  {
    strcpy(race->firstDriverName, raceCar3->driverName);
    strcpy(race->firstCarColor, raceCar3->carColor);
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2, struct RaceCar* raceCar3)
{
  struct Race race = {100,1,"",""};
  for (int i = 0; i < race.totalLap; i++)
  {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateRaceCar(raceCar3);
    updateFirstPlace(&race, raceCar1, raceCar2, raceCar3);
    printFirstPlaceAfterLap(race);
    race.currentLap++;
  }
  printCongratulation(race);
  
}

int main() {
  srand(time(0));

  struct RaceCar raceCar1 = {0,"Pete","Matte Blue"};
  struct RaceCar raceCar2 = {0,"Dave","Slate Green"};
  struct RaceCar raceCar3 = {0,"Alex","Orange"};

  printIntro();
  printReady();
  startRace(&raceCar1, &raceCar2, &raceCar3);

}

