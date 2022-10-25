
// ���ҽ��� ����ϱ� ���ؼ� resource.h ������ include�� �־�� �Ѵ�.
#include "resource.h"
// API �Լ����� ����Ϸ��� windows.h ������ include�� �־�� �Ѵ�.
#include <windows.h>
// C ���� ���� ����Ͽ��� ǥ�� ����� ��� �߰�
#include <stdio.h>

// ���� ��ó���� ��ũ�� ����
// ���ο� ������ ���
/*
	������ �ý�����, �޽������� �ý����̴�.R
	��� �̺�Ʈ�� �޼����� �߻��� ���ؼ� ó���ȴ�.

	����Ʈ�ڽ� ������, �޺��ڽ�������� ��� �̷� ������ ��������� ������
	�޽���ó�������� ���ϴ� ������ �ϰ� �Ǵµ�, �̷� �޽����ܿ� �����
	���� �޽����� �ʿ��Ҷ��� ����. �������, �޺��� ���� ����ɶ�, �θ𿡰� ��
	�ƴ϶�, �ٸ������� �˷��� �ʿ䰡 �ְų� �Ҷ�...

	�׷���, ������ ���� �޽����� ���� �ƹ����Գ� �����ؼ� ����Ҽ� ����.

	#define WM_NewBlock 100
	ó��, �̷������� �����Ѵٸ�, �̹� 100�̶�� ���� �ý����� ����������
	�����ؼ� ����ϴ� �޽��� ����� ���� �ִ�.

	�׷���, ����ڰ� ����ص� �Ǵ� ������ �����״µ� �װ�
	0x400 ������ , 0x7FFF ���� �̴�. ���⼭ 0x400 �� WM_USER �� ���������

	������, ---------------------------------------------
	0 - 0x400 : �ý��� ����
	0x401 - 0x7FFF : WM_USER�޼��������� ����ϰ� ���� ����
	0x8000 - 0xBFFF : ���ø����̼� ��ü �޼��� ȣȯ ����
	��Ÿ...
	-----------------------------------------------------

	�켱 �ٸ� �������� �����ϸ� �Ӹ������ϱ� �켱�� �̷��ٴ°͸� �˾Ƶ���.

	�׸���, WM_USER+1���� 1�� ���ϴ°��� WM_USER�� 0x400�̴ϱ� �� ��������
	�ý����� ����ϴϱ�, 1�� �����༭ 0x401 - 0x7FFF������ ����� ����ص� �Ǵ�
	�Ŵ�.

	(����) ���α׷����� �ʿ信 ���� ������ �����ؼ� ����� �� �ִ� �޽����̴�.
	WM_USER ���ʹ� �����쿡�� ����ϴ� ������ �ƴϹǷ� �ʿ��� ������ŭ +n �ذ��鼭
	�������� �޽����� �����ؼ� �� �� �ִ�. ���� �����찡 ������ �޽����� �ƴϰ�,
	���α׷��Ӱ� ������ �޽����̹Ƿ�, �� �޽����� �߻���Ű�°͵� �� �޽����� ó���ϴ°͵�
	��� ���α׷����� å��.
*/
#define WM_NewBlock WM_USER + 1

#define YES 1
#define NO 0
#define SUCCESS 1
#define FAIL 0
#define ON 1
#define OFF 0
#define ALIVE 1
#define DEAD 0

// ��Ʈ���� ������ ���� 4���� �迭
// �� �迭���� ��� ������ 4���� ����� ����Ǿ� �ִ�.
/*
	������ ��� ȸ�� ����� ����ϱ� ���ؼ� 4���� �迭�� ����Ͽ���. ���⿡���� ù ���� 7�� ������ ����,
	�� ��° 4�� ������ ȸ���� ��Ÿ���� ���̶�� ��������.
	��� ���� ����� 4����(����) ����� ����ϱ� ���ؼ� �迭�� ���� �� �߰��Ͽ���. �Ʒ��� �迭�� ���� ȥ�󽺷����
	�Ʒ��� ���� ���� 4�پ� ��� ���� ������ ����� �� �� �ִ�.
*/

// ��ü ���� ���
int Block[7][4][4][4] = { 0, 1, 0, 0,
						 0, 1, 0, 0,
						 0, 1, 0, 0,
						 0, 1, 0, 0,

						 0, 0, 0, 0,
						 1, 1, 1, 1,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 0, 1, 0, 0,
						 0, 1, 0, 0,
						 0, 1, 0, 0,

						 0, 0, 0, 0,
						 1, 1, 1, 1,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 0, 1, 0,
						 0, 0, 1, 0,
						 0, 1, 1, 0,
						 0, 0, 0, 0,

						 1, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 0, 0, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 0, 0, 0,
						 1, 0, 0, 0,
						 1, 1, 1, 0,
						 0, 0, 0, 0,

						 1, 0, 0, 0,
						 1, 0, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,

						 0, 0, 0, 0,
						 0, 0, 1, 0,
						 1, 1, 1, 0,
						 0, 0, 0, 0,

						 0, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,

						 1, 1, 1, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 0, 0, 0,
						 0, 1, 0, 0,
						 1, 1, 1, 0,
						 0, 0, 0, 0,

						 0, 0, 1, 0,
						 0, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,

						 1, 1, 1, 0,
						 0, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 0, 0, 0,
						 1, 1, 0, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 0, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,

						 0, 1, 1, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 0, 1, 1, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 0,

						 0, 1, 1, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 1, 1, 0, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 0, 1, 1, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 0, 1, 0, 0,
						 1, 1, 0, 0,
						 1, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 0, 1, 1, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0,

						 1, 1, 0, 0,
						 1, 1, 0, 0,
						 0, 0, 0, 0,
						 0, 0, 0, 0 };

// ����� �迭
int BackGround[21][12];

// Ÿ�� OFF
BOOL bTime = OFF;
// ������ ��(����)
int BlockNum;
// ������ ȸ��
int RotateNum;
// ������ ���� ��ǥ
int NowX, NowY;
// ���� ������ ��(����)
int NextBlockNum;
// ������ �� ���� �� ä������ ��� (����)
int FullLineNum;
// ������ �������� ����
int PlayerState;
//ghost���� üũ
int ghostChk;


BOOL holdUse = FALSE;

int holdBlockNum = NULL;
// �������� �ڵ��� ����� ������ �����. (����� ���� �Լ��� ����)
HWND g_hWnd;

// ����� �迭 �ʱ�ȭ �ϴ� �Լ�
void InitBackGround(void);

// ����� �׸��� �Լ�
void DrawBackGround(void);

// ������ �׸��� �Լ�
void DrawBlock(void);

// ������ ����� �Լ�
void EraseBlock(void);

// ���� ������ �׸��� �Լ�
void DrawNextBlock(void);

// ������ ������ �� �ִ����� üũ�ϴ� �Լ�
BOOL BlockCanMove(int x, int y);

// ������ �������� �����̴� �Լ�
void LeftMove(void);

// ������ ���������� �����̴� �Լ�
void RightMove(void);

// ������ ȸ���ϴ� �Լ�
void Rotate(void);

// ������ �Ʒ��� �����̴� �Լ�
BOOL DownMove(void);

// ����� �迭�� ������Ʈ�ϴ� �Լ�
void UpdateBackGround(void);

// ������ �� ���� �� á������ üũ
void CheckFullLine(void);

// ������ �� ���� �� ���� ����� �Լ�
void EraseFullLine(int);

void InitGhost();

void DrawGhost();

void EraseGhost();

void BlockHold();

void BlockHoldRelease();

