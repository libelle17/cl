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
	T_Sollen_neue_Programmversionen_von,
	T_automatisch_installiert_werden,
	T_Logpfad,
	T_oblog,
	T_Oblog,
	T_Aufrufintervall,
	T_kein_Aufruf,
	T_Minute,
	T_sqlv_k,
	T_sql_verbose_l,
	T_Logverzeichnis,
	T_Logdateiname,
	Verbindung_zur_Datenbank_nicht_herstellbar,
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
	// T_Sollen_neue_Programmversionen_von
	{"Sollen neue Programmversionen von ","Shall new versions of "},
	// T_automatisch_installiert_werden
	{" automatisch installiert werden?"," be automatically installed?"},
	// T_Logpfad,
	{"Logpfad: '","Log path: '"},
	// T_oblog,
	{"' (oblog: ","' (with logging: "},
	// T_Oblog,
	{"Oblog (ausführliche Protokollierung): ","Log (detailled logging): "},
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
	// T_Logverzeichnis
	{"Logverzeichnis","log directory"},
	// T_Logdateiname
	{"Logdateiname","log file name"},
	// Verbindung_zur_Datenbank_nicht_herstellbar
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

// wird aufgerufen in: rueckfragen, als virtualle Funktion von hcl::gcl0()
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
} // void hhcl::spezopt()


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
void hhcl::lieskonfein(const string& dprog)
{
	hcl::lieskonfein(dprog);
	/*
	lfd++;
	if (logvneu) agcnfA[lfd].setze(&logvz);
	if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&logvz); else rzf=1; lfd++;
	if (logdneu) agcnfA[lfd].setze(&logdname);
	if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&logdname); else rzf=1; lfd++;
	if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&oblog); else rzf=1; lfd++; 
	if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&cronminut); else rzf=1; lfd++;
	if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&autoupd); else rzf=1; lfd++;
	if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&host); else rzf=1; lfd++;
	if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&muser); else rzf=1; lfd++;
	if (agcnfA[lfd].gelesen) mpwd=XOR(string(agcnfA[lfd].wert),pwk); else rzf=1; lfd++;
	if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&dbq); else rzf=1; lfd++;
	if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&tabelle); else rzf=1; lfd++; //ω
	*/
	setzlog(); //α
	if (nrzf) rzf=0;
} // void hhcl::lieskonfein

