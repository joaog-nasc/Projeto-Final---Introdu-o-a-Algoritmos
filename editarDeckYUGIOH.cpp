/* Tema: Yu-Gi-Oh
 * Grupo 17: Andrey Messias de Lima
 * 		  	 Caio Teixeira Ladeira
 *  		 João Gabriel da Silva Nascimento
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

struct carta{
     char nome[71];
     char atributo[11];
     char raridade[16];
     int nivel;
     char tipo[16];
     int atk;
     int def;
     char descricao[221];
};

void exibirImagem(){
	cout << R"(
	__   __                ___   _          ___    _      _ 
	\ \ / /  _  _   ___   / __| (_)  ___   / _ \  | |_   | |
	 \ V /  | || | |___| | (_ | | | |___| | (_) | | ' \  |_|
	  |_|    \_,_|        \___| |_|        \___/  |_||_| (_)

			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⣠⣴⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⠃⠀⣠⣾⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⢀⣿⣿⡿⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⣿⡷⣯⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⢿⡿⣷⣿⣯⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠠⠤⣦⣶⣤⡈⢷⣿⣥⣿⣿⣻⡗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠰⠶⢆⣠⣶⣶⣿⣿⣿⣾⣿⣿⠿⣿⣿⣿⣦⡤⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⣠⣐⣿⣿⣿⣿⣾⣿⣿⣿⢿⣿⣦⣽⣿⣿⣿⣿⣏⠀⡠⣠⡶⠦⠶⣶⣖⠆⠀⠀⠀
			⠈⠉⠉⠈⠉⠻⢽⣿⣿⣿⣦⣽⣿⣿⣿⣿⣿⠟⢱⡾⢚⣷⣿⠟⠉⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⢠⣿⢟⡿⣿⣿⣿⣯⡿⣿⣿⣟⢤⢲⡿⠔⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⣿⣻⠾⠁⠘⣿⣿⣿⣿⡿⣶⢟⣿⣷⣅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⢺⣿⣟⡄⠀⠀⢸⣿⣯⣿⣿⡀⠀⠉⠙⠛⠻⢿⠀⣖⣂⠆⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠈⢻⠏⡃⣤⡴⢿⣿⣿⣿⣿⣯⠀⠀⠀⠀⠀⠀⠉⠓⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⡎⣤⣳⣿⠇⣼⣿⣭⣿⣿⣿⣷⣶⠶⣶⣶⣶⣶⣶⣄⠀⠀⠀⠀⠀⠀⠀
			⠀⢀⡠⠞⠁⠁⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣶⣻⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀
			⠀⠁⠀⠀⠀⠀⠀⠀⠙⠻⣿⣿⣿⣿⣯⣿⣿⣛⠋⢻⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⡀
			⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣧⡢⠘⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀
			⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⡿⠋⠘⢿⣿⣷⣅⠸⠛⠁⠙⠛⠛⠟⠁⠀⠀⠀
			⠀⠀⠀⢀⣴⣾⣿⣿⣿⣟⣽⣿⠏⠁⠀⠀⣀⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⢰⣿⣿⣿⣿⣿⠋⣸⣿⠏⠀⣀⣬⣯⣭⣿⣯⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⢸⣿⣿⣿⣿⡇⢰⣷⢿⢤⣎⣻⡿⠛⠛⠁⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⢾⣿⣿⣿⣿⠁⢨⡿⢿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠹⣿⣿⣿⠀⠸⣽⠯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠘⢿⣿⡄⠀⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠉⠻⡀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

	)" << endl;
}

void tituloMenu(){
		cout << R"(
  __  __                       _ 
 |  \/  |  ___   _ _    _  _  (_)
 | |\/| | / -_) | ' \  | || |  _ 
 |_|  |_| \___| |_||_|  \_,_| (_)
	)" << endl;
}

void prencherVetor(carta*& vetorCartas, carta cartas, int& capacidade, int& tamanhoAtual, ifstream& arquivoCSV){
		
	string linha;	
	
	while(getline(arquivoCSV, linha)){
		
		stringstream ss(linha);
		
		//preenche o vetor
		ss.getline(cartas.nome, 71, ',');
		ss.getline(cartas.atributo, 11, ',');
		ss.getline(cartas.raridade, 16, ',');
		ss >> cartas.nivel;
		ss.ignore();
		ss.getline(cartas.tipo, 16, ',');
		ss >> cartas.atk;
		ss.ignore();
		ss >> cartas.def;
		ss.ignore();
		ss.getline(cartas.descricao, 221);
		
		vetorCartas[tamanhoAtual] = cartas;
		
		tamanhoAtual++;
		
		//redimensionamento
		if(tamanhoAtual==capacidade){
			
			capacidade += 5;
			carta* aux = new carta[capacidade];
			
			for(int i = 0; i<tamanhoAtual; i++){
                aux[i] = vetorCartas[i];
            }
            
            delete[] vetorCartas;
            vetorCartas =  aux;
			
		}
		
	}
		
}

void imprimirVetor(carta* vetorCartas,int i, int fim){
	
	while(i<=fim){
		
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "Nome: " << vetorCartas[i].nome << endl;
		cout << "Atributo: " << vetorCartas[i].atributo << endl;
		cout << "Raridade: " << vetorCartas[i].raridade << endl;
		cout << "Nivel: " << vetorCartas[i].nivel << endl;
		cout << "Tipo: " << vetorCartas[i].tipo << endl;
		cout << "ATK: " << vetorCartas[i].atk << endl;
		cout << "DEF: " << vetorCartas[i].def << endl;
		cout << "Descricao: " << vetorCartas[i].descricao << endl;
		
		i++;	
	}
	
}

void salvarBinario(carta* vetorCartas, int tamanhoAtual){
	
	ofstream arquivoBinario("dados.bin", ios::binary);
	if(!arquivoBinario){
		cout << "ERRO: Nao foi possivel criar o arquivo binario!" << endl;
		return;
	}
	
	arquivoBinario.write(reinterpret_cast<char*>(vetorCartas), tamanhoAtual * sizeof(carta));
	arquivoBinario.close();
	
}

void salvarCSV(carta* vetorCartas, int tamanhoAtual){
		
	ofstream saida("yugioh.csv");//para testes, versão final salvar em yugioh.csv
	if(!saida){
		cout << "ERRO: Nao foi possivel criar o arquivo csv!" << endl;
		return;
	}
	
	for(int i=0; i<tamanhoAtual; i++){
		
		saida << vetorCartas[i].nome << ",";
		saida << vetorCartas[i].atributo << ",";
		saida << vetorCartas[i].raridade << ",";
		saida << vetorCartas[i].nivel << ",";
		saida << vetorCartas[i].tipo << ",";
		saida << vetorCartas[i].atk << ",";
		saida << vetorCartas[i].def << ",";
		saida << vetorCartas[i].descricao << endl;
		
	}
	
	saida.close();
	
}

void adicionarCarta(carta* vetorCartas, int& tamanhoAtual){
	
	cout << "Digite os dados da nova carta:" << endl;

	cin.ignore();
	
	cout << "Nome (max. 70 caracteres): ";
	cin.getline(vetorCartas[tamanhoAtual].nome, 71);
    
    cout << "Atributo (max. 10 caracteres): ";
    cin.getline(vetorCartas[tamanhoAtual].atributo, 11);
    
    cout << "Raridade (max. 15 caracteres): ";
    cin.getline(vetorCartas[tamanhoAtual].raridade, 16);
    
    cout << "Nivel: ";
    cin >> vetorCartas[tamanhoAtual].nivel;
    cin.ignore();
    
    cout << "Tipo (max. 15 caracteres): ";
    cin.getline(vetorCartas[tamanhoAtual].tipo, 16);
    
    cout << "Atk: ";
    cin >> vetorCartas[tamanhoAtual].atk;
    cin.ignore();
    
    cout << "Def: ";
    cin >> vetorCartas[tamanhoAtual].def;
    cin.ignore();
    
    cout << "Descricao (max. 220 caracteres): ";
    cin.getline(vetorCartas[tamanhoAtual].descricao, 221);

	cout << "Carta adicionada com sucesso!" << endl;
	
    tamanhoAtual++;
}

//QuickSort para os atributos do tipo int
void trocar(carta &a, carta &b) {
    carta aux = a;
    a = b;
    b = aux;
}

int particionarInt(carta* vetorCartas, int menor, int maior, int atributo){

	int pivo;
	if (atributo == 2) pivo = vetorCartas[maior].nivel;
    else if (atributo == 3) pivo = vetorCartas[maior].atk;
    else if (atributo == 4) pivo = vetorCartas[maior].def;

	int i = menor - 1;

	for(int j=menor; j<maior; j++){
		if((atributo==2 && vetorCartas[j].nivel < pivo) || (atributo==3 && vetorCartas[j].atk < pivo) || (atributo==4 && vetorCartas[j].def < pivo)){
			i++;
			trocar(vetorCartas[i], vetorCartas[j]);
		}
	}
	trocar(vetorCartas[i+1], vetorCartas[maior]);
	return i+1;

}

void quickSortInt(carta* vetorCartas, int menor, int maior, int atributo){

	if(menor<maior){
		int pivo = particionarInt(vetorCartas, menor, maior, atributo);

		quickSortInt(vetorCartas, menor, pivo-1, atributo);
		quickSortInt(vetorCartas, pivo+1, maior, atributo);
	}

}

//QuickSort para campos do tipo char
int particionarChar(carta* vetorCartas, int menor, int maior){
	//pivo selecionado
	carta pivo = vetorCartas[maior];
    int i = menor - 1;
    
    for(int j=menor; j<maior; j++){
		//compara usando strcmp
		if(strcmp(vetorCartas[j].nome, pivo.nome) < 0){
            ++i;
            trocar(vetorCartas[i], vetorCartas[j]);
        }
	}
	
	//coloca o pivo na posição correta
    trocar(vetorCartas[i+1], vetorCartas[maior]);
	return i+1;
}

void quickSortChar(carta* vetorCartas, int menor, int maior){

	if(menor<maior){
		int pivo = particionarChar(vetorCartas, menor, maior);

		quickSortChar(vetorCartas, menor, pivo-1);
		quickSortChar(vetorCartas, pivo+1, maior);
	}

}

//Funções de Busca
int buscaBinariaChar(carta* vetorCartas, int inicio, int fim, char alvo[71]){

	quickSortChar(vetorCartas, inicio, fim);
	
	while (inicio <= fim) {
        int meio = (inicio + fim) / 2; 

        if (strcmp(vetorCartas[meio].nome, alvo) == 0) {
            return meio; //valor encontrado
            
        } else if (strcmp(vetorCartas[meio].nome, alvo) < 0) {
            inicio = meio + 1;
            
        } else {
            fim = meio - 1;
        }
    }

    return -1; //valor não encontrado 
}    

/*Obs.: Para buscar dados q se repetem, a lógica da busca binária não se aplica.
 		Por esse motivo, a busca por nível, foi feita de forma sequencial.*/

