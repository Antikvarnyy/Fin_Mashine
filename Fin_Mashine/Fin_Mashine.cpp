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

    double sub_car[30];
    double sub_transport[30];
    double sub_food[30];
    double sub_flat[30];
    double sub_medicine[30];
    double sub_other[30];

    double car_sum_week;
    double transport_sum_week;
    double food_sum_week;
    double flat_sum_week;
    double medicine_sum_week;
    double other_sum_week;

    double car_sum_month;
    double transport_sum_month;
    double food_sum_month;
    double flat_sum_month;
    double medicine_sum_month;
    double other_sum_month;


public:

    Finance() {
        card1_credit = 0;
        card2_credit = 0;
        card1_debut = 0;
        card2_debut = 0;

        for (int i = 0; i < 30; i++) {
            sub_car[i] = 0;
            sub_transport[i] = 0;
            sub_food[i] = 0;
            sub_flat[i] = 0;
            sub_medicine[i] = 0;
            sub_other[i] = 0;
        }

        car_sum_week = 0;
        transport_sum_week = 0;
        food_sum_week = 0;
        flat_sum_week = 0;
        medicine_sum_week = 0;
        other_sum_week = 0;

        car_sum_month = 0;
        transport_sum_month = 0;
        food_sum_month = 0;
        flat_sum_month = 0;
        medicine_sum_month = 0;
        other_sum_month = 0;

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
        for (int i = 0; i < 30; i++) {
            if (sub_car[i] != 0) {
                cout << "\nDay " << i+1 << ": " << sub_car[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this month\n";
        else
            cout << "\n";
        f = 0;

        cout << "===============\nPublic transport: ";
        for (int i = 0; i < 30; i++) {
            if (sub_transport[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_transport[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this month\n";
        else
            cout << "\n";
        f = 0;

        cout << "===============\nFood: ";
        for (int i = 0; i < 30; i++) {
            if (sub_food[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_food[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this month\n";
        else
            cout << "\n";
        f = 0;

        cout << "===============\nFlat: ";
        for (int i = 0; i < 30; i++) {
            if (sub_flat[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_flat[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this month\n";
        else
            cout << "\n";
        f = 0;

        cout << "===============\nMedicine: ";
        for (int i = 0; i < 30; i++) {
            if (sub_medicine[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_medicine[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this month\n";
        else
            cout << "\n";
        f = 0;

        cout << "===============\nOther: ";
        for (int i = 0; i < 30; i++) {
            if (sub_other[i] != 0) {
                cout << "\nDay " << i + 1 << ": " << sub_other[i] << " $";
                f++;
            }
        }
        if (f == 0)
            cout << "No spending this month\n";
        else
            cout << "\n";

        cout << "===============\nTotal spends by week:\n===============\n";
        cout << "Car: " << car_sum_week << " $\n";
        cout << "Public transport: " << transport_sum_week << " $\n";
        cout << "Food: " << food_sum_week << " $\n";
        cout << "Flat: " << flat_sum_week << " $\n";
        cout << "Medicine: " << medicine_sum_week << " $\n";
        cout << "Other: " << other_sum_week << " $\n";

        cout << "===============\nTotal spends by month:\n===============\n";
        cout << "Car: " << car_sum_month << " $\n";
        cout << "Public transport: " << transport_sum_month << " $\n";
        cout << "Food: " << food_sum_month << " $\n";
        cout << "Flat: " << flat_sum_month << " $\n";
        cout << "Medicine: " << medicine_sum_month << " $\n";
        cout << "Other: " << other_sum_month << " $\n";

    }
    void Input_Sub() {
        char ch1, ch2, ch3;
        int ch4 = 0;
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
            cout << "When you spend this money?Enter day: ";
            cin >> s;
            if (CheckingDouble(s))
                ch4 = stoi(s);
            else
                cout << "Error";
        } while (ch4 < 1 || ch4>30);
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

        if (ch3 == '1'){
            if (ch4 < 8)
                car_sum_week += d;
            car_sum_month += d;
            sub_car[ch4 - 1] = d;
        }
        else  if (ch3 == '2') {
            if (ch4 < 8)
                transport_sum_week += d;
            transport_sum_month += d;
            sub_transport[ch4 - 1] = d;
        }
        else  if (ch3 == '3') {
            if (ch4 < 8)
                food_sum_week += d;
            food_sum_month += d;
            sub_food[ch4 - 1] = d;
        }
        else  if (ch3 == '4') {
            if (ch4 < 8)
                flat_sum_week += d;
            flat_sum_month += d;
            sub_flat[ch4 - 1] = d;
        }
        else  if (ch3 == '5') {
            if (ch4 < 8)
                medicine_sum_week += d;
            medicine_sum_month += d;
            sub_medicine[ch4 - 1] = d;
        }
        else  if (ch3 == '6') {
            if (ch4 < 8)
                other_sum_week += d;
            other_sum_month += d;
            sub_other[ch4 - 1] = d;
        }
    }
    void Sort_Week() {       
        double mas[6] = { car_sum_week, transport_sum_week, food_sum_week, flat_sum_week, medicine_sum_week, other_sum_week };
        for (int i = 0; i < 6 - 1; ++i)
        {
            int min = i;
            for (int cur = i + 1; cur < 6; ++cur)
            {
                if (mas[cur] > mas[min])
                    min = cur;
            }
            swap(mas[i], mas[min]);
        }
        if (mas[0] == car_sum_week)
            cout << "1: Car: " << car_sum_week << " $ by week";
        else if(mas[0] == transport_sum_week)
            cout << "1: Public transport: " << transport_sum_week << " $ by week";
        else if (mas[0] == transport_sum_week)
            cout << "1: Food: " << food_sum_week << " $ by week";
        else if (mas[0] == transport_sum_week)
            cout << "1: Flat: " << flat_sum_week << " $ by week";
        else if (mas[0] == transport_sum_week)
            cout << "1: Medicine: " << medicine_sum_week << " $ by week";
        else if (mas[0] == transport_sum_week)
            cout << "1: Other: " << other_sum_week << " $ by week";

        if (mas[1] == car_sum_week)
            cout << "2: Car: " << car_sum_week << " $ by week";
        else if (mas[1] == transport_sum_week)
            cout << "2: Public transport: " << transport_sum_week << " $ by week";
        else if (mas[1] == transport_sum_week)
            cout << "2: Food: " << food_sum_week << " $ by week";
        else if (mas[1] == transport_sum_week)
            cout << "2: Flat: " << flat_sum_week << " $ by week";
        else if (mas[1] == transport_sum_week)
            cout << "2: Medicine: " << medicine_sum_week << " $ by week";
        else if (mas[1] == transport_sum_week)
            cout << "2: Other: " << other_sum_week << " $ by week";

        if (mas[2] == car_sum_week)
            cout << "3: Car: " << car_sum_week << " $ by week";
        else if (mas[2] == transport_sum_week)
            cout << "3: Public transport: " << transport_sum_week << " $ by week";
        else if (mas[2] == transport_sum_week)
            cout << "3: Food: " << food_sum_week << " $ by week";
        else if (mas[2] == transport_sum_week)
            cout << "3: Flat: " << flat_sum_week << " $ by week";
        else if (mas[2] == transport_sum_week)
            cout << "3: Medicine: " << medicine_sum_week << " $ by week";
        else if (mas[2] == transport_sum_week)
            cout << "3: Other: " << other_sum_week << " $ by week";

    }
};


int main()
{
    Finance F;
    F.Sort_Week();
    return 0;
    F.Input_Sub();
    system("cls");
    F.Print();
}