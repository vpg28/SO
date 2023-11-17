#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoubleLinkedlist{
    private:
        Node *head, *tail;

    public:
        DoubleLinkedlist(){
            head = nullptr;
            tail = nullptr;
        }

        bool isEmpty(){
            return head == nullptr;
        }

        void insert(int databaru){
            Node* baru = new Node(databaru);
            if (isEmpty())
            {
                head = baru;
                tail = baru;
            } else {
                tail->next = baru;
                baru->prev = tail;
                tail = baru;
            }
        }

        void show(){
            Node* bantu = head;
            if (!isEmpty())
            {
                while (bantu != nullptr)
                {
                    cout << bantu->data << "<->";
                    bantu = bantu->next;
                }
            } else {
                cout << "masih kosong";
            }
        }

        int hapusBelakang(){
            int val;
            if (!isEmpty())
            {
                Node *bantu = tail;
                val = bantu->data;
                tail = tail->prev;
                if (tail != nullptr){
                    tail->next = nullptr;
                } else {
                    head = nullptr;
                }                    
            } else {
                cout << "masih kosong";
            }
            return val;
        }

        void balik(int size) {
            int i = 0;
            int arr[size];

            while (i < size) {
                int temp = hapusBelakang();
                arr[i] = temp;
                i++;
            }

            for (int i = 0; i < size; i++)
            {
                insert(arr[i]);
            }
        }
};

int main() {
    DoubleLinkedlist DLL;
    DLL.insert(1);
    DLL.insert(3);
    DLL.insert(4);
    DLL.insert(7);
    DLL.show();
    cout << endl;

    DLL.balik(4);
    DLL.show();
    cout << endl;

    DLL.balik(4);
    DLL.show();
    cout << endl;

    return 0;
}