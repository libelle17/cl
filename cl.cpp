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
	T_sqlv_k,
	T_sql_verbose_l,
	T_Verbindung_zur_Datenbank_nicht_herstellbar,
	T_Breche_ab,
	T_pruefDB,
	T_host_k,
	T_host_l,
	T_muser_k,
	T_muser_l,
	T_mpwd_k,
	T_mpwd_l,
	T_db_k,
	T_datenbank_l,
	T_tb_k,
	T_tabelle_l,
	T_Bildschirmausgabe_mit_SQL_Befehlen,
	T_verwendet_die_Datenbank_auf_Host_string_anstatt_auf,
	T_verwendet_fuer_MySQL_MariaDB_den_Benutzer_string_anstatt,
	T_verwendet_fuer_MySQL_MariaDB_das_Passwort_string,
	T_verwendet_die_Datenbank_string_anstatt,
	T_verwendet_die_Tabelle_string_anstatt,
	T_Host_fuer_MySQL_MariaDB_Datenbank,
	T_Benutzer_fuer_MySQL_MariaDB,
	T_Passwort_fuer_MySQL_MariaDB,
	T_Datenbankname_fuer_MySQL_MariaDB_auf,
	T_Tabellenname_in,
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
	// T_sqlv_k
	{"sqlw","sqlv"},
	// T_sql_verbose_l
	{"sql-wortreich","sql-verbose"},
	// T_Verbindung_zur_Datenbank_nicht_herstellbar
	{"Verbindung zur Datenbank nicht herstellbar, fehnr: ","Connection to the database could not be established, errnr: "},
	// T_Breche_ab
	{". Breche ab.","Stopping."},
	// T_pruefDB
	{"pruefDB(","checkDB("},
	// T_host_k
	{"host","host"},
	// T_host_l
	{"host","host"},
	// T_muser_k
	{"muser","muser"},
	// T_muser_l
	{"muser","muser"},
	// T_mpwd_k
	{"mpwd","mpwd"},
	// T_mpwd_l
	{"mpwd","mpwd"},
	// T_db_k
	{"db","db"},
	// T_datenbank_l
	{"datenbank","database"},
	// T_tb_k,
	{"tb","tb"},
	// T_tabelle_l,
	{"tabelle","table"},
	// T_Bildschirmausgabe_mit_SQL_Befehlen
	{"Bildschirmausgabe mit SQL-Befehlen","screen output with SQL commands"},
	// T_verwendet_die_Datenbank_auf_Host_string_anstatt_auf
	{"verwendet die Datenbank auf Host <string> anstatt auf","takes the database on host <string> instead of"},
	// T_verwendet_fuer_MySQL_MariaDB_den_Benutzer_string_anstatt
	{"verwendet fuer MySQL/MariaDB den Benutzer <string> anstatt","takes the user <string> for MySQL/MariaDB instead of"},
	// T_verwendet_fuer_MySQL_MariaDB_das_Passwort_string
	{"verwendet fuer MySQL/MariaDB das Passwort <string>","takes the password <string> for MySQL/MariaDB"},
	// T_verwendet_die_Datenbank_string_anstatt
	{"verwendet die Datenbank <string> anstatt","uses the database <string> instead of"},
	// T_verwendet_die_Tabelle_string_anstatt
	{"verwendet die Tabelle <string> anstatt","uses the table <string> instead of"},
	// T_Host_fuer_MySQL_MariaDB_Datenbank
	{"Host fuer MySQL/MariaDB-Datenbank","host for mysql/mariadb-database"},
	// T_Benutzer_fuer_MySQL_MariaDB,
	{"Benutzer fuer MySQL/MariaDB:","user for mysql/mariadb:"},
	// T_Passwort_fuer_MySQL_MariaDB,
	{"Passwort fuer MySQL/MariaDB (Achtung: nur schwach verschluesselt!)","password for mysql/mariadb (caution: only weakly encrypted!)"},
	// T_Datenbankname_fuer_MySQL_MariaDB_auf
	{"Datenbankname fuer MySQL/MariaDB auf '","database name for mysql/mariabd on '"},
	// T_Tabellenname_in
	{"Tabellenname in '","table name in '"},
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
uchar ZDB=0; // fuer Zusatz-Debugging (SQL): ZDB 1, sonst: 0
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen; muss dann auf lgp zeigen;
const string& pwk = "4893019320jfdksalö590ßs89d0qÃ9m0943Ã09Ãax"; // fuer Antlitzaenderung

using namespace std;

#ifdef mitpostgres 
const DBSTyp myDBS=Postgres;
#else // mitpostgre
const DBSTyp myDBS=MySQL;
#endif // mitpostgres else


hhcl::hhcl(const int argc, const char *const *const argv):hcl(argc,argv,DPROG)
{
} // hhcl::hhcl

hhcl::~hhcl()
{
} // hhcl::~hhcl

// wird aufgerufen in: rueckfragen, parsecl, lieskonfein, hcl::hcl nach holsystemsprache
void hhcl::lgnzuw()
{
	hcl::lgnzuw();
	Txd.lgn=Tx.lgn=Txk.lgn;
} // void hhcl::lgnzuw

