#include "TextNode.h"

using namespace std;

// Конструктор с параметрами
TextNode::TextNode(const StringList& list) : data(list), next(nullptr) {}

// Деструктор для освобождения ресурсов
TextNode::~TextNode() = default;

// Оператор вывода узла в поток
std::ostream& operator<<(std::ostream& os, const TextNode& node) {
    os << node.data;
    return os;
}
