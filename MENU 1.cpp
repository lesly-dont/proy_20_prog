#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <math.h> 
#include <fstream>
#define km 0.6214
#define milla 1.6093
#define metro 39.3701
#define pulgada 0.0254
#define libra 39.3701
#define kilo 2.20462
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
using namespace std;
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos); } 
	  // void de funcion para el case 1o
      void con();
      void con(){
	system("cls");
int a,b,c,d,e,f,p,g,x,centena1,centena2;
int unidad,decena,unidad1,decena1,unidad2,decena2,unidad3,decena3;
char z;
cout<<("***********Multiplicacion Manual*****************  ");
cout<<("\n\nIngrese primer Cantidad: ");
cin>>a;
cout<<("\nIngrese segunda Cantidad: ");
cin>>b;
int r=a*b;
gotoxy(26,10);cout<<a;
gotoxy(18,12);cout<<("X");
gotoxy(26,12);cout<<b;
gotoxy(20,13);cout<<("___________");
	unidad = a%10; a /= 10;
	decena = a%10; a /= 10;
    unidad1 = b%10; b /= 10;
	decena1 = b%10; b /= 10;
c=unidad1*unidad;
	unidad2 = c%10; c /= 10;
	decena2 = c%10; c /= 10;
	centena1= c%10; c /= 10;	
d=unidad1*decena+decena2;
gotoxy(25,15);cout<<d<<unidad2;
e=decena1*unidad;
	unidad3 = e%10; e /= 10;
	decena3 = e%10; e /= 10;
	centena2 = e%10; e /= 10;	
f=decena1*decena+decena3;
gotoxy(24,16);cout<<f<<unidad3;
gotoxy(20,17);cout<<("____________");
gotoxy(24,18);cout<<r;
gotoxy(24,22);cout<<(" Desea repetir (s/n): ");
cin>>z;
if (z=='s'){
 con();
}else{
	if(z=='n'){
		system("cls");
	}	
}
}
 // cajero automatico					
double saldo(double retiro,double deposito,double saldot)
{
    system("cls");
    saldot=saldot+deposito-retiro;
    return saldot;         
} 
double deposit(double saldot)
{
     
    double dep=0;
    char sn;
    do
    {
LDeposito:
    system("cls");
    cout<<"Ingrese cantidad a Depositar: ";
    cin>>dep;
     
    while(dep<=0)
    {
        cout<<"Desea ingresar un valor valido s/S n/N: ";
        cin>>sn;
        if(sn=='S'||sn=='s')
            goto LDeposito;
        else
            exit(0);
    }
    saldot=saldo(0,dep,saldot);
    cout<<"Desea realizar otro deposito s/S n/N: ";cin>>sn;
    }while(sn=='s'||sn=='S');
return saldot;
}
double retiro(double saldot)
{
    double retir=0;
        char sn;
        system("cls");
        if (saldot==0)
        {cout<<"Ud. no cuenta con saldo \n";
            cout<<"Desea realizar otra operacion s/S n/N: ";cin>>sn;
            if(sn=='S'||sn=='s')
            {
            system("cls");
            }
            else
            exit(0);        
        }
        do
        {
            LRetir:
            system("cls");
            cout<<"Ingrese cantidad a Retirar: ";
            cin>>retir;
            while(saldot<retir)
            {   
                cout<<"Ud. no cuenta con saldo suficiente para hacer ese retiro\n";
                goto reintentar;
            }
            while(retir<=0)
            {
            reintentar:
                cout<<"Desea ingresar un valor valido s/S n/N: ";
                cin>>sn;
                if(sn=='S'||sn=='s')
                    goto LRetir;
                else
                    exit(0);    
            }
            saldot=saldo(retir,0,saldot);
            cout<<"Desea realizar otro retiro s/S n/N: ";cin>>sn;
        }while(sn=='s'||sn=='S');
return saldot;
}
double Option(int option1,double saldot)
{
    switch(option1)
    {
    case 1:saldot=deposit(saldot);break;
    case 2:saldot=retiro(saldot);break;
    case 3: {
            saldot=saldo(0,0,saldot);
            cout<<"Usted cuenta con :"<<saldot<<" QUETZALES\n";
            }break;
    case 4:{system("cls");cout<<"GRACIAS POR UTILIZAR MI SISTEMA --LESLY QUEVEDO--\n ";}break;    
    }         
return saldot;
}
 //numero mayor o menor
 int menor(int a,int b,int c)
{
    int m;
    if(a<b)
        if(a<c)
            m=a;
        else
            m=c;
    else
        if(b<c)
            m=b;
        else
            m=c;
return m;
}
int mayor(int a,int b,int c)
{
    int n;
    if(a>b)
        if(a>c)
            n=a;
        else
            n=c;
    else
        if(b>c)
            n=b;
        else
            n=c;
return n;
}
 // void movimiento de punto
 void OcultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle (STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon,&cci );	
}
class Punto{
	int x,y;
	public:
		Punto(int _x, int _y):x(_x),y(_y){}
		void pintar ();
		void borrar ();
		void mover ();
};
void Punto::pintar(){
	system ("color F2");
	gotoxy(25,1);	cout<< "MOVER UN PUNTO CON TECLAS EN LA PANTALLA"<<endl;
	gotoxy(x,y); 
	cout<< "*"<<endl;
}
void Punto::borrar(){
	gotoxy(x,y);
	cout<< " "<<endl;
}
void Punto::mover(){
char opcion;
while(opcion!='z'){
 system("cls");
 gotoxy(x,y);
pintar();
 opcion=getch();
 switch(opcion){
 case ARRIBA: y--; 
 y > 4;
 break;
 case ABAJO: y++;
 y+3 < 33;
 break;
 case IZQUIERDA: x--;
 x > 3;
 break;
 case DERECHA: x++;
 x+6 < 77;
 break;
 }
}		
}   
 //conversiones     
