#ifndef SerialManager_h
#define SerialManager_h
#include <WProgram.h>
class SerialManager{
	public:
		SerialManager(void);
		void ChangeSerial(HardwareSerial* s);
		HardwareSerial* cur();
	
	private:
		HardwareSerial* _cur;
};

extern SerialManager SerialMgr;
#endif
