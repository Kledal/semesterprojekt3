void readGPSData();
int compareGPSCMD(char* cmd);
void resetGPSBuffer();
void handleGPSData(char* cmd);
int getGPSSpeed();
char* getGPSUartSpeed();
/********** GPS  ***************/

char gpsBuffer[300];
int gpsBufferPointer;
char* gpvtg;
char* gpgga;
char* gpgsv;

int speed_;
/********** /GPS  ***************/