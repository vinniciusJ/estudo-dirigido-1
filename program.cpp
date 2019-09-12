#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

bool verificacao (char executar){

    while(executar != 'S' && executar != 'N'){
        executar = getch();
    }
    if (executar == 'S'){
        return true;
    }
    else {
        return false;
    }
}

vector <int> numeros(vector <int> lista){
    lista.clear();
    char tecla;

    do{
        int n;
        cout << "Digite um número: ";
        cin >> n;
        lista.push_back(n);

        cout << "Deseja adicionar mais um número? (S/N)" << endl;
        tecla = getch();
    }while(verificacao(tecla));

    return lista ;
}
void somatorio( vector <int> lista){

    int soma = 0;
    for(int n: lista){
        soma = soma + n;
    }
    cout << "SOMA DOS ELEMENTOS = " << soma << endl;
}
void media( vector <int> lista){
    double media = 0;
    for (int n: lista){
        media = media + n;
    }
    media = media/lista.size();
    cout << "MEDIA = " << media << endl;
}
void media_sem_negativos (vector <int> lista){
    for(int i = 0; i<lista.size(); i++){
        if(lista[i] < 0){
            lista[i] = 0;
        }
    }
    media(lista);
}
void media_somatorio_repetidos (vector <int> lista){
    sort(begin(lista), end(lista));
    vector <int> lista2 = lista;

    for(int i = 0; i<lista.size(); i++){
         for(int j=0; j<lista.size(); j++){
             if(lista2[i] == lista2[j]){
                 if(i != j){
                     lista[i] = 0;
                 }
             }
         }
    }
    somatorio(lista);
    media(lista);
}
void organizar(vector <int> lista) {

    sort(begin(lista), end(lista));
    cout << "Elementos da lista em ordem crescente: {";
    for (int i = 0; i < lista.size()  ; i++) {
        if (i < lista.size()-1) {
            cout << lista[i] << ",";
        } else {
            cout << lista[i] << "}" << endl;
        }
    }
}
int main () {

    vector <int> lista_numeros = {0};
    char tecla, tecla1;
    lista_numeros.clear();

    setlocale(LC_ALL, "Portuguese");

    cout << setw(25) << "SEJA BEM-VINDO(A)" << endl << endl;
    system("pause");
    system("cls");

    lista_numeros = numeros(lista_numeros);

    system("cls");

    while (true){

         cout << setw(50) << "ESCOLHA UMA OPÇÃO:" << endl << endl;
        cout << "[0] SAIR" << setw(38) << "|" << setw(25) << "[4] MEDIA SEM OS VALORES NEGATIVOS" << endl;
        cout << "[1] SOMA DOS NUMEROS DIGITADOS" << setw(16) << "|"<< setw(25) <<  "[5] MEDIA E SOMATORIO SEM OS VALORES REPETIDOS" << endl;
        cout << "[2] MEDIA DOS NUMEROS DIGITADOS" << setw(15) << "|" << setw(25) << "[6] NUMEROS EM ORDEM CRESCENTE"<< endl;
        cout << "[3] MEDIA E SOMATORIO" << setw(25) << "|" << setw(25)<<"[7] DIGITAR NOVOS VALORES" << endl;
        cout << endl;

        tecla1 = getch();

        switch (tecla1) {
            case '0':
                break;
            case '1':
                somatorio(lista_numeros);
                break;
            case '2':
                media(lista_numeros);
                break;
            case '3':
                somatorio(lista_numeros);
                media(lista_numeros);
                break;
            case '4':
                media_sem_negativos(lista_numeros);
                break;
            case '5':
                media_somatorio_repetidos(lista_numeros);
                break;
            case '6':
                organizar(lista_numeros);
                break;
            case '7':
                lista_numeros = numeros(lista_numeros);
                break;
        }
        if (tecla1 == '0'){
            exit(0);
        }
        cout << endl;
        system("pause");
        system("cls");
    }

    return 0;
}
