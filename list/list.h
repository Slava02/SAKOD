#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct elem {
    int data; 
    elem* p_next;
    elem* p_previous;  
    elem(int d);
};
//  ИНИЦИАЛИЗАЦИЯ СПИСКА

elem* init_list(int new_data); 

//  ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ

void insert_front(elem* head, int new_data); 
void insert_back(elem* head, int new_data);
void insert_after(elem* prev_elem, int new_data);

//  УДАЛЕНИЕ ЭЛЕМЕНТОВ

void remove_front(elem* head);
void remove_back(elem* head);
void remove_elem(elem* head, int index);
void delete_all(elem* head);

//  ВЫВОД НА ЭКРАН

void print_all(elem* head);
void print_elem(elem* p_elem);

//  ВСПОМОГАТЛЬНЫЕ ФУНКЦИИ

elem* find_last(elem* head);
void fill_list(elem* head);
elem* find_elem(elem* head, int index);

#endif //  LIST_H       