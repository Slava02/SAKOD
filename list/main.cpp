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
    return 0; 
}