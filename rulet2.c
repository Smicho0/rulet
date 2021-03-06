#include<stdio.h>  //direktiva pretprocesoru
#include<string.h> //
#include<stdlib.h> //
#include<ctype.h> //
#include<math.h> //
#include<time.h> //
#include<conio.h> //
#define MAX 1000

void Clrscr(void); //funkcije za ciscenje ekrana

void PrintRoulette(void); //funkcija za ispis ruleta

struct player //inicijalizacija strukture
{
	int novac;
	int broj;
	char odabir[8];
	int ulog;
	int izbor;	
};


int main(void)
{
	struct player igraci[MAX];
	
	int winningbet, lower = 0, upper = 36, randomNumber, i, n = 37;
	int cont;
	float chance;
	int flag;
	int players;
	char rulet1st[] = "1st", rulet2nd[] = "2nd", rulet3rd[] = "3rd", rulet1st12[] = "1st12", rulet2nd12[] = "2nd12", rulet3rd12[] = "3rd12";
	char rulet118[] = "1-18", rulet1936[] = "19-36", ruletred[] = "RED", ruletblack[] = "BLACK", ruleteven[] = "EVEN", ruletodd[] = "ODD";
	
	//PrintRoulette();
	
	printf("\n");
	printf("Upisite broj igraca: ");
	scanf("%d", &players);
	for (i = 0; i < players; i++) //petlja koja se vrti za broj igraca
	{
		flag=0;
		while (!flag) //petlja koja se ispunjava dok se svi podaci ne ispune ispravno
		{	
	    	printf("Upisite koliko zelite novaca za %d. igraca: ", i+1);
	   		scanf(" %d", &igraci[i].novac);
	   		if ( igraci[i].novac > 0 )
	   			{
				printf("\n");
				flag = 1;
	     		}
	    else //u slucaju krivog unosa, ponovno se upisuje vrijednost
	    	printf("Pogresan unos.\n ");
	
        }
    }
  
		flag = 0;
		while(!flag) //petlja koja se ispunjava dok se svi podaci ne ispune ispravno
		{
			printf("Zelite li se kladit? (1 - yes / 2 - no)\n");
	    	scanf(" %d", &cont);
	    	if( cont == 2)
	    		break;
			srand(time(0)); //koristi trenutno vrijeme za generiranje nasumicnog broja
			randomNumber = (rand() % (upper - lower + 1)) + lower;  //formula za nasumican broj izmedu 0 i 36
					
			//printf("Izvucen broj je: %d\n", randomNumber);
			Clrscr(); //pozivanje funkcije za ciscenje ekrana
			for (i = 0; i < players; i++)
			{
			
		    	printf("Na redu je %d. igrac", i+1);
				printf("\nAko se zelite kladit na polje s brojem upisite 1\nAko se zelite kladit na kombinaciju napisite 2\nAko zelite zavrsit s radom upisite 3\n");
				printf("Upisite zeljenu akciju: ");
				scanf(" %d", &igraci[i].izbor);
			
		    flag = 0; 
		    while (!flag)
		    {
				switch (igraci[i].izbor) //petlja koja se ispunjava dok se svi podaci ne ispune ispravno
				{
					case 1: //case kada se upisuje broj
						printf("Upisite neki broj izmedu 0 i 36: ");
						scanf("%d", &igraci[i].broj);
						if (igraci[i].broj >= 0 && igraci[i].broj < 37)
						flag = 1;
						else
						printf("Krivi upis.\n");
						break;
		
					case 2: //case kada se trazi neka kombinacija
						printf("Upisite neko polje s kombinacijom: ");
						scanf("%s", &igraci[i].odabir);
						if ( strcmp(igraci[i].odabir, rulet3rd) == 0 || strcmp(igraci[i].odabir, rulet2nd) == 0 || strcmp(igraci[i].odabir, rulet1st) == 0 || strcmp(igraci[i].odabir, ruleteven) == 0 || strcmp(igraci[i].odabir, ruletodd) == 0 || strcmp(igraci[i].odabir, rulet1st12) == 0 || strcmp(igraci[i].odabir, rulet2nd12) == 0 || strcmp(igraci[i].odabir, rulet3rd12) == 0 || strcmp(igraci[i].odabir, ruletblack) == 0 || strcmp(igraci[i].odabir, ruletred) == 0 || strcmp(igraci[i].odabir, rulet118) == 0  || strcmp(igraci[i].odabir, rulet1936) == 0)
						flag = 1;
						break;
					
					case 3:
						return 0;
						break;
						
					default: // case kada se upise krivi unos
				        printf("Krivi izbor. Upisite ponovno: ");
			        	scanf(" %d", &igraci[i].izbor);
				}	
		    }
		    Clrscr(); //pozivanje funkcije za ciscenje ekrana
		    }
	
	    
	    
	  for (i = 0; i < players; i++)  
	  {   
	    if (igraci[i].izbor == 1)  //uvjet koji se ispunjava ako smo se kladili na broj
	    {
			printf("\nIzabran broj %d. igraca je %d",i+1, igraci[i].broj); 
			chance = (1./n)*100;
			printf("\nSansa da pogodite broj %d je %.2f%%\n", igraci[i].broj, chance);
		}
		else  //uvjet ako smo se kladili na kombinaciju
		{
			printf("\nIzabrana kombinacija %d. igraca je %s \n",i+1, igraci[i].odabir); 
			if (strcmp(igraci[i].odabir, rulet3rd) == 0 || strcmp(igraci[i].odabir,rulet2nd) == 0 || strcmp(igraci[i].odabir,rulet1st) == 0)	
			printf("Sansa da pogodite %s je %.2f%%\n", igraci[i].odabir, chance = (12./n)*100 );
			if (strcmp(igraci[i].odabir, rulet1st12) == 0 || strcmp(igraci[i].odabir,rulet2nd12) == 0 || strcmp(igraci[i].odabir,rulet3rd12) == 0)
			printf("Sansa da pogodite %s je %.2f%%\n", igraci[i].odabir, chance = (12./n)*100);
			if (strcmp(igraci[i].odabir, ruleteven) == 0 || strcmp(igraci[i].odabir,ruletodd) == 0)
			printf("Sansa da pogodite %s je %.2f%%\n", igraci[i].odabir, chance = (18./n)*100);
			if (strcmp(igraci[i].odabir, ruletred) == 0 || strcmp(igraci[i].odabir,ruletblack) == 0)
			printf("Sansa da pogodite %s je %.2f%%\n", igraci[i].odabir, chance = (18./n)*100);
			if (strcmp(igraci[i].odabir, rulet118) == 0 || strcmp(igraci[i].odabir,rulet1936) == 0)
			printf("Sansa da pogodite %s je %.2f%%\n", igraci[i].odabir, chance = (18./n)*100);
		}
	    }
	    
	      for (i = 0; i < players; i++) //petlja za ulaganje para
	    {
	    	flag = 0;
	    	while (!flag)
	    	{
	    		printf("\nKoliko para zelite ulozit %d. igrac: ", i+1);
				scanf(" %d", &igraci[i].ulog);
	    		if ( igraci[i].ulog <= igraci[i].novac && igraci[i].ulog > 0)
	    		{
					igraci[i].novac -= igraci[i].ulog;
					flag = 1;
				}
				else
				printf("Preveliki ulog. Upisite ponovno.");
		    }
	    }
	    
	
	    PrintRoulette(); //funkcija za printanje ruleta
	
	
	    printf("Izvucen broj je: |%d|\n", randomNumber);
	    
	    for (i = 0; i < players; i++) //petlja za provjeru dobitka
	    {
	    
		if (igraci[i].broj == randomNumber) //uvjet da izabrani broj jednak nasumicnom
		{
			printf("Igrac %d. je dobio.\n", i+1);
			winningbet = igraci[i].ulog*36;
			igraci[i].novac += winningbet;
	    }
		else if ( strcmp(igraci[i].odabir,rulet3rd) == 0 && randomNumber % 3 == 0) //uvjet da je igrac odabrao trece polje
		{
		    printf("Igrac %d. je dobio.\n", i+1);
	    	winningbet = igraci[i].ulog*3;
	    	igraci[i].novac += winningbet;
	    } 
		else if ( strcmp(igraci[i].odabir,rulet2nd) == 0 && (randomNumber+1) % 3 == 0) //uvjet da je igrac odabrao druge polje
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*3;
		    igraci[i].novac += winningbet;
	    }
		else if ( strcmp(igraci[i].odabir,rulet1st) == 0 && (randomNumber+2) % 3 == 0) //uvjet da je igrac odabrao prvo polje
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*3;
		    igraci[i].novac += winningbet;
	    }
		 
		else if ( strcmp(igraci[i].odabir,ruleteven) == 0 && randomNumber % 2 == 0) //uvjet da je igrac odabrao paran broj
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*2;
		    igraci[i].novac += winningbet;
	    }
		else if ( strcmp(igraci[i].odabir,ruletodd) == 0 && randomNumber % 2 != 0) //uvjet da je igrac odabrao neparan broj
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*2;
		    igraci[i].novac += winningbet;
	    }
	    
		else if ( strcmp(igraci[i].odabir,ruletred) == 0 && (randomNumber == 2 || randomNumber == 4 || randomNumber == 6 || randomNumber == 8 || randomNumber == 11 || randomNumber == 13 || randomNumber == 15 || randomNumber == 17) ) //uvjet da je igrac odabrao crveno polje
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*2;
		    igraci[i].novac += winningbet;
	    }
		else if ( strcmp(igraci[i].odabir,ruletred) == 0 && (randomNumber == 20 || randomNumber == 22 || randomNumber == 24 || randomNumber == 26 || randomNumber == 28 || randomNumber == 29 || randomNumber == 31 || randomNumber == 33 || randomNumber == 35) ) //uvjet da je igrac odabrao crveno polje
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*2;
		    igraci[i].novac += winningbet;
	    }
		else if ( strcmp(igraci[i].odabir,ruletblack) == 0 && (randomNumber == 1 || randomNumber == 3 || randomNumber == 5 || randomNumber == 7 || randomNumber == 9 || randomNumber == 12 || randomNumber == 14 || randomNumber == 16 || randomNumber == 18) ) //uvjet da je igrac odabrao crno polje
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*2;
		    igraci[i].novac += winningbet;
	    }
		else if ( strcmp(igraci[i].odabir,ruletblack) == 0 && (randomNumber == 19 || randomNumber == 21 || randomNumber == 23 || randomNumber == 25 || randomNumber == 27 || randomNumber == 30 || randomNumber == 32 || randomNumber == 34 || randomNumber == 36) ) //uvjet da je igrac odabrao crno polje
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*2;
		    igraci[i].novac += winningbet;
	    }
		 
		else if ( strcmp(igraci[i].odabir,rulet118) == 0 && randomNumber >= 1 && randomNumber <= 18) //uvjet da je igrac odabrao broj kombinaciju brojeva izmedu 1 i 18
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*2;
		    igraci[i].novac += winningbet;
	    }
		else if ( strcmp(igraci[i].odabir,rulet1936) == 0 && randomNumber >= 19 && randomNumber <= 36) //uvjet da je igrac odabrao kombinaciju brojeva izmedu 19 i 36
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*2;
		    igraci[i].novac += winningbet;
	    }
		 
		else if ( strcmp(igraci[i].odabir,rulet1st12) == 0 && randomNumber >= 1 && randomNumber <= 12) //uvjet da je igrac odabrao kombinaciju brojeva izmedu 1 i 12
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*3;
		    igraci[i].novac += winningbet;
	    }
		else if ( strcmp(igraci[i].odabir,rulet2nd12) == 0 && randomNumber >= 13 && randomNumber <= 24) //uvjet da je igrac odabrao kombinaciju brojeva izmedu 13 i 24
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*3;
		    igraci[i].novac += winningbet;
	    }
		else if ( strcmp(igraci[i].odabir,rulet3rd12) == 0 && randomNumber >= 25 && randomNumber <= 36) //uvjet da je igrac odabrao kombinaciju brojeva izmedu 25 i 36
		{
		    printf("Igrac %d. je dobio.\n", i+1);
		    winningbet = igraci[i].ulog*3;
		    igraci[i].novac += winningbet;
	    }
		 
		else
		printf("Igrac %d. je izgubio.\n", i+1);
	    }
	    
	    //Clrscr();
	    for (i = 0; i < players; i++)
	    {
	    	printf("Igrac %d imate %d novaca.\n", i+1, igraci[i].novac);
	    }
		
  
	}
}

