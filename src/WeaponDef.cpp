// IW6x WeaponDef Tool : by JANU
// v1: borderless custom window (dark frame, own title bar + minimize/close) instead of the white Windows frame.
// Built specifically for the uploaded IW6x MP build. x64, no CRT.

typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned int   UINT;
typedef unsigned int   DWORD;
typedef int            BOOL;
typedef long long      INT_PTR;
typedef unsigned long long UINT_PTR;
typedef unsigned long long SIZE_T;
typedef UINT_PTR WPARAM;
typedef INT_PTR LPARAM;
typedef INT_PTR LRESULT;
typedef void* HANDLE;
typedef void* HINSTANCE;
typedef void* HMODULE;
typedef void* HWND;
typedef void* HDC;
typedef void* HBRUSH;
typedef void* HFONT;
typedef void* HGDIOBJ;
typedef void* HICON;
typedef void* HCURSOR;
typedef void* HMENU;
typedef const char* LPCSTR;
typedef char* LPSTR;
typedef void* LPVOID;
typedef const void* LPCVOID;

#define WINAPI __stdcall
#define CALLBACK __stdcall
#define TRUE 1
#define FALSE 0
#define NULL 0

struct POINT { long x; long y; };
struct RECT { long left, top, right, bottom; };
struct MSG { HWND hwnd; UINT message; WPARAM wParam; LPARAM lParam; DWORD time; POINT pt; DWORD lPrivate; };
struct PAINTSTRUCT { HDC hdc; BOOL fErase; RECT rcPaint; BOOL fRestore; BOOL fIncUpdate; BYTE rgbReserved[32]; };
struct BITMAPINFOHEADER_X { DWORD biSize; long biWidth; long biHeight; WORD biPlanes; WORD biBitCount; DWORD biCompression; DWORD biSizeImage; long biXPelsPerMeter; long biYPelsPerMeter; DWORD biClrUsed; DWORD biClrImportant; };
struct RGBQUAD_X { BYTE rgbBlue; BYTE rgbGreen; BYTE rgbRed; BYTE rgbReserved; };
struct BITMAPINFO_X { BITMAPINFOHEADER_X bmiHeader; RGBQUAD_X bmiColors[1]; };
struct DRAWITEMSTRUCT { UINT CtlType; UINT CtlID; UINT itemID; UINT itemAction; UINT itemState; HWND hwndItem; HDC hDC; RECT rcItem; UINT_PTR itemData; };
struct MEASUREITEMSTRUCT { UINT CtlType; UINT CtlID; UINT itemID; UINT itemWidth; UINT itemHeight; UINT_PTR itemData; };
typedef LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
struct WNDCLASSEXA {
    UINT cbSize; UINT style; WNDPROC lpfnWndProc; int cbClsExtra; int cbWndExtra;
    HINSTANCE hInstance; HICON hIcon; HCURSOR hCursor; HBRUSH hbrBackground;
    LPCSTR lpszMenuName; LPCSTR lpszClassName; HICON hIconSm;
};
struct MEMORY_BASIC_INFORMATION_X { LPVOID BaseAddress; LPVOID AllocationBase; DWORD AllocationProtect; DWORD _pad0; SIZE_T RegionSize; DWORD State; DWORD Protect; DWORD Type; DWORD _pad1; };

typedef DWORD (WINAPI *LPTHREAD_START_ROUTINE)(LPVOID);

extern "C" {
__declspec(dllimport) HANDLE WINAPI CreateThread(LPVOID,SIZE_T,LPTHREAD_START_ROUTINE,LPVOID,DWORD,DWORD*);
__declspec(dllimport) BOOL WINAPI DisableThreadLibraryCalls(HMODULE);
__declspec(dllimport) void WINAPI Sleep(DWORD);
__declspec(dllimport) BOOL WINAPI VirtualProtect(LPVOID,SIZE_T,DWORD,DWORD*);
__declspec(dllimport) SIZE_T WINAPI VirtualQuery(LPCVOID,MEMORY_BASIC_INFORMATION_X*,SIZE_T);
__declspec(dllimport) HMODULE WINAPI LoadLibraryA(LPCSTR);
__declspec(dllimport) BOOL WINAPI FreeLibrary(HMODULE);
__declspec(dllimport) HMODULE WINAPI GetModuleHandleA(LPCSTR);
__declspec(dllimport) void* WINAPI GetProcAddress(HMODULE,LPCSTR);
__declspec(dllimport) DWORD WINAPI GetModuleFileNameA(HMODULE,LPSTR,DWORD);
__declspec(dllimport) DWORD WINAPI GetTempPathA(DWORD,LPSTR);
__declspec(dllimport) HANDLE WINAPI CreateFileA(LPCSTR,DWORD,DWORD,LPVOID,DWORD,DWORD,HANDLE);
__declspec(dllimport) BOOL WINAPI ReadFile(HANDLE,LPVOID,DWORD,DWORD*,LPVOID);
__declspec(dllimport) BOOL WINAPI WriteFile(HANDLE,LPCVOID,DWORD,DWORD*,LPVOID);
__declspec(dllimport) BOOL WINAPI CloseHandle(HANDLE);
__declspec(dllimport) BOOL WINAPI DeleteFileA(LPCSTR);
__declspec(dllimport) DWORD WINAPI GetFileSize(HANDLE,DWORD*);
__declspec(dllimport) DWORD WINAPI SetFilePointer(HANDLE,long,long*,DWORD);

__declspec(dllimport) unsigned short WINAPI RegisterClassExA(const WNDCLASSEXA*);
__declspec(dllimport) HWND WINAPI CreateWindowExA(DWORD,LPCSTR,LPCSTR,DWORD,int,int,int,int,HWND,HMENU,HINSTANCE,LPVOID);
__declspec(dllimport) LRESULT WINAPI DefWindowProcA(HWND,UINT,WPARAM,LPARAM);
__declspec(dllimport) BOOL WINAPI ShowWindow(HWND,int);
__declspec(dllimport) BOOL WINAPI SetForegroundWindow(HWND);
__declspec(dllimport) BOOL WINAPI BringWindowToTop(HWND);
__declspec(dllimport) HWND WINAPI SetActiveWindow(HWND);
__declspec(dllimport) HWND WINAPI SetFocus(HWND);
__declspec(dllimport) short WINAPI GetAsyncKeyState(int);
__declspec(dllimport) BOOL WINAPI UpdateWindow(HWND);
__declspec(dllimport) BOOL WINAPI GetMessageA(MSG*,HWND,UINT,UINT);
__declspec(dllimport) BOOL WINAPI TranslateMessage(const MSG*);
__declspec(dllimport) LRESULT WINAPI DispatchMessageA(const MSG*);
__declspec(dllimport) void WINAPI PostQuitMessage(int);
__declspec(dllimport) LRESULT WINAPI SendMessageA(HWND,UINT,WPARAM,LPARAM);
__declspec(dllimport) int WINAPI GetWindowTextA(HWND,LPSTR,int);
__declspec(dllimport) BOOL WINAPI SetWindowTextA(HWND,LPCSTR);
__declspec(dllimport) int WINAPI MessageBoxA(HWND,LPCSTR,LPCSTR,UINT);
__declspec(dllimport) HDC WINAPI BeginPaint(HWND,PAINTSTRUCT*);
__declspec(dllimport) BOOL WINAPI EndPaint(HWND,const PAINTSTRUCT*);
__declspec(dllimport) int WINAPI FillRect(HDC,const RECT*,HBRUSH);
__declspec(dllimport) BOOL WINAPI GetClientRect(HWND,RECT*);
__declspec(dllimport) BOOL WINAPI GetWindowRect(HWND,RECT*);
__declspec(dllimport) BOOL WINAPI IsIconic(HWND);
__declspec(dllimport) UINT_PTR WINAPI SetTimer(HWND,UINT_PTR,UINT,LPVOID);
__declspec(dllimport) BOOL WINAPI GetCursorPos(POINT*);
__declspec(dllimport) HWND WINAPI WindowFromPoint(POINT);
__declspec(dllimport) int WINAPI GetSystemMetrics(int);
__declspec(dllimport) HICON WINAPI CreateIcon(HINSTANCE,int,int,BYTE,BYTE,const BYTE*,const BYTE*);
__declspec(dllimport) BOOL WINAPI DestroyIcon(HICON);
__declspec(dllimport) BOOL WINAPI InvalidateRect(HWND,const RECT*,BOOL);
__declspec(dllimport) int WINAPI DrawTextA(HDC,LPCSTR,int,RECT*,UINT);
__declspec(dllimport) INT_PTR WINAPI SetWindowLongPtrA(HWND,int,INT_PTR);
__declspec(dllimport) INT_PTR WINAPI GetWindowLongPtrA(HWND,int);

__declspec(dllimport) HBRUSH WINAPI CreateSolidBrush(DWORD);
__declspec(dllimport) BOOL WINAPI DeleteObject(HGDIOBJ);
__declspec(dllimport) DWORD WINAPI SetTextColor(HDC,DWORD);
__declspec(dllimport) DWORD WINAPI SetBkColor(HDC,DWORD);
__declspec(dllimport) int WINAPI SetBkMode(HDC,int);
__declspec(dllimport) HFONT WINAPI CreateFontA(int,int,int,int,int,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPCSTR);
__declspec(dllimport) HGDIOBJ WINAPI SelectObject(HDC,HGDIOBJ);
__declspec(dllimport) int WINAPI StretchDIBits(HDC,int,int,int,int,int,int,int,int,LPCVOID,const BITMAPINFO_X*,UINT,DWORD);
}

extern "C" void* memset(void* p, int v, SIZE_T n) { BYTE* d=(BYTE*)p; while(n--) *d++=(BYTE)v; return p; }
extern "C" void* memcpy(void* d0, const void* s0, SIZE_T n) { BYTE* d=(BYTE*)d0; const BYTE* s=(const BYTE*)s0; while(n--) *d++=*s++; return d0; }
extern "C" int memcmp(const void* a0,const void* b0,SIZE_T n){const BYTE*a=(const BYTE*)a0;const BYTE*b=(const BYTE*)b0;while(n--){if(*a!=*b)return *a-*b;a++;b++;}return 0;}

static SIZE_T slen(const char* s){SIZE_T n=0;if(!s)return 0;while(s[n])n++;return n;}
static void scopy(char* d,const char* s,SIZE_T cap){if(!cap)return;SIZE_T i=0;if(s)for(;i+1<cap&&s[i];i++)d[i]=s[i];d[i]=0;}
static void scat(char* d,const char* s,SIZE_T cap){SIZE_T n=slen(d),i=0;if(!s)return;while(n+1<cap&&s[i])d[n++]=s[i++];d[n]=0;}
static int seq(const char*a,const char*b){if(!a||!b)return 0;while(*a&&*b&&*a==*b){a++;b++;}return *a==*b;}
static int parse_int(const char*s){int sign=1,v=0;if(!s)return 0;while(*s==' '||*s=='\t')s++;if(*s=='-'){sign=-1;s++;}while(*s>='0'&&*s<='9'){v=v*10+(*s-'0');s++;}return v*sign;}
static float parse_float(const char*s){if(!s)return 0.0f;while(*s==' '||*s=='\t')s++;float sign=1.0f;if(*s=='-'){sign=-1;s++;}float v=0;while(*s>='0'&&*s<='9'){v=v*10+(*s-'0');s++;}if(*s=='.'){s++;float p=.1f;while(*s>='0'&&*s<='9'){v+=(*s-'0')*p;p*=.1f;s++;}}return v*sign;}
static void uint_to_str(unsigned v,char*out){char t[16];int n=0;if(v==0){out[0]='0';out[1]=0;return;}while(v){t[n++]=(char)('0'+v%10);v/=10;}int j=0;while(n)out[j++]=t[--n];out[j]=0;}
static void int_to_str(int v,char*out){if(v<0){*out++='-';uint_to_str((unsigned)(-v),out);}else uint_to_str((unsigned)v,out);}
static void float_to_str(float v,char*out){if(v<0){*out++='-';v=-v;}int whole=(int)v;int frac=(int)((v-whole)*100.0f+0.5f);char t[24];uint_to_str((unsigned)whole,t);scopy(out,t,24);SIZE_T n=slen(out);out[n++]='.';out[n++]=(char)('0'+((frac/10)%10));out[n++]=(char)('0'+(frac%10));out[n]=0;}

#define RGBX(r,g,b) ((DWORD)(((BYTE)(r))|((WORD)((BYTE)(g))<<8)|(((DWORD)(BYTE)(b))<<16)))
#define WS_OVERLAPPEDWINDOW 0x00CF0000u
#define WS_POPUP 0x80000000u
#define WS_EX_APPWINDOW 0x00040000u
#define CS_DROPSHADOW 0x00020000u
#define WM_NCHITTEST 0x0084
#define HTCLIENT 1
#define HTCAPTION 2
#define SW_MINIMIZE 6
#define SW_RESTORE 9
#define WM_TIMER 0x0113
#define WM_SETICON 0x0080
#define GWLP_ID_X (-12)
#define SS_RIGHT 0x0002u
#define SS_CENTER 0x0001u
#define WIN_W 1399
#define WIN_H 801
#define BTN_MIN_ID 990
#define BTN_CLOSE_ID 991
#define WS_CLIPCHILDREN 0x02000000u
#define WS_VISIBLE 0x10000000u
#define WS_CHILD 0x40000000u
#define WS_BORDER 0x00800000u
#define WS_TABSTOP 0x00010000u
#define WS_VSCROLL 0x00200000u
#define BS_OWNERDRAW 0x0000000Bu
#define LBS_NOTIFY 0x0001u
#define LBS_MULTIPLESEL 0x0008u
#define LBS_NOINTEGRALHEIGHT 0x0100u
#define LBS_OWNERDRAWFIXED 0x0010u
#define LBS_HASSTRINGS 0x0040u
#define ES_AUTOHSCROLL 0x0080u
#define WM_DESTROY 0x0002
#define WM_PAINT 0x000F
#define WM_ERASEBKGND 0x0014
#define WM_SETREDRAW 0x000B
#define WM_DRAWITEM 0x002B
#define WM_MEASUREITEM 0x002C
#define WM_CLOSE 0x0010
#define WM_SETFONT 0x0030
#define WM_COMMAND 0x0111
#define WM_CTLCOLORMSGBOX 0x0132
#define WM_CTLCOLOREDIT 0x0133
#define WM_CTLCOLORLISTBOX 0x0134
#define WM_CTLCOLORBTN 0x0135
#define WM_CTLCOLORSTATIC 0x0138
#define LB_ADDSTRING 0x0180
#define LB_RESETCONTENT 0x0184
#define LB_SETSEL 0x0185
#define LB_SETCURSEL 0x0186
#define LB_GETSEL 0x0187
#define LB_GETCURSEL 0x0188
#define LB_GETTEXT 0x0189
#define LBN_SELCHANGE 1
#define ODT_LISTBOX 2
#define ODT_BUTTON 4
#define ODS_SELECTED 0x0001
#define ODS_DISABLED 0x0004
#define DT_CENTER 0x00000001u
#define DT_VCENTER 0x00000004u
#define DT_SINGLELINE 0x00000020u
#define DT_NOPREFIX 0x00000800u
#define EN_CHANGE 0x0300
#define BN_CLICKED 0
#define SW_HIDE 0
#define SW_SHOW 5
#define WS_EX_TOPMOST 0x00000008u
#define VK_INSERT 0x2D
#define WM_JANU_TOGGLE_FOCUS 0x8051
#define COLOR_WINDOW 5
#define TRANSPARENT 1
#define DIB_RGB_COLORS 0u
#define BI_RGB 0u
#define SRCCOPY 0x00CC0020u
#define GWLP_USERDATA (-21)
#define PAGE_EXECUTE_READ 0x20
#define PAGE_EXECUTE_READWRITE 0x40
#define PAGE_READWRITE 0x04
#define MEM_COMMIT 0x1000
#define GENERIC_READ 0x80000000u
#define GENERIC_WRITE 0x40000000u
#define FILE_SHARE_READ 0x00000001u
#define OPEN_EXISTING 3u
#define CREATE_ALWAYS 2u
#define FILE_ATTRIBUTE_NORMAL 0x80u
#define INVALID_HANDLE_VALUE ((HANDLE)(INT_PTR)-1)
#define FILE_BEGIN 0

#define LOWORDX(v) ((WORD)((UINT_PTR)(v)&0xFFFF))
#define HIWORDX(v) ((WORD)(((UINT_PTR)(v)>>16)&0xFFFF))
#define CTRLID(h) ((int)(INT_PTR)(h))

#include "barrier.inc"
#include "ghost_art_v11.inc"
#include "logo.inc"
static unsigned char gGhostTintBGR[514800]={0};

static HINSTANCE g_module=0;
static HWND g_main=0,g_weaponList=0,g_status=0,g_weaponTitle=0,g_countLabel=0,g_search=0;
static volatile int g_toolVisible=1;
static HWND g_allControls[512]={0}; static int g_allControlCount=0;
static HWND wpFieldList=0,wpValueEdit=0; static int g_wpCat=0; static int g_visibleFields[512]={0},g_visibleFieldCount=0;
static int g_visibleWeapons[512]={0},g_visibleWeaponCount=0;
static HWND g_tabs[7]={0};
static HWND g_wp[32]={0}; static int g_wpN=0;
static HWND g_an[32]={0}; static int g_anN=0;
static HWND g_sv[16]={0}; static int g_svN=0;
static HWND g_nb[16]={0}; static int g_nbN=0;
static HWND g_fx[32]={0}; static int g_fxN=0;
static HWND g_th[32]={0}; static int g_thN=0;
static HWND g_bt[24]={0}; static int g_btN=0;
static HBRUSH g_bgBrush=0,g_panelBrush=0,g_editBrush=0,g_accentBrush=0,g_selectBrush=0,g_borderBrush=0,g_brightBrush=0;
static HFONT g_font=0,g_fontBold=0;
static HMODULE g_barrier=0;
static char g_barrierPath[520]={0};
static char g_savePath[520]={0};
static char g_batchPath[520]={0};
static char g_themePath[520]={0};
static char g_fxPath[520]={0};
static char g_winPath[520]={0};
static HWND g_hotWnd=0; static HWND g_btnWnds[256]={0}; static int g_btnWndN=0;
static unsigned char g_iconBGRA[32*32*4]={0};
static HICON g_hIcon=0;
static int g_savedX=-99999,g_savedY=-99999;

struct ThemeDef { const char* name; DWORD bg,panel,edit,accent,accentBright,select,border,text,dim; };
static const ThemeDef kThemes[] = {
    {"Ghost Blue",    RGBX(3,9,14),   RGBX(6,16,25),  RGBX(9,22,33),  RGBX(58,178,255), RGBX(180,232,255), RGBX(16,62,98),  RGBX(48,116,164),  RGBX(235,246,252), RGBX(132,164,181)},
    {"Ice Blue",      RGBX(3,10,16),  RGBX(6,20,30),  RGBX(10,28,42), RGBX(62,190,255), RGBX(173,232,255), RGBX(13,57,82),  RGBX(38,105,137), RGBX(241,249,253), RGBX(142,178,196)},
    {"Carbon",        RGBX(8,9,10),   RGBX(14,16,18), RGBX(20,23,25), RGBX(123,145,153),RGBX(205,218,222),RGBX(38,43,46),  RGBX(58,65,69),   RGBX(238,240,241), RGBX(146,153,157)},
    {"Crimson",       RGBX(12,5,7),   RGBX(22,8,12),  RGBX(31,11,16), RGBX(205,48,75),  RGBX(255,132,150),RGBX(68,18,29),  RGBX(105,31,45),  RGBX(250,239,242), RGBX(187,143,152)},
    {"Purple Neon",   RGBX(8,4,14),   RGBX(16,7,26),  RGBX(24,10,38), RGBX(154,67,255), RGBX(218,171,255),RGBX(53,20,82),  RGBX(84,37,124),  RGBX(246,238,253), RGBX(174,145,194)},
    {"Matrix",        RGBX(2,10,10),  RGBX(4,18,18),  RGBX(5,27,27),  RGBX(0,190,183),  RGBX(118,255,244),RGBX(4,58,56),   RGBX(7,96,91),    RGBX(230,250,248), RGBX(121,177,173)},
    {"MW2 Amber",     RGBX(10,8,3),   RGBX(19,15,6),  RGBX(28,22,8),  RGBX(218,151,38), RGBX(255,210,112),RGBX(60,42,12),  RGBX(96,68,20),   RGBX(249,244,232), RGBX(185,165,124)},
    {"Classic Lime",  RGBX(5,8,5),    RGBX(10,15,10), RGBX(16,24,16), RGBX(130,230,72), RGBX(190,255,145),RGBX(36,64,28),  RGBX(54,90,43),   RGBX(243,248,241), RGBX(157,179,151)},
    {"White Minimal", RGBX(225,230,233),RGBX(239,242,244),RGBX(250,251,252),RGBX(58,113,145),RGBX(22,79,111),RGBX(194,214,226),RGBX(159,177,188),RGBX(20,29,34),RGBX(83,100,109)}
};
static const int kThemeCount=(int)(sizeof(kThemes)/sizeof(kThemes[0]));
static int g_themeIndex=0;
static DWORD C_BG=RGBX(3,9,14), C_PANEL=RGBX(6,16,25), C_EDIT=RGBX(9,22,33), C_ACCENT=RGBX(46,151,220), C_ACCENT_BRIGHT=RGBX(135,211,255), C_SELECT=RGBX(12,48,72), C_BORDER=RGBX(28,78,108), C_TEXT=RGBX(235,246,252), C_DIM=RGBX(132,164,181);
static HWND g_themeButtons[9]={0},g_themeNameLabel=0;
static HWND g_fxToggle=0,g_fxStatus=0;
static HWND g_fxStyleButtons[6]={0},g_fxSpeedButtons[3]={0},g_fxDensityButtons[3]={0},g_fxSizeButtons[3]={0},g_fxBrightButtons[3]={0},g_fxScopeButtons[2]={0};
static int g_fxEnabled=0,g_fxStyle=0,g_fxSpeed=1,g_fxDensity=1,g_fxSize=1,g_fxBrightness=1,g_fxScope=0;
static unsigned g_fxTick=0;
static const char* kFxNames[6]={"Stars","Matrix","Snow","Sparks","Scanlines","Pulse"};
struct FxDisk { DWORD magic; int enabled,style,speed,density,size,brightness,scope; };

