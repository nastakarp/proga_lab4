#ifndef STRING_LIST_H
#define STRING_LIST_H

#include "StringNode.h"

using namespace std;

// Определение класса для списка узлов
struct StringList {
    StringNode* head{}; // Указатель на начало списка
    StringNode* tail{}; // Указатель на конец списка
    // Конструктор по умолчанию
    StringList();
    void fill(char part[]);
    StringList(const StringList& other);

    explicit StringList(const char (*buffer));

    // Деструктор для освобождения памяти
    ~StringList();

    // Добавление узла в конец списка
    void appendNode(const char (*value));

    // Оператор для сравнения StringNode
    friend bool operator<(const StringList& lhs, const StringList& rhs);

    // Оператор сравнения равенства StringNode
    friend bool operator==(const StringList& lhs, const StringList& rhs);

    // Вывод StringList в поток
    friend std::ostream& operator<<(std::ostream& os, const StringList& node);
};

#endif // STRING_LIST_H
