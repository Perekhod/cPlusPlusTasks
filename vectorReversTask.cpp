#include <iostream>
#include <vector>
#include <algorithm>

void ShowVector(const std::vector<int>& vector);

std::vector<int> reverseVector(const std::vector<int>& vec);
std::vector<int> reverseVectorFor(const std::vector<int>& vec);

int main() {
    std::vector<int> vector = { 1, 2, 3, 4, 5 };
    ShowVector(vector);

    std::cout << std::endl;

    std::vector<int> reversVecor = reverseVector(vector);
    ShowVector(reversVecor);

    std::cout << std::endl;

    std::vector<int> reversVecorFor = reverseVectorFor(reversVecor);
    ShowVector(reversVecorFor);

    return 0;
}

void ShowVector(const std::vector<int>& vector) {
    for (int element : vector) {
        std::cout << element << " ";
    }
}

std::vector<int> reverseVector(const std::vector<int>& vec) {
    std::vector<int> reversed = vec;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

std::vector<int> reverseVectorFor(const std::vector<int>& vec) {
    std::vector<int> temp;

    for (auto i = vec.end() -1; ; --i) {
        temp.push_back(*i);

        if (i == vec.begin()) {
            break;
        }
    }
        return temp;
}