struct WeaponCompleteHead { const char* name; void* def; const char* display; void* hide; void* scopes; void* under; void* others; void** anims; };
struct AnimOverrideEntryX { WORD attachment1; WORD attachment2; void* overrideAnim; void* altmodeAnim; DWORD animTreeType; int animTime; int altTime; };
static WeaponCompleteHead* g_weapons[512]={0};
static int g_weaponCount=0;
static int g_sel=-1;
static int g_animType=2,g_modelType=4;
static int g_animSource=0; // 0=Complete, 1=Right Hand, 2=Left Hand, 3=Attachment Overrides
static int g_animFilter=0; // 0=Core,1=Used,2=Reload,3=Move,4=Combat,5=All
static int g_visibleAnimSlots[256]={0},g_visibleAnimCount=0;
static int g_activeTab=0;
static HWND g_wpCatButtons[7]={0},g_animSourceButtons[4]={0},g_animFilterButtons[6]={0};

struct Snapshot {
    WeaponCompleteHead* w;
    BYTE defBytes[0xA98];
    BYTE completeBytes[0x128];
    void* anims[124];
    void* animRight[124];
    void* animLeft[124];
    AnimOverrideEntryX animOverrides[64];
    DWORD animOverrideCount;
    void* gun[64];
    void* world[64];
    int valid;
};
static Snapshot g_orig[512]={0};

struct Preset {
    DWORD magic;
    char name[48];
    char sourceWeapon[80];
    char anim[124][80];
    char gun0[96],gun1[96],hand[96];
    float adsFov;
    int adsIn,adsOut,clip,fire,fireAk,fireAnim,fireAnimAk,firstRaise,firstRaiseAk;
};
static Preset g_presets[16]={0};
static int g_presetCount=0;

static HWND wpAds=0,wpAdsIn=0,wpAdsOut=0,wpClip=0,wpFire=0,wpFireAnim=0,wpFirstRaise=0;
static HWND wpGun0=0,wpGun1=0,wpHand=0;
static HWND anList=0,anEdit=0,svList=0,svName=0,nbStatus=0,btList=0,btInfo=0;
static HWND anAltEdit=0,anTypeEdit=0,anTimeEdit=0,anAltTimeEdit=0,anAttach1Edit=0,anAttach2Edit=0,anSourceInfo=0;
static HWND g_anOverrideOnly[16]={0}; static int g_anOverrideOnlyN=0;

typedef int (__fastcall *DBGetAllFn)(int,void**,int);
typedef void* (__fastcall *DBFindFn)(int,const char*,int);
static DBGetAllFn DBGetAll=(DBGetAllFn)0x14031FC00ull;
static DBFindFn DBFind=(DBFindFn)0x14031F3A0ull;

