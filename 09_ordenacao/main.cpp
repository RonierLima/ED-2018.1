#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &vet, int inicio, int final){

    if(inicio >= final)
        return;
    int i = inicio;
    int j = final;
    int pivo = vet[rand() % vet.size()];

    while(i <= j){

        while(vet[i] < pivo){
            i++;
        }
        while (vet[j] >  pivo) {
            j--;
        }
        if(i <= j){
            swap(vet[i++], vet[j--]);
        }
    }
    quick_sort(vet, inicio, j);
    quick_sort(vet, i, final);

}

int main(){

    const int tam = 20;

    vector <int> vet(tam,0);

    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % 10;
    }

    for (int i = 0; i < tam; i++) {
        cout << vet[i] << " ";
    }

    cout << "\n";

    quick_sort(vet, 0, vet.size()-1);

    for (int i = 0; i < tam; i++) {
        cout << vet[i] << " ";
    }

    return 0;
}
