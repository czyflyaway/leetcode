#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return 0;
    }
};
/*
	DWORD dwVersion = 0;
	WCHAR wzVer[32] = {0};

	wcscpy(wzVer, DEF_TVSHOW_VERSION_TXT);
	WORD wLen = wcslen(wzVer);
	WORD iStart = 0;
	WORD wBitPos = 24;

	for(WORD i = 0; i < wLen; i ++)
	{
		if(wzVer[i] == '.')
		{
			wzVer[i] = 0;
			DWORD dwV = _wtoi(&wzVer[iStart]);
			dwV <<= wBitPos;

			dwVersion |= dwV;
			wBitPos -= 8;
			iStart = i + 1;
		}
	}

	return dwVersion;
*/
std::string transversion(long version)
{
    int v1, v2, v3, v4;
    v1 = (version & 0xff000000) >> 24;
    v2 = (version & 0x00ff0000) >> 16;
    v3 = (version & 0x0000ff00) >> 8;
    v4 = (version & 0x000000ff);

    std::stringstream ss;
    ss << v1 << "."
        << v2 << "."
        << v3 << "."
        << v4;
    return ss.str();
}
long versionArr[] = {
39518208,
39452678,
39518226,
1,
39584000,
39387140,
38862848,
39583744,
39452672,
39583747,
39583745,
39321601,
39059712,
38862852,
39387136,
39583752,
39124992
};
int main(int argc, char *argv[])
{
    int arrSize = sizeof(versionArr) / sizeof(versionArr[0]);
    for(int i = 0; i < arrSize; ++i)
    {
        printf("%d:\t%s\n", versionArr[i], transversion(versionArr[i]).c_str());
    }
}