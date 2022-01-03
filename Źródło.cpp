#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
using namespace std;

class Zamowienie
{
public:
	string danie;
	int id_zamowienia;
	float cena;
	bool status;
	string data;
};

class Karta
{
public:
	float srodki_karta;
	bool autoryzacja();
};
bool Karta::autoryzacja()
{
	int confirm;
	cout << "Jesli potwierdzasz platnosc to nacisnij 1, jesli nie, nacisnij 0";
	cin >> confirm;
	if (confirm == 1) return(true);
	else return false;
}

class Gotowka
{
public:
	float srodki_gotowka;
};

class Platnosc : public Karta, public Gotowka
{
public:
	float kwota;
};

class Klient
{
public:
	Zamowienie zamowienie;
	string imie;
	void zloz_zamowienie(Klient klient, Zamowienie danie);
	float zrealizuj_platnosc_karta(Zamowienie zamowienie, Karta karta);
	float zrealizuj_platnosc_gotowka(Zamowienie zamowienie, Gotowka gotowka);
	void zarezerwuj_stolik();
};
void Klient::zloz_zamowienie(Klient klient, Zamowienie zamowienie)
{
	cout << endl << "Nazwa zamawianego dania: ";
	cin >> klient.zamowienie.danie;
}
float Klient::zrealizuj_platnosc_karta(Zamowienie zamowienie, Karta karta)
{
	karta.autoryzacja();
	if (karta.autoryzacja() == true)
	{
		float pom = karta.srodki_karta;
		if (karta.srodki_karta >= pom - zamowienie.cena) return zamowienie.cena;
		else return(karta.srodki_karta);
		karta.srodki_karta = pom - zamowienie.cena;
	}
	else return -1;
}
float Klient::zrealizuj_platnosc_gotowka(Zamowienie zamowienie, Gotowka gotowka)
{
	float pom = gotowka.srodki_gotowka;
	if (gotowka.srodki_gotowka >= pom - zamowienie.cena) return zamowienie.cena;
	else return(gotowka.srodki_gotowka);
	gotowka.srodki_gotowka = pom - zamowienie.cena;
}
void Klient::zarezerwuj_stolik()
{

}

class Raport
{
public:
	int id_raportu;
	string skladniki_nazwa[15];
	int skladniki_ilosc[15];
	int utarg_karta;
	int utarg_gotowka;
	void drukuj();
	void nazwy_skladnikow();
	//void ilosc_skladnikow();
};
void Raport::drukuj()
{

}
void Raport::nazwy_skladnikow()
{
	skladniki_nazwa[0] = "ciasto";
	skladniki_nazwa[1] = "sos";
	skladniki_nazwa[2] = "mozarella";
	skladniki_nazwa[3] = "gouda";
	skladniki_nazwa[4] = "parmezan";
	skladniki_nazwa[5] = "salami";
	skladniki_nazwa[6] = "chorizo";
	skladniki_nazwa[7] = "boczek";
	skladniki_nazwa[8] = "cebula";
	skladniki_nazwa[9] = "pomidory";
	skladniki_nazwa[10] = "pieczarki";
	skladniki_nazwa[11] = "oliwki";
	skladniki_nazwa[12] = "kukurydza";
	skladniki_nazwa[13] = "papryka";
	skladniki_nazwa[14] = "keczup";
}
/*void Raport::ilosc_skladnikow(Raport raport)
{
	cout << "Wpisz ilosc skladnikow: " << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << skladniki_nazwa[i] << ": ";
		cin >> skladniki_ilosc[i];
	}
}*/

