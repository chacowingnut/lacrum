#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "csv.hpp"
using namespace std;


void CSVTable::add_col(string col_name, double* val_link) {
    if (row_added) {
        cerr << "You've already started chalking up rows!" << endl;
    } else {
        col_names.push_back(col_name);
        val_links.push_back(val_link);
        output = make_header();
    }
}

string CSVTable::make_header() {
    int n = col_names.size();
    string out;
    for (int i = 0; i < n; i ++) {
        if (i > 0) {
            out += ",";
        }
        out += col_names[i];
    }
    return out;
}

void CSVTable::add_row() {
    int n = col_names.size();
    for (int i = 0; i < n; i ++) {
        if (i == 0) {
            output += "\n";
        } else {
            output += ",";
        }
        output += to_string(*val_links[i]);
    }
    row_added = true;
}

void CSVTable::say() {
    cout << output << endl;
}

void CSVTable::write(string csv_path) {
    ofstream outfile(csv_path);

    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
    }

    outfile << output << endl;

    outfile.close();
}


// int main() {
//     float bar = 3.14;
//     float baz = 2.71;

//     CSVTable foo;
//     foo.add_col("bar", &bar);
//     foo.add_col("baz", &baz);
//     foo.add_row();
//     for (int i = 0; i < 10; i++) {
//         bar += 1;
//         baz += 1;
//         foo.add_row();
//     }
//     foo.say();
//     foo.write("deleteme.csv");
//     return 0;
// }