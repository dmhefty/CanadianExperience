/**
 * \file ChildView.cpp
 *
 * \author Team Sarson
 */

#include "pch.h"
#include "framework.h"
#include "Project1.h"
#include "ChildView.h"
#include <sstream>
#include <iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView


/**
 * Constructor
 */
CChildView::CChildView()
{
}

/**
 * Destructor
 */
CChildView::~CChildView()
{
}

/// \cond
/// This doxygen switch tells it to ignore this block of code
BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_OPEN32771, &CChildView::OnFileOpen)
END_MESSAGE_MAP()
/// \endcond



// CChildView message handlers


/**
* This function is called before the window is created.
* \param cs A structure with the window creation parameters
* \returns TRUE
*/
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

/**
* This function is called to draw in the window.
*
* This function is called in response to a drawing message
* whenever we need to redraw the window on the screen.
* It is responsible for painting the window.
*/
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}

/** Menu handler update for opening a file of data */
void CChildView::OnFileOpen()
{
	CFileDialog dlg(true,	// true = Open dialog box
		L".xml",			// Default file extension
		nullptr,			// Default file name (none)
		0,	// Flags
		L"XML Files (*.xml)|*.xml|All Files (*.*)|(*.*||");		// Filter
	if (dlg.DoModal() != IDOK)
		return;

	wstring filename = dlg.GetPathName();
	// mGame.Load(filename);
	// Invalidate;
}
