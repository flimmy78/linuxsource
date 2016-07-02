/*****************************************************************************
   ģ����      : mcu
   �ļ���      : vcsstruct.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: ��VCSͨ�����ýṹ��
   ����        : ���㻪
   �汾        : 
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2008/11/20              ���㻪      ����
******************************************************************************/
#ifndef __VCSSTRUCT_H_
#define __VCSSTRUCT_H_

#include "osp.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "kdvsys.h"
#include "mcuconst.h"
#include "kdvdef.h"
#include "vccommon.h"
#include "ummessagestruct.h"
#include "mcuerrcode.h"
#include "mcustruct.h"

#define MAX_HDTWDEVNUM      (u8)100        // �������õĸ������ǽģ����
#define MAX_HDTWCHANNUM     (u8)1          // ÿ���������ǽģ��֧�ֵ�ͨ����

//VCS�����еĵ���ǽ����ģʽ
#define VCS_TVWALLMANAGE_MANUAL_MODE	(u8)1//�ֶ�ģʽ
#define VCS_TVWALLMANAGE_AUTO_MODE		(u8)2//�Զ�ģʽ
#define VCS_TVWALLMANAGE_REVIEW_MODE	(u8)3//Ԥ��ģʽ

// ����ģʽ
#define VCS_SINGLE_MODE     (u8)1      // ��������ģʽ
#define VCS_MULTW_MODE      (u8)2      // �෽����ǽ����ģʽ
#define VCS_MULVMP_MODE     (u8)3      // �෽����ϳɵ���ģʽ
#define VCS_GROUPSPEAK_MODE (u8)4      // ���������ģʽ
#define VCS_GROUPTW_MODE    (u8)5      // �������ǽģʽ
#define VCS_GROUPVMP_MODE   (u8)6      // �������ϳ�ģʽ
#define VCS_GROUPCHAIRMAN_MODE (u8)7	//�����ϯģʽ
#define VCS_GROUPROLLCALL_MODE (u8)8	//�������ģʽ

// �����ն���������
#define VCS_DTYPE_MTID      (u8)1       // TMt
#define VCS_DTYPE_MTALIAS   (u8)2       // ����

// ������������
#define VCS_AUDPROC_MUTE    (u8)0      // ����
#define VCS_AUDPROC_SILENCE (u8)1      // ����

// ������������
#define VCS_OPR_LOCAL       (u8)0      // ��������
#define VCS_OPR_REMOTE      (u8)1      // ����Զ��

// VCS����Ŀ���
#define VCS_ENTRY_MT_MT             (u8)1
#define VCS_ENTRY_MT_MCU            (u8)6
#define VCS_ENTRY_MT_GROUP          (u8)7
#define VCS_ENTRY_MT_CALL_GROUP     (u8)8

// VCS�����ʱ�����ӵĺ����ն���
#define VCS_MAXNEWADDMT_NUM        (u8)192
// VCS���֧�ֵ������
#define VCS_MAXGROUPCALL_NUM       (u8)64
// VCS����������
#define MAX_VCSGROUPNAMELEN        (u8)32
// VCS������Ϣÿ������ֽ���25k
#define MAX_VCSPACKIFNOLEN         (u16)0x6000

// VCS���Ȳ�������
#define VCS_VCTYPE_DEFAULT         (u8)0
#define VCS_VCTYPE_DROPMT          (u8)1

// VCS����ǿ������
#define VCS_FORCECALL_REQ          (u8)0
#define VCS_FORCECALL_CMD          (u8)1
#define VCS_FORCECALL_CANCELCMD	   (u8)2

// VCS��ϯ��ѯ״̬
#define VCS_POLL_START             (u8)1
#define VCS_POLL_PAUSE             (u8)2
#define VCS_POLL_STOP              (u8)3

#define VCS_MAXLEN_ALIAS			(u8)80

#define VCS_MAXNUM_PLAN		(u8)16

typedef TMtAlias TSMCUAlias;            // �¼�MCU������Ϣ
typedef TMtAliasNoConstruct THDTWModuleAlias;      // �������ǽ����


//20091102Ϊ����ǽ�����е�Ԥ�����ƽṹ
struct TMtVcsPlanNames
{
	u8			m_byPlanNum;
	s8			m_achAlias[VCS_MAXNUM_PLAN][MAX_VCSGROUPNAMELEN];
}
PACKED
;

