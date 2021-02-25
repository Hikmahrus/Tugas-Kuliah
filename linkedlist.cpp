#include<iostream>
#include<climits>
using namespace std;
struct Node{
    long int nim;
    string nama;
    string jurusan;
    Node* next;
};
Node* head = new Node;
void init(){
    head = NULL;
}
bool isEmpty(){
    return (head == NULL) ? true : false;
}
void autoPush(unsigned long int nim,string nama,string jurusan){
    Node* temp = new Node;
    Node* next = new Node;
    Node* prev = new Node;
    temp->nim = nim;
    temp->nama = nama;
    temp->jurusan = jurusan;
    if(isEmpty()){
        head = temp;
        head->next = NULL;
    } else if(head->nim > temp->nim){
        temp->next = head;
        head = temp;
    } else {
        next = head;
        while(next != NULL && temp->nim > next->nim){
            prev = next;
            next = next->next;
        }
        if(next == NULL){
            prev->next = temp;
        } else if(temp->nim != next->nim){
            prev->next = temp;
            temp->next = next;
        } else {
            cout<<"NIM sudah ada"<<endl;
        }
    }
}
void print(){
    if(isEmpty()){
        cout<<"Data Kosong"<<endl;
    } else {
        Node* temp = new Node;
        temp = head;
        while(temp->next != NULL){
            cout<<" | NIM : "<<temp->nim<<" | Nama : "<<temp->nama<<" | Jurusan : "<<temp->jurusan<<endl;
            temp = temp->next;
        }
        cout<<" | NIM : "<<temp->nim<<" | Nama : "<<temp->nama<<" | Jurusan : "<<temp->jurusan<<endl;
    }
}
void deleteNIM(long int nim){
    Node* prev = new Node;
    Node* next = new Node;
    next = head;
    if(isEmpty()){
        cout<<"Data kosong"<<endl;
    } else if(head->nim == nim){
        head = head->next;
    } else {
        while(next->next != NULL && nim != next->nim){
            prev = next;
            next = next->next;
        }
        if(nim == next->nim){
            prev->next = next->next;
            delete next;
        } else {
            cout<<"NIM tidak ada"<<endl;
        }
    }
}
int main(){
    init();
    while(true){
        int pilih;
        long int nim;
        string nama,jurusan;
        cout<<"1. Input data mahasiswa\n2. Hapus data mahasiswa by NIM\n3. Cetak semua data mahasiswa\n4. Exit"<<endl;
        cout<<"Pilih : ";
        cin>>pilih;
        cin.ignore();
        switch(pilih){
            case 1:
                cout<<"Masukkan NIM mahasiswa : ";
                cin>>nim;
                if(cin.fail()){
                    cout<<"Input anda salah"<<endl;
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                } else {
                    cin.ignore();
                    cout<<"Masukkan nama mahasiswa : ";
                    getline(cin,nama);
                    cout<<"Masukkan jurusan mahasiswa : ";
                    getline(cin,jurusan);
                    autoPush(nim,nama,jurusan);
                }            
                break;
            case 2:
                cout<<"Masukkan NIM mahasiswa yang akan dihapus : ";
                cin>>nim;
                if(cin.fail()){
                    cout<<"Input anda salah"<<endl;
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                } else {
                    deleteNIM(nim);
                }
                break;
            case 3:
                print();
                break;
            case 4:
                return false;
                break;
            default:
                cout<<"Input anda salah"<<endl;
                break;
        }
    }
}