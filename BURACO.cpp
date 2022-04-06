#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

int carta_inedita(string x, string **matriz)
{
	int c, j;
	j=0;
	do
	{
		c=0;
		do
		{
			   	if(matriz[j][c]==x)
				   {
				   	c=11;
				   	j=4;
				   }
			   	c++;
		}
		while(c<11);
		++j;
	}
	while(j < 4);
    return (j==4);
}

int main(int argc, char** argv)
{
	string **baralho;
	string **mao;
	int i, j, c;
	
	baralho = new string*[2];
	
	for(i=0; i<2; ++i) 
	{
		baralho[i] = new string[52];
	}
    
	mao = new string*[4];
	
	for(i=0; i<4; ++i) 
	{
		mao[i] = new string[11];
	}
	
    int carta = 0;
	for(int b=0; b<2; ++b)
	{
		for(int naipe=0; naipe<4; ++naipe)
		{
			for(int face=0; face<13; ++face)
			{
				baralho[b][carta] =  to_string(naipe+1) +"-"+ to_string(face+1) +"-"+ to_string(b+1);
				++carta;
				if (carta>51)
				{
					carta = 0;
				}		    
			}
		}
	}
    
	   int cont =0;
	   string s;
	   	srand(time(0));
	  while(cont<=44)
	  {
	  	j=0;
	  	do
		  {
              c=0;
			  do 
			  {
			  	int ba = rand() % (2+1-1)+1;
			  	int ca = rand() % (52+1-1)+1;
			  	
			     s=baralho[ba-1][ca-1];
			 	
				 if(carta_inedita(s,mao))
				 {
				 	 mao[j][c]=s;
				 	 ++cont;
				 	 ++c;
				 }
				 
				 
			  }
			  while(c<11);
			  ++j;
		  }
		  while(j<4);
	  }
  
		
	
	  for(int j=0; j<4; ++j)
	{
		cout<<"Jogador "<< j+1 << endl;
		for(int c=0; c<11; ++c)
		{
			cout<<mao[j][c]<<endl;		   
		}
		cout<< endl;
	}  	
	return 0;
}