class System
{
public:
	Zamowienie zamowienie;
	int skladniki_do_dania[15];
	int* ksiazka_kucharska(Zamowienie zamowienie);
	void wypisz_potrzebne_skladniki();
};
int* System::ksiazka_kucharska(Zamowienie zamowienie)
{
	if (zamowienie.danie == "Desperado")
	{
		skladniki_do_dania[0] = 1;
		skladniki_do_dania[1] = 1;
		skladniki_do_dania[2] = 1;
		skladniki_do_dania[3] = 1;
		skladniki_do_dania[4] = 0;
		skladniki_do_dania[5] = 1;
		skladniki_do_dania[6] = 1;
		skladniki_do_dania[7] = 1;
		skladniki_do_dania[8] = 1;
		skladniki_do_dania[9] = 0;
		skladniki_do_dania[10] = 1;
		skladniki_do_dania[11] = 1;
		skladniki_do_dania[12] = 1;
		skladniki_do_dania[13] = 1;
		skladniki_do_dania[14] = 1;
	}
	if (zamowienie.danie == "Vege")
	{
		skladniki_do_dania[0] = 1;
		skladniki_do_dania[1] = 1;
		skladniki_do_dania[2] = 1;
		skladniki_do_dania[3] = 0;
		skladniki_do_dania[4] = 0;
		skladniki_do_dania[5] = 0;
		skladniki_do_dania[6] = 0;
		skladniki_do_dania[7] = 0;
		skladniki_do_dania[8] = 1;
		skladniki_do_dania[9] = 1;
		skladniki_do_dania[10] = 1;
		skladniki_do_dania[11] = 1;
		skladniki_do_dania[12] = 0;
		skladniki_do_dania[13] = 1;
		skladniki_do_dania[14] = 1;
	}
	if (zamowienie.danie == "Pepperoni")
	{
		skladniki_do_dania[0] = 1;
		skladniki_do_dania[1] = 1;
		skladniki_do_dania[2] = 0;
		skladniki_do_dania[3] = 0;
		skladniki_do_dania[4] = 1;
		skladniki_do_dania[5] = 1;
		skladniki_do_dania[6] = 1;
		skladniki_do_dania[7] = 0;
		skladniki_do_dania[8] = 0;
		skladniki_do_dania[9] = 1;
		skladniki_do_dania[10] = 0;
		skladniki_do_dania[11] = 1;
		skladniki_do_dania[12] = 0;
		skladniki_do_dania[13] = 1;
		skladniki_do_dania[14] = 1;
	}
	if (zamowienie.danie == "Wiejska")
	{
		skladniki_do_dania[0] = 1;
		skladniki_do_dania[1] = 1;
		skladniki_do_dania[2] = 0;
		skladniki_do_dania[3] = 1;
		skladniki_do_dania[4] = 0;
		skladniki_do_dania[5] = 0;
		skladniki_do_dania[6] = 0;
		skladniki_do_dania[7] = 1;
		skladniki_do_dania[8] = 1;
		skladniki_do_dania[9] = 0;
		skladniki_do_dania[10] = 1;
		skladniki_do_dania[11] = 0;
		skladniki_do_dania[12] = 1;
		skladniki_do_dania[13] = 0;
		skladniki_do_dania[14] = 1;
	}
	return skladniki_do_dania;
}
void System::wypisz_potrzebne_skladniki()
{

}

class Kasjer
{
public:
	Zamowienie zamowienie;
	Raport raport;
	System system;
	int id_kasjera;
	bool weryfikacja_zamowienia(Raport raport, Zamowienie zamowienie, System system);
	void dodaj_zamowienie(Zamowienie zamowienie, System system, Raport raport);
	//void usun_zamowienie(Zamowienie zamowienie);
	//void edytuj_zamowienie(Zamowienie zamowienie);
	//void odrzuc_zamowienie(Zamowienie zamowienie);
	void weryfikacja_platnosci(Platnosc platnosc, Zamowienie zamowienie);
	void wydanie_rachunku();
	void wydaj_paragon();
	void pobierz_liste_sprzedarzy();
	Raport wprowadz_do_systemu();
};
bool Kasjer::weryfikacja_zamowienia(Raport raport, Zamowienie zamowienie, System system)
{
	int* tab = new int[15];
	tab = system.ksiazka_kucharska(zamowienie);
	//Weryfikacja iloœci sk³adników:
	int counter = 0;
	for (int i = 0; i < 15; i++)
	{
		if (raport.skladniki_ilosc[i] - tab[i] < 0) counter++;
	}
	if (counter == 0) return true;
	else if (counter > 0) return false;
}
void Kasjer::dodaj_zamowienie(Zamowienie zamowienie, System system, Raport raport)
{
	//Klient wybiera danie, a kasjer uzupe³nia id zamówienia, datê i status.
	cout << endl << "Uzupelnianie zamowienia: " << endl;
	cout << "id_zamowienia: ";
	cin >> zamowienie.id_zamowienia;
	//¯eby uzupe³niæ cenê zamówienia, wywo³ujê metodê menu, która uzupe³nia cenê dla naszego obiektu.
	system.ksiazka_kucharska(zamowienie);
	cout << "Status zamowienia: ";
	cin >> zamowienie.status;
	cout << "Data zamowienia: ";
	cin >> zamowienie.data;
	cout << endl << endl;
}
/*void Kasjer::usun_zamowienie(Zamowienie zamowienie)
{

}*/
/*void Kasjer::edytuj_zamowienie(Zamowienie zamowienie)
{

}*/
/*void Kasjer::odrzuc_zamowienie(Zamowienie zamowienie)
{

}*/
void Kasjer::weryfikacja_platnosci(Platnosc platnosc, Zamowienie zamowienie)
{

}
void Kasjer::wydanie_rachunku()
{

}
void Kasjer::wydaj_paragon()
{

}
void Kasjer::pobierz_liste_sprzedarzy()
{

}
Raport Kasjer::wprowadz_do_systemu()
{
	raport.nazwy_skladnikow();
	cout << endl << "Podaj liczbe porcji skladnikow: " << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << raport.skladniki_nazwa[i] << ": ";
		cin >> raport.skladniki_ilosc[i];
	}
	return raport;
}

