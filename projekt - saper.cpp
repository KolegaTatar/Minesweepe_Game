#include<iostream>
#include <cstdlib> //biblioteka do czyszczenia ekranu konsoli
#include <windows.h>
#include <winbase.h>
#include <time.h>
using namespace std;



void slow_print(const string str, int delay_time) {
        for (size_t u = 0; u != str.size(); ++u) {
            cout << str[u];
            Sleep(delay_time);
        }
    }
    
    
    
int main(){

int hist=0;


int l=0;
int b=1;
int c=0;		//licznik ruchów w grze 
int d=1;		// licznik punktów w grze
int pom[8][8];

char a='-';		//wartosci nieodkryte na planszy
char p='0';	
int n=10;
char tab[n][n];
char tabp[n][n];
int bomby=0;
char q;
int k;


int minp=0;		//minuta pocz¹tkowa od uruchomienia konkretnego trybu gry (medium lub hard)
int secp=0;		//sekunda pocz¹tkowa od uruchomienia konkretnego trybu gry (medium lub hard)
int mink=0;		//minuta koñcowa od uruchomienia konkretnego trybu gry (medium lub hard)
int seck=0;		//sekunda koñcowa od uruchomienia konkretnego trybu gry (medium lub hard)
int czas=0;		//czas gry



string nowa="new";
string next="next"; //zmienna s³u¿¹ca pomijanie treœci//
string x;	//zmienna przechowuj¹ca wybory urzytkownika 
string gra ="gra";	//zmienna przechowuj¹ca dane do pomijania do samej gry, wpisane przez u¿ytkownika 
string poradnik ="poradnik";  //zmienna przechowujaca dane doyczace przechodzenia bezposrednio do zasad gry
string info="info";
string uruchom="uruchom"; 
string easy ="easy";
string medium ="medium";
string hard ="hard";
string end="zakoncz";
string historia="historia";
string wlasna="wlasna";
string graj="graj";
string stworz="stworz";




// poni¿ej znajduje siê poradnik oraz gra



for(int i=0;i<b+1;i++){

	while (x!=nowa && x!=historia){
        system( "cls" );
    
		slow_print("						SAPER - PANEL POCZATKOWY", 50);
		cout<<endl<<endl;
		cout<<"Witaj, przed toba znajduje sie gra w sapera"<<endl<<endl;
		cout<<"W poszczegolnych kategoriach znajdujacych sie w menu, odnajdziesz wiele istotnych"<<endl;
		cout<<"informacji, miedzy innymi: poradnik do gry, jej zasady, informacje o"<<endl;
		cout<<"autorach oraz najwazniejsze czyli sama gra - SAPER "<<endl<<endl;
		cout<<"Aby przejsc do panelu menu wpisz 'new': "<<endl<<endl;
		cout<<"Aby przejsc do panelu histori punktow wpisz 'historia': "<<endl<<endl;
		cout<<"Podaj swoj wybor: ";
		cin>>x;
	}
if(x==nowa){

	while (x!=poradnik && x!=gra && x!=info && x!=wlasna){			//sprawdzanie czy wpisane s³owa s¹ prawdziwe
		system( "cls" );
		slow_print("						SAPER - MENU" , 50);
		cout<<endl<<endl;
		cout<<"Jezeli chcesz zapoznac sie z zasadami oraz poradnikiem do gry, wpisz 'poradnik': "<<endl;
		cout<<endl;
		cout<<"Aby przejsc do gry saper napisz 'gra': "<<endl;
		cout<<endl;
		cout<<"Aby przejsc do informacji o autorach gry napisz 'info': "<<endl;
		cout<<endl;
		cout<<"Aby stworzyc wlasna gre, wpisz 'wlasna': "<<endl;
		cout<<endl;
		cout<<"Podaj swoj wybor: ";
		cin>>x;	
}
	if(x==poradnik){
		while(x!=next){
        system( "cls" );
        slow_print("						SAPER - PORADNIK" , 50);
		cout<<endl<<endl;
		cout<<"                   CELE GRY:"<<endl<<endl;
		cout<<"Celem gry jest odnalezienie wszystkich min znajdujacych sie na planszy,"<<endl; 
		cout<<"poprzez odsloniecie wszystkich pol, ktore nie skrywaja miny."<<endl<<endl;
		cout<<"Jezeli gracz natrafi na pole, pod ktorym ukryta jest mina - gra konczy sie porazka."<<endl;
		cout<<endl<<endl<<endl;
		cout<<"Aby przejsc do dalszej czesci poradnika, napisz 'next': "<<endl;
		cout<<"Podaj swoj wybor: ";
		cin>>x;
		}
		l=l+1;
			if(x==next && l==1){
				x="pusto";
				while(x!=next){
                system( "cls" );
                slow_print("						SAPER - PORADNIK" , 50);
				cout<<endl<<endl;
			    cout<<"               PLANSZA"<<endl<<endl;
	    		cout<<"Plansza to kwadrat to wymiarach 10 na 10, skladajacy sie z 100 mniejszych kwadratow."<<endl; 
	      		cout<<"Kazdy element planszy czyli pojedynczy kwadrat, w ktorym jest wpisana dana wartosc bomb lub"<<endl;
	  			cout<<"jej brak, to tablica dwuwymiarowa."<<endl;
	      		cout<<"Sklada sie ona z ideksow odpowiednio odnoszacych sie do pionu oraz poziomu planszy np. 2;5 "<<endl<<endl;
		  		cout<<"przykladowa plansza do gry 8 na 8, z wartoscia 5 na polu o wspolrzednych: 4;6  : "<<endl<<endl;
				    		for(int i=1;i<9;i++)
					{
						for(int j=1;j<9;j++){
							pom[i][j]=0; 
							//plansza
						}
						
					}
				 	pom[6][4]=5;
					for(int i=1;i<9;i++){
						for(int j=1;j<9;j++){
				
							cout<<"| "<<pom[j][i]<<" |";		
					}
						cout<<endl;
			   }
		   	    cout<<endl<<endl<<endl;
	    		cout<<"      !! SYSTEM SAMEGO PORUSZANIA SIE I WPISYWANIA LICZB ZNAJDUJE SIE W DALSZEJ CZESCI PORADNIKA !!"<<endl<<endl<<endl;
		 		cout<<"W zaleznosci od stopnia zaawansowania sa dostepne trzy tryby gry: "<<endl; 
		 		cout<<"	> easy -  najprostrzy tryb"<<endl;
	 			cout<<"	> medium - tryb sredniozaawanstwany, aby wygrac, musisz odkryc wszystkie pola poza tymi z minami, "<<endl;
		 		cout<<"w czasie szybszym niz 720 sekund"<<endl;
 				cout<<"	> hard - tryb zaawanstwany, aby wygrac, musisz odkryc wszystkie pola poza tymi z minami, w czasie szybszym"<<endl;
			 	cout<<"niz 240s"<<endl;
				cout<<endl<<endl<<endl;
				cout<<"Aby przejsc do dalszej czesci poradnika, napisz 'next': "<<endl;
				cout<<"Podaj swoj wybor: ";
				cin>>x;
					}
				l=l+1;
				  	if(x==next && l==2){
						x="pusto";
						while(x!=next){
					    system( "cls" );
					    slow_print("						SAPER - PORADNIK" , 50);
						cout<<endl<<endl;
						cout<<"               OZNACZENIA WARTOSCI MIN NA PLANSZY W SAPERZE: "<<endl<<endl;
						cout<<"1. '0' to brak min wokol"<<endl;
						cout<<"2. '1' to jedna mina wokol"<<endl;
						cout<<"3. '2' to dwie miny wokol"<<endl;
						cout<<"4. '3' to trzy miny wokol"<<endl;
						cout<<"5. '4' to cztery miny wokol"<<endl;
						cout<<"6. '5' to piec min wokol"<<endl;
						cout<<"7. '-' to nie zbadane pole"<<endl;
						cout<<"8. '9' to mina"<<endl<<endl;
						cout<<endl<<endl<<endl;
						cout<<"Aby przejsc do dalszej czesci poradnika, napisz 'next': "<<endl;
						cout<<"Podaj swoj wybor: ";
						cin>>x;
							}
						l=l+1;
				            if(x==next && l==3){
				      			x="pusto";
								while(x!=next){
  								system( "cls" );
  								slow_print("						SAPER - PORADNIK" , 50);
						  		cout<<endl<<endl;
  								cout<<"         RUCH, ODKRYWANIE MIEJSC, SZUKANIE BOMB :"<<endl<<endl;
  								cout<<"Ruch, czyli odkrywanie konkretnego pola na planszy odbywa sie za pomoca wpisywanych"<<endl;
								  cout<<"wspolrzednych tzw. Y(pion) oraz X(poziom) za kazdym razem zostaniesz zapytany o podanie wysokosci i szerokosci."<<endl;
  								cout<<"dla przykladu niech w planszy 5 na 5 na polu o wspolrzednych 3;2 znajduje sie cyfra '5'"<<endl;
  								cout<<"3 to wysokosc a 2 to szerokosc na ktorej zostanie umieszczona cyfra 5"<<endl;
  								cout<<"kazda wspolrzedna musi byc z zakresu od 1 do 10 wlacznie z tymi liczbami np. 10;3 lub 1;4 itp"<<endl;
  								cout<<endl<<endl<<endl;
	  							cout<<"Aby przejsc do dalszej czesci poradnika, napisz 'next': "<<endl;
								cout<<"Podaj swoj wybor: ";
								cin>>x;
								}
								l=l+1;
						            if(x==next && l==4){
						           		x="pusto";
										while(x!=next){
		  								system( "cls" );
		  								slow_print("						SAPER - PORADNIK" , 50);
								  		cout<<endl<<endl;
										cout<<"         WSKAZOWKI I PORADY"<<endl<<endl;
										cout<<"1. Od samego poczatku gry skup sie oraz analizuj to co widzisz"<<endl;
										cout<<"2. Zwracaj uwage na cyfry np. 3, oznaczajace ilosc min wolol"<<endl;
										cout<<"3. Nie spiesz sie - czas to zly doradzca, nie zawsze wplywa pozytywnie"<<endl;
										cout<<"4. Jezeli za wszelka cene chcesz wybrac, nie ryzyjuj, stawiajac na pole, zagrozone wieloma minami"<<endl;
										cout<<"5. Jesli ci nie wyjdzie, nie przejmuj siê i sprobuj jeszcze raz"<<endl;
										cout<<endl<<endl<<endl;
										cout<<"Aby przejsc do ostatniej czesci poradnika, napisz 'next': "<<endl;
										cout<<"Podaj swoj wybor: ";
										cin>>x;
										}
										l=l+1;
								    		if(x==next && l==5){
								    			x="pusto";
												while(x!=info && x!=gra){
				  								system( "cls" );
				  								slow_print("						SAPER - PORADNIK" , 50);
										  		cout<<endl<<endl;
												cout<<"Wierzymy, ze spodoba ci sie nasza gra"<<endl;
												cout<<"Przede wszystkim mysl i analizuj"<<endl<<endl;
												cout<<"!! POWODZENIA !!"<<endl;					
												cout<<endl<<endl<<endl;
												cout<<"Aby przejsc do panelu gry, napisz 'gra': "<<endl;
												cout<<"Aby przejsc do informacji o autorach, napisz 'info': "<<endl;
												cout<<"Podaj swoj wybor: ";
												cin>>x;
												l=0;
											}
}
}
}
}
}
}
	if(x==gra){
	while(x!=medium && x!=easy && x!=hard){
	c=0;
	d=0;
	system( "cls" );
	slow_print("						SAPER - GRA" , 50);
	cout<<endl<<endl;
	cout<<"Znajdujesz sie w panelu gry Saper"<<endl<<endl;
	cout<<"								!! WAZNE !!"<<endl<<endl;
	cout<<"wspolrzedne nalezy wpisywac TYLKO RAZ, NIE WOLNO POWTARZEC np. pierwszy wybor: 1;2, x wybor 1;2 - BLAD!! "<<endl<<endl<<endl;
	
	cout<<"DOSTEPNE POZIOMY "<<endl;
	cout<<"	> easy "<<endl;
	cout<<"	> medium "<<endl;
 	cout<<"	> hard "<<endl<<endl;
 	cout<<"wpisz poziom gry: ";
 	cin>>x;
 	}
	while(x!=uruchom && x!=end){
        if(x==easy){
      		system( "cls" );
			slow_print("					SAPER - GRA TRYB EASY" , 50);
			cout<<endl<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
				
			    SYSTEMTIME st;
    			GetSystemTime(&st);
    
			    secp=st.wSecond;
				minp=st.wMinute;
				
				for(int i=1;i<n+1;i++)
				{
					for(int j=1;j<n+1;j++){
						tabp[i][j]=a; 
						//plansza
					}
				}
			
				for(int i=1;i<n+1;i++){
					for(int j=1;j<n+1;j++){
			
						cout<<"| "<<tabp[i][j]<<" |";		
				}
					cout<<endl;
			}
			tab[1][1]='2'; 
			tab[1][2]='9';		//1 to bomba 
			tab[1][3]='2';
			tab[1][4]='1';
			tab[1][5]='2';
			tab[1][6]='9'; //2
			tab[1][7]='2';
			tab[1][8]='9';//3
			tab[1][9]='2';
			tab[1][10]='1';
			tab[2][1]='9';//4
			tab[2][2]='3';
			tab[2][3]='2';
			tab[2][4]='9';//5
			tab[2][5]='2';
			tab[2][6]='1';
			tab[2][7]='2';
			tab[2][8]='2';
			tab[2][9]='3';
			tab[2][10]='9'; //
			tab[3][1]='9';//6
			tab[3][2]='9';//7
			tab[3][3]='2';
			tab[3][4]='1';
			tab[3][5]='1';
			tab[3][6]='0';
			tab[3][7]='1';
			tab[3][8]='2';
			tab[3][9]='9';//8
			tab[3][10]='9';//9
			tab[4][1]='3';
			tab[4][2]='2';
			tab[4][3]='1';
			tab[4][4]='0';
			tab[4][5]='0';
			tab[4][6]='0';
			tab[4][7]='1';
			tab[4][8]='9';//10
			tab[4][9]='5';
			tab[4][10]='9';//11
			tab[5][1]='9';//12
			tab[5][2]='2';
			tab[5][3]='1';
			tab[5][4]='0';
			tab[5][5]='0';
			tab[5][6]='0';
			tab[5][7]='2';
			tab[5][8]='3';
			tab[5][9]='9';//13
			tab[5][10]='3';
			tab[6][1]='3';
			tab[6][2]='9';//14
			tab[6][3]='1';
			tab[6][4]='0';
			tab[6][5]='0';
			tab[6][6]='0';
			tab[6][7]='1';
			tab[6][8]='9';//15
			tab[6][9]='3';
			tab[6][10]='9';//16
			tab[7][1]='9';//17
			tab[7][2]='3';
			tab[7][3]='2';
			tab[7][4]='2';
			tab[7][5]='1';
			tab[7][6]='1';
			tab[7][7]='1';
			tab[7][8]='2';
			tab[7][9]='3';
			tab[7][10]='2';
			tab[8][1]='2';
			tab[8][2]='4';
			tab[8][3]='9';//18
			tab[8][4]='3';
			tab[8][5]='9';//19
			tab[8][6]='2';
			tab[8][7]='2';
			tab[8][8]='2';
			tab[8][9]='9';//20
			tab[8][10]='2';
			tab[9][1]='2';
			tab[9][2]='9';// 21
			tab[9][3]='9';//22
			tab[9][4]='4';
			tab[9][5]='3';
			tab[9][6]='9';//23
			tab[9][7]='4';
			tab[9][8]='9';//24
			tab[9][9]='4';
			tab[9][10]='9';//25
			tab[10][1]='9';//26
			tab[10][2]='3';
			tab[10][3]='3';
			tab[10][4]='9';//27
			tab[10][5]='2';
			tab[10][6]='2';
			tab[10][7]='9';//28
			tab[10][8]='9';//29
			tab[10][9]='3';
			tab[10][10]='1';
			
					
			int z=10,y=10;
			while(tab[z][y]!='9' && c<70){
				c=c+1;
				cout<<endl;
				cout<<endl;
				cout<<endl;
			
				cout<<"podaj wysokosc od 1 do 10: ";
				cin>>z;
				
				cout<<"podaj szerokosc od 1 do 10: ";
				cin>>y;	
				
				cout<<"T["<<z<<"]["<<y<<"]: "<<tab[z][y]<<endl;
				
				cout<<"---------------------------"<<endl;
			
					   p=tab[z][y];
		
				cout<<endl;
				        system( "cls" );
			cout<<"					SAPER - GRA TRYB EASY" <<endl<<endl;
							cout<<endl;
							cout<<endl;
				        cout<<"Poprzednio podane pole["<<z<<"]["<<y<<"] wynosilo: "<<p;
							cout<<endl;
							cout<<endl;
			 	  
					for(int i=1;i<n+1;i++){
							for(int j=1;j<n+1;j++){
								if(tab[z][y]!=tabp[z][y]){
								    tabp[z][y]=tab[z][y];					 
								}
								cout<<"| "<<tabp[i][j]<<" |";
								}
							cout<<endl;
					}
					if(tab[z][y]=='9'){
								        GetSystemTime(&st);
										   	mink=st.wMinute-minp;
    										seck=st.wSecond-secp;
    										mink=mink*60;
    										czas=mink+seck;
										cout<<"BUM"<<endl;
										cout<<"BUM"<<endl;
										cout<<"BUM"<<endl;
										cout<<"BUM"<<endl<<endl;
										slow_print("                      !! PRZEGRALES !!", 50);
										cout<<endl<<endl<<endl;
										cout<<"liczba ruchow: "<<c<<endl;
									d=(d+czas)*c;
										cout<<"ilosc zdobytych punktow: "<<d<<endl;
										    
										cout<<"uzyskany czas wynosi: "<<czas<<" s";
										hist=d;
							break; 
									}
					if(c>=70){
						slow_print("                      !! WYGRALES !!", 50);
						cout<<endl<<endl<<endl;
						 							 GetSystemTime(&st);
										   	mink=st.wMinute-minp;
    										seck=st.wSecond-secp;
    										mink=mink*60;
    										czas=mink+seck;
										cout<<"liczba ruchow: "<<c<<endl;
										d=(d+czas)*c;
										cout<<"ilosc zdobytych punktow: "<<d<<endl;
										cout<<"uzyskany czas wynosi: "<<czas<<" s";
										hist=d;
					}
			
			
			
			}
}


	 	else if(x==medium){
      		system( "cls" );
			slow_print("					SAPER - GRA TRYB MEDIUM" , 50);
			cout<<endl<<endl;
							cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
				SYSTEMTIME st;
    			GetSystemTime(&st);
    
			    secp=st.wSecond;
				minp=st.wMinute;
			
				for(int i=1;i<n+1;i++)
				{
					for(int j=1;j<n+1;j++){
						tabp[i][j]=a; 
						//plansza
					}
				}
			
				for(int i=1;i<n+1;i++){
					for(int j=1;j<n+1;j++){
			
						cout<<"| "<<tabp[i][j]<<" |";		
				}
					cout<<endl;
			}
				tab[1][1]='2'; 
			tab[1][2]='9';		//9 to bomba 
			tab[1][3]='2';
			tab[1][4]='1';
			tab[1][5]='2';
			tab[1][6]='9'; //
			tab[1][7]='2';
			tab[1][8]='9';//
			tab[1][9]='2';
			tab[1][10]='1';
			tab[2][1]='9';//
			tab[2][2]='3';
			tab[2][3]='2';
			tab[2][4]='9';//
			tab[2][5]='2';
			tab[2][6]='1';
			tab[2][7]='2';
			tab[2][8]='2';
			tab[2][9]='3';
			tab[2][10]='9';//
			tab[3][1]='9';//7
			tab[3][2]='9';//
			tab[3][3]='2';
			tab[3][4]='1';
			tab[3][5]='1';
			tab[3][6]='0';
			tab[3][7]='1';
			tab[3][8]='2';
			tab[3][9]='9';//
			tab[3][10]='9';//
			tab[4][1]='3';
			tab[4][2]='2';
			tab[4][3]='1';
			tab[4][4]='0';
			tab[4][5]='0';
			tab[4][6]='0';
			tab[4][7]='1';
			tab[4][8]='9';//
			tab[4][9]='5';
			tab[4][10]='9';//
			tab[5][1]='9';//
			tab[5][2]='2';
			tab[5][3]='1';
			tab[5][4]='0';
			tab[5][5]='0';
			tab[5][6]='0';
			tab[5][7]='2';
			tab[5][8]='3';
			tab[5][9]='9';//8
			tab[5][10]='3';
			tab[6][1]='3';
			tab[6][2]='9';//
			tab[6][3]='1';
			tab[6][4]='0';
			tab[6][5]='0';
			tab[6][6]='0';
			tab[6][7]='1';
			tab[6][8]='9';//
			tab[6][9]='3';
			tab[6][10]='9';//
			tab[7][1]='9';//
			tab[7][2]='3';
			tab[7][3]='2';
			tab[7][4]='2';
			tab[7][5]='1';
			tab[7][6]='1';
			tab[7][7]='1';
			tab[7][8]='2';
			tab[7][9]='3';
			tab[7][10]='2';
			tab[8][1]='2';
			tab[8][2]='4';
			tab[8][3]='9';//
			tab[8][4]='3';
			tab[8][5]='9';//
			tab[8][6]='2';
			tab[8][7]='2';
			tab[8][8]='2';
			tab[8][9]='9';//
			tab[8][10]='2';
			tab[9][1]='2';
			tab[9][2]='9';// 9
			tab[9][3]='9';//
			tab[9][4]='4';
			tab[9][5]='3';
			tab[9][6]='9';//
			tab[9][7]='4';
			tab[9][8]='9';//
			tab[9][9]='4';
			tab[9][10]='9';//
			tab[10][1]='9';//
			tab[10][2]='3';
			tab[10][3]='3';
			tab[10][4]='9';//
			tab[10][5]='2';
			tab[10][6]='2';
			tab[10][7]='9';//
			tab[10][8]='9';//
			tab[10][9]='3';
			tab[10][10]='1';
			
					
			int z=10,y=10;
			while(tab[z][y]!='9' && c<70){
				c=c+1;
				cout<<endl;
				cout<<endl;
				cout<<endl;
			
				cout<<"podaj wysokosc od 1 do 10: ";
				cin>>z;
				
				cout<<"podaj szerokosc od 1 do 10: ";
				cin>>y;	
				
				cout<<"T["<<z<<"]["<<y<<"]: "<<tab[z][y]<<endl;
				
				cout<<"---------------------------"<<endl;
			
					   p=tab[z][y];
		
				cout<<endl;
				        system( "cls" );
			cout<<"					SAPER - GRA TRYB MEDIUM" <<endl<<endl;
							cout<<endl;
							cout<<endl;
				        cout<<"Poprzednio podane pole["<<z<<"]["<<y<<"] wynosilo: "<<p;
							cout<<endl;
							cout<<endl;
			 	  
					for(int i=1;i<n+1;i++){
							for(int j=1;j<n+1;j++){
								if(tab[z][y]!=tabp[z][y]){
								    tabp[z][y]=tab[z][y];					 
								}
								cout<<"| "<<tabp[i][j]<<" |";
								}
							cout<<endl;
					}
					if(tab[z][y]=='9'){
								        	 GetSystemTime(&st);
										   	mink=st.wMinute-minp;
    										seck=st.wSecond-secp;
    										mink=mink*60;
    										czas=mink+seck;
										cout<<"BUM"<<endl;
										cout<<"BUM"<<endl;
										cout<<"BUM"<<endl;
										cout<<"BUM"<<endl<<endl;
										slow_print("                      !! PRZEGRALES !!",50);
										cout<<endl<<endl<<endl;
										cout<<"liczba ruchow: "<<c<<endl;
										d=(d+czas)*c;
										cout<<"ilosc zdobytych punktow: "<<d<<endl;
										cout<<"uzyskany czas wynosi: "<<czas<<" s";
										hist=d;
							break; 
									}
					if(c>=70){
						GetSystemTime(&st);
										   	mink=st.wMinute-minp;
    										seck=st.wSecond-secp;
    										mink=mink*60;
    										czas=mink+seck;
						if(c>=70 && czas<=720){
						
						slow_print("                      !! WYGRALES !!",50);
						cout<<endl<<endl<<endl;
													 
										cout<<"liczba ruchow: "<<c<<endl;
										d=(d+czas)*c;
										cout<<"ilosc zdobytych punktow: "<<d<<endl;
										cout<<"uzyskany czas wynosi: "<<czas<<" s"<<endl;
										cout<<"maksymalny mozliwy czas wynosi: 720s";
										hist=d;
									}
									else{
							slow_print("                      !! PRZEGRALES !!",50);
										cout<<endl<<endl<<endl;
										cout<<"liczba ruchow: "<<c<<endl;
										d=(d+czas)*c;
										cout<<"ilosc zdobytych punktow: "<<d<<endl;
										cout<<"uzyskany czas wynosi: "<<czas<<" s"<<endl;
										cout<<"maksymalny mozliwy czas wynosi: 720s";
										hist=d;
						}
					}
			
			
			
			}
			
			
		}
		else{
			system( "cls" );
			slow_print("					SAPER - GRA TRYB HARD" ,50);
			cout<<endl<<endl;
							cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
			
			SYSTEMTIME st;
    			GetSystemTime(&st);
    
			    secp=st.wSecond;
				minp=st.wMinute;
				
				for(int i=1;i<n+1;i++)
				{
					for(int j=1;j<n+1;j++){
						tabp[i][j]=a; 
						//plansza
					}
				}
			
				for(int i=1;i<n+1;i++){
					for(int j=1;j<n+1;j++){
			
						cout<<"| "<<tabp[i][j]<<" |";		
				}
					cout<<endl;
			}
				tab[1][1]='2'; 
			tab[1][2]='9';		//9 to bomba 
			tab[1][3]='2';
			tab[1][4]='1';
			tab[1][5]='2';
			tab[1][6]='9'; //
			tab[1][7]='2';
			tab[1][8]='9';//
			tab[1][9]='2';
			tab[1][10]='1';
			tab[2][1]='9';//
			tab[2][2]='3';
			tab[2][3]='2';
			tab[2][4]='9';//
			tab[2][5]='2';
			tab[2][6]='1';
			tab[2][7]='2';
			tab[2][8]='2';
			tab[2][9]='3';
			tab[2][10]='9'; //
			tab[3][1]='9';//7
			tab[3][2]='9';//
			tab[3][3]='2';
			tab[3][4]='1';
			tab[3][5]='1';
			tab[3][6]='0';
			tab[3][7]='1';
			tab[3][8]='2';
			tab[3][9]='9';//
			tab[3][10]='9';//
			tab[4][1]='3';
			tab[4][2]='2';
			tab[4][3]='1';
			tab[4][4]='0';
			tab[4][5]='0';
			tab[4][6]='0';
			tab[4][7]='1';
			tab[4][8]='9';//
			tab[4][9]='5';
			tab[4][10]='9';//
			tab[5][1]='9';//
			tab[5][2]='2';
			tab[5][3]='1';
			tab[5][4]='0';
			tab[5][5]='0';
			tab[5][6]='0';
			tab[5][7]='2';
			tab[5][8]='3';
			tab[5][9]='9';//8
			tab[5][10]='3';
			tab[6][1]='3';
			tab[6][2]='9';//
			tab[6][3]='1';
			tab[6][4]='0';
			tab[6][5]='0';
			tab[6][6]='0';
			tab[6][7]='1';
			tab[6][8]='9';//
			tab[6][9]='3';
			tab[6][10]='9';//
			tab[7][1]='9';//
			tab[7][2]='3';
			tab[7][3]='2';
			tab[7][4]='2';
			tab[7][5]='1';
			tab[7][6]='1';
			tab[7][7]='1';
			tab[7][8]='2';
			tab[7][9]='3';
			tab[7][10]='2';
			tab[8][1]='2';
			tab[8][2]='4';
			tab[8][3]='9';//
			tab[8][4]='3';
			tab[8][5]='9';//
			tab[8][6]='2';
			tab[8][7]='2';
			tab[8][8]='2';
			tab[8][9]='9';//
			tab[8][10]='2';
			tab[9][1]='2';
			tab[9][2]='9';// 9
			tab[9][3]='9';//
			tab[9][4]='4';
			tab[9][5]='3';
			tab[9][6]='9';//
			tab[9][7]='4';
			tab[9][8]='9';//
			tab[9][9]='4';
			tab[9][10]='9';//
			tab[10][1]='9';//
			tab[10][2]='3';
			tab[10][3]='3';
			tab[10][4]='9';//
			tab[10][5]='2';
			tab[10][6]='2';
			tab[10][7]='9';//
			tab[10][8]='9';//
			tab[10][9]='3';
			tab[10][10]='1';
			
					
			int z=10,y=10;
			while(tab[z][y]!='9' && c<70){
				c=c+1;
				cout<<endl;
				cout<<endl;
				cout<<endl;
			
				cout<<"podaj wysokosc od 1 do 10: ";
				cin>>z;
				
				cout<<"podaj szerokosc od 1 do 10: ";
				cin>>y;	
				
				cout<<"T["<<z<<"]["<<y<<"]: "<<tab[z][y]<<endl;
				
				cout<<"---------------------------"<<endl;
			
					   p=tab[z][y];
		
				cout<<endl;
				        system( "cls" );
			cout<<"					SAPER - GRA TRYB HARD" <<endl<<endl;
							cout<<endl;
							cout<<endl;
				        cout<<"Poprzednio podane pole["<<z<<"]["<<y<<"] wynosilo: "<<p;
							cout<<endl;
							cout<<endl;
			 	  
					for(int i=1;i<n+1;i++){
							for(int j=1;j<n+1;j++){
								if(tab[z][y]!=tabp[z][y]){
								    tabp[z][y]=tab[z][y];					 
								}
								cout<<"| "<<tabp[i][j]<<" |";
								}
							cout<<endl;
					}
					if(tab[z][y]=='9'){
								         GetSystemTime(&st);
										   	mink=st.wMinute-minp;
    										seck=st.wSecond-secp;
    										mink=mink*60;
    										czas=mink+seck;
										cout<<"BUM"<<endl;
										cout<<"BUM"<<endl;
										cout<<"BUM"<<endl;
										cout<<"BUM"<<endl<<endl;
										slow_print("                      !! PRZEGRALES !!",50);
										cout<<endl<<endl<<endl;
										cout<<"liczba ruchow: "<<c<<endl;
										d=(d+czas)*c;
										cout<<"ilosc zdobytych punktow: "<<d<<endl;
										cout<<"uzyskany czas wynosi: "<<czas<<" s";
										hist=d;
							break; 
									}
					if(c>=70){
						GetSystemTime(&st);
										   	mink=st.wMinute-minp;
    										seck=st.wSecond-secp;
    										mink=mink*60;
    										czas=mink+seck;
						if(c>=70 && czas<=240){
						
						slow_print("                      !! WYGRALES !!",50);
						cout<<endl<<endl<<endl;
													  
										cout<<"liczba ruchow: "<<c<<endl;
										d=(d+czas)*c;
										cout<<"ilosc zdobytych punktow: "<<d<<endl;
										cout<<"uzyskany czas wynosi: "<<czas<<" s"<<endl;
										cout<<"maksymalny mozliwy czas wynosi: 240s";
										hist=d;
										}
						else{
							slow_print("                      !! PRZEGRALES !!",50);
										cout<<endl<<endl<<endl;
										cout<<"liczba ruchow: "<<c<<endl;
										d=(d+czas)*c;
										cout<<"ilosc zdobytych punktow: "<<d<<endl;
										cout<<"uzyskany czas wynosi: "<<czas<<" s"<<endl;
										cout<<"maksymalny mozliwy czas wynosi: 240s";
										hist=d;
										
						}

					}
			
			
			
			}
		}
	cout<<endl<<endl<<endl;
	cout<<"Aby uruchomic gre ponownie, napisz 'uruchom' lub 'zakoncz', aby zakonczyc rozgrywke: "<<endl;
	cout<<"Podaj swoj wybor: ";
	cin>>x;
}
 	   if(x==uruchom){
 	   	b=b+1;
		}
		else{
		system( "cls" );
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		slow_print("					ZAKONCZYLES GRE" ,50);
		cout<<endl<<endl;
		slow_print("					!! Dziekujemy !!" ,50);
		cout<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
			return 0;
		}
}
if(x==wlasna){
	while(x!=stworz){
	system( "cls" );
	slow_print("						SAPER - WLASNA GRA " ,50);
	cout<<endl<<endl<<endl<<endl;
	cout<<"	Znajdujesz sie w trybie, w ktorym mozesz sam stworzyc wlasna gre saper. "<<endl;
	cout<<"	Nie masz zadnych ograniczen, mozesz stworzyc plansze x na x, jednak pamietaj aby wartosci min byly poprawne. "<<endl<<endl<<endl;
	cout<<"Aby rozpoczac tworzenie wlasnej gry wpisz 'stworz': "<<endl;
	cout<<"Podaj swoj wybor: ";
	cin>>x;	
}
        if(x==stworz){
        	c=0;
			d=0;
			system( "cls" );
			slow_print("						SAPER - WLASNA GRA - STWORZ " ,50);
			cout<<endl<<endl<<endl<<endl;
        	cout<<"podaj ile na ile: ";
			cin>>k;
			char tabp2[k][k];
			char tp[k][k];
			
			cout<<"podaj co chcesz wpisac do tablicy: ";
			cin>>q;
			
			
			cout<<"plansza: "<<k<<" x "<<k<<endl;
			for(int i=1;i<k+1;i++){
					for(int j=1;j<k+1;j++){
						tabp2[i][j]=q; 
						tp[i][j]=q;
						//wyœwietlenie liczby lub wartoœci
					}
					cout<<endl;
				}
			
				for(int i=1;i<k+1;i++){
					for(int j=1;j<k+1;j++){
			
						cout<<"| "<<tabp2[i][j]<<" |";		
				}
					cout<<endl;
			}
				cout<<endl;
			cout<<endl;
			cout<<"Wpisuj wartosci zgodnie z polecieniami!!"<<endl;
			
			int wz, wy;

			for(int u=1;u<(k*k)+1;u++){

				cout<<"podaj wysokosc od 1 do "<<k<<": ";
				cin>>wz;
				
				cout<<"podaj szerokosc od 1 do "<<k<<": ";
				cin>>wy;	
				cout<<endl;
				cout<<"wpisz pola ktore sasiaduja z minami cyframi od 0 do 5 lub pola ktore sa minami - cyfra 9 "<<endl;
				cout<<"Podaj swoj wybor: ";
				cin>>q;
					   tabp2[wz][wy]=q;
				
				 system( "cls" );
				 cout<<endl<<endl<<endl;	
					for(int i=1;i<k+1;i++)
						{
							for(int j=1;j<k+1;j++)
							
								cout<<"| "<<tabp2[i][j]<<" |";
								
						cout<<endl;
						}
					}
					while(x!=graj){
					system( "cls" );
					slow_print("						SAPER - WLASNA GRA - STWORZ " ,50);
					cout<<endl<<endl<<endl<<endl;
				cout<<"Oto twoja plansza do gry: "<<endl<<endl;
						   for(int i=1;i<k+1;i++)
								{
									for(int j=1;j<k+1;j++)
									
										cout<<"| "<<tabp2[i][j]<<" |";
										
								cout<<endl;
								}
								cout<<"Ile bomb znajduje sie na planszy? ";
								cin>>bomby;
									cout<<"---------------------------"<<endl<<endl;
									cout<<"Aby zagrac, wpisz 'graj' "<<endl;
						   			cout<<"Podaj swoj wybor: ";
									cin>>x;
							}
							if(x==graj){
								system( "cls" );
								slow_print("						SAPER - WLASNA GRA - ROZGRYWKA " ,50);
								cout<<endl<<endl<<endl<<endl;
								
										SYSTEMTIME st;
						    			GetSystemTime(&st);
						    
									    secp=st.wSecond;
										minp=st.wMinute;
								
												 for(int i=1;i<k+1;i++)
								{
									for(int j=1;j<k+1;j++)
									
										cout<<"| "<<tp[i][j]<<" |";
										
								cout<<endl;
								}
										char p =0;
								wz=10; wy=10;
							while(tabp2[wz][wy]!='9' && c<(k*k)-bomby){
								c=c+1;
								cout<<endl;
								cout<<endl;
								cout<<endl;
							
								cout<<"podaj wysokosc od 1 do "<<k<<": ";
								cin>>wz;
								
								cout<<"podaj szerokosc od 1 do "<<k<<": ";
								cin>>wy;
								
								cout<<"T["<<wz<<"]["<<wy<<"]: "<<tabp2[wz][wy]<<endl;
								
								cout<<"---------------------------"<<endl;
				
									   p=tabp2[wz][wy];
						
								cout<<endl;
								        system( "cls" );
							cout<<"					SAPER - WLASNA GRA - ROZGRYWKA" <<endl<<endl;
											cout<<endl;
											cout<<endl;
								        cout<<"Poprzednio podane pole["<<wz<<"]["<<wy<<"] wynosilo: "<<p;
											cout<<endl;
											cout<<endl;
							 	  for(int i=1;i<k+1;i++){
											for(int j=1;j<k+1;j++){
												if(tabp2[wz][wy]!=tp[wz][wy]){
												    tp[wz][wy]=tabp2[wz][wy];					 
												}
												cout<<"| "<<tp[i][j]<<" |";
												}
											cout<<endl;
									}
							
									if(tabp2[wz][wy]=='9'){
				
														GetSystemTime(&st);
												   	mink=st.wMinute-minp;
		    										seck=st.wSecond-secp;
		    										mink=mink*60;
		    										czas=mink+seck;
												cout<<"BUM"<<endl;
												cout<<"BUM"<<endl;
												cout<<"BUM"<<endl;
												cout<<"BUM"<<endl<<endl;
												slow_print("                      !! PRZEGRALES !!", 50);
												cout<<endl<<endl<<endl;
												cout<<"liczba ruchow: "<<c<<endl;
											d=(d+czas)*c;
												cout<<"ilosc zdobytych punktow: "<<d<<endl;
												    
												cout<<"uzyskany czas wynosi: "<<czas<<" s";
												hist=d;
				
											break; 
													}
									if(c>=(k*k)-1){
										slow_print("                      !! WYGRALES !!", 50);
								cout<<endl<<endl<<endl;
								 							 GetSystemTime(&st);
												   	mink=st.wMinute-minp;
		    										seck=st.wSecond-secp;
		    										mink=mink*60;
		    										czas=mink+seck;
												cout<<"liczba ruchow: "<<c<<endl;
												d=(d+czas)*c;
												cout<<"ilosc zdobytych punktow: "<<d<<endl;
												cout<<"uzyskany czas wynosi: "<<czas<<" s";
												hist=d;
									}
							}
							cout<<endl<<endl<<endl;
	cout<<"Aby uruchomic gre ponownie, napisz 'uruchom' lub 'zakoncz', aby zakonczyc rozgrywke: "<<endl;
	cout<<"Podaj swoj wybor: ";
	cin>>x;
							 		} 
}
 	   if(x==uruchom){
 	   	b=b+1;
		}
		else{
		system( "cls" );
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		slow_print("					ZAKONCZYLES GRE" ,50);
		cout<<endl<<endl;
		slow_print("					!! Dziekujemy !!" ,50);
		cout<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
			return 0;
}
}
if(x==info){
	while(x!=uruchom && x!=end){
	system( "cls" );
	slow_print("						SAPER - INFORMACJE " ,50);
	cout<<endl<<endl;
	cout<<"	INFORMACJE O AUTORACH "<<endl<<endl;
	cout<<"Prace wykonali: "<<endl<<" > Wiktor Tatarynowicz"<<endl<<" > Filip Berg"<<endl<<" > klasa: 1C"<<endl<<endl;
	cout<<"Dziekujemy za zagranie w gre!"<<endl;
	cout<<"Zachecamy rowniez do zagrania ponownie";
	cout<<endl<<endl<<endl;
	cout<<"Aby uruchomic gre ponownie, napisz 'uruchom' lub 'zakoncz', aby zakonczyc rozgrywke: "<<endl;
	cout<<"Podaj swoj wybor: ";
	cin>>x;
	}
 	   if(x==uruchom){
 	   	b=b+1;
		}
		else{
			system( "cls" );
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		slow_print("					ZAKONCZYLES GRE",50);
		cout <<endl<<endl;
		slow_print("					!! Dziekujemy !!" ,50);
		cout<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
			return 0;
		}
	
}


}
else{
		while(x!=uruchom && x!=end){
	system( "cls" );
	slow_print("						SAPER - PANEL HISTORII " ,50);
	cout<<endl<<endl;
	cout<<"	HISTORIA OSTATNIEJ GRY"<<endl<<endl;
	cout<<"Panel histori przechowuje dane dotyczace ostatniej rozegranej gry"<<endl;
	cout<<"jezeli widzisz wartosci 0, zagraj i nastepnie tutaj wroc. "<<endl<<endl;
	cout<<"Czas gry: "<<czas<<"s"<<endl;
	cout<<"Liczba punktow: "<<hist<<endl;
	cout<<"Liczba ruchow: "<<c<<endl;
	cout<<endl<<endl<<endl;
	cout<<"Aby uruchomic gre ponownie, napisz 'uruchom' lub 'zakoncz', aby zakonczyc rozgrywke: "<<endl;
	cout<<"Podaj swoj wybor: ";
	cin>>x;
}

 if(x==uruchom){
 	   	b=b+1;
		}
		else{
			system( "cls" );
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		slow_print("					ZAKONCZYLES GRE",50);
		cout <<endl<<endl;
		slow_print("					!! Dziekujemy !!" ,50);
		cout<<endl<<endl;
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
			return 0;
		}	
}
}

	return 0;
}
