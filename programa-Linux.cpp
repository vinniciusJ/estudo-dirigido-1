#include <iostream>
		#include <vector>
		#include <algorithm>
		#include <iomanip>
		#include <stdlib.h>
		#include <locale.h>

		//TESTE!

		using namespace std;

		vector <int> inseridos = {};


		bool verificacao (char executar){
		    char errado;
	         if (executar == 'N'){
		        return false;
	         }
		    else if (executar == 'S'){
		        return true;
		    }

		    else{
		        cout << "(S/N)";
		        cin >> errado;
		        system("clear");
		        verificacao(errado);
		    }

		}

		void inserir ( vector <int> lista){
		    char tecla;
		    int n = 0;
		    do{

		        cout << "Digite um numero: ";
		        cin >> n;
		        lista.push_back(n);

		        cout << "Deseja adicionar mais um numero? (S/N)" << endl;
		        cin >> tecla;
		        system("clear");

		    }while(verificacao(tecla));
		    for(int i = 0; i < lista.size(); i ++)
		    {
		        inseridos.push_back(lista[i]);
		    }
		}
		void somatorio( vector <int> lista){

		    int soma = 0;
		    for(int n: lista){
		        soma = soma + n;
		    }
		    cout << endl << "SOMA DOS ELEMENTOS = " << soma << endl;
		}
		void media( vector <int> lista){
		    double media = 0;
		    for (int n: lista){
		        media = media + n;
		    }
		    media = media/lista.size();
		        cout << "MEDIA = " << media << endl;
		}
		void  soma_media(vector<int> lista) {
		    somatorio(lista);
		    media(lista);
		}
		void media_sem_negativos (vector <int> lista){
		    for(int i = 0; i < lista.size(); i++){
		        if(lista[i] < 0){
		            lista[i] = 0;
		        }
		    }
		    media(lista);
		}
		void media_somatorio_repetidos (vector <int> lista){
		    sort(begin(lista), end(lista));
		    for(int i = 0; i < lista.size(); i++){
		         for(int j=0; j<lista.size(); j++){
		             if(lista[i] == lista[j]){
		                lista[i] = 0;
		                 lista[j] = 0;
		             }
		         }
		    }
		    somatorio(lista);
		    media(lista);
		}
		void organizar(vector <int> lista) {
		  sort(begin(lista), end(lista));
		    cout << "Elementos da lista em ordem crescente: {";
		    for (int i = 0; i < lista.size(); i++) {
		        if (i < lista.size() - 1) {
		            cout << lista[i] << ",";
		        } else {
		            cout << lista[i] << "}" << endl;
		        }
		    }
		}
		int main () {

		    vector <int> lista_numeros;
		    lista_numeros.clear();
		    char tecla1;
		    bool executar = true;

		    setlocale(LC_ALL, "Portuguese");

		    cout << setw(25) << "SEJA BEM-VINDO(A)" << endl << endl;
		    cout << "Pressione enter para continuar...";
		    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	    system("clear");


		 inserir({});


		    while (executar){

		        cout << setw(50) << "ESCOLHA UMA OPCAO:" << endl << endl;
		        cout << setw(50) << "[0] SAIR" << endl;
		        cout << "[1] SOMA DOS NUMEROS DIGITADOS" << setw(16) << "|"<< setw(25) <<  "[4] MEDIA SEM OS VALORES NEGATIVOS" << endl;
		        cout << "[2] MEDIA DOS NUMEROS DIGITADOS" << setw(15) << "|" << setw(25) << "[5] MEDIA E SOMATORIO SEM OS VALORES REPETIDOS" << endl;
		        cout << "[3] MEDIA E SOMATORIO" << setw(25) << "|" << setw(25)<<"[6] NUMEROS EM ORDEM CRESCENTE" << endl;

		        cin >> tecla1;

		        switch (tecla1) {
		            case '0':
		            system ("clear");
		                break;
		            case '1':
		                somatorio(inseridos);
		                break;
		            case '2':
		                media(inseridos);
		                break;
		            case '3':
		                soma_media(inseridos);
		                break;
		            case '4':
		                media_sem_negativos(inseridos);
		                break;
		            case '5':
		                media_somatorio_repetidos(inseridos);
		                break;
		            case '6':
		                organizar(inseridos);
		                break;
		        }

		        if (tecla1 == '0'){
		            exit(0);
		        }
		        else {
		            cout << "Deseja escolher mais uma opcao(S/N)?" << endl;
		               char tecla2;
		            cin >> tecla2;
		            system("clear");

		            if(verificacao(tecla2)){
		                executar = true;
		            }
		            else {
		                char tecla3;
		                cout << "Deseja digitar outros numeros(S/N)?" << endl;
		                cin >> tecla3;
		                system("clear");
		                if(verificacao(tecla3)){
		                    inseridos.clear();
		                    inserir({});
		                }
		                else{
		                    executar = false;
		                }


		            }
		        }
		    }

		    return 0;
		}
