#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int nc = 60;
const int nl = 20;

struct Par{

    int l, c;
    //construtor
    Par(int l = 0, int c = 0){
        this->l = l;
        this->c = c;
    }
};

vector<Par> getNeib(Par p){

    vector<Par> v;

    v.push_back(Par(p.l, p.c + 1));
    v.push_back(Par(p.l, p.c - 1));
    v.push_back(Par(p.l + 1, p.c));
    v.push_back(Par(p.l - 1, p.c));

    return v;
}

vector<Par> embaralhar(vector<Par> vet){
    for(int i = 0; i < (int) vet.size(); i++){
        int aleat = rand() % vet.size();
        swap(vet[i], vet[aleat]);
    }
    return vet;
}

void mostrar(vector<string>& mat){

    cout << string(50, '\n');

    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }

    getchar();
}


int queimar(vector<string> &mat, int l, int c, int nivel){

        if(l < 0 || l >= nl)
                return 0;
        if(c < 0 || c >= nc)
                return 0;
        if(mat[l][c] != '#')
                return 0;

        int queimadas = 0;
        queimadas++;

        mat[l][c] = '0' + nivel % 10;

        mostrar(mat);

        nivel++;

        vector<Par> parVet = embaralhar(getNeib(Par(l, c)));


        for(int i = 0; i < (int)parVet.size(); i++){
            Par v = parVet[i];
            queimadas += queimar(mat, v.l, v.c, nivel);
        }

        mat[l][c] = '.';
        mostrar(mat);

        return queimadas;
}

int main()
{
    srand(time(NULL));
    //os containers tem uma construção padrao
    //container<tipo> nome(qtd, elemento_default)
    //cria um vetor de string
    //com nl elementos da string default
    //a string default sao 30 char ' '
    vector<string> mat(nl, string(nc, ' '));
    int narvores = nl * nc * 1.5;
    //insere varias arvores em lugares aleatorios
    //muitas serao superpostas
    for(int i = 0; i < narvores; i++){
        mat[rand() % nl][rand() % nc] = '#';
    }

    mostrar(mat);

    int total = queimar(mat, 0, 0, 0);
    cout << total << " arvores queimaram\n";

    int restArv = 0;

    //Conta quantas arvores não queimaram
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            if(mat[i][j] == '#')
                restArv ++;
        }
    }

    cout <<"Restaram" << restArv << " arvores\n";

    return 0;
}