void InsertLine();
/*
(1) C declaration(__cdecl) : __cdecl �� �Լ��� �Ծ��� �Ǿ� ������,
	�Լ��� ȣ���� �ʿ��� parameter ������ �Լ��� return �ǰ� ����
	stack ���� ������.���� ȣ���� �Լ��� �ڽ��� parameter �� �˰� �ֱ� ������
	printf �� ���� parameter �� �������� �Լ����� ��밡��.

	__cdecl�� ȣ���ڿ� ���� �������ڷ� ���� ���� �޸𸮸� �����ϴ� ���̸�,
	���� �Լ�ȣ��Ծ��� �⺻��(����Ʈ)�� �� �ִ�. ����, �� �⺻���� [������Ʈ] -> [�Ӽ�] -> [C/C++] -> [����] -> [ȣ�� ��Ģ] ����
	������ ���� �ִ�. ���⼭! ȣ����(Caller)��� �ϳ� ���� ����� �� �ִµ� ȣ���ڴ� �Լ��� �θ��� �Լ��̴�.
	���� ���, main()�Լ����� A()��� �Լ��� �����ߴٸ�, A()�� ȣ���ڴ� main()�Լ��� �Ǵ� ���̴�.
	���Ҿ� �� ��Ȳ���� A()�� �Լ��� main()���κ��� ȣ�� ������(Callee)�� �Ǵ� ���̴�.
	���� �޸𸮸� ȣ���ڰ� ���� ������ �ϴٺ��� ���������� Ŀ���ٴ� ������ �ִµ�,
	�̴� �����ϴ� �ڵ带 ���� ���� �ڵ带 ���� �Լ� �ϳ��ϳ� ���� �޸𸮸� �����ϴ� �ڵ带 �־���ϱ� �����̶� �����ϰ� �ִ�.


(2) standard call(__stdcall) : �� �Ծ��� �Լ��� ȣ�� ���� ��(�� �Լ��� ����)����
	parameter �� �����ϵ��� �Ǿ� �ִ�.���� parameter �� ������ ��Ȯ�� ������
	����ϰ� �Ǿ� �ִ�.���������� API �� ���� ��� �Լ��� ���� ���ڵ��� ��Ȯ��
	���� �Ǿ� �ֱ� ������ �ٷ� __stdcall �Ծ��� ����ϰ� �ִ�.

	WINAPI�� define���� �س��� �ڵ��̸�, �� Ư¡�� ȣ���ڿ��� ���� ������ �ִ� ������ �һ� ���������� �ʴ´ٴ� ���̴�.
	���� �ش� ������ �Լ� ���ο��� ���� ������ �ؾ��ϸ�, ���� �������ڷ� ���ڰ� �� ��� ��Ȯ�� ������ ũ�⸦ �Լ� ������ �� �� ����
	�Լ� ���� ������ ȸ������ ���Ѵ�. ��, __stdcall�� �������ڸ� ����� �� ����.

	(����)stdcall ȣ�� ����� cdecl ȣ�� ��ĺ��� ������, ���α׷� �뷮�� ������.
		  stdcall ȣ�� ������ ȣ���� �Լ� ���ο��� �Ķ���� ũ�⸸ŭ pop�� �� �ֱ� ������ �������ڸ� ����ϴ� ���� �Ұ���

*/
// �޽����� ó���� ���� �� �� �Լ��� �����Ѵ�.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// ���α׷��� �������� �����Ѵ�.
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	// �޽��� ����ü�� �����Ѵ�.
	MSG mSg;

	// �������� ĸ���� �����Ѵ�.
	WCHAR szTitle[] = L"��Ʈ����";
	// �������� Ŭ������ �����Ѵ�.
	WCHAR szClass[] = L"Class";


	// �߰����� ������ ���� ��/////////////////////////////////////
	HICON hIcon1;   // icon handle 
	HICON hIcon2;   // icon handle 

	// �⺻ ������ ����
	hIcon1 = LoadIcon(NULL, IDI_QUESTION);

	// ����� ���� ������ ���� 
	hIcon2 = LoadIcon(hInstance, MAKEINTRESOURCE(101));
	///////////////////////////////////////////////////////////////

	// WNDCLASSEX ����ü�� �����Ѵ�. ������ â�� �ϳ��� ������ Ŭ������ ������� �����ȴ�.
	WNDCLASSEX WndEx;

	// WNDCLASSEX ����ü�� ũ�⸦ �����Ѵ�.
	WndEx.cbSize = sizeof(WndEx);

	// �������� ��Ÿ���� �����Ѵ�.
	WndEx.style = NULL;

	// �޽����� ó���� �Լ��� �����Ѵ�. �� �޽����� �߻��ϸ� �� �޽����� WndProc �Լ����� ó���Ѵ�.
	WndEx.lpfnWndProc = WndProc;

	// �߰� Ŭ������ �����Ѵ�. �߰� Ŭ������ ���� ������ NULL ������ �����Ѵ�.
	WndEx.cbClsExtra = 0;

	// �߰� �����츦 �����Ѵ�. �߰� �����찡 ���� ������ NULL ������ �����Ѵ�.
	WndEx.cbWndExtra = 0;

	// �ν��Ͻ� �ڵ��� �����Ѵ�.
	WndEx.hInstance = hInstance;

	// ���� ���Ͽ� ���� �������� �����Ѵ�. LoadIcon() �Լ��� ���ҽ����� �������� �ҷ��� ��ȯ�Ѵ�.
	WndEx.hIcon = LoadIcon(NULL, L"IDI_ICON");

	// �����쿡�� ���� Ŀ���� �����Ѵ�. LoadCursor() �Լ��� �̸� ����� Ŀ�� ���� ��ȯ�Ѵ�.
	WndEx.hCursor = LoadCursor(NULL, IDC_ARROW);

	// �������� ������ �����Ѵ�. GetStockObject() �Լ��� �������� ��ȯ�Ѵ�.
	WndEx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	// �����쿡 ���� �޴��� �����Ѵ�. �޴��� ���� ������ NULL ������ �����Ͽ���.
	WndEx.lpszMenuName = /*L"IDR_MENU"*/MAKEINTRESOURCE(IDR_MENU);

	// Ŭ������ �����Ѵ�. ������ �� Ŭ������ CreateWindowEx() �Լ����� ������ Ŭ������ �����ؾ� �Ѵ�.
	WndEx.lpszClassName = szClass;

	// �������� ĸ���� ���� �������� �����Ѵ�. LoadIcon() �Լ��� ���ҽ����� �������� �ҷ��� ��ȯ�Ѵ�.
	WndEx.hIconSm = LoadIcon(hInstance, /*L"IDI_ICON"*/MAKEINTRESOURCE(IDI_ICON));
	//WndEx.hIconSm = hIcon2;

	/*
		���ҽ��� -> ���ҽ��� �׷��� ��Ҹ� Ȱ���ϴµ� ������ ������ �ڿ��̴�.
		���ҽ� ��� -> ������Ʈ- ���ҽ� ���� ���콺 ������ Ŭ��- �߰�- ���ҽ�
		���ҽ� ID�� -> ���ҽ����� ������ ID�� �Ҵ�Ǹ�, �̰��� �ĺ��ڷ� �̿��Ѵ�. ���ҽ� ��� ���ҽ��� �� ���� �� �� �ִ�.
		���ҽ� ID Ȯ���ϱ� -> ���ҽ� �信�� �Ѵ��� ���� ������ �� �ִ�.

		������, Ŀ�� ����
		���ҽ� ����� ���� ������, Ŀ���� �����ϸ� ���� �׸��� �׷��� ������ ���� �ְ�, �������⸦ ���� ���� �̹����� �ҷ��� ���� �ִ�.
		Ŀ���� Ư���� �ֽ��� ������ ����, �Է¹��� Ŀ���� ��Ȯ�� ��ġ�� ������ ���� �ִ�. �׸��� ������ �ֽ��ϴ�.


		cf)	���ҽ� �ڿ� Ȱ���� ���� ����
			resource ��� ������ ��Ŭ��� �մϴ�.
			#include "Resource.h��



		MAKEINTRESOURCE �� ��ũ�� �Լ��μ� ������ ���ڿ� ������ ������ִ� ����� �Ѵ�.
		�������� API �� ���ҽ� ���� �Լ����� �� ���� ���ڷ� ���ڿ��� �޴´�.
		�׷��� ���ҽ� ��ȣ�� WORD �� �������̹Ƿ� �̰��� ��ȯ�Ѵ�.
		���̵�� resource.h ���Ͽ� ���� ���������� define �Ǿ� �ִ�.
		�ҽ� ���Ͽ��� ���ҽ� ���̵� �ν����� ���� ���� ������Ͽ� �ùٸ��� define�Ǿ� �ִ��� Ȯ���մϴ�.

		WndEx.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(Ŀ�� ���̵�));
		WndEx.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(������ ���̵�));
	*/

	// WNDCLASSEX�� ������ ������ �������Ϳ� ����Ѵ�.
	RegisterClassEx(&WndEx);

	// �����츦 �����Ѵ�.
	g_hWnd = CreateWindowEx(NULL,				// �������� ��Ÿ���� �����Ѵ�.
		szClass,					// �������� Ŭ������ �����Ѵ�.
		szTitle,					// �������� ĸ���� �����Ѵ�.
		WS_OVERLAPPEDWINDOW,		// �������� ��Ÿ���� �����Ѵ�.
		0,							// �������� x��ǥ ��ġ�� �����Ѵ�.
		0,							// �������� y��ǥ ��ġ�� �����Ѵ�.
		800,						// �������� ���̸� 320���� �����Ͽ���.
		600,						// �������� ���̸� 300���� �����Ͽ���.
		NULL,						// �����츦 �����ϰ� �ִ� �ٸ� �����찡 �����Ƿ� NULL ������ �����Ͽ���.
		NULL,						// �޴��� �����Ƿ� NULL ������ �����Ͽ���.
		hInstance,					// �ν��Ͻ� �ڵ��� �����Ѵ�.
		NULL);						// �� ������ �ʴ´�.

