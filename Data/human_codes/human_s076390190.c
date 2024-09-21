#include <stdio.h>

/*
.0
3124
,5
*/

/* {top, front, right} */
int minase_inori[8][3] = {
	{0, 1, 2}, {0, 2, 4}, {0, 4, 3}, {0, 3, 1},
	{5, 1, 3}, {5, 3, 4}, {5, 4, 2}, {5, 2, 1}
};

int main(void) {
	int hayami_saori[6];
	int uesaka_sumire;
	int iguti_yuka, tamura_yukari, horie_yui;
	for (iguti_yuka = 0; iguti_yuka < 6; iguti_yuka++) {
		if (scanf("%d", &hayami_saori[iguti_yuka]) != 1) return 1;
	}
	for (iguti_yuka = 0; iguti_yuka < 8; iguti_yuka++) {
		for (tamura_yukari = 0; tamura_yukari < 3; tamura_yukari++) {
			minase_inori[iguti_yuka][tamura_yukari] = hayami_saori[minase_inori[iguti_yuka][tamura_yukari]];
		}
	}
	if (scanf("%d", &uesaka_sumire) != 1) return 1;
	for (iguti_yuka = 0; iguti_yuka < uesaka_sumire; iguti_yuka++) {
		int igarasi_hiromi, murakawa_rie;
		if (scanf("%d%d", &igarasi_hiromi, &murakawa_rie) != 2) return 1;
		for (tamura_yukari = 0; tamura_yukari < 8; tamura_yukari++) {
			for (horie_yui = 0; horie_yui < 3; horie_yui++) {
				if (minase_inori[tamura_yukari][horie_yui] == igarasi_hiromi &&
				minase_inori[tamura_yukari][(horie_yui + 1) % 3] == murakawa_rie) {
					printf("%d\n", minase_inori[tamura_yukari][(horie_yui + 2) % 3]);
					tamura_yukari = 334;
					break;
				}
			}
		}
	}
	return 0;
}

