#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char vBuf[128];
char operation, abfrage;
char intro[]="Hallo! Schön, dass du den Rechner 'calculus' nutzt.";
char falscheOperation[]="Falsche Operation gewählt.\nZulässige Operatoren sind:\nAddition (+),\nSubtraktion (-),\nMultiplikation (*)\nDivision (/).\n";
char DivNull[]="Division durch 0 ist nicht erlaubt.\n";
double zahl1=0, zahl2=0, ergebnis=0;

int main(){

    //Bevor die Willkommensnachricht erscheinen soll, "schläft" das Programm 1 Sekunde.
    sleep(1);
    //Willkommensnachricht
    puts(intro);

    //Die nachfolgende Zeile dient der Sprunganweisung im switch case 'Q' || 'q',
    //wenn der Benutzer das Programm nicht beenden möchte.
    sprunganfang:

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
        case 'q':    if (operation=='q' || operation=='Q'){

                        beenden:
                        printf("\nSoll das Programm beendet werden (J/N)?\n");
                        printf("Antwort: ");
                        fgets(vBuf,sizeof(vBuf),stdin);
                        sscanf(vBuf,"%c",&abfrage);

                        //Abfrage, ob der Benutzer das Programm "calculus" beenden will.
                        if ((abfrage=='J' || abfrage=='j') && (abfrage!='N' || abfrage!='n')){

                            printf("Das Programm wird beendet.\n"); sleep(1.5); exit(0); break;

                        } else {

                            printf("\n");
                            goto sprunganfang;
                        }

                    }

        case '+':   ergebnis=zahl1+zahl2; break;
        case '-':   ergebnis=zahl1-zahl2; break;
        case '*':   ergebnis=zahl1*zahl2; break;
        case '/':   //Mit der folgenden if-else-Schleife wird überprüft, ob bei der Division der Teiler "0" ist.

                    if (zahl2 == 0){

                        puts(DivNull);
                        sleep(1);
                        goto beenden;

                    } else {

                        ergebnis=zahl1/zahl2;

                    } break;

        default: puts(falscheOperation); sleep(2); return 1;

    }

    //Ausgabe der beiden zuvor eingegebenen Zahlen. :D
    printf("\nDie Zahlen lauten: %.4lf  %.4lf\n", zahl1, zahl2);
    //Ausgabe des Ergebnisses. :D
    printf("Und das Ergebnis der Berechnung ist: %.4lf\n", ergebnis);

    goto beenden;

    return 0;

}
