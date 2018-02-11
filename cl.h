#define DPROG "cl"
//α
class hhcl:public dhcl
{
 private: //ω
    string maxcapiv; // maximale Versuchnr in Capi, bis Hyla versucht wird
    string maxhylav; // maixmale Versuchsnr in Hylafax, bis Capi versucht wird
 protected: //α
	string p1;
	int p2;
	string p3;
	uchar oblista=0;
	long listz=30; //ω
 public: //α //ω
 private: //α //ω
 protected: //α
	// void virtlgnzuw(); // wird aufgerufen in: virtrueckfragen, parsecl, lieskonfein, hcl::hcl nach holsystemsprache
	void virtVorgbAllg();
	void pvirtVorgbSpeziell()
#ifdef VOMHAUPTCODE
		__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
		;
	void virtinitopt(); // (programm-)spezifische Optionen
	void pvirtmacherkl();
	void virtMusterVorgb();
	void virtzeigversion(const string& ltiffv=nix);
	void pvirtvorrueckfragen();
	void virtrueckfragen();
	void virtpruefweiteres();
	void virtzeigueberschrift();
	void pvirtfuehraus();
	void virtschlussanzeige(); //ω
 public: //α
  hhcl(const int argc, const char *const *const argv);
}; // class hhcl //ω
