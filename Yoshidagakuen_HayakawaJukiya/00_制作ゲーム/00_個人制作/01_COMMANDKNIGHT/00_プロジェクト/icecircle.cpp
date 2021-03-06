//=============================================================================
//
// 円の氷処理 [icecircle.cpp]
// Author : Jukiya Hayakawa
//
//=============================================================================
#include "icecircle.h"
#include "scene3D.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "debugproc.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TEXTURE_ICE "data\\TEXTURE\\IceCircle.png"			//テクスチャ名
//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
LPDIRECT3DTEXTURE9 CIceCircle::m_pTexture = NULL;

//=============================================================================
// オブジェクトのテクスチャ読み込み
//=============================================================================
HRESULT CIceCircle::Load(void)
{
	//レンダリングの取得
	CRenderer *pRenderer;
	pRenderer = CManager::GetRenderer();

	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = pRenderer->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\IceCircle.png",
		&m_pTexture);

	return S_OK;
}

//=============================================================================
// オブジェクトのテクスチャ破棄
//=============================================================================
void CIceCircle::Unload(void)
{
	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//=============================================================================
// ポリゴンのコンストラクタ
//=============================================================================
CIceCircle::CIceCircle() : CScene3D()
{
	m_nTimer = 140;	//タイマーの初期化処理
}
//=============================================================================
// ポリゴンのコンストラクタ
//=============================================================================
CIceCircle::~CIceCircle()
{

}
//=============================================================================
// ポリゴンの生成
//=============================================================================
CIceCircle *CIceCircle::Create(D3DXVECTOR3 pos)
{
	CIceCircle *pIceCircle = NULL;		//オブジェクトのポインタ

	if (pIceCircle == NULL)
	{
		pIceCircle = new CIceCircle;	//動的確保
		if (pIceCircle != NULL)
		{
			pIceCircle->SetPos(pos);				//位置の設置処理
			pIceCircle->Init();						//初期化処理
			pIceCircle->BindTexture(m_pTexture);	//テクスチャの貼り付け
		}
	}
	return pIceCircle;
}
//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CIceCircle::Init(void)
{
	//オブジェクト3Dの初期化処理
	CScene3D::Init();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CIceCircle::Uninit(void)
{
	//オブジェクト3Dの終了処理
	CScene3D::Uninit();

	//オブジェクトの破棄
	Release();
}

//=============================================================================
// 更新処理
//=============================================================================
void CIceCircle::Update(void)
{
	m_nTimer--;	//タイマーの減算処理

	if (m_nTimer <= 0)
	{//タイマーが０以下になった場合
		Uninit();
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CIceCircle::Draw(void)
{
	//オブジェクト3Dの描画処理
	CScene3D::Draw();
}