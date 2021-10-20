#include <iostream>
using namespace std;
class Nodo {// un nodo se conforma un dato y una apuntador de tipo nodo
    char dato;
    Nodo *sig;
public:
    Nodo();

    void setDato(char x);

    void setSig(Nodo *Sig);

    char getDato();

    Nodo *getSig();

};

Nodo::Nodo() { //Inicializar los datos
    dato = '\0';
    sig = NULL;
}

void Nodo::setDato(char x) {
    this->dato = x;
}

void Nodo::setSig(Nodo *sig) {
    this->sig = sig;
}

char Nodo::getDato() {
    return dato;
}

Nodo *Nodo::getSig() {
    return sig;
}
class Pila{
    Nodo *tope;
public:
    Pila();
    ~Pila();
    int estaVacia();
    char getDato();
    void push(char x);
    void pop();
    //complementarios
    void mostrar();
    //...
    void signosDeAgrupacion();
};
Pila::Pila() {
    this->tope = NULL;
}
int Pila::estaVacia() {
    return tope == NULL;
}
char Pila::getDato() {
    if (estaVacia()){
        cout<<"Error pila vacia get dato";
        return -1;
    }
    return tope->getDato();

}
void Pila::push(char x) {
    Nodo * p = new Nodo();
    p->setDato(x);
    p->setSig(tope);
    tope = p;
}
void Pila::pop() {
    if (tope != NULL){
        Nodo *p;
        p = tope;
        tope = p->getSig();
        delete p;
    }
}
Pila::~Pila() {
    while (!estaVacia()){
        pop();
    }
}
void Pila::mostrar() {
    cout<<"Tope->";
    Pila paux;
    while (!estaVacia()){
        paux.push(getDato());
        cout<<getDato()<<"->";
        pop();
    }
    while (!paux.estaVacia()){
        push(paux.getDato());
        paux.pop();
    }
    cout<<"NULL";
}
void Pila::signosDeAgrupacion(){
    Pila paux;
    Pila analizador;
    while (!estaVacia()){
        paux.push(getDato());
        if (getDato() == ')' || getDato() == '}' || getDato() == ']'){
            analizador.push(getDato());
        }
        if (getDato() == '(' || getDato() == '{' || getDato() == '['){
            if (!analizador.estaVacia()){
                if (getDato() == '(' && analizador.getDato() == ')'){
                    analizador.pop();
                } if (getDato() == '[' && analizador.getDato() != ']'){
                    analizador.pop();
                } if (getDato() == '{' && analizador.getDato() != '}'){
                    analizador.pop();
                }
            }else
                cout<<"Falta cerrar el"<<getDato()<<"Linea 118";
        }
        pop();
    }

    while (!paux.estaVacia()){
        push(paux.getDato());
        paux.pop();
    }
    if (!analizador.estaVacia()){
        cout<<"Falto cerrar el "<<analizador.getDato();
        analizador.mostrar();
    }else
        cout<<"Todo correcto";

}

int main() {
    string cadena;
    Pila MainPila;
    cout<<"Inserte una cadena de caracteres\n";
    cin>>cadena;
    for (char i : cadena) {
        MainPila.push(i);//se insertan en forma de pila (1234) = )4321(
    }
//    MainPila.mostrar();
    MainPila.signosDeAgrupacion();

    return 0;
}