void PrintRoulette(void) //funkcija za ispisivanje ruleta
{
	int rulet[3][14] = {{0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36}, {0, 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35}, {0, 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34,} }, i, j;
    char rulet1st[] = "1st", rulet2nd[] = "2nd", rulet3rd[] = "3rd", rulet1st12[] = "1nd12", rulet2nd12[] = "2nd12";
	char rulet3rd12[] = "3nd12", rulet118[] = "1-18", rulet1936[] = "19-36", ruletred[] = "RED", ruletblack[] = "BLACK", ruleteven[] = "EVEN", ruletodd[] = "ODD";
    printf("-------------------------------------------------------------------\n");
    for (i=0; i < 3; i++)
	{
		for (j=0; j < 13; j++)
		printf("|%d| ", rulet[i][j]);
		if (i == 0)
	    printf("|%s|", rulet3rd);
	    if (i == 1)
	    printf("|%s|", rulet2nd);
	    if (i == 2)
	    printf("|%s|", rulet1st);
	    printf("\n-------------------------------------------------------------------\n");
		
	}
	printf("    |    %s     | |      %s      | |      %s      |\n", rulet1st12, rulet2nd12, rulet3rd12);
	printf("    --------------------------------------------------------\n");
	printf("    | %s || %s | |  %s ||  %s  | |  %s ||  %s  |\n", rulet118, ruleteven, ruletred, ruletblack, ruletodd, rulet1936);
	printf("    --------------------------------------------------------\n");
}

void Clrscr(void) //funkcija za ciscenje ekrana
{
	system("@cls||clear");
}
