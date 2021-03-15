/*
TODO : Fix BUG
! ERORR !
*/
#include <iostream>
#include <climits>
using namespace std;
struct Node{
    string plate;
    Node* next;
    Node* prev;
};
struct Structure{
    Node* head = new Node;
    Node* tail = new Node;
    int limit = 10;
};
Structure queue;
Structure stack;
void initQueue(int limit = 10){
    queue.head = NULL;
    queue.tail = NULL;
    queue.limit = limit;
}
void initStack(int limit = 10){
    stack.head = NULL;
    stack.tail = NULL;
    stack.limit = limit;
}
bool isEmpty(Structure strc){
    return (strc.head == NULL)? true : false;
}
bool isFull(Structure strc){
    return (strc.limit == 0)? true : false;
}
void pushQueue(string str){
    Node* temp = new Node;
    temp->plate = str;
    temp->next = NULL;
    if(isEmpty(queue)){
        queue.head = temp;
        queue.tail = temp;
        queue.limit--;
    }else if(!isFull(queue)) {
        queue.tail->next = temp;
        queue.tail = temp;
        queue.limit--;
    } else {
        cout<<"Tempat parkir penuh"<<endl;
    }
}
void pushStack(Node* node){
    Node* prev = new Node;
    Node* temp = new Node;
    temp->plate = node->plate;
    temp->next = NULL;
    temp->prev = NULL;
    if(isEmpty(stack)){
        stack.head = temp;
        stack.tail = temp;
        stack.limit--;
    } else if(!isFull(stack)){
        prev = stack.tail;
        stack.tail->next = temp;
        stack.tail = temp;
        stack.tail->prev = prev;
        stack.limit--;
    } else {
        cout<<"Plat nomor mobil tidak ditemukan"<<endl;
    }
}
void popQueue(string str = "NULL"){
    Node* check = new Node;
    Node* pop = new Node;
    check = queue.head;
    if(isEmpty(queue)) {
        cout<<"Tempat parkir kosong"<<endl;
    } else if(str == "NULL"){
        cout<<"Mobil dengan plat nomor "<<queue.head->plate<<" telah dikeluarkan"<<endl;
        pop = check;
        check = check->next;
        queue.head = check;
        delete pop;
        queue.limit++;
    } else {
        while(check != NULL) {
            if(check->plate == str){
                cout<<"Mobil dengan plat nomor "<<str<<" telah keluar"<<endl;
                pop = check;
                check = check->next;
                queue.head = check;
                delete pop;
                queue.limit++;
                break;
            } else {
                pushStack(check);
                pop = check;
                check = check->next;
                queue.head = check;
                delete pop;
            }
        }
    }
}
void popStack(){
    Node* pop = new Node;
    if(isEmpty(stack)){
        cout<<"Stack is empty"<<endl;
    } else {
        while(!isEmpty(stack)){
            if(stack.tail != stack.head){
                stack.tail->next = queue.head;
                queue.head = stack.tail;
                stack.tail = stack.tail->prev;
                stack.tail->next = NULL;
                stack.limit++;
            } else {
                stack.tail->next = queue.head;
                queue.head = stack.tail;
                stack.limit++;
                stack.head = NULL;
                stack.tail = NULL;
            }
        }
    }
}
void printKeyStack(){
    if(isEmpty(stack)){
        cout<<"stack empty"<<endl;
    }else {
        cout<<"stack head value : "<<stack.head->plate<<endl;
        cout<<"stack tail value : "<<stack.tail->plate<<endl;
    }
    
}
void printKey(){
    cout<<"queue head value : "<<queue.head->plate<<endl;
    cout<<"queue tail value : "<<queue.tail->plate<<endl;
}
void printQueue(){
    Node* check = new Node;
    check = queue.head;
    if(isEmpty(queue)){
        cout<<"Tempat parkir kosong"<<endl;
    } else {
        while(check != NULL){
            cout<<"plate in parking lot : "<<check->plate<<endl;
            check = check->next;
        }
    }
}
int main(){
    initQueue(5); //default = 10
    initStack(5);
    while(true){
        int pilih;
        string plat;
        cout<<"1. Masukkan mobil\n2. Keluarkan mobil\n3. Keluarkan mobil berdasarkan nomor plat\n4. Tampilkan plat mobil\n5. Exit"<<endl;
        cout<<"Pilih : ";
        cin>>pilih;
        cin.ignore();
        switch(pilih){
            case 1:
                cout<<"Masukkan Plat Nomor Mobil : ";
                cin>>plat;
                pushQueue(plat);
                break;
            case 2:
                popQueue();
                break;
            case 3:
                cout<<"Masukkan Plat Nomor Mobil : ";
                cin>>plat;
                popQueue(plat);
                popStack();
                break;
            case 4:
                printQueue(); //change
                break;
            case 5:
                return false;
                break;
            default:
                cout<<"Input anda salah"<<endl;
                break;
        }
    }
}
