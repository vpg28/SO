#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class linkedList {
    private :
        Node *head, *tail;
    public :
        linkedList() {
            head = nullptr;
            tail = nullptr;
        }
    
        bool isEmpty() {
            return head == nullptr;
        }

        void insertDepan(int dataBaru) {
            Node* baru = new Node;
            baru->data = dataBaru;

            if (isEmpty())
            {
                head = tail = baru;
            }
            else
            {
                baru->next = head;
                head = baru;
            }
            cout << "Data Successful Entry" << endl;
        }

        void insert(int dataBaru) {
            Node* baru = new Node;
            baru->data = dataBaru;
            baru->next = nullptr;

            if (isEmpty())
            {
                head = baru;
                tail = baru;
            }
            else
            {
                tail->next = baru;
                tail = baru;
            }
            cout << "Data Successful Entry" << endl;
        }

        void show() {
            Node* bantu = head;
            
            if (!isEmpty())
            {
                while (bantu != nullptr)
                {
                    cout << bantu->data << "->";
                    bantu = bantu->next;
                }
                cout << endl;
            }
            else
            {
                cout << "Masih Kosong" << endl;
            }
        }

        void hapusDepan() {
            if (!isEmpty())
            {
                Node *hapus = head;
                head = head->next;
                delete hapus;
            }
            else {
                cout << "Masih Kosong" << endl;
            }
        }

        int hapusBelakang() {
            if (!isEmpty())
            {
                Node *bantu = head;
                if (head != tail)
                {
                    while (bantu->next != tail)
                    {
                        bantu = bantu->next;
                    }
                    Node *hapus = tail;
                    tail = bantu;
                    delete hapus;
                    tail->next = nullptr;
                    return tail->data;
                }
                else
                {
                    head = tail = nullptr;
                    return 0;
                }
            }
        }

        int peek() {
            return tail->data;
        }

        void OutputKurang() {
            int hasil = peek();

            while (head != tail) {
                cout << peek() << " - ";
                hapusBelakang();
                hasil -= peek();
            }
            cout << peek() << " = ";
            cout << hasil;
        }

        void OutputJumlah()
        {
            int hasil = peek();

            while (head != tail) {
                cout << peek() << " + ";
                hapusBelakang();
                hasil += peek();
            }
            cout << peek() << " = ";
            cout << hasil;
        }
};

int main()
{
    linkedList SLL;
    SLL.insert(1);
    SLL.insert(3);
    SLL.insert(4);
    SLL.insert(7);
    SLL.show();

    SLL.OutputKurang();
    SLL.OutputJumlah();
    cout << endl;
    
    linkedList SLL2;
    SLL2.insert(1);
    SLL2.insert(4);
    SLL2.insert(5);
    SLL2.insert(8);
    
    SLL2.OutputJumlah();
    SLL2.OutputKurang();

    
    return 0;
}