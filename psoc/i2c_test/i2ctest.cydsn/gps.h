void readGPSData();
int compareGPSCMD(char* cmd);
void resetGPSBuffer();
void handleGPSData(char* cmd);
int getGPSSpeed();
char* getGPSUartSpeed();
int GetGPSTime();
int getNumberOfSate();
char* getGPSUartNumberOfSate();

char GetGPSLatitudePos();
char GetGPSLongitudePos();

void GetGPSLatitude(char * returnStr);
void GetGPSLongitude(char * returnStr);

/********** GPS  ***************/

char gpsBuffer[300];
int gpsBufferPointer;
char* gpvtg;
char* gpgga;
char* gpgsv;

int speed_;
int numberOfSate_;
int time_;

float longitude_;
float latitude_;
char latitude_pos;
char longitude_pos;

/********** /GPS  ***************/