#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<int> elements;

public:

    Vector(std::vector<int> elems) : elements(elems) {}

    Vector add(const Vector& other) {
        std::vector<int> result;
        for (size_t i = 0; i < elements.size(); i++) {
            result.push_back(elements[i] + other.elements[i]);
        }
        return Vector(result);
    }

    Vector subtract(const Vector& other) {
        std::vector<int> result;
        for (size_t i = 0; i < elements.size(); i++) {
            result.push_back(elements[i] - other.elements[i]);
        }
        return Vector(result);
    }

    int dotProduct(const Vector& other) {
        int result = 0;
        for (size_t i = 0; i < elements.size(); i++) {
            result += elements[i] * other.elements[i];
        }
        return result;
    }

    void print() {
        std::cout << "(";
        for (size_t i = 0; i < elements.size(); i++) {
            std::cout << elements[i];
            if (i != elements.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    std::vector<int> v1 = { 1, 2, 3 };
    std::vector<int> v2 = { 4, 5, 6 };

    Vector vector1(v1);
    Vector vector2(v2);

    Vector sum = vector1.add(vector2);
    Vector diff = vector1.subtract(vector2);
    int dot = vector1.dotProduct(vector2);

    std::cout << "Сумма векторов: ";
    sum.print();
    std::cout << "Разность векторов: ";
    diff.print();
    std::cout << "Скалярное произведение: " << dot << std::endl;

    return 0;
}
