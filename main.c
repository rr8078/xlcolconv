#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void numtoxlcolumn(int num, char *col);
int xlcolumntonum(const char *col);

int main(void) {
    int i;
	char s1[255], s2[255];
	scanf("%s", s1);
	
	if (isdigit(s1[0])) {
	    s2[0] = '\0';
		numtoxlcolumn(atoi(s1), s2);
		printf("%s\n", s2);
	} else {
		for(i = 0; i < strlen(s1); i++) {
		    s1[i] = toupper(s1[i]);
		}

		printf("%d\n", xlcolumntonum(s1));
	}
	
	return 0;
}

// エクセル列番号→列名
void numtoxlcolumn(int num, char *col)
{
	char *ret, *c, buf[255];
	int maxnum; // 308915776 = 26*26*26*26*26*26
	strcpy(buf, "AAAAAA");
	ret = buf;
	for(maxnum = 308915776; maxnum > 1; maxnum/=26) {
	    if (num == (maxnum - 1) / (26 - 1)) {
		    strcpy(col, ret);
		    return;
	    }
		if (num > (maxnum - 1) / (26 - 1)) break;
		ret++;
	}

	for(c = ret; *c; c++) {
		for(; *c <= 'Z'; (*c)++) {
			if (num < xlcolumntonum(ret)) {
				break;
			}
		}
		*c = *c - 1;
		if (num == xlcolumntonum(ret)) break;
	}
	strcpy(col, ret);
}

// エクセル列名→列番号
int xlcolumntonum(const char *col)
{
	int num;
	for(num = 0; *col; col++) {
		num = (num * 26) + (*col - 'A' + 1);
	}
	return num;
}
