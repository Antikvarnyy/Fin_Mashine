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
    double card1_debut;
    double card2_debut;
    double card1_credit;
    double card2_credit;

    double sub_car[7];
    double sub_transport[7];
    double sub_food[7];
    double sub_flat[7];
    double sub_medicine[7];
    double sub_other[7];

    double car_sum;
    double transport_sum;
    double food_sum;
    double flat_sum;
    double medicine_sum;
    double other_sum;

public:

    Finance() {
        card1_credit = 0;
        card2_credit = 0;
        card1_debut = 0;
        card2_debut = 0;

        for (int i = 0; i < 7; i++) {
            sub_car[i] = 0;
            sub_transport[i] = 0;
            sub_food[i] = 0;
            sub_flat[i] = 0;
            sub_medicine[i] = 0;
            sub_other[i] = 0;
        }

        car_sum = 0;
        transport_sum = 0;
        food_sum = 0;
        flat_sum = 0;
        medicine_sum = 0;
        other_sum = 0;
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
    void Print() {
        int f = 0;
        cout << "===============\nWallet 1:\nDebut card: " << card1_debut << " $\nCredit card: " << card1_credit << " $\n";
        cout << "===============\nWallet 2:\nDebut card: " << card2_debut << " $\nCredit card: " << card2_credit << " $\n";
        cout << "===============\nSpending:\n";
        cout << "===============\nCar: ";
        for (int i = 0; i < 7; i++) {
            if (sub_car[i] != 0) {
                cout << "\nDay " << i+1 << ": " << sub_car[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this week\n";
        else
            cout << "\n";
        f = 0;
        cout << "===============\nPublic transport: ";
        for (int i = 0; i < 7; i++) {
            if (sub_transport[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_transport[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this week\n";
        else
            cout << "\n";
        f = 0;
        cout << "===============\nFood: ";
        for (int i = 0; i < 7; i++) {
            if (sub_food[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_food[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this week\n";
        else
            cout << "\n";
        f = 0;
        cout << "===============\nFlat: ";
        for (int i = 0; i < 7; i++) {
            if (sub_flat[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_flat[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this week\n";
        else
            cout << "\n";
        f = 0;
        cout << "===============\nMedicine: ";
        for (int i = 0; i < 7; i++) {
            if (sub_medicine[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_medicine[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this week\n";
        else
            cout << "\n";
        f = 0;
        cout << "===============\nOther: ";
        for (int i = 0; i < 7; i++) {
            if (sub_other[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_other[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this week\n";
        else
            cout << "\n";

        cout << "===============\nTotal spends by week:\n===============\n";
        cout << "Car: " << car_sum << " $\n";
        cout << "Public transport: " << transport_sum << " $\n";
        cout << "Food: " << food_sum << " $\n";
        cout << "Flat: " << flat_sum << " $\n";
        cout << "Medicine: " << medicine_sum << " $\n";
        cout << "Other: " << other_sum << " $\n";
    }
    void Input_Sub() {
        char ch1, ch2, ch3, ch4;
        string s;
        double d;

        do {
            cout << "Which wallet you used?(1 or 2)\n";
            ch1 = _getch();
        } while (ch1 != '1' && ch1 != '2');
        do {
            cout << "Which card you used?\n1 - Debut\n2 - Credit\n";
            ch2 = _getch();
        } while (ch2 != '1' && ch2 != '2');
        do {
            cout << "What category is spending?\n1 - Car\n2 - Public transport\n3 - Food\n4 - Flat\n5 - Medisine\\drugs\n6 - Other\n";
            ch3 = _getch();
        } while (ch3 != '1' && ch3 != '2' && ch3 != '3' && ch3 != '4' && ch3 != '5' && ch3 != '6');
        do {
            cout << "When you spend this money?\n1 - Mondey\n2 - Thuesday\n3 - Wensday\n4 - Thursday\n5 - Friday\n6 - Saturday\n7 - Sunday\n";
            ch4 = _getch();
        } while (ch4 != '1' && ch4 != '2' && ch4 != '3' && ch4 != '4' && ch4 != '5' && ch4 != '6' && ch4 != '7');
        do {
            cout << "Enter the amount of spend: ";
            cin >> s;
            if (CheckingDouble(s))
                d = stof(s);
            else
                cout << "Error\n";
        } while (!CheckingDouble(s));

        if (ch1 == '1') {
            if (ch2 == '1') {
                if (card1_debut < d) {
                    cout << "You cannot spend more than what is on the debut card.\nThe rest of the spending will be deducted from the credit card account of the same wallet\n";
                    d -= card1_debut;
                    card1_debut = 0;
                    card1_credit -= d;
                    if (card1_credit < d)
                        cout << "Your credit card balance is negative. Please pay off the debt as soon as possible\n";
                }
                else {
                    card1_debut -= d;
                }
            }
            else {
                card1_credit -= d;
                if (card1_credit < d)
                    cout << "Your credit card balance is negative. Please pay off the debt as soon as possible\n";
            }
        }
        else {
            if (ch2 == '1') {
                if (card2_debut < d) {
                    cout << "You cannot spend more than what is on the debut card.\nThe rest of the spending will be deducted from the credit card account of the same wallet\n";
                    d -= card2_debut;
                    card2_debut = 0;
                    card2_credit -= d;
                    if (card1_credit < d)
                        cout << "Your credit card balance is negative. Please pay off the debt as soon as possible\n";
                }
                else {
                    card2_debut -= d;
                }

            }
            else {
                card2_credit -= d;
                if (card1_credit < d)
                    cout << "Your credit card balance is negative. Please pay off the debt as soon as possible\n";
            }
        }

        if (ch3 == '1') {
            if (ch4 == '1') {
                sub_car[0] += d;
            }
            else if (ch4 == '2') {
                sub_car[1] += d;
            }
            else if (ch4 == '3') {
                sub_car[2] += d;
            }
            else if (ch4 == '4') {
                sub_car[3] += d;
            }
            else if (ch4 == '5') {
                sub_car[4] += d;
            }
            else if (ch4 == '6') {
                sub_car[5] += d;
            }
            else if (ch4 == '7') {
                sub_car[6] += d;
            }
            car_sum = 0;
            for (int i = 0; i < 7; i++) {
                car_sum += sub_car[i];
            }
        }
        else if (ch3 == '2') {
            if (ch4 == '1') {
                sub_transport[0] += d;
            }
            else if (ch4 == '2') {
                sub_transport[1] += d;
            }
            else if (ch4 == '3') {
                sub_transport[2] += d;
            }
            else if (ch4 == '4') {
                sub_transport[3] += d;
            }
            else if (ch4 == '5') {
                sub_transport[4] += d;
            }
            else if (ch4 == '6') {
                sub_transport[5] += d;
            }
            else if (ch4 == '7') {
                sub_transport[6] += d;
            }
            transport_sum = 0;
            for (int i = 0; i < 7; i++) {
                transport_sum += sub_transport[i];
            }
        }
        else if (ch3 == '3') {
            if (ch4 == '1') {
                sub_food[0] += d;
            }
            else if (ch4 == '2') {
                sub_food[1] += d;
            }
            else if (ch4 == '3') {
                sub_food[2] += d;
            }
            else if (ch4 == '4') {
                sub_food[3] += d;
            }
            else if (ch4 == '5') {
                sub_food[4] += d;
            }
            else if (ch4 == '6') {
                sub_food[5] += d;
            }
            else if (ch4 == '7') {
                sub_food[6] += d;
            }
            food_sum = 0;
            for (int i = 0; i < 7; i++) {
                food_sum += sub_food[i];
            }
        }
        else if (ch3 == '4') {
            if (ch4 == '1') {
                sub_flat[0] += d;
            }
            else if (ch4 == '2') {
                sub_flat[1] += d;
            }
            else if (ch4 == '3') {
                sub_flat[2] += d;
            }
            else if (ch4 == '4') {
                sub_flat[3] += d;
            }
            else if (ch4 == '5') {
                sub_flat[4] += d;
            }
            else if (ch4 == '6') {
                sub_flat[5] += d;
            }
            else if (ch4 == '7') {
                sub_flat[6] += d;
            }
            flat_sum = 0;
            for (int i = 0; i < 7; i++) {
                flat_sum += sub_flat[i];
            }
        }
        else if (ch3 == '5') {
            if (ch4 == '1') {
                sub_medicine[0] += d;
            }
            else if (ch4 == '2') {
                sub_medicine[1] += d;
            }
            else if (ch4 == '3') {
                sub_medicine[2] += d;
            }
            else if (ch4 == '4') {
                sub_medicine[3] += d;
            }
            else if (ch4 == '5') {
                sub_medicine[4] += d;
            }
            else if (ch4 == '6') {
                sub_medicine[5] += d;
            }
            else if (ch4 == '7') {
                sub_medicine[6] += d;
            }
            medicine_sum = 0;
            for (int i = 0; i < 7; i++) {
                medicine_sum += sub_medicine[i];
            }
        }
        else {
            if (ch4 == '1') {
                sub_other[0] += d;
            }
            else if (ch4 == '2') {
                sub_other[1] += d;
            }
            else if (ch4 == '3') {
                sub_other[2] += d;
            }
            else if (ch4 == '4') {
                sub_other[3] += d;
            }
            else if (ch4 == '5') {
                sub_other[4] += d;
            }
            else if (ch4 == '6') {
                sub_other[5] += d;
            }
            else if (ch4 == '7') {
                sub_other[6] += d;
            }
            other_sum = 0;
            for (int i = 0; i < 7; i++) {
                other_sum += sub_other[i];
            }
        }
    }
};


int main()
{
    Finance F;
    F.Input_Sub();
    system("cls");
    F.Print();
}