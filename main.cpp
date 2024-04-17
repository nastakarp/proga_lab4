#include <iostream>
#include <fstream>

#include "TextList.h"

using namespace std;

bool process(const TextList& list1, const TextList& list2, const TextList& list3, fstream& output){
    TextNode* current1 = list1.head;
    TextNode* current2 = list2.head;
    TextNode* current3 = list3.head;
    output<<"контрольный вывод симметрической разности\n";
    while (current1 != nullptr && current2 != nullptr && current3 != nullptr) {
        if(current1->data == current2->data){
            current1= current1->next;
            current2= current2->next;
        }else if (current1->data < current2->data){
            output<<*current1<<endl;
            if(current1->data == current3->data){current3 = current3->next;}
            current1=current1->next;
        }else {
            output<<*current2<<endl;
            if(current2->data == current3->data){current3 = current3->next;}
            current2=current2->next;
        }
    }
    while(current1 != nullptr && current3!= nullptr){
        output<<*current1<<endl;
        if(current1->data == current3->data){current3 = current3->next;}
        current1=current1->next;
    }
    while(current2 != nullptr && current3!= nullptr){
        output<<*current2<<endl;
        if(current2->data == current3->data){current3 = current3->next;}
        current2=current2->next;
    }
    output<<"\nРЕЗУЛЬТАТ\n";
    return current3 == nullptr;
}
int main() {
    fstream logout;
    fstream output;
    logout.open("LOG.txt", ios::out);
    output.open("output.txt", ios::out);
    output<<"Карпенко Анастасия группа 3353\n";

    TextList list1("input_l1.txt");
    logout<<list1<<endl;

    TextList list2("input_l2.txt");
    logout<<list2<<endl;

    TextList list3("input_l3.txt");
    logout<<list3<<endl;

    output<<process(list1, list2, list3, output);
    return 0;
}
