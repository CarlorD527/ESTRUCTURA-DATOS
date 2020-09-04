#include <iostream>
#include<stdio.h>
#include <fstream> 
#include <string>
using namespace std;
void MenuInicio();
void MenuPrincipal();
void ConfigurarEstadoInicial(ofstream &config);
void VerConfiguracion(ifstream &config);



struct Automovil{


	string placa;
	int espacio;
	bool carro;
	bool moto;
	int nivel;
	int tiempo;
	int precio_pagar;
	Automovil *siguiente;
	
}aut;

void Registro_Automovil(Automovil *&primero);
void MostrarEstacionamiento(Automovil *&primero);
void Quitar_automovil(Automovil *primero);

struct Nivel{
	
	int nro_nivel;
	int nro_espacios_motos;
	int nro_espacios_autos;
	int precio_cada_minuto_auto;
	int precio_cada_minuto_moto;
	
}niv[10];

struct Estacionamiento{
		Nivel niv;
		int numero_niveles_estacionamiento;
}est;


int main(){
	
		
			
		MenuInicio();
		
		
		system("color F0");
	
		
		
		return 0;
	
}

void MenuInicio(){
	
		system("color F0");
		cout<<"********************************************************"<<endl;
		cout<<"*         S I S T E M A    D E     P A R Q U E O       *"<<endl;
		cout<<"*	               Bienvenido :D!                  *"<<endl;
		cout<<"********************************************************"<<endl;
	
		
		system("pause");
		
		system("cls");
		MenuPrincipal();
	
			
}
void Quitar_Automovil(Automovil *&primero){
	
	Automovil *actual = new Automovil();
	Automovil *anterior = new Automovil();
	
	anterior = NULL;
	actual = primero;
	
	if(primero != NULL){
				
				primero = primero->siguiente;
				anterior = actual;
				delete(anterior);
			
			cout<<"AUTOMOVIL REMOVIDO DEL ESTACIONAMIENTO EXITOSAMENTE."<<endl;;
			
	}else{
		
		cout<<"EL ESTACIONAMIENTO SE ENCUENTRA VACIO ! ! ! "<<endl;
	}	

	
}


void Registro_Automovil(Automovil *&primero){
	
	string plac;
	int nro=0;
	int espa=0;
	int tiem=0;
	bool carr=false;
	bool mot=false;
	int precio=0;
	int ni=0;
	string tipo;
	int cantidad=0;
	bool disponible=true;
	
	Automovil *nuevo_automovil = new Automovil();
	
	cout<<"<---- INGRESO DE AUTOMOVILES AL ESTACIONAMIENTO ------>"<<endl;
	cout<<"INGRESE EL TIPO DE AUTOMOVIL QUE ES [CARRO|MOTO]: "<<endl;
	cin.ignore();
	getline(cin,tipo);

	if(tipo== "carro" || tipo== "CARRO"){
		
	carr = true;
	
	cout<<"INGRESE EL NIVEL DONDE ESTARA SU VEHICULO [AUTO]: "<<endl;
	cin>>ni;

	cout<<"INGRESE EL TIEMPO [MINUTOS] QUE HARA USO DEL ESTACIONAMIENTO: "<<endl;
	cin>>tiem;
	
	for(int j=0;j<est.numero_niveles_estacionamiento;j++){
	
		if(niv[j].nro_nivel==ni){
			precio = tiem * niv[j].precio_cada_minuto_auto;
		}
	
	}
	cout<<"INGRESE LA PLACA DEL AUTO: "<<endl;
	cin.ignore();
	getline(cin,plac);	

	
	nuevo_automovil->carro = carr;
	nuevo_automovil->nivel = ni;
	nuevo_automovil->placa = plac;
	nuevo_automovil->precio_pagar = precio;
	nuevo_automovil->tiempo=tiem;
	
	nuevo_automovil->siguiente = primero;
	primero = nuevo_automovil;	
	
	}
	
	if(tipo== "moto "|| tipo== "moto"){
		
	carr = false;
	mot =true;

	cout<<"INGRESE EL NIVEL DONDE ESTARA SU VEHICULO [MOTO]: "<<endl;
	cin>>ni;

	cout<<"INGRESE EL TIEMPO [MINUTOS] QUE HARA USO DEL ESTACIONAMIENTO: "<<endl;
	cin>>tiem;

	for(int j=0;j<est.numero_niveles_estacionamiento;j++){
	
		if(ni==niv[j].nro_nivel){
	
			precio = tiem * niv[j].precio_cada_minuto_moto;
		}
	
	}
	cout<<"INGRESE LA PLACA DE LA MOTO: "<<endl;
	cin.ignore();
	getline(cin,plac);	

	nuevo_automovil->moto = mot;
	nuevo_automovil->nivel = ni;
	nuevo_automovil->placa = plac;
	nuevo_automovil->precio_pagar = precio;
	nuevo_automovil->tiempo=tiem;
	nuevo_automovil->siguiente = primero;
	primero = nuevo_automovil;	
	
	}
	
}
	
