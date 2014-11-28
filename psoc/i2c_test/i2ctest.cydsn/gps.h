 void readGPSData();
int compareGPSCMD(char* cmd);
void resetGPSBuffer();
void handleGPSData(char* cmd);
int getGPSSpeed();
char* getGPSUartSpeed();
int GetGPSTime();
int getNumberOfSate();
char* getGPSUartNumberOfSate();

void initGPSandSPI();


/********** GPS  ***************/

char gpsBuffer[300];
int gpsBufferPointer;
char* gpvtg;
char* gpgga;
char* gpgsv;

int speed_;
int numberOfSate_;
int time_;


/********** /GPS  ***************/