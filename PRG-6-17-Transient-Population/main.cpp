//
//  main.cpp
//  PRG-6-16-Population
//
//  Created by Keith Smith on 9/21/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify Programming Challenge 16 to also consider the effect on population caused by
//  people moving into or out of a geographic area. Given as input a starting population
//  size, the annual birth rate, the annual death rate, the number of individuals who typically
//  move into the area each year, and the number of individuals who typically leave
//  the area each year, the program should project what the population will be numYears
//  from now. You can either prompt the user to input a value for numYears, or you can
//  set it within the program.
//
//  Input Validation: Do not accept numbers less than 2 for the starting size. Do not accept
//  negative numbers for birth rate, death rate, arrivals, or departures


#include <iostream>

using namespace std;

void calculateGrowth();
int yearsQuery();
void populationQuery(int &, float &, float &, int &, int &);

int main() {
    
    calculateGrowth();
    
    return 0;
}

void calculateGrowth()
{
    int intYearsTotal,
        intPopulationStart,
        intPopulationNew = 0, // Initialied to silence xcode warning
        intPopulationMoveIn,
        intPopulationMoveOut;
    
    float fltBirthRate,
          fltDeathRate;
    
    intYearsTotal = yearsQuery();
    
    populationQuery(intPopulationStart, fltBirthRate, fltDeathRate, intPopulationMoveIn, intPopulationMoveOut);
    
    fltBirthRate /= 100.0f;
    fltDeathRate /= 100.0f;
    
    for(int i = 1 ; i <= intYearsTotal ; i++)
    {
        intPopulationNew = intPopulationStart + (intPopulationStart * fltBirthRate) - (intPopulationStart * fltDeathRate) + (intPopulationMoveIn - intPopulationMoveOut);
        intPopulationStart = intPopulationNew;
    }
    
    cout << "After " << intYearsTotal << " years, the population size is " << intPopulationNew << endl;
}

int yearsQuery()
{
    int intYears;
    
    cout << "How many years should the population grow for?\n";
    cin >> intYears;
    
    while(!cin || intYears < 1 || intYears > 100)
    {
        cout << "Please enter an integer between 1 and 100:\n";
        cin.clear();
        cin.ignore();
        cin >> intYears;
    }
    
    return intYears;
}

void populationQuery(int &refPopStart, float &refBirthRate, float &refDeathRate, int &refMoveIn, int &refMoveOut)
{
    cout << "What is the initial starting size of the population?\n";
    cin >> refPopStart;
    
    while(!cin || refPopStart < 2 || refPopStart > 1000000)
    {
        cout << "Please enter a starting population size\n"
        << "between 2 and 1,000,000:\n";
        cin >> refPopStart;
    }
    
    cout << "What is the birth rate of the population?\n";
    cin >> refBirthRate;
    
    while(!cin || refBirthRate < 0 || refBirthRate > 500)
    {
        cout << "Please enter a birth rate between\n"
        << "0% and 500%:\n";
        cin >> refBirthRate;
    }
    
    cout << "What is the death rate of the population?\n";
    cin >> refDeathRate;
    
    while(!cin || refDeathRate < 0 || refDeathRate > 500)
    {
        cout << "Please enter a death rate between\n"
        << "0% and 500%:\n";
        cin >> refDeathRate;
    }
    
    cout << "How many people move in to the area each year?\n";
    cin >> refMoveIn;
    
    while(!cin || refMoveIn < 2 || refMoveIn > 1000000)
    {
        cout << "Please enter a population size\n"
        << "between 2 and 1,000,000:\n";
        cin >> refPopStart;
    }
    
    cout << "How many people move out of the area each year?\n";
    cin >> refMoveOut;
    
    while(!cin || refMoveOut < 2 || refMoveOut > 1000000)
    {
        cout << "Please enter a population size\n"
        << "between 2 and 1,000,000:\n";
        cin >> refPopStart;
    }
}


