#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

// Multiply with matrix as easy as possible.

using std::cin;
using std::cout;
using std::endl;
using std::pow;
using std::string;
using std::vector;

int take_just_input(string &&message = "");
void take_matrix_input(vector<vector<double>> &matrix);
void display_matrix(const vector<vector<double>> &matrix);
void multiply_matrix(vector<vector<double>> &matrix, double &mul);

void display_matrix(const vector<vector<double>> &matrix)
{
    for (const auto &first_d : matrix)
    {
        cout << " | ";
        for (const auto &second_d : first_d)
            cout << std::setw(10) << second_d << " |";
        cout << endl;
    }
}

void take_matrix_input(vector<vector<double>> &matrix)
{
    for (auto &first_d : matrix)
        for (auto &second_d : first_d)
            cin >> second_d;
    display_matrix(matrix); // Display Matrix
}

int take_just_input(string &&message)
{
    int value{};
    cout << message;
    cin >> value;
    return value;
}

void multiply_matrix(vector<vector<double>> &matrix, double &mul)
{
    for (auto &first_d : matrix)
        for (auto &second_d : first_d)
            second_d *= mul;
    display_matrix(matrix); // Display Matrix
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int rows{}, cols{};
    const int max_size = 2 * pow(10, 9);

    do
    {
        cout << "Matrix size must be greater than 0 \nAnd lesser than " << max_size << " row and column combine." << endl;
        rows = take_just_input("\tEnter number of rows: ");    // For Rows
        cols = take_just_input("\tEnter number of columns: "); // For Columns
    } while ((rows < 0 || cols < 0) || (rows + cols) > max_size);

    vector<vector<double>> matrix(rows, vector<double>(cols));

    take_matrix_input(matrix); // Take matrix input

    double mul_with{};
    mul_with = take_just_input("Now, enter the number you want to multiply with matrix: ");

    multiply_matrix(matrix, mul_with); // Multiply Matrix

    return a.exec();
}
