#ifndef _BOLETO_
#define _BOLETO_

class Boleto;
class Fecha; ///Movi de donde estaba y lo 
class Bol {  
public:
  Fecha *FechaBol;//3
  void set_fecha_Bol(Fecha *FechaBol){  //3
    this->FechaBol=FechaBol;            //3
  }//3
//  Fecha get_fecha_Bol();//3
  //3

  string evento;
  void set_evento(string);
  vector<Boleto*> V;
};//end class Bol


template <typename T> class Empresa{
public:
  static T str_empresa;
};//end template Empresa
template <typename T>
T Empresa<T>::str_empresa="UPIITA S.A. de C.V.";

// 3 aqui estaba la leyenda de class Fecha;
class Producto{
public:
  string NombreDEmpresa;
  //Fecha del evento para el cual se vende el Producto 
  //(en este caso un Boleto)
  Fecha *f;
  Producto():NombreDEmpresa(Empresa<string>::str_empresa){ }
  Producto(Fecha *fech):f(fech), 
  NombreDEmpresa(Empresa<string>::str_empresa){ }
  void set_fecha(Fecha *f){
    this->f=f;
  }
};//end class Producto

class Boleto : public Producto{
  static int consecutivo;
public:
  int numdbol;
  Boleto(Fecha *F);
  static int get_consecutivo(){
    return consecutivo;
  }
};//end class Boleto

class Fecha{
public:
  int dia, mes, anio;
  Fecha(int a, int b, int c):dia(a),mes(b),anio(c){ }
  friend ostream& operator<<(ostream& out, Fecha& f);
};//end class Fecha





//vector<string> MItem;
//template <typename T> class MENU{
//public:
//  static vector<T> ElemDM; //Pensado para ser un vector<string>
//};
//template <typename T>
//T vector<T>::ElemDM=MItem;

#endif /* _BOLETO_ */
