/*

    Traveller-MUSE: a space trader game
    Copyright (C) 2025 Robert Eaglestone

    This file is part of Traveller-MUSE.
        
    Traveller-MUSE is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
        
    Traveller-MUSE is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Traveller-MUSE.  If not, see <https://www.gnu.org/licenses/>.
        
*/

#include <stdlib.h>
#include <string.h>

#include "name.h"

//
//  Name fragments start at $b000 of MISC_BANK
//
char                           *NAME_FRAGMENT = "co da as si me ea ar ra iz at ta da ra le ig en ix ag ti id ro ga ex ox lo ca ni me li to la wo de ru de ag ro po ta se in mo lu de ri pe st er st ro ta so ar ru wa wo ad ak wa en eg de ac oc op or pa re ri nu ti ve wi vi ju mo me ne ut a  i  u  e  o  bectlefleshoonaoraphoshoforguelanlasdentinartortertangingengongantontintindundendtriitomeralubeldecremmenducscothedreownepicencansargenterageatebithenhosgragnocidcanardcorcreousathainwheluclinmatmedmismelmarnecnornesnouostpelproporpriplafriregsansalinesolsemsecsulscascisheranmermirspistatecaphteltoltomtentorterlocvalvererg";

#define NAME_FRAGMENT(x)        (char*)(NAME_FRAGMENT + x * 3)

char* name_generate(char* buf)
{
    char* row;
    char tmp[16];

    int bufpos = 0;
    int syl = 2 + rand() % 2; // max 9 chars?

    while(syl--)
    {
        row = NAME_FRAGMENT( rand() % 192 );
        buf[bufpos++] = row[0];
        if (row[1] != ' ') buf[bufpos++] = row[1];
        if (row[2] != ' ') buf[bufpos++] = row[2];
    }
    if (strlen(buf) > 8 && rand() % 2 == 1) { // insert a marker
       strncpy(tmp, buf, 3);
       tmp[3] = '-';
       if (rand() % 2 == 1) tmp[3] = '\'';
       strcpy(tmp + 4, buf + 3);
       strcpy(buf, tmp);
    }
    buf[bufpos] = '\0';
    return buf;
}
