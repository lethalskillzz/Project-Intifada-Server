#ifndef SPREAD_H_INCLUDED
#define SPREAD_H_INCLUDED

//int Spread();

DWORD WINAPI USB_Spreader(LPVOID param);
void SetInfStatsDB(int InfUSBs, int InfEXEs );
void GetInfStatsDataBase();
static int Statscallback(void *data, int argc, char **argv, char **azColName);

/*char *rot13(char *str);
{
	char *ret = str;

    for (; *str; str++)
        if (*str >= 'a' && *str <= 'z')
            *str = (*str - 'a' + 13) % 26 + 'a';
        else if (*str >= 'A' && *str <= 'Z')
            *str = (*str - 'A' + 13) % 26 + 'A';
    return ret;
}*/



#endif // SPREAD_H_INCLUDED
