#ifndef STRING_NODE_H
#define STRING_NODE_H

#include <iostream> // Для использования std::ostream

// Определение класса для узла списка
struct StringNode {
    static const int PART_SIZE = 5;

    char data[PART_SIZE]{}; // Строка из 5 символов
    StringNode *next; // Указатель на следующий узел

    // Конструктор для инициализации узла с заданной строкой и указателем на следующий узел
    explicit StringNode(const char (*value));

    // Деструктор для освобождения ресурсов
    ~StringNode();

    // Оператор для сравнения StringNode
    friend bool operator<(const StringNode &lhs, const StringNode &rhs);

    // Оператор сравнения равенства StringNode
    friend bool operator==(const StringNode &lhs, const StringNode &rhs);

    // Вывод узла в поток
    friend std::ostream &operator<<(std::ostream &os, const StringNode &node);
};

#endif // STRING_NODE_H