void hhcl::spezopt()
{
	static string listzs=ltoan(listz);

	opn<<optcl(/*pname*/"",/*pptr*/&oblista,/*art*/puchar,T_lista_k,T_lista_l,/*TxBp*/&Tx,/*Txi*/T_listet_Zeilen_auf,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"n",/*pptr*/&listz,/*art*/plong,T_listz_k,T_listz_l,/*TxBp*/&Tx,/*Txi*/T_listet_n_Zeilen_auf_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);
	opn<<optcl(/*pname*/"host",/*pptr*/&host,/*art*/psons,T_host_k,T_host_l,/*TxBp*/&Tx,/*Txi*/T_verwendet_die_Datenbank_auf_Host_string_anstatt_auf,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);
	opn<<optcl(/*pname*/"muser",/*pptr*/&muser,/*art*/psons,T_muser_k,T_muser_l,/*TxBp*/&Tx,/*Txi*/T_verwendet_fuer_MySQL_MariaDB_den_Benutzer_string_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);
	opn<<optcl(/*pname*/"mpwd",/*pptr*/&mpwd,/*art*/ppwd,T_mpwd_k,T_mpwd_l,/*TxBp*/&Tx,/*Txi*/T_verwendet_fuer_MySQL_MariaDB_das_Passwort_string,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);
	opn<<optcl(/*pname*/"datenbank",/*pptr*/&dbq,/*art*/psons,T_db_k,T_datenbank_l,/*TxBp*/&Tx,/*Txi*/T_verwendet_die_Datenbank_string_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);
	opn<<optcl(/*pname*/"tabelle",/*pptr*/&tabelle,/*art*/psons,T_tb_k,T_tabelle_l,/*TxBp*/&Tx,/*Txi*/T_verwendet_die_Tabelle_string_anstatt,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);
	opn<<optcl(/*pname*/"",/*pptr*/&ZDB,/*art*/puchar,T_sqlv_k,T_sql_verbose_l,/*TxBp*/&Tx,/*Txi*/T_Bildschirmausgabe_mit_SQL_Befehlen,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);
} // void hhcl::spezopt


void hhcl::VorgbAllg()
{
	Log(violetts+Tx[T_VorgbAllg]+schwarz);
	cronminut="0";
	autoupd=1;
} // void hhcl::VorgbAllg

void hhcl::VorgbSpeziell()
{
	Log(violetts+Tx[T_VorgbSpeziell]+schwarz);
	MusterVorgb();
} // void hhcl::VorgbSpeziell

void hhcl::MusterVorgb()
{
	Log(violetts+Tx[T_MusterVorgb]+schwarz);
} // void hhcl::MusterVorgb


// wird aufgerufen in: main
void hhcl::rueckfragen()
{
	Log(violetts+Tx[T_rueckfragen]+schwarz);
	hcl::rueckfragen();
	if (rzf) {
		host=Tippstr(Tx[T_Host_fuer_MySQL_MariaDB_Datenbank],&host);
		const string Frage=Tx[T_Benutzer_fuer_MySQL_MariaDB];
		muser=Tippstr(Frage.c_str(),&muser);
		string mpw2;
		mpwd.clear();
		do {
			mpwd=Tippstr(string(Tx[T_Passwort_fuer_MySQL_MariaDB])+Txk[T_fuer_Benutzer]+dblau+muser+schwarz+"'",&mpwd);
			mpw2=Tippstr(string(Tx[T_Passwort_fuer_MySQL_MariaDB])+Txk[T_fuer_Benutzer]+dblau+muser+schwarz+"'"+" ("+Txk[T_erneute_Eingabe]+")",&mpw2);
		} while (mpwd!=mpw2);
		const string pwdstr=XOR(mpwd,pwk);
		dbq=Tippstr(string(Tx[T_Datenbankname_fuer_MySQL_MariaDB_auf])+dblau+host+schwarz+"'",&dbq);
		tabelle=Tippstr(string(Tx[T_Tabellenname_in])+dblau+dbq+schwarz+"'",&tabelle);
	} // if (rzf)
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
// wird aufgerufen in: main //α
int hhcl::initDB()
{
	Log(violetts+"initDB(), db: "+blau+dbq+schwarz);
	unsigned int fehler=0;
	if (dbq.empty()) {
		fehler=1046;
	} else {
		if (!My) {
			My=new DB(myDBS,linstp,host,muser,mpwd,maxconz,dbq,/*port=*/0,/*unix_socket=*/0,/*client_flag=*/0,obverb,oblog);
			if (My->ConnError) {
				delete My;
				My=0;
			} else {
				My->lassoffen=1;
			} // 			if (My->ConnError) else
		} // 		if (!My)
		fehler=My->fehnr;
	} // 	if (dbq.empty())
	if (fehler) {
		Log(rots+Tx[T_Verbindung_zur_Datenbank_nicht_herstellbar]+schwarz+ltoan(fehler)+rot+Tx[T_Breche_ab]+schwarz);
		return 1;
	} //   if (My->fehnr)
	return 0;
} // initDB

// wird aufgerufen in rueckfragen
int hhcl::pruefDB(const string& db)
{
	Log(violetts+Tx[T_pruefDB]+db+")"+schwarz);
	if (!My) {
		My=new DB(myDBS,linstp,host,muser,mpwd,maxconz,db,0,0,0,obverb,oblog,DB::defmycharset,DB::defmycollat,3,0);
		if (My->ConnError) {
			delete My;
			My=0;
		}else {
			My->lassoffen=1;
		}
	} // 	if (!My)
	return (My->fehnr); 
} // pruefDB //ω
//α


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

