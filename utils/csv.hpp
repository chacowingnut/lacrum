#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


/**
 * A class for managing float data that will ultimately end up in
 * a CSV for plotting with Python/JS/Winplot/Excel
 */
struct CSVTable {
    /**
     * Names of the columns of the CSV
     */
    vector<string> col_names;

    /**
     * Pointers to the variables that correspond to the column values
     */
    vector<float*> val_links;

    /**
     * Whether the class has started accumulating table data. We
     * cannot add new columns once data tabulation has begun.
     */
    bool row_added = false;

    /**
     * The CSV table output
     */
    string output;

    void add_col(string col_name, float* val_link);

    string make_header();

    void add_row();

    void say();

    void write(string csv_path);
};