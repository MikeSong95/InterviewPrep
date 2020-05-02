#include <iostream>
#include <vector>

using namespace std;

void v(int *arr) {
    int temp = arr[0];
    int temp2 = arr[2];
    arr[0] = arr[1];
    arr[1] = temp;
    arr[2] = arr[3];
    arr[3] = temp2;
}

void h(int *arr) {
    int temp = arr[0];
    int temp2 = arr[1];
    arr[0] = arr[2];
    arr[2] = temp;
    arr[1] = arr[3];
    arr[3] = temp2;
}

int main(void) {
    string s;
    int a[] = {1,2,3,4};

    cin >> s;
    
    for (auto c : s) {
        if (c == 'V') {
            v(a);
        } else {
            h(a);   
        }
    }

    cout << a[0] << " " << a[1] << endl << a[2] << " " << a[3] << endl;
}