// �����찡 ������ ������ ���¸� �����Ѵ�.
	ShowWindow(g_hWnd, nShowCmd);
	// �����츦 �����ϰ� WM_PAINT �޽����� ȣ���Ѵ�.
	UpdateWindow(g_hWnd);

	// �޽��� ó���� ���� �ݺ��� ����
	while (TRUE)
	{
		// �޽��� ť�� ���� �޽����� �ִ��� Ȯ���Ѵ�.
		if (PeekMessage(&mSg, NULL, 0, 0, PM_NOREMOVE))
		{
			// ���� �޽����� ������ MSG ����ü���� �޽����� �о�´�.
			if (!GetMessage(&mSg, NULL, 0, 0))
				break;	// �޽��� �߿� WM_QUIT�޽����� ������ ����������.
			// ����Ű�� �߻��ϸ� �� �޽����� �޾ƿͼ� WM_CHAR�� �ش��ϴ� �ڵ带 ���� ���α׷��� �޽��� ť�� �־� �д�.
			TranslateMessage(&mSg);
			// �� �޽������� ó���ϱ� ���� WndProc() �Լ��� ������.
			DispatchMessage(&mSg);
		}
	}

	// ��Ÿ �μ����� �޽����� ��ȯ�Ѵ�.
	return mSg.wParam;
}

// �޽����� ó���ϱ� ���ؼ� �޽��� ó�� �Լ��� �����Ѵ�.
LRESULT CALLBACK WndProc(HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	// uMsg �������� DispatchMessage() �Լ����� ���� �޽������� ����Ǿ� �ִ�.
	switch (uMsg)
	{
		// �������� �޴��� Ŭ�� �Ǿ����� ���޵Ǵ� �޽���.
	case WM_COMMAND:
		// ���޵� ����Ÿ�� ���� ����� �߶� ...
		switch (LOWORD(wParam))
		{
			// �޴��� [File] -> [Start]�� Ŭ���Ǹ�...(����Ű alt + F + S �������...)
		case FILE_START:
			if (PlayerState == DEAD)
			{
				SetTimer(hWnd, 4, 15000, NULL);
				// ��� ������ ����� �ʱ�ȭ�Ѵ�.
				InitBackGround();
				// �� �Լ��� �̿��Ͽ� 1�� �� ���� �簢���� ����Ѵ�. �� ��� ���� �׸���.
				DrawBackGround();
				// �÷��̾� ���¸� �ʱ�ȭ �Ѵ�.(ALIVE)
				PlayerState = ALIVE;
				// ���� ������ ���� �����Ѵ�.
				NextBlockNum = rand() % 7;
				// ������ �� ���� �� ä������ ��� (����)
				FullLineNum = 0;
				holdBlockNum = -1;

				// �޽����� �߻� ��Ų��.
				SendMessage(hWnd, WM_NewBlock, 0, 0);
			}

			// Ÿ���� ON �̸�
			if (bTime == ON)
			{
				// �ش� ���̵� Ÿ�̸Ӹ� ����(����)�Ѵ�.
				KillTimer(hWnd, 3);
				bTime = OFF;
			}
			else
			{
				// Ÿ�̸Ӹ� ��ġ...�� �ش� ���̵�� Ÿ�̸Ӹ� ����Ѵ�.(�����Ѵ�.)
				// Ÿ�̸��� ���̵�� wParam�� ����ȴ�.(�޽��� �߻���...)
				SetTimer(hWnd, 3, 1000, NULL); // 1�ʸ��� WM_TIMER �޽��� �߻�.(?)
				// Ÿ���� ON���� ����
				bTime = ON;
			}
			break;
			// �޴��� [File] -> [EXIT]�� Ŭ���Ǹ�...(����Ű alt + F + E �������...)
		case FILE_EXIT:
			// �����츦 ����(�ı�)�Ѵ�.
			DestroyWindow(hWnd);
			break;
		}
		return FALSE;

		/* �� �޽����� ���ο� ������ ���� �� �߻��Ѵ�.
		   ���⼭�� ���ο� ������ �Ա��� �׷��ְ�
		   ���� ���� ���� �������� �����ʿ� �׷��ش�.*/
	case WM_NewBlock:
		// ������ ���� x��ǥ
		NowX = 4;
		// ������ ���� y��ǥ
		NowY = 0;
		// ������ ȸ�� ���� (�⺻�� ����)
		RotateNum = 0;
		// �̹��� ���� ����
		BlockNum = NextBlockNum;
		// ������ ���� ����
		NextBlockNum = rand() % 7;

		// �� ������ �Ա��� �׸���.
		DrawGhost();
		DrawBlock();
		// ������ ���� ������ �׸���.
		DrawNextBlock();



		/*
			�� ������ ���� �� ������
			��! ������ �Ա����� ���� �� ������...
		*/
		if (!BlockCanMove(NowX, NowY))
			// ������ �����Ѵ�.
			PlayerState = DEAD;

		return FALSE;

		// Ű������ Ű�� Ŭ���Ǹ�
	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
			// ����Ű LEFT
		case VK_LEFT:
			// ���� ���� �̵�
			LeftMove();
			break;
			// ����Ű RIGHT
		case VK_RIGHT:
			// ���� ���� �̵�
			RightMove();
			break;
			// ���� Ű
		case VK_UP:
			// ���� ȸ��
			Rotate();
			break;
			// ����Ű DOWN
		case VK_DOWN:
			// ���� ������
			DownMove();
			break;
			// SPACEŰ
		case VK_SPACE:
			// ���� �ѹ��� ������
			while (DownMove());
			break;
		case VK_RETURN:
			if (!holdUse)
				BlockHold();
			break;
		}

		return FALSE;

		// WM_TIMER �޽����� �߻��ϸ� (���� �ð� �������� �޽����� ����...(1000�� 1�ʴ�))
	case WM_TIMER:
		// �÷��̾ ��������� 
		switch (wParam)
		{
		case 3:
			if (PlayerState == ALIVE)
				// ������ �Ʒ��� ��� ������.
				DownMove();
			else
			{
				// Ÿ�� ������ ON �϶�
				if (bTime == ON)
				{
					// ���� ������ ���� ����
					bTime = OFF;
					// �ش� ���̵� Ÿ�̸Ӹ� ����(����)�Ѵ�.
					KillTimer(hWnd, 3);
				}
			}

			return FALSE;
		case 4:
			if (PlayerState == ALIVE)
				InsertLine();
			return FALSE;
		}


		// uMsg ������ WM_DESTROY�޽����� ������
	case WM_DESTROY:
		// ���� �� Ÿ�� ON �϶�
		if (bTime == ON)
			// �ش� ���̵� Ÿ�̸Ӹ� �����Ѵ�.
			KillTimer(hWnd, 3);

		// �����츦 �����Ѵ�.
		PostQuitMessage(0);

		return FALSE;
	}
	// ��ó ó������ ���� �޽������� WndProc�Լ��� ������ Ȯ���� ó���Ǿ������� �Ѵ�.
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// �Ʒ��� �Լ��� ����� ���� �Լ��μ� ��� ������ ����� �ʱ�ȭ�Ѵ�.
// �� �Լ��� �Լ��� ������ �����̴� ������ ����� �ִ� ������ �ſ� �߿��ϴ�.
void InitBackGround()
{
	// �� ������ ���� �ʱ�ȭ�� �Ѵ�./////////////////////////////////
	InvalidateRect(g_hWnd, NULL, TRUE);
	// UpdateWindow ���ϸ� ����� �ȱ׷��� �׽�Ʈ �غ���~���� �˱�~
	UpdateWindow(g_hWnd);

	// ��� 0���� �ʱ�ȭ
	for (int row = 0; row < 21; row++)
		for (int col = 0; col < 12; col++)
		{
			BackGround[row][col] = 0;
		}
	///////////////////////////////////////////////////////////////

	// �Ʒ� �� �ݺ����� ��� ������ ���� �����Ѵ�.
	for (int row = 0; row < 21; row++)
		for (int col = 0; col < 12; col++)
		{
			/*
				row���� 20�̸� BackGround[row][col] ���� 1�� �ִ´�. �� ����� ������ �׷��ش�.
				�׸��� ���� ������ ���� ������ ����� ���ϵ��� �ؾ� �Ѵ�.
			*/
			if (row == 20)
				BackGround[row][col] = 1;
			/*
				col ���� 0�̸� BackGround[row][col] ���� 1�� �ִ´�. �� ����� ���� ���� �׷��ش�.
				�׸��� ���� ������ ���� �ٹ����� ����� ���ϵ��� �ؾ� �Ѵ�.
			*/
			else if (col == 0)
				BackGround[row][col] = 1;
			/*
				col ���� 11�̸� BackGround[row][col] ���� 1�� �ִ´�. �� ����� ������ ���� �׷��ش�.
				�׸��� ���� ������ ������ �ٹ����� ����� ���ϵ��� �ؾ� �Ѵ�.
			*/
			else if (col == 11)
				BackGround[row][col] = 1;
			/*
				���� if���� �ش����� ������ ��� 0 ���� �ִ´�. 0 ���� �� ���� ������ ������ �����̴�.
				�׸��� ������ ���� ������ �� 0���� �������� �����ϼ� �ֵ��� ��� �� ������ �Ѵ�.
			*/
			else
				BackGround[row][col] = 0;
		}

}

