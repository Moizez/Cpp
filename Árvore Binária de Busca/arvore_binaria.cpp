#include <iostream>

using namespace std;

class No{
	private:
		No *esq, *dir;
		int chave;

	public:
		No (int chave){
			this->chave = chave;
		esq = NULL;
		dir = NULL;
		}

	int getChave(){
		return chave;
	}

	No* getEsq(){
		return esq;
	}

	No* getDir(){
		return dir;
	}

	void setEsq(No* no){
		esq = no;
	}

	void setDir(No* no){
		dir = no;
	}

};

class Arvore{
	private:
		No* raiz;

	public:
		Arvore(){
			raiz = NULL;
		}

		void inserir (int chave){
			if(raiz == NULL){
				raiz = new No(chave);
			}
			else{
				inserirAux(raiz, chave);
			}
		}
		
		void buscar (No* raiz, int valor) {
    		if(raiz == NULL){
    			return NULL;
			}else if(raiz->valor > valor){
				raiz->
			}
		}



		void inserirAux(No* no, int chave){
			if(chave < no->getChave()){
				if(no->getEsq() == NULL){
					No* novoNo = new No(chave);
					no->setEsq(novoNo);
				}
				else{
					inserirAux(no->getEsq(), chave);
				}
			}
			else if(chave > no->getChave()){
				if(no->getDir() == NULL){
					No* novoNo = new No(chave);
					no->setDir(novoNo);
				}
				else{
					inserirAux(no->getDir(), chave);
				}
			}

		}

		No* getRaiz(){
			return raiz;
		}
		
		//Pré-Ordem: 9-4-2-7-5-8-11-15-14
		void preOrdem(No* no){
			if(no != NULL){
				cout << no->getChave() << " ";
				preOrdem(no->getEsq());				
				preOrdem(no->getDir());
			}
		}

		//Ordem: 2-4-5-7-8-9-11-14-15
		void emOrdem(No* no){
			if(no != NULL){
				emOrdem(no->getEsq());
				cout << no->getChave() << " ";
				emOrdem(no->getDir());
			}
		}
		
		//Pós-Ordem: 2-5-8-7-4-14-15-11-9
		void posOrdem(No* no){
			if(no != NULL){
				posOrdem(no->getEsq());			
				posOrdem(no->getDir());
				cout << no->getChave() << " ";
			}
		}		
		
};

int main(int argc, char **argv){

	/*Arvore:
	R9
	E: 4-2-7-5-8
	D: 11-15-14
	*/
				
	Arvore arv;
	arv.inserir(9);
	arv.inserir(11);
	arv.inserir(15);
	arv.inserir(14);
	arv.inserir(4);
	arv.inserir(2);
	arv.inserir(7);
	arv.inserir(5);
	arv.inserir(8);

	cout << "Percorrer em pre-ordem: ";
	arv.preOrdem(arv.getRaiz());
	
	cout << "\nPercorrer em ordem:     ";
	arv.emOrdem(arv.getRaiz());
	
	cout << "\nPercorrer em pos-ordem: ";
	arv.posOrdem(arv.getRaiz());

	return 0;
}
