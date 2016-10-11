// Stefan Retief
// CS211 game.C, HW4
// inputCheck Header - Header File
// ======================================================

#include <iostream>
using namespace std;

char getLetter(string msg)
{
    string input;
    cin >> input;
    while(input.length() != 1 || !isalpha(input[0]))
    {
        cout << msg;
        cin >> input;
    }
    return input[0];
}

char getResponse(string msg)
{
    char ch;
    ch = getLetter(msg);
    while(toupper(ch) != 'Y' && toupper(ch) != 'N')
    {
        cout << msg;
        ch = getLetter(msg);
    }
    return toupper(ch);
}

char getGender(string msg)
{
    char ch;
    ch = getLetter(msg);
    while(toupper(ch) != 'M' && toupper(ch) != 'F')
    {
        cout << msg;
        ch = getLetter(msg);
    }
    return toupper(ch);
}

int getNumberInRange(int low, int high, string msg) {
    string input;
    bool nonNumber; //set to true if the user's input contains a non-digit character bool invalid;
    cin >> input;
    do {
        //reset something at the beginning of each loop
        nonNumber = false;
        //check each character in "input" and if a non-digit character is found, set "nonNumber" to true
        for(int i = 0; i < input.length(); i++) {
            if (!isdigit(input[i]))
                nonNumber = true;
        }
        //if one of the following 3 conditions is true, "input" is invalid, then “invalid” is set to true. If all the conditions
        //fail, “input” is valid, then “invalid” is set to false.
        // 1. "nonNumber" is true ("input" contains a non-digit character.) e.g. 1@0
        // 2. the number is less than the bottom boundary. e.g. -1 (if low is 0)
        // 3. the number is larger than the top boundary. e.g. 101 (if high is 100)
        bool invalid = nonNumber || atoi(input.c_str()) < low || atoi(input.c_str()) > high;
        //if “invalid” is true, ask for a new input
        if(invalid) { //same as invalid == true {
            cout << msg;
            cin >> input;
			nonNumber = true;
        }
    } while(nonNumber);
    //returning a valid integer between low and high
    return atoi(input.c_str());
}

string getAlpha(string msg)
{
    string input;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++)
    {
        while(!isalpha(input[i]) && input[i] != ' ')
        {
            cout << msg;
            getline(cin, input);
            i = 0;
        }
        input[i] = toupper(input[i]);
    }
    return input;
}


