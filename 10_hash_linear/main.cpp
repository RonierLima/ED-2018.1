#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

enum Marcador {VAZIO = 0, CHEIO = 1, DELETADO = 2};

struct Elem {
    int key;
    string value;

    Elem(int key = 0, string value = ""){
        this->key = key;
        this->value = value;
    }

    bool operator ==(Elem other){
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

struct HashLinear{ //linear probing
    pair<Elem, Marcador> * vet;
    int capacity;
    int size;
    HashLinear(int capacity){
        vet = new pair<Elem, Marcador>[capacity];
        this->capacity = capacity;
        this->size = 0;
        for(int i = 0; i < capacity; i++){
            vet[i].first = Elem();
            vet[i].second = VAZIO;
        }
    }


    bool inserir(Elem elem){
        int ret_busca = buscar(elem.key);
        if(ret_busca == -1)
            return false;
        int posicao = elem.key % this->size;
        while((vet[posicao].second != VAZIO) || (vet[posicao].second != DELETADO))
            posicao = (posicao + 1) % capacity;
        this->vet[posicao].second = CHEIO;
        this->vet[posicao].first = elem;
        this->size++;

    }

    int buscar(int key){
        int base = key % capacity;
        int i = 0;
        int posicao = base;
        while ((vet[posicao].first == NULL) || (vet[posicao].second != VAZIO)){
            i++;
            posicao = (base + i * i) % capacity;
        }
        if(vet[posicao].second == VAZIO)
            return -1;
        return posicao;
    }

    bool remover(int key){
        auto ret_busca = buscar(key);
        if (ret_busca != -1){
            this->vet[ret_busca].second = DELETADO;
            size--;
            return true;
        }
        return false;
    }

};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
