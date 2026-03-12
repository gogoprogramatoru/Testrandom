[Setup]
; Informații de bază despre aplicație
AppName=Verificator Par
AppVersion=1.2
SetupIconFile=logo.ico
AppPublisher=Andrei Gogoseanu (CEO)
; Folderul default unde se va instala (ex: C:\Program Files\Verificator Par)
DefaultDirName={autopf}\Verificator Par
; Numele fisierului final de setup
OutputBaseFilename=VerificatorPar_Setup
; Folderul unde GitHub va salva installer-ul
OutputDir=Output
; Comprimare foarte bună pentru a face fișierul mic
Compression=lzma
SolidCompression=yes
; Permitem instalarea fără drepturi de administrator absolut necesare
PrivilegesRequired=lowest

[Tasks]
; Adăugăm opțiunea (bifată automat) pentru scurtătură pe desktop
Name: "desktopicon"; Description: "Creează o scurtătură pe Desktop"; GroupDescription: "Scurtături suplimentare:"; Flags: checkablealone

[Files]
; Luăm fișierul principal .exe creat de noi
Source: "build\Release\VerificatorPar.exe"; DestDir: "{app}"; Flags: ignoreversion
; Luăm TOATE celelalte fișiere (DLL-urile adăugate de windeployqt)
Source: "build\Release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
; Creăm scurtătura în meniul Start
Name: "{autoprograms}\Verificator Par"; Filename: "{app}\VerificatorPar.exe"
; Creăm scurtătura pe Desktop (dacă utilizatorul a lăsat căsuța bifată)
Name: "{autodesktop}\Verificator Par"; Filename: "{app}\VerificatorPar.exe"; Tasks: desktopicon

[Run]
; Oferim opțiunea de a rula aplicația imediat după terminarea instalării
Filename: "{app}\VerificatorPar.exe"; Description: "Lansează Verificator Par"; Flags: nowait postinstall skipifsilent