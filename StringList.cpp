#include "StringList.h"
#include "StringNode.h"

// Конструктор по умолчанию
StringList::StringList() : head(nullptr), tail(nullptr) {
}
void StringList::fill(char part[]) {
    for (int i = 0; i < StringNode::PART_SIZE; ++i) {
        part[i] = '\0';
    }
}

StringList::StringList(const char (*buffer)) {
    char part[StringNode::PART_SIZE];
    fill(part); // Используем функцию fill() для заполнения нулями

    int index = 0;
    while (buffer[index] != '\0') {
        part[index % StringNode::PART_SIZE] = buffer[index];
        index++;
        if (index % StringNode::PART_SIZE == 0) {
            appendNode(part);
            fill(part); // Используем функцию fill() для сброса массива part в нули
        }
    }
    if (index % StringNode::PART_SIZE != 0) {
        appendNode(part);
        fill(part); // Используем функцию fill() для сброса массива part в нули
    }
}

// Конструктор копирования
StringList::StringList(const StringList& other) : head(nullptr), tail(nullptr) {
    // Если список other пуст, просто выходим из конструктора
    if (other.head == nullptr) return;

    // Копируем данные из списка other
    StringNode* current = other.head;
    while (current) {
        appendNode(current->data);
        current = current->next;
    }
}


// Деструктор для освобождения памяти
StringList::~StringList() {
    StringNode* current = head; // Указатель на текущий узел

    while (current != nullptr) {
        StringNode* next = current->next; // Сохраняем указатель на следующий узел
        delete current; // Освобождаем память для текущего узла
        current = next; // Переходим к следующему узлу
    }

    head = nullptr; // Устанавливаем указатель на начало списка в nullptr
    tail = nullptr; // Устанавливаем указатель на конец списка в nullptr
}

// Добавление узла в конец списка
void StringList::appendNode(const char (*value)) {
    // Создаем новый узел с заданным значением
    auto* newNode = new StringNode(value);

    // Если список пуст, устанавливаем новый узел как начало и конец списка
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Добавляем новый узел в конец списка и обновляем указатель на хвост
        tail->next = newNode;
        tail = newNode;
    }
}

// Определение оператора <
bool operator<(const StringList& lhs, const StringList& rhs) {
    StringNode* leftNode = lhs.head; // Указатель на текущий узел списка lhs
    StringNode* rightNode = rhs.head; // Указатель на текущий узел списка rhs

    // Перебираем узлы обоих списков и сравниваем содержимое их узлов
    while (leftNode != nullptr && rightNode != nullptr) {
        // Если содержимое узлов отличается, списки не равны
        if (*leftNode == *rightNode) {
            leftNode = leftNode->next; // Переходим к следующему узлу списка lhs
            rightNode = rightNode->next; // Переходим к следующему узлу списка rhs
        } else return *leftNode < *rightNode;
    }
    return (leftNode == nullptr && rightNode != nullptr);
}

// Оператор сравнения равенства списка узлов
bool operator==(const StringList &lhs, const StringList &rhs) {
    StringNode *leftNode = lhs.head; // Указатель на текущий узел списка lhs
    StringNode *rightNode = rhs.head; // Указатель на текущий узел списка rhs

    // Перебираем узлы обоих списков и сравниваем содержимое их узлов
    while (leftNode != nullptr && rightNode != nullptr) {
        // Если содержимое узлов отличается, списки не равны
        if (!(*leftNode == *rightNode)) return false;

        leftNode = leftNode->next; // Переходим к следующему узлу списка lhs
        rightNode = rightNode->next; // Переходим к следующему узлу списка rhs
    }

    // Если один список закончился раньше другого, они не равны
    if (leftNode != nullptr || rightNode != nullptr) return false;

    // Все узлы совпадают, списки равны
    return true;
}

// Оператор вывода узла в поток
std::ostream& operator<<(std::ostream& os, const StringList& list) {
    StringNode* current = list.head;
    while (current != nullptr) {
        os << current->data << " -> ";
        current = current->next;
    }
    os << "NULL";
    return os;
}

