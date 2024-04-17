#ifndef TEXT_LIST_H
#define TEXT_LIST_H

#include "TextNode.h"
#include "TextList.h"

using namespace std;

// Определение класса для списка узлов
struct TextList {
    TextNode* head{}; // Указатель на начало списка
    TextNode* tail{}; // Указатель на конец списка

    // Конструктор по умолчанию
    TextList();

    explicit TextList(const std::string& filename);

    // Деструктор для освобождения памяти
    ~TextList();

    // Добавление узла в конец списка
    void appendNode(const StringList& data);

    // Вывод StringList в поток
    friend std::ostream& operator<<(std::ostream& os, const TextList& node);
};

#endif // TEXT_LIST_H