void MostrarEstacionamiento(Automovil *&primero){
	int nro=0;
	
	Automovil *aux = new Automovil();
	
	aux = primero;
	
	if(primero != NULL){
		
		while(aux != NULL){
			cout<<"<------------------------------------------------->"<<endl;
			cout<<"[- - A U T O M O V I L  nro ["<<nro+1<<"]- -]"<<endl;
			cout<<"|-------------- PLACA  --------------|"<<endl;
			cout<<"                "<<aux->placa<<endl;
			cout<<"|-------------- TIEMPO  -------------|"<<endl;
			cout<<"                "<<aux->tiempo<<endl;
			cout<<"|-------------- NIVEL  --------------|"<<endl;
			cout<<"                "<<aux->nivel<<endl;
			cout<<"|-------- PRECIO PAGAR en [S/] ------|"<<endl;
			cout<<"                 "<<aux->precio_pagar<<endl;
		
		
			aux = aux->siguiente;
			nro++;
		}
	}else{
		
		cout<<"EL ESTACIONAMIENTO ESTA VACIO ! ! ! "<<endl;
	}	


}

void ConfigurarEstadoInicial(ofstream &config){

		system("color F0");
		system("cls");
		int opc=0,i=0,opc2=0,opc3=0,opc5=0,opc6=0,nivel=0,opc7=0;
		
		
		
		do{
		
		cout<<"<- - - C O N F I G U R A C I O N   I N I C I A L - - ->"<<endl;
		cout<<"1. Configurar niveles [INGRESAR|QUITAR niveles]"<<endl;
		cout<<"2. Configurar el numero de espacios por nivel y tarifas"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"--> ";
		cin>>opc;
		
			config.open("config.txt",ios::out|ios::app);
						
		switch (opc){
				
			case 1:
					system("cls");
					cout<<"<- CONFIGURACION DE NIVELES ->"<<endl;
					cout<<"--------------------------"<<endl;
				    cout<<"1. Ingresar niveles "<<endl;
				    cout<<"2. Borrar Niveles "<<endl;
				    cout<<"3. Salir "<<endl;
				    cout<<"ingrese una opcion -> "<<endl;;
				    cout<<"--------------------------"<<endl;
				    cin>>opc5;
		
				    if(opc5 == 1){
					
					do{
							
							
						est.numero_niveles_estacionamiento++;
						
						cout<<" Nivel ingresado :D "<<endl;
						niv[i].nro_nivel = i;
						i++;
						cout<<" Actualmente hay ["<<est.numero_niveles_estacionamiento<<" NIVELES] "<<endl;
						cout<<" Desea INGRESAR otro nivel ? [Escriba 1=Si , 0=No]"<<endl;
						cin>>opc2;
					
					}while(opc2!=0);
						
	
						system("cls");
						
						
					}else{
						
						do{
						est.numero_niveles_estacionamiento--;
						cout<<" Nivel eliminado :D "<<endl;
						cout<<" Actualmente hay ["<<est.numero_niveles_estacionamiento<<" NIVELES] "<<endl;
						cout<<" Desea BORRAR otro nivel ? [Escriba 1=Si , 0=No]"<<endl;
						cin>>opc6;
						if(est.numero_niveles_estacionamiento ==0){
							cout<<"No quedan mas niveles en el estacionamiento :("<<endl;
							break;
						}else{
							break;
						}
						
					}while(opc6!=0);
							
							
					}
					config<<"NIVELES: "<<est.numero_niveles_estacionamiento<<" | ";
					
				break;
				
			case 2:
				
					
					system("cls");
					cout<<"<- CONFIGURACION DE ESPACIOS POR NIVEL ->"<<endl;
					cout<<"<---- LISTA - TOTAL - NIVELES ---->"<<endl;
					for(int i=0;i<est.numero_niveles_estacionamiento;i++){
				
					cout<<"NIVEL: ["<<niv[i].nro_nivel<<"] "<<endl;
						}
					cout<<"INGRESE EL NIVEL QUE QUIERE CONFIGURAR: "<<endl;
					cin>>nivel;
					
				for(int j=0;j<est.numero_niveles_estacionamiento;j++){
					
					if(nivel==niv[j].nro_nivel){
									system("cls");
								cout<<"Usted esta modificando el nivel ["<<niv[j].nro_nivel<<"] . . ."<<endl;	
									
								cout<<"----------------- N I V E L ["<<niv[j].nro_nivel<<"]------------------"<<endl;
							
								cout<<"Ingrese la capacidad de autos para el nivel "<<niv[j].nro_nivel<<" :"<<endl;
								cin>>niv[j].nro_espacios_autos;
								config<<"NIVEL ["<<niv[j].nro_nivel<<"] -> ";
								
								config<<"Espacios autos: "<<niv[j].nro_espacios_autos;
								cout<<"Ingrese la capacidad de motos para el nivel "<<niv[j].nro_nivel<<" :"<<endl;
								
								cin>>niv[j].nro_espacios_motos;
								config<<"Espacios motos: "<<niv[j].nro_espacios_motos<<" ";
							
								
								cout<<"Ingrese el precio x minuto [SOLES] de los autos: "<<endl;
								cin>>niv[j].precio_cada_minuto_auto;
								config<<"Precio x minuto [autos]: "<<niv[j].precio_cada_minuto_auto<<" ";
								
								cout<<"Ingrese el precio x minuto [SOLES] de las motos: "<<endl;
								cin>>niv[j].precio_cada_minuto_moto;
								config<<"Precio x minuto [motos]: "<<niv[j].precio_cada_minuto_moto<<" |";
								cout<<"-------------------------------------------------"<<endl;
								
					}
				}
					
						break;
			default:
							
					
							config.close();
							break;
		}
		
				config.close();
		}while(opc!=3);
}


