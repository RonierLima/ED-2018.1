#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
       head = deletarTudo(head);
    }


    Node* deletarTudo(Node* node){

        if(node == nullptr)
            return nullptr;
        deletarTudo(node->next);
        delete node;
        return nullptr;
    }

    Node * cortarRabo(Node * node, int value){
        if(node == nullptr)
            return nullptr;

        node->next = cortarRabo(node->next, value);
        if(node->next == nullptr && node->value != value){
            if(node->value != value){
                delete node;
                return nullptr;
            }else{
                return node;
            }
        }
        return node;
    }

    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }

    Node * _push_back(Node * node, int value){
        if(node == nullptr)
            return new Node(value);

        node->next = _push_back(node->next, value);
        return node;
    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    void rpop_back(){
        this->head = _rpop_back(head);
    }

    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
private:
    void _rshow(Node * node){
        if(node == nullptr)
            return;
        cout << node->value << " ";
        _rshow(node->next);
    }
public:
    void rshow(){
        _rshow(head);
        cout << endl;
    }

    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void rremove(int value){
        head = _remove(head, value);
    }

// Remover iterativo que faltava
    Node * iremove(int value){
      auto node = head;
          if(node == nullptr)
              return nullptr;

          if(head->value == value){
              auto aux = head;
              head = head->next;
              delete aux;
              return head;
          }
          while(node->next != nullptr){
              if(node->next->value == value){
                  auto aux = node->next;
                  node->next = node->next->next;
                  delete aux;
                  return node->next;
              }
              node = node->next;
          }
          return node;
    }
    void inserir_ordenado(int value){
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

    Node * _rinserir_ordenado(Node * node, int value){

        if(node == nullptr || (node->value >= value))
            return new Node(value, node);
        node->next = _rinserir_ordenado(node->next, value);
        return node;
    }

    void rinserir_ordenado(int value){
        head = _rinserir_ordenado(head, value);
    }

    int size(){
        auto node = head;
        int cont = 0;
        while(node != nullptr){
            cont++;
            node = node->next;
        }
        return cont;
    }

    int rsomar(Node * node){

    }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }

};

int main(){
    SList lista;
    lista.push_back(5);
    lista.push_back(6);
    lista.push_back(7);
    lista.push_back(10);
    lista.cortarRabo(lista.head, 7);

    return 0;
}
