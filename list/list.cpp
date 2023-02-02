#include "list.h"

#define PREV(x) x->p_previous
#define NEXT(x) x->p_next

//  МЕТОДЫ

elem::elem(int d) : data{d}, p_next{nullptr}, p_previous{nullptr} {}
elem::~elem() { if(p_next) delete p_next; if(p_previous) delete p_previous;}

//  ИНИЦИАЛИЗАЦИЯ СПИСКА

elem* init_list(int new_data) { 
    elem* head = new elem(new_data); // TODO подумать как обрабатывать нормально случай, если не выделилась память
    return head; 
}

// ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ

void insert_front(elem* head, int new_data) {
    if (head) { // TODO Обработать случай, когда это не так
        elem *new_elem = new elem(new_data);
        if(new_elem) { // TODO Обработать случай, когда это не так
            new_elem->p_next = head->p_next; 
            head->p_next = new_elem; 
        }
    }
}

void insert_back(elem* head, int new_data) {
    if (head) { // TODO Обработать случай, когда это не так
        elem *new_elem = new elem(new_data);
        if(new_elem) { // TODO Обработать случай, когда это не так
            new_elem->p_next = nullptr;
            elem* last = find_last(head);
            last->p_next = new_elem;  
        }
    }
}

void insert_after(elem* prev_elem, int new_data) {
    if(prev_elem) { //  TODO обработать если не так
        elem *new_elem = new elem(new_data);
        if(new_elem) { // TODO Обработать случай, когда это не так
            new_elem->p_next = prev_elem->p_next;
            prev_elem->p_next = new_elem; 
        } 
    }
}

//  УДАЛЕНИЕ ЭЛЕМЕНТОВ
/*
void remove_back(elem* head) {
    elem* last = find_last(head);

}
*/
// ВЫВОД НА ЭКРАН

void print_all(elem* head) {
    elem* tmp = head; 
    while(tmp->p_next) { 
        tmp = tmp->p_next;
        cout << tmp->data << "---"; 
    }
    cout << '\n';
}

//  ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ

elem* find_last(elem* head) {
    elem* last = head; 
    while(last->p_next) { 
        last = last->p_next;
    }
    return last; 
}

void fill_list(elem* head) {
    elem* tmp = head;
    int i = 0;  
    while(tmp->p_next) { 
        tmp = tmp->p_next;
        tmp->data = i++;  
    }
}

elem* find_elem(elem* head, int index) {
    elem* res = head;
    for(int i = 0; i < index; i++) {
        if(res->p_next) {
            res = res->p_next; 
        } else {
            res = nullptr; 
        }
    }
    return res; 
}