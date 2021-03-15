/*
* DETAILS : 
* 1. Queue max 10
* 2. Plat nomor = string
* 3. Delete queue by plat nomor (search plat nomor then delete it)
* 4. 2 linked list
TODO : Return data from stack to queue
? jumlah mobil sudah diketahui atau jumlah mobil dihitung setiap saat ada mobil baru yang akan masuk
! jumlah mobil sudah diketahui
*/

#include <iostream>
using namespace std;
struct Node{
    string plate;
    Node* next;
};
struct Structure{
    Node* head = new Node;
    Node* tail = new Node;
    int limit = 1;
};
Structure queue;
Structure stack;
void initQueue(){
    queue.head = NULL;
    queue.tail = NULL;
}
void initStack(){
    stack.head = NULL;
    stack.tail = NULL;
}
bool isEmpty(Structure strc){
    return (strc.head == NULL)? true : false;
}
void pushQueue(string str){
    Node* temp = new Node;
    Node* check = new Node;
    temp->plate = str;
    temp->next = NULL;
    if(isEmpty(queue)){
        queue.head = temp;
        queue.tail = temp;
        queue.limit++;
    }else if(queue.limit <= 10) {
        check = queue.head;
        while(check->next != NULL){
            check = check->next;
        }
        check->next = temp;
        queue.tail = check->next;
        queue.limit++;
    } else {
        cout<<"Tempat parkir penuh"<<endl;
    }
}
void pushStack(Node* node){
    Node* check = new Node;
    Node* temp = new Node;
    temp->plate = node->plate;
    temp->next = NULL;
    if(isEmpty(stack)){
        stack.head = temp;
        stack.limit++;
    } else if(stack.limit != 10){
        check = stack.head;
        while(check->next != NULL){
            check = check->next;
        }
        check->next = temp;
        stack.tail = check->next;
        stack.limit++;
    } else {
        cout<<"Plat nomor mobil tidak ditemukan"<<endl;
    }
}
void popQueue(string str){
    Node* check = new Node;
    Node* pop = new Node;
    check = queue.head;
    while(check->next != NULL){
        if(check->plate == str){
            cout<<"Mobil dengan plat nomor "<<str<<" telah keluar"<<endl;
            pop = check;
            check = check->next;
            queue.head = check;
            delete pop;
            break;
        }
        pushStack(check);
        pop = check;
        check = check->next;
        queue.head = check;
        delete pop;
    }
}
void popStack(){
    //* pop stack and insert to queue
    //TODO: code here
}
void printKeyStack(){
    cout<<"stack head value : "<<stack.head->plate<<endl;
    cout<<"stack tail value : "<<stack.tail->plate<<endl;
}
void printKey(){
    cout<<"queue head value : "<<queue.head->plate<<endl;
    cout<<"queue tail value : "<<queue.tail->plate<<endl;
}
int main(){
    initQueue();
    initStack();
    for(int i=1;i != 15;i++){
        pushQueue(to_string(i));
    }
    popQueue("8");
    printKeyStack();
    printKey();
}
