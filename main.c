#include <stdio.h>
#include <stdlib.h>

char vBuf[128];
char operation;
char falscheOperation[]="Es wurde die falsche Operation gewählt.\nZulässige Operatoren sind:\nAddition (+),\nSubtraktion (-),\nMultiplikation (*)\nDivision (/).\n";
char DivNull[]="Es wurde eine unzulässige Zahl gewählt.\n";
double zahl1=0, zahl2=0, ergebnis=0;

int main(){

    //Eingabe der ersten Zahl.
    printf("Erste Zahl: ");
    fgets(vBuf,sizeof(vBuf),stdin);
    zahl1=atof(vBuf);

    //Eingabe der zweiten Zahl.
    printf("Zweite Zahl: ");
    fgets(vBuf,sizeof(vBuf),stdin);
    zahl2=atof(vBuf);

    //Eingabe der mathematischen Operation
    printf("Mathematische Operation (+,-,*,/): ");
    fgets(vBuf,sizeof(vBuf),stdin);
    //Hier wird geschaut, welche Operation eingegeben wurde.
    sscanf(vBuf,"%c",&operation);
    switch (operation){

        //Die beiden nachfolgenden Zeilen dienen dazu, um das Programm vorzeitig zu beenden.
        case 'Q':
        case 'q':   exit(0); break;
        case '+':   ergebnis=zahl1+zahl2; break;
        case '-':   ergebnis=zahl1-zahl2; break;
        case '*':   ergebnis=zahl1*zahl2; break;
        case '/':   if (zahl2 == 0){

                        puts(DivNull);

                    } else {

                        ergebnis=zahl1/zahl2;

                    } break;

        default: puts(falscheOperation);

    }

    //Ausgabe der Eingabe. :D
    printf("Die Zahlen lauten: %.4lf  %.4lf\n", zahl1, zahl2);
    printf("Und das Ergebnis der Berechnung ist: %.4lf\n", ergebnis);

    return 0;

}
