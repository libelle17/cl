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
	void macherkl();
 protected:
	void lgnzuw();
 public:
  hhcl(const int argc, const char *const *const argv);
	~hhcl();
	void initopt(); // (programm-)spezifische Optionen
	void pruefggfmehrfach();
	void pruefanrufe(DB *My, const string& tabelle, const int obverb, const int oblog, const uchar direkt=0);
	void getcommandl0();
	void VorgbAllg();
	void VorgbSpeziell()
#ifdef VOMHAUPTCODE
		__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
		;
	void MusterVorgb();
	void rueckfragen(); //ω
	void zeigueberschrift();//α
}; // class hhcl //ω
