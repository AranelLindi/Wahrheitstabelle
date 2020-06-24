#include <stdio.h>                        // Konsolenausgabe

/* TODO:
*    - Logischen Ausdruck unter AUSDRUCK eingeben (Funktion anpassen)
*    - ANZAHLBITS in Anzahl der Variablen des logischen Ausdrucks ändern
*    - ZEILE 37 (Markierung!) entsprechend der Anzahl der Variablen anpassen
*/

// ***************************** TODO *****************************
#define AUSDRUCK(a, b, c, d)		!(a & b & c & d)
#define ANZAHLBITS 4                     // entspricht Anzahl an Variablen
// ****************************************************************

// NICHTS ÄNDERN!
#define SCHRANKE ((1 << ANZAHLBITS) - 1)    // Anzahl der Variationen (2^AnzahlBits)-1
#define BYTE unsigned char                // zur Code-Vereinfachung

// Globale Variable
BYTE arr[ANZAHLBITS] = { 0 };                 // Array mit AnzahlBits-Feldern anlegen, enthält später gesetzte Bits

int main(void) {
    printf("****************************\n AUSGABE - WAHRHEITSTABELLE\n\n A B C D\tAUSDRUCK\n****************************\n");

    for (int i = SCHRANKE; i >= 0; i--) {     // iteriert durch alle Zahlen von [Schranke; 0]
	printf(" ");
        // Variablen neuen Wert übergeben:
        for(int j = 0; j < ANZAHLBITS; j++) { // iteriert durch Array
            arr[j] = (i & 1 << j) ? 1 : 0;         // gibt 0 wenn j-tes Bit von i 'nicht gesetzt' und 1 wenn es 'gesetzt' ist zurück
            printf("%i ", (arr[j]));     // Ausgabe
        }
        printf("\t");

        int i = 0; // fungiert als Zurücksetzen in nächster Iteration

        // ************************* TODO *************************
        //  ZEILE ÄNDERN! Anzahl Variablen hier entsprechend anpassen.
        if (AUSDRUCK(arr[0], arr[1], arr[2], arr[3])) i = 1; // bei true -> 1 setzen
        // ********************************************************

        printf("%5i\n", i); // Ausgabe und neue Zeile
    }

    return 0;
}
