#include <iostream>

int* memory_allocation(int n) {
    return new int[n];
}

void read(int* arr, int n) {
    for (int i{}; i < n; ++i) {
        std::cin >> arr[i];
    }
}

void print(int* arr, int n) {
    for (int i{}; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void clear(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

// Задача 7
void local_max(int* arr, int n) {
    for (int i{1}; i < n - 1; ++i) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << '\n';
}

// Задача 8
bool check_signs(int* arr, int n) {
    for (int i{1}; i < n; ++i) {
        if (arr[i] * arr[i - 1] > 0) {
            return false;
        }
    }
    return true;
}

// Задача 9
int max_series(int* arr, int n) {
    int current{1};
    int best{1};
    for (int i{1}; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            ++current;
        } else {
            current = 1;
        }
        if (current > best) {
            best = current;
        }
    }
    return best;
}

int main() {
    int n{};

    // task 7
    std::cout << "task 7:\n";

    std::cin >> n;
    int* arr7 = memory_allocation(n);
    read(arr7, n);

    local_max(arr7, n);

    clear(arr7);

    // task 8
    std::cout << "task 8:\n";

    std::cin >> n;
    int* arr8 = memory_allocation(n);
    read(arr8, n);

    if (check_signs(arr8, n)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    clear(arr8);

    // task 9
    std::cout << "task 9:\n";

    std::cin >> n;
    int* arr9 = memory_allocation(n);
    read(arr9, n);

    std::cout << max_series(arr9, n) << '\n';

    clear(arr9);

    return 0;
}
