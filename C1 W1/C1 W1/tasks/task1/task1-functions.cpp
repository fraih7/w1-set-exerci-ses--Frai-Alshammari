#include "task1-functions.h"
#include <iostream>
#include <math.h>
using namespace std;

#define KM_PER_MILE 1.609344

// setEngineMode - outputs the engine mode based on speed S (mph) and battery level B (%)
// Returns 0 for battery mode and 1 for petrol
int setEngineMode(int S, int B)
{

	// ************************
	// WRITE YOUR SOLUTION HERE
	// ************************

	if (S < 10 && B > 25) {
		return 0; // Battery mode
	}
	else if (S < 30 && B >= 45) {
		return 0; // Battery mode
	}
	else if (B <= 25) {
		return 1; // Battery less than 25 Petrol mode
	}
	else if (S >= 10 && (B > 25 && B < 45)) {
		return 1;  // Petrol mode
	}
	else if(S >= 30) {
		return 1;  // Petrol mode
	}
}