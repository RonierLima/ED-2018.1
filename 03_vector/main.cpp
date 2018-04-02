#include <iostream>

using namespace std;

struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
//        this->data = (int*) malloc(capacidade * 4);//retorno lixo
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){

        if(this->_size == this->_capacidade)
            this->reserve(2 * _capacidade);

        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }
    int& front(){
        return this->_data[0];
    }
    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){
        return &this->_data[0];
    }
    int * end(){
        return &this->_data[this->_size];
    }
    int size(){
        return this->_size;
    }
    int capacity(){
        return this->_capacidade;
    }

    void reserve(int capacidade){

        Vetor antigo(this->size());

        for (int i = 0; i < this->size(); ++i) {
            antigo.push_back(this->at(i));
        }


        if(capacidade <= this->capacity()){

            this->_capacidade = capacidade;
            this->_size = 0;
            this->_data = new int[capacidade];

            for (int i = 0; i < capacidade; ++i) {
                this->push_back(antigo.at(i));
            }

        }else{

            this->_capacidade = capacidade;
            this->_size = 0;
            this->_data = new int[capacidade];

            for (int i = 0; i < antigo.size(); ++i) {
                this->push_back(antigo.at(i));
            }
        }
    }



};

int main(){

    Vetor vet(5);

    cout << endl;

    for (int i = 0; i < vet.capacity(); ++i) {
        vet.push_back(i);
    }

    cout << endl;
    for (int i = 0; i < vet.size(); ++i) {
        cout << vet.at(i) << endl;
    }

    vet.reserve(2);


    cout << endl;
    for (int i = 0; i < vet.size(); ++i) {
        cout << vet.at(i) << endl;
    }

    cout << endl;
    cout << vet.size() << endl;

    return 0;
}
