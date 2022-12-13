#include <iostream>

using namespace std;

char* Change(char* str)
{
	size_t len = strlen(str);
	int k = 0;
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
			k++;
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
	strcpy_s(str, len + 1, tmp);
	if (k > 0)
		cout << "Yes, Count : " << k << endl;
	else
		cout << "No" << endl;
	return tmp;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}