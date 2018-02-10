// '//α' oder '//ω' als Kommentar sind nur für die Verwendung dieses Programms als Programmvorlage wichtig
// sed -n '/\/\/α/,/\/\/ω/p;/\/\/ω/a\\' test
// sed -n '/\/\/α/,/\/\/ω/p' test
#include "kons.h" //α
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "cl.h"
// für verschiedene Sprachen //α
enum T_      
{
	T_virtVorgbAllg,
	T_virtVorgbSpeziell,
	T_virtMusterVorgb,
	T_virtrueckfragen,
	T_Fehler_beim_Pruefen_von,
	T_Fuege_ein, //ω
	T_lista_k,
	T_lista_l,
	T_listz_k,
	T_listz_l,
	T_listet_Zeilen_auf,
	T_listet_n_Zeilen_auf_anstatt,
	T_MAX //α
}; // enum T_ //ω

// für verschiedene Sprachen //α
char const *DPROG_T[T_MAX+1][SprachZahl]={
	// T_virtVorgbAllg
	{"virtVorgbAllg()","virtgeneralprefs()"},
	// T_virtVorgbSpeziell
	{"virtVorgbSpeziell()","virtspecialprefs()"},
	// T_virtMusterVorgb
	{"virtMusterVorgb()","virtsampleprefs"},
	// T_virtrueckfragen
	{"virtrueckfragen()","virtcallbacks()"},
	//	T_Fehler_beim_Pruefen_von
	{"Fehler beim Pruefen von: ","Error while examining: "},
	// T_Fuege_ein
	{"Fuege ein: ","Inserting: "}, //ω
	// T_lista_k,
	{"lista","lista"},
	// T_lista_l,
	{"lista","lista"},
	// T_listz_k,
	{"n","n"},
	// T_listz_l,
	{"zahl","number"},
	// T_listet_Zeilen_auf
	{"listet Zeilen auf","lists lines"},
	// T_listet_n_Zeilen_auf_anstatt
	{"listet n Zeilen auf anstatt ","lists n lines instead of "},
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;

using namespace std;


hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG)
{
 // mitcron=0;
} // hhcl::hhcl

void hhcl::virtinitopt()
{
	opn<<optcl(/*pname*/"",/*pptr*/&oblista,/*art*/puchar,T_lista_k,T_lista_l,/*TxBp*/&Tx,/*Txi*/T_listet_Zeilen_auf,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"n",/*pptr*/&listz,/*art*/plong,T_listz_k,T_listz_l,/*TxBp*/&Tx,/*Txi*/T_listet_n_Zeilen_auf_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);

	dhcl::virtinitopt();
} // void hhcl::virtinitopt


void hhcl::virtVorgbAllg()
{
	Log(violetts+Tx[T_virtVorgbAllg]+schwarz);

	dhcl::virtVorgbAllg();

} // void hhcl::virtVorgbAllg

void hhcl::virtVorgbSpeziell()
{
	Log(violetts+Tx[T_virtVorgbSpeziell]+schwarz);

	dhcl::virtVorgbSpeziell();
	virtMusterVorgb();
} // void hhcl::virtVorgbSpeziell

void hhcl::virtMusterVorgb()
{
	Log(violetts+Tx[T_virtMusterVorgb]+schwarz);

	dhcl::virtMusterVorgb();
} // void hhcl::MusterVorgb


// wird aufgerufen in: main
void hhcl::virtrueckfragen()
{
	Log(violetts+Tx[T_virtrueckfragen]+schwarz);
	if (rzf) {

  }
	dhcl::virtrueckfragen();
} // void hhcl::virtrueckfragen()


void hhcl::virtmacherkl()
{
	erkl<<blau<<"Programm "<<violett<<DPROG
		
		<<blau<<" ist etwas ganz Spezielles"<<schwarz;
}

void hhcl::virtzeigueberschrift()
{

	hcl::virtzeigueberschrift();
}

int main(int argc,char** argv)
{
	if (argc>1) {
	}
	hhcl hhi(argc,argv); // hiesige Hauptinstanz, mit lngzuw, setzlog und pruefplatte
	hhi.lauf(); // Einleitungsteil mit virtuellen Funktionen, 
	// mit virtVorgbAllg,virtVorgbSpeziell,initopt,parsecl,virtmacherkl,zeighilfe,lieskonfein,verarbeitkonf,lieszaehlerein,MusterVorgb,dovi,dovs,virtzeigversion
	// autokonfschreib,update,
} // int main //ω
// wird aufgerufen in: main