// �Ʒ��� �Լ��� ��� ������ ����� �׸���. 
void DrawBackGround()
{
	// ����̽� ���ؽ�Ʈ�� ���� �� 
	// ������ Ŭ���̾�Ʈ ������ ���÷��� ����̽� ���ؽ�Ʈ(DC) �ڵ��� ���ؼ� ��ȯ�ؼ� ����..
	HDC hDC = GetDC(g_hWnd);
	// ���� �簢���� �׸��� ���ȴ�.
	HPEN hPen, hOldPen;
	// �귯���� �簢���� ä�ﶧ ���ȴ�.
	HBRUSH hBrush, hOldBrush;
	int x, y;

	// �ʷϻ� ��
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	// �ʷϻ� �귯��
	hBrush = CreateSolidBrush(RGB(255, 255, 255));

	/*
		SelectObject �Լ��� ��ü ������ GDI Object�� Bitmap, Pen,
		Brush, Font, Region �̴�. �׷��� Bitmap�� ��쿡��
		DC�� �޸�(Memory) DC�� ��쿡�� Bitmap ��ü�� �����ġ��
		���� ������ �Ǿ� �־ Bitmap ��ü�� ��ü�� �� �����ϴ�.
		�׸��� �� �Լ��� GDI Object ��ü �۾��� �����Ǹ� DC�� ������
		����ϰ� �ִ� GDI Object�� �ڵ� ���� ��ȯ�ϰ� �����ϸ� NULL
		���� ��ȯ�մϴ�.
		���� ���, SelectObject �Լ��� ����ؼ� Brush Object�� ��ü�ϴ�
		���, ���� ���� Brush ��ü�� �ڵ� ���� 0x10000012�̰� ������ DC��
		����Ǿ� �ִ� Brush ��ü�� �ڵ� ���� 0x30000412�� ��쿡 SelectObject
		�Լ��� ����ϰ� ���� DC�� Brush Object �ڵ� ���� 0x10000012���� ����
		�ȴٴ� ���Դϴ�. �׸��� 0x30000412 ���� SelectObject �Լ��� ��ȯ ���� ��!!!!~~~~
		�׷��� SelectObject �Լ��� ���� '�� ��° �Ű� ����'�� '��ȯ' �ڷ����� HGDIOBJ�Դϴ�.
		������ ��� �Ǵ� �ڷ����� HBITMAP, HPEN, HBRUSH �׸��� HFONT�ε� ���̴�. �̰���
		�� GDI Object ���� ��ü �Լ��� ����� �Լ��� �������� GDI Object �� ���Ӱ� �߰��Ǵ�
		��� ���ο� �Լ��� ������ �ϴ� �����Ե� ����� ������ �̷� �ڵ� �ڷ����� ������ �� �ִ�
		HGDIOBJ�� �߰��� ���� ����ϴ� ���Դϴ�. �ᱹ HGDIOBJ �ڷ����� HBITMAP, HPEN, HBRUSH
		�׸��� HFONT�� ���� �ڷ���ó�� ó���Ǵ� ���Դϴ�.(���)
		�׷��� SelectObject�Լ��� �� ��° �Ű� ������ HGDIOBJ�ӿ��� ���� ���޽� Ư���� �� ��ȯ(type casting)
		���̵� �״�� ����� �� �ִ� ���Դϴ�.

		ex)
			// �Ķ��� Brush ��ü ����
			HBRUSH h_brush = CreateSolidBrush(RGB(0, 0, 255));
			// HBRUSH ������ HGDIOBJ�� ���� ����
			HGDIOBJ h_gdiobj = h_brush;

			������ �Ʒ��� ���� HGDIOBJ ���� HBITMAP, HPEN, HBRUSH �Ǵ� HFONT�� �����ϴ� ��� �� ��ȯ��
			������� ������ ������ �߻��Ѵ�.
			// �Ķ��� Brush ��ü ����
			HBRUSH h_brush = CreateSolidBrush(RGB(0, 0, 255));
			// HBRUSH ������ HGDIOBJ�� ���� ����
			HGDIOBJ h_gdiobj = h_brush;
			// ���� �߻�
			HBRUSH check = h_gdiobj;
			errir C2440: '�ʱ�ȭ ��': 'HGDIOBJ'���� 'HBRUSH'(��)�� ��ȯ�� �� ����.

			�� ������ �ذ��Ϸ��� �Ʒ��� ���� ��Ȯ�� �ڵ� �ڷ������� �� ��ȯ�� �ؾ� �Ѵ�.

			// �Ķ��� Brush ��ü ����
			HBRUSH h_brush = CreateSolidBrush(RGB(0, 0, 255));
			// HBRUSH ������ HGDIOBJ�� ���� ����
			HGDIOBJ h_gdiobj = h_brush;
			// ����ȯ�� ����ϸ� ���� �ذ�~!
			HBRUSH check = (HBRUSH)h_gdiobj;

			(����) SelectObject �Լ��� ��ȯ ���� HGDIOBJ �ڷ������� �޾Ҵµ� SelectObject
			�Լ��� ���ؼ� ��ȯ�Ǵ� ���� Brush ��ü�� �ڵ� ���� �и��� ���... ������ HBRUSH
			������ �����ϰ� �; �Ʒ��� ���� ����ϸ� C2440 ������ �߻�~.

			HDC h_dc = ::GetDC(m_hWnd);
			HBURSH h_brush = CreateSolidBrush(RGB(0, 0, 255));
			// ����!
			HBRUSH h_old_brush = selectObject(h_dc, h_brush);

			�� ������ �Ʒ��� ���� �� ��ȯ�� ����ؼ� �ذ��ϸ� ��.
			HDC h_dc = ::GetDC(m_hWnd);
			HBURSH h_brush = CreateSolidBrush(RGB(0, 0, 255));
			// ���� ����!
			HBRUSH h_old_brush = (HBRUSH)selectObject(h_dc, h_brush);

	*/

	// ���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �� �ڵ��� ����.
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �귯�� �ڵ��� ����.
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	// �Ʒ� �� �ݺ����� ��� ������ ���� �˻��Ѵ�.
	for (int row = 0; row < 21; row++) // ��
		for (int col = 0; col < 12; col++) // ��	
			// ���� �迭�� ���� 1�̸�...
			if (BackGround[row][col] == 1)
			{
				// ��� ������ ��ġ�� ���� (�簢���� �ϳ��� ũ�Ⱑ 10�̴� *10 ���ش�)
				x = 320 + col * 15;		// ����� x ������ 100 ��ŭ ����� �����Ѵ�.
				y = row * 15;
				// �ش� ��ġ�� �ش� ũ���(10) �簢���� ����Ѵ�.
				Rectangle(hDC, x, y, x + 15, y + 15);
			}

	// ���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldBrush);

	// ��, �귯�� ��ü�� �����Ѵ�.
	DeleteObject(hPen);
	DeleteObject(hBrush);

	// ����̽� ���ؽ�Ʈ�� �ݳ��Ѵ�.
	ReleaseDC(g_hWnd, hDC);

	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));

	hDC = GetDC(g_hWnd);

	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	Rectangle(hDC, 550, 150, 620, 215);

	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);

	DeleteObject(hPen);
	DeleteObject(hBrush);

	ReleaseDC(g_hWnd, hDC);

}

