#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <locale.h>
using namespace std;

#define LIN 15
#define COL 40

void mostra_mapa(char **x)
{
  for(int i=0; i<LIN; ++i)
	{
		for(int j = 0; j<COL; ++j)
		{
			cout << setw(2) << x[i][j] << "|";
		}
		cout << endl;
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	char **mat;
	int i;
	int j;
	int k;
	int op;
	int p, f, ocupados;
	double bilheteria;
	ocupados=0;
	bilheteria=0;
	
	mat = new char*[LIN];
	
	for(i=0; i<LIN; ++i) 
	{
		mat[i] = new char[COL]; 
	}
	
	k = 0;
	for(i=0; i<LIN; i++)
	{
		for(j = 0; j<COL; j++)
		{
			mat[i][j] = '.';
		}
	}
	
	
	do
	{
    cout << endl;
    cout << "0.	Finalizar" << endl;
    cout << "1.	Reservar poltrona" << endl;
    cout << "2.	Mapa de ocupa��o" << endl;
    cout << "3.	Faturamento" << endl;
    cout << "Digite sua op��o: ";
    cin >> op;
	
	char resp = 'a';
		switch (op)
	   {
		   case 0:
		   	    return 0;
	 	        break;
		
	       case 1:
	       	while(resp !='n'){
	       		cout << "Informe a fileira da poltrona (0-39): ";
    			cin >> f;
    			if((f < 0) ||(f > 15))
				{
					cout << "Fileira inv�lida " <<endl;
				}
				else
				{
		 	        cout << "Informe o n�mero da poltrona (0-14): ";
	    			cin >> p;
	    			if((p < 0) ||(p > 40))
                    {
					cout << "Poltrona inv�lida " << endl;
					}
					else{
		    			if(mat[f][p] == '.')
						{
			            mat[f][p] = '#'; 
			            ocupados++;
						if((f >= 0)&&(f < 5))
							{
								bilheteria = bilheteria + 50;
							}
						if((f >= 5) && (f < 10))
							{
								bilheteria = bilheteria + 30;
							}
						if((f >= 10) && (f < 15))
							{
								bilheteria = bilheteria + 15;
							}
						}
						else
						{
						cout << "Poltrona ocupada " <<endl;
						}
					}
				}
				cout << "Deseja continuar com as reservas s/n: ";
    			cin >> resp;
			   }
			    break;
			 
		   case 2:
		        mostra_mapa(mat);
			    break;
		   case 3:
		   		 cout << "Qtde de lugares ocupados: " << ocupados << endl;
				 cout << "Valor da bilheteria (em R$): " << bilheteria << endl;	
		         break;
		
		   default:
		        cout << "Op��o inv�lida" << endl;
		}
	} while((op=!0));
	
}