#include "StringNode.h"

using namespace std;

// Конструктор
StringNode::StringNode(const char (*value)) : next(nullptr) {
    // Копируем строку value в поле data, обрезая ее до 5 символов
    for (int i = 0; i < PART_SIZE; ++i) data[i] = value[i];
}

// Деструктор
StringNode::~StringNode() = default;

// Оператор сравнения равенства StringNode
bool operator==(const StringNode &lhs, const StringNode &rhs) {
    // Сравниваем содержимое строк узлов
    for (int i = 0; i < StringNode::PART_SIZE; ++i)
        if (lhs.data[i] != rhs.data[i])
            return false;
    return true;
}

// Определение оператора <
bool operator<(const StringNode &lhs, const StringNode &rhs) {
    for (int i = 0; i < StringNode::PART_SIZE; ++i) {
        if (lhs.data[i] != rhs.data[i]) {
            if (rhs.data[i] == '\0') return false;
            return lhs.data[i] < rhs.data[i];
        }
    }
    return false;
}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const StringNode &node) {
    os << node.data;
    return os;
}