// �Ʒ��� �Լ��� ����� ���� �Լ��μ� ������ ����� �׸���. 
void DrawBlock()
{
	// ����̽� ���ؽ�Ʈ�� ���� �� 
	// ������ Ŭ���̾�Ʈ ������ ���÷��� ����̽� ���ؽ�Ʈ(DC) �ڵ��� ���ؼ� ��ȯ�ؼ� ����..
	HDC hDC = GetDC(g_hWnd);
	// ���� �簢���� �׸��� ���ȴ�.
	HPEN hPen, hOldPen;
	// �귯���� �簢���� ä�ﶧ ���ȴ�.
	HBRUSH hBrush, hOldBrush;
	int x, y;

	// �ʷϻ� ��
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	// ��� �귯��
	hBrush = CreateSolidBrush(RGB(255, 255, 255));

	// ���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �� �ڵ��� ����.
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �귯�� �ڵ��� ����.
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	// �Ʒ� �� �ݺ����� ������ ���� �˻��Ѵ�.
	for (int row = 0; row < 4; row++) // ��
		for (int col = 0; col < 4; col++) // ��
			// ���� �迭�� ���� 1�̸�...
			if (Block[BlockNum][RotateNum][row][col] == 1) // BlockNum�� ������ ����, RotateNum�� ������ ȸ�� ����
			{
				// ������ ��ġ�� ���� (�簢���� �ϳ��� ũ�Ⱑ 10�̴� *10 ���ش�)
				x = 335 + NowX * 15 + col * 15; // 110(�⺻) + NowX * 10 ���� ����ϴ� ������ ���̸� �����Ͽ� �� ��ġ����~.
				y = NowY * 15 + row * 15;       // NowY * 10 ���� ����ϴ� ������ ���̸� �����Ͽ� �� ��ġ����~.
				// �ش� ��ġ�� �ش� ũ���(10) �簢���� ����Ѵ�.
				Rectangle(hDC, x, y, x + 15, y + 15);
			}

	/*
		�� �����ϰ� �����ϸ� �ȴ�. ������ ����� ����� ���ؼ� �迭�� ���� 0�̸�
		�ƹ� �͵� ������� �ʰ� 1�̸� �簢���� ����Ͽ� ��°�� ���� ������ ����� ���̴�.
	*/

	// ���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldBrush);

	// ��, �귯�� ��ü�� �����Ѵ�.
	DeleteObject(hPen);
	DeleteObject(hBrush);

	// ����̽� ���ؽ�Ʈ�� �ݳ��Ѵ�.
	ReleaseDC(g_hWnd, hDC);

}

// ������ ����
void EraseBlock()
{
	// ����̽� ���ؽ�Ʈ�� ���� �� 
	// ������ Ŭ���̾�Ʈ ������ ���÷��� ����̽� ���ؽ�Ʈ(DC) �ڵ��� ���ؼ� ��ȯ�ؼ� ����..
	HDC hDC = GetDC(g_hWnd);
	// ���� �簢���� �׸��� ���ȴ�.
	HPEN hPen, hOldPen;
	// �귯���� �簢���� ä�ﶧ ���ȴ�.
	HBRUSH hBrush, hOldBrush;
	int x, y;

	// ������ �� (��� �������� ����)
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	// ������ �귯�� (��� �������� ����)
	hBrush = CreateSolidBrush(RGB(0, 0, 0));

	// ���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �� �ڵ��� ����.
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �귯�� �ڵ��� ����.
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	// �Ʒ� �� �ݺ����� ������ ���� �˻��Ѵ�.
	for (int row = 0; row < 4; row++) // ��
		for (int col = 0; col < 4; col++) // ��
			// ���� �迭�� ���� 1�̸�...
			if (Block[BlockNum][RotateNum][row][col]) // BlockNum�� ������ ����, RotateNum�� ������ ȸ�� ���� (==1 ��� ���� �ǹ��̴�. �� true�� 1)
			{
				// ������ ��ġ�� ���� (�簢���� �ϳ��� ũ�Ⱑ 10�̴� *10 ���ش�)
				x = 335 + NowX * 15 + col * 15; // 110(�⺻) + NowX * 10 ���� ����ϴ� ������ ���̸� �����Ͽ� �� ��ġ����~.
				y = NowY * 15 + row * 15;       // NowY * 10 ���� ����ϴ� ������ ���̸� �����Ͽ� �� ��ġ����~.
				// �ش� ��ġ�� �ش� ũ���(10) �簢���� ����Ѵ�.
				Rectangle(hDC, x, y, x + 15, y + 15);
			}

	// ���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldBrush);

	// ��, �귯�� ��ü�� �����Ѵ�.
	DeleteObject(hPen);
	DeleteObject(hBrush);

	// ����̽� ���ؽ�Ʈ�� �ݳ��Ѵ�.
	ReleaseDC(g_hWnd, hDC);
}