//20091102Ϊ����ǽ�����е�Ԥ���½��Ľṹ
//��ΪҪ�������ϴ��������¶���һ��TMtVCSAlias����TMtAliasΨһ���������m_achAlias�ֶδ�192�ֽڼ��ٵ�32�ֽ�
//�����ն˱����ṹ(len:39)
struct TMtVCSPlanAlias
{
public:
    u8				m_AliasType;               //��������
    s8				m_achAlias[VCS_MAXLEN_ALIAS];  //�����ַ���
    TTransportAddr	m_tTransportAddr;          //�����ַ
	u8				m_byReserve;
public:
	TMtVCSPlanAlias( void ){ memset( this, 0, sizeof(TMtVCSPlanAlias) ); }
	BOOL operator ==( const TMtVCSPlanAlias & tObj ) const;
	BOOL IsNull( void ) const { if( m_AliasType == 0 )return TRUE; return FALSE; }
	void SetNull( void ){ memset(this, 0, sizeof(TMtVCSPlanAlias)); }
	BOOL IsAliasNull( void ) const { return 0 == strlen(m_achAlias); }
	void SetE164Alias( LPCSTR lpzAlias )
	{
		if( lpzAlias != NULL )
		{
			m_AliasType = mtAliasTypeE164;
            memset( m_achAlias, 0, sizeof(m_achAlias));
			strncpy( m_achAlias, lpzAlias, VCS_MAXLEN_ALIAS-1 );
		}
	}
	void SetH323Alias( LPCSTR lpzAlias )
	{
		if( lpzAlias != NULL )
		{
			m_AliasType = mtAliasTypeH323ID;
            memset( m_achAlias, 0, sizeof(m_achAlias));
			strncpy( m_achAlias, lpzAlias, VCS_MAXLEN_ALIAS-1 );
		}
	}
	void SetH320Alias( u8 byLayer, u8 bySlot, u8 byChannel )
	{
		m_AliasType = mtAliasTypeH320ID;
		sprintf( m_achAlias, "��%d-��%d-ͨ��%d%c", byLayer, bySlot, byChannel, 0 );
	}
	BOOL GetH320Alias ( u8 &byLayer, u8 &bySlot, u8 &byChannel )
	{
		BOOL bRet = FALSE;
		byLayer   = 0;
		bySlot    = 0; 
		byChannel = 0; 
		if( mtAliasTypeH320ID != m_AliasType )
		{
			return bRet;
		}

		s8 *pachLayerPrefix   = "��";
		s8 *pachSlotPrefix    = "-��";
		s8 *pachChannelPrefix = "-ͨ��";
		s8 *pachAlias = m_achAlias;

		if( 0 == memcmp( pachAlias, pachLayerPrefix, strlen("��") ) )
		{
			s32  nPos = 0;
			s32  nMaxCHLen = 3; //һ�ֽڵ�����ִ�����
			s8 achLayer[4] = {0};

			//��ȡ���
			pachAlias += strlen("��");
			for( nPos = 0; nPos < nMaxCHLen; nPos++ )
			{
				if( '-' == pachAlias[nPos] )
				{
					break;
				}
				achLayer[nPos] = pachAlias[nPos];
			}
			if( 0 == nPos || nPos >= nMaxCHLen )
			{
				return bRet;
			}
			achLayer[nPos+1] = '\0';
			byLayer = atoi(achLayer);

			//��ȡ�ۺ�
			pachAlias += nPos;
			if( 0 == memcmp( pachAlias, pachSlotPrefix, strlen("-��") ) )
			{
				pachAlias += strlen("-��");
				for( nPos = 0; nPos < nMaxCHLen; nPos++ )
				{
					if( '-' == pachAlias[nPos] )
					{
						break;
					}
					achLayer[nPos] = pachAlias[nPos];
				}
				if( 0 == nPos || nPos >= nMaxCHLen )
				{
					return bRet;
				}
				achLayer[nPos+1] = '\0';
				bySlot = atoi(achLayer);
			
				//��ȡͨ����
				pachAlias += nPos;
				if( 0 == memcmp( pachAlias, pachChannelPrefix, strlen("-ͨ��") ) )
				{
					pachAlias += strlen("-ͨ��");
					memcpy( achLayer, pachAlias, nMaxCHLen );
					achLayer[nMaxCHLen] = '\0';
					byChannel = atoi(achLayer);
					bRet = TRUE;
				}
			}
		}
		return bRet;
	}
	void Print( void ) const
	{
		if( m_AliasType == 0 )
		{
			StaticLog("null alias" );
		}
		else if( m_AliasType == mtAliasTypeTransportAddress )
		{
			StaticLog("IP: 0x%x:%d", 
				     m_tTransportAddr.GetIpAddr(), m_tTransportAddr.GetPort() );
		}		
		else if( m_AliasType == mtAliasTypeE164 )
		{
			StaticLog("E164: %s", m_achAlias ); 
		}
		else if( m_AliasType == mtAliasTypeH323ID )
		{
			StaticLog("H323ID: %s", m_achAlias ); 
		}
		else if( m_AliasType == mtAliasTypeH320ID )
		{
			StaticLog("H320ID: %s", m_achAlias ); 
		}
        else if( m_AliasType == mtAliasTypeH320Alias )
        {
            StaticLog("H320Alias: %s", m_achAlias );
        }
		else
		{
			StaticLog("Other type alias!" ); 
		}
		StaticLog("\n" );
	}
}
/* 
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
*/
PACKED
;

