#include "County.h"

County::County(int index, string name, string state, vector<float> pop, vector<float> age, pair<float,float> edu,
               vector<float> ethc, pair<int, int> inc)
{
    this->score = 0;
    this->index = index;
    this->name = name;
    this->state = state;
    this->pop = pop;
    this->age = age;
    this->edu = edu;
    this->ethnic = ethc;
    this->income = inc;
}

void County::calculateRank(vector<pair<float, int>>& input, int ethcIndex)
{
    float tempScore;

    float popScore = std::abs((input[0].first - pop[0]) / pop[0] ) * (float) input[0].second;
    //cout << "pop: " << popScore << "\n";
    float ethcScore = std::abs((input[1].first - ethnic[ethcIndex]) / ethnic[ethcIndex] ) * (float) input[1].second;
    //cout << "ethnic: " << ethcScore << "\n";
    float ageScore = std::abs((input[2].first - age[3]) / age[3] )  * (float) input[2].second;
    //cout << "age: " << ageScore << "\n";
    float eduScore = std::abs((input[3].first - edu.first) / edu.first ) * (float) input[3].second;
    //cout << "edu: " << eduScore << "\n";
    float incScore = std::abs((input[4].first - (float) income.first) / (float) income.first ) * (float) input[4].second;
    //cout << "income: " << incScore << "\n";
    tempScore = popScore + ethcScore + ageScore + eduScore + incScore;
    //cout << "tempScore: " << tempScore;

    score = tempScore;

}

void County::display()
{
    cout << "[Index " << index << "] - County: " << name << " | State: " << state << "\n";
    cout << "Score: " << score << "\n";
}


void County::displayAttributes()
{
    display();
    cout << "2020 Population: " << pop[0] << "\n";
    cout << "Ages Over 18: "  << age[3] << "%\n";
    cout << "Bachelor's Degree or Higher: " << edu.first << "%\n";
    cout << "American Indian and Alaska Native: " << ethnic[0] << "%\n";
    cout << "Asian: " << ethnic[1] << "%\n";
    cout << "Black: " << ethnic[2] << "%\n";
    cout << "Hispanic or Latino: " << ethnic[3] << "%\n";
    cout << "Native Hawaiian and Other Pacific Islander: " << ethnic[4] << "%\n";
    cout << "White: " << ethnic[5] << "%\n";

    cout << "Median Household Income: " << income.first << "\n";

}

void County::printName()
{
    cout << "[Index " << index << "] - County: " << name << " | State: " << state;
}

void County::printPop()
{
    cout << "--Population--\n";
    cout << "2020 Population: " << pop[0] << "\n";
    cout << "Population per Square: " << pop[2] << "\n";
}

void County::printAge()
{
    cout << "--Age--\n";
    cout << "Ages 65 and Older: " << age[0] << "%\n";
    cout << "Ages Over 18: "  << age[3] << "%\n";
    cout << "Ages Under 18: " << age[1] << "%\n";
    cout << "Ages Under 5: " << age[2] << "%\n";
}

void County::printEdu()
{
    cout << "--Education--\n";
    cout << "Bachelor's Degree or Higher: " << edu.first << "%\n";
    cout << "High School Diploma or Higher: " << edu.second << "%\n";
}

void County::printEthc()
{
    cout << "--Ethnicity--\n";
    cout << "American Indian and Alaska Native: " << ethnic[0] << "%\n";
    cout << "Asian: " << ethnic[1] << "%\n";
    cout << "Black: " << ethnic[2] << "%\n";
    cout << "Hispanic or Latino: " << ethnic[3] << "%\n";
    cout << "Native Hawaiian and Other Pacific Islander: " << ethnic[4] << "%\n";
    cout << "White: " << ethnic[5] << "%\n";
    cout << "White not Hispanic or Latino: " << ethnic[6] << "%\n";
    cout << "Two or More Races: " << ethnic[7] << "%\n";

}

void County::printInc()
{
    cout << "--Income--\n";
    cout << "Median Household Income: " << income.first << "\n";
    cout << "Per Capita Income: " << income.second << "\n";
}

void County::printAll()
{
    display();
    //cout << "\n";
    printPop();
    //cout << "\n";
    printAge();
    //cout << "\n";
    printEdu();
    //cout << "\n";
    printEthc();
    //cout << "\n";
    printInc();
}

bool County::operator<(const County &rhs) const
{
    return this->score < rhs.score;
}

bool County::operator<=(const County &rhs) const
{
    return this->score <= rhs.score;
}

bool County::operator>(const County &rhs) const
{
    return !operator<(rhs);
}