enum FieldKind { FK_INT=0, FK_FLOAT=1, FK_BOOL=2, FK_MODEL_DIRECT=3, FK_MODEL_ARRAY=4 };
enum FieldBase { FB_DEF=0, FB_COMPLETE=1 };
struct FieldDesc { const char* name; int category; int base; unsigned offset; int kind; int arrayIndex; };
static const char* kWpCategories[7]={"Variant","Ammo","Reload","Timing","Misc","Models","Movement"};
static const FieldDesc kFields[]={
    {"playerAnimType",0,FB_DEF,0x90,FK_INT,0},
    {"weapType",0,FB_DEF,0x94,FK_INT,0},
    {"weaponClass",0,FB_DEF,0x98,FK_INT,0},
    {"penetrateType",0,FB_DEF,0x9C,FK_INT,0},
    {"inventoryType",0,FB_DEF,0xA0,FK_INT,0},
    {"fireType",0,FB_DEF,0xA4,FK_INT,0},
    {"burstFireCooldown",0,FB_DEF,0xA8,FK_FLOAT,0},
    {"offhandClass",0,FB_DEF,0xAC,FK_INT,0},
    {"stance",0,FB_DEF,0xB0,FK_INT,0},
    {"activeReticleType",0,FB_DEF,0x2A4,FK_INT,0},
    {"iReticleCenterSize",4,FB_DEF,0x298,FK_INT,0},
    {"iReticleSideSize",4,FB_DEF,0x29C,FK_INT,0},
    {"iReticleMinOfs",4,FB_DEF,0x2A0,FK_INT,0},
    {"fPosMoveRate",6,FB_DEF,0x320,FK_FLOAT,0},
    {"fPosProneMoveRate",6,FB_DEF,0x324,FK_FLOAT,0},
    {"fStandMoveMinSpeed",6,FB_DEF,0x328,FK_FLOAT,0},
    {"fDuckedMoveMinSpeed",6,FB_DEF,0x32C,FK_FLOAT,0},
    {"fProneMoveMinSpeed",6,FB_DEF,0x330,FK_FLOAT,0},
    {"fPosRotRate",4,FB_DEF,0x334,FK_FLOAT,0},
    {"fPosProneRotRate",4,FB_DEF,0x338,FK_FLOAT,0},
    {"fStandRotMinSpeed",4,FB_DEF,0x33C,FK_FLOAT,0},
    {"fDuckedRotMinSpeed",4,FB_DEF,0x340,FK_FLOAT,0},
    {"fProneRotMinSpeed",4,FB_DEF,0x344,FK_FLOAT,0},
    {"hudIconRatio",0,FB_DEF,0x378,FK_INT,0},
    {"pickupIconRatio",0,FB_DEF,0x388,FK_INT,0},
    {"ammoCounterIconRatio",1,FB_DEF,0x398,FK_INT,0},
    {"ammoCounterClip",1,FB_DEF,0x39C,FK_INT,0},
    {"iStartAmmo",1,FB_DEF,0x3A0,FK_INT,0},
    {"iAmmoIndex",1,FB_DEF,0x3B0,FK_INT,0},
    {"iClipIndex",1,FB_DEF,0x3C0,FK_INT,0},
    {"iMaxAmmo",1,FB_DEF,0x3C4,FK_INT,0},
    {"shotCount",1,FB_DEF,0x3C8,FK_INT,0},
    {"iSharedAmmoCapIndex",1,FB_DEF,0x3D8,FK_INT,0},
    {"iSharedAmmoCap",1,FB_DEF,0x3DC,FK_INT,0},
    {"damage",1,FB_DEF,0x3E0,FK_INT,0},
    {"playerDamage",1,FB_DEF,0x3E4,FK_INT,0},
    {"iMeleeDamage",1,FB_DEF,0x3E8,FK_INT,0},
    {"iDamageType",1,FB_DEF,0x3EC,FK_INT,0},
    {"autoAimRange",6,FB_DEF,0x588,FK_FLOAT,0},
    {"aimAssistRange",6,FB_DEF,0x58C,FK_FLOAT,0},
    {"aimAssistRangeAds",6,FB_DEF,0x590,FK_FLOAT,0},
    {"aimPadding",4,FB_DEF,0x594,FK_FLOAT,0},
    {"enemyCrosshairRange",6,FB_DEF,0x598,FK_FLOAT,0},
    {"moveSpeedScale",6,FB_DEF,0x59C,FK_FLOAT,0},
    {"adsMoveSpeedScale",6,FB_DEF,0x5A0,FK_FLOAT,0},
    {"sprintDurationScale",6,FB_DEF,0x5A4,FK_FLOAT,0},
    {"fAdsZoomInFrac",4,FB_DEF,0x5A8,FK_FLOAT,0},
    {"fAdsZoomOutFrac",4,FB_DEF,0x5AC,FK_FLOAT,0},
    {"overlayInterface",4,FB_DEF,0x5E8,FK_FLOAT,0},
    {"fAdsBobFactor",4,FB_DEF,0x5EC,FK_FLOAT,0},
    {"fAdsViewBobMult",4,FB_DEF,0x5F0,FK_FLOAT,0},
    {"fHipSpreadStandMin",6,FB_DEF,0x5F4,FK_FLOAT,0},
    {"fHipSpreadDuckedMin",6,FB_DEF,0x5F8,FK_FLOAT,0},
    {"fHipSpreadProneMin",6,FB_DEF,0x5FC,FK_FLOAT,0},
    {"hipSpreadStandMax",6,FB_DEF,0x600,FK_FLOAT,0},
    {"hipSpreadDuckedMax",6,FB_DEF,0x604,FK_FLOAT,0},
    {"hipSpreadProneMax",6,FB_DEF,0x608,FK_FLOAT,0},
    {"fHipSpreadDecayRate",6,FB_DEF,0x60C,FK_FLOAT,0},
    {"fHipSpreadFireAdd",6,FB_DEF,0x610,FK_FLOAT,0},
    {"fHipSpreadTurnAdd",6,FB_DEF,0x614,FK_FLOAT,0},
    {"fHipSpreadMoveAdd",6,FB_DEF,0x618,FK_FLOAT,0},
    {"fHipSpreadDuckedDecay",6,FB_DEF,0x61C,FK_FLOAT,0},
    {"fHipSpreadProneDecay",6,FB_DEF,0x620,FK_FLOAT,0},
    {"fHipReticleSidePos",4,FB_DEF,0x624,FK_FLOAT,0},
    {"fAdsIdleAmount",4,FB_DEF,0x628,FK_FLOAT,0},
    {"fHipIdleAmount",4,FB_DEF,0x62C,FK_FLOAT,0},
    {"adsIdleSpeed",4,FB_DEF,0x630,FK_FLOAT,0},
    {"hipIdleSpeed",4,FB_DEF,0x634,FK_FLOAT,0},
    {"fIdleCrouchFactor",4,FB_DEF,0x638,FK_FLOAT,0},
    {"fIdleProneFactor",4,FB_DEF,0x63C,FK_FLOAT,0},
    {"fGunMaxPitch",4,FB_DEF,0x640,FK_FLOAT,0},
    {"fGunMaxYaw",4,FB_DEF,0x644,FK_FLOAT,0},
    {"adsIdleLerpStartTime",4,FB_DEF,0x648,FK_FLOAT,0},
    {"adsIdleLerpTime",4,FB_DEF,0x64C,FK_FLOAT,0},
    {"swayMaxAngleSteadyAim",4,FB_DEF,0x650,FK_FLOAT,0},
    {"swayMaxAngle",4,FB_DEF,0x654,FK_FLOAT,0},
    {"swayLerpSpeed",4,FB_DEF,0x658,FK_FLOAT,0},
    {"swayPitchScale",4,FB_DEF,0x65C,FK_FLOAT,0},
    {"swayYawScale",4,FB_DEF,0x660,FK_FLOAT,0},
    {"swayHorizScale",4,FB_DEF,0x664,FK_FLOAT,0},
    {"swayVertScale",4,FB_DEF,0x668,FK_FLOAT,0},
    {"swayShellShockScale",4,FB_DEF,0x66C,FK_FLOAT,0},
    {"adsSwayMaxAngle",4,FB_DEF,0x670,FK_FLOAT,0},
    {"adsSwayLerpSpeed",4,FB_DEF,0x674,FK_FLOAT,0},
    {"adsSwayPitchScale",4,FB_DEF,0x678,FK_FLOAT,0},
    {"adsSwayYawScale",4,FB_DEF,0x67C,FK_FLOAT,0},
    {"adsSwayHorizScale",4,FB_DEF,0x680,FK_FLOAT,0},
    {"adsSwayVertScale",4,FB_DEF,0x684,FK_FLOAT,0},
    {"adsViewErrorMin",4,FB_DEF,0x688,FK_FLOAT,0},
    {"adsViewErrorMax",4,FB_DEF,0x68C,FK_FLOAT,0},
    {"adsFireAnimFrac",4,FB_DEF,0x690,FK_FLOAT,0},
    {"dualWieldViewModelOffset",4,FB_DEF,0x6A0,FK_FLOAT,0},
    {"fScopeDriftDelay",4,FB_DEF,0x6A4,FK_FLOAT,0},
    {"fScopeDriftLerpInTime",4,FB_DEF,0x6A8,FK_FLOAT,0},
    {"fScopeDriftSteadyTime",4,FB_DEF,0x6AC,FK_FLOAT,0},
    {"fScopeDriftLerpOutTime",4,FB_DEF,0x6B0,FK_FLOAT,0},
    {"fScopeDriftSteadyFactor",4,FB_DEF,0x6B4,FK_FLOAT,0},
    {"fScopeDriftUnsteadyFactor",4,FB_DEF,0x6B8,FK_FLOAT,0},
    {"killIconRatio",0,FB_DEF,0x6BC,FK_INT,0},
    {"iReloadAmmoAdd",2,FB_DEF,0x6C0,FK_INT,0},
    {"iReloadStartAdd",2,FB_DEF,0x6C4,FK_INT,0},
    {"ammoDropStockMin",1,FB_DEF,0x6C8,FK_INT,0},
    {"ammoDropClipPercentMin",1,FB_DEF,0x6CC,FK_INT,0},
    {"ammoDropClipPercentMax",1,FB_DEF,0x6D0,FK_INT,0},
    {"iExplosionRadius",1,FB_DEF,0x6D4,FK_INT,0},
    {"iExplosionRadiusMin",1,FB_DEF,0x6D8,FK_INT,0},
    {"iExplosionInnerDamage",1,FB_DEF,0x6DC,FK_INT,0},
    {"iExplosionOuterDamage",1,FB_DEF,0x6E0,FK_INT,0},
    {"damageConeAngle",1,FB_DEF,0x6E4,FK_FLOAT,0},
    {"bulletExplDmgMult",1,FB_DEF,0x6E8,FK_FLOAT,0},
    {"bulletExplRadiusMult",1,FB_DEF,0x6EC,FK_FLOAT,0},
    {"iProjectileSpeed",1,FB_DEF,0x6F0,FK_INT,0},
    {"iProjectileSpeedUp",1,FB_DEF,0x6F4,FK_INT,0},
    {"iProjectileSpeedForward",1,FB_DEF,0x6F8,FK_INT,0},
    {"iProjectileActivateDist",1,FB_DEF,0x6FC,FK_INT,0},
    {"projLifetime",3,FB_DEF,0x700,FK_FLOAT,0},
    {"timeToAccelerate",3,FB_DEF,0x704,FK_FLOAT,0},
    {"projectileCurvature",1,FB_DEF,0x708,FK_FLOAT,0},
    {"projExplosion",1,FB_DEF,0x720,FK_INT,0},
    {"stickiness",1,FB_DEF,0x748,FK_INT,0},
    {"lowAmmoWarningThreshold",1,FB_DEF,0x74C,FK_FLOAT,0},
    {"ricochetChance",1,FB_DEF,0x750,FK_FLOAT,0},
    {"riotShieldEnableDamage",1,FB_DEF,0x754,FK_BOOL,0},
    {"riotShieldHealth",1,FB_DEF,0x758,FK_INT,0},
    {"riotShieldDamageMult",1,FB_DEF,0x75C,FK_FLOAT,0},
    {"guidedMissileType",0,FB_DEF,0x78C,FK_INT,0},
    {"maxSteeringAccel",4,FB_DEF,0x790,FK_FLOAT,0},
    {"projIgnitionDelay",3,FB_DEF,0x794,FK_FLOAT,0},
    {"fAdsAimPitch",4,FB_DEF,0x7A8,FK_FLOAT,0},
    {"fAdsCrosshairInFrac",4,FB_DEF,0x7AC,FK_FLOAT,0},
    {"fAdsCrosshairOutFrac",4,FB_DEF,0x7B0,FK_FLOAT,0},
    {"adsShouldShowCrosshair",0,FB_DEF,0x7B4,FK_BOOL,0},
    {"adsGunKickReducedKickBullets",4,FB_DEF,0x7B8,FK_INT,0},
    {"adsGunKickReducedKickPercent",4,FB_DEF,0x7BC,FK_FLOAT,0},
    {"fAdsGunKickPitchMin",4,FB_DEF,0x7C0,FK_FLOAT,0},
    {"fAdsGunKickPitchMax",4,FB_DEF,0x7C4,FK_FLOAT,0},
    {"fAdsGunKickYawMin",4,FB_DEF,0x7C8,FK_FLOAT,0},
    {"fAdsGunKickYawMax",4,FB_DEF,0x7CC,FK_FLOAT,0},
    {"fAdsGunKickMagMin",4,FB_DEF,0x7D0,FK_FLOAT,0},
    {"fAdsGunKickAccel",4,FB_DEF,0x7D4,FK_FLOAT,0},
    {"fAdsGunKickSpeedMax",4,FB_DEF,0x7D8,FK_FLOAT,0},
    {"fAdsGunKickSpeedDecay",4,FB_DEF,0x7DC,FK_FLOAT,0},
    {"fAdsGunKickStaticDecay",4,FB_DEF,0x7E0,FK_FLOAT,0},
    {"fAdsViewKickPitchMin",4,FB_DEF,0x7E4,FK_FLOAT,0},
    {"fAdsViewKickPitchMax",4,FB_DEF,0x7E8,FK_FLOAT,0},
    {"fAdsViewKickYawMin",4,FB_DEF,0x7EC,FK_FLOAT,0},
    {"fAdsViewKickYawMax",4,FB_DEF,0x7F0,FK_FLOAT,0},
    {"fAdsViewKickMagMin",4,FB_DEF,0x7F4,FK_FLOAT,0},
    {"fAdsViewScatterMin",4,FB_DEF,0x7F8,FK_FLOAT,0},
    {"fAdsViewScatterMax",4,FB_DEF,0x7FC,FK_FLOAT,0},
    {"fAdsSpread",6,FB_DEF,0x800,FK_FLOAT,0},
    {"hipGunKickReducedKickBullets",4,FB_DEF,0x804,FK_INT,0},
    {"hipGunKickReducedKickPercent",4,FB_DEF,0x808,FK_FLOAT,0},
    {"fHipGunKickPitchMin",4,FB_DEF,0x80C,FK_FLOAT,0},
    {"fHipGunKickPitchMax",4,FB_DEF,0x810,FK_FLOAT,0},
    {"fHipGunKickYawMin",4,FB_DEF,0x814,FK_FLOAT,0},
    {"fHipGunKickYawMax",4,FB_DEF,0x818,FK_FLOAT,0},
    {"fHipGunKickMagMin",4,FB_DEF,0x81C,FK_FLOAT,0},
    {"fHipGunKickAccel",4,FB_DEF,0x820,FK_FLOAT,0},
    {"fHipGunKickSpeedMax",4,FB_DEF,0x824,FK_FLOAT,0},
    {"fHipGunKickSpeedDecay",4,FB_DEF,0x828,FK_FLOAT,0},
    {"fHipGunKickStaticDecay",4,FB_DEF,0x82C,FK_FLOAT,0},
    {"fHipViewKickPitchMin",4,FB_DEF,0x830,FK_FLOAT,0},
    {"fHipViewKickPitchMax",4,FB_DEF,0x834,FK_FLOAT,0},
    {"fHipViewKickYawMin",4,FB_DEF,0x838,FK_FLOAT,0},
    {"fHipViewKickYawMax",4,FB_DEF,0x83C,FK_FLOAT,0},
    {"fHipViewKickMagMin",4,FB_DEF,0x840,FK_FLOAT,0},
    {"fHipViewScatterMin",4,FB_DEF,0x844,FK_FLOAT,0},
    {"fHipViewScatterMax",4,FB_DEF,0x848,FK_FLOAT,0},
    {"fightDist",6,FB_DEF,0x84C,FK_FLOAT,0},
    {"maxDist",6,FB_DEF,0x850,FK_FLOAT,0},
    {"iPositionReloadTransTime",2,FB_DEF,0x87C,FK_INT,0},
    {"leftArc",6,FB_DEF,0x880,FK_FLOAT,0},
    {"rightArc",6,FB_DEF,0x884,FK_FLOAT,0},
    {"topArc",6,FB_DEF,0x888,FK_FLOAT,0},
    {"bottomArc",6,FB_DEF,0x88C,FK_FLOAT,0},
    {"accuracy",6,FB_DEF,0x890,FK_FLOAT,0},
    {"aiSpread",6,FB_DEF,0x894,FK_FLOAT,0},
    {"playerSpread",6,FB_DEF,0x898,FK_FLOAT,0},
    {"minVertTurnSpeed",6,FB_DEF,0x89C,FK_FLOAT,0},
    {"minHorTurnSpeed",6,FB_DEF,0x8A0,FK_FLOAT,0},
    {"maxVertTurnSpeed",6,FB_DEF,0x8A4,FK_FLOAT,0},
    {"maxHorTurnSpeed",6,FB_DEF,0x8A8,FK_FLOAT,0},
    {"pitchConvergenceTime",6,FB_DEF,0x8AC,FK_FLOAT,0},
    {"yawConvergenceTime",6,FB_DEF,0x8B0,FK_FLOAT,0},
    {"suppressTime",3,FB_DEF,0x8B4,FK_FLOAT,0},
    {"maxRange",4,FB_DEF,0x8B8,FK_FLOAT,0},
    {"fAnimHorRotateInc",4,FB_DEF,0x8BC,FK_FLOAT,0},
    {"fPlayerPositionDist",6,FB_DEF,0x8C0,FK_FLOAT,0},
    {"horizViewJitter",4,FB_DEF,0x8E0,FK_FLOAT,0},
    {"vertViewJitter",4,FB_DEF,0x8E4,FK_FLOAT,0},
    {"scanSpeed",4,FB_DEF,0x8E8,FK_FLOAT,0},
    {"scanAccel",4,FB_DEF,0x8EC,FK_FLOAT,0},
    {"scanPauseTime",3,FB_DEF,0x8F0,FK_INT,0},
    {"minDamage",1,FB_DEF,0x908,FK_INT,0},
    {"minPlayerDamage",1,FB_DEF,0x90C,FK_INT,0},
    {"fMaxDamageRange",1,FB_DEF,0x910,FK_FLOAT,0},
    {"fMinDamageRange",1,FB_DEF,0x914,FK_FLOAT,0},
    {"destabilizationRateTime",3,FB_DEF,0x918,FK_FLOAT,0},
    {"destabilizationCurvatureMax",4,FB_DEF,0x91C,FK_FLOAT,0},
    {"destabilizeDistance",4,FB_DEF,0x920,FK_INT,0},
    {"turretADSEnabled",0,FB_DEF,0x948,FK_BOOL,0},
    {"turretADSTime",3,FB_DEF,0x94C,FK_FLOAT,0},
    {"turretFov",4,FB_DEF,0x950,FK_FLOAT,0},
    {"turretFovADS",4,FB_DEF,0x954,FK_FLOAT,0},
    {"turretScopeZoomRate",4,FB_DEF,0x958,FK_FLOAT,0},
    {"turretScopeZoomMin",4,FB_DEF,0x95C,FK_FLOAT,0},
    {"turretScopeZoomMax",4,FB_DEF,0x960,FK_FLOAT,0},
    {"turretOverheatUpRate",4,FB_DEF,0x964,FK_FLOAT,0},
    {"turretOverheatDownRate",4,FB_DEF,0x968,FK_FLOAT,0},
    {"turretOverheatPenalty",4,FB_DEF,0x96C,FK_FLOAT,0},
    {"turretBarrelSpinSpeed",4,FB_DEF,0x988,FK_FLOAT,0},
    {"turretBarrelSpinUpTime",3,FB_DEF,0x98C,FK_FLOAT,0},
    {"turretBarrelSpinDownTime",3,FB_DEF,0x990,FK_FLOAT,0},
    {"missileConeSoundRadiusAtTop",4,FB_DEF,0x9F0,FK_FLOAT,0},
    {"missileConeSoundRadiusAtBase",4,FB_DEF,0x9F4,FK_FLOAT,0},
    {"missileConeSoundHeight",4,FB_DEF,0x9F8,FK_FLOAT,0},
    {"missileConeSoundOriginOffset",4,FB_DEF,0x9FC,FK_FLOAT,0},
    {"missileConeSoundVolumescaleAtCore",4,FB_DEF,0xA00,FK_FLOAT,0},
    {"missileConeSoundVolumescaleAtEdge",4,FB_DEF,0xA04,FK_FLOAT,0},
    {"missileConeSoundVolumescaleCoreSize",4,FB_DEF,0xA08,FK_FLOAT,0},
    {"missileConeSoundPitchAtTop",4,FB_DEF,0xA0C,FK_FLOAT,0},
    {"missileConeSoundPitchAtBottom",4,FB_DEF,0xA10,FK_FLOAT,0},
    {"missileConeSoundPitchTopSize",4,FB_DEF,0xA14,FK_FLOAT,0},
    {"missileConeSoundPitchBottomSize",4,FB_DEF,0xA18,FK_FLOAT,0},
    {"missileConeSoundCrossfadeTopSize",4,FB_DEF,0xA1C,FK_FLOAT,0},
    {"missileConeSoundCrossfadeBottomSize",4,FB_DEF,0xA20,FK_FLOAT,0},
    {"knifeAttachTagOverride",0,FB_DEF,0xA24,FK_INT,0},
    {"knifeAlwaysAttached",0,FB_DEF,0xA28,FK_BOOL,0},
    {"meleeOverrideValues",0,FB_DEF,0xA29,FK_BOOL,0},
    {"aim_automelee_lerp",4,FB_DEF,0xA2C,FK_FLOAT,0},
    {"aim_automelee_range",4,FB_DEF,0xA30,FK_FLOAT,0},
    {"aim_automelee_region_height",4,FB_DEF,0xA34,FK_FLOAT,0},
    {"aim_automelee_region_width",4,FB_DEF,0xA38,FK_FLOAT,0},
    {"player_meleeHeight",6,FB_DEF,0xA3C,FK_FLOAT,0},
    {"player_meleeRange",6,FB_DEF,0xA40,FK_FLOAT,0},
    {"player_meleeWidth",6,FB_DEF,0xA44,FK_FLOAT,0},
    {"sharedAmmo",1,FB_DEF,0xA48,FK_BOOL,0},
    {"lockonSupported",0,FB_DEF,0xA49,FK_BOOL,0},
    {"requireLockonToFire",0,FB_DEF,0xA4A,FK_BOOL,0},
    {"isAirburstWeapon",0,FB_DEF,0xA4B,FK_BOOL,0},
    {"bigExplosion",1,FB_DEF,0xA4C,FK_BOOL,0},
    {"noAdsWhenMagEmpty",0,FB_DEF,0xA4D,FK_BOOL,0},
    {"avoidDropCleanup",0,FB_DEF,0xA4E,FK_BOOL,0},
    {"inheritsPerks",0,FB_DEF,0xA4F,FK_BOOL,0},
    {"crosshairColorChange",0,FB_DEF,0xA50,FK_BOOL,0},
    {"bRifleBullet",0,FB_DEF,0xA51,FK_BOOL,0},
    {"armorPiercing",0,FB_DEF,0xA52,FK_BOOL,0},
    {"bBoltAction",0,FB_DEF,0xA53,FK_BOOL,0},
    {"aimDownSight",0,FB_DEF,0xA54,FK_BOOL,0},
    {"canHoldBreath",0,FB_DEF,0xA55,FK_BOOL,0},
    {"meleeOnly",0,FB_DEF,0xA56,FK_BOOL,0},
    {"canVariableZoom",0,FB_DEF,0xA57,FK_BOOL,0},
    {"bRechamberWhileAds",0,FB_DEF,0xA58,FK_BOOL,0},
    {"bBulletExplosiveDamage",1,FB_DEF,0xA59,FK_BOOL,0},
    {"bCookOffHold",0,FB_DEF,0xA5A,FK_BOOL,0},
    {"reticleSpin45",0,FB_DEF,0xA5B,FK_BOOL,0},
    {"bClipOnly",1,FB_DEF,0xA5C,FK_BOOL,0},
    {"noAmmoPickup",1,FB_DEF,0xA5D,FK_BOOL,0},
    {"adsFireOnly",0,FB_DEF,0xA5E,FK_BOOL,0},
    {"cancelAutoHolsterWhenEmpty",0,FB_DEF,0xA5F,FK_BOOL,0},
    {"disableSwitchToWhenEmpty",0,FB_DEF,0xA60,FK_BOOL,0},
    {"suppressAmmoReserveDisplay",1,FB_DEF,0xA61,FK_BOOL,0},
    {"laserSightDuringNightvision",0,FB_DEF,0xA62,FK_BOOL,0},
    {"markableViewmodel",0,FB_DEF,0xA63,FK_BOOL,0},
    {"noDualWield",0,FB_DEF,0xA64,FK_BOOL,0},
    {"flipKillIcon",0,FB_DEF,0xA65,FK_BOOL,0},
    {"bNoPartialReload",2,FB_DEF,0xA66,FK_BOOL,0},
    {"bSegmentedReload",2,FB_DEF,0xA67,FK_BOOL,0},
    {"bMultipleReload",2,FB_DEF,0xA68,FK_BOOL,0},
    {"blocksProne",0,FB_DEF,0xA69,FK_BOOL,0},
    {"silenced",0,FB_DEF,0xA6A,FK_BOOL,0},
    {"isRollingGrenade",0,FB_DEF,0xA6B,FK_BOOL,0},
    {"projExplosionEffectForceNormalUp",1,FB_DEF,0xA6C,FK_BOOL,0},
    {"projExplosionEffectInheritParentDirection",1,FB_DEF,0xA6D,FK_BOOL,0},
    {"bProjImpactExplode",0,FB_DEF,0xA6E,FK_BOOL,0},
    {"bProjTrajectoryEvents",0,FB_DEF,0xA6F,FK_BOOL,0},
    {"bProjWhizByEnabled",0,FB_DEF,0xA70,FK_BOOL,0},
    {"stickToPlayers",0,FB_DEF,0xA71,FK_BOOL,0},
    {"stickToVehicles",0,FB_DEF,0xA72,FK_BOOL,0},
    {"stickToTurrets",0,FB_DEF,0xA73,FK_BOOL,0},
    {"thrownSideways",0,FB_DEF,0xA74,FK_BOOL,0},
    {"hasDetonator",0,FB_DEF,0xA75,FK_BOOL,0},
    {"disableFiring",0,FB_DEF,0xA76,FK_BOOL,0},
    {"timedDetonation",0,FB_DEF,0xA77,FK_BOOL,0},
    {"rotate",0,FB_DEF,0xA78,FK_BOOL,0},
    {"holdButtonToThrow",0,FB_DEF,0xA79,FK_BOOL,0},
    {"freezeMovementWhenFiring",0,FB_DEF,0xA7A,FK_BOOL,0},
    {"thermalScope",0,FB_DEF,0xA7B,FK_BOOL,0},
    {"thermalToggle",0,FB_DEF,0xA7C,FK_BOOL,0},
    {"outlineEnemies",0,FB_DEF,0xA7D,FK_BOOL,0},
    {"altModeSameWeapon",0,FB_DEF,0xA7E,FK_BOOL,0},
    {"turretBarrelSpinEnabled",0,FB_DEF,0xA7F,FK_BOOL,0},
    {"missileConeSoundEnabled",0,FB_DEF,0xA80,FK_BOOL,0},
    {"missileConeSoundPitchshiftEnabled",0,FB_DEF,0xA81,FK_BOOL,0},
    {"missileConeSoundCrossfadeEnabled",0,FB_DEF,0xA82,FK_BOOL,0},
    {"offhandHoldIsCancelable",0,FB_DEF,0xA83,FK_BOOL,0},
    {"doNotAllowAttachmentsToOverrideSpread",0,FB_DEF,0xA84,FK_BOOL,0},
    {"useFastReloadAnims",2,FB_DEF,0xA85,FK_BOOL,0},
    {"useScopeDrift",0,FB_DEF,0xA86,FK_BOOL,0},
    {"alwaysShatterGlassOnImpact",0,FB_DEF,0xA87,FK_BOOL,0},
    {"oldWeapon",0,FB_DEF,0xA88,FK_BOOL,0},
    {"stowTag",0,FB_DEF,0xA8C,FK_INT,0},
    {"handXModel",5,FB_DEF,0x10,FK_MODEL_DIRECT,0},
    {"camoWorldModel",5,FB_DEF,0x18,FK_MODEL_DIRECT,0},
    {"camoViewModel",5,FB_DEF,0x20,FK_MODEL_DIRECT,0},
    {"worldClipModel",5,FB_DEF,0x350,FK_MODEL_DIRECT,0},
    {"rocketModel",5,FB_DEF,0x358,FK_MODEL_DIRECT,0},
    {"knifeModel",5,FB_DEF,0x360,FK_MODEL_DIRECT,0},
    {"worldKnifeModel",5,FB_DEF,0x368,FK_MODEL_DIRECT,0},
    {"projectileModel",5,FB_DEF,0x718,FK_MODEL_DIRECT,0},
    {"stowOffsetModel",5,FB_DEF,0xA90,FK_MODEL_DIRECT,0},
    {"gunModel[0]",5,FB_DEF,0x8,FK_MODEL_ARRAY,0},
    {"gunModel[1]",5,FB_DEF,0x8,FK_MODEL_ARRAY,1},
    {"worldModel[0]",5,FB_DEF,0x348,FK_MODEL_ARRAY,0},
    {"worldModel[1]",5,FB_DEF,0x348,FK_MODEL_ARRAY,1},
    {"iFireDelay",3,FB_DEF,0x3F0,FK_INT,0},
    {"iMeleeDelay",3,FB_DEF,0x3F4,FK_INT,0},
    {"meleeChargeDelay",3,FB_DEF,0x3F8,FK_INT,0},
    {"iDetonateDelay",3,FB_DEF,0x3FC,FK_INT,0},
    {"iRechamberTime",3,FB_DEF,0x400,FK_INT,0},
    {"rechamberTimeOneHanded",3,FB_DEF,0x404,FK_INT,0},
    {"iRechamberBoltTime",3,FB_DEF,0x408,FK_INT,0},
    {"iHoldFireTime",3,FB_DEF,0x40C,FK_INT,0},
    {"iHoldPrimeTime",3,FB_DEF,0x410,FK_INT,0},
    {"iDetonateTime",3,FB_DEF,0x414,FK_INT,0},
    {"iMeleeTime",3,FB_DEF,0x418,FK_INT,0},
    {"meleeChargeTime",3,FB_DEF,0x41C,FK_INT,0},
    {"iReloadTime",2,FB_DEF,0x420,FK_INT,0},
    {"reloadShowRocketTime",2,FB_DEF,0x424,FK_INT,0},
    {"iReloadEmptyTime",2,FB_DEF,0x428,FK_INT,0},
    {"iReloadAddTime",2,FB_DEF,0x42C,FK_INT,0},
    {"iReloadEmptyAddTime",2,FB_DEF,0x430,FK_INT,0},
    {"iReloadStartTime",2,FB_DEF,0x434,FK_INT,0},
    {"iReloadStartAddTime",2,FB_DEF,0x438,FK_INT,0},
    {"iReloadEndTime",2,FB_DEF,0x43C,FK_INT,0},
    {"iDropTime",3,FB_DEF,0x440,FK_INT,0},
    {"iRaiseTime",3,FB_DEF,0x444,FK_INT,0},
    {"iAltDropTime",3,FB_DEF,0x448,FK_INT,0},
    {"quickDropTime",3,FB_DEF,0x44C,FK_INT,0},
    {"quickRaiseTime",3,FB_DEF,0x450,FK_INT,0},
    {"iBreachRaiseTime",3,FB_DEF,0x454,FK_INT,0},
    {"iEmptyRaiseTime",3,FB_DEF,0x458,FK_INT,0},
    {"iEmptyDropTime",3,FB_DEF,0x45C,FK_INT,0},
    {"sprintInTime",3,FB_DEF,0x460,FK_INT,0},
    {"sprintLoopTime",3,FB_DEF,0x464,FK_INT,0},
    {"sprintOutTime",3,FB_DEF,0x468,FK_INT,0},
    {"stunnedTimeBegin",3,FB_DEF,0x46C,FK_INT,0},
    {"stunnedTimeLoop",3,FB_DEF,0x470,FK_INT,0},
    {"stunnedTimeEnd",3,FB_DEF,0x474,FK_INT,0},
    {"nightVisionWearTime",3,FB_DEF,0x478,FK_INT,0},
    {"nightVisionWearTimeFadeOutEnd",3,FB_DEF,0x47C,FK_INT,0},
    {"nightVisionWearTimePowerUp",3,FB_DEF,0x480,FK_INT,0},
    {"nightVisionRemoveTime",3,FB_DEF,0x484,FK_INT,0},
    {"nightVisionRemoveTimePowerDown",3,FB_DEF,0x488,FK_INT,0},
    {"nightVisionRemoveTimeFadeInStart",3,FB_DEF,0x48C,FK_INT,0},
    {"fuseTime",3,FB_DEF,0x490,FK_INT,0},
    {"aiFuseTime",3,FB_DEF,0x494,FK_INT,0},
    {"primeTime",3,FB_DEF,0x498,FK_INT,0},
    {"bHoldFullPrime",3,FB_DEF,0x49C,FK_BOOL,0},
    {"blastFrontTime",3,FB_DEF,0x4A0,FK_INT,0},
    {"blastRightTime",3,FB_DEF,0x4A4,FK_INT,0},
    {"blastBackTime",3,FB_DEF,0x4A8,FK_INT,0},
    {"blastLeftTime",3,FB_DEF,0x4AC,FK_INT,0},
    {"slideInTime",3,FB_DEF,0x4B0,FK_INT,0},
    {"slideLoopTime",3,FB_DEF,0x4B4,FK_INT,0},
    {"slideOutTime",3,FB_DEF,0x4B8,FK_INT,0},
    {"akimbo.iFireDelay",3,FB_DEF,0x4BC,FK_INT,0},
    {"akimbo.iMeleeDelay",3,FB_DEF,0x4C0,FK_INT,0},
    {"akimbo.meleeChargeDelay",3,FB_DEF,0x4C4,FK_INT,0},
    {"akimbo.iDetonateDelay",3,FB_DEF,0x4C8,FK_INT,0},
    {"akimbo.iRechamberTime",3,FB_DEF,0x4CC,FK_INT,0},
    {"akimbo.rechamberTimeOneHanded",3,FB_DEF,0x4D0,FK_INT,0},
    {"akimbo.iRechamberBoltTime",3,FB_DEF,0x4D4,FK_INT,0},
    {"akimbo.iHoldFireTime",3,FB_DEF,0x4D8,FK_INT,0},
    {"akimbo.iHoldPrimeTime",3,FB_DEF,0x4DC,FK_INT,0},
    {"akimbo.iDetonateTime",3,FB_DEF,0x4E0,FK_INT,0},
    {"akimbo.iMeleeTime",3,FB_DEF,0x4E4,FK_INT,0},
    {"akimbo.meleeChargeTime",3,FB_DEF,0x4E8,FK_INT,0},
    {"akimbo.iReloadTime",2,FB_DEF,0x4EC,FK_INT,0},
    {"akimbo.reloadShowRocketTime",2,FB_DEF,0x4F0,FK_INT,0},
    {"akimbo.iReloadEmptyTime",2,FB_DEF,0x4F4,FK_INT,0},
    {"akimbo.iReloadAddTime",2,FB_DEF,0x4F8,FK_INT,0},
    {"akimbo.iReloadEmptyAddTime",2,FB_DEF,0x4FC,FK_INT,0},
    {"akimbo.iReloadStartTime",2,FB_DEF,0x500,FK_INT,0},
    {"akimbo.iReloadStartAddTime",2,FB_DEF,0x504,FK_INT,0},
    {"akimbo.iReloadEndTime",2,FB_DEF,0x508,FK_INT,0},
    {"akimbo.iDropTime",3,FB_DEF,0x50C,FK_INT,0},
    {"akimbo.iRaiseTime",3,FB_DEF,0x510,FK_INT,0},
    {"akimbo.iAltDropTime",3,FB_DEF,0x514,FK_INT,0},
    {"akimbo.quickDropTime",3,FB_DEF,0x518,FK_INT,0},
    {"akimbo.quickRaiseTime",3,FB_DEF,0x51C,FK_INT,0},
    {"akimbo.iBreachRaiseTime",3,FB_DEF,0x520,FK_INT,0},
    {"akimbo.iEmptyRaiseTime",3,FB_DEF,0x524,FK_INT,0},
    {"akimbo.iEmptyDropTime",3,FB_DEF,0x528,FK_INT,0},
    {"akimbo.sprintInTime",3,FB_DEF,0x52C,FK_INT,0},
    {"akimbo.sprintLoopTime",3,FB_DEF,0x530,FK_INT,0},
    {"akimbo.sprintOutTime",3,FB_DEF,0x534,FK_INT,0},
    {"akimbo.stunnedTimeBegin",3,FB_DEF,0x538,FK_INT,0},
    {"akimbo.stunnedTimeLoop",3,FB_DEF,0x53C,FK_INT,0},
    {"akimbo.stunnedTimeEnd",3,FB_DEF,0x540,FK_INT,0},
    {"akimbo.nightVisionWearTime",3,FB_DEF,0x544,FK_INT,0},
    {"akimbo.nightVisionWearTimeFadeOutEnd",3,FB_DEF,0x548,FK_INT,0},
    {"akimbo.nightVisionWearTimePowerUp",3,FB_DEF,0x54C,FK_INT,0},
    {"akimbo.nightVisionRemoveTime",3,FB_DEF,0x550,FK_INT,0},
    {"akimbo.nightVisionRemoveTimePowerDown",3,FB_DEF,0x554,FK_INT,0},
    {"akimbo.nightVisionRemoveTimeFadeInStart",3,FB_DEF,0x558,FK_INT,0},
    {"akimbo.fuseTime",3,FB_DEF,0x55C,FK_INT,0},
    {"akimbo.aiFuseTime",3,FB_DEF,0x560,FK_INT,0},
    {"akimbo.primeTime",3,FB_DEF,0x564,FK_INT,0},
    {"akimbo.bHoldFullPrime",3,FB_DEF,0x568,FK_BOOL,0},
    {"akimbo.blastFrontTime",3,FB_DEF,0x56C,FK_INT,0},
    {"akimbo.blastRightTime",3,FB_DEF,0x570,FK_INT,0},
    {"akimbo.blastBackTime",3,FB_DEF,0x574,FK_INT,0},
    {"akimbo.blastLeftTime",3,FB_DEF,0x578,FK_INT,0},
    {"akimbo.slideInTime",3,FB_DEF,0x57C,FK_INT,0},
    {"akimbo.slideLoopTime",3,FB_DEF,0x580,FK_INT,0},
    {"akimbo.slideOutTime",3,FB_DEF,0x584,FK_INT,0},
    {"adsZoomFov",4,FB_COMPLETE,0x90,FK_FLOAT,0},
    {"adsTransInTime",3,FB_COMPLETE,0x94,FK_INT,0},
    {"adsTransOutTime",3,FB_COMPLETE,0x98,FK_INT,0},
    {"clipSize",1,FB_COMPLETE,0x9C,FK_INT,0},
    {"impactType",0,FB_COMPLETE,0xA0,FK_INT,0},
    {"fireTime",3,FB_COMPLETE,0xA4,FK_INT,0},
    {"fireTimeAkimbo",3,FB_COMPLETE,0xA8,FK_INT,0},
    {"dpadIconRatio",0,FB_COMPLETE,0xAC,FK_INT,0},
    {"penetrateMultiplier",1,FB_COMPLETE,0xB0,FK_FLOAT,0},
    {"adsViewKickCenterSpeed",4,FB_COMPLETE,0xB4,FK_FLOAT,0},
    {"hipViewKickCenterSpeed",4,FB_COMPLETE,0xB8,FK_FLOAT,0},
    {"altWeapon",0,FB_COMPLETE,0xC8,FK_INT,0},
    {"altRaiseTime",3,FB_COMPLETE,0xCC,FK_INT,0},
    {"altRaiseTimeAkimbo",3,FB_COMPLETE,0xD0,FK_INT,0},
    {"fireAnimLength",3,FB_COMPLETE,0xE8,FK_INT,0},
    {"fireAnimLengthAkimbo",3,FB_COMPLETE,0xEC,FK_INT,0},
    {"firstRaiseTime",3,FB_COMPLETE,0xF0,FK_INT,0},
    {"firstRaiseTimeAkimbo",3,FB_COMPLETE,0xF4,FK_INT,0},
    {"ammoDropStockMax",1,FB_COMPLETE,0xF8,FK_INT,0},
    {"adsDofStart",4,FB_COMPLETE,0xFC,FK_FLOAT,0},
    {"adsDofEnd",4,FB_COMPLETE,0x100,FK_FLOAT,0},
    {"motionTracker",0,FB_COMPLETE,0x118,FK_BOOL,0},
    {"enhanced",0,FB_COMPLETE,0x119,FK_BOOL,0},
    {"dpadIconShowsAmmo",0,FB_COMPLETE,0x11A,FK_BOOL,0},
};
static const int kFieldCount=(int)(sizeof(kFields)/sizeof(kFields[0]));