// ���� ������ �׸���.
void DrawNextBlock()
{
	holdUse = FALSE;
	// ���� ������ ����� �׸���.

	// ����̽� ���ؽ�Ʈ�� �����Ѵ�.
	HDC hDC;
	// ���� �簢���� �׸��� ���ȴ�.
	HPEN hPen, hOldPen;
	// �귯���� �簢���� ä�ﶧ ���ȴ�.
	HBRUSH hBrush, hOldBrush;

	int x, y;

	// �ʷϻ� ��
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	// ������ �귯�� (��� �������� ����)
	hBrush = CreateSolidBrush(RGB(0, 0, 0));

	// ������ Ŭ���̾�Ʈ ������ ���÷��� ����̽� ���ؽ�Ʈ(DC) �ڵ��� ���ؼ� ��ȯ�Ѵ�.
	hDC = GetDC(g_hWnd);

	// ���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �� �ڵ��� ����.
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �귯�� �ڵ��� ����.
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	// �ش� ��ġ�� �ش� ũ��� �簢���� ����Ѵ�.
	Rectangle(hDC, 550, 45, 620, 110);

	// ���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldBrush);

	// ��, �귯�� ��ü�� �����Ѵ�.
	DeleteObject(hPen);
	DeleteObject(hBrush);

	// ����̽� ���ؽ�Ʈ�� �ݳ��Ѵ�.
	ReleaseDC(g_hWnd, hDC);

	// ���� ������ �׸���.
	// �ʷϻ� ��
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	// ��� �귯��
	hBrush = CreateSolidBrush(RGB(255, 255, 255));

	// ������ Ŭ���̾�Ʈ ������ ���÷��� ����̽� ���ؽ�Ʈ(DC) �ڵ��� ���ؼ� ��ȯ�Ѵ�.
	hDC = GetDC(g_hWnd);

	// ���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �� �ڵ��� ����.
	hOldPen = (HPEN)SelectObject(hDC, hPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ְ� ��ȯ�� ���� �귯�� �ڵ��� ����.
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	// �Ʒ� �� �ݺ����� ������ ���� �˻��Ѵ�.
	for (int row = 0; row < 4; row++) // ��
		for (int col = 0; col < 4; col++) // ��
		{
			// ���� �迭�� ���� 1�̸�...
			if (Block[NextBlockNum][RotateNum][row][col]) // BlockNum�� ������ ����, RotateNum�� ������ ȸ�� ���� (==1 ��� ���� �ǹ��̴�. �� true�� 1)
			{
				// ������ ��ġ�� ���� (�簢���� �ϳ��� ũ�Ⱑ 10�̴� *10 ���ش�)
				x = 560 + col * 15;		 // ������ x �� �������� 250(�⺻) ��ġ�� ���
				y = 50 + row * 15;       // ������ y �� ��������  50(�⺻) ��ġ�� ���
				// �ش� ��ġ�� �ش� ũ���(10) �簢���� ����Ѵ�.
				Rectangle(hDC, x, y, x + 15, y + 15);
			}
		}

	// ���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldPen);
	// �귯���� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hDC, hOldBrush);

	// ��, �귯�� ��ü�� �����Ѵ�.
	DeleteObject(hPen);
	DeleteObject(hBrush);

	// ����̽� ���ؽ�Ʈ�� �ݳ��Ѵ�.
	ReleaseDC(g_hWnd, hDC);
}

// ������ �̵� �������� ���� üũ
BOOL BlockCanMove(int x, int y)
{
	// üũ ����
	int check = 0;

	// ��, ��
	int row, col;

	// �Ʒ� �� �ݺ����� ������ ���� �˻��Ѵ�.
	for (row = 0; row < 4; row++) // ��
		for (col = 0; col < 4; col++) // ��
			if (Block[BlockNum][RotateNum][row][col]) // BlockNum�� ������ ����, RotateNum�� ������ ȸ�� ���� (==1 ��� ���� �ǹ��̴�. �� true�� 1)
				check += BackGround[y + row][x + col + 1]; // ������ ��� ��迡 �ɸ���...üũ ���� 1 �߰�

	// �̵� ����
	if (check == 0)
		return YES;
	// �̵� �Ұ���
	else
		return NO;
}

// ���� ���� �̵�.
void LeftMove()
{
	// �÷��̾ �׾�����
	if (PlayerState == DEAD)
		return;

	// �׷��� �ʴٸ� ���� ���� �̵�
	if (BlockCanMove(NowX - 1, NowY))
	{
		// ������ �����
		EraseGhost();
		EraseBlock();
		// ���� ��ġ �̵� ��Ű��
		NowX--;
		// ������ �ٽ� �׸���.
		DrawGhost();
		DrawBlock();
	}
}

// ���� ���� �̵�.
void RightMove()
{
	// �÷��̾ �׾�����
	if (PlayerState == DEAD)
		return;

	// �׷��� �ʴٸ� ���� ���� �̵�
	if (BlockCanMove(NowX + 1, NowY))
	{
		// ������ �����
		EraseGhost();
		EraseBlock();
		// ���� ��ġ �̵� ��Ű��
		NowX++;
		// ������ �ٽ� �׸���.
		DrawGhost();
		DrawBlock();

	}
}

// ���� ȸ�� �Լ�
void Rotate()
{
	// �÷��̾ �׾�����
	if (PlayerState == DEAD)
		return;

	// ���� �� �ӽ� ������ ����
	int temp = RotateNum;
	// RotateNum �� 1 ����
	RotateNum++;
	// ������ �Ѱ� ���� 3������ ���� ����(if �Ƚᵵ �� ��ų�̴� ����صα�)
	RotateNum %= 4;

	// ȸ���� ���� �ϸ�
	if (BlockCanMove(NowX, NowY))
	{
		// ����
		RotateNum = temp;
		// ������ �����
		EraseGhost();
		EraseBlock();
		// RotateNum �� 1 ����
		RotateNum++;
		// ������ �Ѱ� ���� 3������ ���� ����(if �Ƚᵵ �� ��ų�̴� ����صα�)
		RotateNum %= 4;
		// ȸ���� ���� �׸���
		DrawGhost();
		DrawBlock();

	}
	// ȸ���� �Ұ��� �ϸ� ����
	else if (NowX > 4)
	{
		RotateNum = temp;
		EraseGhost();
		EraseBlock();

		NowX--;
		if (BlockNum == 0)
			NowX--;
		RotateNum++;
		RotateNum %= 4;
		DrawGhost();
		DrawBlock();

	}
	else
	{
		RotateNum = temp;
		EraseGhost();
		EraseBlock();
		NowX++;
		RotateNum++;
		RotateNum %= 4;
		DrawGhost();
		DrawBlock();
	}
}

// ���� �ٿ� �Լ�
BOOL DownMove()
{
	// �÷��̾ �׾�����
	if (PlayerState == DEAD) return FAIL;

	// ������ �Ʒ��� ���� ���� �ִٸ�(�̸� üũ)
	if (BlockCanMove(NowX, NowY + 1))
	{
		// ������ �����
		EraseBlock();
		// ���� ��ġ �̵� ��Ű��
		NowY++;
		// ������ �ٽ� �׸���.
		DrawBlock();
		return SUCCESS;
	}
	// ������ �Ʒ��� ���� �� �� ���ٸ�
	else
	{
		// �����ϼ� ���� ������ ������� ������Ʈ.
		UpdateBackGround();
		// ������ �� ���ִ��� �˻�.(�̼� �������� �˻�)
		CheckFullLine();
		// �޽����� �߻� ��Ų��.(���� ���� ����)
		SendMessage(g_hWnd, WM_NewBlock, 0, 0);
		return FAIL;
	}
}

// �����ϼ� ���� ������ ������� ������Ʈ.
void UpdateBackGround()
{
	// ��� ����
	int element;
	// �Ʒ� �� �ݺ����� ������ ���� �˻��Ѵ�.
	for (int row = 0; row < 4; row++) // ��
		for (int col = 0; col < 4; col++) // ��
		{
			// ���� ������ ��� ���� �����Ѵ�.
			element = Block[BlockNum][RotateNum][row][col];
			// ���� ���� ���� �迭�� ���� 1 �̸�, 
			// ���� �迭�� ���� ���� ���� ��ġ�� ������� ����~!.
			if (element)
				BackGround[NowY + row][NowX + col + 1] = element;
		}
}

// ���� �Ǵ� �� �̻� �̼��� �����ߴ��� üũ  
void CheckFullLine()
{
	// ��, ��, ���� ����
	int row, col, line;
	// �̼� üũ ����
	int elementNum;

	// ���Һ��� �˻�...
	for (row = 19; row >= 0; row--)
	{
		// �̼� üũ ���� �ʱ�ȭ
		elementNum = 0;
		// �ش� ��, ���� ��� ������ elementNum ���� ����
		for (col = 1; col <= 10; col++)
			elementNum += BackGround[row][col];

		// ������ ���� ü���� �ִ��� �˻��Ѵ�.
		if (elementNum == 10)
		{
			// ���� �� ���� �ٷ� �� ���κ��� ��� �صΰ�~
			for (line = row; line > 0; line--)
				for (col = 1; col <= 10; col++)
					BackGround[line][col] = BackGround[line - 1][col];


			// ��ĭ �������Ŵϱ� �� ���� ����(?)
			//for (col = 1; col <= 10; col++)
			//	BackGround[0][col] = 0;

			// ������ ������ ���� �����Ѵ�.
			EraseFullLine(row);
			// ������ �ɼ��� �ִ�~(��ó��)(?)(�̼�)
			FullLineNum++;
			// 2�� �̻��� ���� ��츦 ���
			row++;
		}
	}
}

// ������ ������ ���� �����ϴ� �Լ�.(������ ����� �Լ�)
void EraseFullLine(int row)
{
	// ����̽� ���ؽ�Ʈ�� �����Ѵ�.
	HDC hDC, hMemDC;
	// ��Ʈ���� �ڵ��� �����ϱ� ����.
	HBITMAP hBmp;

	// �Ѹ���� 100..���� �̾� ����ϸ鼭 �ϴٺ���...
	int Xlen = 300;

	/* ������ ������ Ylen�� ���� ������ ������ ���� �ٷ� ������
	�� �����̴�.
	row�� 0���� �����ϹǷ� row*10�� full line�� �ٷ� �������� ����
	�̴�.
	��! full line�� 10��° ���̶�� �� ������ y ������
	90~99�̴�. �̶� row=9�̰� ������ �κ��� y������ 0~89���� �̴�.*/

	// �Ѹ���� ù ���κ��� ���� ���� ������ �����̴�. (ZeroBase)(�� ���� ����� �׳� �̰͸� ���)
	int Ylen = row * 15;

	// ������ Ŭ���̾�Ʈ ������ ���÷��� ����̽� ���ؽ�Ʈ(DC) �ڵ��� ���ؼ� ��ȯ�Ѵ�.
	hDC = GetDC(g_hWnd);
	// �־��� ����̽��� ȣȯ�Ǵ� �޸� ����̽� ���ؽ�Ʈ�� �����Ѵ�.
	hMemDC = CreateCompatibleDC(hDC);
	// ��Ʈ���� �����Ѵ�. 
	hBmp = CreateCompatibleBitmap(hDC, 200, 300); // ����� ũ��� ��´�.
	// ��Ʈ���� �޸� ����̽� ���ؽ�Ʈ�� �ִ´�.
	SelectObject(hMemDC, hBmp);

	/*
	 �Լ� ����
	BOOL BitBlt(
	HDC hdcDest,
	int nXDest,
	int nYDest,
	int nWidth,
	int nHeight,
	HDC hdcSrc,
	int nXSrc,
	int nYSrc,
	DWORD dwRop);

	�μ�
	hdcDest
	�̹����� ����� ��ġ�� �ڵ�.

	nXDest, nYDest
	�̹����� ����� ��ġ�� x, y ��ǥ.

	nWidth, nHeight
	���� �̹����� �ʺ�, ���� �̴�.
	�� ũ�⸸ŭ ���� �̹������� �߶�� �׸���.

	hdcSrc
	�̹����� �ڵ�.

	nXSrc, nYSrc
	������ �̹����� ���������� x, y��ǥ�̴�.
	�� ��ġ���� nWidth, nHeight��ŭ �̹����� �߶�´�.

	dwRop
	�̹����� ��� ���

	*/

	// ȭ���� �Ϻθ� �޸𸮷� �����Ѵ�.
	//BitBlt(hMemDC, 0, 0, Xlen, Ylen, hDC, 110, 0, SRCCOPY);
	BitBlt(hMemDC, 0, 0, Xlen, Ylen, hDC, 320, 0, SRCCOPY);

	// �޸𸮿��� ȭ���� �ٸ� �κ����� �����Ѵ�.
	// ��! �ι�° �ٺ��� �����Ѵ�.
	//BitBlt(hDC, 110, 10, Xlen, Ylen, hMemDC, 0, 0, SRCCOPY);
	BitBlt(hDC, 320, 15, Xlen, Ylen, hMemDC, 0, 0, SRCCOPY);

	// (�޸�)����̽� ���ؽ�Ʈ(DC)�� ���ش�
	DeleteDC(hMemDC);
	// ����̽� ���ؽ�Ʈ�� �ݳ��Ѵ�.
	ReleaseDC(g_hWnd, hDC);
	// ��ü�� �����Ѵ�.
	DeleteObject(hBmp);
}

void DrawGhost()
{
	HDC hDC = GetDC(g_hWnd);
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;

	ghostChk = 0;

	while (TRUE)
	{
		if (!BlockCanMove(NowX, NowY + ghostChk + 1))
			break;
		ghostChk++;
	}

	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));

	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	for (int row = 0; row < 4; row++) // ��
		for (int col = 0; col < 4; col++) // ��
			if (Block[BlockNum][RotateNum][row][col] == 1) // BlockNum�� ������ ����, RotateNum�� ������ ȸ�� ����
			{
				x = 335 + NowX * 15 + col * 15; // 110(�⺻) + NowX * 10 ���� ����ϴ� ������ ���̸� �����Ͽ� �� ��ġ����~.

				y = (NowY + ghostChk) * 15 + row * 15;       // NowY * 10 ���� ����ϴ� ������ ���̸� �����Ͽ� �� ��ġ����~.
				Rectangle(hDC, x, y, x + 15, y + 15);
			}


	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);

	DeleteObject(hPen);
	DeleteObject(hBrush);

	ReleaseDC(g_hWnd, hDC);
}

