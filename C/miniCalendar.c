#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 || year % 400 == 0));
}

int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

void addDaysToDate(int* mm, int* dd, int* yy, int daysLeftToAdd) {
  int daysLeftInMonth;
  while(daysLeftToAdd>0) {
    
    daysLeftInMonth = daysInMonth[*mm] - *dd;
    
    if(*mm==2 && isLeapYear(*yy)==true) {
      daysLeftInMonth+=1;
      }
      
    if(daysLeftToAdd>daysLeftInMonth) {
    
      daysLeftToAdd -= daysLeftInMonth + 1;
      *dd = 1;
      
      if(*mm==12) {
        *mm = 1;
        *yy+=1;
      }
      else {
        *mm +=1;
      }

    }
    else {
    *dd += daysLeftToAdd;
    daysLeftToAdd = 0;
    }
  }
}

int main() {

int mm, dd, yy, daysLeftToAdd;
static const char* month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

printf("\n\nPlease enter month day and year when prompted!\n\n");
printf("Month(mm): "); scanf("%d", &mm); printf("Day(dd): "); scanf("%d", &dd); printf("Year(yy): "); scanf("%d", &yy);
printf("Enter the number of days you want to add: "); scanf("%d", &daysLeftToAdd);

addDaysToDate(&mm, &dd, &yy, daysLeftToAdd);

if(mm<13 && dd<32) {
        printf("\n\nThe date will be %s %d, %d.\n\n", month[mm-1], dd, yy);
    }
if (dd>31 || mm>12) {
        printf("\n\nYou've put an invalid date! Enter it again.\n");
        main();
    }
}