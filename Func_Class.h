#pragma once


class Func_Class {
public:
	char* sdvig(char* iz) {
		int i = 0, j = 0, fl = 0;
		char* s = new char[16];
		if (iz[0] == '\0')
			return iz;
		while (iz[i++] != '\0') {
			if (iz[i] != ' ' || fl != 0) {
				s[j] = iz[i];
				j++;
				fl++;
			}
		}
		iz = s;
		s[i] = '\0';
		return s;
	}
};
