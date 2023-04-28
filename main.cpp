#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <chrono>
#include "County.h"
#include "Sorting.h"

using std::string;
using std::vector;
using std::ifstream;
using std::set;
using std::cin;
using std::cout;
using std::endl;

void readCounties(const string &file, vector<County>& counties);

int main()
{
    vector<County> counties;

    // Read in the county data from the CSV file using the readCounties function
    readCounties("county_demographics.csv", counties);


    float answer1, answer3, answer4, answer5, answer2A, answer2B;
    vector<pair<float, int>> userInputs;
    // Create a set to hold the unique ranks of the counties
    set <int> ranks;

    // Declare variables to hold the user's desired rank for each category
    int populationRank;
    int ethnicityRank;
    int ageDistributionRank;
    int educationRank;
    int incomeRank;
    int ethnicityIndex;

    // Declare constants for the minimum and maximum values of each category
    const int minPopulation = 64;
    const int maxPopulation = 10014009;
    const float minAgeDistribution = 58.3;
    const float maxAgeDistribution = 93.2;
    const float minEducationDistribution = 0;
    const float maxEducationDistribution = 77.6;
    const int minHouseholdIncome = 21504;
    const int maxHouseholdIncome = 142299;
    const string raceOption1 = "Asian";
    const float race1MinPopulation = 0.1;
    const float race1MaxPopulation = 43.4;
    const string raceOption2 = "Black";
    const float race2MinPopulation = 0.1;
    const float race2MaxPopulation = 86.6;
    const string raceOption3 = "White";
    const float race3MinPopulation = 8;
    const float race3MaxPopulation = 99;
    const string raceOption4 = "Hispanic/Latino";
    const float race4MinPopulation = 0.6;
    const float race4MaxPopulation = 96.4;
    const string raceOption5 = "Native Hawaiian and Other Pacific Islander";
    const float race5MinPopulation = 0;
    const float race5MaxPopulation = 48.8;
    const string raceOption6 = "American Indian and Alaska Native";
    const float race6MinPopulation = 0;
    const float race6MaxPopulation = 86.8;

    // Population question
    cout << "Question 1: What is your preferred county population? (enter a number between " << minPopulation << " and " << maxPopulation << ")" << endl;
    cin >> answer1;

    // Validating user population input
    while (answer1 < minPopulation || answer1 > maxPopulation) {
        cout << "Please enter a valid population between " << minPopulation << " and " << maxPopulation << endl;
        cin >> answer1;
    }

    cout << endl;

    // Ethnicity question
    cout << "Question 2A: Which ethnicity would you like to specify the percentage distribution of?" << endl;
    cout << endl;
    cout << "Please enter a digit corresponding to the following:" << endl;
    cout << "1: " << raceOption1 << endl;
    cout << "2: " << raceOption2 << endl;
    cout << "3: " << raceOption3 << endl;
    cout << "4: " << raceOption4 << endl;
    cout << "5: " << raceOption5 << endl;
    cout << "6: " << raceOption6 << endl;

    cout << endl;
    cout << "Option: ";
    cin >> answer2A;

    // Validating user ethnicity input
    while (answer2A < 1 || answer2A > 6) {
        cout << "Please enter a valid digit between  " << 1 << " and " << 6 << endl;
        cout << "Option: ";
        cin >> answer2A;
    }

    cout << endl;

    // Branching out follow-up question for ethnicity percentage
    // The following code repeats for each case depending on user specified ethnicity
    if (answer2A == 1)
    {
        cout << "Question 2B: What population percentage of " << raceOption1 << " ethnicity would you prefer in your county? (enter a number between " << race1MinPopulation << " and " << race1MaxPopulation << ")" << endl;
        cin >> answer2B;

        while (answer2B < race1MinPopulation || answer2B > race1MaxPopulation) {
            cout << "Please enter a valid population percentage between " << race1MinPopulation << " and " << race1MaxPopulation << endl;
            cin >> answer2B;
        }

        ethnicityIndex = 1;
        cout << endl;
    }

    // Validating user population percentage input
    if (answer2A == 2)
    {
        cout << "Question 2B: What population percentage of " << raceOption2 <<
        " ethnicity would you prefer in your county? (enter a number between " << race2MinPopulation << " and " << race2MaxPopulation << ")" << endl;
        cin >> answer2B;

        while (answer2B < race2MinPopulation || answer2B > race2MaxPopulation) {
            cout << "Please enter a valid population percentage between " << race2MinPopulation << " and " << race2MaxPopulation << endl;
            cin >> answer2B;
        }

        ethnicityIndex = 2;
        cout << endl;
    }

    if (answer2A == 3)
    {
        cout << "Question 2B: What population percentage of " << raceOption3 << " ethnicity would you prefer in your county? (enter a number between " << race3MinPopulation << " and " << race3MaxPopulation << ")" << endl;
        cin >> answer2B;

        while (answer2B < race3MinPopulation || answer2B > race3MaxPopulation) {
            cout << "Please enter a valid population percentage between " << race3MinPopulation << " and " << race3MaxPopulation << endl;
            cin >> answer2B;
        }

        ethnicityIndex = 3;
        cout << endl;
    }

    if (answer2A == 4)
    {
        cout << "Question 2B: What population percentage of " << raceOption4 << " ethnicity would you prefer in your county? (enter a number between " << race4MinPopulation << " and " << race4MaxPopulation << ")" << endl;
        cin >> answer2B;

        while (answer2B < race4MinPopulation || answer2B > race4MaxPopulation) {
            cout << "Please enter a valid population percentage between " << race4MinPopulation << " and " << race4MaxPopulation << endl;
            cin >> answer2B;
        }

        ethnicityIndex = 4;
        cout << endl;
    }

    if (answer2A == 5)
    {
        cout << "Question 2B: What population percentage of " << raceOption5 << " ethnicity would you prefer in your county? (enter a number between " << race5MinPopulation << " and " << race5MaxPopulation << ")" << endl;
        cin >> answer2B;

        while (answer2B < race5MinPopulation || answer2B > race5MaxPopulation) {
            cout << "Please enter a valid population percentage between " << race5MinPopulation << " and " << race5MaxPopulation << endl;
            cin >> answer2B;
        }

        ethnicityIndex = 5;
        cout << endl;
    }

    if (answer2A == 6)
    {
        cout << "Question 2B: What population percentage of " << raceOption6 << " ethnicity would you prefer in your county? (enter a number between " << race6MinPopulation << " and " << race6MaxPopulation << ")" << endl;
        cin >> answer2B;

        while (answer2B < race6MinPopulation || answer2B > race6MaxPopulation) {
            cout << "Please enter a valid population percentage between " << race6MinPopulation << " and " << race6MaxPopulation << endl;
            cin >> answer2B;
        }

        ethnicityIndex = 6;
        cout << endl;
    }

    // Age question
    cout << "Question 3: What is your preferred adult population percentage? (enter a number between " << minAgeDistribution << " and "
         << maxAgeDistribution << ")" << endl;
    cin >> answer3;

    // Validating user age distribution input
    while (answer3 < minAgeDistribution || answer3 > maxAgeDistribution) {
        cout << "Please enter a valid population percentage between " << minAgeDistribution << " and " << maxAgeDistribution << endl;
        cin >> answer3;
    }

    cout << endl;

    // Education question
    cout << "Question 4: What percentage of people do you prefer to have a bachelor's degree or higher? (enter a number between " << minEducationDistribution << " and "
         << maxEducationDistribution << ")" << endl;
    cin >> answer4;

    // Validating user education distribution input
    while (answer4 < minEducationDistribution || answer4 > maxEducationDistribution) {
        cout << "Please enter a valid percentage between " << minEducationDistribution << " and " << maxEducationDistribution << endl;
        cin >> answer4;
    }

    cout << endl;

    // Income question
    cout << "Question 5: What is your preferred county median household income? (enter a number between " << minHouseholdIncome << " and " << maxHouseholdIncome << ")"
         << endl;
    cin >> answer5;

    // Validating user median income input
    while (answer5 < minHouseholdIncome || answer5 > maxHouseholdIncome) {
        cout << "Please enter a valid income between " << minHouseholdIncome << " and " << maxHouseholdIncome << endl;
        cin >> answer5;
    }

    cout << endl;

    // Asking user for the ranks of each attribute
    cout << "Please rank each of the attributes from 1-5, with 1 being the most important to you and not repeating ranks between attributes:" << endl;

    // Population Attribute Rank
    cout << "Population: ";
    cin >> populationRank;

    // Validating user input for population rank
    while ((populationRank < 1 || populationRank > 5) || (ranks.find(populationRank) != ranks.end())) {
        if (populationRank < 1 || populationRank > 5)
        {
            cout << "Please enter a valid rank between " << 1 << " and " << 5 << endl;
            cout << "Population: ";
            cin >> populationRank;
        }


        if(ranks.find(populationRank) != ranks.end())
        {
            cout << "Another attribute already holds a rank value of " << populationRank << ". Please try again." << endl;
            cout << "Population: ";
            cin >> populationRank;
        }
    }

    cout << endl;
    ranks.insert(populationRank);

    // Ethnicity Attribute Rank
    cout << "Ethnicity: ";
    cin >> ethnicityRank;

    // Validating user input for ethnicity rank
    while ((ethnicityRank < 1 || ethnicityRank > 5) || (ranks.find(ethnicityRank) != ranks.end())) {
        if (ethnicityRank < 1 || ethnicityRank > 5)
        {
            cout << "Please enter a valid rank between " << 1 << " and " << 5 << endl;
            cout << "Ethnicity: ";
            cin >> ethnicityRank;
        }


        if(ranks.find(ethnicityRank) != ranks.end())
        {
            cout << "Another attribute already holds a rank value of " << ethnicityRank << ". Please try again." << endl;
            cout << "Ethnicity: ";
            cin >> ethnicityRank;
        }
    }

    cout << endl;
    ranks.insert(ethnicityRank);

    // Age Attribute Rank
    cout << "Age Distribution: ";
    cin >> ageDistributionRank;

    // Validating user input for age distribution rank
    while ((ageDistributionRank < 1 || ageDistributionRank > 5) || (ranks.find(ageDistributionRank) != ranks.end())) {
        if (ageDistributionRank < 1 || ageDistributionRank > 5)
        {
            cout << "Please enter a valid rank between " << 1 << " and " << 5 << endl;
            cout << "Age Distribution: ";
            cin >> ageDistributionRank;
        }


        if(ranks.find(ageDistributionRank) != ranks.end())
        {
            cout << "Another attribute already holds a rank value of " << ageDistributionRank << ". Please try again." << endl;
            cout << "Age Distribution: ";
            cin >> ageDistributionRank;
        }
    }

    cout << endl;
    ranks.insert(ageDistributionRank);

    // Education Attribute Rank
    cout << "Education Distribution: ";
    cin >> educationRank;

    // Validating user input for education rank
    while ((educationRank < 1 || educationRank > 5) || (ranks.find(educationRank) != ranks.end())) {
        if (educationRank < 1 || educationRank > 5)
        {
            cout << "Please enter a valid rank between " << 1 << " and " << 5 << endl;
            cout << "Education Distribution: ";
            cin >> educationRank;
        }

        if(ranks.find(educationRank) != ranks.end())
        {
            cout << "Another attribute already holds a rank value of " << educationRank << ". Please try again." << endl;
            cout << "Education Distribution: ";
            cin >> educationRank;
        }
    }

    cout << endl;
    ranks.insert(educationRank);

    // Income Attribute Rank
    cout << "Median Income: ";
    cin >> incomeRank;

    // Validating user input for income rank
    while ((incomeRank < 1 || incomeRank > 5) || (ranks.find(incomeRank) != ranks.end())) {
        if (incomeRank < 1 || incomeRank > 5)
        {
            cout << "Please enter a valid rank between " << 1 << " and " << 5 << endl;
            cout << "Median Income: ";
            cin >> incomeRank;
        }

        if(ranks.find(incomeRank) != ranks.end())
        {
            cout << "Another attribute already holds a rank value of " << incomeRank << ". Please try again." << endl;
            cout << "Median Income: ";
            cin >> incomeRank;
        }
    }

    ranks.insert(incomeRank);

    // Displaying user inputs and placing them into a vector to calculate the error scores
    cout << endl;
    cout << "Answers:" << endl;
    cout << "Population: " << answer1 << " - Rank: " << populationRank << endl;
    userInputs.emplace_back(answer1, populationRank);
    cout << "Ethnicity: " << answer2A << " - Rank: " << ethnicityRank << endl;
    cout << "Ethnicity Percentage: " << answer2B << endl;
    userInputs.emplace_back(answer2B, ethnicityRank);
    cout << "Age: " << answer3 << " - Rank: " << ageDistributionRank << endl;
    userInputs.emplace_back(answer3, ageDistributionRank);
    cout << "Education: " << answer4 << " - Rank: " << educationRank << endl;
    userInputs.emplace_back(answer4, educationRank);
    cout << "Income: " << answer5 << " - Rank: " << incomeRank << endl;
    userInputs.emplace_back(answer5, incomeRank);
    cout << endl;


    // calculating error scores
    for(auto& county : counties)
        county.calculateRank(userInputs, ethnicityIndex - 1);

    // Sorting class with sorting algorithms
    Sorting<County> sort;
    // a copy of County for each sorting algorithm
    vector<County> tempSort = counties;

    // Timing quick sort
    auto start = std::chrono::high_resolution_clock::now();
    sort.quickSort(tempSort,0, tempSort.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto quickTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Timing merge sort
    tempSort = counties;
    start = std::chrono::high_resolution_clock::now();
    sort.mergeSort(tempSort,0, tempSort.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    auto mergeTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    cout << "---Top 10 Counties That Match Your Criteria---" << "\n";
    for(int i = 0; i < 10; i++)
    {
        cout << i + 1 <<") ";
        tempSort[i].display();
    }
    cout << "\nQuick Sort Execution Time: " << quickTime.count() << " microseconds\n";
    cout << "Merge Sort Execution Time: " << mergeTime.count() << " microseconds\n";

    string userIndex = "";

    // Getting more data about a specific county
    while(true)
    {
        bool isValid = true;
        bool isDigit = true;
        cout << "\nEnter the index between 0 - 3138 to learn more about a specific county " << "\n";
        cout << "Enter q to quit " << "\n";
        cin >> userIndex;
        //Check if user wants to quit
        if(userIndex == "q")
            break;
        //Checks if input is a number
        else
        {
            for(char i : userIndex)
            {
                if(!std::isdigit(i))
                {
                    isDigit = false;
                    break;
                }
            }
        }
        if(!isDigit)
        {
            cout << "Please enter a digit " << "\n";
            continue;
        }

        //Checks if index is in range
        int findIndex = std::stoi(userIndex);
        if(findIndex < 0  || findIndex >= counties.size())
            isValid = false;

        if(isValid)
        {
            counties[findIndex].displayAttributes();
            cout << "\n";
        }
        else
        {
            cout << "Please enter valid index number between 0 and 3138" << "\n";
            continue;
        }

    }



    return 0;
}

void readCounties(const string &file, vector<County>& counties)
{
    ifstream inFile (file);
    string line;
    if(inFile)
    {
        int index = 0;

        std::getline(inFile, line);
        while(std::getline(inFile, line))
        {
            string name;
            string state;
            string temp;
            vector<float> pop;
            vector<float> age;
            pair<float, float> edu;
            vector<float> ethc;
            pair<float, float> inc;

            std::stringstream data(line);

            //County Name
            std::getline(data, name, ',');
            name.erase(std::remove(name.begin(), name.end(), '\"'),name.end());
            //State Name
            std::getline(data, state, ',');
            state.erase(std::remove(state.begin(), state.end(), '\"'),state.end());

            //Age
            std::getline(data, temp, ','); //65 and Older
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            age.push_back(std::stof(temp));
            std::getline(data, temp, ','); //Under 18
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            age.push_back(std::stof(temp));
            std::getline(data, temp, ','); //Under 5
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            age.push_back(std::stof(temp));
            float over18 = 100 - age[1];  //Over 18
            age.push_back(over18);

            //Education
            std::getline(data, temp, ',');  //High school
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            float highschool = std::stof(temp);
            std::getline(data, temp, ',');  //Bachelor's
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            float bachelor = std::stof(temp);
            edu = std::make_pair(highschool,bachelor);

            //Nonemployer
            std::getline(data, temp, ',');

            //Ethnicities
            std::getline(data, temp, ','); //American Indian & Alaska Native
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            ethc.push_back(std::stof(temp));
            std::getline(data, temp, ','); //Asian
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            ethc.push_back(std::stof(temp));
            std::getline(data, temp, ','); //Black
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            ethc.push_back(std::stof(temp));
            std::getline(data, temp, ','); //Hispanic or Latino
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            ethc.push_back(std::stof(temp));
            std::getline(data, temp, ','); //Native Hawaiian & Other Pacific Islander
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            ethc.push_back(std::stof(temp));
            std::getline(data, temp, ','); //Two or More
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            float twoOrMore = stof(temp);        //To adjust the index of two or more
            std::getline(data, temp, ','); //White
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            ethc.push_back(std::stof(temp));
            std::getline(data, temp, ','); //White not Hispanic
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            ethc.push_back(std::stof(temp));
            ethc.push_back(twoOrMore);              //Add Two or More

            //Housing
            std::getline(data, temp, ','); //Homeownership Rate
            std::getline(data, temp, ','); //Households
            std::getline(data, temp, ','); //Housing Units
            std::getline(data, temp, ','); //Median Value of Owner Occupied
            std::getline(data, temp, ','); //Persons per Household

            //Income
            std::getline(data, temp, ','); //Median Household Income
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            int incMedHouse = std::stoi(temp);
            std::getline(data, temp, ','); //Per Capita Income
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            int perCap = std::stoi(temp);
            inc = std::make_pair(incMedHouse, perCap);

            //Miscellanous
            std::getline(data, temp, ','); //Foreign Born
            std::getline(data, temp, ','); //Land Area
            std::getline(data, temp, ','); //Language Other than English
            std::getline(data, temp, ','); //Living in Same House +1 year
            std::getline(data, temp, ','); //Manufacturers Shipments
            std::getline(data, temp, ','); //Mean Travel Time to Work
            std::getline(data, temp, ','); //Percent Female
            std::getline(data, temp, ','); //Veterans

            //Population
            std::getline(data, temp, ','); //2020 Population
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            pop.push_back(std::stof(temp));
            std::getline(data, temp, ','); //2010 Population
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            pop.push_back(std::stof(temp));
            std::getline(data, temp, ','); //Population per Square Mile
            temp.erase(std::remove(temp.begin(), temp.end(), '\"'),temp.end());
            pop.push_back(std::stof(temp));

            //Sales
            std::getline(data, temp, ',');

            //Employment Firms
            std::getline(data, temp, ','); //Total
            std::getline(data, temp, ','); //Women-Owned
            std::getline(data, temp, ','); //Men-Owned
            std::getline(data, temp, ','); //Minority-Owned
            std::getline(data, temp, ','); //Nonminority-Owned
            std::getline(data, temp, ','); //Veteran-Owned
            std::getline(data, temp, ','); //Nonveteran-Owned

            counties.emplace_back(index, name, state, pop, age, edu, ethc, inc);
            index++;

        }
    }
}
