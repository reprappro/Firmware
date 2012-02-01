#include "SerialManager.h"

SerialManager::SerialManager()
{
	_cur = &Serial;
}

void SerialManager::ChangeSerial(HardwareSerial* s)
{
	_cur = s;
}

HardwareSerial* SerialManager::cur()
{
	return _cur;
}

SerialManager SerialMgr;