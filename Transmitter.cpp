#using < System.dll >
#include <iostream>
#include <string>
using namespace std;

char arreglo[5]; 
int contadorarreglo = 0; 

template<class TIPO> class lista;

template<class TIPO>
class nodo {
public:
	nodo(TIPO v, nodo<TIPO> *sig = NULL)
	{
		valor = v;
		siguiente = sig;
	}

private:
	TIPO valor;
	nodo<TIPO> *siguiente;

	friend class lista<TIPO>;
};

template<class TIPO>
class lista {
public:
	lista() { actual = NULL; }
	~lista();

	void Insertar(string v);
	void Borrar(TIPO v);
	string Codigo(char l);
	bool ListaVacia() { return actual == NULL; }
	void Mostrar();
	void Siguiente();
	bool Actual() { return actual != NULL; }
	TIPO ValorActual() { return actual->valor; }

private:
	nodo<TIPO> *actual;
};

template<class TIPO>
lista<TIPO>::~lista()
{
	nodo<TIPO> *Nodo;

	// Mientras la lista tenga más de un nodo
	while (actual->siguiente != actual) {
		// Borrar el nodo siguiente al apuntado por lista
		Nodo = actual->siguiente;
		actual->siguiente = Nodo->siguiente;
		delete Nodo;
	}
	// Y borrar el último nodo
	delete actual;
	actual = NULL;
}

template<class TIPO>
void lista<TIPO>::Insertar(string v)
{
	nodo<TIPO> *Nodo;

	// Creamos un nodo para el nuevo valor a insertar
	Nodo = new nodo<string>(v);

	// Si la lista está vacía, la lista será el nuevo nodo
	// Si no lo está, insertamos el nuevo nodo a continuación del apuntado
	// por lista
	if (actual == NULL) actual = Nodo;
	else Nodo->siguiente = actual->siguiente;
	// En cualquier caso, cerramos la lista circular
	actual->siguiente = Nodo;
}

template<class TIPO>
void lista<TIPO>::Borrar(TIPO v)
{
	nodo<TIPO> *Nodo;

	Nodo = actual;

	// Hacer que lista apunte al nodo anterior al de valor v
	do {
		if (actual->siguiente->valor != v) actual = actual->siguiente;
	} while (actual->siguiente->valor != v && actual != Nodo);
	// Si existe un nodo con el valor v:
	if (actual->siguiente->valor == v) {
		// Y si la lista sólo tiene un nodo
		if (actual == actual->siguiente) {
			// Borrar toda la lista
			delete actual;
			actual = NULL;
		}
		else {
			// Si la lista tiene más de un nodo, borrar el nodo  de valor v
			Nodo = actual->siguiente;
			actual->siguiente = Nodo->siguiente;
			delete Nodo;
		}
	}
}

template<class TIPO>
string lista<TIPO>::Codigo(char l)
{
	nodo<TIPO> *Nodo;

	Nodo = actual;

	int c = (int)l - 97;


	for (int x = 0; x<c; x++)
	{
		Nodo = Nodo->siguiente;
	}

	return Nodo->valor;
}

template<class TIPO>
void lista<TIPO>::Mostrar()
{
	nodo<TIPO> *Nodo = actual;

	do {
		cout << Nodo->valor << "-> ";
		Nodo = Nodo->siguiente;
	} while (Nodo != actual);

	cout << endl;
}

template<class TIPO>
void lista<TIPO>::Siguiente()
{
	if (actual) actual = actual->siguiente;
}



using namespace System;
using namespace System::IO::Ports;

