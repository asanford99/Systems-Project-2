#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Calculates the total amount of occurence for each expenses with the cap of what the company is willing to spend
float allowedExpense (int breakfastMeals, int lunchMeals, int dinnerMeals, int taxiDays, int parkingDays, int hotelNights, float airfareCost, float carRentalCost, float privateVehicleCost, float seminarCost)
{
    float returnValue = 0;

    returnValue += (breakfastMeals * 9);
    returnValue += (lunchMeals * 12);
    returnValue += (dinnerMeals * 16);
    returnValue += (taxiDays * 10);
    returnValue += (parkingDays * 6);
    returnValue += (hotelNights * 90);
    returnValue += airfareCost;
    returnValue += carRentalCost;
    returnValue += privateVehicleCost;
    returnValue += seminarCost;

    return returnValue;
}

// Gives the time a number value and converts to military time
int getTime(char* readTimePar, char* userAMPMPar)
{
	int returnTime;
	int i;
	int afterColon = 0;
	char newReadTime[4];

	bool hasColon = false;

	for (int i = 0; i < strlen(readTimePar); i++)
	{
		if (readTimePar[i] != ':')
        {
			if (hasColon == true)
            {
				afterColon ++;
				newReadTime[i - 1] = readTimePar[i];
			}
			else
            {
				newReadTime[i] = readTimePar[i];
			}
		}
		else
        {
			hasColon = true;
		}
	}

	if (!strtod(newReadTime, NULL))
    {
		if(strcmp(readTimePar, "0"))
        {
			return -1;
		}
	}

	if (hasColon == false)
    {
		return -1;
	}

	if (afterColon != 2)
    {
		return -1;	
	}

	returnTime = atoi(newReadTime);

	if (returnTime < 0)
    {
		return -1;
	}

	if (!strcmp(userAMPMPar, "PM"))
    {
		returnTime = returnTime + 1200;
	}
	else
    {
		if (strcmp(userAMPMPar, "AM"))
        {
			return -1;
		}
	}

	if (returnTime == 2400)
    {
		returnTime = 0;
	}

	if (returnTime > 2400)
    {
		return -1;
	}

	return returnTime;
}

int main ()
{
    return 0;
}