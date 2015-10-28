#pragma once

#include <string>
#include <windows.h>

namespace Common
{
	std::wstring ansi2unicode(const std::string& ansi);
	std::string unicode2ansi(const std::wstring& unicode);
	std::wstring utf8ToUnicode(const std::string& str);
	std::string toString(const char *fmt, ...);
	std::string getErrString();
}

#pragma warning(disable : 4200)					// ʹ���˷Ǳ�׼��չ : �ṹ/�����е����С����

#define MAX_NAME_LEN 256
#pragma pack(push)								//�������״̬
#pragma pack(4)									//�趨Ϊ4�ֽڶ���
struct IM_MSG
{
	int   nIMType;								//�������ͣ���������=0x1��Ⱥ����=0x2���ļ�����=0x3
	int   nDirection;							//��Ϣ������Ϣ���ļ��Ľ���= 0����Ϣ���ļ��ķ���= 1
	INT64 uTime;								//��Ϣ�Ĳ���ʱ�䣬ʹ�ø��ֽ�
	wchar_t szLocalAccount[MAX_NAME_LEN];		//���ص�½�˺������ַ���ʹ��unicode���룬�����С��*2=512�ֽ�
	wchar_t szTargetAccount[MAX_NAME_LEN];		//�Է��˺���
	int nMessageLen;							//������Ϣ����
	wchar_t szMsg[0];

	IM_MSG()
	{
		nIMType = 0;
		nDirection = 0;
		uTime = 0;
		wmemset(szLocalAccount, 0, _countof(szLocalAccount));
		wmemset(szTargetAccount, 0, _countof(szTargetAccount));
		nMessageLen = 0;
	}
};
#pragma pack(pop)//�ָ�����״̬
