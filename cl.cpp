// '//α' oder '//ω' als Kommentar sind nur für die Verwendung dieses Programms als Programmvorlage wichtig
// sed -n '/\/\/α/,/\/\/ω/p;/\/\/ω/a\\' test
// sed -n '/\/\/α/,/\/\/ω/p' test
#include "kons.h" //α
#include "DB.h" 
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "cl.h"
#include <map>
// für verschiedene Sprachen //α
enum T_      
{
	T_VorgbAllg,
	T_VorgbSpeziell,
	T_MusterVorgb,
	T_rueckfragen,
	T_Logpfad,
	T_oblog,
	T_Aufrufintervall,
	T_kein_Aufruf,
	T_Minute,
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
	// T_VorgbAllg
	{"VorgbAllg()","generalprefs()"},
	// T_VorgbSpeziell
	{"VorgbSpeziell()","specialprefs()"},
	// T_MusterVorgb
	{"MusterVorgb()","sampleprefs"},
	// T_rueckfragen
	{"rueckfragen()","callbacks()"},
	// T_Logpfad,
	{"Logpfad: '","Log path: '"},
	// T_oblog,
	{"' (oblog: ","' (with logging: "},
	// T_Aufrufintervall
	{"; Aufrufintervall: ","; (cron) call interval: "},
	// T_kein_Aufruf
	{"kein cron-Aufruf","no cron call"},
	// T_Minute
	{" Minute"," minute"},
	//	T_Fehler_beim_Pruefen_von
	{"Fehler beim Pruefen von: ","Error while examining: "},
	// T_Fuege_ein
	{"Füge ein: ","Inserting: "}, //ω
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
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen; muss dann auf lgp zeigen;

using namespace std;

#ifdef mitpostgres 
const DBSTyp myDBS=Postgres;
#else // mitpostgre
const DBSTyp myDBS=MySQL;
#endif // mitpostgres else


hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG)
{
} // hhcl::hhcl

hhcl::~hhcl()
{
} // hhcl::~hhcl

// wird aufgerufen in: rueckfragen, parsecl, lieskonfein, hcl::hcl nach holsystemsprache
void hhcl::lgnzuw()
{
	dhcl::lgnzuw();
	Tx.lgn=Txk.lgn;
} // void hhcl::lgnzuw

void hhcl::initopt()
{
	static string listzs=ltoan(listz);
	opn<<optcl(/*pname*/"",/*pptr*/&oblista,/*art*/puchar,T_lista_k,T_lista_l,/*TxBp*/&Tx,/*Txi*/T_listet_Zeilen_auf,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"n",/*pptr*/&listz,/*art*/plong,T_listz_k,T_listz_l,/*TxBp*/&Tx,/*Txi*/T_listet_n_Zeilen_auf_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);
	dhcl::initopt();
} // void hhcl::initopt


void hhcl::VorgbAllg()
{
	Log(violetts+Tx[T_VorgbAllg]+schwarz);
	dhcl::VorgbAllg();

} // void hhcl::VorgbAllg

void hhcl::VorgbSpeziell()
{
	Log(violetts+Tx[T_VorgbSpeziell]+schwarz);
	dhcl::VorgbSpeziell();
	MusterVorgb();
} // void hhcl::VorgbSpeziell

void hhcl::MusterVorgb()
{
	Log(violetts+Tx[T_MusterVorgb]+schwarz);
	dhcl::MusterVorgb();
} // void hhcl::MusterVorgb


// wird aufgerufen in: main
void hhcl::rueckfragen()
{
	Log(violetts+Tx[T_rueckfragen]+schwarz);
	if (rzf) {

  }
	dhcl::rueckfragen();
} // void hhcl::rueckfragen()


// wird aufgerufen in: main
void hhcl::zeigueberschrift()
{
	char buf[20]; snprintf(buf,sizeof buf,"%.5f",versnr);
	::Log(schwarzs+Txk[T_Programm]+blau+mpfad+schwarz+", V: "+blau+buf+schwarz
			+(crongeprueft?
				Tx[T_Aufrufintervall]+blaus
				+(vorcm!=cronminut&&!(vorcm.empty()&&cronminut=="0")?((vorcm.empty()?Txk[T_gar_nicht]:vorcm)+" -> "):"")
				+(cronminut=="0"?Tx[T_kein_Aufruf]+schwarzs:cronminut+schwarz+(cronminut=="1"?Tx[T_Minute]:Txk[T_Minuten])):
				"")
			,1,oblog);
} // void hhcl::zeigueberschrift

void hhcl::pruefggfmehrfach()
{
	if (!obhilfe &&!obvi &&!obvs &&!zeigvers &&!rzf) {
		pruefmehrfach(meinname,nrzf);
	}
} // void hhcl::pruefggfmehrfach()
//ω

void hhcl::macherkl()
{
	erkl<<blau<<"Programm "<<violett<<DPROG<<blau<<" ist etwas ganz Spezielles"<<schwarz;
}

int main(int argc,char** argv)
{
	if (argc>1) {
	}
	hhcl hhi(argc,argv); // hiesige Hauptinstanz
	hhi.fangan(); // Einleitungsteil mit Aufruf virtueller Funktionen

	caus<<"keineverarbeitung: "<<(int)hhi.keineverarbeitung<<endl;
	if (!hhi.keineverarbeitung) {
		caus<<"rzf: "<<(int)hhi.rzf<<endl;
		hhi.rueckfragen();
		hhi.pruefggfmehrfach();
		caus<<"nach pruefggfmehrfach"<<endl;
		if (hhi.logdateineu) tuloeschen(logdt,"",hhi.obverb,hhi.oblog);
		caus<<"nach tuloeschen"<<endl;
		hhi.Log(Tx[T_Logpfad]+drots+hhi.loggespfad+schwarz+Tx[T_oblog]+drot+ltoan((int)hhi.oblog)+schwarz+")");
//		if (hhi.initDB()) return 10; //ω
	} // 	if (!hhi.keineverarbeitung) //α

	hhi.pruefcron(nix); // soll vor Log(Tx[T_Verwende ... stehen
	caus<<"nach pruefcron"<<endl;
	if (!hhi.keineverarbeitung) {
		hhi.zeigueberschrift(); //ω
	caus<<"nach zeigueberschrift"<<endl;
		hhi.setzzaehler(); //α
	caus<<"nach setzzaehler"<<endl;
		hhi.schreibzaehler();
	caus<<"nach schreibzaehler"<<endl;
	} //  if (!hhi.keineverarbeitung)
	caus<<"nach keineverarbeitung"<<endl;
} // int main //ω
// wird aufgerufen in: main

