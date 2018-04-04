#include <iostream>

using namespace std;

void rodar(int pessoas[], int& qtdPessoas){


        int aux = pessoas[0];

        for(int i = 0; i < qtdPessoas - 1; i++ )
            pessoas[i] = pessoas[i + 1];

        pessoas[qtdPessoas - 1] = aux;

}

void matar(int pessoas[], int& qtdPessoas){

    for(int i = 1; i < qtdPessoas; i++ )
        pessoas[i] = pessoas[i + 1];

    qtdPessoas --;
}

void mostrar(int pessoas[], int& qtdPessoas){

    for(int i = 0; i < qtdPessoas; i++ ){
        cout << pessoas[i]<< " ";
    }
    cout << endl;
}

int main()
{

    int qtdPessoas, posseArma;

    cin >> qtdPessoas;
    cin >> posseArma;

    int pessoas[qtdPessoas];


    for(int i = 0; i < qtdPessoas ; i++ )
        pessoas[i] = i + 1;

    while(pessoas[0] != posseArma){

        rodar(pessoas, qtdPessoas);
    }

    while(qtdPessoas > 1){

        mostrar(pessoas, qtdPessoas);
        matar(pessoas, qtdPessoas);
        for(int r = 0; r < posseArma; r++){
            rodar(pessoas, qtdPessoas);
        }
        posseArma = pessoas[0];

    }

    mostrar(pessoas, qtdPessoas);

    return 0;
}
