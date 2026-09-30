#include <iostream>

int* memory_allocation(int n) {
    return new int[n];
}

void read(int* arr, int n) {
    for (int i{}; i < n; ++i) {
        std::cin >> arr[i];
    }
}

void clear(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

// Задача 7
void local_max(int* arr, int n) {
    for (int i{1}; i + 1 < n; ++i) {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            std::cout << arr[i] << ' ';
        }
    }
    std::cout << '\n';
}

// Задача 8
bool check_signs(int* arr, int n) {
    bool ok{true};
    for (int i{1}; i < n; ++i) {
        if (arr[i] * arr[i - 1] > 0) {
            ok = false;
        }
    }
    return ok;
}

// Задача 9
int max_series(int* arr, int n) {
    int len{1};
    int mx{1};
    for (int i{1}; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            ++len;
        } else {
            len = 1;
        }
        if (len > mx) {
            mx = len;
        }
    }
    return mx;
}

int main() {
    int n{};

    // task 7
    std::cout << "task 7:\n";
    std::cin >> n;
    int* arr1 = memory_allocation(n);
    read(arr1, n);
    local_max(arr1, n);
    clear(arr1);

    // task 8
    std::cout << "task 8:\n";
    std::cin >> n;
    int* arr2 = memory_allocation(n);
    read(arr2, n);
    if (check_signs(arr2, n)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    clear(arr2);

    // task 9
    std::cout << "task 9:\n";
    std::cin >> n;
    int* arr3 = memory_allocation(n);
    read(arr3, n);
    std::cout << max_series(arr3, n) << '\n';
    clear(arr3);

    return 0;
}
