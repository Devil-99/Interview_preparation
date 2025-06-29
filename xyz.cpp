#include <iostream>
#include <vector>
#include <thread>     // for sleep
#include <chrono>     // for duration

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

void printArrayBars(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << ": ";
        for (int i = 0; i < val; ++i)
            std::cout << "*";
        std::cout << "\n";
    }
    std::cout << "------------------\n";
}

void visualizeBubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);

                system(CLEAR);  // Clear console (platform dependent)
                printArrayBars(arr);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pause for 500ms
            }
        }
    }
}

int main() {
    std::vector<int> arr = {5, 3, 8, 4, 1};
    std::cout << "Initial Array:\n";
    printArrayBars(arr);

    std::cout << "Sorting...\n";
    visualizeBubbleSort(arr);

    std::cout << "Sorted Array:\n";
    printArrayBars(arr);

    return 0;
}
