#include <iostream>
#include "list.h"
using namespace std;


int main(void) {
    elem* head = init_list(0); 
    for(int i=0; i<10; i++, insert_back(head, i)); 
    print_all(head);
    cout<<"Добавляем еще одну 5-ку после 4-ёх: \n"; 
    elem* fourth = find_elem(head, 4); 
    insert_after(fourth, 5);
    print_all(head);
    cout<<"Удаляем последний: \n";
    remove_back(head);
    print_all(head);
    cout<<"Удаляем 5-ый: \n";
    remove_elem(head, 5);
    print_all(head);
    cout<<"Удаляем 1-ый: \n";
    remove_elem(head, 1);
    print_all(head);
    cout<<"Удаляем все: \n";
    delete_all(head);
    //print_all(head);
    return 0; 
}