class Pizza_Artist
{
public:
	int id_pa;
	void sprawdz_stan_magazynu();
	void pobierz_produkty_z_magazynu();
	void zrob_raport();
	void wykonanie_pizzy();
	void pobierz_raport();
};
void Pizza_Artist::sprawdz_stan_magazynu()
{

}
void Pizza_Artist::pobierz_produkty_z_magazynu()
{

}
void Pizza_Artist::zrob_raport()
{

}
void Pizza_Artist::wykonanie_pizzy()
{

}
void Pizza_Artist::pobierz_raport()
{

}

class Manager
{
public:
	int id_managera;
	void uzupelnij_magazyn();
	void zweryfikuj_arkusz();
	void zdeponuj_utarg();
};
void Manager::uzupelnij_magazyn()
{

}
void Manager::zweryfikuj_arkusz()
{

}
void Manager::zdeponuj_utarg()
{

}

int main()
{
	//Program rozpoczyna siê od kasjera, który wprowadza stan pocz¹tkowy wszystkich sk³adników do raportu.
	//Potrzebujemy równie¿ listy sk³adników potrzebnych dop wykonania poszczególnych dañ, któr¹ przechowuj¹ obiekty klasy System.
	//Tworzymy obiekty klas Kasjer, Raport i System.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "----------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "KASJER" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	Kasjer kasjer;
	Raport raport;
	System system;
	raport=kasjer.wprowadz_do_systemu();
	cout << endl << "Skladniki zostaly wprowadzone do systemu. " << endl<<endl;

	//Tworzony jest nowy klient.
	Klient klient;
	cout << "----------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); 
	cout << "KLIENT" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
	cout << "Witamy w naszej Pizzerii! Podaj swoje imie: ";
	cin >> klient.imie;

	//Klient wpisuje swoje œrodki w gotówce i na karcie.
	//Tworzymy obiekt klasy Karta i Gotówka.
	Karta karta;
	Gotowka gotowka;
	cout << endl << "Podaj srodki na karcie: ";
	cin >> karta.srodki_karta;
	cout << "Podaj srodki w gotowce: ";
	cin >> gotowka.srodki_gotowka;

	//Klient wybiera pizzê któr¹ chce zamówiæ.
	cout << "Wybierz pizze ktora chcialbys zamowic." << endl;
	cout << "1 -> Desperado" << endl;
	cout << "2 -> Vege" << endl;
	cout << "3 -> Pepperoni" << endl;
	cout << "4 -> Wiejska" << endl;
	cout << "Podaj numer: ";
	int pom;
	cin >> pom;

	//Tworzymy nowe zamowienie.
	Zamowienie zamowienie;
	if (pom == 1)
	{
		zamowienie.danie = "Desperado";
		zamowienie.cena = 30;
	}
	if (pom == 2) 
	{
		zamowienie.danie = "Vege";
		zamowienie.cena = 27;
	}
	if (pom == 3)
	{
		zamowienie.danie = "Pepperoni";
		zamowienie.cena = 28;
	}
	if (pom == 4)
	{
		zamowienie.danie = "Wiejska";
		zamowienie.cena = 29;
	}

	cout << endl;
	cout << "----------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "KASJER" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	//Kasjer przystêpuje do weryfikacji zamowienia.
	if (kasjer.weryfikacja_zamowienia(raport, zamowienie, system) == false) exit(-1);
	if (kasjer.weryfikacja_zamowienia(raport, zamowienie, system) == true) cout<<"Zamowienie moze zostac zrealizowane"<<endl<<endl;

	cout << "----------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "KLIENT" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	//P³atnoœæ: klient wybiera sposób p³atnoœci, przeprowadza p³atnoœæ, a kasjer j¹ weryfikuje.
	
	

}
