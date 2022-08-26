#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

bool CheckingDouble(const string& s) {
    bool b = true;
    for (auto& a : s) {
        if (!isdigit(a) && a != '.' && a != '-') {
            b = false;
            break;
        }
    }
    return b;
}

class Finance {
public:
    double card1_debut;
    double card2_debut;
    double card1_credit;
    double card2_credit;

    Finance() {
        card1_credit = 0;
        card2_credit = 0;
        card1_debut = 0;
        card2_debut = 0;
    }

    void Input() {
        char ch1,ch2;
        string s;
        double d;
        do {
            cout << "Which wallet do you want to fill?(1 or 2)\n";
            ch1 = _getch();
        } while (ch1 != '1' && ch1 != '2');
        do {
            cout << "Which card do you want to fill?\n1 - Debut\n2 - Credit\n";
            ch2 = _getch();
        } while (ch2 != '1' && ch2 != '2');
        do {
            cout << "Enter the amount to replenish: ";
            cin >> s;
            if (CheckingDouble(s))
                d = stof(s);
            else
                cout << "Error\n";
        } while (!CheckingDouble(s));
        if (ch1 == '1') {
            if (ch2 == '1') {
                card1_debut += d;
            }
            else {
                card1_credit += d;
            }
        }
        else {
            if (ch2 == '1') {
                card2_debut += d;
            }
            else {
                card2_credit += d;
            }
        }
    }
};


int main()
{

}