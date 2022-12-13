#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_1_Iter/Lab_08_1_Iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

char* TestChange(char* str)
{
	size_t len = strlen(str);
	if (len < 3)
		return str;
	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
	while (i < len && str[i + 2] != 0)
	{
		if (((str[i] == 'O' && str[i + 2] == 'O') || (str[i] == 'A' && str[i + 2] == 'A')) && str[i + 1] == 'G')
		{
			strcat_s(t, len, "**");
			t += 2;
			i += 3;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy_s(str, len, tmp);
	return tmp;
}

namespace UnitTestLab081Iter
{
	TEST_CLASS(UnitTestLab081Iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[101] = "TESTOGOTESTAGA";
			char teststr[101] = "TESTOGOTESTAGA";
			char* dest = Change(str);
			char* testdest = TestChange(teststr);
			Assert::AreEqual(strcmp(dest, testdest), 0);
		}
	};
}
