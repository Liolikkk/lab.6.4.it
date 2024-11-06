#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void Init(double* b, const int n) {
    for (int i = 0; i < n; i++)
        b[i] = -10 + rand() % 21; 
}

void Print(const double* const b, const int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(0) << b[i] << " ";
    }
    cout << "}" << endl;
}

//рівних нулю
int CountZeros(const double* const b, const int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            count++;
        }
    }
    return count;
}

//після мінімального елемента
double SumAfterMin(const double* const b, const int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (b[i] < b[minIndex]) {
            minIndex = i;
        }
    }
    double sum = 0;
    for (int i = minIndex + 1; i < n; i++) {
        sum += b[i];
    }
    return sum;
}

// за зростанням 
void SortOddIndexedElements(double* b, const int n) {
    vector<double> oddElements;
    for (int i = 1; i < n; i += 2) { // непарні
        oddElements.push_back(b[i]);
    }

    sort(oddElements.begin(), oddElements.end(), [](double a, double b) {
        return abs(a) < abs(b);
        });

    int j = 0;
    for (int i = 1; i < n; i += 2) { // Повертаємо непарні 
        b[i] = oddElements[j++];
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter the size of the array n = "; cin >> n;
    double* arr = new double[n];
    Init(arr, n);

    cout << "Initial array:" << endl;
    Print(arr, n);

  
    cout << "Number of zero elements: " << CountZeros(arr, n) << endl;

   
    cout << "Sum of elements after minimum element: " << SumAfterMin(arr, n) << endl;

  
    SortOddIndexedElements(arr, n);
    cout << "Array after sorting odd indexed elements by modulus:" << endl;
    Print(arr, n);

    delete[] arr;
    arr = nullptr;
    return 0;
}