//wird aufgerufen in: main
int hhcl::getcommandline()
{
#ifdef alt
	Log(violetts+"getcommandline()"+schwarz);
	opts.push_back(/*2*/optioncl(T_host_k,T_host_l,&Tx, T_verwendet_die_Datenbank_auf_Host_string_anstatt_auf,0,&host,psons,&agcnfA,"host",&obkschreib));
	opts.push_back(/*2*/optioncl(T_muser_k,T_muser_l,&Tx, T_verwendet_fuer_MySQL_MariaDB_den_Benutzer_string_anstatt,0,&muser,psons,&agcnfA, "muser",&obkschreib));
	opts.push_back(/*2*/optioncl(T_mpwd_k,T_mpwd_l,&Tx, T_verwendet_fuer_MySQL_MariaDB_das_Passwort_string,0,&mpwd,psons,&agcnfA,"mpwd",&obkschreib));
	opts.push_back(/*2*/optioncl(T_db_k,T_datenbank_l,&Tx, T_verwendet_die_Datenbank_string_anstatt,0,&dbq,psons,&agcnfA,"datenbank",&obkschreib));
	opts.push_back(/*2*/optioncl(T_tb_k,T_tabelle_l,&Tx, T_verwendet_die_Tabelle_string_anstatt,0,&tabelle,psons,&agcnfA,"tabelle",&obkschreib)); //ω
	opts.push_back(/*3*/optioncl(T_cm_k,T_cronminuten_l,&Tx,T_Alle_wieviel_Minuten_soll,1,&meinname,T_aufgerufen_werden_0_ist_gar_nicht,&cronminut, psons, &agcnfA,"cronminut",&obkschreib)); //α
	opts.push_back(/*4*/optioncl(T_autoupd_k,T_autoupd_l, &Tx, T_Programm_automatisch_aktualisieren,1,&autoupd,1,&agcnfA,"autoupd",&obkschreib));
	opts.push_back(/*4*/optioncl(T_sqlv_k,T_sql_verbose_l, &Tx, T_Bildschirmausgabe_mit_SQL_Befehlen,1,&ZDB,1));
	opts.push_back(/*4*/optioncl(T_rf_k,T_rueckfragen_l, &Tx, T_alle_Parameter_werden_abgefragt_darunter_einige_hier_nicht_gezeigte,1,&rzf,1));
	opts.push_back(/*4*/optioncl(T_krf_k,T_keinerueckfragen_l, &Tx, T_keine_Rueckfragen_zB_aus_Cron,1,&nrzf,1));
	opts.push_back(/*4*/optioncl(T_info_k,T_version_l, &Tx, T_Zeigt_die_Programmversion_an, 1, &zeigvers,1));
	opts.push_back(/*4*/optioncl(T_vi_k,T_vi_l, &Tx, T_Konfigurations_u_Logdatei_bearbeiten_sehen, 1, &obvi,1));
	opts.push_back(/*4*/optioncl(T_h_k,T_hilfe_l, &Tx, T_Erklaerung_haeufiger_Optionen, 1, &obhilfe,1));
	opts.push_back(/*4*/optioncl(T_lh_k,T_lhilfe_l, &Tx, T_Erklaerung_aller_Optionen, 1, &obhilfe,2));
	opts.push_back(/*4*/optioncl(T_fgz_k,T_fgz_l, &Tx, -1, 1, &obhilfe,1));

	// hier wird die Befehlszeile ueberprueft:
	for(;optslsz<opts.size();optslsz++) {
		for(size_t i=0;i<argcmv.size();i++) {
			if (opts[optslsz].pruefpar(&argcmv,&i,&obhilfe)) {
				if (opts[optslsz].kurzi==T_cm_k) { // cronminuten
					keineverarbeitung=1;
					cmeingegeben=1;
				}
				else if (opts[optslsz].kurzi==T_mpwd_k) {
					const string pwdstr=XOR(mpwd,pwk);
					agcnfA.setze(string(Tx[T_mpwd_k]),pwdstr);
				} // 				if (opts[optslsz].kurzi==T_mpwd_k) //ω
				break; //α
			} //       if (opts[optslsz].pruefpar(&argcmv,&i,&obhilfe,Tx.lgn))
		} // for(size_t i=0;i<argcmv.size();i++)
	} //   for(;optslsz<opts.size();optslsz++)
#endif
	Log(violetts+Txk[T_Ende]+"getcommandline()"+schwarz);
	return 0;
} // int hhcl::getcommandline

// wird aufgerufen in: main
void hhcl::rueckfragen()
{
	Log(violetts+Tx[T_rueckfragen]+schwarz);
	if (rzf) {
		const char *const locale = setlocale(LC_CTYPE,"");
		if (langu.empty()) if (locale) if (strchr("defi",locale[0])) langu=locale[0];
		vector<string> sprachen={"e","d"/*,"f","i"*/};
			langu=Tippstrs(sprachstr.c_str()/*"Language/Sprache/Lingue/Lingua"*/,&sprachen,&langu);
			lgnzuw();
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
			cronminut=Tippzahl(Txk[T_Alle_wieviel_Minuten_soll]+meinname+Txk[T_aufgerufen_werden_0_ist_gar_nicht],&cronminut);
			autoupd=Tippob(Tx[T_Sollen_neue_Programmversionen_von]+meinname+Tx[T_automatisch_installiert_werden],autoupd?Txk[T_j_af]:"n");
			logvz=Tippverz(Tx[T_Logverzeichnis],&logvz);
			logdname=Tippstr(Tx[T_Logdateiname],&logdname);
			setzlog();
			oblog=Tippzahl(Tx[T_Oblog],oblog);
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
	if (!obhilfe &&!obvi &&!zeigvers) {
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
		Log(rots+Tx[Verbindung_zur_Datenbank_nicht_herstellbar]+schwarz+ltoan(fehler)+rot+Tx[T_Breche_ab]+schwarz);
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
	hhi.fangan();

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