void VerConfiguracion(ifstream &Lec){
		int i=0;
	
		 
		cout<<"********************************************************"<<endl;
		cout<<"*      C O N F I G U R A C I O N      A C T U A L      *"<<endl;
		cout<<"*	                                                  *"<<endl;
		cout<<"********************************************************"<<endl;
		
		
		cout<<"----------------------------------------------------"<<endl;
	
   		
		cout<<"NUMERO TOTAL DE NIVELES DEL ESTACIONAMIENTO: "<<est.numero_niveles_estacionamiento<<endl;
		
		cout<<"<------------- NIVELES ----------------->"<<endl;

		for(int j=0;j<est.numero_niveles_estacionamiento;j++){
			
		cout<<"<------ NIVEL "<<niv[j].nro_nivel<<"----->"<<endl;
		cout<<"Nro de autos totales disponibles para este nivel: "<<niv[j].nro_espacios_autos<<endl;
		cout<<"Nro de motos totales disponibles para este nivel: "<<niv[j].nro_espacios_motos<<endl;
		cout<<"El precio en soles x minuto en este nivel para los autos es: "<<niv[j].precio_cada_minuto_auto<<endl;
		cout<<"El precio en soles x minuto en este nivel para las motos es: "<<niv[j].precio_cada_minuto_moto<<endl;
		cout<<"<-----------------------------------------"<<endl;
		
		}
	
			
			system("pause");

}

void MenuPrincipal(){
		
	Automovil *primero = NULL;	
	int opc=0,opc1=0;	
	
	ofstream Esc; 
	ifstream Lec;	
	system("color F0");
	
	do{
	
	cout<<"********************************************************"<<endl;
	cout<<"*         S I S T E M A    D E     P A R Q U E O       *"<<endl;
	cout<<"*	              Menu principal                     *"<<endl;
	cout<<"********************************************************"<<endl;
	
		cout<<"1. Configurar estado inicial del parqueo"<<endl;
		cout<<"2. Ver configuracion del estacionamiento"<<endl;
		cout<<"3. Ingresar vehiculo"<<endl;
		cout<<"4. Ver estado actual de parquederos"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"ingrese una opcion -> ";
		cin>>opc;
		
		
		switch (opc){
			
			case 1:
				
				ConfigurarEstadoInicial(Esc);
				break;
			case 2:
				VerConfiguracion(Lec);	
				break;
			case 3:
			
				do{
				
				
				
				Registro_Automovil(primero);
				cout<<"Desea registrar otro automovil? Si=1 | No=0 "<<endl;
				cin>>opc1;
				}while(opc1!=0);
					system("cls");
				break;
			
			case 4:
				MostrarEstacionamiento(primero);
				break;
				
		}
		
	}while(opc!=4);
}