inline  BOOL   TMtVCSPlanAlias::operator ==( const TMtVCSPlanAlias & tObj ) const
{
    if( tObj.m_AliasType == 0 || tObj.m_AliasType != m_AliasType ) 
	{
		return FALSE ;
	}

	if( tObj.m_AliasType == mtAliasTypeTransportAddress )
	{
		if( (tObj.m_tTransportAddr.GetIpAddr() == m_tTransportAddr.GetIpAddr()) && 
			(tObj.m_tTransportAddr.GetPort() == m_tTransportAddr.GetPort()) && 
			(tObj.m_tTransportAddr.GetIpAddr() != 0 ))
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		if( (memcmp( tObj.m_achAlias, m_achAlias, sizeof( m_achAlias ) ) == 0) && 
			(m_achAlias[0] != 0) )
		{
            return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
}

// ����������ǽ������,�����ɸ����ն����
struct THDTvWall
{
public:
	void SetNull()
	{
		m_byHDTWDevNum = 0;
		m_byReserve    = 0;
		memset(m_awHDTWDialBitRate, 0, sizeof(m_awHDTWDialBitRate));
		memset(m_atHDTWModuleAlias, 0, sizeof(m_atHDTWModuleAlias));
		// ��Ա����ΪTW_MEMBERTYPE_NULL������ָ����ͨ��������
		memset(m_abyMemberType, 0, sizeof(m_abyTvWallMember));
		for (u8 byDevID = 0; byDevID < MAX_HDTWDEVNUM; byDevID++)
		{
			for (u8 byChanID = 0; byChanID < MAX_HDTWCHANNUM; byChanID++)
			{
				// ��ʼ������Ա�������ó�Ϊ�Ƿ���������
				m_abyTvWallMember[byDevID][byChanID] = 0xFF;
			}
		}
	}


public:
	BOOL SetHDTWCfg(u8 byHDTWDevNum, THDTWModuleAlias* const patModuelAlias, u16* const paDialBitRate = NULL)
	{
		if (NULL == patModuelAlias)
		{
			return FALSE;
		}
		THDTWModuleAlias* ptHDTWModuelAlias = patModuelAlias;
		u16* pwHDTWDialBitRate = paDialBitRate;

		m_byHDTWDevNum = byHDTWDevNum;
		for (u8 byDevID = 0; byDevID < byHDTWDevNum; byDevID++)
		{
			m_atHDTWModuleAlias[byDevID] = *ptHDTWModuelAlias++;
			if (pwHDTWDialBitRate != NULL)
			{
				m_awHDTWDialBitRate[byDevID] = *pwHDTWDialBitRate++;
			}

		}
		return TRUE;
	}

	BOOL SetHDTwWallMember(u8 byHDTWDevID, u8 byHDTWChanID, u8 byMTIndex, u8 byMemberType)
	{
		if (byHDTWDevID >= m_byHDTWDevNum || byHDTWChanID >= MAX_HDTWCHANNUM )
		{
			return FALSE;
		}

		m_abyTvWallMember[byHDTWDevID][byHDTWChanID] = byMTIndex;
		m_abyMemberType[byHDTWDevID][byHDTWChanID] = byMemberType;
		return TRUE;
	}

	BOOL GetHDTwWallMember(u8 byHDTWDevID, u8 byHDTWChanID, u8& byMTIndex, u8& byMemberType) const
	{
		if (byHDTWDevID >= m_byHDTWDevNum || byHDTWChanID >= MAX_HDTWCHANNUM)
		{
			return FALSE;
		}

		byMTIndex = m_abyTvWallMember[byHDTWDevID][byHDTWChanID];
		byMemberType = m_abyMemberType[byHDTWDevID][byHDTWChanID];
		return TRUE;
	}
	
	// ��������ǽ�Զ�����ģʽ��ָ�����õ�ͨ����, �����Զ�ģʽ��ͨ����������
	BOOL StartAutoModel(u8 byUsableChanNum)
	{
		// �Ƿ������㹻�ĵ���ǽ�豸֧��ָ����ͨ����
		if (byUsableChanNum > m_byHDTWDevNum * MAX_HDTWCHANNUM)
		{
			return FALSE;
		}
		u8 byCurUsableChanNum = 0;
		for (u8 byDevID = 0; byDevID < m_byHDTWDevNum; byDevID++)
		{
			for (u8 byChanID = 0; byChanID < MAX_HDTWCHANNUM; byChanID++)
			{
				if (byCurUsableChanNum >= byUsableChanNum)
				{
					return TRUE;
				}
				m_abyMemberType[byDevID][byChanID] = TW_MEMBERTYPE_VCSAUTOSPEC;
				byCurUsableChanNum++;				
			}
		}
		return TRUE;
	}

	// �Ƿ������˸������ǽ
	BOOL IsHDTWCfg()  { return m_byHDTWDevNum != 0; }

	u8               m_byHDTWDevNum;
	u8               m_byReserve;
	u16              m_awHDTWDialBitRate[MAX_HDTWDEVNUM];          //���ϸ������ǽ�豸ʹ�õ�����
	THDTWModuleAlias m_atHDTWModuleAlias[MAX_HDTWDEVNUM];
    u8   m_abyTvWallMember[MAX_HDTWDEVNUM][MAX_HDTWCHANNUM];       //����ǽ��Ա������������ʱTMtAlias��������+1��
    u8   m_abyMemberType  [MAX_HDTWDEVNUM][MAX_HDTWCHANNUM];       //����ǽ��Ա��������
}
PACKED
;

// VCS�¼�MCU����
struct TVCSSMCUCfg
{
public:
	TVCSSMCUCfg()
	{
 		SetNull();
	}
	void SetNull()
	{
		m_wSMCUNum = 0;
		memset(m_atSMCUAlias, 0, sizeof(m_atSMCUAlias));
		memset(m_awSMCUDialBitRate, 0, sizeof(m_awSMCUDialBitRate));
	}

	// �Ƿ�������VCS�¼�mcu
	BOOL IsVCSMCUCfg() { return m_wSMCUNum != 0; }

	u8         m_wSMCUNum;
	TSMCUAlias m_atSMCUAlias[MAXLIMIT_CONF_SMCU];
	u16        m_awSMCUDialBitRate[MAXLIMIT_CONF_SMCU];
}
PACKED
;

// �ն˷�����Ϣ
struct TVCSGroupInfo
{
	s8  achGroupName[MAX_VCSGROUPNAMELEN];    // �÷�������
	u16 dwEntryNum;                           // �÷���ʵ�����
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;
struct TVCSEntryInfo
{
    TVCSEntryInfo()
    {
        memset( this, 0, sizeof(TVCSEntryInfo) );
    }

	s8 achEntryName[VCS_MAXLEN_ALIAS];   // �����а����ĸ�ʵ������(��Ϊ�ն˵�164��/IP��ַ/H323ID�������ļ�������)
	u8 byEntryType;                         // ��Ŀ���ͣ�MT/MCU/�飩
    u8 byAddrType;                          // ��ַ���ͣ�H323/E164/IP��
  	u16 wDialBitRate;                       //������
	s8 achUIName[VCS_MAXLEN_ALIAS];      // ������ʾ������

	BOOL32 operator == ( const TVCSEntryInfo &tEntry ) const
	{
		if ( byEntryType != tEntry.byEntryType )
			return FALSE;
		if( byAddrType != tEntry.byAddrType )
			return FALSE;
		if ( strcmp( achEntryName, tEntry.achEntryName ) != 0 )
			return FALSE;
		return TRUE;
	}

	//����<�Ա���map��ʹ��  sq101210   ���ڳ�wDialBitRate4���ֶο���ȷ��Ψһ ���Բ�����wDialBitRate
	BOOL operator < ( const TVCSEntryInfo &tEntry ) const
	{
		if( this->byEntryType > tEntry.byEntryType  )
		{
			return FALSE;
		}
		else if(this->byEntryType == tEntry.byEntryType)
		{
			if( this-> byAddrType > tEntry.byAddrType )
			{
				return FALSE;
			}
			else  if( this-> byAddrType == tEntry.byAddrType )
			{
				//return FALSE;
				int nRes = strcmp(this->achEntryName, tEntry.achEntryName);
				if( nRes >0 )
				{
					return FALSE;
				}
				else if( ( nRes == 0 ))
				{
					nRes = strcmp(this->achUIName, tEntry.achUIName);
					if( nRes >0 )
					{
						return FALSE;
					}
					else if ( nRes == 0 )
					{
						return FALSE;
					}
					else
					{
						return TRUE;
					}
				}
				else
				{
					return TRUE;
				}	
			}
			else
			{
				return TRUE;
			}
		}
		else
		{
			return TRUE;
		}
		
		return FALSE;
	}
}
PACKED
;
//���鷢��ģʽ
#define     CONF_SPEAKMODE_NORMAL            0  //���ָ�� �� һ�����루�����У����Զ����У�
#define     CONF_SPEAKMODE_ANSWERINSTANTLY   1  //���𣨴����У��Զ����У�
//����˫���ķ���ʹ��״̬
#define     CONF_DUALSTATUS_DISABLE          0  //����˫���ر�
#define     CONF_DUALSTATUS_ENABLE           1  //����˫������

class CBasicVCCStatus
{
    enum emMaskEx
    {
        emIsGroupLock = 0x01,
    };
public:
	CBasicVCCStatus()
	{
		DefaultStatus();
	}

    u8   GetCurVCMode()               { return m_byVCMode; }
	void SetCurVCMode(u8 byMode)      { m_byVCMode = byMode; }
	
	const TMt& GetCurVCMT()           { return m_tCurVCMT; }
	void  SetCurVCMT(TMt& tMt)        
	{ 
//		m_tLastVcMt = m_tCurVCMT;
		memcpy(&m_tCurVCMT, &tMt, sizeof(TMt)); 
	}

    BOOL IsLocMute()                  { return (m_byLocalMuteType & (1 << VCS_AUDPROC_MUTE)) != 0; }
	BOOL IsLocSilence()               { return (m_byLocalMuteType & (1 << VCS_AUDPROC_SILENCE)) != 0;}
	void SetLocAudProcType(u8 byOpenFlag, u8 byMuteType)
	{ 
		m_byLocalMuteType = (byOpenFlag ? (m_byLocalMuteType | (1 << byMuteType)) : (m_byLocalMuteType & (~(1 << byMuteType))));
	}

    BOOL IsRemMute()                  { return (m_byRemoteMuteType & (1 << VCS_AUDPROC_MUTE)) != 0; }
	BOOL IsRemSilence()               { return (m_byRemoteMuteType & (1 << VCS_AUDPROC_SILENCE)) != 0;}
	void SetRemAudProcType(u8 byOpenFlag, u8 byMuteType)
	{ 
		m_byRemoteMuteType = (byOpenFlag ? (m_byRemoteMuteType | (1 << byMuteType)) : (m_byRemoteMuteType & (~(1 << byMuteType))));
	}

	// ��ȡ��������б�
	const s8* GetGroupCallList()
	{
		return (s8*)m_achOnLineGroup;
	}
	
	// ������������б�
    BOOL32 OprGroupCallList(s8* pachGroupName, u8 byNameLen, u8 byAdd, u16 wErrCode)
	{
		wErrCode = 0;

		if (NULL == pachGroupName)
		{
			StaticLog("[OprGroupCallList] NULL == pachGroupName\n");
			return FALSE;
		}
		
		u8 byExistPos = VCS_MAXGROUPCALL_NUM;
		u8 byEmptPos  = VCS_MAXGROUPCALL_NUM;
		for (u8 byIdx = 0; byIdx < VCS_MAXGROUPCALL_NUM; byIdx++)
		{
			if (!memcmp(pachGroupName, m_achOnLineGroup[byIdx], min(byNameLen, MAX_VCSGROUPNAMELEN)) &&
				min(byNameLen, MAX_VCSGROUPNAMELEN) >= strlen(m_achOnLineGroup[byIdx]))
			{
				byExistPos = byIdx;
				break;
			}
			if (!memcmp(m_achOnLineGroup[byIdx], "", sizeof("")) && VCS_MAXGROUPCALL_NUM == byExistPos)
			{
				byEmptPos = byIdx;
			}
		}

		if (byAdd)
		{ 
			if (byExistPos != VCS_MAXGROUPCALL_NUM)
			{
				StaticLog("[OprGroupCallList] %s has on line\n", m_achOnLineGroup[byExistPos]);
				return TRUE;
			}

			if (VCS_MAXGROUPCALL_NUM == byEmptPos)
			{
				wErrCode = ERR_MCU_VCS_OVERGROUPNUM;
				return FALSE;
			}
			else
			{
				memcpy(m_achOnLineGroup[byEmptPos], pachGroupName, min(byNameLen, MAX_VCSGROUPNAMELEN));
				m_achOnLineGroup[byEmptPos][MAX_VCSGROUPNAMELEN - 1] = 0;
			}
		}
		else
		{
			if (byExistPos != VCS_MAXGROUPCALL_NUM)
			{
				memset(m_achOnLineGroup[byExistPos], 0, sizeof(m_achOnLineGroup[byExistPos]));
			}

		}

		return TRUE;
	}

	// �Ƿ񳬹���֧�ֵ���ʱ������
	BOOL32 IsAddEnable()
	{
		for (u8 byIdx = 0; byIdx < VCS_MAXNEWADDMT_NUM; byIdx++)
		{
			if (m_atNewAddMt[byIdx].IsNull())
			{
				return TRUE;
			}
		}
		
		return FALSE;
	}
	
	// ��ȡ��ʱ�����ն��б�
	const TMt* GetNewMtList()
	{
		return m_atNewAddMt;
	}

	// ������ʱ���е��ն��б�
	BOOL32 OprNewMt(const TMt& tMt, u8 byAdd)
	{
		u8 byExistPos = VCS_MAXNEWADDMT_NUM;
		u8 byEmptyPos = VCS_MAXNEWADDMT_NUM;
		for (u8 byIdx = 0; byIdx < VCS_MAXNEWADDMT_NUM; byIdx++)
		{
			if (m_atNewAddMt[byIdx] == tMt)
			{
				byExistPos = byIdx;
				break;
			}
			if (m_atNewAddMt[byIdx].IsNull() && VCS_MAXNEWADDMT_NUM == byEmptyPos)
			{
				byEmptyPos = byIdx;
			}
		}
		if (byAdd)
		{
			if (byExistPos != VCS_MAXNEWADDMT_NUM)
			{
				return TRUE;
			}
			if (VCS_MAXNEWADDMT_NUM == byEmptyPos)
			{
				return FALSE;
			}
			else
			{
				m_atNewAddMt[byEmptyPos] = tMt;
				return TRUE;
			}
		}
		else
		{
			if (byExistPos != VCS_MAXNEWADDMT_NUM)
			{
				m_atNewAddMt[byExistPos].SetNull();
				return TRUE;
			}

		}
		return FALSE;

	}

	// ��ȡ��ǰ����ϯ��ѯ�ն�
	const TMt& GetCurChairPollMt()
	{
		return m_tMtPolling;
	}
	// ���õ�ǰ����ϯ��ѯ�ն�
	void SetCurChairPollMt(const TMt& tMt)
	{
		m_tMtPolling = tMt;
	}
	// ��ȡ��ϯ��ѯ״̬
	u8 GetChairPollState()
	{
		return m_byPollState;
	}
	void SetChairPollState(u8 byPollState)
	{
		m_byPollState = byPollState;
	}
	// ��ȡ��ϯ��ѯ���
	u8 GetPollIntval()
	{
		return m_byPollIntval;
	}
	void SetPollIntval(u8 byIntval)
	{
		m_byPollIntval = byIntval;
	}

	// ����ģʽ�л�ʱ��������ģʽ������״̬������״̬������Ҫ�ָ�Ϊԭʼֵ
	void  RestoreStatus()
	{
		m_tCurVCMT.SetNull();
//		m_tLastVcMt.SetNull();
// 		m_byLocalMuteType  = 0;
// 		m_byRemoteMuteType = 0; 
		memset(m_achOnLineGroup, 0, sizeof(m_achOnLineGroup));
		m_tMtPolling.SetNull();
		m_byPollIntval = 0;
		m_byPollState  = VCS_POLL_STOP;
		m_byTvWallManageMode = VCS_TVWALLMANAGE_MANUAL_MODE;
        m_bySpeakMode = CONF_SPEAKMODE_NORMAL;
        m_byDualEnable = CONF_DUALSTATUS_DISABLE;
//        m_byDualing = 0;
        SetGroupModeLock( TRUE );
	}

	// �����ģʽ�л�,��������ѯ״̬�������״̬
	void RestoreGroupStatus()
	{
		m_tCurVCMT.SetNull();
        //[9/13/2011 zhushengze]�ָ�˫��ʹ��״̬
        SetConfDualEnable(CONF_DUALSTATUS_DISABLE);
//		m_tLastVcMt.SetNull();
// 		m_byLocalMuteType  = 0;
// 		m_byRemoteMuteType = 0; 
	}

	// Ĭ��״̬
	void DefaultStatus()
	{
		// Ĭ��Ϊ��������ģʽ
		m_byVCMode = VCS_SINGLE_MODE;
		m_byTvWallManageMode = VCS_TVWALLMANAGE_MANUAL_MODE;
		m_byIsMtInTvWallCanMixing = 0;	
		m_byLocalMuteType  = 0;
		m_byRemoteMuteType = 0; 
        m_bySpeakMode = CONF_SPEAKMODE_NORMAL;
        m_byDualEnable = CONF_DUALSTATUS_DISABLE;
//        m_byDualing = 0;
		memset(m_atNewAddMt, 0, sizeof(m_atNewAddMt));
		RestoreStatus();
	}

	//zjj20091102
	u8 GetTVWallManageMode(){ return m_byTvWallManageMode; }
	void SetTVWallManageMode( u8 byMode )
	{
		if( byMode >= VCS_TVWALLMANAGE_MANUAL_MODE &&
			byMode <= VCS_TVWALLMANAGE_REVIEW_MODE )
		{
			m_byTvWallManageMode = byMode;
		}
	}

	BOOL32 GetMtInTvWallCanMixing(){ return (1 == m_byIsMtInTvWallCanMixing) ;}
	void SetMtInTvWallCanMixing( BOOL32 bCanMixing )
	{
		if( bCanMixing )
		{
			m_byIsMtInTvWallCanMixing = 1;
		}
		else
		{
			m_byIsMtInTvWallCanMixing = 0;
		}
	}

    u8   GetConfSpeakMode()   {   return m_bySpeakMode;   }
    void SetConfSpeakMode(u8 byMode) {    m_bySpeakMode = byMode; }
    BOOL32 IsConfDualEnable()   {   return m_byDualEnable == 1 ? TRUE : FALSE;   }
    void   SetConfDualEnable(BOOL32 bDualing) {   m_byDualEnable = bDualing ? 1 : 0 ; }

//    BOOL32 IsConfDualing()   {   return m_byDualing == 1 ? TRUE : FALSE;   }
//    void   SetConfDualing(BOOL32 bDualing) {   m_byDualing = bDualing ? 1 : 0 ; }

    BOOL32 IsGroupModeLock() const{ return ((m_byMask & emIsGroupLock ) != 0); }
    void   SetGroupModeLock( BOOL32 byIsLock )
    { 
        if( byIsLock )
        {
            m_byMask |= emIsGroupLock;
        }
        else
        {
            m_byMask &= (~emIsGroupLock);
        }		
	}

	void ClearAllNewMt( void )
	{
		memset(m_atNewAddMt, 0, sizeof(m_atNewAddMt));
	}
//	const TMt& GetLstVCMT()           { return m_tLastVcMt; }

	void Print()
	{
 		StaticLog("m_byVCMode:%d\n", m_byVCMode);
 		StaticLog("m_byLocalMuteType:%d\n", m_byLocalMuteType);
 		StaticLog("m_byRemoteMuteType:%d\n", m_byRemoteMuteType);
 		StaticLog("m_tCurVCMT:mcuid��%d mtid��%d\n", m_tCurVCMT.GetMcuId(), m_tCurVCMT.GetMtId() );
 		StaticLog("m_tMtPolling:mcuid-%d mtid��%d\n", m_tMtPolling.GetMcuId(),m_tMtPolling.GetMtId() );
 		StaticLog("m_byPollIntval:%d\n", m_byPollIntval);
 		StaticLog("m_byPollState:%d\n", m_byPollState);
 		StaticLog("m_byTvWallManageMode:%d\n", m_byTvWallManageMode);
 		StaticLog("m_byIsMtInTvWallCanMixing:%d\n", m_byIsMtInTvWallCanMixing);
        StaticLog("m_bySpeakMode:%d\n", m_bySpeakMode);
        StaticLog("m_byDualEnable:%d\n", m_byDualEnable);
//        StaticLog("m_byDualing:%d\n", m_byDualing);
        StaticLog("m_byMask:%d\n", m_byMask);
		StaticLog( "m_atNewAddMt:\n");        

		for (u8 byIdx = 0, byPrintIdx = 0; byIdx < VCS_MAXNEWADDMT_NUM; byIdx++)
		{
			if (!m_atNewAddMt[byIdx].IsNull())
			{
				StaticLog("%d)mtid(%d)\n", byPrintIdx, m_atNewAddMt[byIdx].GetMtId());
				byPrintIdx++;
			}
		}
//		StaticLog( "m_tLastVcMt:mcuid��%d mtid��%d\n", m_tLastVcMt.GetMcuId(), m_tLastVcMt.GetMtId() );
	}

protected:
	u8  m_byVCMode;         // VCS���鵱ǰ�����ĵ���ģʽ(VCS_SINGLE_MODE,VCS_MULTW_MODE,VCS_MULVMP_MODE) 
	TMt m_tCurVCMT;         // VCS��ǰ���ڵ��ȵ��ն�
	u8  m_byLocalMuteType;  // ���ؾ���������
	u8  m_byRemoteMuteType; // Զ�˾���������

	TMt m_atNewAddMt[VCS_MAXNEWADDMT_NUM]; // VCS��ʱ�����ն��б�
	s8  m_achOnLineGroup[VCS_MAXGROUPCALL_NUM][MAX_VCSGROUPNAMELEN]; // VCS��ǰ���������

	TMt m_tMtPolling;    // ��ǰ���ڽ�����ϯ��ѯ���ն�
	u8  m_byPollIntval;  // ��ѯ���(s)
	u8  m_byPollState;   // ��ѯ״̬

	//zjj20091102 ����ǽ����ģʽ
	u8	m_byTvWallManageMode;

	//zjj20091102 ����ǽԤ��������һ������
	//�ڵ���ǽ�е��ն��Ƿ���Խ�����0-������ 1-����
	u8	m_byIsMtInTvWallCanMixing;

	//����ģʽ������/��������(CONF_SPEAKMODE_NORMAL/CONF_SPEAKMODE_ANSWERINSTANTLY)
    u8  m_bySpeakMode;


    u8  m_byMask;	//��ֵ��������,��һλ����ǰ����״̬���ڶ�λ������ǰ����״̬

    //˫���Ƿ��������ͣ�vcs����
    u8  m_byDualEnable;    
}
PACKED
;


// ��HDUͨ�������Ϣ
struct THduModChnlInfo
{
public:
	THduModChnlInfo()
	{
		SetNull();
	}

	void SetNull()
	{
		m_byHduId = 0;
		m_byHduChnlIdx = MAXNUM_HDU_CHANNEL;
		m_byHduChnlMember = MAXNUM_CONF_MT + 1;
		m_byMemberType = TW_MEMBERTYPE_NULL;
	}

	void SetHduId(u8 byHduId)  { m_byHduId = byHduId; }
	u8   GetHduID()    const        { return m_byHduId; }

	void SetHduChnlIdx(u8 byHduChnlIdx)  { m_byHduChnlIdx = byHduChnlIdx; }
	u8   GetHduChnlIdx()    const             { return m_byHduChnlIdx; }

	void SetHduChnlMember(u8 byHduChnlMember)  { m_byHduChnlMember = byHduChnlMember; }
	u8   GetHduChnlMember()      const         { return m_byHduChnlMember; }

	void SetMemberType(u8 byMemberType)  { m_byMemberType = byMemberType; }
	u8   GetMemberType()   const             { return m_byMemberType; }

	// [5/25/2011 liuxu] ���ӺϷ��Խӿ�
	BOOL32 IsValid( ) const
	{
		// Hdu��Id�ж�
		if(HDUID_MIN > m_byHduId || HDUID_MAX < m_byHduId)
		{
			return FALSE;
		}
		
		// ͨ����������1
		if ( m_byHduChnlIdx >= MAXNUM_HDU_CHANNEL )
		{
			return FALSE;
		}
		
		return TRUE;
	}

private:
	u8    m_byHduId;             //ͨ�������豸ID
	u8    m_byHduChnlIdx;        //��Ӧ�豸��ͨ����
    u8    m_byHduChnlMember;     //��ͨ����Ա����
    u8    m_byMemberType;        //��ͨ����Ա��������,TW_MEMBERTYPE_MCSSPEC,TW_MEMBERTYPE_SPEAKER...
}
PACKED
;

struct TMtListInfo
{
public:
	TMtListInfo()
	{
		memset(this, 0, sizeof(TMtListInfo));
	}

	BOOL SetMtList(u8 byMtNum, const TMtAlias* patMtAlias, const u16* pawMtDialRate)
	{
		if (byMtNum > MAXNUM_CONF_MT ||
			!patMtAlias || !pawMtDialRate)
		{
			StaticLog("[SetMtList]bad input param(byMtNum:%d, patMtAlias:%d, pawMtDialRate:%d)\n",
				      byMtNum, patMtAlias, pawMtDialRate);
			return FALSE;
		}

		m_byMtNum = byMtNum;
		memcpy(m_tMtAliasArray, patMtAlias, byMtNum * sizeof(TMtAlias));
		memcpy(m_awMtDialRate, pawMtDialRate, byMtNum * sizeof(u16));
		return TRUE;
	}

	u8 GetMtNum()
	{
		return m_byMtNum;
	}

	TMtAlias& GetMtAliasByIdx(u8 byIdx)
	{
		return m_tMtAliasArray[byIdx];
	}

	u16 GetMtDialRateByIdx(u8 byIdx)
	{
		return m_awMtDialRate[byIdx];
	}
private:
	TMtAlias   m_tMtAliasArray[MAXNUM_CONF_MT]; // VCSԭʼ������ն��б���Ϣ
	u16        m_awMtDialRate[MAXNUM_CONF_MT];    // VCSԭʼ������ն˺�������
	u8         m_byMtNum;
	u8         m_byReserve;
}
PACKED
;

// [5/25/2011 liuxu] �жϵ���ǽ��Ա�����Ƿ���Vcs�����е�����
inline BOOL IsVcsTvwMemberType( const u8 byType )
{
	if ( byType == TW_MEMBERTYPE_VCSAUTOSPEC 
		|| byType == TW_MEMBERTYPE_VCSSPEC
		|| byType == TW_MEMBERTYPE_TWPOLL)
	{
		return TRUE;
	}

	return FALSE;
}


#endif  /* __VCSSTRUCT_H_ */

