#include <fstream>

#include "TextList.h"
#include "TextNode.h"

// Конструктор по умолчанию
TextList::TextList() : head(nullptr), tail(nullptr) {
}

// Деструктор для освобождения памяти
TextList::~TextList() {
    TextNode* current = head; // Указатель на текущий узел

    while (current != nullptr) {
        TextNode* next = current->next; // Сохраняем указатель на следующий узел
        delete current; // Освобождаем память для текущего узла
        current = next; // Переходим к следующему узлу
    }

    head = nullptr; // Устанавливаем указатель на начало списка в nullptr
    tail = nullptr; // Устанавливаем указатель на конец списка в nullptr
}

TextList::TextList(const std::string& filename) {
    fstream input(filename, ios::in);
    if (!input.is_open()) {
        cout << "Не удалось открыть файл input.txt" << endl;
        throw std::runtime_error("Ошибка открытия файла");
    }

    while (!input.eof()) {
        char *buffer = new char[1024]; // Буфер для хранения считанной строки
        input >> buffer;
        appendNode(StringList(buffer));
    }
}

// Метод добавления узла в конец списка
void TextList::appendNode(const StringList& data) {
    auto* newNode = new TextNode(data); // Создание нового узла
    if (head == nullptr) { // Если список пуст
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Оператор вывода узла в поток
std::ostream& operator<<(std::ostream& os, const TextList& list) {
    TextNode* current = list.head;

    os << "HEAD" << endl;
    os << " | " << endl;
    os << "\\|/" << endl;

    while (current) {
        os << current->data << endl;
        os << " | " << endl;
        os << "\\|/" << endl;
        current = current->next;
    }
    os << "NULL" << endl;

    return os;
}
