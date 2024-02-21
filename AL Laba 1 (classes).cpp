#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// ВАРИАНТ 23

struct exhibit {
    string name;
    double days;
    double price_per_day;
};

class Exhibits {
public:
    vector<exhibit> exhibits;
    Exhibits() {
    };
    Exhibits(string file_name) {
        ifstream file(file_name);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                string kusok;
                istringstream ss(line);
                exhibit exhibit;
                ss >> kusok;
                exhibit.name = kusok;
                ss >> kusok;
                exhibit.days = stod(kusok);
                ss >> kusok;
                exhibit.price_per_day = stod(kusok);
                this->exhibits.push_back(exhibit);
            }
            file.close();
        }
        else {
            cout << "Input file didn't open";
        }
    };
    void print(string name) { // По названию
        for (int i = 0; i < exhibits.size(); i++) {
            if (exhibits[i].name == name) {
                cout << "Name: " << exhibits[i].name << "; Days : " << exhibits[i].days << "; Price per day : " << exhibits[i].price_per_day << endl;
                ofstream file("output.txt");
                if (file.is_open()) {
                    file << exhibits[i].name << " ";
                    file << exhibits[i].days << " ";
                    file << exhibits[i].price_per_day << endl;
                    file.close();
                }
                else {
                    cout << "Output file didn't open";
                }
                break;
            }
        }
    };
    void print(int number) { // По номеру
        for (int i = 0; i < exhibits.size(); i++) {
            if ((i + 1) == number) {
                cout << "Name: " << exhibits[i].name << "; Days : " << exhibits[i].days << "; Price per day : " << exhibits[i].price_per_day << endl;
                ofstream file("output.txt");
                if (file.is_open()) {
                    file << exhibits[i].name << " ";
                    file << exhibits[i].days << " ";
                    file << exhibits[i].price_per_day << endl;
                    file.close();
                }
                else {
                    cout << "Output file didn't open";
                }
                break;
            }
        }
    };
    void print_all() {
        ofstream file("output.txt");
        if (not file.is_open()) {
            cout << "Output file didn't open";
        }
        double max = 0;
        string max_name;
        for (int i = 0; i < exhibits.size(); i++) {
            cout << i << ") Name: " << exhibits[i].name << "; Days: " << exhibits[i].days << "; Price per day: " << exhibits[i].price_per_day << endl;
            if (this->total_price(i) > max) {
                max = this->total_price(i);
                max_name = this->exhibits[i].name;
            }
            if (file.is_open()) {
                file << exhibits[i].name << " ";
                file << exhibits[i].days << " ";
                file << exhibits[i].price_per_day << endl;
            }
        }
        cout << max_name << " has the highest exhibit price of " << max << endl;
        if (file.is_open()) {
            file << max_name << " has the highest exhibit price of " << max << endl;
            file.close();
        }
    };
    void total_price(string name) { // По названию
        for (int i = 0; i < exhibits.size(); i++) {
            if (exhibits[i].name == name) {
                cout << "Total price of '" << exhibits[i].name << "' exhibit = " << exhibits[i].price_per_day * exhibits[i].days << endl;
                break;
            }
        }
    };
    double total_price(int number) { // По номеру
        for (int i = 0; i < exhibits.size(); i++) {
            if ((i + 1) == number) {
                return exhibits[i].price_per_day * exhibits[i].days;
            }
        }
    };
};

int main()
{
    /*Exhibits exhibits;
    for (int i = 1; i < 4; i++) {
        exhibit exhibit;
        exhibit.name = "Exhibit-" + to_string(i);
        exhibit.days = i * 2;
        exhibit.price_per_day = i * 3;
        exhibits.exhibits.push_back(exhibit);
    };
    exhibits.print_all();
    cout << "Total price of '" << exhibits[i].name << "' exhibit = " << exhibits.total_price(3) << endl;*/
    Exhibits exhibits("input.txt");
    exhibits.print_all();
}
