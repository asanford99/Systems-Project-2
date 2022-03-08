#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ReturnArray.c>
#include<expenses.c>
#include<sumOf.c>
#include<sumOfNegativeNumbers.c>


int main() {
	int tripDays = 0;
	int taxiDays = 0;
	int departTime = 0;
	int arriveTime = 0;
	int breakfastMeals;
	int lunchMeals;
	int dinnerMeals;
	int i;
	float userNum = 0.0;
	float airfaireCost = 0;
	float carRentalCost = 0;
	float milesDriven = 0;
	float seminarFees = 0;
	float allowedBusinessExpense = 0;
	float businessManSpent = 0;
	float businessManSaved = 0;
	float businessManOwes = 0;
	float businessPaid = 0;

	bool usedTaxi;

	char userInput[20];
	char readDepartureTime[10];
	char readDepartureAMPM[10];
	char readArrivalTime[10];
	char readArrivalAMPM[10];

	//takes input, validates it, and stores into tripDays
	readTripDays:

	printf("Total number of days spent on trip (include departure and arrival days): ");
	scanf("%s", userInput);

	if (!strtod(userInput, NULL)) {

		printf("Invalid input. Please enter a valid number of trip days.\n");

		goto readTripDays;

	}

	tripDays = atoi(userInput);

	if (tripDays < 1){

		printf("Invalid input. Please enter a number of trip days.\n");

		goto readTripDays;

	}

	//takes input and stores into readDepartureTime
	readDeparture:

	printf("Departure time: ");
	scanf("%s", readDepartureTime);

	//takes input and stores into readDepartureAMPM
	printf("AM or PM?: ");
	scanf("%s", readDepartureAMPM);

	//validates input and gives the time a number value and converts to military time
	departTime = getTime(readDepartureTime, readDepartureAMPM);

	if (departTime == -1) {

		printf("Invalid input. Please put time in this format: 10:00, and AM or PM in this format: AM.\n");

		goto readDeparture;

	}

	//takes input and stores into readArrivalTime
	readArrival:

	printf("Arrival time: ");
	scanf("%s", readArrivalTime);

	//takes input and stores into readArrivalAMPM
	printf("AM or PM?: ");
	scanf("%s", readArrivalAMPM);

	//validates input and gives the time a number value and converts to military time
	arriveTime = getTime(readArrivalTime, readArrivalAMPM);

	if (arriveTime == -1) {

		printf("Invalid input. Please put time in this format: 10:00, and AM or PM in this format: AM.\n");

		goto readArrival;

	}

	//takes input, validates, and stores into airfaireCost
	printf("Round-trip airfaire cost: $");
	scanf("%s", userInput);

	airfaireCost = validInput(userInput);

	//takes input, validates, and stores into carRentalCost
	printf("Total car rentals cost: $");
	scanf("%s", userInput);

	carRentalCost = validInput(userInput);

	//takes input, validates, and stores into milesDriven
	printf("Miles driven in private car (0 if not applicable): ");
	scanf("%s", userInput);

	milesDriven = validInput(userInput);

	//takes input, validates, and stores into seminarFees
	printf("Conference or seminar registreation fees: $");
	scanf("%s", userInput);

	seminarFees = validInput(userInput);
	//declares dynamic array hotelCosts, takes input, validates and stores into hotelCosts
	float* hotelCosts = (float*)malloc(tripDays * sizeof(float));

	for (i = 0; i < (tripDays - 1); i++){

		readHotelCosts:

		printf("Hotel cost for night %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readHotelCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readHotelCosts;

			}

			hotelCosts[i] = userNum;

		}

	}

	
	//declares dynamic array breakfastCosts, takes input, validates,  and stores into breakfastCosts
	int excludeDays = 0;

	if (departTime > 700){

		excludeDays += 1;

	}

	if (arriveTime < 800){

		excludeDays += 1;

	}

	breakfastMeals = tripDays - excludeDays;

	float* breakfastCosts = (float*)malloc((breakfastMeals) * sizeof(float));

	for (i = 0; i < (tripDays - excludeDays); i++){

		readBreakfastCosts:

		printf("Breakfast price %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readBreakfastCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readBreakfastCosts;

			}

			breakfastCosts[i] = userNum;

		}

	}

	//declares dynamic array lunchCosts, takes input, validates,  and stores into lunchCosts
	excludeDays = 0;

	if (departTime > 1200){

		excludeDays += 1;

	}

	if (arriveTime < 1300){

		excludeDays += 1;

	}

	lunchMeals = tripDays - excludeDays;

	float* lunchCosts = {0};
	lunchCosts = (float*)malloc((lunchMeals) * sizeof(float));

	for (i = 0; i <= (tripDays - excludeDays); i++){

		readLunchCosts:

		printf("Lunch price %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readLunchCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readLunchCosts;

			}

			lunchCosts[i] = userNum;

		}

	}

	//declares dynamic array dinnerCosts, takes input, validates,  and stores into dinnerCosts
	excludeDays = 0;

	if (departTime > 1800){

		excludeDays += 1;

	}

	if (arriveTime < 1900){

		excludeDays += 1;

	}

	dinnerMeals = tripDays - excludeDays;

	float* dinnerCosts = (float*)malloc((dinnerMeals) * sizeof(float));

	for (i = 0; i < (tripDays - excludeDays); i++){

		readDinnerCosts:

		printf("Dinner price %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readDinnerCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readDinnerCosts;

			}

			dinnerCosts[i] = userNum;

		}

	}

	//declares dynamic array parkingCosts, takes input, validates and stores into parkingCosts
	float* parkingCosts = (float*)malloc(tripDays * sizeof(float));

	for (i = 0; i < (tripDays); i++){

		readParkingCosts:

		printf("Parking costs for day %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readParkingCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readParkingCosts;

			}

			parkingCosts[i] = userNum;

		}

	}

	//checks if a taxi was used during trip. if so, inputs the amount of days a taxi was used, declares dynamic array taxiCosts, takes input, validates and stores into taxiCosts
	readUsedTaxi:

	printf("Was a taxi used during this trip? (Yes or No): ");
	scanf("%s", userInput);

	float* taxiCosts;

	if (!strcmp(userInput, "Yes")){

		usedTaxi = true;

	}
	else{

		if (strcmp(userInput, "No")){

			printf("Invalid input. Please type Yes or No.\n");

			goto readUsedTaxi;

		}

		usedTaxi = false;

	}

	if (usedTaxi == true){
		readTaxiDays:

		printf("How many days was a taxi used?: ");
		scanf("%s", userInput);

		if (!strtod(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please enter a valid number of days.\n");

				goto readTaxiDays;

			}

		}

		taxiDays = atoi(userInput);

		if (taxiDays < 0){

			printf("Invalid input. Please enter a valid number of days.\n");

			goto readTaxiDays;

		}

		if (taxiDays > tripDays){

			printf("Invalid input. Please enter a valid number of days less than the amount of days on trip.\n");

			goto readTaxiDays;

		}

		taxiCosts = (float*)malloc(taxiDays * sizeof(float));

		for (i = 0; i < taxiDays; i++){

			readTaxiCosts:

			printf("Taxi costs for day %d used: $", (i + 1));
			scanf("%s", userInput);

			if (!strtof(userInput, NULL)){

				if(strcmp(userInput, "0")){

					printf("Invalid input. Please use a valid monetary amount.\n");

					goto readTaxiCosts;

				}

			}

			else{

				userNum = atof(userInput);

				if (userNum < 0){

					printf("Invalid input. Please use a valid monetary amount.\n");

					goto readTaxiCosts;

				}

				taxiCosts[i] = userNum;

				

			}

		}

	}

	//gets the total amount possible that the business may pay
	allowedBusinessExpense = allowedExpense(breakfastMeals, lunchMeals, dinnerMeals, taxiDays, tripDays, (tripDays - 1), milesDriven, airfaireCost, carRentalCost, seminarFees);

	//gets the total amount that the businessman spent
	businessManSpent += airfaireCost;
	businessManSpent += carRentalCost;
	businessManSpent += (milesDriven * .27);
	businessManSpent += sumOf(parkingCosts, tripDays);
	if (usedTaxi == true){

		businessManSpent += sumOf(taxiCosts, taxiDays);

	}
	businessManSpent += seminarFees;
	businessManSpent += sumOf(hotelCosts, (tripDays - 1));
	businessManSpent += sumOf(breakfastCosts, breakfastMeals);
	businessManSpent += sumOf(lunchCosts, lunchMeals);
	businessManSpent += sumOf(dinnerCosts, dinnerMeals);

	//gets the total amount that the businessman saved
	businessManSaved += sumOf(returnArray(breakfastCosts, breakfastMeals, 9), breakfastMeals);
	businessManSaved += sumOf(returnArray(lunchCosts, lunchMeals, 12), lunchMeals);
	businessManSaved += sumOf(returnArray(dinnerCosts, dinnerMeals, 16), dinnerMeals);
	businessManSaved += sumOf(returnArray(parkingCosts, tripDays, 6), tripDays);
	businessManSaved += sumOf(returnArray(hotelCosts, (tripDays - 1), 90), (tripDays - 1));
	if (usedTaxi == true){

		businessManSaved += sumOf(returnArray(taxiCosts, taxiDays, 10), taxiDays);

	}

	//gets the total amount that the businessman owes
	businessManOwes += sumOfNegativeNumbers(returnArray(breakfastCosts, breakfastMeals, 9), breakfastMeals);
	businessManOwes += sumOfNegativeNumbers(returnArray(lunchCosts, lunchMeals, 12), lunchMeals);
	businessManOwes += sumOfNegativeNumbers(returnArray(dinnerCosts, dinnerMeals, 16), dinnerMeals);
	businessManOwes += sumOfNegativeNumbers(returnArray(parkingCosts, tripDays, 6), tripDays);
	businessManOwes += sumOfNegativeNumbers(returnArray(hotelCosts, (tripDays - 1), 90), (tripDays - 1));
	if (usedTaxi == true){

		businessManOwes += sumOfNegativeNumbers(returnArray(taxiCosts, taxiDays, 10), taxiDays);

	}

	businessManOwes = businessManOwes * (-1);

	//gets what amount the company will spend from the amount that the businessman spent
	businessPaid = businessManSpent - businessManOwes;

	//rounds values to two decimal places for a monetary value
	allowedBusinessExpense = roundf(allowedBusinessExpense * 100)/100;
	businessManSpent = roundf(businessManSpent * 100)/100;
	businessManSaved = roundf(businessManSaved * 100)/100;
	businessManOwes = roundf(businessManOwes * 100)/100;
	businessPaid = roundf(businessPaid * 100)/100;

	//outputs results
	printf("\nTotal expenses allowed for trip: %.2f\n", allowedBusinessExpense);
	printf("Total amount spent by businessman: %.2f\n", businessManSpent);
	printf("Total amount saved by businessman: %.2f\n", businessManSaved);
	printf("Total amount businessman owes: %.2f\n", businessManOwes);
	printf("Total amount business is willing to spend on trip from amount spent: %.2f\n\n", businessPaid);

	
	free(hotelCosts);
	free(parkingCosts);
	free(breakfastCosts);
	free(lunchCosts);
	free(dinnerCosts);
	if (usedTaxi == true){

		free(taxiCosts);

	}


	return 0;
}