int main()
{
	lista<string> cLista;

	cLista.Insertar(".-");     //a
	cLista.Insertar("--..");  //z
	cLista.Insertar("-.--"); //y
	cLista.Insertar("-..-");  //x
	cLista.Insertar(".--");  //w
	cLista.Insertar("...-");  //v
	cLista.Insertar("..-");  //u
	cLista.Insertar("-");   //t
	cLista.Insertar("...");   //s
	cLista.Insertar(".-.");   //r
	cLista.Insertar("--.-");  //q
	cLista.Insertar(".--.");  //p
	cLista.Insertar("---");   //o
	cLista.Insertar("-.");   //n
	cLista.Insertar("--");    //m
	cLista.Insertar(".-..");   //l
	cLista.Insertar("-.-");   //k
	cLista.Insertar(".---");   //j
	cLista.Insertar("..");   //i
	cLista.Insertar("....");   //h
	cLista.Insertar("--.");     //g
	cLista.Insertar("..-.");   //f
	cLista.Insertar(".");       //e
	cLista.Insertar("-..");     //d
	cLista.Insertar("-.-.");    //c
	cLista.Insertar("-...");   //b


	String^ answer;
	String^ portName;
	int baudRate = 9600;
	Console::WriteLine("Nombre del puerto");
	portName = Console::ReadLine();
	// arduino settings
	SerialPort^ arduino;
	arduino = gcnew SerialPort(portName, baudRate);
	// open port
	try
	{
		arduino->Open();

		do
		{
			// ask on or off
			Console::WriteLine("Escriba la letra que desea emitir");
			contadorarreglo = 0;
			// get answer
			answer = Console::ReadLine();
			//check that user typed one of the options
			int delaypalabra=0; 
			for (int i = 0; i < 4; i++) {
				if (answer[i] ==  'a') {
					string codi = cLista.Codigo('a');
					for (int i = 0; i < 2; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}

					arduino->WriteLine("2"); 
				}
				else if (answer[i] == 'b'){
					string codi = cLista.Codigo('b');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'c') {
					string codi = cLista.Codigo('c');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'd' ) {
					string codi = cLista.Codigo('d');
					for (int i = 0; i < 3; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'e') {
					string codi = cLista.Codigo('e');
					for (int i = 0; i < 1; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'f'){
					string codi = cLista.Codigo('f');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'g') {
					string codi = cLista.Codigo('g');
					for (int i = 0; i < 3; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'h') {
					string codi = cLista.Codigo('h');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'i') {
					string codi = cLista.Codigo('i');
					for (int i = 0; i < 2; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'j') {
					string codi = cLista.Codigo('j');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'k') {
					string codi = cLista.Codigo('k');
					for (int i = 0; i < 3; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'l') {
					string codi = cLista.Codigo('l');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'm') {
					string codi = cLista.Codigo('m');
					for (int i = 0; i < 2; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'n') {
					string codi = cLista.Codigo('n');
					for (int i = 0; i < 2; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'o') {
					string codi = cLista.Codigo('o');
					for (int i = 0; i < 3; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'p') {
					string codi = cLista.Codigo('p');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'q') {
					string codi = cLista.Codigo('q');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'r') {
					string codi = cLista.Codigo('r');
					for (int i = 0; i < 3; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 's') {
					string codi = cLista.Codigo('s');
					for (int i = 0; i < 3; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 't') {
					string codi = cLista.Codigo('t');
					for (int i = 0; i < 1; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'u') {
					string codi = cLista.Codigo('u');
					for (int i = 0; i < 3; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'v') {
					string codi = cLista.Codigo('v');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'w') {
					string codi = cLista.Codigo('w');
					for (int i = 0; i < 3; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'x') {
					string codi = cLista.Codigo('x');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'y') {
					string codi = cLista.Codigo('y');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else if (answer[i] == 'z') {
					string codi = cLista.Codigo('z');
					for (int i = 0; i < 4; i++) {
						if (codi[i] == '.') {
							arduino->WriteLine("1");

						}
						else if (codi[i] == '-') {
							arduino->WriteLine("0");
						}

					}
					arduino->WriteLine("2");
				}
				else
					Console::WriteLine(answer + " no es válido");
				// ask user if he wants to contineu
			}
			Console::WriteLine("Emitir otra letra? si/no");
			// get answer
			answer = Console::ReadLine();
			// clear the screen
			Console::Clear();
		} while (String::Compare(answer, "si") == 0);
		// close port to arduino
		arduino->Close();
	}
	catch (IO::IOException^ e)
	{
		Console::WriteLine(e->GetType()->Name + ": Puerto no listo");
	}
	catch (ArgumentException^ e)
	{
		Console::WriteLine(e->GetType()->Name + ": Nombre incorrecto de puerto, debe empezar como COM/com");
	}
	// end program
	Console::Write("Presione enter para cerrar el programa");
	Console::Read();
	return 0;
}