void EraseGhost()
{
	HDC hDC = GetDC(g_hWnd);
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	int x, y;
	ghostChk = 0;

	while (TRUE)
	{
		if (!BlockCanMove(NowX, NowY + ghostChk + 1))
			break;
		ghostChk++;
	}

	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));

	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	for (int row = 0; row < 4; row++) // ��
		for (int col = 0; col < 4; col++) // ��
			if (Block[BlockNum][RotateNum][row][col]) // BlockNum�� ������ ����, RotateNum�� ������ ȸ�� ���� (==1 ��� ���� �ǹ��̴�. �� true�� 1)
			{
				x = 335 + NowX * 15 + col * 15; // 110(�⺻) + NowX * 10 ���� ����ϴ� ������ ���̸� �����Ͽ� �� ��ġ����~.

				y = (NowY + ghostChk) * 15 + row * 15;       // NowY * 10 ���� ����ϴ� ������ ���̸� �����Ͽ� �� ��ġ����~.
				Rectangle(hDC, x, y, x + 15, y + 15);
			}

	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);

	DeleteObject(hPen);
	DeleteObject(hBrush);

	ReleaseDC(g_hWnd, hDC);
}

void BlockHold()
{

	int temp;
	if (holdBlockNum == -1)
	{
		holdBlockNum = BlockNum;
		EraseGhost();
		EraseBlock();
		NowX = 4;
		NowY = 0;
		RotateNum = 0;
		BlockNum = NextBlockNum;
		NextBlockNum = rand() % 7;


		HDC hDC;
		HPEN hPen, hOldPen;
		HBRUSH hBrush, hOldBrush;

		int x, y;

		hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		hBrush = CreateSolidBrush(RGB(0, 0, 0));

		hDC = GetDC(g_hWnd);

		hOldPen = (HPEN)SelectObject(hDC, hPen);
		hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

		Rectangle(hDC, 550, 150, 620, 215);

		SelectObject(hDC, hOldPen);
		SelectObject(hDC, hOldBrush);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(g_hWnd, hDC);

		hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		hBrush = CreateSolidBrush(RGB(255, 255, 255));

		hDC = GetDC(g_hWnd);

		hOldPen = (HPEN)SelectObject(hDC, hPen);
		hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

		for (int row = 0; row < 4; row++) // ��
			for (int col = 0; col < 4; col++) // ��
			{
				if (Block[holdBlockNum][RotateNum][row][col]) // BlockNum�� ������ ����, RotateNum�� ������ ȸ�� ���� (==1 ��� ���� �ǹ��̴�. �� true�� 1)
				{
					// ������ ��ġ�� ���� (�簢���� �ϳ��� ũ�Ⱑ 10�̴� *10 ���ش�)
					x = 560 + col * 15;		 // ������ x �� �������� 250(�⺻) ��ġ�� ���
					y = 155 + row * 15;       // ������ y �� ��������  50(�⺻) ��ġ�� ���
					Rectangle(hDC, x, y, x + 15, y + 15);
				}
			}

		SelectObject(hDC, hOldPen);
		SelectObject(hDC, hOldBrush);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(g_hWnd, hDC);

		DrawGhost();
		DrawBlock();
		DrawNextBlock();
		holdUse = TRUE;

	}
	else {

		EraseGhost();
		EraseBlock();

		temp = holdBlockNum;
		holdBlockNum = BlockNum;
		BlockNum = temp;

		NowX = 4;
		NowY = 0;
		RotateNum = 0;


		HDC hDC;
		HPEN hPen, hOldPen;
		HBRUSH hBrush, hOldBrush;

		int x, y;

		hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		hBrush = CreateSolidBrush(RGB(0, 0, 0));

		hDC = GetDC(g_hWnd);

		hOldPen = (HPEN)SelectObject(hDC, hPen);
		hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

		Rectangle(hDC, 550, 150, 620, 215);

		SelectObject(hDC, hOldPen);
		SelectObject(hDC, hOldBrush);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(g_hWnd, hDC);

		hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		hBrush = CreateSolidBrush(RGB(255, 255, 255));

		hDC = GetDC(g_hWnd);

		hOldPen = (HPEN)SelectObject(hDC, hPen);
		hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

		for (int row = 0; row < 4; row++) // ��
			for (int col = 0; col < 4; col++) // ��
			{
				if (Block[holdBlockNum][RotateNum][row][col]) // BlockNum�� ������ ����, RotateNum�� ������ ȸ�� ���� (==1 ��� ���� �ǹ��̴�. �� true�� 1)
				{
					// ������ ��ġ�� ���� (�簢���� �ϳ��� ũ�Ⱑ 10�̴� *10 ���ش�)
					x = 560 + col * 15;		 // ������ x �� �������� 250(�⺻) ��ġ�� ���
					y = 155 + row * 15;       // ������ y �� ��������  50(�⺻) ��ġ�� ���
					Rectangle(hDC, x, y, x + 15, y + 15);
				}
			}

		SelectObject(hDC, hOldPen);
		SelectObject(hDC, hOldBrush);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(g_hWnd, hDC);

		DrawGhost();
		DrawBlock();
		holdUse = TRUE;
	}
}

