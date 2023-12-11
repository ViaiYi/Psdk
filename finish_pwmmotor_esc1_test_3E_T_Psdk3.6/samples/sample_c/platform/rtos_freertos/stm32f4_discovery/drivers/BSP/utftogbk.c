#include "utftogbk.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "iconv.h"
#pragma comment(lib,"libiconv.lib")

//iInLen�ĳ��Ȳ�����\0��Ӧ����strlen������ֵ�Ǵ�����sOut����
int Utf8ToGb2312(char *sOut, int iMaxOutLen, const char *sIn, int iInLen)
{
    char *pIn = (char *)sIn;
    char *pOut = sOut;
    size_t ret;
    size_t iLeftLen=iMaxOutLen;
    iconv_t cd;

    cd = iconv_open("gb2312", "utf-8");

    if (cd == (iconv_t) - 1)
    {
        return -1;
    }
	
    size_t iSrcLen=iInLen;
    ret = iconv(cd, &pIn,&iSrcLen, &pOut,&iLeftLen);
	
    if (ret == (size_t) - 1)
    {
        iconv_close(cd);
        return -1;
    }

    iconv_close(cd);

    return (iMaxOutLen - iLeftLen);
}

//iInLen�ĳ��Ȳ�����\0��Ӧ����strlen������ֵ�Ǵ�����sOut����
int Gb2312ToUtf8(char *sOut, int iMaxOutLen, const char *sIn, int iInLen)
{
    char *pIn = (char *)sIn;
    char *pOut = sOut;
    size_t ret;
    size_t iLeftLen=iMaxOutLen;
    iconv_t cd;


    cd = iconv_open("utf-8", "gb2312");
	
    if (cd == (iconv_t) - 1)
    {
        return -1;
    }
    size_t iSrcLen=iInLen;
	
    ret = iconv(cd, &pIn,&iSrcLen, &pOut,&iLeftLen);
    if (ret == (size_t) - 1)
    {
        iconv_close(cd);
        return -1;
    }

    iconv_close(cd);

    return (iMaxOutLen - iLeftLen);
}

