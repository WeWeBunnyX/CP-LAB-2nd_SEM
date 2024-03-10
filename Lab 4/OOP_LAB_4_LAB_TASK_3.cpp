
#include <list>
#include <iostream>
using namespace std;
class Spreadsheet {
private:
    list<list<int>> matrix;
public:
    Spreadsheet(const list<list<int>>& m) : matrix(m) {}
    void printSpreadsheet() {
        for (const auto& row : matrix) {
            for (int val : row) cout << val << " ";
            cout << endl;
        }
    }
    void addRow(list<int> newRow) {
        matrix.push_back(newRow);
    }
    void deleteRow(int rowIndex) {
        auto it = matrix.begin();
        advance(it, rowIndex);
        if (it != matrix.end()) {
            matrix.erase(it);
        }
    }
};
int main() {
    Spreadsheet sheet({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });
    cout << "Original Matrix:" << endl;
    sheet.printSpreadsheet();
    sheet.addRow({10, 11, 12});
    cout << "\nMatrix after adding a row:" << endl;
    sheet.printSpreadsheet();
    sheet.deleteRow(0);
    cout << "\nMatrix after deleting a row:" << endl;
    sheet.printSpreadsheet();
    return 0;
}
