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
	T_pvirtvorrueckfragen,
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
	{"pvirtVorgbSpeziell()","pvirtspecialprefs()"},
	// T_virtMusterVorgb
	{"virtMusterVorgb()","virtsampleprefs"},
	// T_pvirtvorrueckfragen
	{"pvirtvorrueckfragen()","pvirtbeforecallbacks()"},
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
 // mitcron=0; //ω
	
} // hhcl::hhcl //α




// wird aufgerufen in lauf
void hhcl::virtVorgbAllg()
{
	Log(violetts+Tx[T_virtVorgbAllg]+schwarz); //ω

	dhcl::virtVorgbAllg(); //α

} // void hhcl::virtVorgbAllg

// wird aufgerufen in lauf
void hhcl::pvirtVorgbSpeziell()
{
	Log(violetts+Tx[T_virtVorgbSpeziell]+schwarz); //ω

	dhcl::pvirtVorgbSpeziell(); //α
	virtMusterVorgb();
} // void hhcl::pvirtVorgbSpeziell

// wird aufgerufen in lauf
void hhcl::virtinitopt()
{ //ω
	opn<<optcl(/*pname*/"",/*pptr*/&oblista,/*art*/puchar,T_lista_k,T_lista_l,/*TxBp*/&Tx,/*Txi*/T_listet_Zeilen_auf,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"n",/*pptr*/&listz,/*art*/plong,T_listz_k,T_listz_l,/*TxBp*/&Tx,/*Txi*/T_listet_n_Zeilen_auf_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);

	dhcl::virtinitopt(); //α
} // void hhcl::virtinitopt

// wird aufgerufen in lauf
void hhcl::pvirtmacherkl()
{
	erkl<<blau<<Txk[T_Program]<<violett<<DPROG //ω
		
		<<blau<<" ist etwas ganz Spezielles"<<schwarz; //α
} // void hhcl::pvirtmacherkl

// wird aufgerufen in lauf
void hhcl::virtMusterVorgb()
{
	Log(violetts+Tx[T_virtMusterVorgb]+schwarz); //ω

	dhcl::virtMusterVorgb(); //α
} // void hhcl::MusterVorgb

// wird aufgerufen in lauf
void hhcl::virtzeigversion(const string& ltiffv/*=nix*/)
{
	dhcl::virtzeigversion(ltiffv);
} // void hhcl::virtzeigversion

// wird aufgerufen in lauf
void hhcl::pvirtvorrueckfragen()
{
	Log(violetts+Tx[T_pvirtvorrueckfragen]+schwarz);
	if (rzf) { //ω

  } //α
} // void hhcl::pvirtvorrueckfragen

// wird aufgerufen in lauf
void hhcl::virtrueckfragen()
{
	Log(violetts+Tx[T_virtrueckfragen]+schwarz);
	if (rzf) { //ω

  } //α
	dhcl::virtrueckfragen();
} // void hhcl::virtrueckfragen()

// wird aufgerufen in lauf
void hhcl::virtpruefweiteres()
{

	hcl::virtpruefweiteres(); // z.Zt. leer
}

// wird aufgerufen in lauf
void hhcl::virtzeigueberschrift()
{
  // hier ggf. noch etwas an 'uebers' anhaengen
	hcl::virtzeigueberschrift();
}

// wird aufgerufen in lauf
void hhcl::pvirtfuehraus()
{

}

// wird aufgerufen in lauf
void hhcl::virtschlussanzeige()
{
	dhcl::virtschlussanzeige();
}

int main(int argc,char** argv)
{
	if (argc>1) {
	}
	hhcl hhi(argc,argv); // hiesige Hauptinstanz, mit lngzuw, setzlog und pruefplatte
	hhi.lauf(); // Einleitungsteil mit virtuellen Funktionen, 
	// mit virtVorgbAllg,pvirtVorgbSpeziell,initopt,parsecl,pvirtmacherkl,zeighilfe,lieskonfein,verarbeitkonf,lieszaehlerein,MusterVorgb,dovi,dovs,virtzeigversion
	// autokonfschreib,update,
} // int main //ω
// wird aufgerufen in: main