struct BatchFieldValue { UINT_PTR bits; char asset[96]; };
struct BatchOverrideValue { WORD attachment1; WORD attachment2; DWORD animTreeType; int animTime; int altTime; char anim[80]; char altAnim[80]; };
struct BatchWeaponEntry {
    DWORD magic; char weapon[80]; BatchFieldValue field[kFieldCount];
    char anim[3][124][80]; DWORD overrideCount; BatchOverrideValue overrides[64];
};
static BatchWeaponEntry g_batch[24]={0};
static int g_batchCount=0;

static const char* kAnimLabels[124]={
    "ROOT",
    "IDLE",
    "EMPTY_IDLE",
    "FIRE",
    "HOLD_FIRE",
    "LASTSHOT",
    "RECHAMBER",
    "GRENADE_PRIME",
    "GRENADE_PRIME_READY",
    "MELEE_SWIPE",
    "MELEE_HIT",
    "MELEE_FATAL",
    "MELEE_MISS",
    "MELEE_VICTIM_CROUCH_HIT",
    "MELEE_VICTIM_CROUCH_FATAL",
    "MELEE_VICTIM_CROUCH_MISS",
    "RELOAD",
    "RELOAD_EMPTY",
    "RELOAD_START",
    "RELOAD_END",
    "FAST_RELOAD",
    "FAST_RELOAD_EMPTY",
    "FAST_RELOAD_START",
    "FAST_RELOAD_END",
    "DUALMAG_RELOAD",
    "DUALMAG_RELOAD_EMPTY",
    "SPEED_RELOAD",
    "RELOAD_FROM_ALT",
    "RAISE",
    "FIRST_RAISE",
    "BREACH_RAISE",
    "DROP",
    "ALT_RAISE",
    "ALT_DROP",
    "ALT_OVERRIDE",
    "QUICK_RAISE",
    "QUICK_DROP",
    "EMPTY_RAISE",
    "EMPTY_DROP",
    "HYBRID_SIGHT_ON",
    "HYBRID_SIGHT_OFF",
    "SPRINT_IN",
    "SPRINT_IN_FROM_SLIDE",
    "SPRINT_IN_CANCEL",
    "SPRINT_LOOP",
    "SPRINT_OUT",
    "SPRINTANDFIRE_IN",
    "SPRINTANDFIRE_LOOP",
    "SPRINTANDFIRE_OUT",
    "STUNNED_START",
    "STUNNED_LOOP",
    "STUNNED_END",
    "THROWBACK",
    "DETONATE",
    "NIGHTVISION_WEAR",
    "NIGHTVISION_REMOVE",
    "ADS_FIRE",
    "ADS_LASTSHOT",
    "ADS_RECHAMBER",
    "BLAST_FRONT",
    "BLAST_RIGHT",
    "BLAST_BACK",
    "BLAST_LEFT",
    "SLIDE_IN",
    "SLIDE_LOOP",
    "SLIDE_OUT_TO_SPRINT",
    "SLIDE_OUT",
    "SLIDE_AND_FIRE_IN",
    "SLIDE_AND_FIRE_LOOP",
    "SLIDE_AND_FIRE_OUT",
    "HIGH_JUMP_IN",
    "HIGH_JUMP_DROP_IN",
    "HIGH_JUMP_DROP_LOOP",
    "HIGH_JUMP_DROP_LAND",
    "DODGE_GROUND_BACK",
    "DODGE_GROUND_LEFT",
    "DODGE_GROUND_RIGHT",
    "DODGE_AIR_FORWARD",
    "DODGE_AIR_BACK",
    "DODGE_AIR_LEFT",
    "DODGE_AIR_RIGHT",
    "LAND_DIP",
    "RECOIL_SETTLE",
    "SWIM_LOOP",
    "MANTLE_UP_64",
    "MANTLE_UP_56",
    "MANTLE_UP_48",
    "MANTLE_UP_40",
    "MANTLE_UP_32",
    "MANTLE_UP_24",
    "MANTLE_UP_16",
    "MANTLE_OVER_64",
    "MANTLE_OVER_56",
    "MANTLE_OVER_48",
    "MANTLE_OVER_40",
    "MANTLE_OVER_32",
    "MANTLE_OVER_24",
    "MANTLE_OVER_16",
    "GOLIATH_ENTRY",
    "OFFHAND_SWITCH",
    "HEAT_COOLDOWN_IN",
    "HEAT_COOLDOWN_OUT",
    "OVERHEAT_OUT",
    "SCRIPTED",
    "INSPECTION",
    "RELOAD_MULTIPLE_1",
    "RELOAD_MULTIPLE_2",
    "RELOAD_MULTIPLE_3",
    "RELOAD_MULTIPLE_4",
    "RELOAD_MULTIPLE_5",
    "RELOAD_MULTIPLE_6",
    "RELOAD_MULTIPLE_7",
    "RELOAD_MULTIPLE_8",
    "RELOAD_MULTIPLE_FAST_1",
    "RELOAD_MULTIPLE_FAST_2",
    "RELOAD_MULTIPLE_FAST_3",
    "RELOAD_MULTIPLE_FAST_4",
    "RELOAD_MULTIPLE_FAST_5",
    "RELOAD_MULTIPLE_FAST_6",
    "RELOAD_MULTIPLE_FAST_7",
    "RELOAD_MULTIPLE_FAST_8",
    "SLOT_121",
    "SLOT_122",
    "SLOT_123"
};

static int readable_exec(void* p){MEMORY_BASIC_INFORMATION_X m;memset(&m,0,sizeof(m));if(VirtualQuery(p,&m,sizeof(m))<sizeof(m))return 0;if(m.State!=MEM_COMMIT)return 0;if((m.Protect&0xFF)==0x01)return 0;return 1;}
static int patch_bytes(void* dst,const void* src,SIZE_T n){DWORD old=0,tmp=0;if(!dst||!VirtualProtect(dst,n,PAGE_EXECUTE_READWRITE,&old))return 0;memcpy(dst,src,n);VirtualProtect(dst,n,old,&tmp);return 1;}
template<typename T> static int patch_value(void* dst,T v){return patch_bytes(dst,&v,sizeof(v));}

static const char* asset_name(void* p){if(!p)return ""; MEMORY_BASIC_INFORMATION_X m; if(VirtualQuery(p,&m,sizeof(m))<sizeof(m)||m.State!=MEM_COMMIT)return ""; const char* n=*(const char**)p; if(!n)return ""; if(VirtualQuery(n,&m,sizeof(m))<sizeof(m)||m.State!=MEM_COMMIT)return ""; return n;}

static void build_module_path(char*out,SIZE_T cap,const char*leaf){char tmp[520];tmp[0]=0;GetModuleFileNameA(g_module,tmp,519);tmp[519]=0;int last=-1;for(int i=0;tmp[i];i++)if(tmp[i]=='\\'||tmp[i]=='/')last=i;if(last>=0)tmp[last+1]=0;else tmp[0]=0;scopy(out,tmp,cap);scat(out,leaf,cap);}
static void make_temp_barrier_path(){char t[420];t[0]=0;DWORD n=GetTempPathA(400,t);if(n&&n<400){scopy(g_barrierPath,t,520);scat(g_barrierPath,"IW6X_JANU_NoBarriers_Internal.dll",520);}else build_module_path(g_barrierPath,520,"IW6X_JANU_NoBarriers_Internal.dll");}

static void status(const char*s){if(g_status)SetWindowTextA(g_status,s);}
static void set_bold(HWND h){ if(h && g_fontBold) SendMessageA(h,WM_SETFONT,(WPARAM)g_fontBold,TRUE); }
static HWND add_ctrl(const char*cls,const char*txt,DWORD style,int x,int y,int w,int h,int id,HWND*group,int*gn){HWND z=CreateWindowExA(0,cls,txt,WS_CHILD|WS_VISIBLE|style,x,y,w,h,g_main,(HMENU)(INT_PTR)id,g_module,0);if(z){SendMessageA(z,WM_SETFONT,(WPARAM)g_font,TRUE);if(g_allControlCount<512)g_allControls[g_allControlCount++]=z;if(group&&gn&&*gn<32)group[(*gn)++]=z;}return z;}
static HWND label(const char*t,int x,int y,int w,int h,HWND*g,int*n){return add_ctrl("STATIC",t,0,x,y,w,h,0,g,n);}
static HWND editbox(int x,int y,int w,int h,int id,HWND*g,int*n){return add_ctrl("EDIT","",WS_BORDER|ES_AUTOHSCROLL|WS_TABSTOP,x,y,w,h,id,g,n);}
static HWND button(const char*t,int x,int y,int w,int h,int id,HWND*g,int*n){HWND z=add_ctrl("BUTTON",t,BS_OWNERDRAW,x,y,w,h,id,g,n);if(z&&g_btnWndN<256)g_btnWnds[g_btnWndN++]=z;return z;}
static void show_group(HWND*g,int n,int show){for(int i=0;i<n;i++)ShowWindow(g[i],show?SW_SHOW:0);}
static void redraw_nav(){for(int i=0;i<7;i++)if(g_tabs[i])InvalidateRect(g_tabs[i],0,TRUE);for(int i=0;i<7;i++)if(g_wpCatButtons[i])InvalidateRect(g_wpCatButtons[i],0,TRUE);for(int i=0;i<4;i++)if(g_animSourceButtons[i])InvalidateRect(g_animSourceButtons[i],0,TRUE);for(int i=0;i<6;i++)if(g_animFilterButtons[i])InvalidateRect(g_animFilterButtons[i],0,TRUE);if(g_fxToggle)InvalidateRect(g_fxToggle,0,TRUE);for(int i=0;i<6;i++)if(g_fxStyleButtons[i])InvalidateRect(g_fxStyleButtons[i],0,TRUE);for(int i=0;i<3;i++){if(g_fxSpeedButtons[i])InvalidateRect(g_fxSpeedButtons[i],0,TRUE);if(g_fxDensityButtons[i])InvalidateRect(g_fxDensityButtons[i],0,TRUE);if(g_fxSizeButtons[i])InvalidateRect(g_fxSizeButtons[i],0,TRUE);if(g_fxBrightButtons[i])InvalidateRect(g_fxBrightButtons[i],0,TRUE);}for(int i=0;i<2;i++)if(g_fxScopeButtons[i])InvalidateRect(g_fxScopeButtons[i],0,TRUE);}
static void switch_tab(int tab){g_activeTab=tab;show_group(g_wp,g_wpN,tab==0);show_group(g_an,g_anN,tab==1);show_group(g_sv,g_svN,tab==2);show_group(g_nb,g_nbN,tab==3);show_group(g_fx,g_fxN,tab==4);show_group(g_th,g_thN,tab==5);show_group(g_bt,g_btN,tab==6);redraw_nav();}
static void list_begin(HWND h){if(h)SendMessageA(h,WM_SETREDRAW,FALSE,0);}
static void list_end(HWND h){if(h){SendMessageA(h,WM_SETREDRAW,TRUE,0);InvalidateRect(h,0,TRUE);}}

static void set_int_edit(HWND h,int v){char b[32];int_to_str(v,b);SetWindowTextA(h,b);}
static void set_float_edit(HWND h,float v){char b[32];float_to_str(v,b);SetWindowTextA(h,b);}
static int get_int_edit(HWND h){char b[64];b[0]=0;GetWindowTextA(h,b,63);return parse_int(b);}
static float get_float_edit(HWND h){char b[64];b[0]=0;GetWindowTextA(h,b,63);return parse_float(b);}
static void get_text(HWND h,char*b,int cap){b[0]=0;GetWindowTextA(h,b,cap);b[cap-1]=0;}

