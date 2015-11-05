#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <ostream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */
using namespace std;
#include "Boleto.h"
vector<string> MItem;
vector<string> Evento;
Fecha *FECHA;

void mostrar_vector(Bol *);
//void mostrar_Boleto(Boleto *);
void agregar(Bol *, int, Boleto *);
void resumen(Bol *, int);
int mostrar_menu();
void procesar_comandos(Bol *B, Fecha *f);										//3 Añadi , Fecha *f
void generar_Boleto(Bol *P);
void presentar_Resumen(Bol *P);
void agregar_evento();								
string ingresar_nombre();
int main(){

  MItem.push_back("Generar Boleto");
  MItem.push_back("Agregar evento");
  MItem.push_back("Presentar Resumen");
  MItem.push_back("Salir");
  FECHA=new Fecha(10,10,2015);
  string evento1="Guerra de Robots";
  string evento2="Eleccion de Representantes al CTCE UPIITA";
  //string evento3;//
  string evento3="Regresar a menu anterior";
  Evento.push_back(evento1);
  Evento.push_back(evento2);
  Evento.push_back(evento3);
  //Evento.push_back(evento4);//
  int numero_Maximo_D_Eventos=10;
  Bol *B;
  B=new Bol[numero_Maximo_D_Eventos];

  //B=new Bol[3];//
  B->set_evento(evento1);
  B->set_fecha_Bol(FECHA);  													//3
  (B+1)->set_evento(evento2);
  (B+1)->set_fecha_Bol(FECHA); 													//3
  //(B+2)->set_evento(evento3);//

//cout << Evento.size();


  procesar_comandos(B,FECHA);													//3 Añadi ,FECHA
  
  return 0;
}//end main()

string ingresar_nombre(){
	string nuevoEvento;
// 1 aqui estaba  // 	cout << "Ingrese el nombre de su evento por favor:  ";
	getline(cin,nuevoEvento);
	//cout << "Se ingreso el evento: " << nuevoEvento <<endl;
	return nuevoEvento;
}
void agregar_evento(Bol *B, Fecha *f){  										//3

  
  int a1;
  a1=Evento.size();
  //string nuevoEvento=ingresar_nombre();
  	cout << "Ingrese el nombre de su evento por favor:  "; // 1 aqui puse
  string nuevoEvento="";
do{
	nuevoEvento=ingresar_nombre();
}while(nuevoEvento=="");

  // string nuevoEvento="Simposium"; //BIEN¡
  Evento.push_back("Regresar a menu anterior");

  Evento[a1-1]=nuevoEvento;//a1-1
  //Bol *B;
  //B= new Bol[3];
  (B+a1-1)->set_evento(nuevoEvento);//a1-1
    //(B+a1-1)->set_fecha_Bol(f);//a1-1											//3
  //return 0;
}


int mostrar_menu(){
  int cho;
  do{
  cout << endl;
  cout << "Teclee un numero que corresponda a un elemento del siguiente menu:" << endl;
//  for(int i=0; i<MENU<string>::ElemDM.size(); ++i)
//    cout << i << " " << MENU<string>::ElemDM[i] << endl;
  for(int i=0; i<MItem.size(); ++i)
    cout << i << " " << MItem[i] << endl;
  cout << "Teclee el numero de la opcion elegida: ";
  cin >> cho;
  }while((cho<0)||(cho>=MItem.size()));
  return cho;
}
void procesar_comandos(Bol *B, Fecha *f){										//3 Añadi , Fecha *f
  int elec;
  do{
    elec=mostrar_menu();
    switch(elec){
      case 0:{generar_Boleto(B);break;}
      case 1:{agregar_evento(B,f);break;}											//3 Añadi agregar_evento(B,f)
      case 2:{presentar_Resumen(B);break;}//Para evitar SEGFAULT hay que llamar a presentar_Resumen()
                                          //solo si para todos los eventos hay al menos un Boleto generado
                                          // o mas bien en presentar_Resumen() antes de imprimir 
                                          //la info del cada evento asegurarse de que hay al menos un boleto
                                          //generado por el evento.
      case 3:{exit(0); 																//Añadir esta linea junto con libreria #include <stdlib.h>
      	break;
      }
      default:{break;}
    };
  }while(elec!=MItem.size()-1);
}
void presentar_Resumen(Bol *P){
	cout<<endl <<"Total de eventos: " <<Evento.size()-1<< endl;
  resumen(P, Evento.size()-1);
}

int Boleto::consecutivo=0;
Boleto::Boleto(Fecha *fec):Producto(fec){
//  set_fecha(fec);
  consecutivo++;
}
void Bol::set_evento(string evt){
  evento=evt;
}

void mostrar_vector(Bol *P){
  for(int i=0; i<P->V.size(); ++i)
    cout << P->V[i]->numdbol << " " << P->evento << " "
         << (*(P->V[i])).NombreDEmpresa << " " 
         << *((*(P->V[i])).f) << endl;
  cout <<  endl;
}
//void mostrar_Boleto(Boleto *);

/**
 @param index: indice que corresponde al evento para el cual 
 se va a agregar un Boleto en el vector<Boleto*> V del 
 index-esimo objeto de clase Bol.
 */
void agregar(Bol *P, int index, Boleto *b){
  b->numdbol=(P+index)->V.size()+1;
  (P+index)->V.push_back(b);
}
void generar_Boleto(Bol *P){
  int M;
  Boleto *b;
 // do{
  	  cout << "Elija el evento:" << endl;
  for(int i=0; i<Evento.size(); ++i)
    cout << i << " " << Evento[i] << endl;
  cout << "Evento elegido: ";
  cin >> M;
  if (M==(Evento.size()-1)){
procesar_comandos(P,FECHA);														//Añadi   ,FECHA
  }
  else{
  b=new Boleto(FECHA);
  agregar(P, M, b);
  }
  //}while(M<0 || M>(Evento.size()-1));

  

}

ostream& operator<<(ostream& out, Fecha& f){
    out << f.dia << "/" << f.mes << "/" << f.anio;
    return out;
}
//Fecha Bol::get_fecha_Bol(){
//	return FechaBol;
//}


/**
  @param n: el numero de eventos para los cuales hay series de boletos.
 */
void resumen(Bol *P, int n){
 
  cout << Empresa<string>::str_empresa << endl;
  cout << "Total de Boletos emitidos: " << Boleto::get_consecutivo() << endl;
  for(int k=0; k<n; ++k){ 
    cout << "Boletos emitidos para el evento (" << P->FechaBol << ") \"" 
    //cout << "Boletos emitidos para el evento (" << *((*((P+k)->V[0])).f) << ") \"" 
         << (P+k)->evento << "\": " << (P+k)->V.size() << endl;
  }
 
}
