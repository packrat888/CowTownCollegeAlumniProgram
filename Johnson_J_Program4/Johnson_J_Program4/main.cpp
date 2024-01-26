#include <sstream>
#include "class.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

vector<string> getFile(string fname) {
    vector<string> fcontents;
    string line;
    ifstream MyFile(fname);

    if (MyFile.is_open()) {
        while (getline(MyFile, line)) {
            fcontents.push_back(line);
        }
    }
    else {
        cout << "error";
    }
    return fcontents;
}

vector<string> split(const string s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


class HTMLTable
{
private:
    vector<string> headers;
    vector<vector<string> > rows;
    void writeRow(ostream& out, string tag, vector<string> row);
public:
    void setHeaders(const vector<string>& headers)
    {
        this->headers = headers;
    }
    void addRow(const vector<string>& row)
    {
        rows.push_back(row);
    }
    friend ostream& operator << (ostream& out, HTMLTable htmlTable);
};

void HTMLTable::writeRow(ostream& out, string tag,
    vector<string> row)
{
    out << "<tr>\n";
    for (unsigned int k = 0; k < headers.size(); k++)
    {
        out << "<" << tag << "> "
            << row[k] << " </" << tag << "> ";
    }
    out << "\n</tr>\n";
}

ostream& operator << (ostream& out, HTMLTable htmlTable)
{
    out << "<table border = \"1\">\n";
    out << "<thead>" << endl;
    out << "<tr>" << endl;
    out << "<th colspan=\"9\"\n>" << "Cow Town College Alumni" << "</th>" << endl;
    out << "</tr>" << endl;

   
    htmlTable.writeRow(out, "th", htmlTable.headers);
    out << "</thead>" << endl;
    out << "<tbody>" << endl;

    
    for (unsigned int r = 0; r < htmlTable.rows.size(); r++)
    {
        htmlTable.writeRow(out, "td", htmlTable.rows[r]);
    }
    out << "</tbody>" << endl;
    out << "</table>\n";
    return out;
}

vector<Alumni> displayReportOption2(vector<Alumni> lastName) {
    vector<string> sorting;
    for (size_t i = 0; i < lastName.size(); i++) {
        sorting.push_back(lastName[i].getLastName());
    }

    string temp;
    Alumni temp2;
    int j;
    for (size_t i = 1; i < sorting.size(); i++) {
        j = i;
        temp = sorting[i];
        temp2 = lastName[i];
        while (j > 0 && temp < sorting[j - 1]) {
            sorting[j] = sorting[j - 1];
            lastName[j] = lastName[j - 1];
            j--;
        }
        sorting[j] = temp;
        lastName[j] = temp2;
    }
    return lastName;
}
vector<Alumni> displayReportOption3(vector<Alumni> city) {
    string name;
    vector<string> state;
    for (size_t i = 0; i < city.size(); i++) {
        if (find(state.begin(), state.end(), city[i].getState()) != state.end()) {}
        else {
            state.push_back(city[i].getState());
        }
    }
    for (size_t i = 0; i < state.size(); i++) {
        cout << state[i] << endl;
    }
    cout << "Choose a state to get a report of members in that state(Enter the state as shown above with two Upper Case letters) : ";
    cin >> name;

    vector<Alumni> names;
    for (size_t i = 0; i < city.size(); i++) {
        if (city[i].getState() == name) {
            names.push_back(city[i]);
        }

    }

    vector<string> sorting;
    for (size_t i = 0; i < names.size(); i++) {
        sorting.push_back(names[i].getCity());
    }

    string temp;
    Alumni temp2;
    int j;
    for (size_t i = 1; i < sorting.size(); i++) {
        j = i;
        temp = sorting[i];
        temp2 = names[i];
        while (j > 0 && temp < sorting[j - 1]) {
            sorting[j] = sorting[j - 1];
            names[j] = names[j - 1];
            j--;
        }
        sorting[j] = temp;
        names[j] = temp2;
    }
    return names;



}

void displayReport(vector<Alumni>alumnus) {
    vector<string>headers{ "Last Name", "First Name", "Company", "Address", "City", "State",  "Zip", "Phone", "Email" };
    HTMLTable hTable;
    hTable.setHeaders(headers);


    for (Alumni a : alumnus) {
        hTable.addRow(a.toVect());
    }
    ofstream outFile("table.html");
    outFile << hTable;
    outFile.close();
    cout << hTable;
    system("table.html");
}
int main() {
    vector<string> file = getFile("cosc1337_members.csv");
    vector<Alumni>alumnus;


    for (string s : file) {
        vector<string> sSplit = split(s, ',');
        alumnus.push_back(Alumni(sSplit[0], sSplit[1], sSplit[2], sSplit[3], sSplit[4], sSplit[5], sSplit[6], sSplit[7], (sSplit[8])));

    }


    int choice;

    do {

        cout << "Cow Town College Alumni Reports Menu" << endl;
        cout << "=======================================================" << endl;
        cout << "1: All Members by natural Order of Input File" << endl;
        cout << "2: All Members Sorted Ascending by Last Name" << endl;
        cout << "3: Members in One State Only, sorted Ascending by City" << endl;
        cout << "0: Exit the program" << endl;
        cout << "Please select report you wish to be run from menu above(0-3): ";


        cin >> choice;
        switch (choice) {
        case 1: {
            displayReport(alumnus);
            break;
        }
        case 2: {
            displayReport(displayReportOption2(alumnus));
            break;
        }
        case 3: {
            displayReport(displayReportOption3(alumnus));
            break;
        }
        case 0: {
            exit(0);
        }
        default: {
            cout << "Not a valid choice. Enter a valid option." << endl;
        }

        }

    } while (choice != 0);
    return 0;
}