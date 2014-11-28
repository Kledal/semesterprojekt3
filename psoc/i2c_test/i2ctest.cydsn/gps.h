void readGPSData();
int compareGPSCMD(char* cmd);
void resetGPSBuffer();
void handleGPSData(char* cmd);
int getGPSSpeed();
int getNumberOfSate();

void initGPSandSPI();

/********** GPS  ***************/

char gpsBuffer[300];
int gpsBufferPointer;
char* gpvtg;
char* gpgga;

int speed_;
int numberOfSate_;

/********** /GPS  ***************/