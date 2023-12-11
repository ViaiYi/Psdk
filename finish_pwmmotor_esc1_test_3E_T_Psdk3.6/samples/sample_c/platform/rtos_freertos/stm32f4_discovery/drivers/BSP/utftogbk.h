#ifndef _UTFTOGBK_H_
#define _UTFTOGBK_H_

int Utf8ToGb2312(char *sOut, int iMaxOutLen, const char *sIn, int iInLen);
int Gb2312ToUtf8(char *sOut, int iMaxOutLen, const char *sIn, int iInLen);

#endif