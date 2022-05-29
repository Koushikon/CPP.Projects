#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Hello, world!\n";
    int num{};
    cin >> num;
    cout << num << endl;

    int arr[]{7, 8, 9, 10};
    cout << std::size(arr) << endl;
    return 0;
}