static void save_theme_file(){HANDLE h=CreateFileA(g_themePath,GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return;DWORD wr=0;DWORD v=(DWORD)g_themeIndex;WriteFile(h,&v,sizeof(v),&wr,0);CloseHandle(h);}
static void load_theme_file(){g_themeIndex=0;HANDLE h=CreateFileA(g_themePath,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return;DWORD rd=0,v=0;if(ReadFile(h,&v,sizeof(v),&rd,0)&&rd==sizeof(v)&&v<(DWORD)kThemeCount)g_themeIndex=(int)v;CloseHandle(h);}
static void destroy_theme_brushes(){if(g_bgBrush)DeleteObject(g_bgBrush);if(g_panelBrush)DeleteObject(g_panelBrush);if(g_editBrush)DeleteObject(g_editBrush);if(g_accentBrush)DeleteObject(g_accentBrush);if(g_selectBrush)DeleteObject(g_selectBrush);if(g_borderBrush)DeleteObject(g_borderBrush);if(g_brightBrush)DeleteObject(g_brightBrush);g_bgBrush=g_panelBrush=g_editBrush=g_accentBrush=g_selectBrush=g_borderBrush=g_brightBrush=0;}
static void rebuild_ghost_tint(){
    unsigned ar=(unsigned)(C_ACCENT&255), ag=(unsigned)((C_ACCENT>>8)&255), ab=(unsigned)((C_ACCENT>>16)&255);
    for(int i=0;i<kGhostArtW*kGhostArtH;i++){
        unsigned b=kGhostArtBGR[i*3+0],g=kGhostArtBGR[i*3+1],r=kGhostArtBGR[i*3+2];
        unsigned lum=(r*30+g*59+b*11)/100;
        // Keep shadows neutral; push highlights toward the active theme accent.
        unsigned mix=(lum>48)?72u:38u;
        unsigned rr=(lum*(100-mix)+ar*mix)/100;
        unsigned gg=(lum*(100-mix)+ag*mix)/100;
        unsigned bb=(lum*(100-mix)+ab*mix)/100;
        if(rr>255)rr=255;if(gg>255)gg=255;if(bb>255)bb=255;
        gGhostTintBGR[i*3+0]=(BYTE)bb;gGhostTintBGR[i*3+1]=(BYTE)gg;gGhostTintBGR[i*3+2]=(BYTE)rr;
    }
}
static void build_icon_pixels(){for(int y=0;y<32;y++)for(int x=0;x<128;x++)g_iconBGRA[(31-y)*128+x]=kLogo32BGRA[y*128+x];}
static HICON make_icon(){static BYTE andBits[128]={0};return CreateIcon(g_module,32,32,1,32,andBits,g_iconBGRA);}
static void create_theme_brushes(){const ThemeDef&t=kThemes[g_themeIndex];C_BG=t.bg;C_PANEL=t.panel;C_EDIT=t.edit;C_ACCENT=t.accent;C_ACCENT_BRIGHT=t.accentBright;C_SELECT=t.select;C_BORDER=t.border;C_TEXT=t.text;C_DIM=t.dim;g_bgBrush=CreateSolidBrush(C_BG);g_panelBrush=CreateSolidBrush(C_PANEL);g_editBrush=CreateSolidBrush(C_EDIT);g_accentBrush=CreateSolidBrush(C_ACCENT);g_selectBrush=CreateSolidBrush(C_SELECT);g_borderBrush=CreateSolidBrush(C_BORDER);g_brightBrush=CreateSolidBrush(C_ACCENT_BRIGHT);build_icon_pixels();}
static void invalidate_all_theme_controls(){if(g_main)InvalidateRect(g_main,0,TRUE);for(int i=0;i<g_allControlCount;i++)if(g_allControls[i])InvalidateRect(g_allControls[i],0,TRUE);redraw_nav();}
static void apply_theme(int idx,int persist){if(idx<0||idx>=kThemeCount)return;g_themeIndex=idx;destroy_theme_brushes();create_theme_brushes();if(g_themeNameLabel)SetWindowTextA(g_themeNameLabel,kThemes[g_themeIndex].name);if(persist)save_theme_file();if(g_main){HICON n=make_icon();if(n){SendMessageA(g_main,WM_SETICON,1,(LPARAM)n);SendMessageA(g_main,WM_SETICON,0,(LPARAM)n);if(g_hIcon)DestroyIcon(g_hIcon);g_hIcon=n;}}invalidate_all_theme_controls();}
static void save_window_pos(){struct WinDisk{DWORD magic;int x,y;};WinDisk w;w.magic=0x31574A4Au;w.x=g_savedX;w.y=g_savedY;HANDLE h=CreateFileA(g_winPath,GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return;DWORD wr=0;WriteFile(h,&w,sizeof(w),&wr,0);CloseHandle(h);}
static int load_window_pos(int*x,int*y){struct WinDisk{DWORD magic;int x,y;};WinDisk w;memset(&w,0,sizeof(w));HANDLE h=CreateFileA(g_winPath,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return 0;DWORD rd=0;int ok=ReadFile(h,&w,sizeof(w),&rd,0)&&rd==sizeof(w)&&w.magic==0x31574A4Au;CloseHandle(h);if(!ok)return 0;
    int sw=GetSystemMetrics(0),sh=GetSystemMetrics(1);if(sw<=0)sw=1920;if(sh<=0)sh=1080;
    if(w.x<-(WIN_W-240))w.x=-(WIN_W-240);if(w.x>sw-240)w.x=sw-240;if(w.y<0)w.y=0;if(w.y>sh-120)w.y=sh-120;*x=w.x;*y=w.y;return 1;}
static void save_fx_file(){FxDisk f;f.magic=0x3158464Au;f.enabled=g_fxEnabled;f.style=g_fxStyle;f.speed=g_fxSpeed;f.density=g_fxDensity;f.size=g_fxSize;f.brightness=g_fxBrightness;f.scope=g_fxScope;HANDLE h=CreateFileA(g_fxPath,GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return;DWORD wr=0;WriteFile(h,&f,sizeof(f),&wr,0);CloseHandle(h);}
static void load_fx_file(){FxDisk f;memset(&f,0,sizeof(f));HANDLE h=CreateFileA(g_fxPath,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return;DWORD rd=0;if(ReadFile(h,&f,sizeof(f),&rd,0)&&rd==sizeof(f)&&f.magic==0x3158464Au){g_fxEnabled=f.enabled?1:0;if(f.style>=0&&f.style<6)g_fxStyle=f.style;if(f.speed>=0&&f.speed<3)g_fxSpeed=f.speed;if(f.density>=0&&f.density<3)g_fxDensity=f.density;if(f.size>=0&&f.size<3)g_fxSize=f.size;if(f.brightness>=0&&f.brightness<3)g_fxBrightness=f.brightness;if(f.scope>=0&&f.scope<2)g_fxScope=f.scope;}CloseHandle(h);}
static void update_fx_status(){if(!g_fxStatus)return;char b[128]="FX: ";scat(b,g_fxEnabled?"ON  |  ":"OFF  |  ",128);scat(b,kFxNames[g_fxStyle],128);scat(b,"  |  ",128);scat(b,g_fxSpeed==0?"Slow":(g_fxSpeed==1?"Normal":"Fast"),128);SetWindowTextA(g_fxStatus,b);if(g_fxToggle)SetWindowTextA(g_fxToggle,g_fxEnabled?"FX ON":"FX OFF");}
static unsigned fx_hash(unsigned x){x^=x>>16;x*=0x7feb352du;x^=x>>15;x*=0x846ca68bu;x^=x>>16;return x;}
static HBRUSH fx_brush(){return g_fxBrightness==0?g_borderBrush:(g_fxBrightness==1?g_accentBrush:g_brightBrush);}
static DWORD fx_color(){return g_fxBrightness==0?C_BORDER:(g_fxBrightness==1?C_ACCENT:C_ACCENT_BRIGHT);}
static void fx_dot(HDC dc,int x,int y,int s,HBRUSH b){RECT q={x,y,x+s,y+s};FillRect(dc,&q,b);}
static void draw_fx(HDC dc,const RECT&client){
    if(!g_fxEnabled)return;
    // Background-only rendering. Never use the header, nav rail, footer or Ghost-art panel.
    // Child windows are clipped by WS_CLIPCHILDREN, so FX cannot paint over lists/buttons/edits.
    RECT a;
    if(g_fxScope==0){a.left=408;a.top=88;a.right=1088;a.bottom=client.bottom-48;} // content background only
    else{a.left=94;a.top=88;a.right=1088;a.bottom=client.bottom-48;} // entire editor background
    if(a.right<=a.left||a.bottom<=a.top)return;
    int w=a.right-a.left,h=a.bottom-a.top;
    HBRUSH br=fx_brush();
    int sz=g_fxSize+1;
    unsigned tick=g_fxTick;
    int sp=g_fxSpeed+1;
    if(g_fxStyle==0){
        int n=g_fxDensity==0?28:(g_fxDensity==1?52:84);
        for(int i=0;i<n;i++){
            unsigned q=fx_hash((unsigned)i*7919u+17u);
            int x=a.left+(int)(q%(unsigned)w);
            unsigned yy=((q>>8)%(unsigned)h)+(unsigned)((tick*sp*(1+(i%3)))/3);
            int y=a.top+(int)(yy%(unsigned)h);
            int tw=((tick/7+i)%5==0)?sz+1:sz;
            fx_dot(dc,x,y,tw,br);
        }
    }else if(g_fxStyle==1){
        int cols=g_fxDensity==0?8:(g_fxDensity==1?13:19);
        SetBkMode(dc,TRANSPARENT);SetTextColor(dc,fx_color());
        for(int i=0;i<cols;i++){
            unsigned q=fx_hash((unsigned)i*3571u+91u);
            unsigned xrange=(unsigned)(w>30?w-30:w);
            int x=a.left+(int)(q%xrange);
            unsigned seq=((q>>9)%(unsigned)(h+160))+(unsigned)(tick*sp*3);
            int base=(int)(seq%(unsigned)(h+160))-80;
            for(int j=0;j<5;j++){
                int y=a.top+base-j*18;
                if(y<a.top||y>a.bottom-16)continue;
                char c[2];c[0]=(char)('0'+((q+(unsigned)j+tick)%10));c[1]=0;
                RECT tr={x,y,x+16,y+16};
                DrawTextA(dc,c,1,&tr,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX);
            }
        }
    }else if(g_fxStyle==2){
        int n=g_fxDensity==0?32:(g_fxDensity==1?58:94);
        for(int i=0;i<n;i++){
            unsigned q=fx_hash((unsigned)i*1237u+311u);
            int x=a.left+(int)(q%(unsigned)w);
            unsigned yy=((q>>10)%(unsigned)h)+(unsigned)(tick*sp*(1+i%2));
            int y=a.top+(int)(yy%(unsigned)h);
            fx_dot(dc,x,y,sz,br);
        }
    }else if(g_fxStyle==3){
        int n=g_fxDensity==0?22:(g_fxDensity==1?42:70);
        for(int i=0;i<n;i++){
            unsigned q=fx_hash((unsigned)i*4441u+707u);
            int t=(int)(((unsigned)(tick*sp*(2+i%3))+(q&255u))%(unsigned)(w+h));
            int x=a.left+(t%w);
            int y=a.bottom-1-((t+(int)(q>>9))%h);
            fx_dot(dc,x,y,sz+(i%3==0),br);
        }
    }else if(g_fxStyle==4){
        int gap=g_fxDensity==0?42:(g_fxDensity==1?28:18);
        int off=(int)((tick*(unsigned)sp)%(unsigned)gap);
        for(int y=a.top+off;y<a.bottom;y+=gap){RECT ln={a.left,y,a.right,y+(g_fxSize==2?2:1)};FillRect(dc,&ln,br);}
    }else{
        int bands=g_fxDensity==0?3:(g_fxDensity==1?5:7);
        for(int i=0;i<bands;i++){
            unsigned q=fx_hash((unsigned)i*1171u+29u);
            int x=a.left+(int)(q%(unsigned)w);
            int y=a.top+(int)((q>>10)%(unsigned)h);
            int rad=8+(int)((tick*(unsigned)sp+(unsigned)i*17u)%36u);
            int t=g_fxSize+1;
            RECT top={x-rad,y-rad,x+rad,y-rad+t};RECT bot={x-rad,y+rad-t,x+rad,y+rad};RECT le={x-rad,y-rad,x-rad+t,y+rad};RECT ri={x+rad-t,y-rad,x+rad,y+rad};
            FillRect(dc,&top,br);FillRect(dc,&bot,br);FillRect(dc,&le,br);FillRect(dc,&ri,br);
        }
    }
}
static DWORD WINAPI FxThread(LPVOID){for(;;){if(!g_main)break;if(g_fxEnabled){g_fxTick++;RECT cr;GetClientRect(g_main,&cr);RECT fxr;if(g_fxScope==0){fxr.left=408;fxr.top=88;fxr.right=1088;fxr.bottom=cr.bottom-48;}else{fxr.left=94;fxr.top=88;fxr.right=1088;fxr.bottom=cr.bottom-48;}InvalidateRect(g_main,&fxr,FALSE);Sleep(g_fxSpeed==0?66:(g_fxSpeed==1?40:28));}else Sleep(200);}return 0;}

static void* find_asset_auto(int*cached,const char*name,void*known){if(!name||!*name)return 0;if(*cached>=0)return DBFind(*cached,name,0);if(known){const char* kname=asset_name(known);if(kname&&*kname){for(int t=0;t<64;t++){void* p=DBFind(t,kname,0);if(p==known){*cached=t;break;}}}}if(*cached>=0)return DBFind(*cached,name,0);return 0;}

static void snapshot_weapon(int i){
    if(i<0||i>=g_weaponCount)return; WeaponCompleteHead*w=g_weapons[i]; Snapshot&s=g_orig[i]; memset(&s,0,sizeof(s)); s.w=w; if(!w)return;
    if(readable_exec(w)){memcpy(s.completeBytes,w,0x128);s.valid=1;}
    if(w->anims)for(int a=0;a<124;a++)s.anims[a]=w->anims[a];
    if(w->def){BYTE*d=(BYTE*)w->def;if(readable_exec(d))memcpy(s.defBytes,d,0xA98);void**ga=*(void***)(d+0x08);void**wa=*(void***)(d+0x348);void**ra=*(void***)(d+0x40);void**la=*(void***)(d+0x48);if(ga)for(int a=0;a<64;a++)s.gun[a]=ga[a];if(wa)for(int a=0;a<64;a++)s.world[a]=wa[a];if(ra)for(int a=0;a<124;a++)s.animRight[a]=ra[a];if(la)for(int a=0;a<124;a++)s.animLeft[a]=la[a];}
    DWORD oc=*(DWORD*)((BYTE*)w+0x40);AnimOverrideEntryX*ov=*(AnimOverrideEntryX**)((BYTE*)w+0x48);if(oc>64)oc=64;s.animOverrideCount=oc;if(ov&&oc)for(DWORD a=0;a<oc;a++)s.animOverrides[a]=ov[a];
}

static int lowerch(int c){if(c>='A'&&c<='Z')return c+32;return c;}
static int contains_icase(const char*s,const char*q){if(!q||!*q)return 1;if(!s)return 0;for(int i=0;s[i];i++){int j=0;while(q[j]&&s[i+j]&&lowerch(s[i+j])==lowerch(q[j]))j++;if(!q[j])return 1;}return 0;}

static void** get_anim_array(WeaponCompleteHead*w,int source){
    if(!w)return 0;
    if(source==0)return w->anims;
    if(!w->def)return 0;
    BYTE*d=(BYTE*)w->def;
    if(source==1)return *(void***)(d+0x40);
    if(source==2)return *(void***)(d+0x48);
    return 0;
}
static DWORD get_anim_override_count(WeaponCompleteHead*w){if(!w)return 0;DWORD n=*(DWORD*)((BYTE*)w+0x40);if(n>256)n=256;return n;}
static AnimOverrideEntryX* get_anim_overrides(WeaponCompleteHead*w){if(!w)return 0;return *(AnimOverrideEntryX**)((BYTE*)w+0x48);}
static const char* source_name(int s){return s==0?"COMPLETE":(s==1?"RIGHT HAND":(s==2?"LEFT HAND":"ATTACHMENT OVERRIDES"));}
static void* resolved_anim(WeaponCompleteHead*w,int slot,int*sourceOut){
    if(sourceOut)*sourceOut=-1;if(!w||slot<0||slot>=124)return 0;
    int order[3];
    if(g_animSource==0){order[0]=0;order[1]=1;order[2]=2;}
    else if(g_animSource==1){order[0]=1;order[1]=0;order[2]=2;}
    else {order[0]=2;order[1]=0;order[2]=1;}
    for(int k=0;k<3;k++){int s=order[k];void**a=get_anim_array(w,s);if(a&&a[slot]){if(sourceOut)*sourceOut=s;return a[slot];}}
    return 0;
}
static const char* label_from_anim_name(const char*n){
    if(!n||!*n)return 0;
    if(contains_icase(n,"reload_empty_fast")||contains_icase(n,"reload_fast_empty"))return "FAST_RELOAD_EMPTY";
    if(contains_icase(n,"reload_start_fast"))return "FAST_RELOAD_START";
    if(contains_icase(n,"reload_end_fast"))return "FAST_RELOAD_END";
    if(contains_icase(n,"reload_fast"))return "FAST_RELOAD";
    if(contains_icase(n,"reload_empty"))return "RELOAD_EMPTY";
    if(contains_icase(n,"reload_start"))return "RELOAD_START";
    if(contains_icase(n,"reload_end"))return "RELOAD_END";
    if(contains_icase(n,"reload"))return "RELOAD";
    if(contains_icase(n,"pullout_empty")||contains_icase(n,"empty_pullout"))return "EMPTY_RAISE";
    if(contains_icase(n,"putaway_empty")||contains_icase(n,"empty_putaway"))return "EMPTY_DROP";
    if(contains_icase(n,"pullout_first")||contains_icase(n,"first_pullout"))return "FIRST_RAISE";
    if(contains_icase(n,"pullout_fast")||contains_icase(n,"fast_pullout"))return "QUICK_RAISE";
    if(contains_icase(n,"putaway_fast")||contains_icase(n,"fast_putaway"))return "QUICK_DROP";
    if(contains_icase(n,"breach")&&contains_icase(n,"pullout"))return "BREACH_RAISE";
    if(contains_icase(n,"pullout"))return "RAISE";
    if(contains_icase(n,"putaway"))return "DROP";
    if(contains_icase(n,"rechamber"))return "RECHAMBER";
    if(contains_icase(n,"sprint_in"))return "SPRINT_IN";
    if(contains_icase(n,"sprint_out"))return "SPRINT_OUT";
    if(contains_icase(n,"sprint_loop")||contains_icase(n,"sprint"))return "SPRINT_LOOP";
    if(contains_icase(n,"slide_in"))return "SLIDE_IN";
    if(contains_icase(n,"slide_out"))return "SLIDE_OUT";
    if(contains_icase(n,"slide_loop")||contains_icase(n,"slide"))return "SLIDE_LOOP";
    if(contains_icase(n,"mantle"))return "MANTLE";
    if(contains_icase(n,"inspect"))return "INSPECTION";
    if(contains_icase(n,"nightvision")||contains_icase(n,"nvg"))return "NIGHTVISION";
    if(contains_icase(n,"stun"))return "STUNNED";
    if(contains_icase(n,"melee"))return "MELEE";
    if(contains_icase(n,"grenade")&&contains_icase(n,"prime"))return "GRENADE_PRIME";
    if(contains_icase(n,"detonate"))return "DETONATE";
    if(contains_icase(n,"idle_empty")||contains_icase(n,"empty_idle"))return "EMPTY_IDLE";
    if(contains_icase(n,"idle"))return "IDLE";
    if(contains_icase(n,"lastshot")||contains_icase(n,"last_shot"))return "LASTSHOT";
    if(contains_icase(n,"ads")&&contains_icase(n,"fire"))return "ADS_FIRE";
    if(contains_icase(n,"fire"))return "FIRE";
    if(contains_icase(n,"raise"))return "RAISE";
    if(contains_icase(n,"drop"))return "DROP";
    return 0;
}
static const char* infer_anim_label(int slot,const char*n){
    const char*byName=label_from_anim_name(n);if(byName)return byName;
    if(slot>=0&&slot<124)return kAnimLabels[slot];
    return "UNKNOWN";
}
static const char* clean_anim_label(int slot,const char*n){
    // IW6 weapon files are not consistent enough for a single hard-coded slot
    // table to be the only authority. Prefer the loaded XAnim name when it
    // clearly identifies the action (pullout, putaway, reload, sprint, etc.).
    // Fall back to the raw slot label only when the asset name is generic.
    const char*byName=label_from_anim_name(n);if(byName)return byName;
    if(slot>=0&&slot<124){
        const char*c=kAnimLabels[slot];
        if(c&&c[0]&&!(c[0]=='S'&&c[1]=='L'&&c[2]=='O'&&c[3]=='T'&&c[4]=='_'))return c;
    }
    return "UNKNOWN";
}
static int core_label_match(const char*l){
    if(!l)return 0;
    return seq(l,"IDLE")||seq(l,"EMPTY_IDLE")||seq(l,"FIRE")||seq(l,"LASTSHOT")||
           seq(l,"RECHAMBER")||seq(l,"MELEE")||seq(l,"MELEE_SWIPE")||
           seq(l,"RELOAD")||seq(l,"RELOAD_EMPTY")||seq(l,"RELOAD_START")||seq(l,"RELOAD_END")||
           seq(l,"RAISE")||seq(l,"FIRST_RAISE")||seq(l,"DROP")||
           seq(l,"QUICK_RAISE")||seq(l,"QUICK_DROP")||seq(l,"EMPTY_RAISE")||seq(l,"EMPTY_DROP")||
           seq(l,"SPRINT_IN")||seq(l,"SPRINT_LOOP")||seq(l,"SPRINT_OUT")||
           seq(l,"ADS_FIRE")||seq(l,"ADS_LASTSHOT")||seq(l,"ADS_RECHAMBER")||seq(l,"INSPECTION");
}
static int anim_filter_match(int slot,const char*l,void*resolved){
    (void)slot;
    // ALL is the raw editor. Every other view stays clean and only shows
    // animations that actually exist for the currently selected source.
    if(g_animFilter==5)return 1;
    if(!resolved)return 0;
    if(g_animFilter==1)return 1;
    if(g_animFilter==0)return core_label_match(l);
    if(g_animFilter==2)return contains_icase(l,"RELOAD")||contains_icase(l,"RECHAMBER");
    if(g_animFilter==3)return contains_icase(l,"RAISE")||contains_icase(l,"DROP")||contains_icase(l,"SPRINT")||contains_icase(l,"MANTLE")||contains_icase(l,"SLIDE");
    if(g_animFilter==4)return contains_icase(l,"FIRE")||contains_icase(l,"ADS")||contains_icase(l,"MELEE")||contains_icase(l,"STUN")||contains_icase(l,"NIGHT")||contains_icase(l,"INSPECTION");
    return 1;
}
static int label_seen(const char*label,const char**seen,int count){for(int i=0;i<count;i++)if(seq(label,seen[i]))return 1;return 0;}
static const char* source_short(int s){return s==0?"B":(s==1?"R":(s==2?"L":"O"));}

static void rebuild_weapon_list();
static const char* kStreakCandidates[]={
    "killstreak_heli_pilot_mp","killstreak_heli_gunner_mp","killstreak_remote_tank_mp","remote_tank_projectile_mp",
    "killstreak_uplink_mp","killstreak_loki_mp","killstreak_odin_mp","airdrop_marker_mp","airdrop_sentry_marker_mp",
    "a10_30mm_mp","maverick_mp","maverick_projectile_mp","odin_projectile_large_rod_mp","odin_projectile_small_rod_mp",
    "gas_strike_mp","ball_drone_gun_mp","drone_hive_projectile_mp","switch_blade_child_mp","artillery_mp",
    "cobra_player_minigun_mp","sentry_minigun_mp","juggernaut_mp","iw6_maaws_mp"
};
static int weapon_exists(WeaponCompleteHead*w){if(!w)return 1;for(int i=0;i<g_weaponCount;i++)if(g_weapons[i]==w)return 1;return 0;}
static int append_weapon_asset(WeaponCompleteHead*w){if(!w||g_weaponCount>=512||weapon_exists(w))return 0;if(!readable_exec(w)||!w->name)return 0;g_weapons[g_weaponCount]=w;snapshot_weapon(g_weaponCount);g_weaponCount++;return 1;}
static int discover_streak_assets(){int added=0;for(unsigned i=0;i<sizeof(kStreakCandidates)/sizeof(kStreakCandidates[0]);i++){WeaponCompleteHead*w=(WeaponCompleteHead*)DBFind(0x23,kStreakCandidates[i],0);if(w)added+=append_weapon_asset(w);}return added;}
static void find_add_weapon(){char name[160];get_text(g_search,name,160);if(!name[0]){status("Type an internal weapon/killstreak asset name in Search first.");return;}WeaponCompleteHead*w=(WeaponCompleteHead*)DBFind(0x23,name,0);if(!w){status("That weapon asset is not loaded in the current IW6 zone/map.");return;}int added=append_weapon_asset(w);rebuild_weapon_list();if(added){status("Loaded weapon/killstreak asset added to the editor.");}else status("Weapon asset was already in the editor.");}

static void rebuild_weapon_list(){
    char filter[128];filter[0]=0;if(g_search)GetWindowTextA(g_search,filter,127);list_begin(g_weaponList);SendMessageA(g_weaponList,LB_RESETCONTENT,0,0);g_visibleWeaponCount=0;
    for(int i=0;i<g_weaponCount;i++){const char*n=(g_weapons[i]&&g_weapons[i]->name)?g_weapons[i]->name:"<unnamed weapon>";if(!contains_icase(n,filter))continue;g_visibleWeapons[g_visibleWeaponCount++]=i;SendMessageA(g_weaponList,LB_ADDSTRING,0,(LPARAM)n);}
    if(g_visibleWeaponCount){SendMessageA(g_weaponList,LB_SETCURSEL,0,0);g_sel=g_visibleWeapons[0];}else g_sel=-1;list_end(g_weaponList);
}

static void refresh_pool(){
    if(!readable_exec((void*)0x14031FC00ull)){status("IW6 game module is not ready yet.");return;}
    memset(g_weapons,0,sizeof(g_weapons));int n=DBGetAll(0x23,(void**)g_weapons,512);if(n<0)n=0;if(n>512)n=512;g_weaponCount=n;
    for(int i=0;i<n;i++)snapshot_weapon(i);
    int streaks=discover_streak_assets();
    rebuild_weapon_list();
    char b[128]="Loaded ";char num[24];uint_to_str((unsigned)g_weaponCount,num);scat(b,num,128);scat(b," weapons",128);(void)streaks;status(b);
    if(g_countLabel){char c[64]={0};scat(c,num,64);scat(c," weapons",64);SetWindowTextA(g_countLabel,c);}
}


static void update_anim_override_visibility(){int show=(g_animSource==3);for(int i=0;i<g_anOverrideOnlyN;i++)ShowWindow(g_anOverrideOnly[i],show?SW_SHOW:0);}
static void set_anim_override_field(HWND h,int v){char b[32];int_to_str(v,b);SetWindowTextA(h,b);}
static void anim_selection_changed(){
    if(g_sel<0||g_sel>=g_weaponCount)return;WeaponCompleteHead*w=g_weapons[g_sel];int ls=(int)SendMessageA(anList,LB_GETCURSEL,0,0);if(ls<0||ls>=g_visibleAnimCount)return;int s=g_visibleAnimSlots[ls];
    if(g_animSource==3){DWORD n=get_anim_override_count(w);AnimOverrideEntryX*ov=get_anim_overrides(w);if(!ov||(DWORD)s>=n)return;AnimOverrideEntryX&e=ov[s];SetWindowTextA(anEdit,asset_name(e.overrideAnim));SetWindowTextA(anAltEdit,asset_name(e.altmodeAnim));set_anim_override_field(anTypeEdit,(int)e.animTreeType);set_anim_override_field(anTimeEdit,e.animTime);set_anim_override_field(anAltTimeEdit,e.altTime);set_anim_override_field(anAttach1Edit,(int)e.attachment1);set_anim_override_field(anAttach2Edit,(int)e.attachment2);return;}
    if(s>=124)return;void**a=get_anim_array(w,g_animSource);void*p=(a?a[s]:0);SetWindowTextA(anEdit,asset_name(p));
}
static void refresh_anims(){
    if(!anList)return;list_begin(anList);SendMessageA(anList,LB_RESETCONTENT,0,0);g_visibleAnimCount=0;if(anSourceInfo)SetWindowTextA(anSourceInfo,source_name(g_animSource));update_anim_override_visibility();
    if(g_sel<0||g_sel>=g_weaponCount){list_end(anList);return;}WeaponCompleteHead*w=g_weapons[g_sel];if(!w){list_end(anList);return;}
    if(g_animSource==3){
        DWORD n=get_anim_override_count(w);AnimOverrideEntryX*ov=get_anim_overrides(w);if(!ov||!n){SendMessageA(anList,LB_ADDSTRING,0,(LPARAM)"No attachment animation overrides");SetWindowTextA(anEdit,"");list_end(anList);return;}
        for(DWORD i=0;i<n&&g_visibleAnimCount<256;i++){
            void* resolved=ov[i].overrideAnim?ov[i].overrideAnim:ov[i].altmodeAnim;
            const char*nm=asset_name(resolved);
            const char*label=(ov[i].animTreeType<124)?clean_anim_label((int)ov[i].animTreeType,nm):"OVERRIDE";
            if(!anim_filter_match((int)ov[i].animTreeType,label,resolved))continue;
            char b[300],num[20],x[24];b[0]=0;if(i<10)scat(b,"00",300);else if(i<100)scat(b,"0",300);uint_to_str(i,num);scat(b,num,300);scat(b,"  ",300);
            if(ov[i].animTreeType<124)scat(b,label,300);else{scat(b,"TYPE ",300);uint_to_str(ov[i].animTreeType,x);scat(b,x,300);}SIZE_T ln=slen(b);while(ln<28&&ln+1<300){b[ln++]=' ';b[ln]=0;}
            const char*mainName=asset_name(ov[i].overrideAnim);const char*altName=asset_name(ov[i].altmodeAnim);
            if(mainName&&*mainName)scat(b,mainName,300);else if(altName&&*altName){scat(b,"ALT> ",300);scat(b,altName,300);}else scat(b,"[empty]",300);
            g_visibleAnimSlots[g_visibleAnimCount++]=(int)i;SendMessageA(anList,LB_ADDSTRING,0,(LPARAM)b);
        }
        if(g_visibleAnimCount)SendMessageA(anList,LB_SETCURSEL,0,0);list_end(anList);anim_selection_changed();return;
    }
    void**a=get_anim_array(w,g_animSource);if(!a){SendMessageA(anList,LB_ADDSTRING,0,(LPARAM)"Animation array unavailable");SetWindowTextA(anEdit,"");list_end(anList);return;}
    const char*seenCore[64]={0};int seenCoreN=0;
    for(int i=0;i<124&&g_visibleAnimCount<256;i++){
        void*cur=a[i];const char*cn=asset_name(cur);const char*label=clean_anim_label(i,cn);if(!anim_filter_match(i,label,cur))continue;
        // CORE is semantic, not slot-number based. If two raw IW6 slots point
        // to the same action (for example the same normal FIRE), show it once.
        // Distinct actions such as EMPTY_IDLE, LASTSHOT and FIRST_RAISE remain.
        if(g_animFilter==0){if(label_seen(label,seenCore,seenCoreN))continue;if(seenCoreN<64)seenCore[seenCoreN++]=label;}
        char b[320],num[16];b[0]=0;if(i<10)scat(b,"00",320);else if(i<100)scat(b,"0",320);uint_to_str((unsigned)i,num);scat(b,num,320);scat(b,"  ",320);scat(b,label,320);SIZE_T ln=slen(b);while(ln<30&&ln+1<320){b[ln++]=' ';b[ln]=0;}
        if(cn&&*cn)scat(b,cn,320);else scat(b,"[empty]",320);
        g_visibleAnimSlots[g_visibleAnimCount++]=i;SendMessageA(anList,LB_ADDSTRING,0,(LPARAM)b);
    }
    if(g_visibleAnimCount){SendMessageA(anList,LB_SETCURSEL,0,0);}else SendMessageA(anList,LB_ADDSTRING,0,(LPARAM)"No animations in this view");list_end(anList);if(g_visibleAnimCount)anim_selection_changed();else SetWindowTextA(anEdit,"");
}

static void field_to_text(const FieldDesc&f,char*out,int cap){out[0]=0;if(g_sel<0||g_sel>=g_weaponCount)return;WeaponCompleteHead*w=g_weapons[g_sel];BYTE*base=(f.base==FB_COMPLETE)?(BYTE*)w:(BYTE*)w->def;if(!base)return;BYTE*p=base+f.offset;if(f.kind==FK_INT){int v=*(int*)p;int_to_str(v,out);}else if(f.kind==FK_FLOAT){float v=*(float*)p;float_to_str(v,out);}else if(f.kind==FK_BOOL){out[0]=(*(BYTE*)p)?'1':'0';out[1]=0;}else if(f.kind==FK_MODEL_DIRECT){void*m=*(void**)p;scopy(out,asset_name(m),cap);if(!out[0])scopy(out,"<none>",cap);}else if(f.kind==FK_MODEL_ARRAY){void**a=*(void***)p;void*m=a?a[f.arrayIndex]:0;scopy(out,asset_name(m),cap);if(!out[0])scopy(out,"<none>",cap);}}
static void refresh_wp_fields(){if(!wpFieldList)return;list_begin(wpFieldList);SendMessageA(wpFieldList,LB_RESETCONTENT,0,0);g_visibleFieldCount=0;if(g_sel<0){list_end(wpFieldList);return;}for(int i=0;i<kFieldCount;i++){const FieldDesc&f=kFields[i];if(f.category!=g_wpCat)continue;char value[128],row[240];field_to_text(f,value,128);row[0]=0;scat(row,f.name,240);SIZE_T n=slen(row);while(n<32&&n+1<240){row[n++]=' ';row[n]=0;}scat(row,value,240);g_visibleFields[g_visibleFieldCount++]=i;SendMessageA(wpFieldList,LB_ADDSTRING,0,(LPARAM)row);}if(g_visibleFieldCount){SendMessageA(wpFieldList,LB_SETCURSEL,0,0);char v[128];field_to_text(kFields[g_visibleFields[0]],v,128);SetWindowTextA(wpValueEdit,v);}else SetWindowTextA(wpValueEdit,"");list_end(wpFieldList);}
static void wp_field_changed(){int s=(int)SendMessageA(wpFieldList,LB_GETCURSEL,0,0);if(s<0||s>=g_visibleFieldCount)return;char v[128];field_to_text(kFields[g_visibleFields[s]],v,128);SetWindowTextA(wpValueEdit,v);}
static void apply_wp_field(){int s=(int)SendMessageA(wpFieldList,LB_GETCURSEL,0,0);if(s<0||s>=g_visibleFieldCount||g_sel<0)return;const FieldDesc&f=kFields[g_visibleFields[s]];WeaponCompleteHead*w=g_weapons[g_sel];BYTE*base=(f.base==FB_COMPLETE)?(BYTE*)w:(BYTE*)w->def;if(!base)return;char in[160];get_text(wpValueEdit,in,160);int ok=0;if(f.kind==FK_INT){int v=parse_int(in);ok=patch_value(base+f.offset,v);}else if(f.kind==FK_FLOAT){float v=parse_float(in);ok=patch_value(base+f.offset,v);}else if(f.kind==FK_BOOL){BYTE v=(parse_int(in)!=0)?1:0;ok=patch_bytes(base+f.offset,&v,1);}else if(f.kind==FK_MODEL_DIRECT){void*m=0;if(in[0]&&!(in[0]=='<'||seq(in,"none")||seq(in,"null")))m=DBFind(4,in,0);if(!in[0]||in[0]=='<'||seq(in,"none")||seq(in,"null")||m)ok=patch_value(base+f.offset,m);}else if(f.kind==FK_MODEL_ARRAY){void**a=*(void***)(base+f.offset);void*m=0;if(in[0]&&!(in[0]=='<'||seq(in,"none")||seq(in,"null")))m=DBFind(4,in,0);if(a&&(!in[0]||in[0]=='<'||seq(in,"none")||seq(in,"null")||m))ok=patch_value(&a[f.arrayIndex],m);}status(ok?"WeaponDef value applied live.":"Value/model could not be written or asset was not loaded.");refresh_wp_fields();if(s<g_visibleFieldCount){SendMessageA(wpFieldList,LB_SETCURSEL,s,0);wp_field_changed();}}

static void refresh_wp(){refresh_wp_fields();}

static void weapon_changed(){int ls=(int)SendMessageA(g_weaponList,LB_GETCURSEL,0,0);if(ls>=0&&ls<g_visibleWeaponCount){g_sel=g_visibleWeapons[ls];if(g_weaponTitle){const char*n=(g_weapons[g_sel]&&g_weapons[g_sel]->name)?g_weapons[g_sel]->name:"<weapon>";SetWindowTextA(g_weaponTitle,n);}if(g_activeTab==0)refresh_wp();else if(g_activeTab==1)refresh_anims();}}
static void apply_values(){if(g_sel<0)return;WeaponCompleteHead*w=g_weapons[g_sel];BYTE*c=(BYTE*)w;float f=get_float_edit(wpAds);int adsin=get_int_edit(wpAdsIn),adsout=get_int_edit(wpAdsOut),clip=get_int_edit(wpClip),fire=get_int_edit(wpFire),fa=get_int_edit(wpFireAnim),fr=get_int_edit(wpFirstRaise);int ok=1;ok&=patch_value(c+0x90,f);ok&=patch_value(c+0x94,adsin);ok&=patch_value(c+0x98,adsout);ok&=patch_value(c+0x9C,clip);ok&=patch_value(c+0xA4,fire);ok&=patch_value(c+0xE8,fa);ok&=patch_value(c+0xF0,fr);status(ok?"IW6 weapon values applied live.":"One or more IW6 fields could not be written.");}
static void apply_models(){if(g_sel<0)return;WeaponCompleteHead*w=g_weapons[g_sel];if(!w||!w->def)return;BYTE*d=(BYTE*)w->def;void**ga=*(void***)(d+0x08);char a[128],b[128],h[128];get_text(wpGun0,a,128);get_text(wpGun1,b,128);get_text(wpHand,h,128);void* known=(ga&&ga[0])?ga[0]:(ga?ga[1]:0);void*p0=*a?find_asset_auto(&g_modelType,a,known):0;void*p1=*b?find_asset_auto(&g_modelType,b,known):0;void*ph=*h?find_asset_auto(&g_modelType,h,known):0;int ok=1;if(*a){if(!p0)ok=0;else ok&=patch_value(&ga[0],p0);}if(*b){if(!p1)ok=0;else ok&=patch_value(&ga[1],p1);}if(*h){if(!ph)ok=0;else ok&=patch_value(d+0x10,ph);}status(ok?"IW6 XModel changes applied.":"Model not found in the loaded IW6 asset pool.");}
static int visible_anim_index_for_slot(int slot){for(int i=0;i<g_visibleAnimCount;i++)if(g_visibleAnimSlots[i]==slot)return i;return -1;}
static int name_is_variant_of(const char*base,const char*n);
static void push_anim_slot_one(WeaponCompleteHead*v,int slot,void*x){if(!v||slot<0||slot>=124||!x)return;if(v->anims)patch_value(&v->anims[slot],x);void**ra=get_anim_array(v,1);void**la=get_anim_array(v,2);if(ra&&ra[slot])patch_value(&ra[slot],x);if(la&&la[slot])patch_value(&la[slot],x);AnimOverrideEntryX*ov=get_anim_overrides(v);DWORD on=get_anim_override_count(v);if(ov)for(DWORD k=0;k<on&&k<256;k++)if(ov[k].animTreeType==(DWORD)slot&&ov[k].overrideAnim)patch_value(&ov[k].overrideAnim,x);}
static void push_anim_slot_everywhere(WeaponCompleteHead*w,int slot,void*x){push_anim_slot_one(w,slot,x);for(int k=0;k<g_weaponCount;k++){WeaponCompleteHead*v=g_weapons[k];if(!v||v==w)continue;if(name_is_variant_of(w->name,v->name))push_anim_slot_one(v,slot,x);}}
static void apply_anim(){
    if(g_sel<0)return;int ls=(int)SendMessageA(anList,LB_GETCURSEL,0,0);if(ls<0||ls>=g_visibleAnimCount)return;int slot=g_visibleAnimSlots[ls];WeaponCompleteHead*w=g_weapons[g_sel];
    if(g_animSource==3){DWORD n=get_anim_override_count(w);AnimOverrideEntryX*ov=get_anim_overrides(w);if(!ov||(DWORD)slot>=n){status("No override entry selected.");return;}AnimOverrideEntryX&e=ov[slot];char a[160],alt[160],tmp[64];get_text(anEdit,a,160);get_text(anAltEdit,alt,160);void*pa=0;void*pb=0;if(a[0]&&a[0]!='<')pa=DBFind(2,a,0);if(alt[0]&&alt[0]!='<')pb=DBFind(2,alt,0);int ok=1;if(!a[0]||a[0]=='<'||pa)ok&=patch_value(&e.overrideAnim,pa);else ok=0;if(!alt[0]||alt[0]=='<'||pb)ok&=patch_value(&e.altmodeAnim,pb);else ok=0;get_text(anTypeEdit,tmp,64);DWORD typ=(DWORD)parse_int(tmp);get_text(anTimeEdit,tmp,64);int tm=parse_int(tmp);get_text(anAltTimeEdit,tmp,64);int atm=parse_int(tmp);get_text(anAttach1Edit,tmp,64);WORD at1=(WORD)parse_int(tmp);get_text(anAttach2Edit,tmp,64);WORD at2=(WORD)parse_int(tmp);ok&=patch_value(&e.animTreeType,typ);ok&=patch_value(&e.animTime,tm);ok&=patch_value(&e.altTime,atm);ok&=patch_value(&e.attachment1,at1);ok&=patch_value(&e.attachment2,at2);status(ok?"Attachment animation override updated live.":"One or more override values could not be applied.");refresh_anims();{int vi=visible_anim_index_for_slot(slot);if(vi>=0)SendMessageA(anList,LB_SETCURSEL,vi,0);}anim_selection_changed();return;}
    if(slot>=124)return;void**arr=get_anim_array(w,g_animSource);if(!arr){status("This animation array is unavailable for the selected weapon.");return;}char n[160];get_text(anEdit,n,160);void*p=0;if(n[0]&&n[0]!='<')p=DBFind(2,n,0);if(n[0]&&n[0]!='<'&&!p){status("XAnim not found in the loaded IW6 asset pool.");return;}if(patch_value(&arr[slot],p)){if(p)push_anim_slot_everywhere(w,slot,p);status("Animation applied to the selected weapon and all its attachment versions.");refresh_anims();{int vi=visible_anim_index_for_slot(slot);if(vi>=0)SendMessageA(anList,LB_SETCURSEL,vi,0);}anim_selection_changed();}else status("Animation pointer could not be written.");
}
static void restore_all_anims(){
    if(g_sel<0)return;Snapshot&s=g_orig[g_sel];WeaponCompleteHead*w=g_weapons[g_sel];if(s.w!=w||!s.valid)return;void**base=get_anim_array(w,0);void**right=get_anim_array(w,1);void**left=get_anim_array(w,2);if(base)for(int i=0;i<124;i++)patch_value(&base[i],s.anims[i]);if(right)for(int i=0;i<124;i++)patch_value(&right[i],s.animRight[i]);if(left)for(int i=0;i<124;i++)patch_value(&left[i],s.animLeft[i]);AnimOverrideEntryX*ov=get_anim_overrides(w);DWORD n=get_anim_override_count(w);DWORD r=s.animOverrideCount<n?s.animOverrideCount:n;if(ov)for(DWORD i=0;i<r;i++)patch_bytes(&ov[i],&s.animOverrides[i],sizeof(AnimOverrideEntryX));refresh_anims();status("All Complete/Right/Left/Override animation data restored.");
}
static void restore_selected(){if(g_sel<0)return;Snapshot&s=g_orig[g_sel];WeaponCompleteHead*w=g_weapons[g_sel];if(s.w!=w||!s.valid){status("Original snapshot does not match this weapon. Refresh Pool first.");return;}patch_bytes(w,s.completeBytes,0x128);if(w->def){BYTE*d=(BYTE*)w->def;patch_bytes(d,s.defBytes,0xA98);void**ga=*(void***)(d+0x08);void**wa=*(void***)(d+0x348);void**ra=*(void***)(d+0x40);void**la=*(void***)(d+0x48);if(ga)for(int i=0;i<64;i++)patch_value(&ga[i],s.gun[i]);if(wa)for(int i=0;i<64;i++)patch_value(&wa[i],s.world[i]);if(ra)for(int i=0;i<124;i++)patch_value(&ra[i],s.animRight[i]);if(la)for(int i=0;i<124;i++)patch_value(&la[i],s.animLeft[i]);}if(w->anims)for(int i=0;i<124;i++)patch_value(&w->anims[i],s.anims[i]);AnimOverrideEntryX*ov=get_anim_overrides(w);DWORD on=get_anim_override_count(w);DWORD rn=s.animOverrideCount<on?s.animOverrideCount:on;if(ov)for(DWORD i=0;i<rn;i++)patch_bytes(&ov[i],&s.animOverrides[i],sizeof(AnimOverrideEntryX));refresh_wp();refresh_anims();status("Reset selected weapon, all animation sources and mapped WeaponDef data to the refresh snapshot.");}


static void save_presets_file(){HANDLE h=CreateFileA(g_savePath,GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return;DWORD wr=0;DWORD hdr[2]={0x36504E4Au,(DWORD)g_presetCount};WriteFile(h,hdr,sizeof(hdr),&wr,0);if(g_presetCount)WriteFile(h,g_presets,(DWORD)(sizeof(Preset)*g_presetCount),&wr,0);CloseHandle(h);}
static void load_presets_file(){g_presetCount=0;HANDLE h=CreateFileA(g_savePath,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return;DWORD hdr[2]={0},rd=0;if(!ReadFile(h,hdr,sizeof(hdr),&rd,0)||rd!=sizeof(hdr)||hdr[0]!=0x36504E4Au){CloseHandle(h);return;}int n=(int)hdr[1];if(n<0)n=0;if(n>16)n=16;DWORD want=(DWORD)(sizeof(Preset)*n);if(n&&(!ReadFile(h,g_presets,want,&rd,0)||rd!=want))n=0;g_presetCount=n;CloseHandle(h);}
static void refresh_preset_list(){if(!svList)return;list_begin(svList);SendMessageA(svList,LB_RESETCONTENT,0,0);for(int i=0;i<g_presetCount;i++)SendMessageA(svList,LB_ADDSTRING,0,(LPARAM)g_presets[i].name);if(g_presetCount)SendMessageA(svList,LB_SETCURSEL,0,0);list_end(svList);}
static void save_current(){if(g_sel<0)return;if(g_presetCount>=16){status("SAVED is full (16). Delete one preset first.");return;}Preset&p=g_presets[g_presetCount];memset(&p,0,sizeof(p));p.magic=0x3656534Au;get_text(svName,p.name,48);if(!p.name[0])scopy(p.name,"IW6 Setup",48);WeaponCompleteHead*w=g_weapons[g_sel];scopy(p.sourceWeapon,w->name,80);if(w->anims)for(int i=0;i<124;i++)scopy(p.anim[i],asset_name(w->anims[i]),80);if(w->def){BYTE*d=(BYTE*)w->def;void**ga=*(void***)(d+0x08);scopy(p.gun0,asset_name(ga?ga[0]:0),96);scopy(p.gun1,asset_name(ga?ga[1]:0),96);scopy(p.hand,asset_name(*(void**)(d+0x10)),96);}BYTE*c=(BYTE*)w;p.adsFov=*(float*)(c+0x90);p.adsIn=*(int*)(c+0x94);p.adsOut=*(int*)(c+0x98);p.clip=*(int*)(c+0x9C);p.fire=*(int*)(c+0xA4);p.fireAk=*(int*)(c+0xA8);p.fireAnim=*(int*)(c+0xE8);p.fireAnimAk=*(int*)(c+0xEC);p.firstRaise=*(int*)(c+0xF0);p.firstRaiseAk=*(int*)(c+0xF4);g_presetCount++;save_presets_file();refresh_preset_list();status("Saved IW6 setup. It will persist across injections.");}
static void apply_preset_core(Preset&p,WeaponCompleteHead*w){if(!w)return;void*knownAnim=0;if(w->anims)for(int i=0;i<124&&!knownAnim;i++)knownAnim=w->anims[i];if(w->anims)for(int i=0;i<124;i++)if(p.anim[i][0]){void*x=find_asset_auto(&g_animType,p.anim[i],knownAnim);if(x)patch_value(&w->anims[i],x);}if(w->def){BYTE*d=(BYTE*)w->def;void**ga=*(void***)(d+0x08);void*knownModel=(ga&&ga[0])?ga[0]:(ga?ga[1]:0);if(ga&&p.gun0[0]){void*x=find_asset_auto(&g_modelType,p.gun0,knownModel);if(x)patch_value(&ga[0],x);}if(ga&&p.gun1[0]){void*x=find_asset_auto(&g_modelType,p.gun1,knownModel);if(x)patch_value(&ga[1],x);}if(p.hand[0]){void*x=find_asset_auto(&g_modelType,p.hand,knownModel);if(x)patch_value(d+0x10,x);}}BYTE*c=(BYTE*)w;patch_value(c+0x90,p.adsFov);patch_value(c+0x94,p.adsIn);patch_value(c+0x98,p.adsOut);patch_value(c+0x9C,p.clip);patch_value(c+0xA4,p.fire);patch_value(c+0xA8,p.fireAk);patch_value(c+0xE8,p.fireAnim);patch_value(c+0xEC,p.fireAnimAk);patch_value(c+0xF0,p.firstRaise);patch_value(c+0xF4,p.firstRaiseAk);}

static int name_is_variant_of(const char*base,const char*n){if(!base||!n)return 0;int i=0;while(base[i]){if(n[i]!=base[i])return 0;i++;}return n[i]=='_'&&n[i+1]!=0;}
// Also push each preset animation into the per-hand arrays and the attachment override entries of one weapon.
static void apply_preset_extras(Preset&p,WeaponCompleteHead*w){
    if(!w)return;void*knownAnim=0;if(w->anims)for(int i=0;i<124&&!knownAnim;i++)knownAnim=w->anims[i];
    void**ra=get_anim_array(w,1);void**la=get_anim_array(w,2);AnimOverrideEntryX*ov=get_anim_overrides(w);DWORD on=get_anim_override_count(w);
    for(int i=0;i<124;i++){if(!p.anim[i][0])continue;void*x=find_asset_auto(&g_animType,p.anim[i],knownAnim);if(!x)continue;
        if(ra&&ra[i])patch_value(&ra[i],x);if(la&&la[i])patch_value(&la[i],x);
        if(ov)for(DWORD k=0;k<on&&k<256;k++)if(ov[k].animTreeType==(DWORD)i&&ov[k].overrideAnim)patch_value(&ov[k].overrideAnim,x);}
}
// Apply to the weapon and to every attachment version of it (names like <weapon>_acog, <weapon>_silencer_...).
static void apply_preset_to_weapon(Preset&p,WeaponCompleteHead*w){
    if(!w)return;apply_preset_core(p,w);apply_preset_extras(p,w);
    for(int k=0;k<g_weaponCount;k++){WeaponCompleteHead*v=g_weapons[k];if(!v||v==w)continue;if(name_is_variant_of(w->name,v->name)){apply_preset_core(p,v);apply_preset_extras(p,v);}}
}static void apply_saved(){int s=(int)SendMessageA(svList,LB_GETCURSEL,0,0);if(s<0||s>=g_presetCount||g_sel<0){status("Select a saved setup and weapon first.");return;}apply_preset_to_weapon(g_presets[s],g_weapons[g_sel]);refresh_wp();refresh_anims();status("SAVED setup applied to selected IW6 weapon.");}
static void delete_saved(){int s=(int)SendMessageA(svList,LB_GETCURSEL,0,0);if(s<0||s>=g_presetCount)return;for(int i=s;i+1<g_presetCount;i++)g_presets[i]=g_presets[i+1];g_presetCount--;save_presets_file();refresh_preset_list();status("Saved setup deleted.");}
static void batch_apply_saved(){int s=(int)SendMessageA(svList,LB_GETCURSEL,0,0);if(s<0||s>=g_presetCount)return;for(int i=0;i<g_weaponCount;i++)apply_preset_to_weapon(g_presets[s],g_weapons[i]);status("SAVED setup batch-applied to all loaded IW6 weapons.");}

static void batch_capture_field(BatchWeaponEntry&b,int i,WeaponCompleteHead*w){
    const FieldDesc&f=kFields[i];BatchFieldValue&v=b.field[i];memset(&v,0,sizeof(v));BYTE*base=(f.base==FB_COMPLETE)?(BYTE*)w:(BYTE*)w->def;if(!base)return;BYTE*p=base+f.offset;
    if(f.kind==FK_INT){int x=*(int*)p;memcpy(&v.bits,&x,sizeof(x));}
    else if(f.kind==FK_FLOAT){float x=*(float*)p;memcpy(&v.bits,&x,sizeof(x));}
    else if(f.kind==FK_BOOL){v.bits=*(BYTE*)p?1:0;}
    else if(f.kind==FK_MODEL_DIRECT){scopy(v.asset,asset_name(*(void**)p),96);}
    else if(f.kind==FK_MODEL_ARRAY){void**a=*(void***)p;scopy(v.asset,asset_name(a?a[f.arrayIndex]:0),96);}
}
static int batch_apply_field(const BatchWeaponEntry&b,int i,WeaponCompleteHead*w){
    const FieldDesc&f=kFields[i];const BatchFieldValue&v=b.field[i];BYTE*base=(f.base==FB_COMPLETE)?(BYTE*)w:(BYTE*)w->def;if(!base)return 0;BYTE*p=base+f.offset;
    if(f.kind==FK_INT){int x=0;memcpy(&x,&v.bits,sizeof(x));return patch_value(p,x);}
    if(f.kind==FK_FLOAT){float x=0;memcpy(&x,&v.bits,sizeof(x));return patch_value(p,x);}
    if(f.kind==FK_BOOL){BYTE x=v.bits?1:0;return patch_bytes(p,&x,1);}
    if(f.kind==FK_MODEL_DIRECT){void*m=0;if(v.asset[0]){m=DBFind(4,v.asset,0);if(!m)return 0;}return patch_value(p,m);}
    if(f.kind==FK_MODEL_ARRAY){void**a=*(void***)p;if(!a)return 0;void*m=0;if(v.asset[0]){m=DBFind(4,v.asset,0);if(!m)return 0;}return patch_value(&a[f.arrayIndex],m);}
    return 0;
}
static int batch_index_for_weapon(const char*n){for(int i=0;i<g_batchCount;i++)if(seq(g_batch[i].weapon,n))return i;return -1;}
static void capture_weapon_to_batch(BatchWeaponEntry&b,WeaponCompleteHead*w){
    memset(&b,0,sizeof(b));b.magic=0x3642544Au;if(!w)return;scopy(b.weapon,w->name,80);for(int i=0;i<kFieldCount;i++)batch_capture_field(b,i,w);
    for(int src=0;src<3;src++){void**a=get_anim_array(w,src);for(int i=0;i<124;i++)scopy(b.anim[src][i],asset_name(a?a[i]:0),80);}
    DWORD n=get_anim_override_count(w);if(n>64)n=64;b.overrideCount=n;AnimOverrideEntryX*ov=get_anim_overrides(w);if(ov)for(DWORD i=0;i<n;i++){BatchOverrideValue&o=b.overrides[i];o.attachment1=ov[i].attachment1;o.attachment2=ov[i].attachment2;o.animTreeType=ov[i].animTreeType;o.animTime=ov[i].animTime;o.altTime=ov[i].altTime;scopy(o.anim,asset_name(ov[i].overrideAnim),80);scopy(o.altAnim,asset_name(ov[i].altmodeAnim),80);}
}
static int apply_batch_weapon(const BatchWeaponEntry&b,WeaponCompleteHead*w){
    if(!w||!w->def)return 0;int ok=1;for(int i=0;i<kFieldCount;i++)if(!batch_apply_field(b,i,w))ok=0;
    for(int src=0;src<3;src++){void**a=get_anim_array(w,src);if(!a)continue;for(int i=0;i<124;i++){void*x=0;if(b.anim[src][i][0]){x=DBFind(2,b.anim[src][i],0);if(!x){ok=0;continue;}}if(!patch_value(&a[i],x))ok=0;}}
    AnimOverrideEntryX*ov=get_anim_overrides(w);DWORD n=get_anim_override_count(w);DWORD count=b.overrideCount<n?b.overrideCount:n;if(ov)for(DWORD i=0;i<count;i++){const BatchOverrideValue&o=b.overrides[i];void*x=0,*xa=0;if(o.anim[0]){x=DBFind(2,o.anim,0);if(!x){ok=0;continue;}}if(o.altAnim[0]){xa=DBFind(2,o.altAnim,0);if(!xa){ok=0;continue;}}patch_value(&ov[i].attachment1,o.attachment1);patch_value(&ov[i].attachment2,o.attachment2);patch_value(&ov[i].animTreeType,o.animTreeType);patch_value(&ov[i].animTime,o.animTime);patch_value(&ov[i].altTime,o.altTime);patch_value(&ov[i].overrideAnim,x);patch_value(&ov[i].altmodeAnim,xa);}
    return ok;
}
static void save_batch_file(){HANDLE h=CreateFileA(g_batchPath,GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return;DWORD wr=0;DWORD hdr[3]={0x3642544Au,1u,(DWORD)g_batchCount};WriteFile(h,hdr,sizeof(hdr),&wr,0);if(g_batchCount)WriteFile(h,g_batch,(DWORD)(sizeof(BatchWeaponEntry)*g_batchCount),&wr,0);CloseHandle(h);}
static void load_batch_file(){g_batchCount=0;HANDLE h=CreateFileA(g_batchPath,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return;DWORD hdr[3]={0},rd=0;if(!ReadFile(h,hdr,sizeof(hdr),&rd,0)||rd!=sizeof(hdr)||hdr[0]!=0x3642544Au||hdr[1]!=1u){CloseHandle(h);return;}int n=(int)hdr[2];if(n<0)n=0;if(n>24)n=24;DWORD want=(DWORD)(sizeof(BatchWeaponEntry)*n);if(n&&(!ReadFile(h,g_batch,want,&rd,0)||rd!=want))n=0;g_batchCount=n;CloseHandle(h);}
static void refresh_batch_list(){if(!btList)return;list_begin(btList);SendMessageA(btList,LB_RESETCONTENT,0,0);for(int i=0;i<g_batchCount;i++){char row[180];row[0]=0;scat(row,g_batch[i].weapon,180);scat(row,"   [full saved edit]",180);SendMessageA(btList,LB_ADDSTRING,0,(LPARAM)row);}list_end(btList);if(btInfo){char b[80],n[16];b[0]=0;uint_to_str((unsigned)g_batchCount,n);scat(b,n,80);scat(b," weapon edits saved in Batch",80);SetWindowTextA(btInfo,b);}}
static void batch_save_current(){if(g_sel<0||g_sel>=g_weaponCount){status("Select a weapon first.");return;}WeaponCompleteHead*w=g_weapons[g_sel];if(!w||!w->name)return;int idx=batch_index_for_weapon(w->name);if(idx<0){if(g_batchCount>=24){status("Batch is full (24 weapons). Remove one first.");return;}idx=g_batchCount++;}capture_weapon_to_batch(g_batch[idx],w);save_batch_file();refresh_batch_list();SendMessageA(btList,LB_SETSEL,TRUE,idx);status("Current weapon edit saved/updated in Batch.");}
static void batch_select_all(int yes){if(!btList)return;for(int i=0;i<g_batchCount;i++)SendMessageA(btList,LB_SETSEL,yes?TRUE:FALSE,i);}
static void batch_remove_selected(){if(!btList)return;int write=0;for(int i=0;i<g_batchCount;i++){int sel=(int)SendMessageA(btList,LB_GETSEL,i,0);if(sel>0)continue;if(write!=i)g_batch[write]=g_batch[i];write++;}if(write==g_batchCount){status("Select one or more Batch entries to remove.");return;}g_batchCount=write;save_batch_file();refresh_batch_list();status("Selected Batch entries removed.");}
static void batch_apply_selected(){if(!btList)return;int chosen=0,applied=0,missing=0,partial=0;for(int i=0;i<g_batchCount;i++){if((int)SendMessageA(btList,LB_GETSEL,i,0)<=0)continue;chosen++;WeaponCompleteHead*w=(WeaponCompleteHead*)DBFind(0x23,g_batch[i].weapon,0);if(!w){missing++;continue;}if(apply_batch_weapon(g_batch[i],w))applied++;else{applied++;partial++;}}if(!chosen){status("Select the saved weapon edits you want, then press Apply Selected Batch.");return;}char b[180],n[16];b[0]=0;uint_to_str((unsigned)applied,n);scat(b,n,180);scat(b," weapon edits applied",180);if(missing){uint_to_str((unsigned)missing,n);scat(b,"; ",180);scat(b,n,180);scat(b," not loaded",180);}if(partial){uint_to_str((unsigned)partial,n);scat(b,"; ",180);scat(b,n,180);scat(b," had unloaded assets",180);}status(b);if(g_activeTab==0)refresh_wp_fields();if(g_activeTab==1)refresh_anims();}

static int write_embedded_barrier(){make_temp_barrier_path();HANDLE h=CreateFileA(g_barrierPath,GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);if(h==INVALID_HANDLE_VALUE)return 0;DWORD wr=0;BOOL ok=WriteFile(h,kBarrierDll,kBarrierDllSize,&wr,0);CloseHandle(h);return ok&&wr==kBarrierDllSize;}
static void update_nb(){if(nbStatus)SetWindowTextA(nbStatus,g_barrier?"ACTIVE - IW6 map barriers are disabled":"OFF - normal IW6 map barriers are active");}
static void toggle_barrier(){if(!g_barrier){if(!write_embedded_barrier()){status("Could not prepare embedded IW6 No Barriers module.");return;}g_barrier=LoadLibraryA(g_barrierPath);if(g_barrier)status("No Barriers ON. Using the exact IW6 DLL you supplied.");else status("No Barriers failed to load on this IW6x build.");}else{HMODULE h=g_barrier;g_barrier=0;if(FreeLibrary(h)){DeleteFileA(g_barrierPath);status("No Barriers OFF. Original DLL detach routine requested.");}else{g_barrier=h;status("No Barriers could not be unloaded safely.");}}update_nb();}

static void dark_scrollbar(HWND h){
    static HMODULE ux=0;typedef long (WINAPI *SetThemeFn)(HWND,const unsigned short*,const unsigned short*);static SetThemeFn fn=0;
    if(!ux){ux=LoadLibraryA("uxtheme.dll");if(ux)fn=(SetThemeFn)GetProcAddress(ux,"SetWindowTheme");}
    if(fn&&h)fn(h,(const unsigned short*)L"DarkMode_Explorer",0);
}
static void build_ui(){
    g_font=CreateFontA(-16,0,0,0,400,0,0,0,1,0,0,5,0,"Segoe UI");
    g_fontBold=CreateFontA(-19,0,0,0,700,0,0,0,1,0,0,5,0,"Segoe UI Semibold");

    // Polished shell: same editor internals, cleaner Ghost-style frame.
    
    HWND title=label("Janu's WeaponDef",78,30,440,26,0,0);set_bold(title);
    {HWND hint=add_ctrl("STATIC","INSERT  show / hide",SS_RIGHT,1000,32,270,22,0,0,0);(void)hint;}
    {HWND hm=button("",WIN_W-14-8-44-4-44,24,44,36,BTN_MIN_ID,0,0);(void)hm;HWND hc=button("",WIN_W-14-8-44,24,44,36,BTN_CLOSE_ID,0,0);(void)hc;}

    g_tabs[0]=button("WP",18,116,48,46,200,0,0);
    g_tabs[1]=button("AN",18,174,48,46,201,0,0);
    g_tabs[2]=button("SV",18,232,48,46,202,0,0);
    g_tabs[3]=button("NB",18,290,48,46,203,0,0);
    g_tabs[4]=button("FX",18,348,48,46,204,0,0);
    g_tabs[5]=button("TH",18,406,48,46,205,0,0);
    g_tabs[6]=button("BT",18,464,48,46,206,0,0);

    label("WEAPONS",100,92,120,22,0,0);
    g_search=editbox(100,118,292,30,150,0,0);
    button("Refresh Pool",100,158,142,34,101,0,0);
    button("Find/Add Asset",250,158,142,34,151,0,0);
    g_countLabel=label("0 weapons",100,202,292,24,0,0);
    g_weaponList=add_ctrl("LISTBOX","",WS_BORDER|LBS_NOTIFY|LBS_NOINTEGRALHEIGHT|LBS_OWNERDRAWFIXED|LBS_HASSTRINGS|WS_VSCROLL,100,230,292,512,100,0,0);

    g_weaponTitle=label("Select a weapon",416,92,475,32,0,0);set_bold(g_weaponTitle);
    button("Reset to Defaults",904,92,176,32,102,0,0);
    g_status=label("Starting Janu's WeaponDef...",100,765,740,22,0,0);
    {HWND ver=add_ctrl("STATIC","v1",SS_RIGHT,1020,765,64,22,0,0,0);(void)ver;}

    // WP - unchanged editor behavior, polished spacing.
    const char* ct[7]={"Variant","Ammo","Reload","Timing","Misc","Models","Movement"};int cx=416;int cw[7]={88,82,88,88,82,88,102};
    for(int i=0;i<7;i++){g_wpCatButtons[i]=button(ct[i],cx,140,cw[i],36,210+i,g_wp,&g_wpN);cx+=cw[i]+5;}
    label("Property",428,192,260,24,g_wp,&g_wpN);label("Current Value",764,192,220,24,g_wp,&g_wpN);
    wpFieldList=add_ctrl("LISTBOX","",WS_BORDER|LBS_NOTIFY|LBS_NOINTEGRALHEIGHT|LBS_OWNERDRAWFIXED|LBS_HASSTRINGS|WS_VSCROLL,416,220,664,420,230,g_wp,&g_wpN);
    label("Select a property, edit the value, then Apply.",428,654,430,24,g_wp,&g_wpN);wpValueEdit=editbox(624,688,306,30,231,g_wp,&g_wpN);button("Apply",942,686,138,34,232,g_wp,&g_wpN);

    // AN - unchanged animation behavior.
    g_animSourceButtons[0]=button("BASE",416,140,74,31,404,g_an,&g_anN);g_animSourceButtons[1]=button("RIGHT",495,140,74,31,405,g_an,&g_anN);g_animSourceButtons[2]=button("LEFT",574,140,74,31,406,g_an,&g_anN);g_animSourceButtons[3]=button("OVR",653,140,74,31,407,g_an,&g_anN);anSourceInfo=label("COMPLETE",740,144,142,24,g_an,&g_anN);button("Restore All Anims",886,140,194,31,403,g_an,&g_anN);
    const char* af[6]={"CORE","USED","RELOAD","MOVE","COMBAT","ALL"};int ax=416;for(int i=0;i<6;i++){g_animFilterButtons[i]=button(af[i],ax,180,82,29,420+i,g_an,&g_anN);ax+=87;}
    anList=add_ctrl("LISTBOX","",WS_BORDER|LBS_NOTIFY|LBS_NOINTEGRALHEIGHT|LBS_OWNERDRAWFIXED|LBS_HASSTRINGS|WS_VSCROLL,416,218,664,334,400,g_an,&g_anN);
    label("Current / New XAnim",416,564,180,24,g_an,&g_anN);anEdit=editbox(596,562,342,30,401,g_an,&g_anN);button("Apply",946,560,134,34,402,g_an,&g_anN);
    HWND oa=label("Altmode XAnim",416,602,145,24,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=oa;anAltEdit=editbox(562,600,260,27,408,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=anAltEdit;
    HWND ot=label("Type",834,602,45,24,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=ot;anTypeEdit=editbox(880,600,72,27,409,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=anTypeEdit;
    HWND om=label("Time",416,638,52,24,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=om;anTimeEdit=editbox(468,636,82,27,410,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=anTimeEdit;
    HWND oat=label("Alt Time",562,638,70,24,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=oat;anAltTimeEdit=editbox(634,636,82,27,411,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=anAltTimeEdit;
    HWND o1=label("Attach 1",730,638,70,24,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=o1;anAttach1Edit=editbox(800,636,70,27,412,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=anAttach1Edit;
    HWND o2=label("Attach 2",884,638,70,24,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=o2;anAttach2Edit=editbox(954,636,70,27,413,g_an,&g_anN);g_anOverrideOnly[g_anOverrideOnlyN++]=anAttach2Edit;
    label("CORE shows useful live actions. USED/category views expose variants. ALL shows every raw slot.",416,680,664,38,g_an,&g_anN);

    // SAVED - unchanged logic.
    label("SAVED PRESETS",416,140,220,26,g_sv,&g_svN);svList=add_ctrl("LISTBOX","",WS_BORDER|LBS_NOTIFY|LBS_OWNERDRAWFIXED|LBS_HASSTRINGS|WS_VSCROLL,416,178,664,354,500,g_sv,&g_svN);
    label("Preset name",416,548,130,24,g_sv,&g_svN);svName=editbox(524,546,300,28,501,g_sv,&g_svN);button("Save Current Setup",836,544,244,32,502,g_sv,&g_svN);
    button("Apply to Selected Weapon",416,590,300,34,503,g_sv,&g_svN);button("Delete Saved",728,590,352,34,505,g_sv,&g_svN);

    // NB - unchanged logic.
    label("NO BARRIERS",416,140,260,30,g_nb,&g_nbN);nbStatus=label("OFF - normal IW6 map barriers are active",416,184,560,28,g_nb,&g_nbN);button("Toggle No Barriers",416,228,250,36,600,g_nb,&g_nbN);label("Uses the exact iw6-no-barriers.dll you supplied.",416,280,520,24,g_nb,&g_nbN);

    // FX - animated visual layer only; no WeaponDef data is touched.
    label("FX",416,140,80,30,g_fx,&g_fxN);g_fxStatus=label("",500,140,500,30,g_fx,&g_fxN);set_bold(g_fxStatus);
    g_fxToggle=button("FX OFF",416,184,160,40,900,g_fx,&g_fxN);label("FX is background-only. It will never draw over tabs, lists, fields, buttons or Ghost art.",590,188,490,34,g_fx,&g_fxN);
    label("STYLE",416,244,100,24,g_fx,&g_fxN);int fxX=416,fxY=274;for(int i=0;i<6;i++){g_fxStyleButtons[i]=button(kFxNames[i],fxX,fxY,206,40,910+i,g_fx,&g_fxN);fxX+=220;if(i==2){fxX=416;fxY+=52;}}
    label("SPEED",416,386,100,24,g_fx,&g_fxN);g_fxSpeedButtons[0]=button("Slow",416,414,132,36,920,g_fx,&g_fxN);g_fxSpeedButtons[1]=button("Normal",556,414,132,36,921,g_fx,&g_fxN);g_fxSpeedButtons[2]=button("Fast",696,414,132,36,922,g_fx,&g_fxN);
    label("DENSITY",416,466,100,24,g_fx,&g_fxN);g_fxDensityButtons[0]=button("Low",416,494,132,36,930,g_fx,&g_fxN);g_fxDensityButtons[1]=button("Medium",556,494,132,36,931,g_fx,&g_fxN);g_fxDensityButtons[2]=button("High",696,494,132,36,932,g_fx,&g_fxN);
    label("SIZE",416,546,80,24,g_fx,&g_fxN);g_fxSizeButtons[0]=button("Small",416,574,132,36,940,g_fx,&g_fxN);g_fxSizeButtons[1]=button("Medium",556,574,132,36,941,g_fx,&g_fxN);g_fxSizeButtons[2]=button("Large",696,574,132,36,942,g_fx,&g_fxN);
    label("BRIGHTNESS",848,386,120,24,g_fx,&g_fxN);g_fxBrightButtons[0]=button("Low",848,414,106,36,950,g_fx,&g_fxN);g_fxBrightButtons[1]=button("Medium",962,414,118,36,951,g_fx,&g_fxN);g_fxBrightButtons[2]=button("High",848,458,232,36,952,g_fx,&g_fxN);
    label("BACKGROUND",848,516,120,24,g_fx,&g_fxN);g_fxScopeButtons[0]=button("Content BG",848,544,106,36,960,g_fx,&g_fxN);g_fxScopeButtons[1]=button("Editor BG",962,544,118,36,961,g_fx,&g_fxN);
    label("Content BG = right editor panel only. Editor BG = weapon + editor background. Controls stay clean.",848,594,232,58,g_fx,&g_fxN);
    update_fx_status();

    // THEME - visual only. Does not touch WeaponDef data.
    label("THEME",416,140,180,30,g_th,&g_thN);g_themeNameLabel=label(kThemes[g_themeIndex].name,598,140,300,30,g_th,&g_thN);set_bold(g_themeNameLabel);
    label("Change the tool colors instantly. Weapon, animation, saved and batch data are untouched.",416,178,664,42,g_th,&g_thN);
    int tx=416,ty=236;for(int i=0;i<kThemeCount;i++){g_themeButtons[i]=button(kThemes[i].name,tx,ty,206,46,800+i,g_th,&g_thN);tx+=220;if((i%3)==2){tx=416;ty+=62;}}
    label("Theme choice is saved beside the DLL and restored next time the tool opens.",416,448,664,36,g_th,&g_thN);

    // BATCH - unchanged multi-weapon loader.
    label("BATCH LOADER",416,140,260,28,g_bt,&g_btN);btInfo=label("0 weapon edits saved in Batch",416,176,500,24,g_bt,&g_btN);
    btList=add_ctrl("LISTBOX","",WS_BORDER|LBS_NOTIFY|LBS_MULTIPLESEL|LBS_NOINTEGRALHEIGHT|LBS_OWNERDRAWFIXED|LBS_HASSTRINGS|WS_VSCROLL,416,210,664,334,700,g_bt,&g_btN);
    label("Save each edited weapon here, then select any combination and load them together.",416,556,664,36,g_bt,&g_btN);
    button("Save / Update Current Weapon",416,604,248,34,701,g_bt,&g_btN);button("Select All",672,604,124,34,702,g_bt,&g_btN);button("Clear Selection",804,604,134,34,703,g_bt,&g_btN);button("Remove",946,604,134,34,704,g_bt,&g_btN);
    button("Apply Selected Batch",416,650,664,40,705,g_bt,&g_btN);

    dark_scrollbar(g_weaponList);dark_scrollbar(wpFieldList);dark_scrollbar(anList);dark_scrollbar(svList);dark_scrollbar(btList);
    g_wpCat=0;g_animFilter=0;switch_tab(0);update_anim_override_visibility();
}

static int button_active_id(int id){
    if(id>=200&&id<=206)return id==(200+g_activeTab);
    if(id>=210&&id<=216)return id==(210+g_wpCat);
    if(id>=404&&id<=407)return id==(404+g_animSource);
    if(id>=420&&id<=425)return id==(420+g_animFilter);
    if(id>=800&&id<800+kThemeCount)return id==(800+g_themeIndex);
    if(id==900)return g_fxEnabled;
    if(id>=910&&id<=915)return id==(910+g_fxStyle);
    if(id>=920&&id<=922)return id==(920+g_fxSpeed);
    if(id>=930&&id<=932)return id==(930+g_fxDensity);
    if(id>=940&&id<=942)return id==(940+g_fxSize);
    if(id>=950&&id<=952)return id==(950+g_fxBrightness);
    if(id>=960&&id<=961)return id==(960+g_fxScope);
    return 0;
}
static void fill_strip_frame(HDC dc,const RECT&r,HBRUSH b,int t);
static void draw_button_owner(DRAWITEMSTRUCT*d){
    RECT r=d->rcItem;
    int hover=(d->hwndItem==g_hotWnd);
    if(d->CtlID==BTN_MIN_ID||d->CtlID==BTN_CLOSE_ID){
        int pr=((d->itemState&ODS_SELECTED)!=0)||hover;int cl=(d->CtlID==BTN_CLOSE_ID);
        HBRUSH red=CreateSolidBrush(RGBX(196,43,28));
        FillRect(d->hDC,&r,(pr&&cl)?red:(pr?g_selectBrush:g_panelBrush));
        RECT fr={r.left,r.top,r.right,r.bottom};fill_strip_frame(d->hDC,fr,g_borderBrush,1);
        int mx=(r.left+r.right)/2,my=(r.top+r.bottom)/2;HBRUSH ink=pr?g_brightBrush:g_brightBrush;
        if(cl){for(int i=-6;i<=6;i++){RECT a={mx+i-1,my+i-1,mx+i+1,my+i+1};FillRect(d->hDC,&a,ink);RECT b={mx+i-1,my-i-1,mx+i+1,my-i+1};FillRect(d->hDC,&b,ink);}}
        else{RECT a={mx-7,my+4,mx+7,my+6};FillRect(d->hDC,&a,ink);}
        DeleteObject(red);return;
    }
    int active=button_active_id((int)d->CtlID);int pressed=(d->itemState&ODS_SELECTED)!=0;
    int hot=(active||pressed);
    if(!hot&&hover){
        FillRect(d->hDC,&r,g_accentBrush);RECT hi={r.left+1,r.top+1,r.right-1,r.bottom-1};FillRect(d->hDC,&hi,g_selectBrush);
        char ht[128];ht[0]=0;GetWindowTextA(d->hwndItem,ht,127);SetBkMode(d->hDC,TRANSPARENT);SetTextColor(d->hDC,C_ACCENT_BRIGHT);RECT tr={r.left+2,r.top+2,r.right-2,r.bottom-2};DrawTextA(d->hDC,ht,-1,&tr,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX);return;
    }
    FillRect(d->hDC,&r,hot?g_brightBrush:g_borderBrush);
    RECT mid={r.left+1,r.top+1,r.right-1,r.bottom-1};FillRect(d->hDC,&mid,hot?g_accentBrush:g_panelBrush);
    RECT in={r.left+2,r.top+2,r.right-2,r.bottom-2};FillRect(d->hDC,&in,hot?g_selectBrush:g_panelBrush);
    if(hot){RECT gl={r.left+2,r.top+2,r.right-2,r.top+6};FillRect(d->hDC,&gl,g_brightBrush);gl={r.left+2,r.bottom-6,r.right-2,r.bottom-2};FillRect(d->hDC,&gl,g_accentBrush);RECT edge={r.left+2,r.top+2,r.left+6,r.bottom-2};FillRect(d->hDC,&edge,g_brightBrush);RECT edge2={r.right-6,r.top+2,r.right-2,r.bottom-2};FillRect(d->hDC,&edge2,g_accentBrush);} 
    char t[128];t[0]=0;GetWindowTextA(d->hwndItem,t,127);SetBkMode(d->hDC,TRANSPARENT);SetTextColor(d->hDC,hot?C_ACCENT_BRIGHT:C_TEXT);DrawTextA(d->hDC,t,-1,&in,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX);
}
static void draw_list_owner(DRAWITEMSTRUCT*d){
    if(d->itemID==(UINT)-1)return;RECT r=d->rcItem;int sel=(d->itemState&ODS_SELECTED)!=0;FillRect(d->hDC,&r,sel?g_selectBrush:g_editBrush);if(sel){RECT a={r.left,r.top,r.left+3,r.bottom};FillRect(d->hDC,&a,g_accentBrush);RECT hi={r.left+3,r.top,r.right,r.top+1};FillRect(d->hDC,&hi,g_borderBrush);}char t[384];t[0]=0;SendMessageA(d->hwndItem,LB_GETTEXT,d->itemID,(LPARAM)t);RECT tr={r.left+8,r.top,r.right-4,r.bottom};SetBkMode(d->hDC,TRANSPARENT);SetTextColor(d->hDC,sel?C_ACCENT_BRIGHT:C_TEXT);DrawTextA(d->hDC,t,-1,&tr,DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX);
}

static void fill_strip_frame(HDC dc,const RECT&r,HBRUSH b,int t){
    RECT x={r.left,r.top,r.right,r.top+t};FillRect(dc,&x,b);
    x={r.left,r.bottom-t,r.right,r.bottom};FillRect(dc,&x,b);
    x={r.left,r.top+t,r.left+t,r.bottom-t};FillRect(dc,&x,b);
    x={r.right-t,r.top+t,r.right,r.bottom-t};FillRect(dc,&x,b);
}
static void draw_ghost_art(HDC dc,const RECT&r){
    if(r.right<=r.left||r.bottom<=r.top)return;
    // Fit the art to the panel height without stretching it, centred, with a thin frame.
    int ph=r.bottom-r.top-16,pw=(ph*kGhostArtW)/kGhostArtH;int maxw=r.right-r.left-16;if(pw>maxw){pw=maxw;ph=(pw*kGhostArtH)/kGhostArtW;}
    RECT a;a.left=r.left+((r.right-r.left)-pw)/2;a.top=r.top+((r.bottom-r.top)-ph)/2;a.right=a.left+pw;a.bottom=a.top+ph;
    BITMAPINFO_X bi;memset(&bi,0,sizeof(bi));bi.bmiHeader.biSize=sizeof(BITMAPINFOHEADER_X);bi.bmiHeader.biWidth=kGhostArtW;bi.bmiHeader.biHeight=-kGhostArtH;bi.bmiHeader.biPlanes=1;bi.bmiHeader.biBitCount=24;bi.bmiHeader.biCompression=BI_RGB;
    StretchDIBits(dc,a.left,a.top,pw,ph,0,0,kGhostArtW,kGhostArtH,kGhostArtBGR,&bi,DIB_RGB_COLORS,SRCCOPY);
    RECT fr={a.left-2,a.top-2,a.right+2,a.bottom+2};fill_strip_frame(dc,fr,g_borderBrush,1);
}
static LRESULT CALLBACK WndProc(HWND h,UINT msg,WPARAM wp,LPARAM lp){
    if(msg==WM_JANU_TOGGLE_FOCUS){
        if(wp){
            if(IsIconic(h))ShowWindow(h,SW_RESTORE);else ShowWindow(h,SW_SHOW);
            BringWindowToTop(h);
            SetForegroundWindow(h);
            SetActiveWindow(h);
            SetFocus(h);
            UpdateWindow(h);
        }else{
            ShowWindow(h,SW_HIDE);
        }
        return 0;
    }
    if(msg==WM_TIMER&&wp==7){
        POINT pt;pt.x=0;pt.y=0;GetCursorPos(&pt);HWND w=WindowFromPoint(pt);HWND hot=0;
        for(int i=0;i<g_btnWndN;i++)if(g_btnWnds[i]==w){hot=w;break;}
        if(hot!=g_hotWnd){HWND old=g_hotWnd;g_hotWnd=hot;if(old)InvalidateRect(old,0,FALSE);if(hot)InvalidateRect(hot,0,FALSE);}
        static int tick=0;if(++tick>=20){tick=0;if(!IsIconic(h)&&!(GetAsyncKeyState(1)&0x8000)){RECT wr;GetWindowRect(h,&wr);if(wr.left>-30000&&(wr.left!=g_savedX||wr.top!=g_savedY)){g_savedX=wr.left;g_savedY=wr.top;save_window_pos();}}}
        return 0;
    }
    if(msg==WM_NCHITTEST){
        // Borderless window: the header strip drags the window, the buttons stay clickable.
        RECT wr;GetWindowRect(h,&wr);int cx=(int)(short)(lp&0xFFFF)-wr.left,cy=(int)(short)((lp>>16)&0xFFFF)-wr.top;
        if(cy>=14&&cy<72&&cx>=14&&cx<(WIN_W-14-8-44-4-44-8))return HTCAPTION;
        return HTCLIENT;
    }
    if(msg==WM_MEASUREITEM){MEASUREITEMSTRUCT*m=(MEASUREITEMSTRUCT*)lp;if(m&&m->CtlType==ODT_LISTBOX){m->itemHeight=22;return TRUE;}}
    if(msg==WM_DRAWITEM){DRAWITEMSTRUCT*d=(DRAWITEMSTRUCT*)lp;if(d){if(d->CtlType==ODT_BUTTON){draw_button_owner(d);return TRUE;}if(d->CtlType==ODT_LISTBOX){draw_list_owner(d);return TRUE;}}}
    if(msg==WM_COMMAND){int id=LOWORDX(wp),code=HIWORDX(wp);
        if(id==BTN_MIN_ID){ShowWindow(h,SW_MINIMIZE);return 0;}
        if(id==BTN_CLOSE_ID){{RECT wr;GetWindowRect(h,&wr);if(wr.left>-30000){g_savedX=wr.left;g_savedY=wr.top;save_window_pos();}}g_toolVisible=0;ShowWindow(h,SW_HIDE);status("Hidden. Press INSERT to show the tool again.");return 0;}
        if(id==100&&code==LBN_SELCHANGE){weapon_changed();return 0;}
        if(id==150&&code==EN_CHANGE){rebuild_weapon_list();weapon_changed();return 0;}
        if(id==101){refresh_pool();weapon_changed();return 0;}
        if(id==151){find_add_weapon();weapon_changed();return 0;}
        if(id==102){restore_selected();return 0;}
        if(id>=200&&id<=206){switch_tab(id-200);if(id==200)refresh_wp_fields();if(id==201){update_anim_override_visibility();refresh_anims();}if(id==206)refresh_batch_list();redraw_nav();return 0;}
        if(id>=210&&id<=216){g_wpCat=id-210;refresh_wp_fields();redraw_nav();return 0;}
        if(id==230&&code==LBN_SELCHANGE){wp_field_changed();return 0;}
        if(id==232){apply_wp_field();return 0;}
        if(id==400&&code==LBN_SELCHANGE){anim_selection_changed();return 0;}
        if(id==402){apply_anim();return 0;}
        if(id>=404&&id<=407){g_animSource=id-404;refresh_anims();redraw_nav();return 0;}
        if(id>=420&&id<=425){g_animFilter=id-420;refresh_anims();redraw_nav();return 0;}
        if(id==403){restore_all_anims();return 0;}
        if(id==900){g_fxEnabled=!g_fxEnabled;save_fx_file();update_fx_status();redraw_nav();InvalidateRect(g_main,0,FALSE);return 0;}
        if(id>=910&&id<=915){g_fxStyle=id-910;save_fx_file();update_fx_status();redraw_nav();InvalidateRect(g_main,0,FALSE);return 0;}
        if(id>=920&&id<=922){g_fxSpeed=id-920;save_fx_file();update_fx_status();redraw_nav();return 0;}
        if(id>=930&&id<=932){g_fxDensity=id-930;save_fx_file();redraw_nav();InvalidateRect(g_main,0,FALSE);return 0;}
        if(id>=940&&id<=942){g_fxSize=id-940;save_fx_file();redraw_nav();InvalidateRect(g_main,0,FALSE);return 0;}
        if(id>=950&&id<=952){g_fxBrightness=id-950;save_fx_file();redraw_nav();InvalidateRect(g_main,0,FALSE);return 0;}
        if(id>=960&&id<=961){g_fxScope=id-960;save_fx_file();redraw_nav();InvalidateRect(g_main,0,FALSE);return 0;}
        if(id>=800&&id<800+kThemeCount){apply_theme(id-800,1);redraw_nav();return 0;}
        if(id==502){save_current();return 0;}if(id==503){apply_saved();return 0;}if(id==505){delete_saved();return 0;}if(id==600){toggle_barrier();return 0;}if(id==701){batch_save_current();return 0;}if(id==702){batch_select_all(1);return 0;}if(id==703){batch_select_all(0);return 0;}if(id==704){batch_remove_selected();return 0;}if(id==705){batch_apply_selected();return 0;}
    }
    if(msg==WM_CTLCOLORSTATIC||msg==WM_CTLCOLORBTN||msg==WM_CTLCOLOREDIT||msg==WM_CTLCOLORLISTBOX){HDC dc=(HDC)wp;SetTextColor(dc,(msg==WM_CTLCOLORSTATIC)?C_ACCENT:C_TEXT);if(msg==WM_CTLCOLOREDIT||msg==WM_CTLCOLORLISTBOX){SetBkColor(dc,C_EDIT);return (LRESULT)g_editBrush;}SetBkMode(dc,TRANSPARENT);return (LRESULT)g_panelBrush;}
    if(msg==WM_ERASEBKGND){return TRUE;} // prevents the erase/paint flash that caused FX flicker
    if(msg==WM_PAINT){PAINTSTRUCT ps;HDC dc=BeginPaint(h,&ps);RECT r;GetClientRect(h,&r);FillRect(dc,&r,g_bgBrush);
        // Thin window frame: 1px accent outline, 1px dark inner line. No thick glow band.
        RECT f0={0,0,r.right,r.bottom};fill_strip_frame(dc,f0,g_accentBrush,1);
        RECT f1={1,1,r.right-1,r.bottom-1};fill_strip_frame(dc,f1,g_selectBrush,1);
        int pb=r.bottom-46;
        RECT header={14,14,r.right-14,72};FillRect(dc,&header,g_panelBrush);fill_strip_frame(dc,header,g_borderBrush,1);
        RECT hline={15,70,r.right-15,72};FillRect(dc,&hline,g_accentBrush);
        RECT leftAccent={14,14,17,70};FillRect(dc,&leftAccent,g_accentBrush);
        RECT badge={20,20,64,64};FillRect(dc,&badge,g_bgBrush);fill_strip_frame(dc,badge,g_accentBrush,1);
        {BITMAPINFO_X ib;memset(&ib,0,sizeof(ib));ib.bmiHeader.biSize=sizeof(BITMAPINFOHEADER_X);ib.bmiHeader.biWidth=40;ib.bmiHeader.biHeight=-40;ib.bmiHeader.biPlanes=1;ib.bmiHeader.biBitCount=24;ib.bmiHeader.biCompression=BI_RGB;
         StretchDIBits(dc,22,22,40,40,0,0,40,40,kLogo40BGR,&ib,DIB_RGB_COLORS,SRCCOPY);}
        RECT rail={14,86,82,pb};FillRect(dc,&rail,g_panelBrush);fill_strip_frame(dc,rail,g_borderBrush,1);
        RECT weaponPanel={92,86,402,pb};FillRect(dc,&weaponPanel,g_panelBrush);fill_strip_frame(dc,weaponPanel,g_borderBrush,1);
        RECT contentPanel={406,86,1090,pb};FillRect(dc,&contentPanel,g_panelBrush);fill_strip_frame(dc,contentPanel,g_borderBrush,1);
        RECT artPanel={1100,86,r.right-14,pb};FillRect(dc,&artPanel,g_panelBrush);fill_strip_frame(dc,artPanel,g_borderBrush,1);draw_ghost_art(dc,artPanel);
        draw_fx(dc,r);
        RECT footer={14,r.bottom-40,r.right-14,r.bottom-12};FillRect(dc,&footer,g_panelBrush);fill_strip_frame(dc,footer,g_borderBrush,1);
        RECT fAcc={14,r.bottom-40,17,r.bottom-12};FillRect(dc,&fAcc,g_accentBrush);
        EndPaint(h,&ps);return 0;}
    if(msg==WM_DESTROY){g_main=0;PostQuitMessage(0);return 0;}return DefWindowProcA(h,msg,wp,lp);
}

static DWORD WINAPI HotkeyThread(LPVOID){
    int wasDown=0;
    int keepAliveTicks=0;
    for(;;){
        if(!g_main)break;
        int down=(GetAsyncKeyState(VK_INSERT)&0x8000)!=0;
        if(down&&!wasDown){
            g_toolVisible=!g_toolVisible;
            SendMessageA(g_main,WM_JANU_TOGGLE_FOCUS,(WPARAM)(g_toolVisible?1:0),0);
            keepAliveTicks=0;
        }
        wasDown=down;
        if(g_toolVisible){
            keepAliveTicks++;
            if(keepAliveTicks>=30){
                // IW6 can steal foreground/focus during match transitions. Keep the
                // already-topmost editor visible. Focus is only taken when Insert opens it.
                if(!IsIconic(g_main))ShowWindow(g_main,SW_SHOW);
                keepAliveTicks=0;
            }
        }else keepAliveTicks=0;
        Sleep(15);
    }
    return 0;
}

static DWORD WINAPI MainThread(LPVOID){
    // Wait for IW6 MP module mapped at 0x140... by IW6x.
    for(int i=0;i<120;i++){if(readable_exec((void*)0x14031FC00ull)&&readable_exec((void*)0x14031F3A0ull))break;Sleep(500);}
    build_module_path(g_savePath,520,"IW6X_WeaponDef_JANU_Saved.bin");build_module_path(g_batchPath,520,"IW6X_WeaponDef_JANU_Batch_v6.bin");build_module_path(g_themePath,520,"IW6X_WeaponDef_JANU_Theme_v1.bin");build_module_path(g_fxPath,520,"IW6X_WeaponDef_JANU_FX_v1.bin");build_module_path(g_winPath,520,"IW6X_WeaponDef_JANU_Window_v1.bin");load_presets_file();load_batch_file();load_theme_file();load_fx_file();
    create_theme_brushes();
    WNDCLASSEXA wc;memset(&wc,0,sizeof(wc));wc.cbSize=sizeof(wc);wc.style=CS_DROPSHADOW;wc.lpfnWndProc=WndProc;wc.hInstance=g_module;wc.hbrBackground=0;wc.lpszClassName="IW6XWeaponDefJanuGhostV1FXBgWindow";
    int startX=35,startY=25;load_window_pos(&startX,&startY);g_savedX=startX;g_savedY=startY;
    wc.hIcon=wc.hIconSm=g_hIcon=make_icon();RegisterClassExA(&wc);
    g_main=CreateWindowExA(WS_EX_TOPMOST|WS_EX_APPWINDOW,wc.lpszClassName,"Janu's WeaponDef",WS_POPUP|WS_VISIBLE|WS_CLIPCHILDREN,startX,startY,WIN_W,WIN_H,0,0,g_module,0);
    if(!g_main)return 0;
    {   // Windows 11: no extra system border around our own frame (ignored on older Windows)
        HMODULE dwm=LoadLibraryA("dwmapi.dll");
        if(dwm){typedef long (WINAPI *DwmSetFn)(HWND,DWORD,const void*,DWORD);DwmSetFn f=(DwmSetFn)GetProcAddress(dwm,"DwmSetWindowAttribute");
            if(f){DWORD none=0xFFFFFFFEu;f(g_main,34,&none,4);}}
    }build_ui();refresh_preset_list();refresh_batch_list();refresh_pool();weapon_changed();refresh_wp_fields();g_toolVisible=1;ShowWindow(g_main,SW_SHOW);UpdateWindow(g_main);SetTimer(g_main,7,50,0);CreateThread(0,0,FxThread,0,0,0);CreateThread(0,0,HotkeyThread,0,0,0);
    MSG m;while(GetMessageA(&m,0,0,0)>0){TranslateMessage(&m);DispatchMessageA(&m);}return 0;
}

extern "C" BOOL WINAPI DllMain(HMODULE h,DWORD reason,LPVOID);
extern "C" __declspec(dllexport) void* IW6X_GUI_RelocAnchor=(void*)&DllMain;
extern "C" BOOL WINAPI DllMain(HMODULE h,DWORD reason,LPVOID){if(reason==1){g_module=(HINSTANCE)h;DisableThreadLibraryCalls(h);CreateThread(0,0,MainThread,0,0,0);}return TRUE;}

extern "C" int _fltused = 0;
