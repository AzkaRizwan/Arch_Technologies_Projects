#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

const int MIN_DICE = 1;
const int MAX_DICE = 6;

int rollDie()
{
    return (rand() % MAX_DICE) + MIN_DICE;
}

void getDiceRows(int val, string rows[5])
{
    switch (val)
    {
    case 1:
        rows[0] = "+-------+";
        rows[1] = "|       |";
        rows[2] = "|   *   |";
        rows[3] = "|       |";
        rows[4] = "+-------+";
        break;
    case 2:
        rows[0] = "+-------+";
        rows[1] = "| *     |";
        rows[2] = "|       |";
        rows[3] = "|     * |";
        rows[4] = "+-------+";
        break;
    case 3:
        rows[0] = "+-------+";
        rows[1] = "| *     |";
        rows[2] = "|   *   |";
        rows[3] = "|     * |";
        rows[4] = "+-------+";
        break;
    case 4:
        rows[0] = "+-------+";
        rows[1] = "| *   * |";
        rows[2] = "|       |";
        rows[3] = "| *   * |";
        rows[4] = "+-------+";
        break;
    case 5:
        rows[0] = "+-------+";
        rows[1] = "| *   * |";
        rows[2] = "|   *   |";
        rows[3] = "| *   * |";
        rows[4] = "+-------+";
        break;
    case 6:
        rows[0] = "+-------+";
        rows[1] = "| *   * |";
        rows[2] = "| *   * |";
        rows[3] = "| *   * |";
        rows[4] = "+-------+";
        break;
    }
}

void displayResults(int die1, int die2)
{
    string rows1[5], rows2[5];
    getDiceRows(die1, rows1);
    getDiceRows(die2, rows2);

    cout << "\n  Rolling the dice...\n"
         << endl;
    cout << "   Die 1          Die 2" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "   " << rows1[i] << "   " << rows2[i] << endl;
    }

    cout << "\n  Die 1 rolled : " << die1 << endl;
    cout << "  Die 2 rolled : " << die2 << endl;
    cout << "  ---------------------" << endl;
    cout << "  Total        : " << die1 + die2 << endl;

    if (die1 == die2)
        cout << "\n  ** Doubles! Both dice show " << die1 << "! **" << endl;
    if (die1 + die2 == 12)
        cout << "\n  ** Boxcars! Maximum roll (12)! **" << endl;
    if (die1 + die2 == 2)
        cout << "\n  ** Snake Eyes! Minimum roll (2)! **" << endl;
}

bool askRollAgain()
{
    char choice;
    cout << "\n  Roll again? (y/n): ";

    while (true)
    {
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        choice = tolower(choice);

        if (choice == 'y')
            return true;
        if (choice == 'n')
            return false;

        cout << "  Invalid input! Please enter 'y' or 'n': ";
    }
}

void displayDivider()
{
    cout << "  =====================================" << endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int totalRolls = 0;
    int grandTotal = 0;

    cout << endl;
    displayDivider();
    cout << "         DICE ROLLING GAME" << endl;
    displayDivider();
    cout << endl;

    do
    {
        int die1 = rollDie();
        int die2 = rollDie();

        displayResults(die1, die2);

        totalRolls++;
        grandTotal += die1 + die2;

    } while (askRollAgain());

    cout << endl;
    displayDivider();
    cout << "  Session Summary:" << endl;
    cout << "  Total rolls      : " << totalRolls << endl;
    cout << "  Grand total      : " << grandTotal << endl;
    if (totalRolls > 0)
        cout << "  Average per roll : " << (double)grandTotal / totalRolls << endl;
    displayDivider();
    cout << "  Thanks for playing! Goodbye." << endl;
    cout << endl;

    return 0;
}