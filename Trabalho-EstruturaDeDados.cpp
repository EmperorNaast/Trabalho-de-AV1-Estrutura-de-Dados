#include <iostream>
using namespace std;

struct Pessoa
{
	int idade=0;
	string cpf="0";
	int sexo=0;
	bool gravida=false;

	Pessoa* proximo=NULL;
	Pessoa* anterior=NULL;
};

void printPessoa(Pessoa pessoa);
int lerInteiro(string campo);
string lerString(string campo);

int main()
{
	Pessoa* inicioLista=NULL;
	Pessoa* fimLista=NULL;
	Pessoa* aux=NULL;

	cout<<"AV1 Estrutura de Dados\n";
	int opcao=0;
	while(opcao != 4)
	{
		cout<<"\n1-Inserir nova pessoa";
		cout<<"\n2-Listar todas as pessoas";
		cout<<"\n3-Proximo atendimento";
		cout<<"\n4-Sair";
		cout<<"\n\nEscolha Opcao: ";
		cin>>opcao;

		switch(opcao)
		{
			case 1:
			{
				Pessoa* novo=new Pessoa;
				novo->idade=lerInteiro("Idade");
				novo->cpf=lerString("CPF");
				novo->sexo=lerInteiro("Sexo (1-Feminino 2-Masculino)");
				if(novo->sexo==1)
				{
					int gravida;
					cout<<"\nVoce esta gravida? (1-Sim 2-Nao): ";
					cin>>gravida;
					if(gravida==1)
					{
						novo->gravida=true;
					}
					else
					{
						novo->gravida=false;
					}
				}

				if(novo->idade>65 || novo->gravida==true)
				{
					if(inicioLista==NULL)
					{
						inicioLista=novo;
						fimLista=novo;
						novo->proximo=NULL;
						novo->anterior=NULL;
					}
					else
					{
						novo->proximo = inicioLista;
						inicioLista->anterior = novo;
						novo->anterior = NULL;
						inicioLista = novo;
					}
				}
				else
				{
					if(inicioLista==NULL)
					{
						inicioLista=novo;
						fimLista=novo;
						novo->proximo=NULL;
						novo->anterior=NULL;
					}
					else
					{
						fimLista->proximo=novo;
						novo->anterior=fimLista;
						novo->proximo=NULL;
						fimLista=novo;
					}
				}
			} break;
			case 2:
			{
				if(inicioLista==NULL)
				{
					cout<<"\nLista Vazia"<<endl;
				}
				else
				{
					aux=inicioLista;
					while(aux != NULL)
					{
						printPessoa(*aux);
						aux=aux->proximo;
					}
				}
			} break;
			case 3:
			{
				if(inicioLista==NULL)
				{
					cout<<"\nLista Vazia"<<endl;
				}
				else
				{
					aux=inicioLista;
					printPessoa(*aux);
					aux=aux->proximo;
					aux = inicioLista;
					inicioLista=inicioLista->proximo;
					delete(aux);
					aux=inicioLista;
				}
			} break;
		}
	}
	return 0;
}

int lerInteiro(string campo)
{
	int valor;
	cout<<"\nDigite "<<campo<<": ";
	cin>>valor;

	return valor;
}

string lerString(string campo)
{
	string valor;
	cout<<"\nDigite "<<campo<<": ";
	cin>>valor;

	return valor;
}

void printPessoa(Pessoa pessoa)
{
	cout<<"__________________________________\n";
	cout<<"\nIdade: "<<pessoa.idade<<endl;
	cout<<"CPF: "<<pessoa.cpf<<endl;
	if(pessoa.sexo==1)
	{
		cout<<"Sexo: Feminino\n";
		if(pessoa.gravida==true)
		{
			cout<<"Gravida: Sim\n";
		}
		else
		{
			cout<<"Gravida: Nao\n";
		}
	}
	else
	{
		cout<<"Sexo: Masculino\n";
	}
}
