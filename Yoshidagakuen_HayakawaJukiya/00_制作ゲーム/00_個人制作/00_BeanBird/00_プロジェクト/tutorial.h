//=============================================================================
//
// チュートリアルの処理 [tutorial.h]
// Author : Jukiya Hayakawa
//
//=============================================================================
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include "main.h"

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CTutorial
{
public:
	//=========================================================================
	// 構造体の定義
	//=========================================================================

	//メンバ関数
	CTutorial();
	~CTutorial();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	//静的メンバ関数
	static CTutorial *Create(void);

private:
	int m_counter;
};
#endif