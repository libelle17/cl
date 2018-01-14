#define DPROG "cl"
//α
class hhcl:public hcl
{
 private:
 public:
  uchar obvi=0; // ob Konfigurationsdatei editiert werden soll
	uchar obvs=0;   // ob Quelldateien bearbeitet werden sollen
	string host="localhost";  // fuer MySQL/MariaDB
	string dbq="faxe"; // Datenbank
	string tabelle  //ω
		;  //α
	string muser; // Benutzer fuer Mysql/MariaDB
	string mpwd;  // Passwort fuer Mysql/MariaDB //ω
	const size_t maxconz=12;//aktc: 0=... //α
	uchar keineverarbeitung=0; // wenn cronminuten geaendert werden sollen, vorher abkuerzen
	DB* My=0;
	string p1;
	int p2;
	string p3;
 private:
	void lgnzuw();
 public:
  hhcl(const int argc, const char *const *const argv);
  ~hhcl();
	void pruefggfmehrfach();
	int  initDB();
	int  pruefDB(const string& db);
	void pruefanrufe(DB *My, const string& tabelle, const int obverb, const int oblog, const uchar direkt=0);
	void getcommandl0();
	void VorgbAllg();
	void VorgbSpeziell()
#ifdef VOMHAUPTCODE
		__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
		;
	void MusterVorgb();
	void lieskonfein(const string& dprog);
	int getcommandline();
	void rueckfragen(); //ω
	void autokonfschreib(); //α
	void zeigueberschrift();
}; // class hhcl //ω
