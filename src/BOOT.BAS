10 COLOR 2,0
20 ? CHR$($93)
30 ? "SPLASH SCREEN"
100 COLOR 8
110 FOR X = 1 TO 80:L$=L$+CHR$(164):NEXT
120 ?:?:?:?:? L$;
130 ?:?:? SPC(27);"PRESS <RETURN> TO BEGIN"
140 GET A$:IF A$="" GOTO 140
150 A = RND(-TI)
200 REM LOAD RESOURCES HERE
210 REM ...
220 REM ...
998 REM NOW LOAD MAIN PROGRAM
999 LOAD "MAIN",8,1
