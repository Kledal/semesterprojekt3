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