//
//void BlockHoldRelease()
//{
//	holdHave = FALSE;
//	EraseGhost();
//	EraseBlock();
//
//	NowX = 4;
//	NowY = 0;
//
//	RotateNum = 0;
//
//
//	HDC hDC;
//	HPEN hPen, hOldPen;
//	HBRUSH hBrush, hOldBrush;
//
//	int x, y;
//
//	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
//	hBrush = CreateSolidBrush(RGB(0, 0, 0));
//
//	hDC = GetDC(g_hWnd);
//
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//
//	Rectangle(hDC, 550, 150, 620, 215);
//
//	SelectObject(hDC, hOldPen);
//	SelectObject(hDC, hOldBrush);
//
//	DeleteObject(hPen);
//	DeleteObject(hBrush);
//
//	ReleaseDC(g_hWnd, hDC);
//
//	BlockNum = holdBlockNum;
//	DrawBlock();
//	DrawGhost();
//	DrawNextBlock();
//
//}


void InsertLine()
{
	EraseGhost();
	EraseBlock();
	HDC hDC, hMemDC;
	HBITMAP hBmp;
	int row, col, x, y;
	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	for (row = 1; row < 20;row++) {
		for (col = 1;col < 11;col++)
		{
			if (BackGround[row][col])
				BackGround[row - 1][col] = BackGround[row][col];
			else
				BackGround[row - 1][col] = 0;
		}
	}

	while (1)
	{
		int sum=0;
		for (int i = 1; i < 11;i++)
		{
			BackGround[19][i] = rand() % 2;
			sum += BackGround[19][i];
		}
		if (sum > 7 && sum < 10)
			break;
	}

	int Xlen = 300;

	int Ylen = row * 15;

	hDC = GetDC(g_hWnd);
	hMemDC = CreateCompatibleDC(hDC);
	hBmp = CreateCompatibleBitmap(hDC, 200, 300); // ����� ũ��� ��´�.
	SelectObject(hMemDC, hBmp);
	BitBlt(hMemDC, 0, 0, Xlen, Ylen, hDC, 320, 0, SRCCOPY);

	BitBlt(hDC, 320, -15, Xlen, Ylen, hMemDC, 0, 0, SRCCOPY);

	DeleteDC(hMemDC);
	ReleaseDC(g_hWnd, hDC);
	DeleteObject(hBmp);

	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));

	hDC = GetDC(g_hWnd);

	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	for (int col = 1; col < 12; col++)
	{
		x = 320 + col * 15;
		y = 285;
		Rectangle(hDC, x, y, x + 15, y + 15);
	}


	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);

	DeleteObject(hPen);
	DeleteObject(hBrush);

	ReleaseDC(g_hWnd, hDC);


	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	hBrush = CreateSolidBrush(RGB(255, 255, 255));
	hDC = GetDC(g_hWnd);

	hOldPen = (HPEN)SelectObject(hDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	for (int col = 1; col < 12; col++) // ��	
		// ���� �迭�� ���� 1�̸�...
		if (BackGround[19][col] == 1)
		{
			// ��� ������ ��ġ�� ���� (�簢���� �ϳ��� ũ�Ⱑ 10�̴� *10 ���ش�)
			x = 320 + col * 15;		// ����� x ������ 100 ��ŭ ����� �����Ѵ�.
			y = 285;
			// �ش� ��ġ�� �ش� ũ���(10) �簢���� ����Ѵ�.
			Rectangle(hDC, x, y, x + 15, y + 15);
		}

	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldBrush);

	DeleteObject(hPen);
	DeleteObject(hBrush);

	ReleaseDC(g_hWnd, hDC);

	DrawBlock();
	DrawGhost();
}