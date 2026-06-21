/*
    Project       : Sorting Algorithm Visualizer
    Language      : C++
    Author        : Avinash Kumar
    Description   : A console-based Sorting Algorithm Visualizer that
                     demonstrates Bubble Sort, Selection Sort, Insertion Sort,
                     and Quick Sort step-by-step using bar representation
                     made of asterisks (*) printed in the terminal.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

class SortingVisualizer {
private:
    vector<int> arr;
    int delayMs;

    void printArray(int highlight1 = -1, int highlight2 = -1) {
        system("clear || cls");
        cout << "\n===== SORTING ALGORITHM VISUALIZER =====\n\n";
        for (int i = 0; i < (int)arr.size(); i++) {
            if (i == highlight1 || i == highlight2)
                cout << setw(3) << arr[i] << " | " << string(arr[i], '#') << "\n";
            else
                cout << setw(3) << arr[i] << " | " << string(arr[i], '*') << "\n";
        }
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }

public:
    SortingVisualizer(int size = 10, int delay = 300) {
        delayMs = delay;
        srand((unsigned)time(0));
        for (int i = 0; i < size; i++)
            arr.push_back(rand() % 40 + 1);
    }

    void showArray() {
        cout << "\nCurrent Array: ";
        for (int x : arr) cout << x << " ";
        cout << "\n";
    }

    void bubbleSort() {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                printArray(j, j + 1);
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
        printArray();
        cout << "\nBubble Sort Complete!\n";
    }

    void selectionSort() {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                printArray(minIdx, j);
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
        printArray();
        cout << "\nSelection Sort Complete!\n";
    }

    void insertionSort() {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                printArray(j, j + 1);
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        printArray();
        cout << "\nInsertion Sort Complete!\n";
    }

    int partition(int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            printArray(j, high);
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSortHelper(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSortHelper(low, pi - 1);
            quickSortHelper(pi + 1, high);
        }
    }

    void quickSort() {
        quickSortHelper(0, arr.size() - 1);
        printArray();
        cout << "\nQuick Sort Complete!\n";
    }

    void resetArray(int size) {
        arr.clear();
        for (int i = 0; i < size; i++)
            arr.push_back(rand() % 40 + 1);
    }
};

void showMenu() {
    cout << "\n========= SORTING ALGORITHM VISUALIZER =========\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Generate New Random Array\n";
    cout << "6. Exit\n";
    cout << "==================================================\n";
    cout << "Enter your choice: ";
}

int main() {
    int size, choice;
    cout << "Welcome to the Sorting Algorithm Visualizer (CITS2826)\n";
    cout << "Enter number of elements to visualize (e.g. 10-20): ";
    cin >> size;

    SortingVisualizer visualizer(size);

    do {
        visualizer.showArray();
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: visualizer.bubbleSort(); break;
            case 2: visualizer.selectionSort(); break;
            case 3: visualizer.insertionSort(); break;
            case 4: visualizer.quickSort(); break;
            case 5:
                visualizer.resetArray(size);
                cout << "\nNew array generated!\n";
                break;
            case 6: cout << "\nExiting... Thank you!\n"; break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