void buscaInt(carta* vetorCartas, int inicio, int fim, int alvo){
	
	
	while (inicio <= fim) {
		
		if (vetorCartas[inicio].nivel == alvo){
			imprimirVetor(vetorCartas, inicio, inicio);
		}
		
		inicio++;
    }
    
    cout << "Nivel nao encontrado!" << endl;
} 

void removerCarta(carta* vetorCartas, int posicao, int& tamanhoAtual){
	
	if(posicao == -1){
		cout << "Carta nao encontrada!" << endl;
		return;
	}else{
		
		for(int i = posicao; i<tamanhoAtual; i++){
			vetorCartas[i] = vetorCartas[i+1];
		}
		
		tamanhoAtual--;
		
		cout << "Carta removida com sucesso!" << endl;
		
	}
}

int main(){
	
	//Abrindo .csv
	ifstream arquivoCSV("yugioh.csv");
	if(!arquivoCSV){
		cout << "ERRO: não é possível abrir o arquivo!" << endl;
	}
	
	//Criando o vetor
	int capacidade = 40;
	int tamanhoAtual = 0;
	
	carta* vetorCartas = new carta[capacidade];
	carta cartas;
	
	//Carregando os dados do .csv no vetor
	prencherVetor(vetorCartas, cartas, capacidade, tamanhoAtual, arquivoCSV);
	
	//Menu do projeto
	int opcao = 0;
	
	cout << "-----------------------------------------------------------------------------" << endl;
	exibirImagem();
	
	do{
		
		cout << "-----------------------------------------------------------------------------" << endl;
		tituloMenu();
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "1. Imprimir todo o deck" << endl;
		cout << "2. Imprimir apenas um trecho" << endl;
		cout << "3. Adicionar carta" << endl; 
		cout << "4. Remover carta" << endl; 
		cout << "5. Buscar carta" << endl; 
		cout << "6. Ordenar deck" << endl;
		cout << "7. Salvar alteracoes (.bin e .csv)" << endl;
		cout << "0. Sair" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
 		cin >> opcao;
		
		switch(opcao){
			
			case 1:
				imprimirVetor(vetorCartas, 0,(tamanhoAtual-1));
				break;
			
			case 2:
				//Imprimindo um intervalo do vetor
				int inicio;
				int fim;	
				cout << "Selecione um intervalo entre 0 e " << (tamanhoAtual-1) << ": " << endl;
				cout << "Inicio: ";
				cin >> inicio;
				cout << "Fim: ";
				cin >> fim; 
				cout << "-----------------------------------------------------------------------------" << endl;
				
				imprimirVetor(vetorCartas, inicio, fim);
								
				break;
				
			case 3:
				//Adicionar Carta
				adicionarCarta(vetorCartas, tamanhoAtual);
				break;
			
			case 4:
				//Remover carta
				char alvoNome[71];
				cout << "Insira o nome da carta que voce deseja excluir: ";
				cin.ignore();
				cin.getline(alvoNome, 71);
				
				int posicao;
				posicao = buscaBinariaChar(vetorCartas, 0, tamanhoAtual-1, alvoNome);
				
				removerCarta(vetorCartas, posicao, tamanhoAtual);
				
				break;

			case 5:
				//Buscar carta
				cout << "Voce deseja buscar por:" << endl;
				cout << "1. Nome" << endl;
				cout << "2. Nivel" << endl;
				cout << "-----------------------------------------------------------------------------" << endl;
				cin >> opcao;
				
				switch(opcao){
					
					case 1:
						char alvoNome[71];
						cout << "Insira o nome: ";
						cin.ignore();
						cin.getline(alvoNome, 71);
						
						int posicao;
						posicao = buscaBinariaChar(vetorCartas, 0, tamanhoAtual-1, alvoNome);
						
						if(posicao == -1){
							cout << "Nome nao encontrado!" << endl;
						}else{
							imprimirVetor(vetorCartas, posicao, posicao);
						}
						
						break;
				
					case 2:
						int alvoNivel;
						cout << "Insira o nivel: ";
						cin >> alvoNivel;
						
						buscaInt(vetorCartas, 0, tamanhoAtual-1, alvoNivel);
						
						break;
						
					default:
						break;
				}
				
				break;
			
			case 6:
				//ordenção
				cout << "Voce deseja ordenar por: " << endl;
				cout << "1. Nome" << endl;
				cout << "2. Nivel" << endl;
				cout << "3. Atk" << endl;
				cout << "4. Def" << endl;
				cout << "-----------------------------------------------------------------------------" << endl;
				cin >> opcao;

				quickSortInt(vetorCartas, 0, tamanhoAtual - 1, opcao);
				
				switch (opcao)
				{	
					case 1:
						quickSortChar(vetorCartas, 0, tamanhoAtual - 1);
						cout << "Cartas ordenadas por Nome!" << endl;
						break;
					
					case 2:
						cout << "Cartas ordenadas por Nivel!" << endl;
						break;
					
					case 3:
						cout << "Cartas ordenadas por Atk!" << endl;
						break;

					case 4:
						cout << "Cartas ordenadas por Def!" << endl;
						break;

					default:
						break;
				}

				break;

			case 7:
				//Salvando os dados em .bin e .csv	
				salvarBinario(vetorCartas, tamanhoAtual);
				salvarCSV(vetorCartas, tamanhoAtual);
				cout << "Dados salvos com sucesso!" << endl;
				break;
		    
			
			case 0:
				//Encerrar o programa
				cout << "Obrigado por utilizar nosso programa! <3";
				break;

			default:
				cout << "Digite uma opcao valida!" << endl;
		}	
	}while(opcao!=0);
	
	return 0;
}
