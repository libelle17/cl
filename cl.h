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
	void virtmacherkl();
 protected:
 public:
  hhcl(const int argc, const char *const *const argv);
//	~hhcl();
	void virtinitopt(); // (programm-)spezifische Optionen
	void pruefanrufe(DB *My, const string& tabelle, const int obverb, const int oblog, const uchar direkt=0);
	void getcommandl0();
	// void virtzeigversion(const string& ltiffv=nix);
	void virtVorgbAllg();
	void virtVorgbSpeziell()
#ifdef VOMHAUPTCODE
		__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
		;
	void virtMusterVorgb();
	void virtvorrueckfragen(); //ω
	void virtrueckfragen(); //ω
	void virtzeigueberschrift();
  void virtfuehraus();
}; // class hhcl //ω
