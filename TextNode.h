#ifndef TEXT_NODE_H
#define TEXT_NODE_H

#include "StringList.h"

#include <iostream> // Для использования std::ostream

// Определение класса для узла списка
struct TextNode {
    StringList data; // Указатель на StringList
    TextNode* next; // Указатель на следующий узел

    // Конструктор с параметрами
    explicit TextNode(const StringList& list);

    // Деструктор для освобождения ресурсов
    ~TextNode();

    // Вывод узла в поток
    friend std::ostream& operator<<(std::ostream& os, const TextNode& node);
};

#endif // TEXT_NODE_H