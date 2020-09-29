# -SZE-MOSZE-2020-My_Little_D-D
Csapatunk célja a MOSZE(GKNB_INTM006) tantárgy teljesítése, félév közbeni munkával amely során szöveges RPG játék fejlesztése közben fogunk megismerkedni a modern szoftverfejlesztés eszközeivel.

Csapat tagok:
  1. Raboczki Csongor
  2. Szoták Bálint
  3. Rehus Ádám

## Működés:
Jelenlegi működése a programnak úgy történik, hogy vár két file nevet mint parancssori argumentum. JSON struktúrában kell leírni benne.
Például:
```
{
    "name" : "Arthas Menethil",
    "hp" : 40000,
    "dmg" : 7000
}
```
Sorrend nem számít, a program kikeresi melyik sorban melyik adat található.
Amennyiben a file nem létezik, hibával lép ki a programunk nem fut tovább.
