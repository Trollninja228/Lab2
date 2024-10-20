#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct student {
    string last_name;
    string first_name;
    double GPA;

    void print() {
        cout << last_name << " " << first_name << " " << fixed << setprecision(3) << GPA << endl;
    }
};

bool compare(const student &a, const student &b) {
    if (a.GPA != b.GPA) {
        return a.GPA < b.GPA;
    } else if (a.last_name != b.last_name) {
        return a.last_name < b.last_name;
    } else {
        return a.first_name < b.first_name;
    }
}

double calcGPA(int m) {
    double g1;
    double sum = 0;
    double sum1 = 0;
    string g;
    double c;
    for (int i = 0; i < m; i++) {
        cin >> g >> c;
        if (g == "A+") {
            g1 = 4.000;
        } else if (g == "A") {
            g1 = 3.750;
        } else if (g == "B+") {
            g1 = 3.500;
        } else if (g == "B") {
            g1 = 3.000;
        } else if (g == "C+") {
            g1 = 2.500;
        } else if (g == "C") {
            g1 = 2.000;
        } else if (g == "D+") {
            g1 = 1.500;
        } else if (g == "D") {
            g1 = 1.000;
        } else {
            g1 = 0.000;
        }
        sum += g1 * c;
        sum1 += c;
    }
    return sum / sum1;
}

int main() {
    int n, m;
    cin >> n;
    vector<student> st(n);
    for (int i = 0; i < n; i++) {
        cin >> st[i].last_name >> st[i].first_name >> m;
        st[i].GPA = calcGPA(m);
    }

    sort(st.begin(), st.end(), compare);

    for (int i = 0; i < n; i++) {
        st[i].print();
    }

    return 0;
}
