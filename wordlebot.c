#include <stdio.h> 
#include <string.h>

int startup();
int bestg();
int nextg();
int repeatcheck(char *letters, int letval, char let, int letpos);


#define LEN 2316
double current = 0.0;
char list[LEN][7], first[10], second[10], third[10], fourth[10], fifth[10], win = 'n';
int dis[26][6], pg = 0;


int main(){
	printf("Hello I can help you solve the wordle.\nHow many possible guesses would you like me to display? (1-5)\n");
	scanf(" %d", &pg);
	
	
	int gnum = 1;
	startup();
	while(win != 'y' && gnum < 7){
		bestg();
		if(win == 'y')
			break;
		printf("Did you win? (y or n)\n");
		scanf(" %c", &win);
		if(win == 'y')
			break;
		gnum++;
		if(gnum == 7)
			break;
		nextg();
		
	}
	if(gnum<7)
		printf("You won in %d tries", gnum);
	else
		printf("Unlucky");
	return 0;
}
	
int startup() {
	
	char buf[1][7];
	FILE *file;
	
	file = fopen("SOLUTION.txt", "r");
	
	if(file == NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	
	for(int i=0; i<LEN; i++)
	{
		fgets(buf[0], 7, file);
		if(strcmp(buf[0],"\n"))
		{
			strcpy(list[i], buf[0]);
		}
		strcpy(buf[0], "");
	}
	
	fclose(file);
	
	return 0;
	
}

int bestg(){
	int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0, o=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0, top1=0, top2=0, top3=0, top4=0,top5=0,score[LEN]; 
	
	char  letters[5];
	for(int aa=0; aa<26; aa++){
		for(int bb=0; bb<6; bb++){
			dis[aa][bb] = 0;
		}
	}
	for(int aa=0; aa<LEN; aa++){
		for(int bb=0; bb<6; bb++){
			if(list[aa][bb] == 'a'){
				a++;	
				dis[0][bb]++;
			}
			if(list[aa][bb] == 'b'){
				b++;	
				dis[1][bb]++;
			}
			if(list[aa][bb] == 'c'){
				c++;	
				dis[2][bb]++;
			}
			if(list[aa][bb] == 'd'){
				d++;	
				dis[3][bb]++;
			}
			if(list[aa][bb] == 'e'){
				e++;	
				dis[4][bb]++;
			}
			if(list[aa][bb] == 'f'){
				f++;	
				dis[5][bb]++;
			}
			if(list[aa][bb] == 'g'){
				g++;	
				dis[6][bb]++;
			}
			if(list[aa][bb] == 'h'){
				h++;	
				dis[7][bb]++;
			}
			if(list[aa][bb] == 'i'){
				i++;	
				dis[8][bb]++;
			}
			if(list[aa][bb] == 'j'){
				j++;	
				dis[9][bb]++;
			}
			if(list[aa][bb] == 'k'){
				k++;	
				dis[10][bb]++;
			}
			if(list[aa][bb] == 'l'){
				l++;	
				dis[11][bb]++;
			}
			if(list[aa][bb] == 'm'){
				m++;	
				dis[12][bb]++;
			}
			if(list[aa][bb] == 'n'){
				n++;	
				dis[13][bb]++;
			}
			if(list[aa][bb] == 'o'){
				o++;	
				dis[14][bb]++;
			}
			if(list[aa][bb] == 'p'){
				p++;	
				dis[15][bb]++;
			}
			if(list[aa][bb] == 'q'){
				q++;	
				dis[16][bb]++;
			}
			if(list[aa][bb] == 'r'){
				r++;	
				dis[17][bb]++;
			}
			if(list[aa][bb] == 's'){
				s++;	
				dis[18][bb]++;
			}
			if(list[aa][bb] == 't'){
				t++;	
				dis[19][bb]++;
			}
			if(list[aa][bb] == 'u'){
				u++;	
				dis[20][bb]++;
			}
			if(list[aa][bb] == 'v'){
				v++;	
				dis[21][bb]++;
			}
			if(list[aa][bb] == 'w'){
				w++;	
				dis[22][bb]++;
			}
			if(list[aa][bb] == 'x'){
				x++;	
				dis[23][bb]++;
			}
			if(list[aa][bb] == 'y'){
				y++;	
				dis[24][bb]++;
			}
			if(list[aa][bb] == 'z'){
				z++;	
				dis[25][bb]++;
			}
		}
	}
	/*printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\nf = %d\ng = %d\nh = %d\ni = %d\nj = %d\nk = %d\nl = %d\nm = %d\n" 
			"n = %d\no = %d\np = %d\nq = %d\nr = %d\ns = %d\nt = %d\nu = %d\nv = %d\nw = %d\nx = %d\ny = %d\nz = %d\n", 
			a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);*/
	
	for(int aa=0; aa<LEN; aa++){
		current = 0.0;
		for(int dd = 0; dd < 6; dd++)
			letters[dd] = '?';
		for(int bb=0; bb<6; bb++){
			if(list[aa][bb] == 'a')
				repeatcheck(letters, a, list[aa][bb], bb);
			if(list[aa][bb] == 'b')
				repeatcheck(letters, b, list[aa][bb], bb);
			if(list[aa][bb] == 'c')
				repeatcheck(letters, c, list[aa][bb], bb);
			if(list[aa][bb] == 'd')
				repeatcheck(letters, d, list[aa][bb], bb);
			if(list[aa][bb] == 'e')
				repeatcheck(letters, e, list[aa][bb], bb);
			if(list[aa][bb] == 'f')
				repeatcheck(letters, f, list[aa][bb], bb);
			if(list[aa][bb] == 'g')
				repeatcheck(letters, g, list[aa][bb], bb);
			if(list[aa][bb] == 'h')
				repeatcheck(letters, h, list[aa][bb], bb);
			if(list[aa][bb] == 'i')
				repeatcheck(letters, i, list[aa][bb], bb);
			if(list[aa][bb] == 'j')
				repeatcheck(letters, j, list[aa][bb], bb);
			if(list[aa][bb] == 'k')
				repeatcheck(letters, k, list[aa][bb], bb);
			if(list[aa][bb] == 'l')
				repeatcheck(letters, l, list[aa][bb], bb);
			if(list[aa][bb] == 'm')
				repeatcheck(letters, m, list[aa][bb], bb);
			if(list[aa][bb] == 'n')
				repeatcheck(letters, n, list[aa][bb], bb);
			if(list[aa][bb]== 'o')
				repeatcheck(letters, o, list[aa][bb], bb);
			if(list[aa][bb] == 'p')
				repeatcheck(letters, p, list[aa][bb], bb);
			if(list[aa][bb] == 'q')
				repeatcheck(letters, q, list[aa][bb], bb);
			if(list[aa][bb] == 'r')
				repeatcheck(letters, r, list[aa][bb], bb);
			if(list[aa][bb] == 's')
				repeatcheck(letters, s, list[aa][bb], bb);
			if(list[aa][bb] == 't')
				repeatcheck(letters, t, list[aa][bb], bb);
			if(list[aa][bb] == 'u')
				repeatcheck(letters, u, list[aa][bb], bb);
			if(list[aa][bb]== 'v')
				repeatcheck(letters, v, list[aa][bb], bb);
			if(list[aa][bb] == 'w')
				repeatcheck(letters, w, list[aa][bb], bb);
			if(list[aa][bb] == 'x')
				repeatcheck(letters, x, list[aa][bb], bb);
			if(list[aa][bb] == 'y')
				repeatcheck(letters, y, list[aa][bb], bb);
			if(list[aa][bb] == 'z')
				repeatcheck(letters, z, list[aa][bb], bb);
			if(list[aa][bb] != '\0');
				letters[bb] = list[aa][bb];
			//printf("1%s1", letters);
		}
		score[aa] = current;
	
	}
	for(int dd = 0; dd<LEN; dd++){
		if(score[dd] > top1){
			top5 = top4;
			strcpy(fifth, fourth);
			top4 = top3;
			strcpy(fourth, third);
			top3 = top2;
			strcpy(third, second);
			top2 = top1;
			strcpy(second, first);
			top1 = score[dd];
			strcpy(first, list[dd]);
		}else if(score[dd] > top2){
			top5 = top4;
			strcpy(fifth, fourth);
			top4 = top3;
			strcpy(fourth, third);
			top3 = top2;
			strcpy(third, second);
			top2 = score[dd];
			strcpy(second, list[dd]);
		}else if(score[dd] > top3){
			top5 = top4;
			strcpy(fifth, fourth);
			top4 = top3;
			strcpy(fourth, third);
			top3 = score[dd];
			strcpy(third, list[dd]);
		}else if(score[dd] > top4){
			top5 = top4;
			strcpy(fifth, fourth);
			top4 = score[dd];
			strcpy(fourth, list[dd]);
		}else if(score[dd] > top5){
			top5 = score[dd];
			strcpy(fifth, list[dd]);
		}
	}
	if(top2 == 0 && top3 == 0 && top4 == 0 && top4 == 0 && top1 != 0){
		printf("The answer is %s", first);
		win = 'y';
	}else {
	switch(pg){
		case 1:
			top2 = -1, top3 = -1, top4 = -1, top5 = -1; break;
		case 2:
			top3 = -1, top4 = -1, top5 = -1; break;
		case 3:
			top4 = -1, top5 = -1; break;
		case 4:
			top5 = -1; break;
	}
	if(pg ==1)
		printf("Guess %s", first);
	else {
		printf("Your best guesses are:\n1: %s - %d\n",first, top1);
		if(top2 > 0)
			printf("2: %s - %d\n", second, top2);
		if(top3 > 0)
			printf("3: %s - %d\n", third, top3);
		if(top4 > 0)
			printf("4: %s - %d\n", fourth, top4);
		if(top5 > 0)
			printf("5: %s - %d\n", fifth, top5);
		}
	}
	/*for(int aa = 0; aa < 26; aa++){
		printf("%c ", aa+97);
		for(int bb = 0; bb<5;bb++){
			printf("%d ", dis[aa][bb]);
		}
		printf("\n");
	}*/
}

int repeatcheck(char *letters, int letval, char let, int letpos){
	double divisor = 1.0;
	int multiplier = 1;
	//printf("%c %d %d\n", let, let-97, dis[let-97][letpos]);
	for(int cc = 0; cc<=strlen(letters); cc++){
		if(letters[cc] == let)
			divisor+=8;
		if(cc == letpos)
			multiplier += dis[let-97][letpos];
	}
	//printf("%d  ", multiplier);
	current += ((letval/divisor)+multiplier);
	
	}

int nextg(){
	int choice;
	const int len = 5;
	int currnuml[5] = {0, 0, 0, 0, 0}, numl[5] = {0, 0, 0, 0, 0};
	
	char currlist[len];
	for(int i=0; i<10; i++){
		currlist[i] = '0';
	}
	choice = 1;
	if(pg != 1){
		printf("Which option did you choose? (1-5)\n");
		scanf(" %d", &choice);
	}
	
	char colors[len];
	for(int i=0; i<5; i++){
		colors[i] = '0';
	}
	printf("What colors were the squares? (g, y, r)\n");
	scanf(" %s", &colors);
	
	switch(choice){
		case 1:
			strcpy(currlist, first);
			break;
		case 2:
			strcpy(currlist, second);
			break;
		case 3:
			strcpy(currlist, third);
			break;
		case 4:
			strcpy(currlist, fourth);
			break;
		case 5:
			strcpy(currlist, fifth);
			break;
	}
	
	for(int i = 0; i < 5; i++){
		for(int k = 0; k < 5; k++){
			if(currlist[i] == currlist[k] && colors[k] != 'r')
				currnuml[i]++;
		}
	}
	
	
	for(int j = 0; j<LEN; j++){
		for(int c = 0; c < 5; c++){
			numl[c] = 0;
		}
		for(int k = 0; k < 5; k++){
			for(int m = 0; m<5; m++){
				if(list[j][k] == list[j][m] && list[j][k] != '?')
					numl[m]++;
			}
		}
		for(int i = 0; i<5; i++){
			
			switch(colors[i]){
				case 'g':
					if(currlist[i] == list[j][i])
						if((numl[i] < currnuml[i]) && (currnuml[i] > 1))
							for(int l = 0; l < 5; l++){
								list[j][l] = '?';
							}
					break;
				case 'y':
					if(currlist[i] == list[j][i])
						if((numl[i] < currnuml[i]) && (currnuml[i] > 1))
							for(int l = 0; l < 5; l++){
								list[j][l] = '?';
							}
					break;
			}
		}
	}
	
	for(int i = 0; i<5; i++){
		for(int j = 0; j<LEN; j++){
			choice = 0;
			switch(colors[i]){
				case 'g':
					if(currlist[i] != list[j][i])
						for(int l = 0; l < 5; l++){
							list[j][l] = '?';
						}
					break;
				case 'y':
					if(currlist[i] == list[j][i])
						for(int l = 0; l < 5; l++){
							list[j][l] = '?';
						}
					for(int k = 0; k<5;k++){
						if(k != i){
							if(currlist[i] == list[j][k]){
								choice=6;
								break;
							}
						}
					}
					if(choice!=6)
						for(int l = 0; l < 5; l++){
							list[j][l] = '?';
						}
					
					break;
				case 'r':
					if(currlist[i] == list[j][i]){
						for(int l = 0; l < 5; l++){
							list[j][l] = '?';
						} break;
					}
					for(int k=0; k<5; k++){
						if((currlist[i] == list[j][k]) && (k != i) && (colors[i] == colors[k])){
							for(int l = 0; l < 5; l++){
							list[j][l] = '?';
							} break;
						}/*
						if((currlist[i] == list[j][k])  && (k == i)){
							for(int l = 0; l < 5; l++){
							list[j][l] = '?';
							} break;
						}*/
					}
					
					break;
			}
			
			
		}
	}
		
		
	/*
	for(int i = 0; i<LEN; i++){
		if(list[i][0] != '?')
			printf("%d %s\n", i+1, list[i]);
	}*/
}
