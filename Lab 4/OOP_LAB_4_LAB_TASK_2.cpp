
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
void printList(const list<int>& lst) {
    for (int n : lst) cout << n << " ";
    cout <<endl;
}
bool ListSort(int a, int b) {
    return a < b;
}
int main() {
    list<int> myList1 = {5, 4, 3, 1, 2};
    list<int> myList2 = {10, 9, 8, 6, 7};
    myList1.sort(ListSort); // Sorting the list 1 using the custom ListSort function
    myList2.sort(ListSort); // Sorting the list 2 using the custom ListSort function
    cout<<"\nSorted List 1 (not merged yet):"<<endl;
    printList(myList1);
    cout<<"\nSorted List 2 (not merged yet):"<<endl;
    printList(myList2);
    cout<<"\nSorted and Merged both lists:"<<endl;
    myList1.merge(myList2); // Merge myList2 into myList1
    printList(myList1);
}
