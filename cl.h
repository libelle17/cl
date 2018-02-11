#define DPROG "cl"
//α
class hhcl:public dhcl
{
 private:
 public:
	string p1;
	int p2;
	string p3;
	uchar oblista=0;
	long listz=30;
 private:
 protected:
	void virtzeigversion(const string& ltiffv=nix);
	void pvirtvorrueckfragen(); //ω
	void virtrueckfragen(); //ω
	void virtpruefweiteres();
	void virtzeigueberschrift();
  void pvirtfuehraus();
	void virtschlussanzeige();

	// void virtlgnzuw(); // wird aufgerufen in: virtrueckfragen, parsecl, lieskonfein, hcl::hcl nach holsystemsprache
	void virtVorgbAllg();
	void pvirtVorgbSpeziell();
	void virtinitopt(); // (programm-)spezifische Optionen
	void pvirtmacherkl();
	void virtMusterVorgb();
	void virtzeigversion(const string& ltiffv=nix);
	//	void pvirtvorrueckfragen();
	void virtrueckfragen();
	//	void virtpruefweiteres();
	//	void virtzeigueberschrift();
	//  void pvirtfuehraus();
	void virtschlussanzeige();
 public:
  hhcl(const int argc, const char *const *const argv);
//	~hhcl();
	void pruefanrufe(DB *My, const string& tabelle, const int obverb, const int oblog, const uchar direkt=0);
	void getcommandl0();
#ifdef VOMHAUPTCODE
		__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
		;
	void virtMusterVorgb();
}; // class hhcl //ω