float km_mi(float cantidad){
	return cantidad*km;
}
float mi_km(float cantidad){
	return cantidad*milla;
}
float m_pul(float cantidad){
	return cantidad*metro;
}
float pul_m(float cantidad){
	return cantidad/metro;
}
float lb_kil(float cantidad){
	return cantidad/kilo;
}
float kil_lb(float cantidad){
	return cantidad*kilo;
}
int main()
{
    int opcion;
    do {
        system("cls");    
      gotoxy(30,3);
        cout << "************MENU DE OPCIONES************\n" << endl;
        cout << "1. Suma, Resta, Multiplicacion y division de dos numeros " << endl;
        cout << "2. Numero par o impar" << endl;
        cout << "3. conversiones" << endl;
        cout << "4. Palabra o numero palindromo" << endl;
        cout << "5. Numeros arabicos a romanos" << endl;
        cout << "6. Numeros a letras" << endl;
        cout << "7. Numeros a letras con decimal" << endl;
        cout << "8. una tabla de multiplicar" << endl;
        cout << "9. Tablas del 1 al 10" << endl;
        cout << "10. Multiplicacion Manual de dos numeros" << endl;
        cout << "11. conversion de numero decimales a binarios" << endl;
        cout << "12. conversion de numeros decimales a hexadecimales" << endl;
        cout << "13. Figuras geometricas basicas" << endl;
        cout << "14. Mover un punto en toda la pantalla" << endl;
        cout << "15. Simulacion de un cajero automatico" << endl;
        cout << "16. Calcular la hipotenusa" << endl;
        cout << "17. Signo zodiacal" << endl;
        cout << "18. Calculo de horas trabajadas" << endl;
        cout << "19. Simulacion de creacion de matricula universitaria" << endl;
        cout << "20. Calculo de dias por mes y año" << endl;
        cout << "21. SALIR" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion; 
        switch (opcion) {
            case 1:{
            	 system("cls");
int opcion;
float x=1;
float y=1;
float resultado;
cout << "Que operacion desea realizar: Suma [1] Resta [2] Multiplicacion [3] Division [4]." << endl;
cin >> opcion;
cout << "Ingrese el primer numero: ";
cin >> x;
cout << "Ingrese el segundo numero: ";
cin >> y;
if (opcion==1){
    resultado = x+y;}
if (opcion==2){
    resultado = x-y;}
if (opcion==3){
    resultado = x*y;}
if (opcion==4){
   resultado = x/y;}
cout << "\n El resultado es:  "<<resultado<<endl;
system("PAUSE");
 break;}
            case 2:{
            	 system("cls");
    int num;
    cout<< "\n   Introduzca un numero entero: ", 163 ;
    cin>> num ;
    if ( num % 2 == 0 )
        cout<< "\n   ES PAR" ;
    else
        cout<<"\n   ES IMPAR" ;
    break;
} 
            case 3:
system("cls");
int op;
float cantidad;
cout<<"CONVERTIR\n 1.-km a millas\n 2.-millas a km\n 3.-metros a pulgadas\n 4.-pulgadas a metros\n 5.-libras a kilos\n 6.-kilos a libras\n Seleccione la Opcion: ";
cin>>op;
cout<<"\nINTRODUCE LA CANTIDAD:   ";
cin>>cantidad;
switch(op){
	
	case 1:
		cout<<cantidad<<"  KM   EQUIVALE  "<<km_mi(cantidad)<<"  MILLAS\n  ";
		system("PAUSE");
		break; 
	case 2:
	    cout<<cantidad<<"  MILLAS  EQUIVALE  "<<mi_km(cantidad)<<"  KM\n"; 	
	system("PAUSE");
	break;
	case 3:
		cout<<cantidad<<"  METROS  EQUIVALE  "<<m_pul(cantidad)<<"  PULGADAS\n";
			system("PAUSE");
		break;
	case 4:
		cout<<cantidad<<"  PULGADAS EQUIVALE  "<<pul_m(cantidad)<<"  METROS\n";
			system("PAUSE");
		break;
	case 5:
		cout<<cantidad<<"  LIBRAS EQUIVALE"<<lb_kil(cantidad)<<"  KILOS\n";
			system("PAUSE");
		break;
	case 6:
		cout<<cantidad<<"  KILOS EQUIVALE "<<kil_lb(cantidad)<<"  LIBRAS";
			system("PAUSE");
		break;
	default:
		cout<<"opcion introducida incorrecta";
}
break;
            case 4:
            	system("cls");
int opi;
cout<<"INGRESE OPCION \n 1.NUMERO PALINDROMO\n 2.PALABRA PALINDORMA\n ";
cin>>opi;
switch(opi){
case 1:
int numero,p,s,t,c,m;
cout<<"ingrese un numero:     ";
cin>>numero;
p=numero%10;
s=p/10;
c=s/10;
m=p*100+t*10+c;
if (m=numero)
{
cout<<"El Numero es Palindromo\n";
}
else
{
cout<<"El Numero no es Palindromo\n";
} system ("pause"); break; 
case 2:
 int I = 0;
 string palabra;
 cout<<"ingrese una palabra:    ";
 cin >> palabra;
 int J = palabra.length() - 1;
 int mitad = J / 2;
 while(palabra[I] == palabra[J]){
  if(mitad == I){
   cout << "Es palindromo\n";
   break;
  }
 J--;
 I++;
 }
 if(mitad != I)
 cout << "No es palindromo\n";
} system ("pause");break;
                          break;
            case 5:
            	system("cls");
            	int num, a;
cout << "Transformacion de numero arabigos a romanos" << endl;
cout << "Escribe el numero a convertir, que sea mayor o igual a 1 y menor o igual a 1000" << endl;
cin >> a;
num=a;
while(num!=0)
{
	if (num>999 && num<= 1000)
{
cout << "M";
num = num -1000;
}
else if(num <1000 && num>=900)
{
cout << "CM";
num = num - 900;
}
else if(num < 900 && num>500)
{
cout << "D";
num = num - 500;
}
else if (num == 500)
{
cout << "D";
num = num -500;
}
else if (num<500 && num>= 400)
{
cout << "CD";
num = num - 400;
}
else if (num<400 && num >99)
{
cout << "C";
num = num -100;
}
else if (num< 100 && num>89)
{
cout << "XC";
num = num - 90;
}
else if (num< 90 && num>59)
{
cout << "L";
num = num - 50;
}
else if(num<60 && num >50)
{
cout << "L";
num = num - 50;
}
else if (num ==50)
{
cout << "L";
num = num -50;
}
else if(num<50 && num>39)
{
cout << "XL";
num = num - 40;
}
else if(num< 40 && num> 10)
{
cout << "X";
num = num - 10;
}
else if(num == 10)
{
cout << "X";
num = num -10;
}
else if(num==9)
{
cout << "IX";
num = num - 9;
}
else if(num<=8 && num>=6)
{
cout << "V";
num = num - 5;
}
else if (num == 5)
{
cout << "V";
num = num - 5;
}
else if (num == 4)
{
cout << "IV";
num = num - 4;
}
else if (num<= 3 && num>=1)
{
cout << "I";
num = num - 1;
}
}
cout << "      <---- RESULTADO" << endl;
system("pause");
            	break;
            	case 6:{
    system("cls");
	int x;
    cout<<"INGRESA UN NUMERO DEL 1 AL 999\n";
    cout<<"ingrese un numero"<<endl;
    cin>>x;
if((x<1)||(x>999)) 
cout<<"INGRESA UN NUMERO DEL 1 AL 999\n";
else
    {
        if(x>=900)   {cout<<"NOVECIENTOS " ;x=x-900;}
       else if(x>=800)   {cout<<"OCHOCIENTOS " ;x=x-800;}
       else if(x>=700)   {cout<<"SETECIENTOS " ;x=x-700;}
       else if(x>=600)   {cout<<"SEISCIENTOS " ;x=x-600;}
       else if(x>=500)   {cout<<"QUINIENTOS "  ;x=x-500;}
       else if(x>=400)   {cout<<"CUATROCIENTOS "   ;x=x-400;}
       else if(x>=300)   {cout<<"TRESCIENTOS " ;x=x-300;}
       else if(x>=200)   {cout<<"DOSCIENTOS "  ;x=x-200;}
       else if(x>100)    {cout<<"CIENTO "  ;x=x-100;}
       else if(x==100)  {cout<<"CIEN"     ;x=x-100;}
        if(x>90) {cout<<"NOVENTA Y "   ;x=x-90; }
            if(x==90)   {cout<<"NOVENTA"  ;x=x-90; }  
            if(x>80) {cout<<"OCHENTA Y "   ;x=x-80; }
            if(x==80)   {cout<<"OCHENTA"  ;x=x-80; }
            if(x>70) {cout<<"SETENTA Y "   ;x=x-70; }
            if(x==70)   {cout<<"SETENTA"  ;x=x-70; }
            if(x>60) {cout<<"SESENTA Y "   ;x=x-60; }
            if(x==60)   {cout<<"SESENTA"  ;x=x-60; }
            if(x>50) {cout<<"CINCUENTA Y " ;x=x-50; }
            if(x==50)   {cout<<"CINCUENTA"    ;x=x-50; }
            if(x>40) {cout<<"CUARENTA Y "  ;x=x-40; }
            if(x==40)   {cout<<"CUARENTA" ;x=x-40; }
            if(x>30) {cout<<"TREINTA Y "   ;x=x-30; }
            if(x==30)   {cout<<"TREINTA"  ;x=x-30; }
            if(x>20) {cout<<"VEINTI"       ;x=x-20; }
            if(x==20)   {cout<<"VEINTE"       ;x=x-20; }
        if(x>=16)    {cout<<"DIECI"        ;x=x-10; }
       else if(x==15)   {cout<<"QUINCE"       ;x=x-15; }
       else if(x==14)   {cout<<"CATORCE"  ;x=x-14; }
       else if(x==13)   {cout<<"TRECE"        ;x=x-13; } 
       else if(x==12)   {cout<<"DOCE"     ;x=x-12; }
       else if(x==11)   {cout<<"ONCE"     ;x=x-11; }
       else if(x==10)   {cout<<"DIEZ"     ;x=x-10; }      
        if(x==9)    {cout<<"NUEVE"        ;x=x-9;  }
        if(x==8)    {cout<<"OCHO"     ;x=x-8;  }
        if(x==7)    {cout<<"SIETE"        ;x=x-7;  }
            if(x==6)    {cout<<"SEIS"     ;x=x-6;  }
       else if(x==5)    {cout<<"CINCO"        ;x=x-5;  }
       else if(x==4)    {cout<<"CUATRO"       ;x=x-4;  }
       else if(x==3)    {cout<<"TRES"     ;x=x-3;  }
       else if(x==2)    {cout<<"DOS"      ;x=x-2;  }
       else if(x==1)    {cout<<"UNO"      ;x=x-1;  }
       }
    cout<<endl;
    system("pause");
} break;
				case 7:{
					system("cls");
				 int x,y;
    cout<<"INGRESA UN NUMERO DEL 1 AL 999 CON DECIMAL\n";
    cout<<"ingrese un numero"<<endl;
    cin>>x;
    cout<<"ingrese el decimal"<<endl;
    cin>>y;
if((x<1)||(x>999)) cout<<"INGRESA UN NUMERO DEL 1 AL 999\n";
else
    {
        if(x>=900)   {cout<<"NOVECIENTOS " ;x=x-900;}
       else if(x>=800)   {cout<<"OCHOCIENTOS " ;x=x-800;}
       else if(x>=700)   {cout<<"SETECIENTOS " ;x=x-700;}
       else if(x>=600)   {cout<<"SEISCIENTOS " ;x=x-600;}
       else if(x>=500)   {cout<<"QUINIENTOS "  ;x=x-500;}
       else if(x>=400)   {cout<<"CUATROCIENTOS "   ;x=x-400;}
       else if(x>=300)   {cout<<"TRESCIENTOS " ;x=x-300;}
       else if(x>=200)   {cout<<"DOSCIENTOS "  ;x=x-200;}
       else if(x>100)    {cout<<"CIENTO "  ;x=x-100;}
       else if(x==100)  {cout<<"CIEN"     ;x=x-100;}
        if(x>90) {cout<<"NOVENTA Y "   ;x=x-90; }
            if(x==90)   {cout<<"NOVENTA"  ;x=x-90; }  
            if(x>80) {cout<<"OCHENTA Y "   ;x=x-80; }
            if(x==80)   {cout<<"OCHENTA"  ;x=x-80; }
            if(x>70) {cout<<"SETENTA Y "   ;x=x-70; }
            if(x==70)   {cout<<"SETENTA"  ;x=x-70; }
            if(x>60) {cout<<"SESENTA Y "   ;x=x-60; }
            if(x==60)   {cout<<"SESENTA"  ;x=x-60; }
            if(x>50) {cout<<"CINCUENTA Y " ;x=x-50; }
            if(x==50)   {cout<<"CINCUENTA"    ;x=x-50; }
            if(x>40) {cout<<"CUARENTA Y "  ;x=x-40; }
            if(x==40)   {cout<<"CUARENTA" ;x=x-40; }
            if(x>30) {cout<<"TREINTA Y "   ;x=x-30; }
            if(x==30)   {cout<<"TREINTA"  ;x=x-30; }
            if(x>20) {cout<<"VEINTI"       ;x=x-20; }
            if(x==20)   {cout<<"VEINTE"       ;x=x-20; }
        if(x>=16)    {cout<<"DIECI"        ;x=x-10; }
       else if(x==15)   {cout<<"QUINCE"       ;x=x-15; }
       else if(x==14)   {cout<<"CATORCE"  ;x=x-14; }
       else if(x==13)   {cout<<"TRECE"        ;x=x-13; } 
       else if(x==12)   {cout<<"DOCE"     ;x=x-12; }
       else if(x==11)   {cout<<"ONCE"     ;x=x-11; }
       else if(x==10)   {cout<<"DIEZ"     ;x=x-10; }      
        if(x==9)    {cout<<"NUEVE"        ;x=x-9;  }
        if(x==8)    {cout<<"OCHO"     ;x=x-8;  }
        if(x==7)    {cout<<"SIETE"        ;x=x-7;  }
            if(x==6)    {cout<<"SEIS"     ;x=x-6;  }
       else if(x==5)    {cout<<"CINCO"        ;x=x-5;  }
       else if(x==4)    {cout<<"CUATRO"       ;x=x-4;  }
       else if(x==3)    {cout<<"TRES"     ;x=x-3;  }
       else if(x==2)    {cout<<"DOS"      ;x=x-2;  }
       else if(x==1)    {cout<<"UNO"      ;x=x-1;  }
       //
       gotoxy(33,5);  
      cout<<" PUNTO ";
       if(y>=900)   {cout<<"NOVECIENTOS " ;y=y-900;}
       else if(y>=800)   {cout<<"OCHOCIENTOS " ;y=y-800;}
       else if(y>=700)   {cout<<"SETECIENTOS " ;y=y-700;}
       else if(y>=600)   {cout<<"SEISCIENTOS " ;y=y-600;}
       else if(y>=500)   {cout<<"QUINIENTOS "  ;y=y-500;}
       else if(y>=400)   {cout<<"CUATROCIENTOS "   ;y=y-400;}
       else if(y>=300)   {cout<<"TRESCIENTOS " ;y=y-300;}
       else if(y>=200)   {cout<<"DOSCIENTOS "  ;y=y-200;}
       else if(y>100)    {cout<<"CIENTO "  ;y=y-100;}
       else if(y==100)  {cout<<"CIEN"     ;y=y-100;}
        if(y>90) {cout<<"NOVENTA Y "   ;y=y-90; }
            if(y==90)   {cout<<"NOVENTA"  ;y=y-90; }  
            if(y>80) {cout<<"OCHENTA Y "   ;y=y-80; }
            if(y==80)   {cout<<"OCHENTA"  ;y=y-80; }
            if(y>70) {cout<<"SETENTA Y "   ;y=y-70; }
            if(y==70)   {cout<<"SETENTA"  ;y=y-70; }
            if(y>60) {cout<<"SESENTA Y "   ;y=y-60; }
            if(y==60)   {cout<<"SESENTA"  ;y=y-60; }
            if(y>50) {cout<<"CINCUENTA Y " ;y=y-50; }
            if(y==50)   {cout<<"CINCUENTA"    ;y=y-50; }
            if(y>40) {cout<<"CUARENTA Y "  ;y=y-40; }
            if(y==40)   {cout<<"CUARENTA" ;y=y-40; }
            if(y>30) {cout<<"TREINTA Y "   ;y=y-30; }
            if(y==30)   {cout<<"TREINTA"  ;y=y-30; }
            if(y>20) {cout<<"VEINTI"       ;y=y-20; }
            if(y==20)   {cout<<"VEINTE"       ;y=y-20; }
        if(y>=16)    {cout<<"DIECI"        ;y=y-10; }
       else if(y==15)   {cout<<"QUINCE"       ;y=y-15; }
       else if(y==14)   {cout<<"CATORCE"  ;y=y-14; }
       else if(y==13)   {cout<<"TRECE"        ;y=y-13; } 
       else if(y==12)   {cout<<"DOCE"     ;y=y-12; }
       else if(y==11)   {cout<<"ONCE"     ;y=y-11; }
       else if(y==10)   {cout<<"DIEZ"     ;y=y-10; }      
        if(y==9)    {cout<<"NUEVE"        ;y=y-9;  }
        if(y==8)    {cout<<"OCHO"     ;y=y-8;  }
        if(y==7)    {cout<<"SIETE"        ;y=y-7;  }
            if(y==6)    {cout<<"SEIS"     ;y=y-6;  }
       else if(y==5)    {cout<<"CINCO"        ;y=y-5;  }
       else if(y==4)    {cout<<"CUATRO"       ;y=y-4;  }
       else if(y==3)    {cout<<"TRES"     ;y=y-3;  }
       else if(y==2)    {cout<<"DOS"      ;y=y-2;  }
       else if(y==1)    {cout<<"UNO"      ;y=y-1;  }
       }
    cout<<endl;
    system("pause");				
					break;
				}
				case 8:{
system("cls");
    int num;
    cout<<"por favor ingresa un numero para tu tabla :"<<endl;
    cin>>num;
    for(int i=1;i<=10;i++){
        int multiplicacion = i * num;
        cout<<num <<" x "<< i <<"="<< multiplicacion <<endl;
    } system("pause");
    		break;
				}
			 	case 9:{
			 		system("cls");
int izquierda=1;
int derecha=1;
while (izquierda <= 10){
cout << izquierda << "x" << derecha << "=" << izquierda*derecha << endl;
if (derecha == 10){
izquierda++;
derecha=0;
}
derecha++; 
}
cin.get();
system("pause");
break; 
}
				case 10:{
					con();
					break;
				}				
				case 11:{
					system("cls");
					cout<<"ingrese un numero entero positivo: \n";
					int numeros;
					string binario="";
					cin>> numeros;
					if (numeros>0){
						while (numeros>0){
							if (numeros%2==0){
								binario="0"+binario;
							} else{
								binario="1"+binario;
							}
								numeros =(int)numeros/2;
						}
					} else if (numeros==0){
						binario="0";
					} else{
						binario="El numero no es valido, por favor ingresa un numero positivo entero";
					}
					cout<<"El resultado de la conversion es :  "<< binario<<endl;
					system("pause");
					break;
				}
				case 12:{
system("cls");
int digitoex[20];
int decimal, residuo, resultado, i = 0;
    cout << "Introduce el numero decimal a convertir: " << endl;
    cin >> decimal;
    do{
        residuo = decimal % 16;
        resultado = decimal / 16;
        digitoex[i] = residuo;
        decimal = resultado;
        i++;
    } while (resultado > 15);
    digitoex[i] = resultado;
    cout << "El equivalente en hexadecimal es: ";
    for (int j = i; j >= 0; j--)
    {
        if (digitoex[j] == 10)
        {
            cout << "A";
        }
        else if (digitoex[j] == 11)
        {
            cout << "B";
        }
        else if (digitoex[j] == 12)
        {
            cout << "C";
        }
        else if (digitoex[j] == 13)
        {
            cout << "D";
        }
        else if (digitoex[j] == 14)
        {
            cout << "E";
        }
        else if (digitoex[j] == 15)
        {
            cout << "F";
        }
        else
        {
            cout << digitoex[j];
        }   
    }
    cout << endl;
    system("PAUSE");
					break;
				}
				case 13:{
					system ("cls");
	cout << "Programa que dibuja FIGURAS GEOMETRICAS \n" << endl;
    int alto, ancho, fila, columna,lineas;
    cout << "\nDime el ancho del rectángulo o cuadrado: ";
    cin >> ancho;
    cout << "\nDime el alto del rectángulo o cuadrado : ";
    cin >> alto;
    cout<<endl;
    for (fila=0; fila < alto; fila=fila+1)
    {
        for (columna=0; columna < ancho; columna=columna+1)
            cout << "*";
        cout << endl;
    }
    cout<<"\ningresa la cantidad de lineas para el triangulo: ";
    cin>>lineas;
    cout<<endl;
   int i;
   for (i=1; i<=lineas; i++)
     {
     	int j;
     	for(j=0;j<i;j++)
     	{
     		cout<<"*";
		 }
		 cout<<"\n";
	 }
	  cout << "ROMBO\n";
    int n = 10;
	  int k = 2*n - 2;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<k; j++)
            cout <<" ";
        k = k - 1;
        for (int j=0; j<=i; j++ )
        {
            cout << " *";
        }
        cout << endl;
    }
    for (int i=n; i>=0; i--)
    {
        for (int j=k; j>0; j--)
            cout <<" ";
        k = k + 1;
        for (int j=i; j>=0; j-- )
        {
            cout << " *";
        }
        cout << endl;
    }
    cout<<"\nCIRCULO\n";
cout<<"          *******             \n";
cout<<"      ***************         \n";
cout<<"    *******************       \n";
cout<<"  ***********************     \n";
cout<<" *************************    \n";
cout<<"***************************   \n";
cout<<"***************************   \n";
cout<<"***************************   \n";
cout<<"***************************   \n";
cout<<" *************************    \n";
cout<<"  ***********************     \n";
cout<<"    *******************       \n";
cout<<"      ***************         \n";
cout<<"          *******            \n";
system("pause");
					break;
				}
				case 14:{
					system ("cls");
					cout<< "MOVER PUNTO EN PANTALLA";
					OcultarCursor();
	Punto P(7,7);
	P.pintar();
	P.mover();
		Sleep(30);
		system ("pause");
					break;
				}
				case 15:{
					system("cls");
    int opt;
    char sn;
    double saldot=0;     
    do
    {
    system("cls");
    cout<<"\t\t\tOperaciones Bancarias\n";
    cout<<"1. Deposito\n";
    cout<<"2. Retiro\n";
    cout<<"3. Saldo\n";
    cout<<"4. Salir\n\n";
    cout<<"Elija el numero de la opcion: ";cin>>opt;
    saldot=Option(opt,saldot);
    cout<<"Seguro que Quieres salir? s/S n/N: ";cin>>sn;
    }while(sn=='n'||sn=='N');
    system("cls");
					break;
				}
				case 16:{
					system ("cls");
	cout<<"TRIANGULO DE PITAGORAS"<<endl<<endl;
    float a,b,c;
    cout<<"Ingrese el Primer cateto"<<endl;
    cin>>a;
    cout<<"Ingrese el Segundo cateto"<<endl;
    cin>>b;
    c=sqrt(pow(a,2)+pow(b,2));
    cout<<"La Hipotenusa es:"<<"\n"<<c<<endl<<endl;
    cout<<"\t"<<"_\\"<<endl;
    cout<<"\t"<<"___\\"<<endl;
    cout<<"\t"<<"_____\\"<<endl;
    cout<<"\t"<<"_______\\"<<endl;
    cout<<"\t"<<"_________\\"<<endl;
    cout<<"\t"<<a<<"__________"<<c<<endl;
    cout<<"\t"<<"_____________\\"<<endl;
    cout<<"\t"<<"_______________\\"<<endl;
    cout<<"\t"<<"_________________\\"<<endl;
    cout<<"\t"<<"_________"<<b<<"__________\\"<<endl<<endl;
     system("pause");
					break;
				}
				case 17:{
					system("cls");
					int mes, dia;
      cout<<"\t\t\tSIGNO ZODIACAL"<<endl;
      cout<<"(1)Enero  \t(2)Febrero  \t(3)Marzo  \t(4)Abril"<<endl;
      cout<<"(5)Mayo  \t(6)Junio     \t(7)Julio  \t(8)Agosto"<<endl;
      cout<<"(9)Septiembre  \t(10)Octubre  \t(11)Noviembre  \t(12)Diciembre"<<endl<<endl;
      cout<<"Ingrese la fecha de su cumplea"<<char(164)<<"os (dia)"<<endl;
      cin>>dia;
      cout<<"Ingrese el numero de mes "<<endl;
      cin>>mes;
      switch(mes)
      {
/*enero*/       case 1:if(dia<21) cout<<"Capricornio"<<endl;
                        else      cout<<"Acuario"<<endl;break;
 
/*febrero*/     case 2:if(dia<21) cout<<"Acuario"<<endl;
                        else      cout<<"Piscis"<<endl;break;
 
/*marzo*/       case 3:if(dia<21) cout<<"Piscis"<<endl;
                        else      cout<<"Aries"<<endl;break;
 
/*abril*/       case 4:if(dia<21) cout<<"Aries"<<endl;
                        else      cout<<"Tauro"<<endl;break;
 
/*mayo*/        case 5:if(dia<22) cout<<"Tauro"<<endl;
                        else      cout<<"Geminis"<<endl;break;
 
/*junio*/       case 6:if(dia<22) cout<<"Geminis"<<endl;
                        else      cout<<"Cancer"<<endl;break;
 
/*julio*/       case 7:if(dia<23) cout<<"Cancer"<<endl;
                        else      cout<<"Leo"<<endl;break;
 
/*agosto*/      case 8:if(dia<23) cout<<"Leo"<<endl;
                        else      cout<<"Virgo"<<endl;break;
 
/*septiembre*/  case 9:if(dia<24) cout<<"Virgo"<<endl;
                        else      cout<<"Libra"<<endl;break;
 
/*octubre*/     case 10:if(dia<25)cout<<"Libra"<<endl;
                        else      cout<<"Escorpio"<<endl;break;
 
/*noviembre*/   case 11:if(dia<23)cout<<"Escorpio"<<endl;
                        else      cout<<"Sagitario"<<endl;break;
 
/*diciembre*/   case 12:if(dia<22)cout<<"Sagitario"<<endl;
                        else      cout<<"Capricornio"<<endl;break;
 
                default:cout<<"INGRESE UNA FECHA VALIDA"<<endl;
      } system ("pause");
					break;
				}
				case 18:{
					system("cls");
					string apno;
    float hrtr,tahr,subt,boni,tota;
    cout<<"Calculos de pagos\n\n";
    cout<<"Nombres:\t";cin>>apno;
    cout<<endl<<endl<<"Horas Trabajadas:\t";cin>>hrtr;
    if (hrtr<=0)
        cout<<"No trabajo nada"<<endl;else
    {cout<<"Tarifa por hora:\t";cin>>tahr;
    subt=hrtr*tahr;
    if(hrtr>192)
        boni=subt*0.05;
    else
        boni=subt*0.03;
    tota=subt+boni;
    cout<<"El sub total es:\t"<<subt<<endl;
    cout<<"La bonifiacion es:\t"<<boni<<endl;
    cout<<"El total a pagar es:\t"<<tota<<endl<<endl;
	system("pause");				}
					break;
				}
				case 19:{
					system ("cls");
	int ncredisp, ncred, ncredmat=0, ncursos=0,ciclo;
    char i;
    string nom;
    cout<<"Nombre del alumno: ";cin>>nom;
    IngreseCiclo:
    cout<<"Ingrese ciclo: ";cin>>ciclo;
     
    switch(ciclo)
    {
        case 1: case 4: case 7:
        {
            ncredisp=20;
            cout<<"Creditos disponibles: "<<ncredisp<<endl;
             
            do
            {
                IngreseCreditos:
                do
                {
                    cout<<"Ingrese la cantidad creditos del curso: ";cin>>ncred;
                    if(ncred<=0||ncred>ncredisp)
                    {
                         
                        cout<<"La cantidad de creditos debe ser mas de 0 y menor-igual que el total de creditos disponibles"<<endl;
                        sn:
                        cout<<"Desea ingresar un valor valido (Si:S/s) (No:N/n): ";cin>>i;
                        decide:
                        switch(i)
                        {
                        case 's':case'S': goto IngreseCreditos;
                        case 'n':case'N':   {if(ncredmat>=12) goto notificar;
                                            else exit(0);
                                            }break;
                        default: cout<<"Invalido\n";goto sn;
                        }
                    }
                    ncredisp=ncredisp-ncred;
                     
                    cout<<"Credito  Restante: "<<ncredisp<<endl;
                    ncredmat=ncredmat+ncred;
                    ncursos++;
                }while(ncredmat<12);
                 
                while(ncredisp>0)
                {       
                cout<<"Desea matricularse en algun curso mas (Si:S/s) (No:N/n): ";cin>>i;
                goto decide;
                }
            }while(ncred<0&&ncred>ncredisp);
        }break;
        case 2: case 3: case 8:
            {
                ncredisp=22;
                cout<<"Creditos disponibles: "<<ncredisp<<endl;
                goto IngreseCreditos;
 
            }break;
        case 5: case 6: case 9: case 10:
            {
                ncredisp=24;
                cout<<"Creditos disponibles: "<<ncredisp<<endl;
                goto IngreseCreditos;
 
            }break;
        default:
                {
                    cout<<"Desea ingresar un valor valido s/S n/N: ";cin>>i;
                    switch(i)
                    {
                        case 's': case 'S':goto IngreseCiclo;
                        case 'N': case 'n':exit(0);
                        default: cout<<"respuesta invalida"<<endl;
                    }
                }
     
    }
    notificar:
    cout<<"\n\nREPORTE\n\n";
    cout<<"Nombre del alumno: "<<nom<<endl;
    cout<<"Ciclo del alumno: "<<ciclo<<endl;
    cout<<"Total de creditos matriculados: "<<ncredmat<<endl;
    cout<<"Total de creditos disponibles: "<<ncredisp<<endl;
    cout<<"Total de cursos matriculados: "<<ncursos<<endl;
				system ("Pause");	break;
				}
				case 20:{
					system("cls");
  
    int mes,dias,a;
    cout<<"ingrese el mes y el a"<<char(164)<<"o (presiona ENTER entre cada uno)"<<endl;
    cin>>mes>>a;
 
switch (mes)
{
case 1: case 3: case 5: case 7: case 8: case 10: case 12:
dias = 31;
break;
case 4: case 6: case 9: case 11:
dias = 30;
break;
case 2:if(a%4==0)
dias = 28;
    else
dias=29;
break;
default:
printf("El mes no es válido\n");
break;
}
cout<<dias<<endl;
     system("pause");
					break;
				}
        }        
    } while (opcion!= 21);           
    exit(0);
}
